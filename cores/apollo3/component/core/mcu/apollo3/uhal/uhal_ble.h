#ifndef _UHAL_BLE_H_
#define _UHAL_BLE_H_

#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>


#include "board_basic.h"

#include "udrv_ble.h"
#include "udrv_system.h"
#include "udrv_serial.h"
#include "udrv_errno.h"
#include "udrv_powersave.h"
#include "service_mode_cli.h"
#include "uhal_ble_hid.h"
#include "uhal_ble_cfg.h"

#ifndef BLE_MODULE_CONN_MAX
#define BLE_MODULE_CONN_MAX                  1
#endif

#define DEVICE_NAME                     "RAK"   
#define MIN_CONN_ADV_INTERVAL           20                                          /**  Minimum advertising interval (in ms).*/
#define MIN_NON_CONN_ADV_INTERVAL       100                                         /**	 Minimum advertising interval for non-connectable advertisements (in ms).*/
#define MAX_ADV_INTERVAL                10240   
#define APP_ADV_INTERVAL                1600    /**< The advertising interval (in units of 0.625 ms. This value corresponds to 100 ms). */                                    /**< Name of device. Will be included in the advertising data. */
#define MIN_ADV_INTERVAL                1000    /**< Minimum advertising interval 1000 ms */
#define APP_ADV_TIMEOUT_LIMITED_MAX     180     /**< Maximum advertising time in 10 ms units corresponding to TGAP(lim_adv_timeout) = 180 s in limited discoverable mode. */

#ifdef BLE_CENTRAL_SUPPORT

#define SCAN_INTERVAL   160                                             // <o> SCAN_INTERVAL - Scanning interval, determines scan interval in units of 0.625 millisecond. 
#define SCAN_WINDOW     160                                             // SCAN_WINDOW - Scanning window, determines scan window in units of 0.625 millisecond. 
#define SCAN_DURATION   0x0000    

#define BLE_GAP_SCAN_INTERVAL_MS_MIN                3                   /**< Minimum Scan interval in ms. */
#define BLE_GAP_SCAN_INTERVAL_MS_MAX                40960               /**< Maximum Scan interval in ms, i.e. 40.96 s. */
#define BLE_GAP_SCAN_WINDOW_MS_MIN                  3                   /**< Minimum Scan window in ms. */
#define BLE_GAP_SCAN_WINDOW_MS_MAX                  40960               /**< Maximum Scan window in ms, i.e. 40.96 s. */

#define BLE_MODULE_NOTIFY_CHAR_SIZE     10

// ble device running mode
typedef enum
{
    BLE_WORK_PERIPHERAL = 0,
    BLE_WORK_CENTRAL,
    BLE_WORK_OBSERVER
} ble_work_mode_t;

static ble_central_cfg_t uhal_g_ble_cfg_t =
{
    /* BLE default configuration */
    .work_mode = BLE_WORK_PERIPHERAL,
    .long_range_enable = 0,
};

static uint8_t g_ble_current_mode = BLE_WORK_PERIPHERAL;
#endif

static uint16_t   m_conn_handle          = 0 /*BLE_CONN_HANDLE_INVALID*/;                 /**< Handle of the current connection. */
static uint16_t   m_ble_nus_max_data_len = 0/* BLE_GATT_ATT_MTU_DEFAULT - 3*/;            /**< Maximum length of data (in bytes) that can be transmitted to the peer by the Nordic UART service module. */

/*************************************Define for Beacon Mode***********************************************/

static int uhal_is_scanning = 0;

void uhal_ble_apollo3_wait_ble_core(void);

void uhal_ble_stack_init(void);
void uhal_gap_params_init(void);
void uhal_gatt_init(void);
void uhal_services_init(void);
void uhal_advertising_init(void);
void uhal_conn_params_init(void);
int32_t uhal_advertising_start(uint8_t time_out);
int32_t uhal_advertising_stop(uint8_t temp_processing);
int32_t uhal_advertising_status(void);

