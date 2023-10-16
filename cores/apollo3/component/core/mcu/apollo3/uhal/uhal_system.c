#include "uhal_system.h"

#ifndef RUI_BOOTLOADER
#include "uhal_timer.h"

//*****************************************************************************
//
// FreeRTOS include files.
//
//*****************************************************************************
#include "FreeRTOS.h"
#include "task.h"
#include "event_groups.h"

static uint8_t seed_data[SEED_LENGTH];

static TimerHandle_t uhal_system_user_app_timer_id;  /**< Definition of timer. */

static timer_handler system_tmr_handler;
static void *p_context = NULL;

static inline bool isInISR(void)
{
  return (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0 ;
}

static void uhal_system_timer_handler(TimerHandle_t xTimer)
{
    system_tmr_handler(p_context);
}

#endif

void uhal_sys_reboot(void)
{
    NVIC_SystemReset();
}

void uhal_sys_board_critical_section_begin(uint32_t *mask)
{
    *mask = __get_PRIMASK();
    __disable_irq();

    //*mask = am_hal_interrupt_master_disable();
}

void uhal_sys_board_critical_section_end(uint32_t *mask)
{
    __set_PRIMASK(*mask);
    //am_hal_interrupt_master_set(*mask);
}

#ifndef RUI_BOOTLOADER

void uhal_sys_randomseed(unsigned long seed) {
    seed_data[0] = (uint8_t)((seed & 0XFF));
    seed_data[1] = (uint8_t)((seed >> 8) & 0xFF) ;
    seed_data[2] = (uint8_t)((seed >> 16) & 0xFF) ;
    seed_data[3] = (uint8_t)((seed >> 24) & 0XFF);
}

unsigned long uhal_sys_random (unsigned long maxvalue) {
    //FIXME
}

int32_t uhal_sys_user_app_timer_create (timer_handler tmr_handler, TimerMode_E mode) {
    
    if(uhal_system_user_app_timer_id == NULL)
    {
        uhal_system_user_app_timer_id = xTimerCreate("TMR_SYSTEM",
                                                    1,
                                                    get_apollo_timer_mode(mode),
                                                    NULL,
                                                    uhal_system_timer_handler);
    }

    system_tmr_handler = tmr_handler;

    if (uhal_system_user_app_timer_id != NULL) {
        return UDRV_RETURN_OK;
    } else {
        return -UDRV_INTERNAL_ERR;
    }
}

int32_t uhal_sys_user_app_timer_start (uint32_t count, void *m_data) {
    
    if (uhal_system_user_app_timer_id == NULL) {
        return -UDRV_INTERNAL_ERR;
    }

    if(count == 0)
        return -UDRV_INTERNAL_ERR;

    p_context = m_data;

    if( isInISR() ) 
    {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        if(pdPASS != xTimerStopFromISR(uhal_system_user_app_timer_id, xHigherPriorityTaskWoken))
        {
            return -UDRV_INTERNAL_ERR;
        }

        if(xHigherPriorityTaskWoken != pdFALSE)
        {
            portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }
        
        if(pdPASS != xTimerChangePeriodFromISR( uhal_system_user_app_timer_id,
                        (uint32_t) (count*1.024f), // This is not correct solution! FIX ME!
                        &xHigherPriorityTaskWoken ))
        {
            return -UDRV_INTERNAL_ERR;
        }

        if(xHigherPriorityTaskWoken != pdFALSE)
        {
            portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }

        if(pdPASS != xTimerStartFromISR(uhal_system_user_app_timer_id, &xHigherPriorityTaskWoken))
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
        if(pdPASS != xTimerStop(uhal_system_user_app_timer_id, OSTIMER_WAIT_FOR_QUEUE))
        {
            return -UDRV_INTERNAL_ERR;
        }

        if(pdPASS != xTimerChangePeriod( uhal_system_user_app_timer_id,
                        (uint32_t) (count*1.024f), // This is not correct solution! FIX ME!
                        OSTIMER_WAIT_FOR_QUEUE ))
        {
            return -UDRV_INTERNAL_ERR;
        }

        // Start application timers.
        if (pdPASS != xTimerStart(uhal_system_user_app_timer_id, OSTIMER_WAIT_FOR_QUEUE))
        {
            return -UDRV_INTERNAL_ERR;
        }
    }

    return UDRV_RETURN_OK;
}

int32_t uhal_sys_user_app_timer_stop (void) {
    
    if (uhal_system_user_app_timer_id == NULL) {
        return -UDRV_INTERNAL_ERR;
    }

    if( isInISR() ) 
    {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        if(pdPASS != xTimerStop(uhal_system_user_app_timer_id, &xHigherPriorityTaskWoken))
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
        if (pdPASS != xTimerStop(uhal_system_user_app_timer_id, OSTIMER_WAIT_FOR_QUEUE))
        {
            return -UDRV_INTERNAL_ERR;
        }
    }

    return UDRV_RETURN_OK;
}
#endif