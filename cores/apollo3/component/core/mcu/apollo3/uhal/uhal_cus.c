#include "wsf_types.h"
#include "att_api.h"
#include "wsf_trace.h"
#include "bstream.h"
#include "svc_ch.h"
#include "svc_cfg.h"
#include "uhal_cus.h"
#include "uhal_ble.h"
#include "uhal_powersave.h"
#include "udrv_ble.h"

#include "am_log.h"

// Write --> {ATT_PROP_WRITE_NO_RSP | ATT_PROP_WRITE, UINT16_TO_BYTES(CUSTS_HANDLE_WRITEONLY), ATT_UUID_CUSTS_WRITEONLY};
// Read --> {ATT_PROP_READ, UINT16_TO_BYTES(CUSTS_HANDLE_READONLY), ATT_UUID_CUSTS_READONLY};
// Notify --> {ATT_PROP_NOTIFY | ATT_PROP_READ, UINT16_TO_BYTES(CUSTS_HANDLE_NOTIFYONLY), ATT_UUID_CUSTS_NOTIFYONLY};
// Indicate --> {ATT_PROP_INDICATE | ATT_PROP_READ, UINT16_TO_BYTES(CUSTS_HANDLE_INDICATEONLY), ATT_UUID_CUSTS_INDICATEONLY};

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
#pragma pack(push,1)
typedef struct
{
  uint8_t settings;
  uint8_t hdl[2];
  uint8_t uuid[ATT_128_UUID_LEN];
} char_settings_t; // size: 18 byte
#pragma pack(pop)

extern attsCccSet_t bleModuleCccSet[BLE_MODULE_NOTIFY_CHAR_SIZE];

/**************************************************************************************************
 Static Variables
**************************************************************************************************/
extern void (*CUS_NOTIFY_HANDLER)(uint16_t, uint8_t *);
extern void (*CUS_SEND_HANDLER)(uint16_t, uint8_t *);
extern int uhal_is_connected;

/**************************************************************************************************
 Service variables
**************************************************************************************************/
/* CUS service & characteristic declaration */
static uint8_t cus_srv_uuid[ATT_128_UUID_LEN]; // Service UUID
static uint8_t cus_char_uuid[MAXIMUM_CUS_CHARACTERISTIC_SIZE][ATT_128_UUID_LEN];
static char_settings_t cus_char_settings[MAXIMUM_CUS_CHARACTERISTIC_SIZE];
static uint8_t cus_char_ccc[MAXIMUM_CUS_CHARACTERISTIC_SIZE][2];
static uint8_t cus_char_value[MAXIMUM_CUS_CHARACTERISTIC_SIZE][ATT_DEFAULT_PAYLOAD_LEN];
static uint16_t cus_char_value_len[MAXIMUM_CUS_CHARACTERISTIC_SIZE];
notify_char_t notify_list[MAXIMUM_CUS_CHARACTERISTIC_SIZE];

static uint16_t cus_uuid_len = ATT_128_UUID_LEN;
static uint16_t cus_char_settings_len = sizeof(char_settings_t);
static uint16_t cus_char_ccc_len = 2;

/* CUS service & characteristic status */
static uint16_t current_service_index = 0;
static uint16_t current_characteristic_index = 0;
static uint16_t current_characteristic_array_index = 0;
static uint16_t current_notify_list_index = 0;
static uint16_t current_service_hdl = CUS_SERVICE_START_HDL;

/* Attribute list for CUS service group */
static attsAttr_t uhal_cus_list[1 + (MAXIMUM_CUS_CHARACTERISTIC_SIZE*3)];

/* CUS service group structure */
static attsGroup_t uhal_cus_group;