void uhal_stop_ble(void);
size_t uhal_nus_available(void);
int32_t uhal_nus_read(uint8_t *Buffer, int32_t NumberOfBytes);
int32_t uhal_nus_write(uint8_t *pdata, uint16_t length);

int32_t uhal_ble_get_txpower(void);
void uhal_ble_set_txpower(drv_ble_tx_power_t tx_power);
int32_t uhal_ble_set_device_name(char *devic_name, uint8_t device_name_length);
char* uhal_ble_get_device_name(void);

int32_t uhal_ble_get_macaddress(uint8_t *macaddr);
int32_t uhal_ble_set_macaddress(uint8_t *macaddr);
int32_t uhal_ble_set_adv_interval(uint32_t adv_interval);
int32_t uhal_ble_get_adv_interval(void);
void uhal_ble_set_adv_slow_mode(uint8_t adv_mode);
uint8_t uhal_ble_get_adv_slow_mode(void);
void uhal_ble_set_adv_fast_mode(uint8_t adv_mode);
uint8_t uhal_ble_get_adv_fast_mode();
void uhal_ble_switch_service_mode(drv_ble_service_mode service_mode);
int32_t uhal_ble_set_beacon_major(uint16_t major_value);
int32_t uhal_ble_set_beacon_minor(uint16_t minor_value);
int32_t uhal_ble_set_beacon_uuid(uint8_t beaconUuid[]);
int32_t uhal_ble_set_beacon_power(int8_t beacon_power);
int32_t uhal_ble_set_beacon_custom_payload(uint8_t cus_adv_data[], uint8_t cus_adv_len);

void uhal_ble_serial_init (SERIAL_PORT Port, uint32_t BaudRate, SERIAL_WORD_LEN_E DataBits, SERIAL_STOP_BIT_E StopBits, SERIAL_PARITY_E Parity, SERIAL_WIRE_MODE_E WireMode);
void uhal_ble_serial_deinit (SERIAL_PORT Port);
int32_t uhal_ble_serial_write (SERIAL_PORT Port, uint8_t const *Buffer, int32_t NumberOfBytes, uint32_t Timeout);
int32_t uhal_ble_serial_read (SERIAL_PORT Port, uint8_t *Buffer, int32_t NumberOfBytes, uint32_t Timeout);
int32_t uhal_ble_serial_peek (SERIAL_PORT Port);
void uhal_ble_serial_flush (SERIAL_PORT Port, uint32_t Timeout);
size_t uhal_ble_serial_read_available (SERIAL_PORT Port);

//void uhal_ble_set_work_mode(ble_work_mode_t mode, bool long_range_enable);
int32_t uhal_ble_set_scan_interval_window(uint16_t scan_interval, uint16_t scan_window);
void uhal_ble_scan_start(uint16_t scan_sec);
void uhal_nus_peer_manager_init(void);
int32_t uhal_nus_set_keypairing(uint8_t *pairing_key, uint8_t key_length);
int32_t uhal_nus_set_permission(uint8_t permission);
void uhal_ble_wake_lock (void);
void uhal_ble_wake_unlock (void);
void uhal_ble_wake_unlock_all (void);

void uhal_ble_default_config(void);
void uhal_nus_data_handler(uint8_t *p_data, uint16_t length);

void uhal_ble_scan_data_handler(BLE_SCAN_DATA_HANDLER handler);
void uhal_ble_keyboard_handler(BLE_KEYBOARD_HANDLER handler);

void uhal_ble_connect_handler(BLE_HANDLER handler);
void uhal_ble_disconnect_handler(BLE_HANDLER handler);

uint32_t uhal_ble_hci_write(uint8_t *raw_data,uint8_t len);
int32_t uhal_ble_hci_read(uint8_t *recv,uint32_t *recv_bytes);
void uhal_ble_set_dtm_txpower(int tx_power);
#endif  // #ifndef _UHAL_BLE_H_
