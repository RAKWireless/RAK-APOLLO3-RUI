#include "uhal_dfu.h"
#include "udrv_flash.h"
#include "mcu_basic.h"

void uhal_enter_dfu (void)
{
    uint8_t buff = 0xAA;

    udrv_flash_write(MCU_BOOTLOADER_FLAG_LOCATION, 1, &buff); // Edited by Sercan ERAT
    NVIC_SystemReset();
}