//*****************************************************************************
//
// Connection Open event
//
//*****************************************************************************
static void uhal_cus_main_conn_open(dmEvt_t *pMsg)
{
    hciLeConnCmplEvt_t *evt = (hciLeConnCmplEvt_t*) pMsg;

    (void)evt;

    am_log_inf("connection opened");

    #if AM_BLE_DEBUG
    am_log_inf("connection opened");
    am_log_inf("handle = 0x%x", evt->handle);
    am_log_inf("role = 0x%x", evt->role);
    am_log_inf("addrMSB = %02x%02x%02x%02x%02x%02x", evt->peerAddr[0], evt->peerAddr[1], evt->peerAddr[2]);
    am_log_inf("addrLSB = %02x%02x%02x%02x%02x%02x", evt->peerAddr[3], evt->peerAddr[4], evt->peerAddr[5]);
    am_log_inf("connInterval = 0x%x", evt->connInterval);
    am_log_inf("connLatency = 0x%x", evt->connLatency);
    am_log_inf("supTimeout = 0x%x", evt->supTimeout);
    #endif
}

//*****************************************************************************
//
// Connection Update event
//
//*****************************************************************************
static void uhal_cus_main_conn_update(dmEvt_t *pMsg)
{
    hciLeConnUpdateCmplEvt_t *evt = (hciLeConnUpdateCmplEvt_t*) pMsg;

    (void)evt;

    am_log_inf("connection update status = 0x%x", evt->status);

    if (evt->status == 0)
    {
        #if AM_BLE_DEBUG
        am_log_inf("handle = 0x%x", evt->handle);
        am_log_inf("connInterval = 0x%x", evt->connInterval);
        am_log_inf("connLatency = 0x%x", evt->connLatency);
        am_log_inf("supTimeout = 0x%x", evt->supTimeout);
        #endif
    }
}

//*****************************************************************************
//
//! @brief initialize cus service
//!
//! @param handlerId - connection handle
//! @param pCfg - configuration parameters
//!
//! @return None
//
//*****************************************************************************
void uhal_cus_main_init(wsfHandlerId_t handlerId, UhalCUSMainCfg_t *pCfg)
{
    memset(&svcCUSMainCb, 0, sizeof(svcCUSMainCb));
    svcCUSMainCb.appHandlerId = handlerId;

    for(int i=0; i<MAXIMUM_CUS_CHARACTERISTIC_SIZE; i++)
    {
        notify_list[i].conn_id = DM_CONN_ID_NONE;
        notify_list[i].notify_enabled = FALSE;
    }
}

void uhal_cus_main_conn_close(void)
{
    /* clear connection */
    for(int i=0; i<MAXIMUM_CUS_CHARACTERISTIC_SIZE; i++)
    {
        notify_list[i].conn_id = DM_CONN_ID_NONE;
        notify_list[i].notify_enabled = FALSE;
    }
}

void uhal_cus_main_start(dmConnId_t connId, uint8_t CUSCccIdx)
{
    //
    // set conn id
    //
    notify_list[CUSCccIdx].conn_id = connId;
    notify_list[CUSCccIdx].notify_enabled = TRUE;
}

void uhal_cus_main_stop(uint8_t CUSCccIdx)
{
    //
    // clear connection
    //
    notify_list[CUSCccIdx].conn_id = DM_CONN_ID_NONE;
    notify_list[CUSCccIdx].notify_enabled = FALSE;
}

//*****************************************************************************
//
//! @brief initialize cus service
//!
//! @param pMsg - WSF message
//!
//! @return None
//
//*****************************************************************************
void uhal_cus_main_proc_msg(wsfMsgHdr_t *pMsg)
{
    if (pMsg->event == DM_CONN_OPEN_IND)
    {
        uhal_cus_main_conn_open((dmEvt_t *) pMsg);
    }
    else if (pMsg->event == DM_CONN_UPDATE_IND)
    {
        uhal_cus_main_conn_update((dmEvt_t *) pMsg);
    }
}

static uint8_t write_cback(dmConnId_t connId, uint16_t handle, uint8_t operation,
                   uint16_t offset, uint16_t len, uint8_t *pValue, attsAttr_t *pAttr)
{
    am_log_inf("[%s]", __func__);
    am_log_inf("connId           = 0x%02X", connId);
    am_log_inf("handle           = 0x%02X", handle);
    am_log_inf("operation        = 0x%02X", operation);
    am_log_inf("offset           = 0x%04X", offset);
    am_log_inf("len              = 0x%04X", len);

    for(int i=0; i<MAXIMUM_CUS_CHARACTERISTIC_SIZE; i++)
    {
      uint16_t char_handle = 0;
      BYTES_TO_UINT16(char_handle, cus_char_settings[i].hdl);
      if(handle == char_handle)
      {
        am_log_inf("Char%d Write CB", (i+1));
        break;
      }
    }

    AttsSetAttr(handle, len, pValue);  // Update Attribute table (read caharacteristic)

    return ATT_SUCCESS;
}

