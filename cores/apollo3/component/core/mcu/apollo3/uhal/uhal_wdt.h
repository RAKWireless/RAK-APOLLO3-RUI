#ifndef _UHAL_WDT_H_
#define _UHAL_WDT_H_

#include "udrv_wdt.h"

#define WDT_FEED_PERIOD     8*1000

void uhal_wdt_feed(void);

void uhal_wdt_init(uint32_t period);

#endif
