#include "stdbool.h"
#include "udrv_errno.h"
#include "uhal_timer.h"
#include "uhal_powersave.h"
#include "udrv_system.h"
#include "uhal_rtc.h"

// This file exists solely for compilation compatibility with legacy libraries
// Test if in interrupt mode
static inline bool isInISR(void)
{
  return (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0 ;
}

extern bool udrv_powersave_in_sleep;

static TimerHandle_t uhal_timer_id0;  /**< Definition of timer. */
static TimerHandle_t uhal_timer_id1;  /**< Definition of timer. */
static TimerHandle_t uhal_timer_id2;  /**< Definition of timer. */
static TimerHandle_t uhal_timer_id3;  /**< Definition of timer. */
static TimerHandle_t uhal_timer_id4;  /**< Definition of timer. */
static TimerHandle_t uhal_sys_timer_id0;  /**< Definition of timer. */
static TimerHandle_t uhal_sys_timer_id1;  /**< Definition of timer. */
static TimerHandle_t uhal_sys_timer_id2;  /**< Definition of timer. */
static TimerHandle_t uhal_sys_timer_id3;  /**< Definition of timer. */
static TimerHandle_t uhal_sys_timer_id4;  /**< Definition of timer. */

static uhal_timer_data uhal_timer_pdata[TIMER_ID_MAX];
static uhal_timer_data uhal_sys_timer_pdata[SYSTIMER_ID_MAX];

static udrv_system_event_t rui_user_timer_event[TIMER_ID_MAX];
static udrv_system_event_t rui_sys_timer_event[SYSTIMER_ID_MAX];

static TimerID_E get_apollo_timer_number(TimerHandle_t task)
{
  if( task == uhal_timer_id0)
   return TIMER_0;
  if( task == uhal_timer_id1)
   return TIMER_1;
  if( task == uhal_timer_id2)
   return TIMER_2;
  if( task == uhal_timer_id3)
   return TIMER_3;
  if( task == uhal_timer_id4)
   return TIMER_4;
  else
   return (TimerID_E) NULL;        
}

static SysTimerID_E get_sys_apollo_timer_number(TimerHandle_t task)
{
    if( task == uhal_sys_timer_id0)
     return SYSTIMER_LORAWAN;
    if( task == uhal_sys_timer_id1)
     return SYSTIMER_TRANSPARENT_MODE;
    if( task == uhal_sys_timer_id2)
     return SYSTIMER_PROTOCOL_MODE;
    if( task == uhal_sys_timer_id3)
     return SYSTIMER_LED;
    if( task == uhal_sys_timer_id4)
     return SYSTIMER_LCT;
    else
     return (SysTimerID_E) NULL; 
}

void uhal_timer_handler_handler(void *pdata)
{
    if (((uhal_timer_data *)pdata)->timer_func) {
        ((uhal_timer_data *)pdata)->timer_func(((uhal_timer_data *)pdata)->m_data);
    }
}

static void uhal_timer_handler_dispatcher(TimerHandle_t xTimer)
{
    udrv_powersave_in_sleep = false;

    TimerID_E timer_id = get_apollo_timer_number(xTimer);

    rui_user_timer_event[timer_id].request = UDRV_SYS_EVT_OP_USER_TIMER;
    rui_user_timer_event[timer_id].p_context = (void *)&uhal_timer_pdata[timer_id];
    udrv_system_event_produce(&rui_user_timer_event[timer_id]);

    if(uhal_mcu_sleep_status() == true)
    {
        // Resume peripherals...
        uhal_mcu_resume();

        udrv_system_event_consume();

        // Suspend peripherals...
        uhal_mcu_suspend();
    }
}

static void uhal_sys_timer_handler_dispatcher(TimerHandle_t xTimer)
{
    udrv_powersave_in_sleep = false;

    SysTimerID_E timer_id = get_sys_apollo_timer_number(xTimer);

    rui_sys_timer_event[timer_id].request = UDRV_SYS_EVT_OP_SYS_TIMER;
    rui_sys_timer_event[timer_id].p_context = (void *)&uhal_sys_timer_pdata[timer_id];
    udrv_system_event_produce(&rui_sys_timer_event[timer_id]);

    if(uhal_mcu_sleep_status() == true)
    {
        // Resume peripherals...
        uhal_mcu_resume();

        udrv_system_event_consume();

        // Suspend peripherals...
        uhal_mcu_suspend();
    }
}

UBaseType_t get_apollo_timer_mode(TimerMode_E mode)
{
    switch(mode)
    {
        case HTMR_ONESHOT: return pdFALSE;
        case HTMR_PERIODIC: return pdTRUE;
        default: return pdTRUE;
    }
}

static TimerHandle_t get_apollo_timer_id(TimerID_E timer_id)
{
    switch(timer_id)
    {
        case TIMER_0: return uhal_timer_id0;
        case TIMER_1: return uhal_timer_id1;
        case TIMER_2: return uhal_timer_id2;
        case TIMER_3: return uhal_timer_id3;
        case TIMER_4: return uhal_timer_id4;
        default: return NULL;
    }
}

static void set_apollo_timer_id(TimerID_E timer_id, TimerHandle_t handle)
{
    switch(timer_id)
    {
        case TIMER_0: 
            uhal_timer_id0 = handle;
            break;
        case TIMER_1: 
            uhal_timer_id1 = handle;
            break;
        case TIMER_2: 
            uhal_timer_id2 = handle;
            break;
        case TIMER_3: 
            uhal_timer_id3 = handle;
            break;
        case TIMER_4: 
            uhal_timer_id4 = handle;
            break;
        default: return;
    }
}

static TimerHandle_t get_sys_apollo_timer_id(SysTimerID_E timer_id)
{
    switch(timer_id)
    {
        case SYSTIMER_LORAWAN: return uhal_sys_timer_id0;
        case SYSTIMER_TRANSPARENT_MODE: return uhal_sys_timer_id1;
        case SYSTIMER_PROTOCOL_MODE: return uhal_sys_timer_id2;
        case SYSTIMER_LED: return uhal_sys_timer_id3;
        case SYSTIMER_LCT: return uhal_sys_timer_id4;
        default: return NULL;
    }
}

static void set_sys_apollo_timer_id(SysTimerID_E timer_id, TimerHandle_t handle)
{
    switch(timer_id)
    {
        case SYSTIMER_LORAWAN: 
            uhal_sys_timer_id0 = handle;
        case SYSTIMER_TRANSPARENT_MODE: 
            uhal_sys_timer_id1 = handle;
        case SYSTIMER_PROTOCOL_MODE:
            uhal_sys_timer_id2 = handle;
        case SYSTIMER_LED:
            uhal_sys_timer_id3 = handle;
        case SYSTIMER_LCT:
            uhal_sys_timer_id4 = handle;
        default: return;
    }
}

void uhal_timer_init (void) {

    return;
}

int32_t uhal_timer_create (TimerID_E timer_id, timer_handler tmr_handler, TimerMode_E mode) {
    TimerHandle_t apollo3_timer_id = get_apollo_timer_id(timer_id);

    uhal_timer_pdata[timer_id].timer_id = timer_id;
    uhal_timer_pdata[timer_id].timer_func = tmr_handler;

    if(apollo3_timer_id != NULL)
    {
        if(pdPASS != xTimerDelete(apollo3_timer_id, OSTIMER_WAIT_FOR_QUEUE))
        {
            return -UDRV_INTERNAL_ERR;
        }
        set_apollo_timer_id(timer_id, NULL);
        apollo3_timer_id = NULL;
    }

    apollo3_timer_id = xTimerCreate("TMR",
                              1,
                              get_apollo_timer_mode(mode),
                              NULL,
                              uhal_timer_handler_dispatcher);

    if (apollo3_timer_id != NULL) {
        set_apollo_timer_id(timer_id, apollo3_timer_id);
        return UDRV_RETURN_OK;
    } else {
        return -UDRV_INTERNAL_ERR;
    }
}

int32_t uhal_timer_start (TimerID_E timer_id, uint32_t count, void *m_data) {
    TimerHandle_t apollo3_timer_id = get_apollo_timer_id(timer_id);

    if(count == 0)
        return -UDRV_INTERNAL_ERR;

    if(apollo3_timer_id != NULL)
    {
        uhal_timer_pdata[timer_id].timer_id = timer_id;
        uhal_timer_pdata[timer_id].m_data = m_data;

        if( isInISR() ) 
        {
            BaseType_t xHigherPriorityTaskWoken = pdFALSE;
            if(pdPASS != xTimerStopFromISR(apollo3_timer_id, xHigherPriorityTaskWoken))
            {
                return -UDRV_INTERNAL_ERR;
            }

            if(xHigherPriorityTaskWoken != pdFALSE)
            {
                portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
            }
            
            if(pdPASS != xTimerChangePeriodFromISR( apollo3_timer_id,
                            (uint32_t) (count*1.024f), // This is not correct solution! FIX ME!
                            &xHigherPriorityTaskWoken ))
            {
                return -UDRV_INTERNAL_ERR;
            }

            if(xHigherPriorityTaskWoken != pdFALSE)
            {
                portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
            }

            if(pdPASS != xTimerStartFromISR(apollo3_timer_id, &xHigherPriorityTaskWoken))
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
            if(pdPASS != xTimerStop(apollo3_timer_id, OSTIMER_WAIT_FOR_QUEUE))
            {
                return -UDRV_INTERNAL_ERR;
            }

            if(pdPASS != xTimerChangePeriod( apollo3_timer_id,
                            (uint32_t) (count*1.024f), // This is not correct solution! FIX ME!
                            OSTIMER_WAIT_FOR_QUEUE ))
            {
                return -UDRV_INTERNAL_ERR;
            }

            // Start application timers.
            if (pdPASS != xTimerStart(apollo3_timer_id, OSTIMER_WAIT_FOR_QUEUE))
            {
                return -UDRV_INTERNAL_ERR;
            }
        }

        return UDRV_RETURN_OK;
    }

    return -UDRV_INTERNAL_ERR;
}

int32_t uhal_timer_stop (TimerID_E timer_id) {
    TimerHandle_t apollo3_timer_id = get_apollo_timer_id(timer_id);

    if(apollo3_timer_id != NULL)
    {
        uhal_timer_pdata[timer_id].m_data = NULL;

        if( isInISR() ) 
        {
            BaseType_t xHigherPriorityTaskWoken = pdFALSE;
            if(pdPASS != xTimerStop(apollo3_timer_id, &xHigherPriorityTaskWoken))
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
            if (pdPASS != xTimerStop(apollo3_timer_id, OSTIMER_WAIT_FOR_QUEUE))
            {
                return -UDRV_INTERNAL_ERR;
            }
        }

        return UDRV_RETURN_OK;
    }

    return -UDRV_INTERNAL_ERR;
}

int32_t uhal_sys_timer_create (SysTimerID_E timer_id, timer_handler tmr_handler, TimerMode_E mode) {
     TimerHandle_t apollo3_timer_id = get_sys_apollo_timer_id(timer_id);

    uhal_sys_timer_pdata[timer_id].sys_timer_id = timer_id;
    uhal_sys_timer_pdata[timer_id].timer_func = tmr_handler;

    if(apollo3_timer_id != NULL)
    {
        if(pdPASS != xTimerDelete(apollo3_timer_id, OSTIMER_WAIT_FOR_QUEUE))
        {
            return -UDRV_INTERNAL_ERR;            
        }
        set_sys_apollo_timer_id(timer_id, NULL);
        apollo3_timer_id = NULL;
    }

    apollo3_timer_id = xTimerCreate("SYS_TMR",
                                1,
                                get_apollo_timer_mode(mode),
                                NULL,
                                uhal_sys_timer_handler_dispatcher);

    if (apollo3_timer_id != NULL) {
        set_sys_apollo_timer_id(timer_id, apollo3_timer_id);
        return UDRV_RETURN_OK;
    } else {
        return -UDRV_INTERNAL_ERR;
    }
}

int32_t uhal_sys_timer_start (SysTimerID_E timer_id, uint32_t count, void *m_data) {
    TimerHandle_t apollo3_timer_id = get_sys_apollo_timer_id(timer_id);

    if(count == 0)
        return -UDRV_INTERNAL_ERR;
        
    if(apollo3_timer_id != NULL)
    {
        uhal_sys_timer_pdata[timer_id].sys_timer_id = timer_id;
        uhal_sys_timer_pdata[timer_id].m_data = m_data;

        if( isInISR() ) 
        {
            BaseType_t xHigherPriorityTaskWoken = pdFALSE;
            if(pdPASS != xTimerStopFromISR(apollo3_timer_id, xHigherPriorityTaskWoken))
            {
                return -UDRV_INTERNAL_ERR;
            }

            if(xHigherPriorityTaskWoken != pdFALSE)
            {
                portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
            }
            
            if(pdPASS != xTimerChangePeriodFromISR( apollo3_timer_id,
                            (uint32_t) (count*1.024f), // This is not correct solution! FIX ME!
                            &xHigherPriorityTaskWoken ))
            {
                return -UDRV_INTERNAL_ERR;
            }

            if(xHigherPriorityTaskWoken != pdFALSE)
            {
                portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
            }

            if(pdPASS != xTimerStartFromISR(apollo3_timer_id, &xHigherPriorityTaskWoken))
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
            if(pdPASS != xTimerStop(apollo3_timer_id, OSTIMER_WAIT_FOR_QUEUE))
            {
                return -UDRV_INTERNAL_ERR;
            }

            if(pdPASS != xTimerChangePeriod(apollo3_timer_id,
                            (uint32_t) (count*1.024f), // This is not correct solution! FIX ME!
                            OSTIMER_WAIT_FOR_QUEUE ))
            {
                return -UDRV_INTERNAL_ERR;
            }

            // Start application timers.
            if (pdPASS != xTimerStart(apollo3_timer_id, OSTIMER_WAIT_FOR_QUEUE))
            {
                return -UDRV_INTERNAL_ERR;
            }
        }

        return UDRV_RETURN_OK;
    }

    return -UDRV_INTERNAL_ERR;
}

int32_t uhal_sys_timer_stop (SysTimerID_E timer_id) {
    TimerHandle_t apollo3_timer_id = get_sys_apollo_timer_id(timer_id);

    if(apollo3_timer_id != NULL)
    {
        uhal_timer_pdata[timer_id].m_data = NULL;

        if( isInISR() ) 
        {
            BaseType_t xHigherPriorityTaskWoken = pdFALSE;
            if(pdPASS != xTimerStop(apollo3_timer_id, &xHigherPriorityTaskWoken))
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
            if (pdPASS != xTimerStop(apollo3_timer_id, OSTIMER_WAIT_FOR_QUEUE))
            {
                return -UDRV_INTERNAL_ERR;
            }
        }

        return UDRV_RETURN_OK;
    }

    return -UDRV_INTERNAL_ERR;
}

uint64_t uhal_get_microsecond(void)
{
    return uhal_rtc_get_us_timestamp((RtcID_E)SYS_RTC_COUNTER_PORT);
}