static uint8_t read_cback(dmConnId_t connId, uint16_t handle, uint8_t operation,
                                   uint16_t offset, attsAttr_t *pAttr)
{
    static uint8_t s_readcnt = 0x00;

    am_log_inf("[%s]", __func__);
    am_log_inf("connId            = 0x%02X", connId);
    am_log_inf("handle            = 0x%02X", handle);
    am_log_inf("operation         = 0x%02X", operation);
    am_log_inf("offset            = 0x%04X", offset);
    am_log_inf("attsAttr_t.pLen   = 0x%04X", *pAttr->pLen);
    am_log_inf("attsAttr_t.pValue = 0x%04X", *pAttr->pValue);

    uint16_t index = 0;
    uint16_t current_uuid = 0;
    uint16_t char_handle = 0;
    for(index=0; index<MAXIMUM_CUS_CHARACTERISTIC_SIZE; index++)
    {
      BYTES_TO_UINT16(char_handle, cus_char_settings[index].hdl);
      if(handle == char_handle)
      {
        am_log_inf("Char%d Read CB", (index+1));
        current_uuid = (cus_char_uuid[index][13] << 8) + cus_char_uuid[index][12];
        break;
      }
    }

      if (CUS_SEND_HANDLER)
      {
        if(uhal_mcu_sleep_status() == true)
        {
            // Resume peripherals...
            uhal_mcu_resume();

            CUS_SEND_HANDLER(current_uuid, (uint8_t *) pAttr->pValue);
            
            // Suspend peripherals...
            uhal_mcu_suspend();
        }
        else        
            CUS_SEND_HANDLER(current_uuid, (uint8_t *) pAttr->pValue);
      }
      
    return ATT_SUCCESS;
}

/* ------- */
// Create custom service
void uhal_cus_services_init(uint8_t cus_base_uuid[])
{
  if(current_service_index > MAXIMUM_CUS_SERVICE_SIZE)
    return;

  for(int i = 0; i< MAXIMUM_CUS_CHARACTERISTIC_SIZE; i++)
  {
    cus_char_value_len[i] = ATT_DEFAULT_PAYLOAD_LEN;
  }

  //memcpy(cus_srv_uuid, cus_base_uuid, cus_uuid_len);
  for(int i=0; i<ATT_128_UUID_LEN; i++)
  {
    cus_srv_uuid[i] = cus_base_uuid[(ATT_128_UUID_LEN-1) - i];
  }

  // Service Declaration
  uhal_cus_list[0].pUuid = attPrimSvcUuid;
  uhal_cus_list[0].pValue = (uint8_t *) cus_srv_uuid;
  uhal_cus_list[0].pLen = (uint16_t *) &cus_uuid_len;
  uhal_cus_list[0].maxLen = cus_uuid_len;
  uhal_cus_list[0].settings = 0;
  uhal_cus_list[0].permissions = ATTS_PERMIT_READ;

  current_service_index++;
  current_characteristic_array_index++;
  current_service_hdl++;

  uhal_cus_group.pNext = 0;
  uhal_cus_group.pAttr = (attsAttr_t *) uhal_cus_list;
  uhal_cus_group.readCback = read_cback;
  uhal_cus_group.writeCback = write_cback;
  uhal_cus_group.startHandle = CUS_SERVICE_START_HDL;
  uhal_cus_group.endHandle = (current_service_hdl-1);

  AttsAddGroup(&uhal_cus_group);
}

