#include "uhal_flash.h"

void uhal_flash_init (void) {
}

void uhal_flash_deinit (void) {
}

int32_t uhal_flash_write (uint32_t addr, uint8_t *buff, uint32_t len) {

    uint32_t *pui32Dst = (uint32_t *) addr;
    int32_t i32ReturnCode = am_hal_flash_program_main(AM_HAL_FLASH_PROGRAM_KEY,
                                              (uint32_t *) buff,
                                              pui32Dst,
                                              (len/4));

    //
    // Check for an error from the HAL.
    //
    if (i32ReturnCode)
    {
        am_log_inf("FLASH program page at 0x%08x i32ReturnCode = 0x%x.", addr,
                                                                         i32ReturnCode);

	    return -UDRV_INTERNAL_ERR;
    }

    am_log_inf("WRITE program page at 0x%08x", addr);

    return UDRV_RETURN_OK;
}

int32_t uhal_flash_read (uint32_t addr, uint8_t *buff, uint32_t len) {
    memcpy(buff, (uint32_t*) addr, len);
    
    am_log_inf("READ program page at 0x%08x", addr);

    return UDRV_RETURN_OK;
}

int32_t uhal_flash_erase (uint32_t addr, uint32_t len) {
    
    uint32_t page_cnt = len / uhal_flash_get_page_size();
    
    for(uint16_t i = 0; i<page_cnt; i++)
    {
        int32_t i32ReturnCode = am_hal_flash_page_erase(AM_HAL_FLASH_PROGRAM_KEY,
                                                AM_HAL_FLASH_ADDR2INST((addr + (len*0x2000))),
                                                AM_HAL_FLASH_ADDR2PAGE((addr+ (len*0x2000))));
        //
        // Check for an error from the HAL.
        //
        if (i32ReturnCode)
        {
            am_log_inf(" FLASH erase page at 0x%08x i32ReturnCode =  0x%x.", addr + (len*0x2000), 
                                                                             i32ReturnCode);
            return -UDRV_INTERNAL_ERR;
        }
    }

    am_log_inf("ERASE program page at 0x%08x", addr);

    return UDRV_RETURN_OK;
}

uint32_t uhal_flash_get_page_size(void) {
    return AM_HAL_FLASH_PAGE_SIZE;
}

bool uhal_flash_check_addr_valid(uint32_t addr, uint32_t len) {
    return 0;
}

void uhal_flash_suspend(void) {
}

void uhal_flash_resume(void) {
}
