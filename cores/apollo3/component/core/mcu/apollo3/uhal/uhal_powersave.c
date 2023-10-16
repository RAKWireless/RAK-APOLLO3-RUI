#include "uhal_powersave.h"
#include "uhal_timer.h"
#include "udrv_errno.h"
#include "uhal_uart.h"
#include "uhal_gpio.h"
#include "uhal_twimst.h"
#include "uhal_spimst.h"
#include "uhal_pwm.h"
#include "uhal_adc.h"
#include "uhal_rtc.h"
#include "am_log.h"
#include "rtos.h"

#define MAX_COUNTING_VALUE      255
#define INITIAL_COUNTING_VALUE  0

extern bool udrv_powersave_in_sleep;
extern bool udrv_powersave_in_deep_sleep;
extern bool udrv_powersave_early_wakeup;

extern bool no_busy_loop;
extern uint32_t wlock_cnt;

static inline bool isInISR(void)
{
  return (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0 ;
}

static TimerHandle_t uhal_ps_timer_id = NULL;
static TimerHandle_t uart_wait_timer_id = NULL;
static TaskHandle_t consume_event_task;
static SemaphoreHandle_t ps_semaphore = NULL;
static SemaphoreHandle_t ps_counting_semaphore = NULL;
static timer_handler ps_tmr_handler = NULL;
static void *p_context = NULL;
static volatile bool is_mcu_sleeping = false;
volatile bool is_mcu_resumed = false;
volatile bool rx_wait_active = false;

void consume_event_task_handler(void *pvPaParameters)
{
    while(1)
    {
        xSemaphoreTake(ps_counting_semaphore, portMAX_DELAY);

        if(uhal_mcu_sleep_status() == true)
        {
            // Resume peripherals...
            uhal_mcu_resume();

            udrv_system_event_consume();

            // Suspend peripherals...
            uhal_mcu_suspend();
        }
    }
}

static void ps_timer_timeout_handler(TimerHandle_t xTimer)
{
  uhal_mcu_wake_up();
  ps_tmr_handler(p_context);
}

static void uart_wait_timer_timeout_handler(TimerHandle_t xTimer)
{
    taskENTER_CRITICAL();

    if(service_nvm_get_auto_sleep_time_from_nvm() == 0 && no_busy_loop == true)
    {   
        rx_wait_active = false;
        taskEXIT_CRITICAL();
        return;
    }

    if(wlock_cnt != 0)
    {
        rx_wait_active = false;
        taskEXIT_CRITICAL();
        return;
    }

    uhal_mcu_clear_rx_interrupt();
    uint8_t *str_ok = "SLEEP\r\n";
    uhal_uart_write(0, str_ok, strlen(str_ok), 0);
    uhal_uart_write(1, str_ok, strlen(str_ok), 0);

    taskEXIT_CRITICAL();
}

int32_t uhal_ps_timer_create (timer_handler tmr_handler, TimerMode_E mode) {
    
    if(uhal_ps_timer_id == NULL)
    {
      uhal_ps_timer_id = xTimerCreate("PS_TMR",
                            1,
                            get_apollo_timer_mode(mode),
                            NULL,
                            ps_timer_timeout_handler);
    }

    ps_tmr_handler = tmr_handler;

    if (uhal_ps_timer_id != NULL) {
        return UDRV_RETURN_OK;
    } else {
        return -UDRV_INTERNAL_ERR;
    }
}

int32_t uhal_ps_timer_start (uint32_t count, void *m_data) {

    if(uhal_ps_timer_id == NULL)
    {
        return -UDRV_INTERNAL_ERR;
    }

    if(count == 0)
        return -UDRV_INTERNAL_ERR;
        
    p_context = m_data;

    if( isInISR() ) 
    {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        if(pdPASS != xTimerStopFromISR(uhal_ps_timer_id, xHigherPriorityTaskWoken))
        {
            return -UDRV_INTERNAL_ERR;
        }

        if(xHigherPriorityTaskWoken != pdFALSE)
        {
            portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }

        if(pdPASS != xTimerChangePeriodFromISR( uhal_ps_timer_id,
                        (uint32_t) (count*1.024f), // This is not correct solution! FIX ME!
                        &xHigherPriorityTaskWoken ))
        {
            return -UDRV_INTERNAL_ERR;
        }

        if(xHigherPriorityTaskWoken != pdFALSE)
        {
            portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }

        if(pdPASS != xTimerStartFromISR(uhal_ps_timer_id, &xHigherPriorityTaskWoken))
        {
            return -UDRV_INTERNAL_ERR;
        }

        if(xHigherPriorityTaskWoken != pdFALSE)
        {
            portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }
    } 
    else
    {
        if(pdPASS != xTimerStop(uhal_ps_timer_id, OSTIMER_WAIT_FOR_QUEUE))
        {
            return -UDRV_INTERNAL_ERR;
        }

        if(pdPASS != xTimerChangePeriod( uhal_ps_timer_id,
                        (uint32_t) (count*1.024f), // This is not correct solution! FIX ME!
                        OSTIMER_WAIT_FOR_QUEUE ))
        {
            return -UDRV_INTERNAL_ERR;
        }

        // Start application timers.
        if (pdPASS != xTimerStart(uhal_ps_timer_id, OSTIMER_WAIT_FOR_QUEUE))
        {
            return -UDRV_INTERNAL_ERR;
        }
    }

    return UDRV_RETURN_OK;
}

int32_t uhal_ps_timer_stop () {

    if(uhal_ps_timer_id == NULL)
    {
        return -UDRV_INTERNAL_ERR;
    }

    if( isInISR() ) 
    {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        if(pdPASS != xTimerStopFromISR(uhal_ps_timer_id, xHigherPriorityTaskWoken))
        {
            return -UDRV_INTERNAL_ERR;
        }

        if(xHigherPriorityTaskWoken != pdFALSE)
        {
            portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }

    } 
    else
    {
        if(pdPASS != xTimerStop(uhal_ps_timer_id, OSTIMER_WAIT_FOR_QUEUE))
        {
            return -UDRV_INTERNAL_ERR;
        }
    }

    return UDRV_RETURN_OK;
}

int32_t uhal_uart_wait_timer_start (uint32_t count) {

    if(count == 0)
        return -UDRV_INTERNAL_ERR;
    
    if( service_nvm_get_auto_sleep_time_from_nvm() == 0 && no_busy_loop == true )
         return -UDRV_BUSY;

    if(uart_wait_timer_id == NULL)
    {
      uart_wait_timer_id = xTimerCreate("UW_TMR",
                            1,
                            pdFALSE, // One shot timer
                            NULL,
                            uart_wait_timer_timeout_handler);
    }

    if( isInISR() ) 
    {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        if(pdPASS != xTimerStopFromISR(uart_wait_timer_id, xHigherPriorityTaskWoken))
        {
            return -UDRV_INTERNAL_ERR;
        }

        if(xHigherPriorityTaskWoken != pdFALSE)
        {
            portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }

        if(pdPASS != xTimerChangePeriodFromISR( uart_wait_timer_id,
                        (uint32_t) (count*1.024f), // This is not correct solution! FIX ME!
                        &xHigherPriorityTaskWoken ))
        {
            return -UDRV_INTERNAL_ERR;
        }

        if(xHigherPriorityTaskWoken != pdFALSE)
        {
            portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }

        if(pdPASS != xTimerStartFromISR(uart_wait_timer_id, &xHigherPriorityTaskWoken))
        {
            return -UDRV_INTERNAL_ERR;
        }

        if(xHigherPriorityTaskWoken != pdFALSE)
        {
            portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }
    } 
    else
    {
        if(pdPASS != xTimerStop(uart_wait_timer_id, OSTIMER_WAIT_FOR_QUEUE))
        {
            return -UDRV_INTERNAL_ERR;
        }

        if(pdPASS != xTimerChangePeriod( uart_wait_timer_id,
                        (uint32_t) (count*1.024f), // This is not correct solution! FIX ME!
                        OSTIMER_WAIT_FOR_QUEUE ))
        {
            return -UDRV_INTERNAL_ERR;
        }

        // Start application timers.
        if (pdPASS != xTimerStart(uart_wait_timer_id, OSTIMER_WAIT_FOR_QUEUE))
        {
            return -UDRV_INTERNAL_ERR;
        }
    }

    rx_wait_active = true;
    return UDRV_RETURN_OK;
}

int32_t uhal_uart_wait_timer_stop () {

    if(uart_wait_timer_id == NULL)
    {
        return -UDRV_INTERNAL_ERR;
    }

    if( isInISR() ) 
    {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        if(pdPASS != xTimerStopFromISR(uart_wait_timer_id, xHigherPriorityTaskWoken))
        {
            return -UDRV_INTERNAL_ERR;
        }

        if(xHigherPriorityTaskWoken != pdFALSE)
        {
            portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }

    } 
    else
    {
        if(pdPASS != xTimerStop(uart_wait_timer_id, OSTIMER_WAIT_FOR_QUEUE))
        {
            return -UDRV_INTERNAL_ERR;
        }
    }

    return UDRV_RETURN_OK;
}

void uart0_rx_interrupt_handler()
{
  am_log_inf("UART0 RX interrupt...");
  
  uhal_mcu_clear_rx_interrupt();

  if(uhal_mcu_sleep_status() == true)
  {
    am_log_inf("Resume System");
    uhal_mcu_wake_up();

    uhal_uart_resume();
    uint8_t *str_ok = "WAKE_UP\r\n";
    uhal_uart_write(0, str_ok, strlen(str_ok), 0);
    uhal_uart_write(1, str_ok, strlen(str_ok), 0);
    uhal_uart_suspend();
  }

  if(no_busy_loop == false)
    rx_wait_active = true;
  else
    uhal_uart_wait_timer_start(UART_WAIT_TIMEOUT_TIME);
}

void uart1_rx_interrupt_handler()
{
  am_log_inf("UART1 RX interrupt...");
  
  uhal_mcu_clear_rx_interrupt();

  if(uhal_mcu_sleep_status() == true)
  {
    am_log_inf("Resume System");
    uhal_mcu_wake_up();

    uhal_uart_resume();
    uint8_t *str_ok = "WAKE_UP\r\n";
    uhal_uart_write(0, str_ok, strlen(str_ok), 0);
    uhal_uart_write(1, str_ok, strlen(str_ok), 0);
    uhal_uart_suspend();
  }

  if(no_busy_loop == false)
    rx_wait_active = true;
  else
    uhal_uart_wait_timer_start(UART_WAIT_TIMEOUT_TIME);
}

void uhal_mcu_set_rx_interrupt(void) {

  am_log_inf("Set RX interrupt...");

  uhal_gpio_intc_clear(WB_RXD0);
  uhal_gpio_pin_suspend(WB_RXD0);
  uhal_gpio_set_dir(WB_RXD0, GPIO_DIR_IN);
  uhal_gpio_set_pull(WB_RXD0, GPIO_PULL_UP);
  uhal_gpio_intc_trigger_mode(WB_RXD0, GPIO_INTC_FALLING_EDGE);
  uhal_gpio_register_isr(WB_RXD0, uart0_rx_interrupt_handler);

  uhal_gpio_intc_clear(WB_RXD1);
  uhal_gpio_pin_suspend(WB_RXD1);
  uhal_gpio_set_dir(WB_RXD1, GPIO_DIR_IN);
  uhal_gpio_set_pull(WB_RXD1, GPIO_PULL_UP);
  uhal_gpio_intc_trigger_mode(WB_RXD1, GPIO_INTC_FALLING_EDGE);
  uhal_gpio_register_isr(WB_RXD1, uart1_rx_interrupt_handler);
}

void uhal_mcu_clear_rx_interrupt(void) {

  am_log_inf("Clear RX interrupt...");

  uhal_gpio_intc_clear(WB_RXD0);
  uhal_gpio_pin_suspend(WB_RXD0);

  uhal_gpio_intc_clear(WB_RXD1);
  uhal_gpio_pin_suspend(WB_RXD1);

  rx_wait_active = false;
}

void uhal_mcu_sleep (uint32_t level)
{
  if (ps_semaphore == NULL)
  {
    ps_semaphore = xSemaphoreCreateBinary();
  }

  if (ps_counting_semaphore == NULL)
  {
    ps_counting_semaphore = xSemaphoreCreateCounting(MAX_COUNTING_VALUE, INITIAL_COUNTING_VALUE);
  }

    static bool consume_event_task_status = false;
    if(consume_event_task_status == false)
    {
        xTaskCreate(
            (TaskFunction_t) consume_event_task_handler,
            "CONS_EVT_TASK",
            configMINIMAL_STACK_SIZE*4,
            NULL,
            RAK_TASK_PRIO_NORMAL,
            &consume_event_task
        );

        consume_event_task_status = true;
    }

  is_mcu_sleeping = true;

  uhal_mcu_set_rx_interrupt();

  if( isInISR() ) 
  {
      BaseType_t xHigherPriorityTaskWoken, xResult;
      xSemaphoreTakeFromISR(ps_semaphore, &xHigherPriorityTaskWoken);
      if (xResult != pdFAIL)
        portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
  } 
  else
  {
      xSemaphoreTake(ps_semaphore, portMAX_DELAY);
  }
}

void uhal_mcu_wake_up (void)
{
  if (ps_semaphore == NULL)
  {
    return;
  }

  uhal_ps_timer_stop();

  if( isInISR() ) 
  {
      BaseType_t xHigherPriorityTaskWoken, xResult;
      xSemaphoreGiveFromISR(ps_semaphore, &xHigherPriorityTaskWoken);
      if (xResult != pdFAIL)
        portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
  } 
  else
  {
      xSemaphoreGive(ps_semaphore);
  }

  uhal_mcu_clear_rx_interrupt();

  is_mcu_sleeping = false;
  udrv_powersave_in_sleep = false;
}

void uhal_mcu_consume_event (void)
{
  if (ps_counting_semaphore == NULL)
  {
    return;
  }

  if(is_mcu_sleeping == false)
  {
    return;
  }

  if( isInISR() ) 
  {
      BaseType_t xHigherPriorityTaskWoken, xResult;
      xSemaphoreGiveFromISR(ps_counting_semaphore, &xHigherPriorityTaskWoken);
      if (xResult != pdFAIL)
        portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
  } 
  else
  {
      xSemaphoreGive(ps_counting_semaphore);
  }
}

void uhal_sys_clock_init(void) {
}

void uhal_sys_clock_on(void) {
}

void uhal_sys_clock_off(void) {
}

void uhal_mcu_resume(void) {

    if(is_mcu_resumed == true)
        return;

    UBaseType_t uxSavedInterruptStatus;
    if(isInISR())
    {
        uxSavedInterruptStatus = taskENTER_CRITICAL_FROM_ISR();
    }
    else
    {
        taskENTER_CRITICAL();
    }

    uhal_mcu_clear_rx_interrupt();

    uhal_rtc_resume();
    uhal_gpio_resume();
    #ifdef SUPPORT_SPI
    uhal_spimst_resume();
    #endif
    uhal_twimst_resume();
    uhal_uart_resume();
    uhal_pwm_resume();
    uhal_adc_resume();

    is_mcu_resumed = true;

    if(isInISR())
    {
        taskEXIT_CRITICAL_FROM_ISR( uxSavedInterruptStatus );

    }
    else
    {
        taskEXIT_CRITICAL();
    }

    am_log_inf("uhal_mcu_resume");
}

void uhal_mcu_suspend(void) {


    if(is_mcu_resumed == false)
        return;

    UBaseType_t uxSavedInterruptStatus;
    if(isInISR())
    {
        uxSavedInterruptStatus = taskENTER_CRITICAL_FROM_ISR();
    }
    else
    {
        taskENTER_CRITICAL();
    }

    #ifdef SUPPORT_SPI
    uhal_spimst_suspend();
    #endif
    uhal_adc_suspend();
    uhal_pwm_suspend();
    uhal_uart_suspend();
    uhal_twimst_suspend();
    uhal_gpio_suspend();
    uhal_rtc_suspend();

    if(is_mcu_sleeping == true)
      uhal_mcu_set_rx_interrupt();

    is_mcu_resumed = false;

    if(isInISR())
    {
        taskEXIT_CRITICAL_FROM_ISR( uxSavedInterruptStatus );

    }
    else
    {
        taskEXIT_CRITICAL();
    }

    am_log_inf("uhal_mcu_suspend");
}

bool uhal_mcu_sleep_status(void) {
    
    return is_mcu_sleeping;
}
