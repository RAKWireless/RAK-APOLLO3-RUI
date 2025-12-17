#ifndef __MCU_BASIC_H__
#define __MCU_BASIC_H__

/* ***********************************
   * Memory Map of Apollo3 MCU Flash *
   ***********************************

  0x0000_0000      0x0000_0C000         0x0001_4000           0x0008_4000               0x000F_4000                             0x000F_FFFF
 /                /                    /                     /                         /                                       /
/                /                    /                     /                         /                                       /
|                |  Bootloader        |  Main application   |  OTA application region |  Memory regions (see #defines bellow) |
|----------------|--------------------|---------------------|-------------------------|---------------------------------------|
|  48KB          |  32KB              |  448KB              |  448KB                  |  48KB                                 |
-------------------------------------------------------------------------------------------------------------------------------
|                                                       Total: 1MB                                                            |
-------------------------------------------------------------------------------------------------------------------------------
*/

#define END_OF_FLASH_ADDRESS            0x000FFFFF  // 1MB

#define MCU_FLASH_OTA_ADDRESS           0x00084000
#define MCU_FLASH_OTA_ADDRESS_UART      0x00014000  // Not sure why this is called UART OTA address when it's the base address of main application

#define MCU_BOOTLOADER_FLAG_LOCATION    0x000FE000  // 8192 bytes [8 KB]
#define MCU_USER_DATA_NVM_ADDR          0x000FC000  // 8192 bytes [8 KB]
#define MCU_BLE_NVM_LOCATION            0x000FA000  // 8192 bytes [8 KB]
#define MCU_OTA_POINTER_LOCATION        0x000F8000  // 8192 bytes [8 KB]

#define MCU_FACTORY_DEFAULT_NVM_ADDR    0x000F6000  // 8192 bytes [8 KB]
#define MCU_CERT_CONFIG_NVM_ADDR        0x000F4500  // 6912 bytes [6.75 KB]
#define MCU_SYS_CONFIG_NVM_ADDR         0x000F4000  // 1280 bytes [1.25 KB]


#define MCU_BOOTLOADER_FLAG_SIZE        (END_OF_FLASH_ADDRESS+1 - MCU_BOOTLOADER_FLAG_LOCATION)
#define MCU_USER_DATA_NVM_SIZE          (MCU_BOOTLOADER_FLAG_LOCATION - MCU_USER_DATA_NVM_ADDR)
#define MCU_BLE_NVM_SIZE                (MCU_USER_DATA_NVM_ADDR - MCU_BLE_NVM_LOCATION)
#define MCU_OTA_POINTER_SIZE            (MCU_BLE_NVM_LOCATION - MCU_OTA_POINTER_LOCATION)

#define MCU_FACTORY_DEFAULT_NVM_SIZE    (MCU_OTA_POINTER_LOCATION - MCU_FACTORY_DEFAULT_NVM_ADDR)
#define MCU_CERT_CONFIG_NVM_SIZE        (MCU_FACTORY_DEFAULT_NVM_ADDR - MCU_CERT_CONFIG_NVM_ADDR)
#define MCU_SYS_CONFIG_NVM_SIZE         (MCU_CERT_CONFIG_NVM_ADDR - MCU_SYS_CONFIG_NVM_ADDR)

#endif
