#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "am_mcu_apollo.h"
#include "am_util.h"

#include "uhal_trng.h"

static volatile uint32_t data_received = 0;

//******************************************************************************
//
// Callback function for entropy generator - Called when data has been transferred.
//
//******************************************************************************
void entropy_complete_callback(void *context)
{
    uint32_t *flag = (uint32_t *) context;
    *flag = 1;
}

void uhal_trng_init(void)
{
    //
    // Initialize the entropy hardware.
    //
    am_hal_entropy_init();
}

void uhal_trng_get_values(uint8_t *output, uint32_t length)
{
    //
    // Start the entropy generator. It won't produce anything until we ask for data, but
    //
    am_hal_entropy_enable();

    data_received = 0;
    am_hal_entropy_get_values(output, length, entropy_complete_callback, (void *) &data_received);

    //
    // Note: we can't sleep here because it would stop the SysTick timer,
    // which is part of the entropy generation method.
    //
    while (data_received == 0);

    // Disable the entropy generator.
    am_hal_entropy_disable();
}
