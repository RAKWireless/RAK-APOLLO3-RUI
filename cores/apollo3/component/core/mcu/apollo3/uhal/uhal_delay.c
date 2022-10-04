#include "uhal_delay.h"

void uhal_delay_ms (uint32_t ms_time)
{
    am_util_delay_ms(ms_time);
}

void uhal_delay_us (uint32_t us_time)
{
    am_util_delay_us(us_time);
}
