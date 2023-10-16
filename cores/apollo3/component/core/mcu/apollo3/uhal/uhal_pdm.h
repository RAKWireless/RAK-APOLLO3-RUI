#ifndef _UHAL_PDM_H_
#define _UHAL_PDM_H_

#include <stdint.h>
#include <stddef.h>
#include "pin_define.h"
#include "udrv_serial.h"
#include "udrv_pdm.h"

extern void uhal_pdm_enable_frequency(void) __attribute__((weak));
extern bool uhal_pdm_set_rate(long rate) __attribute__((weak));
extern bool uhal_pdm_set_channel(int channels) __attribute__((weak));
extern void uhal_pdm_psel_connect(uint32_t psel_clk,uint32_t psel_din) __attribute__((weak));
extern void uhal_pdm_event_clear(udrv_pdm_event_t event) __attribute__((weak));
extern void uhal_pdm_int_enable(void) __attribute__((weak));
extern void uhal_pdm_set_nvic(void) __attribute__((weak));
extern void uhal_pdm_enable(void) __attribute__((weak));
extern void uhal_pdm_task_trigger(udrv_pdm_task_t task) __attribute__((weak));
extern void uhal_pdm_disable(void) __attribute__((weak));
extern void uhal_pdm_disable_nvic(void) __attribute__((weak));
extern void uhal_pdm_enable_nvic(void) __attribute__((weak));
extern void uhal_pdm_psel_disconnect(void) __attribute__((weak));
extern void uhal_pdm_set_gain(int gain) __attribute__((weak));
extern bool uhal_pdm_event_check(udrv_pdm_event_t event) __attribute__((weak));
extern bool uhal_pdm_buffer_set(uint32_t * p_buffer, uint32_t num) __attribute__((weak));
 
#endif  // #ifndef _UHAL_PDM_H_
