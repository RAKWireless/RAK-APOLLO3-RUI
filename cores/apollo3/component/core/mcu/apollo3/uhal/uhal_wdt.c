#include "uhal_wdt.h"
#include "am_bsp.h"
#include "am_util.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
static uint32_t wdt_period;
static TimerHandle_t wdt_timerhandler;
/*
const am_hal_wdt_config_t Config =
{
    .ui32Config =
        AM_HAL_WDT_LFRC_CLK_1_16HZ                      |
        AM_HAL_WDT_ENABLE_RESET                         |
        AM_HAL_WDT_ENABLE_INTERRUPT,
    //
    // Set WDT interrupt timeout for 3/4 second.
    //
    .ui16InterruptCount = 0xFFFF,

    //
    // Set WDT reset timeout for 1.5 seconds.
    //
    .ui16ResetCount = 5
};
void
am_watchdog_isr(void)
{
    //
    // Clear the watchdog interrupt.
    //
    am_hal_wdt_int_clear();

    am_hal_wdt_restart();
}
*/
static WDT_TimerCallback(TimerHandle_t pxTimer)
{
    NVIC_SystemReset();
}
void uhal_wdt_feed(void)
{
    //am_hal_wdt_restart();
    xTimerReset( wdt_timerhandler, wdt_period );
}

void uhal_wdt_init(uint32_t period)
{
    /*
    am_hal_wdt_halt();
    am_hal_clkgen_control(AM_HAL_CLKGEN_CONTROL_LFRC_START, 0);
    am_hal_wdt_init(&Config);
    
    am_hal_wdt_restart();
    am_hal_wdt_start();
    */
    if(period != 15 && period != 30 && period != 60 && period != 120 && period != 250 && period != 500 && period != 1000 && period != 2000 && period != 4000 && period != 8000 )
    {
        period = 8000;
    }
    wdt_period = period *1.024f;
    wdt_timerhandler = xTimerCreate("WDT",wdt_period,0,NULL,WDT_TimerCallback);
    xTimerStart( wdt_timerhandler, 0 );
}

