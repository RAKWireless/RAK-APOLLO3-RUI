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

static inline bool isInISR(void)
{
  return (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0 ;
}

static TimerHandle_t uhal_ps_timer_id = NULL;
static SemaphoreHandle_t ps_semaphore = NULL;
static timer_handler ps_tmr_handler = NULL;
static void *p_context = NULL;
static volatile bool is_mcu_sleeping = false;

static void ps_timer_timeout_handler(TimerHandle_t xTimer)
{
  uhal_mcu_wake_up();
  ps_tmr_handler(p_context);
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

    p_context = m_data;

    xTimerStop(uhal_ps_timer_id, OSTIMER_WAIT_FOR_QUEUE);

    xTimerChangePeriod( uhal_ps_timer_id,
                        (uint32_t) (count*1.024f), // This is not correct solution! FIX ME!
                        OSTIMER_WAIT_FOR_QUEUE );

    // Start application timers.
    if (pdPASS != xTimerStart(uhal_ps_timer_id, OSTIMER_WAIT_FOR_QUEUE))
    {
        return -UDRV_INTERNAL_ERR;
    }
    else {
        return UDRV_RETURN_OK;
    }
}

int32_t uhal_ps_timer_stop () {
    if(uhal_ps_timer_id == NULL)
        return UDRV_RETURN_OK;

    // Start application timers.
    if (pdPASS != xTimerStop(uhal_ps_timer_id, 2))
    {
        return -UDRV_INTERNAL_ERR;
    }
    else {
        return UDRV_RETURN_OK;
    }
}

void uhal_mcu_sleep (void)
{
  if (ps_semaphore == NULL)
  {
    ps_semaphore = xSemaphoreCreateBinary();
  }

  is_mcu_sleeping = true;
  
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

  is_mcu_sleeping = false;
}

void uhal_sys_clock_init(void) {
}

void uhal_sys_clock_on(void) {
}

void uhal_sys_clock_off(void) {
}

void uhal_mcu_resume(void) {

    am_log_inf("uhal_mcu_resume");

    uhal_rtc_resume();
    uhal_gpio_resume();
    #ifdef SUPPORT_SPI
    uhal_spimst_resume();
    #endif
    uhal_twimst_resume();
    uhal_uart_resume();
    uhal_pwm_resume();
    uhal_adc_resume();
}

void uhal_mcu_suspend(void) {

    am_log_inf("uhal_mcu_suspend");

    #ifdef SUPPORT_SPI
    uhal_spimst_suspend();
    #endif
    uhal_adc_suspend();
    uhal_pwm_suspend();
    uhal_uart_suspend();
    uhal_twimst_suspend();
    uhal_gpio_suspend();
    uhal_rtc_suspend();
}

bool uhal_mcu_sleep_status(void) {
    
    return is_mcu_sleeping;
}