int32_t uhal_cus_add_char(uint16_t chars_uuid, uint32_t chars_properties, uint8_t chars_permission, uint16_t len)
{
  if(current_service_index > MAXIMUM_CUS_SERVICE_SIZE)
    return;

  if(current_characteristic_index > MAXIMUM_CUS_CHARACTERISTIC_SIZE)
    return;

  // Create Characteristic UUID
  memcpy(cus_char_uuid[current_characteristic_index], cus_srv_uuid, cus_uuid_len);
  cus_char_uuid[current_characteristic_index][12] = (uint8_t) (chars_uuid);
  cus_char_uuid[current_characteristic_index][13] = (uint8_t) ((chars_uuid) >> 8);

  // Create Characteristic Settings
  if((chars_properties & CHR_PROPS_WRITE) == CHR_PROPS_WRITE)
  {
    am_log_inf("WRITE_CHAR: 0x%X", chars_uuid);
    cus_char_settings[current_characteristic_index].settings |= (ATT_PROP_WRITE);
  }
  if((chars_properties & CHR_PROPS_WRITE_WO_RESP) == CHR_PROPS_WRITE_WO_RESP)
  {
    am_log_inf("WRITE_CHAR: 0x%X", chars_uuid);
    cus_char_settings[current_characteristic_index].settings |= (ATT_PROP_WRITE | ATT_PROP_WRITE_NO_RSP);
  }
  if((chars_properties & CHR_PROPS_READ) == CHR_PROPS_READ)
  {
    am_log_inf("READ_CHAR: 0x%X", chars_uuid);
    cus_char_settings[current_characteristic_index].settings |= (ATT_PROP_READ);
  }
  if((chars_properties & CHR_PROPS_NOTIFY) == CHR_PROPS_NOTIFY)
  {
    am_log_inf("NOTIFY_CHAR: 0x%X", chars_uuid);
    cus_char_settings[current_characteristic_index].settings |= (ATT_PROP_NOTIFY);
  }

  current_service_hdl++;
  cus_char_settings[current_characteristic_index].hdl[0] = (uint8_t) (current_service_hdl);
  cus_char_settings[current_characteristic_index].hdl[1] = (uint8_t) ((current_service_hdl) >> 8);
  memcpy(cus_char_settings[current_characteristic_index].uuid, cus_char_uuid[current_characteristic_index], cus_uuid_len);

  // Characteristic Declaration
  uhal_cus_list[current_characteristic_array_index].pUuid = attChUuid;
  uhal_cus_list[current_characteristic_array_index].pValue = (uint8_t *) &cus_char_settings[current_characteristic_index];
  uhal_cus_list[current_characteristic_array_index].pLen = (uint16_t *) &cus_char_settings_len;
  uhal_cus_list[current_characteristic_array_index].maxLen = cus_char_settings_len;
  uhal_cus_list[current_characteristic_array_index].settings = 0;
  uhal_cus_list[current_characteristic_array_index].permissions = ATTS_PERMIT_READ;

  current_characteristic_array_index++;

  // Set characteristic value len
  if(len > 0 && len <= ATT_DEFAULT_PAYLOAD_LEN)
    cus_char_value_len[current_characteristic_index] = len;
  else
    cus_char_value_len[current_characteristic_index] = ATT_DEFAULT_PAYLOAD_LEN;

  // Characteristic Value
  uhal_cus_list[current_characteristic_array_index].pUuid = cus_char_settings[current_characteristic_index].uuid;
  uhal_cus_list[current_characteristic_array_index].pValue = (uint8_t *) &cus_char_value[current_characteristic_index];
  uhal_cus_list[current_characteristic_array_index].pLen = (uint16_t *) &cus_char_value_len[current_characteristic_index];
  uhal_cus_list[current_characteristic_array_index].maxLen = ATT_VALUE_MAX_LEN;
  if((chars_properties & CHR_PROPS_WRITE) == CHR_PROPS_WRITE)
    uhal_cus_list[current_characteristic_array_index].settings |= (ATTS_SET_UUID_128 | ATTS_SET_VARIABLE_LEN | ATTS_SET_WRITE_CBACK);
  if((chars_properties & CHR_PROPS_WRITE_WO_RESP) == CHR_PROPS_WRITE_WO_RESP)
    uhal_cus_list[current_characteristic_array_index].settings |= (ATTS_SET_UUID_128 | ATTS_SET_VARIABLE_LEN | ATTS_SET_WRITE_CBACK);
  if((chars_properties & CHR_PROPS_READ) == CHR_PROPS_READ)
    uhal_cus_list[current_characteristic_array_index].settings |= (ATTS_SET_UUID_128 | ATTS_SET_VARIABLE_LEN | ATTS_SET_READ_CBACK);
  if((chars_properties & CHR_PROPS_NOTIFY) == CHR_PROPS_NOTIFY)
    uhal_cus_list[current_characteristic_array_index].settings |= (ATTS_SET_UUID_128 | ATTS_SET_VARIABLE_LEN);
  if((chars_properties & CHR_PROPS_WRITE) == CHR_PROPS_WRITE)
    uhal_cus_list[current_characteristic_array_index].permissions |= ATTS_PERMIT_WRITE;
  if((chars_properties & CHR_PROPS_WRITE_WO_RESP) == CHR_PROPS_WRITE_WO_RESP)
    uhal_cus_list[current_characteristic_array_index].permissions |= ATTS_PERMIT_WRITE;
  if((chars_properties & CHR_PROPS_READ) == CHR_PROPS_READ)
    uhal_cus_list[current_characteristic_array_index].permissions |= ATTS_PERMIT_READ;
  if((chars_properties & CHR_PROPS_NOTIFY) == CHR_PROPS_NOTIFY)
    uhal_cus_list[current_characteristic_array_index].permissions |= ATTS_PERMIT_READ;

  current_characteristic_array_index++;
  current_service_hdl++;

  if((chars_properties & CHR_PROPS_NOTIFY) == CHR_PROPS_NOTIFY)
  {
    cus_char_ccc[current_characteristic_index][0] = 0x00;
    cus_char_ccc[current_characteristic_index][1] = 0x00;

    uhal_cus_list[current_characteristic_array_index].pUuid = attCliChCfgUuid;
    uhal_cus_list[current_characteristic_array_index].pValue = (uint8_t *) &cus_char_ccc[current_characteristic_index];
    uhal_cus_list[current_characteristic_array_index].pLen = (uint16_t *) &cus_char_ccc_len;
    uhal_cus_list[current_characteristic_array_index].maxLen = cus_char_ccc_len;
    uhal_cus_list[current_characteristic_array_index].settings = ATTS_SET_CCC;
    uhal_cus_list[current_characteristic_array_index].permissions = (ATTS_PERMIT_READ | ATTS_PERMIT_WRITE);

    // DM_SEC_LEVEL_NONE           0     /*!< \brief Connection has no security */
    // DM_SEC_LEVEL_ENC            1     /*!< \brief Connection is encrypted with unauthenticated key */
    // DM_SEC_LEVEL_ENC_AUTH       2     /*!< \brief Connection is encrypted with authenticated key */
    // DM_SEC_LEVEL_ENC_LESC       3     /*!< \brief Connection is encrypted with LE Secure Connections */
    bleModuleCccSet[current_notify_list_index+3].handle = current_service_hdl;
    bleModuleCccSet[current_notify_list_index+3].valueRange = ATT_CLIENT_CFG_NOTIFY;
    if(chars_permission>=DM_SEC_LEVEL_NONE && chars_permission<=DM_SEC_LEVEL_ENC_LESC)
      bleModuleCccSet[current_notify_list_index+3].secLevel = chars_permission;
    else
      bleModuleCccSet[current_notify_list_index+3].secLevel = DM_SEC_LEVEL_NONE;

    notify_list[current_notify_list_index].notify_enabled = FALSE;
    notify_list[current_notify_list_index].conn_id = 0;
    notify_list[current_notify_list_index].index = current_notify_list_index;
    notify_list[current_notify_list_index].handle = current_service_hdl-1;
    notify_list[current_notify_list_index].uuid = chars_uuid;

    current_notify_list_index++;
    current_characteristic_array_index++;
    current_service_hdl++;
  }

  current_characteristic_index++;

  uhal_cus_group.endHandle = (current_service_hdl-1);
}

