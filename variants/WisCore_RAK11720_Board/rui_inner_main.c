#include "am_mcu_apollo.h"
#include "am_bsp.h"
#include "am_util.h"
#include "am_log.h"
#include "amota_profile_config.h"
#include "error_check.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "portmacro.h"
#include "portable.h"

#include "rtos.h"
#include "variant.h"
#include "app.h"

#include "uhal_powersave.h"

#include "udrv_errno.h"
#include "udrv_gpio.h"
#include "udrv_serial.h"
#include "udrv_timer.h"
#include "udrv_system.h"
#include "udrv_flash.h"
#include "udrv_rtc.h"
#include "udrv_powersave.h"
#include "udrv_ble.h"
#include "udrv_serial.h"
#include "service_nvm.h"
#include "service_mode.h"
#include "service_mode_proto.h"
#include "service_mode_cli.h"
#include "service_mode_transparent.h"

#if CFG_SYSVIEW
#include "SEGGER_RTT.h"
#include "SEGGER_SYSVIEW.h"
#endif

#if defined(SUPPORT_LORA) || defined(SUPPORT_LORA_P2P)
#include "radio.h"
#endif
#ifdef SUPPORT_LORA
#include "LoRaMac.h"
extern service_lora_join_cb service_lora_join_callback;
#endif

bool no_busy_loop = false;

static udrv_system_event_t rui_user_app_event = {.request = UDRV_SYS_EVT_OP_USER_APP, .p_context = NULL};
static bool run_user_app = false;

extern bool udrv_powersave_in_sleep;
extern volatile bool rx_wait_active;

extern const char *sw_version;

