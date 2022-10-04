#include "uhal_rtc.h"
#include "uhal_timer.h"
#include "uhal_powersave.h"
#include "udrv_rtc.h"
#include "am_log.h"

#include "FreeRTOSConfig.h"

extern bool udrv_powersave_in_sleep;

static uint32_t rtc_timer_context = 0;
static rtc_handler compare0_handler;
static uint32_t alarm_cnt = 0;
static udrv_system_event_t rui_rtc_event = {.request = UDRV_SYS_EVT_OP_RTC, .p_context = NULL};

void am_stimer_isr(void)
{
    // FIXME
    am_hal_stimer_int_clear(AM_HAL_STIMER_INT_OVERFLOW);
    am_log_inf("Overflow!!!"); // FIXME
    // At the fastest rate (3MHz) the 64 bits of the stimer
    // along with this overflow counter can keep track of
    // the time for ~ 195,000 years without wrapping to 0
}

uint32_t uhal_rtc_tick2ms(uint32_t tick) {
    return (uint32_t)((float) (tick*1000)/(float)SYS_RTC_FREQ);
}

uint32_t uhal_rtc_ms2tick(uint32_t ms) {
    return (uint32_t)((float)ms*(float)SYS_RTC_FREQ/(float)1000);
}

uint32_t uhal_rtc_sleep_mode_tick2ms(uint32_t tick) {
    return (uint32_t)((float)tick*(float)1000/(float)UHAL_RTC_SLEEP_MODE_FREQ);
}

uint32_t uhal_rtc_sleep_mode_ms2tick(uint32_t ms) {
    return (uint32_t)((float)ms*(float)UHAL_RTC_SLEEP_MODE_FREQ/(float)1000);
}

static TimerHandle_t uhal_timer_rtc;  /**< Definition of timer. */

void uhal_rtc_handler_handler(void *pdata)
{
    if (compare0_handler) {
        compare0_handler(NULL);

        am_log_inf("compare0 handler!!!!");
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
    }
    alarm_cnt = 0;

    am_log_inf("RTC ALARM INTERRUPT!!!!");
}

TimerHandle_t apollo3_timer_rtc = NULL;
int32_t uhal_rtc_init (RtcID_E timer_id, rtc_handler handler, uint32_t hz) {
    apollo3_timer_rtc = xTimerCreate("RTC",
                                  1,
                                  pdFALSE, // OneSHOT
                                  NULL,
                                  uhal_rtc_handler);

    compare0_handler = handler;

    if (apollo3_timer_rtc != NULL) {
        return 0;
    } else {
        return -1;
    }
}

int32_t uhal_rtc_set_alarm (RtcID_E timer_id, uint32_t count, void *m_data) {

    uint32_t period = uhal_rtc_tick2ms(count);
    if(period == 0)
        period = 1;

    xTimerChangePeriod( apollo3_timer_rtc,
                        (uint32_t) (period*1.024f), // This is not correct solution! FIX ME!
                        OSTIMER_WAIT_FOR_QUEUE );

    // Start application timers.
    if (pdPASS != xTimerStart(apollo3_timer_rtc, OSTIMER_WAIT_FOR_QUEUE))
    {
        return -1;
    }
    else {
        alarm_cnt = 1;
        am_log_inf("Start timer: %d!!!!", uhal_rtc_tick2ms(count));
        return 0;
    }
}

int32_t uhal_rtc_cancel_alarm (RtcID_E timer_id) {

    alarm_cnt = 0;

    am_log_inf("Stop timer...");
        
    // Start application timers.
    if (pdPASS != xTimerStop(apollo3_timer_rtc, OSTIMER_WAIT_FOR_QUEUE))
    {
        return -1;
    }
    else {
        return 0;
    }
}

uint64_t uhal_rtc_get_counter (RtcID_E timer_id) {
    return (am_hal_stimer_counter_get() & 0xFFFFFFFF);
}

uint64_t uhal_rtc_get_timestamp(RtcID_E timer_id){
    uint32_t tick = (am_hal_stimer_counter_get() & 0xFFFFFFFF);
    return (uint32_t)((float)tick*(float)1023/(float)32768);
}

uint64_t uhal_rtc_get_elapsed_time (RtcID_E timer_id, uint64_t old_ts) {

    uint64_t ts = uhal_rtc_get_timestamp(0);

    if (old_ts < ts) {
        am_log_inf("Elapsed time: %d", (ts - old_ts));
        return (uint64_t)(ts - old_ts);
    } else {
        return 0;
    }
}

void uhal_rtc_suspend(void){
}

void uhal_rtc_resume(void){
}