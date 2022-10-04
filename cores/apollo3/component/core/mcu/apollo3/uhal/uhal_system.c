#include "uhal_system.h"
#include "uhal_timer.h"

//*****************************************************************************
//
// FreeRTOS include files.
//
//*****************************************************************************
#include "FreeRTOS.h"
#include "task.h"
#include "event_groups.h"

//static uint8_t is_seed = 0;
//static uint8_t seed_data[SEED_LENGTH];

static TimerHandle_t uhal_system_user_app_timer_id;  /**< Definition of timer. */

static timer_handler system_tmr_handler;
static void *p_context = NULL;

static void uhal_system_timer_handler(TimerHandle_t xTimer)
{
    system_tmr_handler(p_context);
}

void uhal_sys_reboot(void)
{
    NVIC_SystemReset();
}

#ifndef RUI_BOOTLOADER
void uhal_sys_board_critical_section_begin(uint32_t *mask)
{
    *mask = __get_PRIMASK();
    __disable_irq();

    //*mask = am_hal_interrupt_master_disable();
}

void uhal_sys_board_critical_section_end(uint32_t *mask)
{
    __set_PRIMASK(*mask);
    //am_hal_interrupt_master_set(*mask);
}

//static int32_t uhal_sys_crypto_init(void)
//{
//    uint32_t err_code = NRF_ERROR_INTERNAL;
//    err_code = nrf_crypto_init();
//    
//    switch (err_code) {
//        case NRF_SUCCESS:
//            return UDRV_RETURN_OK;
//        default:
//            return -UDRV_INTERNAL_ERR;
//    }
//
//}

//static int32_t uhal_sys_crypto_uninit(void)
//{
//    uint32_t err_code = NRF_ERROR_INTERNAL;
//    err_code = nrf_crypto_uninit();
//    
//    switch (err_code) {
//        case NRF_SUCCESS:
//            return UDRV_RETURN_OK;
//        default:
//            return -UDRV_INTERNAL_ERR;
//    }
//}

//static int32_t uhal_sys_crypto_rng_init(nrf_crypto_rng_context_t * p_context, nrf_crypto_rng_temp_buffer_t * p_temp_buffer)
//{
//    uint32_t err_code = NRF_ERROR_INTERNAL;
//    err_code = nrf_crypto_rng_init(p_context, p_temp_buffer);
//    
//    switch (err_code) {
//        case NRF_SUCCESS:
//            return UDRV_RETURN_OK;
//        default:
//            return -UDRV_INTERNAL_ERR;
//    }
//}

//static int32_t uhal_sys_crypto_rng_uninit(void)
//{
//    uint32_t err_code = NRF_ERROR_INTERNAL;
//    err_code = nrf_crypto_rng_uninit();
//    
//    switch (err_code) {
//        case NRF_SUCCESS:
//            return UDRV_RETURN_OK;
//        default:
//            return -UDRV_INTERNAL_ERR;
//    }
//}

//static int32_t uhal_sys_crypto_rng_vector_generate(uint8_t * const p_target, size_t size)
//{
//    uint32_t err_code = NRF_ERROR_INTERNAL;
//    err_code = nrf_crypto_rng_vector_generate(p_target, size);
//
//    switch (err_code) {
//        case NRF_SUCCESS:
//            return UDRV_RETURN_OK;
//        default:
//            return -UDRV_INTERNAL_ERR;
//    }
//}

//static int32_t uhal_sys_crypto_rng_reseed(nrf_crypto_rng_temp_buffer_t * p_temp_buffer, uint8_t * p_input_data, size_t size)
//{
//    uint32_t err_code = NRF_ERROR_INTERNAL;
//    err_code = nrf_crypto_rng_reseed(p_temp_buffer, p_input_data, size);
//
//    switch (err_code) {
//        case NRF_SUCCESS:
//            return UDRV_RETURN_OK;
//        default:
//            return -UDRV_INTERNAL_ERR;
//    }
//}

//void uhal_sys_randomseed(unsigned long seed) {
//    //valye = 0x12345678;
//    is_seed = 1;
//    seed_data[0] = (uint8_t)((seed & 0XFF));
//    seed_data[1] = (uint8_t)((seed >> 8) & 0xFF) ;
//    seed_data[2] = (uint8_t)((seed >> 16) & 0xFF) ;
//    seed_data[3] = (uint8_t)((seed >> 24) & 0XFF);
//}

//unsigned long uhal_sys_random (unsigned long maxvalue) {
//    int32_t ret_val;
//    uint8_t random_vector[RANDOM_LENGTH];
//    unsigned long get_random;
//    ret_val = uhal_sys_crypto_init();
//    ret_val = uhal_sys_crypto_rng_init(NULL,NULL);
//
//    if(is_seed)
//    {
//        uhal_sys_crypto_rng_reseed(NULL, seed_data, SEED_LENGTH);
//    }
//
//    ret_val = uhal_sys_crypto_rng_vector_generate(random_vector, RANDOM_LENGTH);
//
//    get_random = ( (random_vector[0])
//                   + (random_vector[1] << 8)
//                   + (random_vector[2] << 16)
//                   + (random_vector[3] << 24) );
//    uhal_sys_crypto_rng_uninit();
//    uhal_sys_crypto_uninit();
//    is_seed = 0;
//
//    get_random = get_random % maxvalue;
//    return get_random;
//}

int32_t uhal_sys_user_app_timer_create (timer_handler tmr_handler, TimerMode_E mode) {
    
    system_tmr_handler = tmr_handler;

    uhal_system_user_app_timer_id = xTimerCreate("TMR_SYSTEM",
                                                    1,
                                                    get_apollo_timer_mode(mode),
                                                    NULL,
                                                    uhal_system_timer_handler);

    if (uhal_system_user_app_timer_id != NULL) {
        return UDRV_RETURN_OK;
    } else {
        return -UDRV_INTERNAL_ERR;
    }
}

int32_t uhal_sys_user_app_timer_start (uint32_t count, void *m_data) {
    
    if (uhal_system_user_app_timer_id != NULL) {
        return UDRV_RETURN_OK;
    } else {
        return -UDRV_INTERNAL_ERR;
    }

    p_context = m_data;

    xTimerChangePeriod( uhal_system_user_app_timer_id,
                        (uint32_t) (count*1.024f), // This is not correct solution! FIX ME!
                        OSTIMER_WAIT_FOR_QUEUE );

    // Start application timers.
    if (pdPASS != xTimerStart(uhal_system_user_app_timer_id, OSTIMER_WAIT_FOR_QUEUE))
    {
        return -UDRV_INTERNAL_ERR;
    }
    else {
        return UDRV_RETURN_OK;
    }
}

int32_t uhal_sys_user_app_timer_stop (void) {
    
    if (uhal_system_user_app_timer_id != NULL) {
        return UDRV_RETURN_OK;
    } else {
        return -UDRV_INTERNAL_ERR;
    }

    if (pdPASS != xTimerStop(uhal_system_user_app_timer_id, OSTIMER_WAIT_FOR_QUEUE))
    {
        return -UDRV_INTERNAL_ERR;
    }
    else {
        return UDRV_RETURN_OK;
    }
}
#endif