void uhal_cus_control_notify(uint16_t value, uint16_t conn_id, uint16_t index, uint16_t handle)
{
  if (value == ATT_CLIENT_CFG_NOTIFY)
  {
      // notify enabled
      uhal_cus_main_start((dmConnId_t) conn_id, index);
    
      if (CUS_NOTIFY_HANDLER && uhal_is_connected == 1)
      {
        if(uhal_mcu_sleep_status() == true)
        {
            // Resume peripherals...
            uhal_mcu_resume();

            CUS_NOTIFY_HANDLER(notify_list[index].uuid, (uint8_t *) cus_char_value[index]);
            
            // Suspend peripherals...
            uhal_mcu_suspend();
        }
        else        
            CUS_NOTIFY_HANDLER(notify_list[index].uuid, (uint8_t *) cus_char_value[index]);
      }
  }
  else
  {
      // notify disabled
      uhal_cus_main_stop(index);
      if (CUS_NOTIFY_HANDLER && uhal_is_connected == 1)
      {
        if(uhal_mcu_sleep_status() == true)
        {
            // Resume peripherals...
            uhal_mcu_resume();

            CUS_NOTIFY_HANDLER(notify_list[index].uuid, (uint8_t *) 0);
            
            // Suspend peripherals...
            uhal_mcu_suspend();
        }
        else        
            CUS_NOTIFY_HANDLER(notify_list[index].uuid, (uint8_t *) 0);
      }
  }
}

