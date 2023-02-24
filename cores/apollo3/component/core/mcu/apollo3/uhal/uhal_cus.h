#ifndef UHAL_CUS_H__
#define UHAL_CUS_H__

//
// Put additional includes here if necessary.
//

#ifdef __cplusplus
extern "C"
{
#endif

#include "stdint.h"
#include "wsf_timer.h"
#include "wsf_types.h"
#include "att_api.h"
#include "dm_api.h"
#include "uhal_cus.h"
#include "att_api.h"
#include "wsf_types.h"
#include "udrv_ble.h"

//*****************************************************************************
//
// Macro definitions
//
//*****************************************************************************
#define CUS_SERVICE_START_HDL               0x0600 // This is important!!!

#define MAXIMUM_CUS_SERVICE_SIZE 1
#define MAXIMUM_CUS_CHARACTERISTIC_SIZE 7

#pragma pack(push,1)
typedef struct 
{
  bool_t   notify_enabled;
  uint16_t conn_id;
  uint16_t index;
  uint16_t uuid;
  uint16_t handle;
} notify_char_t;
#pragma pack(pop)

//*****************************************************************************
//
// Macro definitions
//
//*****************************************************************************
/*! Configurable parameters */
typedef struct
{
    //! Short description of each member should go here.
    uint32_t reserved;
} UhalCUSMainCfg_t;

/* Control block */
static struct
{
    UhalCUSMainCfg_t        cfg;                  // configurable parameters
    wsfHandlerId_t          appHandlerId;
} svcCUSMainCb;

//*****************************************************************************
//
// External variable definitions
//
//*****************************************************************************

//*****************************************************************************
//
// External function definitions.
//
//*****************************************************************************

//*****************************************************************************
//
// function definitions
//
//*****************************************************************************
void uhal_cus_main_init(wsfHandlerId_t handlerId, UhalCUSMainCfg_t *pCfg);

void uhal_cus_main_proc_msg(wsfMsgHdr_t *pMsg);

void uhal_cus_main_start(dmConnId_t connId, uint8_t CUSCccIdx);

void uhal_cus_main_stop(uint8_t CUSCccIdx);

void uhal_cus_main_conn_close(void);

void uhal_cus_services_init(uint8_t cus_base_uuid[]);
int32_t uhal_cus_add_char(uint16_t chars_uuid, uint32_t chars_properties, uint8_t chars_permission, uint16_t len);
void uhal_cus_control_notify(uint16_t value, uint16_t conn_id, uint16_t index, uint16_t handle);
uint32_t uhal_cus_send_data(uint16_t uuid, uint8_t *buf);
uint32_t uhal_cus_write(uint16_t uuid, uint8_t *buf);
uint8_t uhal_cus_is_notifyEnabled(uint16_t chars_uuid);

#ifdef __cplusplus
}
#endif

#endif // UHAL_CUS_H__
