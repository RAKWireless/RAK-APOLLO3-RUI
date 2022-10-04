#include "uhal_dfu.h"
#include "udrv_flash.h"

void uhal_enter_dfu (void)
{
    uint8_t buff = 0xAA;

    udrv_flash_write(0x000F8000, 1, &buff); // Edited by Sercan ERAT
    NVIC_SystemReset();
}