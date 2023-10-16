#include <string.h>
#include <stdio.h>
#include "wsf_types.h"
#include "bstream.h"
#include "wsf_msg.h"
#include "wsf_trace.h"
#include "hci_api.h"
#include "dm_api.h"
#include "att_api.h"
#include "app_api.h"
#include "app_db.h"
#include "app_ui.h"
#include "app_hw.h"
#include "app_main.h"
#include "svc_ch.h"
#include "svc_core.h"
#include "svc_dis.h"
#include "gatt_api.h"
#include "hci_drv_apollo3.h"

#include "uhal_cus_ble.h"
#include "uhal_cus.h"

extern uint32_t uhal_ble_wlock_cnt;

void (*CUS_NOTIFY_HANDLER)(uint16_t, uint8_t *);
void (*CUS_SEND_HANDLER)(uint16_t, uint8_t *);

uint8_t uhal_cus_base_uuid[16];

void uhal_ble_cus_register_notify_handler(BLE_CUS_NOTIFY_HANDLER handler)
{
    CUS_NOTIFY_HANDLER = handler;
}

void uhal_ble_cus_register_send_handler (BLE_CUS_SEND_HANDLER handler)
{
    CUS_SEND_HANDLER = handler;
}

void cus_timers_init(void)
{
}

void cus_ble_stack_init(void)
{
        /* Set Device Name */
        char device_name[] = "RAK";

        // scan_data[0] = strlen(device_name) + 1;
        // scan_data[1] = DM_ADV_TYPE_LOCAL_NAME;
        // memcpy(&scan_data[2], device_name, strlen(device_name));
        // scan_data_size = strlen(device_name) + 2;

        // memset(ble_parameter.custom_dev_name, 0, sizeof(ble_parameter.custom_dev_name));
        // memcpy(ble_parameter.custom_dev_name, device_name, strlen(device_name));
        // SvcCoreSetDevName(ble_parameter.custom_dev_name, sizeof(ble_parameter.custom_dev_name));
        // am_log_inf("BLE Set DEVNAME = %s ", ble_parameter.custom_dev_name);

        uhal_ble_set_device_name(device_name, strlen(device_name));

        /* Set Security Configuration */
        // ble_parameter.permission = SET_OPEN;

        // security_conf.auth = DM_AUTH_BOND_FLAG;
        // security_conf.iKeyDist = 0;
        // security_conf.rKeyDist = DM_KEY_DIST_LTK;
        // security_conf.initiateSec = FALSE;
        // security_conf.oob = FALSE;
        // security_parameters.ioCap = SMP_IO_NO_IN_NO_OUT;
        uhal_nus_set_permission(SET_OPEN);

        /* Remove Servives */
        UhalNUSRemoveGroup();
        SvcAmotasRemoveGroup();

}

void cus_gap_params_init(void)
{
}

void cus_peer_manager_init(void)
{
}

void cus_conn_params_init(void)
{
}

void cus_gatt_init(void)
{
}

void cus_services_init(uint8_t cus_base_uuid[])
{
    for(int i = 0; i < 16; i++)
    {
        uhal_cus_base_uuid[i] = cus_base_uuid[15-i];
    }
    uhal_cus_services_init(cus_base_uuid);
}

int32_t cus_add_char(uint16_t chars_uuid, uint32_t chars_properties, uint8_t chars_permission, uint16_t len)
{
    uhal_cus_add_char(chars_uuid, chars_properties, chars_permission, len);
}

void cus_write(uint8_t *send_data, uint16_t chars_uuid)
{
    uhal_cus_write(chars_uuid, send_data);
}

void cus_notify(uint8_t *notify_data, uint16_t chars_uuid)
{
    uhal_cus_send_data(chars_uuid, notify_data);
}

uint8_t cus_is_notifyEnabled(uint16_t chars_uuid)
{
    uhal_cus_is_notifyEnabled(chars_uuid);
}

void cus_advertising_init(void)
{
    uhal_advertising_init();
}

void cus_advertising_start(bool erase_bonds)
{
    uhal_advertising_start(0);
}