// This file exists solely for compilation compatibility with legacy libraries
// Test if in interrupt mode
static inline bool isInISR(void)
{
  return (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0 ;
}

/* These magic symbols are provided by the linker.  */
extern void (*__preinit_array_start []) (void) __attribute__((weak));
extern void (*__preinit_array_end []) (void) __attribute__((weak));
extern void (*__init_array_start []) (void) __attribute__((weak));
extern void (*__init_array_end []) (void) __attribute__((weak));

extern void _init (void) __attribute__((weak));

/* Iterate over all the init routines.  */
void
__libc_init_array (void)
{
  size_t count;
  size_t i;

  count = __preinit_array_end - __preinit_array_start;
  for (i = 0; i < count; i++)
    __preinit_array_start[i] ();

  //_init ();

  count = __init_array_end - __init_array_start;
  for (i = 0; i < count; i++)
    __init_array_start[i] ();
}

#define LOOP_STACK_SZ       (256*16)

static TaskHandle_t  _loopHandle;

#ifdef TOGGLE_LED_PER_SEC
void OnTimerEvent()
{
    udrv_gpio_toggle_logic(BLUE_LED);
}
#endif

void HardFault_Handler(void)
{
    NVIC_SystemReset();
}

void error_fault_handler(uint32_t info)
{
    NVIC_SystemReset();
}

/********************************************************************/
/* RUI handler functions                                            */
/********************************************************************/
void rui_event_handler_func(void *data, uint16_t size) {
    udrv_system_event_t *event = (udrv_system_event_t *)data;
    switch (event->request) {
        case UDRV_SYS_EVT_OP_SERIAL_FALLBACK:
        {
            SERIAL_PORT port = (SERIAL_PORT)event->p_context;
            SERVICE_MODE_TYPE mode = service_nvm_get_mode_type_from_nvm(port);

            /* escape now immediately */
            switch (mode)
            {
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
                case SERVICE_MODE_TYPE_TRANSPARENT:
                {
                    service_mode_transparent_deinit(port);
                    break;
                }
#endif
#endif
#ifdef SUPPORT_BINARY
                case SERVICE_MODE_TYPE_PROTOCOL:
                {
                    service_mode_proto_deinit(port);
                    break;
                }
#endif
                default:
                {
                    break;
                }
            }
            service_mode_cli_init(port);
            service_nvm_set_mode_type_to_nvm(port, SERVICE_MODE_TYPE_CLI);
            break;
        }
        case UDRV_SYS_EVT_OP_SERIAL_UART:
        {
            if (service_nvm_get_mode_type_from_nvm(SERIAL_UART1) != SERVICE_MODE_TYPE_CUSTOM) {
                
                if(no_busy_loop == true)
                    uhal_uart_wait_timer_start(UART_WAIT_TIMEOUT_TIME);
                
                while (udrv_serial_read_available(SERIAL_UART1) > 0) {
                    uint8_t Buf[1];
                    int32_t count = udrv_serial_read (SERIAL_UART1, Buf, 1);
                    SERIAL_WLOCK_STATE state;
                    switch (service_nvm_get_mode_type_from_nvm(SERIAL_UART1)) {
                        case SERVICE_MODE_TYPE_CLI:
                        {
                            if ((state = udrv_serial_get_lock_state(SERIAL_UART1)) == SERIAL_WLOCK_OPEN) {
                                service_mode_cli_handler(SERIAL_UART1, Buf[0]);
                            } else if (state == SERIAL_WLOCK_LOCKED) {
                                udrv_serial_wlock_handler(SERIAL_UART1, Buf[0]);
                            }
                            break;
                        }
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
                        case SERVICE_MODE_TYPE_TRANSPARENT:
                        {
                            service_mode_transparent_handler(SERIAL_UART1, Buf[0]);
                            break;
                        }
#endif
#endif
#ifdef SUPPORT_BINARY
                        case SERVICE_MODE_TYPE_PROTOCOL:
                        {
                            service_mode_proto_recv(SERIAL_UART1, Buf[0]);
                            break;
                        }
#endif
                        default:
                        {
                            break;
                        }
                    }
                }
            }
            if (service_nvm_get_mode_type_from_nvm(SERIAL_UART0) != SERVICE_MODE_TYPE_CUSTOM) {
                
                if(no_busy_loop == true)
                    uhal_uart_wait_timer_start(UART_WAIT_TIMEOUT_TIME);
                
                while (udrv_serial_read_available(SERIAL_UART0) > 0) {
                    uint8_t Buf[1];
                    int32_t count = udrv_serial_read (SERIAL_UART0, Buf, 1);
                    SERIAL_WLOCK_STATE state;
                    switch (service_nvm_get_mode_type_from_nvm(SERIAL_UART0)) {
                        case SERVICE_MODE_TYPE_CLI:
                        {
                            if ((state = udrv_serial_get_lock_state(SERIAL_UART0)) == SERIAL_WLOCK_OPEN) {
                                service_mode_cli_handler(SERIAL_UART0, Buf[0]);
                            } else if (state == SERIAL_WLOCK_LOCKED) {
                                udrv_serial_wlock_handler(SERIAL_UART0, Buf[0]);
                            }
                            break;
                        }
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
                        case SERVICE_MODE_TYPE_TRANSPARENT:
                        {
                            service_mode_transparent_handler(SERIAL_UART0, Buf[0]);
                            break;
                        }
#endif
#endif
#ifdef SUPPORT_BINARY
                        case SERVICE_MODE_TYPE_PROTOCOL:
                        {
                            service_mode_proto_recv(SERIAL_UART0, Buf[0]);
                            break;
                        }
#endif
                        default:
                        {
                            break;
                        }
                    }
                }
            }
            break;
        }
#ifdef SUPPORT_USB
        case UDRV_SYS_EVT_OP_SERIAL_USB:
        {
            if (service_nvm_get_mode_type_from_nvm(SERIAL_USB0) != SERVICE_MODE_TYPE_CUSTOM) {
                while (udrv_serial_read_available(SERIAL_USB0) > 0) {
                    uint8_t Buf[1];
                    int32_t count = udrv_serial_read (SERIAL_USB0, Buf, 1);
                    SERIAL_WLOCK_STATE state;
                    switch (service_nvm_get_mode_type_from_nvm(SERIAL_USB0)) {
                        case SERVICE_MODE_TYPE_CLI:
                        {
                            if ((state = udrv_serial_get_lock_state(SERIAL_USB0)) == SERIAL_WLOCK_OPEN) {
                                service_mode_cli_handler(SERIAL_USB0, Buf[0]);
                            } else if (state == SERIAL_WLOCK_LOCKED) {
                                udrv_serial_wlock_handler(SERIAL_USB0, Buf[0]);
                            }
                            break;
                        }
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
                        case SERVICE_MODE_TYPE_TRANSPARENT:
                        {
                            service_mode_transparent_handler(SERIAL_USB0, Buf[0]);
                            break;
                        }
#endif
#endif
#ifdef SUPPORT_BINARY
                        case SERVICE_MODE_TYPE_PROTOCOL:
                        {
                            service_mode_proto_recv(SERIAL_USB0, Buf[0]);
                            break;
                        }
#endif
                        default:
                        {
                            break;
                        }
                    }
                }
            }
            break;
        }
#endif
#ifdef SUPPORT_BLE
        case UDRV_SYS_EVT_OP_SERIAL_BLE:
        {
            if (service_nvm_get_mode_type_from_nvm(SERIAL_BLE0) != SERVICE_MODE_TYPE_CUSTOM) {
                while (udrv_serial_read_available(SERIAL_BLE0) > 0) {
                    uint8_t Buf[1];
                    int32_t count = udrv_serial_read (SERIAL_BLE0, Buf, 1);
                    SERIAL_WLOCK_STATE state;
                    switch (service_nvm_get_mode_type_from_nvm(SERIAL_BLE0)) {
                        case SERVICE_MODE_TYPE_CLI:
                        {
                            if ((state = udrv_serial_get_lock_state(SERIAL_BLE0)) == SERIAL_WLOCK_OPEN) {
                                service_mode_cli_handler(SERIAL_BLE0, Buf[0]);
                            } else if (state == SERIAL_WLOCK_LOCKED) {
                                udrv_serial_wlock_handler(SERIAL_BLE0, Buf[0]);
                            }
                            break;
                        }
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
                        case SERVICE_MODE_TYPE_TRANSPARENT:
                        {
                            service_mode_transparent_handler(SERIAL_BLE0, Buf[0]);
                            break;
                        }
#endif
#endif
#ifdef SUPPORT_BINARY
                        case SERVICE_MODE_TYPE_PROTOCOL:
                        {
                            service_mode_proto_recv(SERIAL_BLE0, Buf[0]);
                            break;
                        }
#endif
                        default:
                        {
                            break;
                        }
                    }
                }
            }
            break;
        }
#endif
#if defined(SUPPORT_LORA) || defined(SUPPORT_LORA_P2P)
        case UDRV_SYS_EVT_OP_LORAWAN:
        {
            // Process Radio IRQ
            if( Radio.IrqProcess != NULL )
            {
                Radio.IrqProcess( );
            }
#ifdef SUPPORT_LORA
            // Processes the LoRaMac events
            LoRaMacProcess( );

            // Call all packages process functions
            LmHandlerPackagesProcess( );
#endif
            break;
        }
#endif
#ifdef SUPPORT_LORA
        case UDRV_SYS_EVT_OP_LORAWAN_JOIN_CB:
        {
            if (service_lora_join_callback != NULL) {
                service_lora_join_callback((int32_t) (event->p_context));
            }
            break;
        }
#endif
        case UDRV_SYS_EVT_OP_USER_TIMER:
        case UDRV_SYS_EVT_OP_SYS_TIMER:
        {
            udrv_system_timer_handler_handler(event->p_context);
            break;
        }
#ifdef SUPPORT_NFC
        case UDRV_SYS_EVT_OP_SERIAL_NFC:
        {
            if (service_nvm_get_mode_type_from_nvm(SERIAL_NFC) != SERVICE_MODE_TYPE_CUSTOM) {
                while (udrv_serial_read_available(SERIAL_NFC) > 0) {
                    uint8_t Buf[1];
                    int32_t count = udrv_serial_read(SERIAL_NFC, Buf, 1);
                    SERIAL_WLOCK_STATE state;
	                switch (service_nvm_get_mode_type_from_nvm(SERIAL_NFC)) {
                        case SERVICE_MODE_TYPE_CLI:
                        {
                            service_mode_cli_handler(SERIAL_NFC, Buf[0]);
                            break;
                        }				
    	            }
                }
            }
            break;
        }
#endif
        case UDRV_SYS_EVT_OP_RTC:
        {
            udrv_rtc_timer_handler_handler(NULL);
            break;
        }
        case UDRV_SYS_EVT_OP_GPIO_INTERRUPT:
        {
            udrv_gpio_handler_handler(event->p_context);
            break;
        }
        default:
        {
            break;
        }
    }
}

#if defined(AM_PART_APOLLO3) || defined(AM_PART_APOLLO3P)
static char *otaStatusMessage[] =
    {
        "Success",
        "Error",
        "Failure",
        "Pending"
    };
static void
dump_ota_status(void)
{
    uint32_t *pOtaDesc = (uint32_t *)(OTA_POINTER_LOCATION & ~(AM_HAL_FLASH_PAGE_SIZE - 1));
    uint32_t i;

    // Check if the current content at OTA descriptor is valid
    for (i = 0; i < AM_HAL_SECURE_OTA_MAX_OTA + 1; i++)
    {
        // Make sure the image address looks okay
        if (pOtaDesc[i] == 0xFFFFFFFF)
        {
            break;
        }
        if (((pOtaDesc[i] & 0x3) == AM_HAL_OTA_STATUS_ERROR) || ((pOtaDesc[i] & ~0x3) >= 0x100000))
        {
            break;
        }
    }
    if (pOtaDesc[i] == 0xFFFFFFFF)
    {
        // udrv_serial_log_printf("Valid Previous OTA state\r\n");
        // It seems in last boot this was used as OTA descriptor
        // Dump previous OTA information
        am_hal_ota_status_t otaStatus[AM_HAL_SECURE_OTA_MAX_OTA];
        am_hal_get_ota_status(pOtaDesc, AM_HAL_SECURE_OTA_MAX_OTA, otaStatus);
        for ( uint32_t i = 0; i < AM_HAL_SECURE_OTA_MAX_OTA; i++ )
        {
            if ((uint32_t)otaStatus[i].pImage == 0xFFFFFFFF)
            {
                break;
            }
            {
                // udrv_serial_log_printf("Previous OTA: Blob Addr: 0x%x - Result %s\r\n",
                //                     otaStatus[i].pImage, otaStatusMessage[otaStatus[i].status]);

            }
        }
    }
    else
    {
        // udrv_serial_log_printf("No Previous OTA state\r\n");
    }
}
#endif


void rui_init(void)
{
    SERVICE_MODE_TYPE mode;
    uint32_t baudrate;
    uint8_t set_dev_name[30];
    uint8_t mac[12];
    uint8_t rbuff[8] = {0};

    am_log_inf("RUI Version: %s", sw_version);

    udrv_timer_init();

#ifdef SUPPORT_USB
    udrv_serial_init(SERIAL_USB0, baudrate, SERIAL_WORD_LEN_8, SERIAL_STOP_BIT_1, SERIAL_PARITY_DISABLE, SERIAL_TWO_WIRE_NORMAL_MODE);
#endif

    udrv_flash_init();
    service_nvm_init_config();

    baudrate = service_nvm_get_baudrate_from_nvm();
    udrv_serial_init(SERIAL_UART0, baudrate, SERIAL_WORD_LEN_8, SERIAL_STOP_BIT_1, SERIAL_PARITY_DISABLE, SERIAL_TWO_WIRE_NORMAL_MODE);
    udrv_serial_init(SERIAL_UART1, baudrate, SERIAL_WORD_LEN_8, SERIAL_STOP_BIT_1, SERIAL_PARITY_DISABLE, SERIAL_TWO_WIRE_NORMAL_MODE);

#if defined(AM_PART_APOLLO3) || defined(AM_PART_APOLLO3P)
    dump_ota_status();
#endif

#ifdef SUPPORT_BLE
    udrv_ble_stack_start();
    uhal_ble_apollo3_wait_ble_core();
    udrv_ble_services_start();
#endif

#ifdef SUPPORT_BLE
#ifdef SUPPORT_LORA
    service_lora_get_dev_eui(rbuff, 8);
    sprintf(set_dev_name,"RAK.%02X%02X%02X",rbuff[5],rbuff[6],rbuff[7]);
    udrv_ble_set_device_name(set_dev_name,strlen(set_dev_name));
#endif
    service_nvm_get_ble_mac_from_nvm(mac,12);
    udrv_ble_set_macaddress(mac);
    service_nvm_set_mode_type_to_nvm(SERIAL_BLE0, SERVICE_MODE_TYPE_CLI);
    udrv_serial_init(SERIAL_BLE0, baudrate, SERIAL_WORD_LEN_8, SERIAL_STOP_BIT_1, SERIAL_PARITY_DISABLE, SERIAL_TWO_WIRE_NORMAL_MODE);
#endif
#ifdef SUPPORT_NFC
    udrv_serial_init(SERIAL_NFC, baudrate, SERIAL_WORD_LEN_8, SERIAL_STOP_BIT_1, SERIAL_PARITY_DISABLE, SERIAL_TWO_WIRE_NORMAL_MODE);
#endif

#if defined(SUPPORT_LORA)
#ifdef SUPPORT_LORA_104
    service_lora_mac_nvm_data_init();
#endif
    service_lora_init(service_nvm_get_band_from_nvm());
#elif defined(SUPPORT_LORA_P2P)
    BoardInitMcu();
    service_lora_p2p_init();
#else
    udrv_rtc_init((RtcID_E) SYS_RTC_COUNTER_PORT, NULL); // Edited by Sercan ERAT
#endif

    for (int i = 0 ; i < SERIAL_MAX ; i++) {
        if (service_nvm_get_mode_type_from_nvm((SERIAL_PORT)i) == SERVICE_MODE_TYPE_CLI) {
            service_mode_cli_init((SERIAL_PORT)i);
        }
    }
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
    for (int i = 0 ; i < SERIAL_MAX ; i++) {
        if (service_nvm_get_mode_type_from_nvm((SERIAL_PORT)i) == SERVICE_MODE_TYPE_TRANSPARENT) {
            if (service_lora_get_njs() == false) {
                service_nvm_set_mode_type_to_nvm((SERIAL_PORT)i, SERVICE_MODE_TYPE_CLI);
                service_mode_cli_init((SERIAL_PORT)i);
                continue;
            }
            service_mode_transparent_init((SERIAL_PORT)i);
        }
    }
#endif
#endif
#ifdef SUPPORT_BINARY
    for (int i = 0 ; i < SERIAL_MAX ; i++) {
        if (service_nvm_get_mode_type_from_nvm((SERIAL_PORT)i) == SERVICE_MODE_TYPE_PROTOCOL) {
            service_mode_proto_init((SERIAL_PORT)i);
        }
    }
#endif

#ifdef SUPPORT_WDT
    udrv_wdt_init();
    udrv_wdt_feed();//Consider software reset case, reload WDT counter first.
#endif

    udrv_system_event_init();

#ifdef SUPPORT_LORA
#ifdef SUPPORT_LORA_104
    if(service_nvm_get_certi_from_nvm() == 1)
        service_lora_certification(1);
#endif
#endif
}

void rui_running(void)
{
    udrv_system_event_consume();
}

static void loop_task(void* arg)
{
    (void) arg;

    rui_init();

    rui_setup();

#ifdef TOGGLE_LED_PER_SEC
    udrv_gpio_set_dir(BLUE_LED, GPIO_DIR_OUT);
    if (udrv_system_timer_create(SYSTIMER_LED, OnTimerEvent, HTMR_PERIODIC) == UDRV_RETURN_OK)
    {
        udrv_system_timer_start(SYSTIMER_LED, 1000, NULL);
    }
#endif

#if defined(SUPPORT_LORA) || defined(SUPPORT_LORA_P2P)
    udrv_serial_log_printf("Current Work Mode: ");
#ifdef SUPPORT_LORA
    switch (service_lora_get_nwm())
#else
    switch (service_lora_p2p_get_nwm())
#endif
    {
        case SERVICE_LORA_P2P:
        {
            udrv_serial_log_printf("LoRa P2P.\r\n");
            break;
        }
        case SERVICE_LORAWAN:
        {
            udrv_serial_log_printf("LoRaWAN.\r\n");
            break;
        }
        case SERVICE_LORA_FSK:
        {
            udrv_serial_log_printf("LoRa FSK.\r\n");
            break;
        }
    }
#endif

    while (1)
    {
        //system loop
        rui_running();

        //user loop
        if (!no_busy_loop) {
            if(rx_wait_active == true)
            {
                udrv_app_delay_ms(UART_WAIT_TIMEOUT_TIME);
                rx_wait_active = false;

                uint8_t *str_ok = "SLEEP\r\n";
                uhal_uart_write(0, str_ok, strlen(str_ok), 0);
                uhal_uart_write(1, str_ok, strlen(str_ok), 0);
            }

            rui_loop();
        } else {
            if (service_nvm_get_auto_sleep_time_from_nvm() && rx_wait_active == false) {
                udrv_sleep_ms(0);
            }
        }
    }
}

// \brief Main entry point of Arduino application
int main( void )
{
    __libc_init_array();

    am_log_init();
    am_log_inf("RUI INNER MAIN - APOLLO3");

    #if CFG_SYSVIEW
    am_log_inf("SYSVIEW Configuration");
    SEGGER_SYSVIEW_Conf();
    #endif
    //
    // Set the clock frequency.
    //
    uint32_t err_code = am_hal_clkgen_control(AM_HAL_CLKGEN_CONTROL_SYSCLK_MAX, 0);
    ERROR_CHECK(err_code);

    //
    // Set the default cache configuration
    //
    err_code = am_hal_cachectrl_config(&am_hal_cachectrl_defaults);
    ERROR_CHECK(err_code);
    err_code = am_hal_cachectrl_enable();
    ERROR_CHECK(err_code);

#ifndef NOFPU
    //
    // Enable the floating point module, and configure the core for lazy
    // stacking.
    //
    am_hal_sysctrl_fpu_enable();
    am_hal_sysctrl_fpu_stacking_enable(true);
#else
    am_hal_sysctrl_fpu_disable();
#endif

    //
    // Initialize for low power in the power control block
    //
    err_code = am_hal_pwrctrl_low_power_init();
    ERROR_CHECK(err_code);

    //
    // Disable the RTC.
    //
    am_hal_rtc_osc_disable();

    // Create a task for loop()
    xTaskCreate(loop_task, "loop", LOOP_STACK_SZ, NULL, RAK_TASK_PRIO_LOW, &_loopHandle);

    // Start FreeRTOS scheduler.
    vTaskStartScheduler();

    NVIC_SystemReset();

    return 0;
}

void suspendLoop(void)
{
    vTaskSuspend(_loopHandle);
}

void resumeLoop(void)
{
    if( isInISR() ) 
    {
        xTaskResumeFromISR(_loopHandle);
    } 
    else
    {
        vTaskResume(_loopHandle);
    }
}
