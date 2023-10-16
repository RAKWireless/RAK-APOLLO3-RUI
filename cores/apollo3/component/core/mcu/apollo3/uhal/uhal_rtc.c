#include "uhal_rtc.h"
#include "uhal_timer.h"
#include "uhal_powersave.h"
#include "uhal_delay.h"
#include "uhal_gpio.h"
#include "udrv_rtc.h"
#include "udrv_delay.h"
#include "udrv_serial.h"
#include "am_log.h"

#include "FreeRTOSConfig.h"
#include "rtos.h"

#define TEST_DEBUG(fmt, args...)      udrv_serial_log_printf("(Line:%d,Func:%s)[DEBUG]"fmt"\r\n",__LINE__,__func__,##args)

extern bool udrv_powersave_in_sleep;

static uint64_t time_base = 0;
static uint64_t counter_base = 0;
static uint32_t max_ticks = UINT32_MAX;
static uint32_t rtc_timer_context = 0;
static rtc_handler compare0_handler;
static uint32_t alarm_cnt = 0;
static udrv_system_event_t rui_rtc_event = {.request = UDRV_SYS_EVT_OP_RTC, .p_context = NULL};

static TaskHandle_t rtc_event_task;
static SemaphoreHandle_t rtc_semaphore = NULL;

static inline bool isInISR(void)
{
  return (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0 ;
}

void am_stimer_isr(void)
{
    // FIXME
    am_hal_stimer_int_clear(AM_HAL_STIMER_INT_OVERFLOW);
    am_log_inf("Overflow!!!"); // FIXME

    time_base += uhal_rtc_tick2ms(max_ticks);
    counter_base += max_ticks;
}

// Timer Interrupt Service Routine (ISR)
void am_ctimer_isr(void)
{
    uint32_t ui32Status;

    ui32Status = am_hal_ctimer_int_status_get(false);
    am_hal_ctimer_int_clear(ui32Status);

    am_hal_ctimer_int_service(ui32Status);
}

uint32_t uhal_rtc_tick2ms(uint32_t tick) {
    return (uint32_t)((float)tick*(float)1000/(float)SYS_RTC_FREQ);
}

uint32_t uhal_rtc_tick2us(uint32_t tick) {
    return (uint32_t)((float)tick*(float)1000000/(float)SYS_RTC_FREQ);
}

uint32_t uhal_rtc_ms2tick(uint32_t ms) {
    return (uint32_t)((float)ms*(float)SYS_RTC_FREQ/(float)1000);
}

static TimerHandle_t uhal_timer_rtc;  /**< Definition of timer. */

void uhal_rtc_handler_handler(void *pdata)
{
    if (compare0_handler) {
        compare0_handler(NULL);
    }
}

// Interrupt handler for the RTC
void uhal_rtc_handler(void)
{
    if (compare0_handler) {
        udrv_powersave_in_sleep = false;
        udrv_system_event_produce(&rui_rtc_event);

        if(uhal_mcu_sleep_status() == true)
        {
            // Resume peripherals...
            uhal_mcu_resume();

            udrv_system_event_consume();

            // Suspend peripherals...
            uhal_mcu_suspend();
        }

        alarm_cnt = 0;
    }
}

//*****************************************************************************
//
// Events associated with CTimer 3
//
//*****************************************************************************
void uhal_rtc_ctimer_handler(void)
{
    // Restart the one-shot timer for next 'tick'
    am_hal_ctimer_clear(3, AM_HAL_CTIMER_BOTH);

    am_log_inf("CTIMER Interrupt...");
    
    // if (compare0_handler) {
    //     compare0_handler(NULL);
    // }

    //uhal_rtc_handler();

    if( isInISR() ) 
    {
        BaseType_t xHigherPriorityTaskWoken, xResult;
        xSemaphoreGiveFromISR(rtc_semaphore, &xHigherPriorityTaskWoken);
        if (xResult != pdFAIL)
            portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
    } 
    else
    {
        xSemaphoreGive(rtc_semaphore);
    }
}

void rtc_event_task_handler(void *pvPaParameters)
{
    while(1)
    {
        xSemaphoreTake(rtc_semaphore, portMAX_DELAY);
        
        uhal_rtc_handler();

        // if (compare0_handler) {
        //     compare0_handler(NULL);
        // }
    }
}

int32_t uhal_rtc_init (RtcID_E timer_id, rtc_handler handler, uint32_t hz) {

    if (rtc_semaphore == NULL)
    {
        rtc_semaphore = xSemaphoreCreateBinary();
    }

    if(rtc_event_task == NULL)
    {
        xTaskCreate(
            (TaskFunction_t) rtc_event_task_handler,
            "CONS_EVT_TASK",
            configMINIMAL_STACK_SIZE*4,
            NULL,
            RAK_TASK_PRIO_HIGHEST,
            &rtc_event_task
        );
    }

    am_hal_ctimer_config_t cTimer0Config =
    {
        .ui32Link = 1,
        .ui32TimerAConfig = (AM_HAL_CTIMER_XT_32_768KHZ |
                             AM_HAL_CTIMER_FN_ONCE|
                             AM_HAL_CTIMER_INT_ENABLE),

        .ui32TimerBConfig = 0
    };

    //
    // Configure the timer frequency and mode.
    //
    am_hal_ctimer_config(3, &cTimer0Config);

    //
    // Clear timer interrupts
    //
    am_hal_ctimer_int_clear((1 << 3*2));

    //
    // Enable the interrupt for timer A0
    //
    am_hal_ctimer_int_enable(AM_HAL_CTIMER_INT_TIMERA3);

    //
    // Enable the timer interrupt in the NVIC, making sure to use the
    // appropriate priority level.
    //
    NVIC_SetPriority(CTIMER_IRQn, NVIC_configKERNEL_INTERRUPT_PRIORITY);
    am_hal_ctimer_int_register(AM_HAL_CTIMER_INT_TIMERA3, uhal_rtc_ctimer_handler);
    NVIC_EnableIRQ(CTIMER_IRQn);

    compare0_handler = handler;
    return 0;
}

int32_t uhal_rtc_set_alarm (RtcID_E timer_id, uint32_t count, void *m_data) {

    uint32_t current_time = uhal_rtc_get_counter(SYS_RTC_COUNTER_PORT);
    uint32_t elapsed_time = current_time - *(uint32_t*)m_data;
    uint32_t timeout_ticks = (count - elapsed_time);
    uint32_t compare_val = 0;

    if(timeout_ticks < max_ticks)
    {
        compare_val = timeout_ticks;
    }
    else
    {
        compare_val =  count - elapsed_time - (max_ticks /*-  *(uint32_t*)m_data */);
    }

    // udrv_gpio_set_dir((uint32_t) 44, GPIO_DIR_OUT);
    // udrv_gpio_set_logic((uint32_t) 44, GPIO_LOGIC_HIGH);
    // uint32_t ms = uhal_rtc_tick2ms(compare_val);
    // TEST_DEBUG("T: %d\r\n", ms);
    // udrv_gpio_set_logic((uint32_t) 44, GPIO_LOGIC_LOW);

    am_hal_ctimer_stop(3, AM_HAL_CTIMER_BOTH);
    am_hal_ctimer_clear(3, AM_HAL_CTIMER_BOTH);
    am_hal_ctimer_compare_set(3, AM_HAL_CTIMER_BOTH, 0, compare_val);

    am_hal_ctimer_start(3, AM_HAL_CTIMER_BOTH);

    alarm_cnt = 1;
    return 0;
}

int32_t uhal_rtc_cancel_alarm (RtcID_E timer_id) {

    alarm_cnt = 0;

    am_hal_ctimer_stop(3, AM_HAL_CTIMER_BOTH);
    am_hal_ctimer_clear(3, AM_HAL_CTIMER_BOTH);
    am_hal_ctimer_int_clear((1 << 3*2));
        
    return 0;
}

uint64_t uhal_rtc_get_counter (RtcID_E timer_id) {
    uint32_t now_counter = 0;
    now_counter = am_hal_stimer_counter_get();
    return  now_counter;
}

uint32_t uhal_rtc_get_counter_calculation_overflow(RtcID_E timer_id) {

    uint32_t now_counter = 0;
    now_counter = am_hal_stimer_counter_get();
    
    return  now_counter + counter_base;
}

uint64_t uhal_rtc_get_timestamp(RtcID_E timer_id){

    uint32_t ticks = am_hal_stimer_counter_get();
    return (uint64_t)(time_base + uhal_rtc_tick2ms(ticks));
}

uint64_t uhal_rtc_get_us_timestamp(RtcID_E timer_id)
{
    uint32_t ticks = am_hal_stimer_counter_get();

    return (uint64_t)(time_base + uhal_rtc_tick2us(ticks));
}

uint32_t uhal_rtc_get_elapsed_time (RtcID_E timer_id, uint32_t old_ts) {
    uint32_t ts = uhal_rtc_get_counter(timer_id);
    if(ts >= old_ts)
    {
        return (uint32_t)(ts - old_ts);
    }
    else
    {
        return  max_ticks - old_ts + ts;
    }
}

uint32_t uhal_rtc_get_max_ticks()
{
    return  max_ticks;
}

void uhal_rtc_suspend(void){
}

void uhal_rtc_resume(void){
}