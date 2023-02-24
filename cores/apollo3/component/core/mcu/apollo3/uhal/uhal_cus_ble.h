#ifndef BLE_CUS_H__
#define BLE_CUS_H__

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "udrv_errno.h"
#include "udrv_ble.h"

#define CUSTOM_SERVICE_UUID_BASE          {0xFE, 0x10, 0xD7, 0x1C, 0x72, 0x96, 0xBE, 0xB8, \
                                          0x42, 0x5C, 0xE2, 0x3A, 0xAA, 0x03, 0x8C, 0xDD}


#define CUSTOM_SERVICE_UUID               0x1400
#define CUSTOM_VALUE_CHAR_UUID_1          0x1401
#define CUSTOM_VALUE_CHAR_UUID_2          0x1402
#define CHARACTERISTIC_MAX_NUM  3
static uint16_t custom_service_uuid = CUSTOM_SERVICE_UUID;

/**@brief Custom Service event type. */
typedef enum
{
    BLE_CUS_EVT_NOTIFICATION_ENABLED,                             /**< Custom value notification enabled event. */
    BLE_CUS_EVT_NOTIFICATION_DISABLED,                            /**< Custom value notification disabled event. */
    BLE_CUS_EVT_DISCONNECTED,
    BLE_CUS_EVT_CONNECTED
} ble_cus_evt_type_t;

void uhal_ble_cus_register_notify_handler (BLE_CUS_NOTIFY_HANDLER handler);
void uhal_ble_cus_register_send_handler (BLE_CUS_SEND_HANDLER handler);
void cus_timers_init(void);
void cus_ble_stack_init(void);
void cus_gap_params_init(void);
void cus_gatt_init(void);
void cus_services_init(uint8_t cus_base_uuid[]);
int32_t cus_add_char(uint16_t chars_uuid, uint32_t chars_properties, uint8_t chars_permission, uint16_t len);
void cus_advertising_init(void);
void cus_conn_params_init(void);
void cus_peer_manager_init(void);

void cus_application_timers_start(void);
void cus_advertising_start(bool erase_bonds);
void cus_notify(uint8_t *notify_data, uint16_t chars_uuid);  //send to smart phone apps
void cus_write(uint8_t *send_data, uint16_t chars_uuid);     //send to smart phone apps
uint8_t cus_is_notifyEnabled(uint16_t chars_uuid);

#endif // BLE_CUS_H__