//*****************************************************************************
//
// Write to Client
//
//*****************************************************************************
uint32_t uhal_cus_write(uint16_t uuid, uint8_t *buf)
{
    uint16_t index = 0;
    uint16_t current_uuid = 0;
    for(index = 0; index<MAXIMUM_CUS_CHARACTERISTIC_SIZE; index++)
    {
      current_uuid = (cus_char_uuid[index][13] << 8) + cus_char_uuid[index][12];
      if(current_uuid == uuid)
      {
        break;
      }
    }

    if(index == MAXIMUM_CUS_CHARACTERISTIC_SIZE)
    {
      am_log_inf("CUS Invalid UUID");
      return -1;
    }

    uint16_t char_handle = 0;
    BYTES_TO_UINT16(char_handle, cus_char_settings[index].hdl);
    uint8_t err_code = AttsSetAttr(char_handle, cus_char_value_len[index], buf);
    am_log_inf("Handle: %d, Index: %d, Err: %d", char_handle, index, err_code);

    return 0;
}

//*****************************************************************************
//
// Write to Client
//
//*****************************************************************************
uint32_t uhal_cus_send_data(uint16_t uuid, uint8_t *buf)
{
    uint16_t index = 0;
    for(index = 0; index<MAXIMUM_CUS_CHARACTERISTIC_SIZE; index++)
    {
      if(notify_list[index].uuid == uuid)
      {
        break;
      }
    }

    if(index == MAXIMUM_CUS_CHARACTERISTIC_SIZE)
    {
      am_log_inf("CUS Invalid UUID");
      return -1;
    }

    /* send notification */
    if ( notify_list[index].conn_id )
    {
        AttsHandleValueNtf(notify_list[index].conn_id, notify_list[index].handle, cus_char_value_len[index], buf);
        return 0;
    }
    else
    {
        am_log_inf("CUS Invalid Conn");

        uint16_t char_handle = 0;
        BYTES_TO_UINT16(char_handle, cus_char_settings[index].hdl);
        AttsSetAttr(char_handle, cus_char_value_len[index], buf);
        return -1;
    }
}

uint8_t uhal_cus_is_notifyEnabled(uint16_t chars_uuid)
{
    uint16_t index = 0;
    for(index = 0; index<MAXIMUM_CUS_CHARACTERISTIC_SIZE; index++)
    {
      if(notify_list[index].uuid == chars_uuid)
      {
        break;
      }
    }

    if(index == MAXIMUM_CUS_CHARACTERISTIC_SIZE)
    {
      am_log_inf("CUS Invalid UUID");
      return -1;
    }

    return notify_list[index].notify_enabled;
}