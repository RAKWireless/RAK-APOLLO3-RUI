#ifndef _UHAL_POWERSAVE_H_
#define _UHAL_POWERSAVE_H_

#include <stdint.h>
#include <stddef.h>
#include "fund_event_queue.h"
#include "udrv_powersave.h"
#include "udrv_timer.h"
#include "am_mcu_apollo.h"
#include "am_util.h"

//*****************************************************************************
//
// FreeRTOS include files.
//
//*****************************************************************************
#include "FreeRTOS.h"
#include "task.h"
#include "event_groups.h"
#include "semphr.h"
#include "event_groups.h"

void uhal_mcu_sleep (void);
void uhal_mcu_wake_up (void);
void uhal_sys_clock_init(void);
void uhal_sys_clock_on(void);
void uhal_sys_clock_off(void);
int32_t uhal_ps_timer_create (timer_handler tmr_handler, TimerMode_E mode);
int32_t uhal_ps_timer_start (uint32_t count, void *m_data);
int32_t uhal_ps_timer_stop ();

void uhal_mcu_resume(void);
void uhal_mcu_suspend(void);
bool uhal_mcu_sleep_status(void);

#endif  // #ifndef _UHAL_POWERSAVE_H_
