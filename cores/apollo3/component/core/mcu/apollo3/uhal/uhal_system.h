#ifndef _UHAL_SYSTEM_H_
#define _UHAL_SYSTEM_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "udrv_errno.h"
#include "udrv_system.h"
#include "udrv_timer.h"

#include "am_mcu_apollo.h"
#include "am_bsp.h"
#include "am_util.h"
#include "am_log.h"


void uhal_sys_reboot(void);

void uhal_sys_board_critical_section_begin(uint32_t *mask);

void uhal_sys_board_critical_section_end(uint32_t *mask);

void uhal_sys_randomseed(unsigned long seed);

unsigned long uhal_sys_random (unsigned long maxvalue);

int32_t uhal_sys_user_app_timer_create (timer_handler tmr_handler, TimerMode_E mode);

int32_t uhal_sys_user_app_timer_start (uint32_t count, void *m_data);

int32_t uhal_sys_user_app_timer_stop (void);

#endif  // #ifndef _UHAL_SYSTEM_H_
