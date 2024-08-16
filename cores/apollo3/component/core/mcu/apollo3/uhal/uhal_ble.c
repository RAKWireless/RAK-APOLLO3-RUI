#include "uhal_ble.h"
#include "uhal_ble_cfg.h"
#include "am_log.h"
#include "udrv_system.h"

#ifdef SUPPORT_BLE

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

//*****************************************************************************
//
// Standard AmbiqSuite includes.
//
//*****************************************************************************
#include "am_mcu_apollo.h"
#include "am_bsp.h"
#include "am_util.h"
#include "fund_circular_queue.h"

//*****************************************************************************
//
// Required built-ins.
//
//*****************************************************************************
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//*****************************************************************************
//
// FreeRTOS include files.
//
//*****************************************************************************
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"
#include "portable.h"
#include "semphr.h"
#include "event_groups.h"
#include "rtos.h"

//*****************************************************************************
//
// WSF standard includes.
//
//*****************************************************************************
#include "wsf_types.h"
#include "wsf_trace.h"
#include "wsf_buf.h"
#include "wsf_timer.h"

//*****************************************************************************
//
// Includes for operating the ExactLE stack.
//
//*****************************************************************************
#include "hci_handler.h"
#include "dm_handler.h"
#include "l2c_handler.h"
#include "att_handler.h"
#include "smp_handler.h"
#include "l2c_api.h"
#include "att_api.h"
#include "smp_api.h"
#include "app_api.h"
#include "hci_core.h"
#include "hci_drv.h"
#include "hci_drv_apollo.h"
#include "hci_drv_apollo3.h"

#include "am_mcu_apollo.h"
#include "am_util.h"
#include "am_bsp.h"
#include "am_log.h"

#include "hci_apollo_config.h"
#include "wsf_msg.h"
#include "uhal_uart.h"
#include "uhal_powersave.h"
#include "uhal_delay.h"

//*****************************************************************************
//
// Includes for the ExactLE "fit" profile.
//
//*****************************************************************************
#include "app_ui.h"

#ifdef AM_NUS_ADD
#include "uhal_nus.h"
#include "uhal_nus_main.h"
#endif

#ifdef AM_AMOTA_ADD
#include "svc_amotas.h"
#include "amotas_api.h"
#endif

#ifdef AM_CUS_ADD
#include "uhal_cus.h"
#endif

//*****************************************************************************
//
// Radio task handle.
//
//*****************************************************************************
TaskHandle_t radio_task_handle;

//*****************************************************************************
//
// Function prototypes
//
//*****************************************************************************
void exactle_stack_init(void);

//*****************************************************************************
//
// WSF buffer pools.
//
//*****************************************************************************
#define WSF_BUF_POOLS               4

// Important note: the size of g_pui32BufMem should includes both overhead of internal
// buffer management structure, wsfBufPool_t (up to 16 bytes for each pool), and pool
// description (e.g. g_psPoolDescriptors below).

// Memory for the buffer pool
static uint32_t g_pui32BufMem[
        (WSF_BUF_POOLS*16
         + 16*8 + 32*4 + 64*6 + 280*8) / sizeof(uint32_t)];

// Default pool descriptor.
static wsfBufPoolDesc_t g_psPoolDescriptors[WSF_BUF_POOLS] =
{
    {  16,  8 },
    {  32,  4 },
    {  64,  6 },
    { 280,  8 }
};

//*****************************************************************************
//
// Tracking variable for the scheduler timer.
//
//*****************************************************************************

void radio_timer_handler(void);

// This file exists solely for compilation compatibility with legacy libraries
// Test if in interrupt mode
static inline bool isInISR(void)
{
  return (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0 ;
}


/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! Application message type */
typedef union
{
    wsfMsgHdr_t     hdr;
    dmEvt_t         dm;
    attsCccEvt_t    ccc;
    attEvt_t        att;
} bleModuleMsg_t;

/**************************************************************************************************
  Configurable Parameters
**************************************************************************************************/

/*! configurable parameters for advertising */
static appAdvCfg_t adv_conf =
 {
     {   0,    0,    0},                  /*! Advertising durations in ms */
     {   0,    0,    0}                   /*! Advertising intervals in 0.625 ms units */
 };

/*! configurable parameters for slave */
static const appSlaveCfg_t slave_conf =
{
    BLE_MODULE_CONN_MAX,                           /*! Maximum connections */
};

/*! local IRK */
static uint8_t localIrk[] = {
    0x95, 0xC8, 0xEE, 0x6F, 0xC5, 0x0D, 0xEF, 0x93, 0x35, 0x4E, 0x7C, 0x57, 0x08, 0xE2, 0xA3, 0x85
};

/*! configurable parameters for security */
static appSecCfg_t security_conf =
{
  DM_AUTH_BOND_FLAG,                     /*! Authentication and bonding flags */
  DM_KEY_DIST_IRK,                       /*! Initiator key distribution flags */
  DM_KEY_DIST_LTK | DM_KEY_DIST_IRK,     /*! Responder key distribution flags */
  TRUE,                                  /*! TRUE if Out-of-band pairing data is present */
  TRUE                                   /*! TRUE to initiate security upon connection */
};

/*! SMP security parameter configuration */
static smpCfg_t security_parameters =
{
  3000,                                     /*! 'Repeated attempts' timeout in msec */
  SMP_IO_NO_IN_NO_OUT,                      /*! I/O Capability */
  7,                                        /*! Minimum encryption key length */
  16,                                       /*! Maximum encryption key length */
  3,                                        /*! Attempts to trigger 'repeated attempts' timeout */
  0,                                        /*! Device authentication requirements */
};

/*! configurable parameters for connection parameter update */
static appUpdateCfg_t connparam_conf =
{
    0,                                   /*! Connection idle period in ms before attempting
                                             connection parameter update; set to zero to disable */
    (20 / 1.25),                         /*! 15 ms */
    (75 / 1.25),                         /*! 30 ms */
    0,                                   /*! Connection latency */
    (4000 / 10),                         /*! Supervision timeout in 10ms units */
    5                                    /*! Number of update attempts before giving up */
};

/*! Configurable parameters for service and characteristic discovery */
// static const appDiscCfg_t disc_conf =
// {
//   FALSE                                   /*! TRUE to wait for a secure connection before initiating discovery */
// };

// static const appCfg_t app_conf =
// {
//   TRUE,                                   /*! TRUE to abort service discovery if service not found */
//   TRUE                                    /*! TRUE to disconnect if ATT transaction times out */
// };

/*! configurable parameters for master */
static appMasterCfg_t scanner_conf =
{
  SCAN_INTERVAL,                       /*! The scan interval, in 0.625 ms units */
  SCAN_WINDOW,                         /*! The scan window, in 0.625 ms units  */
  SCAN_DURATION,                       /*! The scan duration in ms */
  DM_DISC_MODE_GENERAL,                /*! The GAP discovery mode */
  DM_SCAN_TYPE_ACTIVE                 /*! The scan type (active or passive) */
};

/**************************************************************************************************
  Macros
**************************************************************************************************/
#ifdef AM_NUS_ADD
/*! NUS service configuration */ // This is for NUS Service
static const UhalNUSMainCfg_t UhalNUSMainCfg =
{
    0
};
#endif

#ifdef AM_AMOTA_ADD
/*! AMOTAS configuration */
static const AmotasCfg_t s_sAmotasCfg =
{
    .reserved   = 0,
};

#ifdef AM_CUS_ADD
/*! NUS service configuration */ // This is for NUS Service
static const UhalCUSMainCfg_t UhalCUSMainCfg =
{
    0
};
#endif

/*! WSF message event enumeration */
enum
{
    /*! WSF message event starting value */
    BLE_MODULE_MSG_START      = 0xC0,
    BLE_MODULE_AMOTA_RESET_TIMER_IND,  /*! AMOTA reset timer expired */
    BLE_MODULE_AMOTA_DISCONNECT_TIMER_IND,  /*! AMOTA disconnect timer expired */
};
#endif

/**************************************************************************************************
  Advertising Data
**************************************************************************************************/

/*! advertising data, discoverable mode */
static uint8_t adv_data[31];
static uint8_t adv_data_size = 31;

/*! scan data, discoverable mode */
static uint8_t scan_data[31];
static uint8_t scan_data_size = 31;

extern uint8_t uhal_cus_base_uuid[16];

/**************************************************************************************************
  Client Characteristic Configuration Descriptors
**************************************************************************************************/

/*! enumeration of client characteristic configuration descriptors */
// enum
// {
//     BLE_MODULE_GATT_SC_CCC_IDX,   /*! GATT service, service changed characteristic */
//     #ifdef AM_NUS_ADD
//     BLE_MODULE_UHAL_NUS_CHAR2_CCC_IDX,   /*! NUS service, char2 characteristic */
//     #endif
//     #ifdef AM_AMOTA_ADD
//     BLE_MODULE_AMOTAS_TX_CCC_IDX, /*! AMOTA service, tx characteristic */
//     #endif
//     BLE_MODULE_NUM_CCC_IDX
// };

/*! client characteristic configuration descriptors settings, indexed by above enumeration */
// BLE_MODULE_GATT_SC_CCC_IDX -> 1
// BLE_MODULE_UHAL_NUS_CHAR2_CCC_IDX -> 2
// BLE_MODULE_AMOTAS_TX_CCC_IDX -> 3
// 4-5-6-7-8-9-10 (CUS up to 7 notify characteristic...)
uint16_t ccc_index = BLE_MODULE_NOTIFY_CHAR_SIZE;
attsCccSet_t bleModuleCccSet[BLE_MODULE_NOTIFY_CHAR_SIZE] =
{
    /* cccd handle          value range               security level */
    {GATT_SC_CH_CCC_HDL,    ATT_CLIENT_CFG_INDICATE,  DM_SEC_LEVEL_NONE}, // GATT service (index-0)
    #ifdef AM_NUS_ADD
    {NUS_CHAR2_CH_CCC_HDL,  ATT_CLIENT_CFG_NOTIFY,    DM_SEC_LEVEL_NONE}, // (index-1)
    #endif
    #ifdef AM_AMOTA_ADD
    {AMOTAS_TX_CH_CCC_HDL,  ATT_CLIENT_CFG_NOTIFY,    DM_SEC_LEVEL_NONE}, // (index-2)
    #endif
};

/**************************************************************************************************
  Global Variables
**************************************************************************************************/

/*! WSF handler ID */
wsfHandlerId_t bleModuleHandlerId;
txPowerLevel_t tx_power_level = TX_POWER_LEVEL_0P0_dBm;

/**************************************************************************************************
  RAK related variables
**************************************************************************************************/

static uint32_t uhal_ble_wlock_cnt;

int uhal_is_advertising = 0;
int uhal_is_connected = 0;
uint32_t ui32IntEnable;

extern void *BLE;

extern bool udrv_powersave_in_sleep;
static udrv_system_event_t rui_ble_event = {.request = UDRV_SYS_EVT_OP_SERIAL_BLE, .p_context = NULL};

struct uhal_ble_parameter ble_parameter =
{
    .txpower = DRV_BLE_TX_POWER_0DBM,
    .custom_dev_name = {'\0'},
    .adv_interval = APP_ADV_INTERVAL,
    .adv_mode = DRV_BLE_ADV_MODE_FAST,
    .service_mode = DRV_BLE_UART_MODE,
    .adv_timeout = APP_ADV_TIMEOUT_IN_SECONDS,
    .pairing_key = {},
    .permission = SET_ENC_NO_MITM,
};

#define READ_SIZE 1
FUND_CIRCULAR_QUEUE_INIT(uint8_t, BLE_rxq, 256);

/* Scanner Parameters*/
#pragma pack(push,1)
typedef struct 
{
    uint8_t adv_data[31];
    uint8_t adv_length;
    int8_t  rssi;
    uint8_t mac_addr[6];
} scanner_data_t;
#pragma pack(pop)

#define SCANNER_ITEM_SIZE 10
static QueueHandle_t        Scanner_Queue;
static SemaphoreHandle_t    Scanner_Semaphore;
static TaskHandle_t         Scanner_Task;

static void ble_queue_reset(void)
{
    BLE_rxq.start = 0;
    BLE_rxq.end = 0;
}

void uhal_ble_wake_lock (void) {
    uhal_ble_wlock_cnt++;
}

void uhal_ble_wake_unlock (void) {
    if (uhal_ble_wlock_cnt > 0) {
        uhal_ble_wlock_cnt--;
    }
}

void uhal_ble_wake_unlock_all (void) {
    while (uhal_ble_wlock_cnt > 0) {
        uhal_ble_wlock_cnt--;
    }
}

static void (*SCAN_DATA_HANDLER)(int8_t, uint8_t *, uint8_t *, uint16_t); //rssi, mac address, raw data, raw data length
static void (*CONNECT_HANDLER)(void);
static void (*DISCONNECT_HANDLER)(void);

void uhal_ble_connect_handler(BLE_HANDLER handler)
{
    CONNECT_HANDLER = handler;
}
    
void uhal_ble_disconnect_handler(BLE_HANDLER handler)
{
    DISCONNECT_HANDLER = handler;  
}

void uhal_ble_scan_data_handler(BLE_SCAN_DATA_HANDLER handler)
{
    SCAN_DATA_HANDLER = handler;
}

static void (*CLI_HANDLER) (void *);

void uhal_ble_register_cli_handler (SERIAL_CLI_HANDLER handler)
{
    CLI_HANDLER = handler;
}

/*************************************************************************************************/
/*!
 *  \fn     bleModuleDmCback
 *
 *  \brief  Application DM callback.
 *
 *  \param  pDmEvt  DM callback event
 *
 *  \return None.
 */
/*************************************************************************************************/
static void bleModuleDmCback(dmEvt_t *pDmEvt)
{
    dmEvt_t *pMsg;

    if ((pMsg = WsfMsgAlloc(sizeof(dmEvt_t))) != NULL)
    {
        memcpy(pMsg, pDmEvt, sizeof(dmEvt_t));
        WsfMsgSend(bleModuleHandlerId, pMsg);
    }
}

/*************************************************************************************************/
/*!
 *  \fn     bleModuleAttCback
 *
 *  \brief  Application ATT callback.
 *
 *  \param  pEvt    ATT callback event
 *
 *  \return None.
 */
/*************************************************************************************************/
static void bleModuleAttCback(attEvt_t *pEvt)
{
    attEvt_t *pMsg;

    if ((pMsg = WsfMsgAlloc(sizeof(attEvt_t) + pEvt->valueLen)) != NULL)
    {
        memcpy(pMsg, pEvt, sizeof(attEvt_t));
        pMsg->pValue = (uint8_t *) (pMsg + 1);
        memcpy(pMsg->pValue, pEvt->pValue, pEvt->valueLen);
        WsfMsgSend(bleModuleHandlerId, pMsg);
    }
}

/*************************************************************************************************/
/*!
 *  \fn     bleModuleCccCback
 *
 *  \brief  Application ATTS client characteristic configuration callback.
 *
 *  \param  pDmEvt  DM callback event
 *
 *  \return None.
 */
/*************************************************************************************************/
static void bleModuleCccCback(attsCccEvt_t *pEvt)
{
    attsCccEvt_t  *pMsg;
    appDbHdl_t    dbHdl;

    // FIX ME: Cordio stack problem. pEvt->handle is NULL!!!
    uint16_t handle = bleModuleCccSet[pEvt->idx].handle;
    am_log_inf("bleModuleCccCback value:%d handle:%d idx:%d", pEvt->value, handle, pEvt->idx);
    // END_OF_FIXME 

    /* if CCC not set from initialization and there's a device record */
    if ((handle != ATT_HANDLE_NONE) &&
        ((dbHdl = AppDbGetHdl((dmConnId_t) pEvt->hdr.param)) != APP_DB_HDL_NONE) &&
        AppCheckBonded((dmConnId_t)pEvt->hdr.param))
    {
        /* store value in device database */
        AppDbSetCccTblValue(dbHdl, pEvt->idx, pEvt->value);
    }

    if ((pMsg = WsfMsgAlloc(sizeof(attsCccEvt_t))) != NULL)
    {
        memcpy(pMsg, pEvt, sizeof(attsCccEvt_t));
        pMsg->handle = handle;
        WsfMsgSend(bleModuleHandlerId, pMsg);
    }
}

/*************************************************************************************************/
/*!
 *  \fn     bleModuleProcCccState
 *
 *  \brief  Process CCC state change.
 *
 *  \param  pMsg    Pointer to message.
 *
 *  \return None.
 */
/*************************************************************************************************/
static void bleModuleProcCccState(bleModuleMsg_t *pMsg)
{
    am_log_inf("ccc state ind value:%d handle:%d idx:%d", pMsg->ccc.value, pMsg->ccc.handle, pMsg->ccc.idx);

    /* handle heart rate measurement CCC */

    switch(pMsg->ccc.idx)
    {
        #ifdef AM_NUS_ADD
        case 1: // index-1 NUS
            if (pMsg->ccc.value == ATT_CLIENT_CFG_NOTIFY)
            {
                // notify enabled
                uhal_nus_main_start((dmConnId_t) pMsg->ccc.hdr.param,
                                    pMsg->ccc.idx);
            }
            else
            {
                // notify disabled
                uhal_nus_main_stop((dmConnId_t) pMsg->ccc.hdr.param);
            }
            break;
        #endif

        #ifdef AM_AMOTA_ADD 
        case 2: // index-2 AMOTAS
            if (pMsg->ccc.value== ATT_CLIENT_CFG_NOTIFY)
            {
                // notify enabled
                amotas_start((dmConnId_t) pMsg->ccc.hdr.param, 
                            BLE_MODULE_AMOTA_RESET_TIMER_IND, 
                            BLE_MODULE_AMOTA_DISCONNECT_TIMER_IND, 
                            pMsg->ccc.idx);
            }
            else
            {
                // notify disabled
                amotas_stop((dmConnId_t) pMsg->ccc.hdr.param);
            }
            break;
        #endif
    }
    /* ----- */

    #ifdef AM_CUS_ADD
    if(pMsg->ccc.idx>2)
    {
        uhal_cus_control_notify(pMsg->ccc.value, pMsg->ccc.hdr.param, (pMsg->ccc.idx-3), pMsg->ccc.handle);
    }

    #endif
}

/*************************************************************************************************/
/*!
 *  \fn     bleModuleClose
 *
 *  \brief  Perform UI actions on connection close.
 *
 *  \param  pMsg    Pointer to message.
 *
 *  \return None.
 */
/*************************************************************************************************/
static void bleModuleClose(bleModuleMsg_t *pMsg)
{
    am_log_inf("bleModuleClose connId=%d", pMsg->hdr.param);

    #ifdef AM_NUS_ADD
    uhal_nus_main_conn_close((dmConnId_t)  pMsg->hdr.param);
    #endif

    #ifdef AM_AMOTA_ADD
    amotas_conn_close((dmConnId_t)  pMsg->hdr.param);
    #endif

    #ifdef AM_CUS_ADD
    uhal_cus_main_conn_close();
    #endif
}

// RX Task to handle incoming data via UART
void scanner_handler(void *pvPaParameters)
{
    scanner_data_t data;

    while(1)
    {
        xSemaphoreTake(Scanner_Semaphore, portMAX_DELAY);

        if(uhal_mcu_sleep_status() == true)
        {
            // Resume peripherals...
            uhal_mcu_resume();

            uint16_t size = uxQueueMessagesWaiting(Scanner_Queue);
            am_log_inf("DM_SCAN_REPORT_IND_SLEEP: %d", size);
            for(uint16_t i = 0; i < size; i++)
            {
                xQueueReceive(Scanner_Queue, &data, portMAX_DELAY);
                
                SCAN_DATA_HANDLER(data.rssi, data.mac_addr, data.adv_data, data.adv_length);//rssi, mac address, raw data, raw data length
            }

            // Suspend peripherals...
            uhal_mcu_suspend();
        }
        else
        {
            uint16_t size = uxQueueMessagesWaiting(Scanner_Queue);
            am_log_inf("DM_SCAN_REPORT_IND: %d", size);
            for(uint16_t i = 0; i < size; i++)
            {
                xQueueReceive(Scanner_Queue, &data, portMAX_DELAY);
         
                SCAN_DATA_HANDLER(data.rssi, data.mac_addr, data.adv_data, data.adv_length);//rssi, mac address, raw data, raw data length
            }
        }
    }
}
/*************************************************************************************************/
/*!
 *  \fn     bleModuleProcMsg
 *
 *  \brief  Process messages from the event handler.
 *
 *  \param  pMsg    Pointer to message.
 *
 *  \return None.
 */
/*************************************************************************************************/
SemaphoreHandle_t adv_stop_semaphore;
SemaphoreHandle_t adv_start_semaphore;
SemaphoreHandle_t conn_stop_semaphore;
SemaphoreHandle_t scan_start_semaphore;
SemaphoreHandle_t scan_stop_semaphore;
SemaphoreHandle_t ble_module_init_semaphore;
SemaphoreHandle_t nus_notify_semaphore;
uint16_t att_mtu = ATT_DEFAULT_MTU - 3;
static bool is_ble_module_init = false;
static void bleModuleProcMsg(bleModuleMsg_t *pMsg)
{
    uint8_t uiEvent = APP_UI_NONE;
    BaseType_t xHigherPriorityTaskWoken, xResult;

    switch(pMsg->hdr.event)
    {
        case ATTS_HANDLE_VALUE_CNF:
            am_log_inf("ATTS_HANDLE_VALUE_CNF");
            #ifdef AM_NUS_ADD
            if(pMsg->att.handle == NUS_CHAR2_HDL)
            #else
            if(0)
            #endif
            {
                am_log_inf("NUS");
                xSemaphoreGive(nus_notify_semaphore);
            }
            else
            {
                am_log_inf("OTHER");
            }
            break;

        case ATTS_CCC_STATE_IND:
            am_log_inf("ATTS_CCC_STATE_IND");
            bleModuleProcCccState(pMsg);
            break;

        case ATT_MTU_UPDATE_IND:
            am_log_inf("Negotiated MTU %d", ((attEvt_t *)pMsg)->mtu);
            att_mtu = (((attEvt_t *)pMsg)->mtu) - 3;
            break;

        case DM_RESET_CMPL_IND:
            am_log_inf("BLE Module Setup!");
            AttsCalculateDbHash();
            DmSecGenerateEccKeyReq();
            xSemaphoreGive(ble_module_init_semaphore);

            uiEvent = APP_UI_RESET_CMPL;
            break;

        case DM_ADV_SET_START_IND:
            am_log_inf("DM_ADV_SET_START_IND");
            uiEvent = APP_UI_ADV_SET_START_IND;
            break;

        case DM_ADV_SET_STOP_IND:
            am_log_inf("DM_ADV_SET_STOP_IND");
            uiEvent = APP_UI_ADV_SET_STOP_IND;
            break;

        case DM_ADV_START_IND:
            am_log_inf("Adv started.");
            uhal_is_advertising = true;
            xSemaphoreGive(adv_start_semaphore);
            
            uiEvent = APP_UI_ADV_START;
            break;

        case DM_ADV_STOP_IND:
            am_log_inf("Adv stopped.");
            uhal_is_advertising = false;
            xSemaphoreGive(adv_stop_semaphore);
            uiEvent = APP_UI_ADV_STOP;
            break;

        case DM_SCAN_START_IND:
        {
            am_log_inf("Scan start.");
            uhal_is_scanning = true;
            xSemaphoreGive(scan_start_semaphore);
        }
        break;

        case DM_SCAN_STOP_IND:
        {
            uhal_is_scanning = false;
            xSemaphoreGive(scan_stop_semaphore);
            am_log_inf("Scan stop.");
        }

        break;

        case DM_SCAN_REPORT_IND:
        {
            if(SCAN_DATA_HANDLER && (pMsg->dm.scanReport.len !=0))
            {
                scanner_data_t data;
                memcpy(&data.adv_data, pMsg->dm.scanReport.pData, pMsg->dm.scanReport.len);
                data.adv_length = pMsg->dm.scanReport.len;
                memcpy(&data.mac_addr, pMsg->dm.scanReport.addr, sizeof(data.mac_addr));
                data.rssi = pMsg->dm.scanReport.rssi;

                if(pdPASS != xQueueSendToBack(Scanner_Queue, &data, ( TickType_t ) 10))
                {
                    am_log_inf("Scanner queue error!!!");
                }

                xSemaphoreGive(Scanner_Semaphore);
            }
        }
        break;

        case DM_CONN_OPEN_IND:
            am_log_inf("(NUS) Connected.");
            if(ble_parameter.permission == SET_ENC_WITH_MITM)
            {
                security_conf.auth = DM_AUTH_MITM_FLAG | DM_AUTH_BOND_FLAG;
                security_conf.iKeyDist = DM_KEY_DIST_IRK;
                security_conf.rKeyDist = DM_KEY_DIST_LTK | DM_KEY_DIST_IRK;
                security_conf.initiateSec = TRUE;
                security_conf.oob = TRUE;
                security_parameters.ioCap = SMP_IO_DISP_ONLY;
            }
            else if(ble_parameter.permission == SET_ENC_NO_MITM)
            {
                security_conf.auth = DM_AUTH_BOND_FLAG;
                security_conf.iKeyDist = DM_KEY_DIST_IRK;
                security_conf.rKeyDist = DM_KEY_DIST_LTK | DM_KEY_DIST_IRK;
                security_conf.initiateSec = TRUE;
                security_conf.oob = TRUE;
                security_parameters.ioCap = SMP_IO_NO_IN_NO_OUT;
            }
            else
            {
                security_conf.auth = DM_AUTH_BOND_FLAG;
                security_conf.iKeyDist = 0;
                security_conf.rKeyDist = DM_KEY_DIST_LTK;
                security_conf.initiateSec = FALSE;
                security_conf.oob = FALSE;
                security_parameters.ioCap = SMP_IO_NO_IN_NO_OUT;
            }

            ble_queue_reset();

            #ifdef AM_NUS_ADD
            uhal_nus_main_proc_msg(&pMsg->hdr);
            #endif

            #ifdef AM_AMOTA_ADD
            amotas_proc_msg(pMsg);
            #endif
            
            #ifdef AM_CUS_ADD
            uhal_cus_main_proc_msg(&pMsg->hdr);
            #endif

            // FIXME
            // At first conn, notification is not enabled correctly if device is bonded.
            #ifdef AM_NUS_ADD
            if(ble_parameter.permission != SET_OPEN)
                uhal_nus_main_start((dmConnId_t) pMsg->ccc.hdr.param,
                                    1 /* index-1 NUS */);
            #endif

            #ifdef AM_AMOTA_ADD
            // notify enabled
            if(ble_parameter.permission != SET_OPEN)
                amotas_start((dmConnId_t) pMsg->ccc.hdr.param, 
                        BLE_MODULE_AMOTA_RESET_TIMER_IND, 
                        BLE_MODULE_AMOTA_DISCONNECT_TIMER_IND, 
                        2 /* index-2 AMOTAS */);
            #endif

            #ifdef AM_CUS_ADD
            if(ble_parameter.permission != SET_OPEN)
            {
                for(int i=3; i<MAXIMUM_CUS_CHARACTERISTIC_SIZE+3; i++)
                {
                    if(bleModuleCccSet[i].handle != 0)
                    {
                        uhal_cus_main_start((dmConnId_t) pMsg->ccc.hdr.param,
                                    i-3 /* index CUS */);
                    }
                }
            }
            #endif
            // END OF FIXME

            xSemaphoreGive(adv_stop_semaphore);
            xSemaphoreGive(adv_start_semaphore);

            uhal_is_advertising = 0;
            uhal_is_connected = 1;

            if(ble_parameter.permission != SET_OPEN)
            {
                AppHandleNumericComparison(&pMsg->dm.cnfInd);
                AppSlaveSecurityReq((dmConnId_t) pMsg->hdr.param);
            }

            uint8_t msg[] = "Connected.\r\n";
            uhal_uart_write_buffer(0, msg, strlen(msg), 0);
            
            if(CONNECT_HANDLER != NULL )
            {
                if(uhal_mcu_sleep_status() == true)
                {
                    // Resume peripherals...
                    uhal_mcu_resume();

                    CONNECT_HANDLER(); 

                    // Suspend peripherals...
                    uhal_mcu_suspend();
                }
                else
                {
                    CONNECT_HANDLER(); 
                }
            }    

            uiEvent = APP_UI_CONN_OPEN;
            break;

        case DM_CONN_CLOSE_IND:
        {
            xSemaphoreGive(conn_stop_semaphore);

            hciDisconnectCmplEvt_t *evt = (hciDisconnectCmplEvt_t*) pMsg;
            am_log_inf(">>> Connection closed reason 0x%x <<<",
                    evt->reason);
            ble_queue_reset();
            bleModuleClose(pMsg);

            att_mtu = ATT_DEFAULT_MTU - 3;

            uhal_is_advertising = 1;
            uhal_is_connected = 0;

            uint8_t msg[] = "Disconnected.\r\n";
            uhal_uart_write_buffer(0, msg, strlen(msg), 0);

            if(DISCONNECT_HANDLER != NULL)
            {
                if(uhal_mcu_sleep_status() == true)
                {
                    // Resume peripherals...
                    uhal_mcu_resume();

                    DISCONNECT_HANDLER(); 

                    // Suspend peripherals...
                    uhal_mcu_suspend();
                }
                else
                {
                    DISCONNECT_HANDLER(); 
                }
            }
            am_log_inf("%d: %s(): unlock:", __LINE__, __func__);
            uhal_ble_wake_unlock();

            uiEvent = APP_UI_CONN_CLOSE;
        }
        break;

        case DM_CONN_UPDATE_IND:
            am_log_inf("Update");

            #ifdef AM_CUS_ADD
            uhal_cus_main_proc_msg(&pMsg->hdr);
            #endif

            #ifdef AM_NUS_ADD
            uhal_nus_main_proc_msg(&pMsg->hdr);
            #endif

            #ifdef AM_AMOTA_ADD
            amotas_proc_msg(pMsg);
            #endif

        break;

        case DM_PHY_UPDATE_IND:
            am_log_inf("DM_PHY_UPDATE_IND status: %d, RX: %d, TX: %d", pMsg->dm.phyUpdate.status, pMsg->dm.phyUpdate.rxPhy, pMsg->dm.phyUpdate.txPhy);
        break;

        case DM_SEC_PAIR_CMPL_IND:
            am_log_inf("Pair completed.");
            DmSecGenerateEccKeyReq();
            uiEvent = APP_UI_SEC_PAIR_CMPL;
        break;

        case DM_SEC_PAIR_FAIL_IND:
            am_log_inf("Pair failed.");
            DmSecGenerateEccKeyReq();

            // Disconnect...
            AppConnClose((dmConnId_t) pMsg->hdr.param);

            uiEvent = APP_UI_SEC_PAIR_FAIL;
        break;

        case DM_SEC_ENCRYPT_IND:
            am_log_inf("Pair encrypt.");
            uiEvent = APP_UI_SEC_ENCRYPT;
        break;

        case DM_SEC_ENCRYPT_FAIL_IND:
            am_log_inf("Pair encrypt failed.");

             // Disconnect...
            AppConnClose((dmConnId_t) pMsg->hdr.param);

            uiEvent = APP_UI_SEC_ENCRYPT_FAIL;
        break;

        case DM_SEC_AUTH_REQ_IND:
            am_log_inf("Handle passkey.");

            //AppHandlePasskey(&pMsg->dm.authReq);
            
            uint32_t passkey=atoi(ble_parameter.pairing_key);
            uint8_t  buf[SMP_PIN_LEN];

            /* convert to byte buffer */
            buf[0] = UINT32_TO_BYTE0(passkey);
            buf[1] = UINT32_TO_BYTE1(passkey);
            buf[2] = UINT32_TO_BYTE2(passkey);

            /* send authentication response to DM */
            pMsg->hdr.event = SMP_MSG_API_AUTH_RSP;
            DmSecAuthRsp((dmConnId_t) pMsg->hdr.param, SMP_PIN_LEN, buf);

            /* display passkey */
            //AppUiDisplayPasskey(passkey);

        break;

        case DM_SEC_ECC_KEY_IND:
            am_log_inf("ecc_key");

            DmSecSetEccKey(&pMsg->dm.eccMsg.data.key);
          break;

        case DM_SEC_COMPARE_IND:
            am_log_inf("compare");
            AppHandleNumericComparison(&pMsg->dm.cnfInd);
          break;

        case DM_PRIV_CLEAR_RES_LIST_IND:
          am_log_inf("Clear resolving list status 0x%02x", pMsg->hdr.status);
          break;

        case DM_HW_ERROR_IND:
          am_log_inf("DM_HW_ERROR_IND");
          uiEvent = APP_UI_HW_ERROR;
          break;

        case DM_VENDOR_SPEC_CMD_CMPL_IND:
          {
            am_log_inf("DM_VENDOR_SPEC_CMD_CMPL_IND");
            #if defined(AM_PART_APOLLO) || defined(AM_PART_APOLLO2)

              uint8_t *param_ptr = &pMsg->dm.vendorSpecCmdCmpl.param[0];

              switch (pMsg->dm.vendorSpecCmdCmpl.opcode)
              {
                case 0xFC20: //read at address
                {
                  uint32_t read_value;

                  BSTREAM_TO_UINT32(read_value, param_ptr);

                  APP_TRACE_INFO3("VSC 0x%0x complete status %x param %x",
                    pMsg->dm.vendorSpecCmdCmpl.opcode,
                    pMsg->hdr.status,
                    read_value);
                }

                break;
                default:
                    APP_TRACE_INFO2("VSC 0x%0x complete status %x",
                        pMsg->dm.vendorSpecCmdCmpl.opcode,
                        pMsg->hdr.status);
                break;
              }

            #endif
          }
          break;

        #ifdef AM_AMOTA_ADD
        case BLE_MODULE_AMOTA_RESET_TIMER_IND:
        case BLE_MODULE_AMOTA_DISCONNECT_TIMER_IND:
            amotas_proc_msg(pMsg);
            break;
        #endif

        default:
        break;
    }

    if (uiEvent != APP_UI_NONE)
    {
        AppUiAction(uiEvent);
    }
}

/*************************************************************************************************/
/*!
 *  \fn     bleModuleHandlerInit
 *
 *  \brief  Application handler init function called during system initialization.
 *
 *  \param  handlerID  WSF handler ID.
 *
 *  \return None.
 */
/*************************************************************************************************/
void bleModuleHandlerInit(wsfHandlerId_t handlerId)
{
    /* store handler ID */
    bleModuleHandlerId = handlerId;

    /* Set configuration pointers */
    pAppMasterCfg = (appMasterCfg_t *) &scanner_conf;
    pAppSlaveCfg = (appSlaveCfg_t *) &slave_conf;
    pAppAdvCfg = (appAdvCfg_t *) &adv_conf;
    pAppSecCfg = (appSecCfg_t *) &security_conf;
    pAppUpdateCfg = (appUpdateCfg_t *) &connparam_conf;
    //pAppDiscCfg = (appDiscCfg_t *) &disc_conf;
    //pAppCfg = (appCfg_t *) &app_conf;

    /* Set stack configuration pointers */
    pSmpCfg = (smpCfg_t *) &security_parameters;

    /* Initialize application framework */
    AppMasterInit();
    AppSlaveInit();
    AppServerInit();
    AppDiscInit();

    #ifdef AM_NUS_ADD
    /* Initialize NUS service server */
    uhal_nus_main_init(handlerId, (UhalNUSMainCfg_t *) &UhalNUSMainCfg);
    #endif

    #ifdef AM_AMOTA_ADD
    amotas_init(handlerId, (AmotasCfg_t *) &s_sAmotasCfg);
    #endif

    #ifdef AM_CUS_ADD
    /* Initialize NUS service server */
    uhal_cus_main_init(handlerId, (UhalCUSMainCfg_t *) &UhalCUSMainCfg);
    #endif

    /* Set IRK for the local device */
    DmSecSetLocalIrk(localIrk);
}

/*************************************************************************************************/
/*!
 *  \fn     bleModuleHandler
 *
 *  \brief  WSF event handler for application.
 *
 *  \param  event   WSF event mask.
 *  \param  pMsg    WSF message.
 *
 *  \return None.
 */
/*************************************************************************************************/
void bleModuleHandler(wsfEventMask_t event, wsfMsgHdr_t *pMsg)
{
    if (pMsg != NULL)
    {
       //am_log_inf("BLE module got evt %d", pMsg->event);

        /* process ATT messages */
        if (pMsg->event >= ATT_CBACK_START && pMsg->event <= ATT_CBACK_END)
        {
            /* process server-related ATT messages */
            AppServerProcAttMsg(pMsg);
        }
        /* process DM messages */
        else if (pMsg->event >= DM_CBACK_START && pMsg->event <= DM_CBACK_END)
        {
            /* process advertising and connection-related messages */
            AppSlaveProcDmMsg((dmEvt_t *) pMsg);

            /* process security-related messages */
            AppSlaveSecProcDmMsg((dmEvt_t *) pMsg);
        }

        /* perform profile and user interface-related operations */
        bleModuleProcMsg((bleModuleMsg_t *) pMsg);
    }
}

/*************************************************************************************************/
/*!
 *  \fn     bleModuleStart
 *
 *  \brief  Start the application.
 *
 *  \return None.
 */
/*************************************************************************************************/
void bleModuleStart(void)
{
    /* Register for stack callbacks */
    DmRegister(bleModuleDmCback);
    DmConnRegister(DM_CLIENT_ID_APP, bleModuleDmCback);
    AttRegister(bleModuleAttCback);
    AttConnRegister(AppServerConnCback);
    AttsCccRegister(ccc_index, (attsCccSet_t *) bleModuleCccSet, bleModuleCccCback);

    /* Initialize attribute server database */
    SvcCoreGattCbackRegister(GattReadCback, GattWriteCback);
    
    SvcCoreSetDevName(ble_parameter.custom_dev_name, sizeof(ble_parameter.custom_dev_name));
    SvcCoreSetPPCP(connparam_conf.connIntervalMin, connparam_conf.connIntervalMax, 
                    connparam_conf.connLatency, connparam_conf.supTimeout);
    SvcCoreAddGroup();  // Generic Access & Attribute
    //SvcDisAddGroup();   // Device Information Service
    
    #ifdef AM_NUS_ADD
    // Edited by Sercan ERAT -- NUS is always active even in BEACON mode.
    UhalNUSCbackRegister(uhal_nus_main_read_cback, uhal_nus_main_write_cback); // Custom Service
    UhalNUSAddGroup();
    #endif

    #ifdef AM_AMOTA_ADD
    // Amota service init
    SvcAmotasCbackRegister(NULL, amotas_write_cback);
    SvcAmotasAddGroup();
    #endif

    /* Set Service Changed CCCD index. */
    //GattSetSvcChangedIdx(BLE_MODULE_GATT_SC_CCC_IDX);
    //GattSetSvcChangedIdx(BLE_MODULE_UHAL_NUS_CHAR2_CCC_IDX);

    /* Reset the device */
    DmDevReset();
}


//*****************************************************************************
//
// Initialization for the ExactLE stack.
//
//*****************************************************************************
void exactle_stack_init(void)
{
    wsfHandlerId_t handlerId;
    uint16_t       wsfBufMemLen;

    //
    // Set up timers for the WSF scheduler.
    //
    WsfOsInit();
    WsfTimerInit();

    //
    // Initialize a buffer pool for WSF dynamic memory needs.
    //
    wsfBufMemLen = WsfBufInit(sizeof(g_pui32BufMem), 
                              (uint8_t *)g_pui32BufMem, 
                              WSF_BUF_POOLS,
                              g_psPoolDescriptors);

    if (wsfBufMemLen > sizeof(g_pui32BufMem))
    {
        am_log_inf("Memory pool is too small by %d",
                             wsfBufMemLen - sizeof(g_pui32BufMem));
    }

    //
    // Initialize the WSF security service.
    //
    SecInit();
    SecAesInit();
    SecCmacInit();
    SecEccInit();

    //
    // Set up callback functions for the various layers of the ExactLE stack.
    //
    handlerId = WsfOsSetNextHandler(HciHandler);
    HciHandlerInit(handlerId);

    handlerId = WsfOsSetNextHandler(DmHandler);

    DmDevVsInit(0);
    DmAdvInit();
    DmScanInit();
    DmConnInit();
    DmConnSlaveInit();
    DmSecInit();
    DmSecLescInit();
    DmPrivInit();
    DmHandlerInit(handlerId);

    handlerId = WsfOsSetNextHandler(L2cSlaveHandler);
    L2cSlaveHandlerInit(handlerId);
    L2cInit();
    L2cSlaveInit();

    handlerId = WsfOsSetNextHandler(AttHandler);
    AttHandlerInit(handlerId);
    AttsInit();
    AttsIndInit();
    AttcInit();

    handlerId = WsfOsSetNextHandler(SmpHandler);
    SmpHandlerInit(handlerId);
    SmprInit();
    SmprScInit();
    HciSetMaxRxAclLen(251);

    handlerId = WsfOsSetNextHandler(AppHandler);
    AppHandlerInit(handlerId);

    handlerId = WsfOsSetNextHandler(HciDrvHandler);
    HciDrvHandlerInit(handlerId);

    handlerId = WsfOsSetNextHandler(bleModuleHandler);
    bleModuleHandlerInit(handlerId);
}

//*****************************************************************************
//
// Interrupt handler for BLE
//
//*****************************************************************************
void am_ble_isr(void)
{
    #if CFG_SYSVIEW
    SEGGER_SYSVIEW_RecordEnterISR();
    #endif

    HciDrvIntService();

    #if CFG_SYSVIEW
    SEGGER_SYSVIEW_RecordExitISR();
    #endif
}

/*************************************************************************************************/
/*!
 *  \fn     TxPowerCtrlDmCback
 *
 *  \brief  Application DM callback.
 *
 *  \param  pDmEvt  DM callback event
 *
 *  \return None.
 */
/*************************************************************************************************/
static void TxPowerCtrlDmCback(dmEvt_t *pDmEvt)
{
  // do nothing
  am_log_inf("TxPowerCtrlDmCback");
}

//*****************************************************************************
//
// Perform initial setup for the radio task.
//
//*****************************************************************************
void RadioTaskSetup(void)
{
    am_log_inf("RadioTask: setup");

    NVIC_SetPriority(BLE_IRQn, NVIC_configMAX_SYSCALL_INTERRUPT_PRIORITY);
}

//*****************************************************************************
//
// Short Description.
//
//*****************************************************************************
void uhal_ble_apollo3_wait_ble_core(void)
{
    xSemaphoreTake(ble_module_init_semaphore, portMAX_DELAY);
}

void RadioTask(void *pvParameters)
{
    am_log_inf("Starting wicentric trace:");

    //
    // Boot the radio.
    //
    HciDrvRadioBoot(1);

    //
    // Initialize the main ExactLE stack.
    //
    exactle_stack_init();

    // Set MAC address
    uint8_t addr[12];
    uint8_t addr_empty[12] = {0};
    service_nvm_get_ble_mac_from_nvm(addr, sizeof(addr));
    if(memcmp(addr, addr_empty, sizeof(addr)) != 0)
        uhal_ble_set_macaddress(addr);

    //
    // Need to register DM callback for Vendor specific command's event
    //
    DmRegister(TxPowerCtrlDmCback);

    //
    // Start the BLE Module profile.
    //
    bleModuleStart();

    while (1)
    {
        //
        // Calculate the elapsed time from our free-running timer, and update
        // the software timers in the WSF scheduler.
        //
        wsfOsDispatcher();

    }
}

/* ----------------------------------- */
/* ----------------------------------- */
/* ----------------------------------- */
/* ----------------------------------- */
/* ----------------------------------- */
/* ----------------------------------- */
// UHAL_BLE FUNCTIONS //
void uhal_nus_data_handler(uint8_t *p_data, uint16_t length)
{
    uint32_t err_code;
    size_t rx_available = fund_circular_queue_available_get(&BLE_rxq);

    udrv_powersave_in_sleep = false;
    am_log_inf("rx_available.(%d)", rx_available);
    am_log_inf("Received data from BLE NUS.(%d)", length);
   
    if (rx_available >= length)
    {
        #ifndef RUI_BOOTLOADER
        {
            for (int i = 0 ; i < length ; i++) {
                serial_fallback_handler(SERIAL_BLE0, p_data[i]);
            }
        }
        #endif
        fund_circular_queue_in(&BLE_rxq, p_data, length);
    } else {
        am_log_inf("%u available is less than %u received!", rx_available, length);
        #ifndef RUI_BOOTLOADER
        {
            for (int i = 0 ; i < rx_available ; i++) {
                serial_fallback_handler(SERIAL_BLE0, p_data[i]);
            }
        }
        #endif
        fund_circular_queue_in(&BLE_rxq, p_data, rx_available);
    }
    udrv_system_event_produce(&rui_ble_event);
    uhal_mcu_consume_event();
}

size_t uhal_nus_available()
{
    return (size_t) fund_circular_queue_utilization_get(&BLE_rxq);
}

/**@snippet [Handling the data received over BLE] */
int32_t uhal_nus_read(uint8_t *Buffer, int32_t NumberOfBytes)
{
    return (int32_t)fund_circular_queue_out(&BLE_rxq, Buffer, NumberOfBytes);
}

/**@snippet [Handling the data transmission over BLE] */
int32_t uhal_nus_write(uint8_t *pdata, uint16_t length)
{
    #ifdef AM_NUS_ADD
    uint32_t ret;

    uint8_t *p = pdata;
    uint16_t remaining = length, chunk_len = att_mtu;
    do
    {
        if(remaining <= att_mtu)
        {
            ret = uhal_nus_main_send_data(NUS_CHAR2_HDL, p, remaining);
            if(ret == 0)
            {
                p += remaining;
                remaining -= remaining;
            }
        }
        else
        {
            ret = uhal_nus_main_send_data(NUS_CHAR2_HDL, p, chunk_len);
            if(ret == 0)
            {
                p += chunk_len;
                remaining -= chunk_len;
            }
        }

        if(ret == 0)
        {
            if(isInISR())
            {
                BaseType_t xHigherPriorityTaskWoken, xResult;
                xResult = xSemaphoreTakeFromISR(nus_notify_semaphore, &xHigherPriorityTaskWoken);
                if (xResult != pdFAIL)
                    portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
            }    
            else
                xSemaphoreTake(nus_notify_semaphore, (connparam_conf.connIntervalMax)*3);
        }

    } while (ret == 0 && remaining != 0);
    
    if(remaining != 0)
    {
        am_log_inf("sending failed. (%u)", remaining);
        return -UDRV_INTERNAL_ERR;
    }

    am_log_inf("sending completed. (%u)", remaining);
    #endif

    return UDRV_RETURN_OK;
}

void uhal_ble_default_config()
{
    ble_parameter.txpower = DRV_BLE_TX_POWER_0DBM;
    tx_power_level = TX_POWER_LEVEL_0P0_dBm; 
    strncpy(ble_parameter.custom_dev_name, (const uint8_t *)DEVICE_NAME, sizeof(ble_parameter.custom_dev_name));
    ble_parameter.adv_interval = APP_ADV_INTERVAL;
    ble_parameter.adv_mode = DRV_BLE_ADV_MODE_FAST; 
    ble_parameter.service_mode = DRV_BLE_UART_MODE;
}

/**@brief Function for initializing the Peer Manager. */
void uhal_nus_peer_manager_init(void)
{
}

/**@brief Function for the GAP initialization.
 *
 * @details This function will set up all the necessary GAP (Generic Access Profile) parameters of
 *          the device. It also sets the permissions and appearance.
 */
void uhal_gap_params_init(void)
{
}

/**@brief Function for initializing the GATT library. */
void uhal_gatt_init(void)
{
}

/**@brief Function for initializing the Advertising functionality.
 */
#pragma pack(push,1)
typedef struct frame_iBEACON_s{

  uint8_t uuid[16];
  uint8_t major[2];
  uint8_t minor[2];
  uint8_t rssi;
} frame_iBEACON_t;
#pragma pack(pop)
static frame_iBEACON_t frame_iBEACON;

static const uint8_t iBEACON_constant[] = {0x02, 0x01, 0x04, 0x1A, 0xFF, 0x4C, 0x00, 0x02, 0x15};
static bool custom_adv_active = false; 
uint8_t uart_adv[21] = 
{
    0x02,                       // ad field length = 2 bytes
    0x01,                       // ad field type = 0x01 [Flags)
    0x06,                       // flags = 0x04(BLE_GAP_ADV_FLAG_BR_EDR_NOT_SUPPORTED), 0x05(BLE_GAP_ADV_FLAG_BR_EDR_NOT_SUPPORTED & BLE_GAP_ADV_FLAG_LE_LIMITED_DISC_MODE)
                                //         0x06(BLE_GAP_ADV_FLAG_BR_EDR_NOT_SUPPORTED & BLE_GAP_ADV_FLAG_LE_GENERAL_DISC_MODE)

    0x11,                       // length = 17 bytes
    0x07,                       // type = 128-bit UUID
    0x9e,                       
    0xca,
    0xdc,                       
    0x24,
    0x0e,
    0xe5,
    0xa9,
    0xe0,
    0x93,
    0xf3,
    0xa3,
    0xb5,
    0x01,
    0x00,
    0x40,
    0x6e 
};

uint8_t cus_adv[21] = 
{
    0x02,                       // ad field length = 2 bytes
    0x01,                       // ad field type = 0x01 [Flags)
    0x06,                       // flags = 0x04(BLE_GAP_ADV_FLAG_BR_EDR_NOT_SUPPORTED), 0x05(BLE_GAP_ADV_FLAG_BR_EDR_NOT_SUPPORTED & BLE_GAP_ADV_FLAG_LE_LIMITED_DISC_MODE)
                                //         0x06(BLE_GAP_ADV_FLAG_BR_EDR_NOT_SUPPORTED & BLE_GAP_ADV_FLAG_LE_GENERAL_DISC_MODE)

    0x11,                       // length = 17 bytes
    0x07,                       // type = 128-bit UUID
    0x00,                       
    0x00,
    0x00,                       
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00 
};

void uhal_advertising_init(void)
{
    uint32_t err_code;

    uhal_advertising_stop(0);

    if (ble_parameter.service_mode == DRV_BLE_UART_MODE)
    {
        memcpy(&adv_data[0], uart_adv, sizeof(uart_adv));
        adv_data_size = sizeof(uart_adv);
        
        // Get mac address
        // uint8_t test_bdaddress[6];
        // uint8_t *pBda;

        // pBda = HciGetBdAddr();
        // BdaCpy(test_bdaddress, pBda);

        /* set advertising and scan response data for discoverable mode */
        AppAdvSetData(APP_ADV_DATA_DISCOVERABLE, adv_data_size, (uint8_t *) adv_data);
        AppAdvSetData(APP_SCAN_DATA_DISCOVERABLE, scan_data_size, (uint8_t *) scan_data);

        /* set advertising and scan response data for connectable mode */
        AppAdvSetData(APP_ADV_DATA_CONNECTABLE, adv_data_size, (uint8_t *) adv_data);
        AppAdvSetData(APP_SCAN_DATA_CONNECTABLE, scan_data_size, (uint8_t *) scan_data);

        // connectable advertising
        AppSetAdvType(DM_ADV_CONN_UNDIRECT);

        am_log_inf("UART ADV INIT...");
    }
    else if (ble_parameter.service_mode == DRV_BLE_BEACON_MODE)
    {
        if(custom_adv_active == false)
        {
            memcpy(&adv_data[0], iBEACON_constant, sizeof(iBEACON_constant));
            memcpy(&adv_data[sizeof(iBEACON_constant)], &frame_iBEACON, sizeof(frame_iBEACON));
            adv_data_size = sizeof(iBEACON_constant) + sizeof(frame_iBEACON);

            am_log_inf("iBEACON ADV INIT...");
        }

        /* set advertising and scan response data for discoverable mode */
        AppAdvSetData(APP_ADV_DATA_DISCOVERABLE, adv_data_size, (uint8_t *) adv_data);
        AppAdvSetData(APP_SCAN_DATA_DISCOVERABLE, scan_data_size, (uint8_t *) scan_data);

        /* set advertising and scan response data for connectable mode */
        AppAdvSetData(APP_ADV_DATA_CONNECTABLE, adv_data_size, (uint8_t *) adv_data);
        AppAdvSetData(APP_SCAN_DATA_CONNECTABLE, scan_data_size, (uint8_t *) scan_data);

        // non-connectable advertising
        AppSetAdvType(DM_ADV_NONCONN_UNDIRECT);

        am_log_inf("BEACON ADV INIT...");
    }
    else if(ble_parameter.service_mode == DRV_BLE_CUS_MODE)
    {
        memcpy(&cus_adv[5], uhal_cus_base_uuid, sizeof(uhal_cus_base_uuid));
        memcpy(&adv_data[0], cus_adv, sizeof(cus_adv));
        adv_data_size = sizeof(cus_adv);
        
        // Get mac address
        // uint8_t test_bdaddress[6];
        // uint8_t *pBda;

        // pBda = HciGetBdAddr();
        // BdaCpy(test_bdaddress, pBda);

        /* set advertising and scan response data for discoverable mode */
        AppAdvSetData(APP_ADV_DATA_DISCOVERABLE, adv_data_size, (uint8_t *) adv_data);
        AppAdvSetData(APP_SCAN_DATA_DISCOVERABLE, scan_data_size, (uint8_t *) scan_data);

        /* set advertising and scan response data for connectable mode */
        AppAdvSetData(APP_ADV_DATA_CONNECTABLE, adv_data_size, (uint8_t *) adv_data);
        AppAdvSetData(APP_SCAN_DATA_CONNECTABLE, scan_data_size, (uint8_t *) scan_data);

        // connectable advertising
        AppSetAdvType(DM_ADV_CONN_UNDIRECT);

        am_log_inf("CUS ADV INIT...");    
    }
}

/**@brief Function for initializing the Connection Parameters module.
 */
void uhal_conn_params_init(void)
{
}

/**@brief Function for initializing services that will be used by the application.
 */
void uhal_services_init(void)
{
}

/**@brief Function for the SoftDevice initialization.
 *
 * @details This function initializes the SoftDevice and the BLE event interrupt.
 */
void uhal_ble_stack_init(void)
{
    static bool is_ble_stack_initialized = false;

    if(is_ble_stack_initialized == false)
    {
        if(adv_stop_semaphore == NULL)
            adv_stop_semaphore = xSemaphoreCreateBinary();

        if(adv_start_semaphore == NULL)
            adv_start_semaphore = xSemaphoreCreateBinary();

        if(conn_stop_semaphore == NULL)
            conn_stop_semaphore = xSemaphoreCreateBinary();

        if(scan_start_semaphore == NULL)
            scan_start_semaphore = xSemaphoreCreateBinary();

        if(scan_stop_semaphore == NULL)
            scan_stop_semaphore = xSemaphoreCreateBinary();

        if(nus_notify_semaphore == NULL)
            nus_notify_semaphore = xSemaphoreCreateBinary();

        if(ble_module_init_semaphore == NULL)
            ble_module_init_semaphore = xSemaphoreCreateBinary();

        if(Scanner_Queue == NULL)
            Scanner_Queue = xQueueCreate(SCANNER_ITEM_SIZE, sizeof(scanner_data_t));
        
        if(Scanner_Semaphore == NULL)
        {
            Scanner_Semaphore = xSemaphoreCreateBinary();
        }

        if(Scanner_Task == NULL)
        {
          xTaskCreate(
              (TaskFunction_t) scanner_handler,
              "Scanner_Handler",
              configMINIMAL_STACK_SIZE,
              NULL,
              RAK_TASK_PRIO_NORMAL,
              &Scanner_Task
          );
        }

        //
        // Run setup functions.
        //
        RadioTaskSetup();

        //
        // Create the functional tasks
        //
        xTaskCreate(RadioTask, "RadioTask", 512, 0, RAK_TASK_PRIO_HIGH, &radio_task_handle);

        is_ble_stack_initialized = true;
    }
}

/**@brief  Function for stop BLE. */
void uhal_stop_ble(void)
{
    dmConnId_t connId;

    am_log_inf("[STOP SOFTDEVICE!!!]");
    if ((connId = AppConnIsOpen()) != DM_CONN_ID_NONE)
    {
        AppConnClose(connId);
        if(isInISR())
        {
            BaseType_t xHigherPriorityTaskWoken, xResult;
            xSemaphoreTakeFromISR(conn_stop_semaphore, &xHigherPriorityTaskWoken);
            if (xResult != pdFAIL)
                portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }    
        else
            xSemaphoreTake(conn_stop_semaphore, 2000);
        
        // Give processor time to restart advertisement after disconnect.
        uhal_delay_ms(3000);
    }

    uhal_advertising_stop(0);
    ble_queue_reset();
    uhal_is_advertising = 0;
    //uhal_ble_default_config(); //reset to default ble config

    am_log_inf("%d: %s(): unlock all:", __LINE__, __func__);
    uhal_ble_wake_unlock_all();   
}

/**@brief Function for starting advertising. */
int32_t uhal_advertising_start(uint8_t time_out)
{
    uint32_t err_code;

    if(uhal_is_connected == 1)
        return -UDRV_INTERNAL_ERR;

    if (time_out > APP_ADV_TIMEOUT_LIMITED_MAX)
    {
        am_log_inf("Out of APP_ADV_TIMEOUT_LIMITED_MAX");
        return -UDRV_INTERNAL_ERR;
    }
    
    uhal_advertising_stop(0);
    uhal_ble_wake_unlock();

    if (ble_parameter.service_mode == DRV_BLE_UART_MODE)
    {
        am_log_inf("(NUS) Start. (%d)", time_out);

        adv_conf.advDuration[0] = time_out*1000;
        adv_conf.advDuration[1] = 0;
        adv_conf.advDuration[2] = 0;
        adv_conf.advInterval[0] = ble_parameter.adv_interval;
        adv_conf.advInterval[1] = 0;
        adv_conf.advInterval[2] = 0;

        /* start advertising; automatically set connectable/discoverable mode and bondable mode */
        AppSetBondable(TRUE);
        AppAdvStart(APP_MODE_DISCOVERABLE);
    }
    else if (ble_parameter.service_mode == DRV_BLE_BEACON_MODE)
    {
        am_log_inf("(Beacon) Start. (%d)", time_out);

        adv_conf.advDuration[0] = 0; // Never Timeout
        adv_conf.advDuration[1] = 0;
        adv_conf.advDuration[2] = 0;
        if (ble_parameter.adv_interval >= MIN_NON_CONN_ADV_INTERVAL)
            adv_conf.advInterval[0] = ble_parameter.adv_interval;
        else
            adv_conf.advInterval[0] = MIN_NON_CONN_ADV_INTERVAL;
        adv_conf.advInterval[1] = 0;
        adv_conf.advInterval[2] = 0;

        /* start advertising; automatically set connectable/discoverable mode and bondable mode */
        AppAdvStart(APP_MODE_AUTO_INIT);
    }
    else if (ble_parameter.service_mode == DRV_BLE_HID_MODE)
    {
    }
    else if(ble_parameter.service_mode == DRV_BLE_CUS_MODE)
    {
        am_log_inf("(CUS) Start. (%d)", time_out);

        adv_conf.advDuration[0] = time_out*1000;
        adv_conf.advDuration[1] = 0;
        adv_conf.advDuration[2] = 0;
        adv_conf.advInterval[0] = ble_parameter.adv_interval;
        adv_conf.advInterval[1] = 0;
        adv_conf.advInterval[2] = 0;

        /* start advertising; automatically set connectable/discoverable mode and bondable mode */
        AppSetBondable(TRUE);
        AppAdvStart(APP_MODE_DISCOVERABLE);
    }
    if(isInISR())
    {
        BaseType_t xHigherPriorityTaskWoken, xResult;
        xResult = xSemaphoreTakeFromISR(adv_start_semaphore, &xHigherPriorityTaskWoken);
        if (xResult != pdFAIL)
            portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
    }    
    else
        xSemaphoreTake(adv_start_semaphore, 1000);

    uhal_is_advertising = 1;
    return UDRV_RETURN_OK;
}


/** @brief  Function for stop advertising. 
 *  @param[in] temp_processing 
 *    0 : Nothing , for API 
 *    1 : For Flash Write/Erase operation. need to close advertising before operating flash
 *    2 : For Flash Read operation. need to start advertising after operating flash   
*/
int32_t uhal_advertising_stop(uint8_t temp_processing)
{
    if(uhal_is_connected == 1)
        return -UDRV_INTERNAL_ERR;

    if(uhal_is_advertising == 1)
    {
        AppAdvStop();
        if(isInISR())
        {
            BaseType_t xHigherPriorityTaskWoken, xResult;
            xSemaphoreTakeFromISR(adv_stop_semaphore, &xHigherPriorityTaskWoken);
            if (xResult != pdFAIL)
                portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }    
        else
            xSemaphoreTake(adv_stop_semaphore, 1000);
    }

    uhal_is_advertising = 0;
    ble_queue_reset();
    return UDRV_RETURN_OK;
}

/**@brief  Function for set TX Power. */
void uhal_ble_set_txpower(drv_ble_tx_power_t tx_power)
{
    switch (tx_power)
    {
        case DRV_BLE_TX_POWER_8DBM:
        case DRV_BLE_TX_POWER_7DBM:
        case DRV_BLE_TX_POWER_6DBM:
        case DRV_BLE_TX_POWER_5DBM:
        case DRV_BLE_TX_POWER_4DBM:
        case DRV_BLE_TX_POWER_3DBM:
            tx_power_level = TX_POWER_LEVEL_PLUS_3P0_dBm;
            ble_parameter.txpower = DRV_BLE_TX_POWER_3DBM;
            break;
    
        case DRV_BLE_TX_POWER_2DBM:
        case DRV_BLE_TX_POWER_0DBM:
            tx_power_level = TX_POWER_LEVEL_0P0_dBm;
            ble_parameter.txpower = DRV_BLE_TX_POWER_0DBM;
            break;
        
        case DRV_BLE_TX_POWER_NEG4DBM:
        case DRV_BLE_TX_POWER_NEG5DBM:
            tx_power_level = TX_POWER_LEVEL_MINUS_5P0_dBm;
            ble_parameter.txpower = DRV_BLE_TX_POWER_NEG5DBM;
            break;

        case DRV_BLE_TX_POWER_NEG8DBM:
        case DRV_BLE_TX_POWER_NEG10DBM:
        case DRV_BLE_TX_POWER_NEG12DBM:
        case DRV_BLE_TX_POWER_NEG16DBM:
        case DRV_BLE_TX_POWER_NEG20DBM:
        case DRV_BLE_TX_POWER_NEG30DBM:
        case DRV_BLE_TX_POWER_NEG40DBM:
            tx_power_level = TX_POWER_LEVEL_MINUS_10P0_dBm;
            ble_parameter.txpower = DRV_BLE_TX_POWER_NEG10DBM;
            break;

        default:
            break;
    }

    if(uhal_is_advertising)
    {
        uhal_advertising_stop(0);
        
        HciVscSetRfPowerLevelEx(tx_power_level);

        uhal_advertising_init();
        uhal_advertising_start(0);
    }
    else
    {
        HciVscSetRfPowerLevelEx(tx_power_level);
    }
    am_log_inf("TX power is updated: %d", ble_parameter.txpower);
}

/**@brief  Function for get TX Power. */
int32_t uhal_ble_get_txpower()
{
    return ble_parameter.txpower;
}

int32_t uhal_ble_set_device_name(char *device_name, uint8_t device_name_length)
{   
    char set_dev_name[29];
    sprintf(set_dev_name, "%s", device_name); // Maximum device name is 29.

    am_log_inf("Input BLE Set DEVNAME = %s ", set_dev_name);
    am_log_inf("Input BLE Length = %d ", device_name_length);

    scan_data[0] = device_name_length + 1;
    scan_data[1] = DM_ADV_TYPE_LOCAL_NAME;
    memcpy(&scan_data[2], device_name, device_name_length);
    scan_data_size = device_name_length + 2;

    memset(ble_parameter.custom_dev_name, 0, sizeof(ble_parameter.custom_dev_name));
    memcpy(ble_parameter.custom_dev_name, device_name, device_name_length);
    SvcCoreSetDevName(ble_parameter.custom_dev_name, sizeof(ble_parameter.custom_dev_name));
    am_log_inf("BLE Set DEVNAME = %s ", ble_parameter.custom_dev_name);
    
    if(uhal_is_advertising)
    {
        uhal_advertising_stop(0);
        uhal_advertising_init();
        uhal_advertising_start(0);
    }
    else
    {
        uhal_advertising_init();
    }
    
    return UDRV_RETURN_OK;
}

char *uhal_ble_get_device_name()
{
    return ble_parameter.custom_dev_name;
}

int32_t uhal_advertising_status()
{
    return uhal_is_advertising;
}

int32_t uhal_ble_get_macaddress(uint8_t *macaddr)
{
    uint8_t test_bdaddress[BDA_ADDR_LEN];
    uint8_t *pBda;

    pBda = HciGetBdAddr();
    BdaCpy(test_bdaddress, pBda);

    sprintf(macaddr, "%02X%02X%02X%02X%02X%02X",
            test_bdaddress[5], test_bdaddress[4], test_bdaddress[3],
            test_bdaddress[2], test_bdaddress[1], test_bdaddress[0]);

    am_log_inf("Get BLE MAC Address = %s", macaddr);

    return UDRV_RETURN_OK;
}

int32_t uhal_ble_set_macaddress(uint8_t *macaddr)
{
    uint32_t err_code;
    uint8_t addr[6];
    uint8_t *pBda;

    dmConnId_t connId;

    pBda = HciGetBdAddr();
    BdaCpy(addr, pBda);

    int sum = 0;
    for(int i=0;i<6;i++)
    {
        sum = 0;
        if(isdigit(macaddr[i*2]))
            sum += macaddr[i*2] - '0';
        else
            sum += toupper(macaddr[i*2]) - 'A' + 10;
        sum *= 16;
        if(isdigit(macaddr[i*2+1]))
            sum += macaddr[i*2+1] - '0';
        else
            sum += toupper(macaddr[i*2+1]) - 'A' + 10;
        addr[5-i] = sum;
    }

    if(uhal_is_advertising)
    {
        uhal_advertising_stop(0);

        HciVscSetCustom_BDAddr(&addr);
        BdaCpy(hciCoreCb.bdAddr, addr);
        hciCoreResetStart();

        uhal_advertising_init();
        uhal_advertising_start(ble_parameter.adv_timeout);
    }
    else
    {
        HciVscSetCustom_BDAddr(&addr);
        BdaCpy(hciCoreCb.bdAddr, addr);
        hciCoreResetStart();
    }

    am_log_inf("Set BLE MAC Address = %s", macaddr);
    return UDRV_RETURN_OK;
}

int32_t uhal_ble_set_adv_interval(uint32_t adv_interval)
{
    if(ble_parameter.service_mode == DRV_BLE_BEACON_MODE)
    {
        if (adv_interval < MIN_NON_CONN_ADV_INTERVAL || adv_interval > MAX_ADV_INTERVAL)
        {
            /* This value can vary between 100ms to 10.24s). 
             * But, modify to 1000ms ,if too aggressive ,it can affect flash or system operation
            */ 
            am_log_inf("uhal_ble_set_adv_interval fail.");
            return UDRV_INTERNAL_ERR;
        }
    }
    else
    {
        if (adv_interval < MIN_CONN_ADV_INTERVAL || adv_interval > MAX_ADV_INTERVAL)
        {   
            /* This value can vary between 100ms to 10.24s). 
             * But, modify to 1000ms ,if too aggressive ,it can affect flash or system operation
            */ 
            am_log_inf("uhal_ble_set_adv_interval fail.");
            return UDRV_INTERNAL_ERR;
        }
    }

    ble_parameter.adv_interval = (adv_interval / 0.625);
    am_log_inf("uhal_ble_set_adv_interval = %d", ble_parameter.adv_interval);

    if(uhal_is_advertising)
    {
        uhal_advertising_stop(0);
        uhal_advertising_init();
        uhal_advertising_start(0);
    }
    else
    {
        uhal_advertising_init();
    }
    
    return UDRV_RETURN_OK;

}

int32_t uhal_ble_get_adv_interval()
{
    am_log_inf("uhal_ble_get_adv_interval = %d", ble_parameter.adv_interval);
    return (ble_parameter.adv_interval * 0.625);
}

void uhal_ble_set_adv_slow_mode(uint8_t adv_mode)
{
    if (adv_mode)
    {
        ble_parameter.adv_mode = DRV_BLE_ADV_MODE_SLOW;
    }
    else
    {
        ble_parameter.adv_mode = DRV_BLE_ADV_MODE_FAST;
    }
}

uint8_t uhal_ble_get_adv_slow_mode()
{
    if (ble_parameter.adv_mode == DRV_BLE_ADV_MODE_SLOW)
        return true;
    else
        return false;
}

void uhal_ble_set_adv_fast_mode(uint8_t adv_mode)
{
    if (adv_mode)
    {
        ble_parameter.adv_mode = DRV_BLE_ADV_MODE_FAST;
    }
    else
    {
        ble_parameter.adv_mode = DRV_BLE_ADV_MODE_SLOW;
    }
}

uint8_t uhal_ble_get_adv_fast_mode()
{
    if (ble_parameter.adv_mode == DRV_BLE_ADV_MODE_FAST)
        return true;
    else
        return false;
}

void uhal_ble_switch_service_mode(drv_ble_service_mode service_mode)
{
    am_log_inf("uhal_ble_switch_service_mode : %d", service_mode);
    ble_parameter.service_mode = (drv_ble_service_mode)service_mode;

    custom_adv_active = false;
}

int32_t uhal_ble_set_beacon_major(uint16_t major_value)
{
    if (ble_parameter.service_mode != DRV_BLE_BEACON_MODE)
    {
        am_log_inf("ble_parameter.service_mode : %d", ble_parameter.service_mode);
        return -UDRV_INTERNAL_ERR;
    }

    frame_iBEACON.major[0] = (uint8_t) (major_value>>8);
    frame_iBEACON.major[1] = (uint8_t) (major_value);

    if(uhal_is_advertising)
    {
        uhal_advertising_stop(0);
        uhal_advertising_init();
        uhal_advertising_start(0);
    }
    else
    {
        uhal_advertising_init();
    }

    am_log_inf("Major value is updated: %d", major_value);

    return UDRV_RETURN_OK;
}
int32_t uhal_ble_set_beacon_minor(uint16_t minor_value)
{
    if (ble_parameter.service_mode != DRV_BLE_BEACON_MODE)
    {
        am_log_inf("ble_parameter.service_mode : %d", ble_parameter.service_mode);
        return -UDRV_INTERNAL_ERR;
    }

    frame_iBEACON.minor[0] = (uint8_t) (minor_value>>8);
    frame_iBEACON.minor[1] = (uint8_t) (minor_value);

    if(uhal_is_advertising)
    {
        uhal_advertising_stop(0);
        uhal_advertising_init();
        uhal_advertising_start(0);
    }
    else
    {
        uhal_advertising_init();
    }

    am_log_inf("Minor value is updated: %d", minor_value);

    return UDRV_RETURN_OK;
}

int32_t uhal_ble_set_beacon_power(int8_t beacon_power)
{
    if (ble_parameter.service_mode != DRV_BLE_BEACON_MODE)
    {
        am_log_inf("ble_parameter.service_mode : %d", ble_parameter.service_mode);
        return -UDRV_INTERNAL_ERR;
    }

    if(beacon_power < -128 || beacon_power > 0)
    {
        am_log_inf("Input Beacon Power(RSSI) out of rang. The value must be between 0 ~ -128");
        return -UDRV_INTERNAL_ERR;
    }

    frame_iBEACON.rssi = beacon_power;

    if(uhal_is_advertising)
    {
        uhal_advertising_stop(0);
        uhal_advertising_init();
        uhal_advertising_start(0);
    }
    else
    {
        uhal_advertising_init();
    }

    am_log_inf("Beacon power value is updated: %d", beacon_power);

    return UDRV_RETURN_OK;
}


int32_t uhal_ble_set_beacon_uuid(uint8_t beaconUuid[])
{
    if (ble_parameter.service_mode != DRV_BLE_BEACON_MODE)
    {
        am_log_inf("ble_parameter.service_mode : %d", ble_parameter.service_mode);
        return -UDRV_INTERNAL_ERR;
    }

    memcpy(frame_iBEACON.uuid, beaconUuid, sizeof(frame_iBEACON.uuid));

    if(uhal_is_advertising)
    {
        uhal_advertising_stop(0);
        uhal_advertising_init();
        uhal_advertising_start(0);
    }
    else
    {
        uhal_advertising_init();
    }

    am_log_inf("UUID is updated.");

    return UDRV_RETURN_OK;
}

int32_t uhal_ble_set_beacon_custom_payload(uint8_t cus_adv_data[], uint8_t cus_adv_len)
{
    uint32_t err_code = 0;
    if (ble_parameter.service_mode != DRV_BLE_BEACON_MODE)
    {
        am_log_inf("ble_parameter.service_mode : %d", ble_parameter.service_mode);
        return -UDRV_INTERNAL_ERR;
    }

    if(cus_adv_len > 31)
    {
        am_log_inf("BLE advertisements can only contain up to 31 bytes of data in their payload.");
        return -UDRV_INTERNAL_ERR;
    }

    custom_adv_active = true;
    
    memcpy(adv_data, cus_adv_data, cus_adv_len);
    adv_data_size = cus_adv_len;
    
    if(uhal_is_advertising)
    {
        uhal_advertising_stop(0);
        uhal_advertising_init();
        uhal_advertising_start(0);
    }
    else
    {
        uhal_advertising_init();
    }

    return UDRV_RETURN_OK;
}

int32_t uhal_ble_set_scan_interval_window(uint16_t scan_interval, uint16_t scan_window)
{
    if (scan_interval < BLE_GAP_SCAN_INTERVAL_MS_MIN || scan_interval > BLE_GAP_SCAN_INTERVAL_MS_MAX)
    {
        /* This value can vary between 3ms to 40.96s). */
        am_log_inf("uhal_ble_set_scan_interval fail.");
        return -UDRV_INTERNAL_ERR;
    }
    else if(scan_window < BLE_GAP_SCAN_WINDOW_MS_MIN || scan_window > BLE_GAP_SCAN_WINDOW_MS_MAX)
    {
        /* This value can vary between 3ms to 40.96s). */
        am_log_inf("uhal_ble_set_scan_window fail.");
        return -UDRV_INTERNAL_ERR;
    }

    scanner_conf.scanInterval = (scan_interval / 0.625);
    scanner_conf.scanWindow = (scan_window / 0.625);
    
    am_log_inf("(BLE Scan) interval = %d", scanner_conf.scanInterval);
    am_log_inf("(BLE Scan) window = %d", scanner_conf.scanWindow);

    if(uhal_is_scanning)
    {
        DmScanStop();

        if(isInISR())
        {
            BaseType_t xHigherPriorityTaskWoken, xResult;
            xSemaphoreTakeFromISR(scan_stop_semaphore, &xHigherPriorityTaskWoken);
            if (xResult != pdFAIL)
                portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }    
        else
            xSemaphoreTake(scan_stop_semaphore, 1000);

        DmScanSetInterval(HCI_SCAN_PHY_LE_1M_BIT, &(scanner_conf.scanInterval), &(scanner_conf.scanWindow));
        DmScanStart(HCI_SCAN_PHY_LE_1M_BIT, scanner_conf.discMode, &(scanner_conf.scanType), FALSE, scanner_conf.scanDuration, 0);

        if(isInISR())
        {
            BaseType_t xHigherPriorityTaskWoken, xResult;
            xSemaphoreTakeFromISR(scan_start_semaphore, &xHigherPriorityTaskWoken);
            if (xResult != pdFAIL)
                portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }    
        else
            xSemaphoreTake(scan_start_semaphore, 1000);        
    }

    return UDRV_RETURN_OK;
}

void uhal_ble_scan_start(uint16_t scan_sec)
{
    if(uhal_is_advertising)
    {
        uhal_advertising_stop(0);
    }

    am_log_inf("(BLE Scan) Start (sec): %d", scan_sec);
    scanner_conf.scanDuration = (scan_sec * 1000);

    DmScanSetInterval(HCI_SCAN_PHY_LE_1M_BIT, &(scanner_conf.scanInterval), &(scanner_conf.scanWindow));
    DmScanStart(HCI_SCAN_PHY_LE_1M_BIT, scanner_conf.discMode, &(scanner_conf.scanType), FALSE, scanner_conf.scanDuration, 0);

    if(isInISR())
    {
        BaseType_t xHigherPriorityTaskWoken, xResult;
        xSemaphoreTakeFromISR(scan_start_semaphore, &xHigherPriorityTaskWoken);
        if (xResult != pdFAIL)
            portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
    }    
    else
        xSemaphoreTake(scan_start_semaphore, 1000);
}

void uhal_scan_init(bool connect_if_match)
{
    //TODO
}
void uhal_ble_scan_stop(void)
{
    //TODO
}
int32_t uhal_nus_set_keypairing(uint8_t *pairing_key, uint8_t key_length)
{
    uint32_t err_code = 0;
    
    if(key_length != 6 /*BLE_GAP_PASSKEY_LEN*/)
    {
        am_log_inf("uhal_nus_set_keypairing Out of Range(encryption key size define is 6).");
        err_code = UDRV_INTERNAL_ERR;
    }
    

    am_log_inf("uhal_nus_set_keypairing - key length: %d",strlen(pairing_key));
    //memccpy(ble_parameter.pairing_key, pairing_key, key_length - 1);
    strncpy(ble_parameter.pairing_key, pairing_key, /*BLE_GAP_PASSKEY_LEN*/ 6);
    //ble_parameter.pairing_key = pairing_key
    ble_parameter.pairing_key[/*BLE_GAP_PASSKEY_LEN*/ 6] = 0x00;
    am_log_inf("(NUS)uhal_nus_set_keypairing :%02X%02X%02X%02X%02X%02X", ble_parameter.pairing_key[0], 
                                                                        ble_parameter.pairing_key[1],
                                                                        ble_parameter.pairing_key[2],
                                                                        ble_parameter.pairing_key[3],
                                                                        ble_parameter.pairing_key[4],
                                                                        ble_parameter.pairing_key[5]);
    switch (err_code)
    {
        case 0:
            return UDRV_RETURN_OK;
        default:
            return -UDRV_INTERNAL_ERR;
    }
}

int32_t uhal_nus_set_permission(uint8_t permission)
{
    uint32_t err_code = 0;

    if(permission == SET_ENC_WITH_MITM)
    {
        ble_parameter.permission = permission;
        am_log_inf("uhal_nus_set_permission = %d", permission);

        security_conf.auth = DM_AUTH_MITM_FLAG | DM_AUTH_BOND_FLAG;
        security_conf.iKeyDist = DM_KEY_DIST_IRK;
        security_conf.rKeyDist = DM_KEY_DIST_LTK | DM_KEY_DIST_IRK;
        security_conf.initiateSec = TRUE;
        security_conf.oob = TRUE;
        security_parameters.ioCap = SMP_IO_DISP_ONLY;
    }
    else if(permission == SET_ENC_NO_MITM)
    {
        ble_parameter.permission = permission;
        am_log_inf("uhal_nus_set_permission = %d", permission);

        security_conf.auth = DM_AUTH_BOND_FLAG;
        security_conf.iKeyDist = DM_KEY_DIST_IRK;
        security_conf.rKeyDist = DM_KEY_DIST_LTK | DM_KEY_DIST_IRK;
        security_conf.initiateSec = TRUE;
        security_conf.oob = TRUE;
        security_parameters.ioCap = SMP_IO_NO_IN_NO_OUT;
    }
    else if(permission == SET_OPEN)
    {
        ble_parameter.permission = permission;
        am_log_inf("uhal_nus_set_permission = %d", permission);

        security_conf.auth = DM_AUTH_BOND_FLAG;
        security_conf.iKeyDist = 0;
        security_conf.rKeyDist = DM_KEY_DIST_LTK;
        security_conf.initiateSec = FALSE;
        security_conf.oob = FALSE;
        security_parameters.ioCap = SMP_IO_NO_IN_NO_OUT;
    }
    else
    {
        am_log_inf("permission Out of Range(permission only support SET_ENC_NO_MITM or SET_ENC_WITH_MITM).");
        err_code = UDRV_INTERNAL_ERR;
    }
    
    
    switch (err_code)
    {
        case 0:
            return UDRV_RETURN_OK;
        default:
            return -UDRV_INTERNAL_ERR;
    }
}

void uhal_ble_serial_init (SERIAL_PORT Port, uint32_t BaudRate, SERIAL_WORD_LEN_E DataBits, SERIAL_STOP_BIT_E StopBits, SERIAL_PARITY_E Parity, SERIAL_WIRE_MODE_E WireMode) {
    return;
}

void uhal_ble_serial_deinit (SERIAL_PORT Port) {
    return;
}

int32_t uhal_ble_serial_write (SERIAL_PORT Port, uint8_t const *Buffer, int32_t NumberOfBytes, uint32_t Timeout) {
    return uhal_nus_write(Buffer, NumberOfBytes);
}

int32_t uhal_ble_serial_read (SERIAL_PORT Port, uint8_t *Buffer, int32_t NumberOfBytes, uint32_t Timeout) {
    return uhal_nus_read(Buffer, NumberOfBytes);
}

int32_t uhal_ble_serial_peek (SERIAL_PORT Port) {
    // uint8_t ch;

    // if (nrf_queue_generic_pop (&ble_rxq, &ch, true) == NRF_SUCCESS) {
    //     return (int32_t)ch;
    // } else {
        return -UDRV_INTERNAL_ERR;
    // }
}

void uhal_ble_serial_flush (SERIAL_PORT Port, uint32_t Timeout) {
    return;
}

size_t uhal_ble_serial_read_available (SERIAL_PORT Port) {
    return (size_t)uhal_nus_available();
}

uint32_t uhal_ble_hci_write(uint8_t *raw_data,uint8_t len)
{
    am_hal_ble_buffer(16) sWriteCommand;
    am_hal_ble_state_t *pBLE = BLE;
    char hex[2];
    for(int i=0;i<len/2;i++)
    {
        memcpy(hex,raw_data+i*2,2);
        sWriteCommand.bytes[i] = strtol(hex,NULL,16);;
    }


    am_hal_ble_sleep_set(pBLE, false);
    uint32_t ui32Module = pBLE->ui32Module;
    ui32IntEnable = BLEIFn(ui32Module)->INTEN;
    BLEIFn(ui32Module)->INTEN = 0;
    am_hal_ble_blocking_hci_write(pBLE,
                                  AM_HAL_BLE_RAW,
                                  sWriteCommand.words,
                                  7);
    BLEIFn(ui32Module)->BLEDBG_b.IOCLKON = 1;
}
int32_t uhal_ble_hci_read(uint8_t *recv,uint32_t *recv_bytes)
{
    am_hal_ble_buffer(256) sResponse;
    am_hal_ble_state_t *pBLE = BLE;
    uint32_t ui32Module = pBLE->ui32Module;
    uint32_t ui32ErrorStatus;
    for (uint32_t i = 0; i < 100; i++)
    {
        if (BLEIFn(ui32Module)->BSTATUS_b.BLEIRQ != 0)
        {
            break;
        }
        else if (i == (100 - 1))
        {
            return AM_HAL_BLE_NO_HCI_RESPONSE;
        }
        else
        {
            am_util_delay_ms(1);
        }
    }

    ui32ErrorStatus = am_hal_ble_blocking_hci_read(pBLE, sResponse.words, recv_bytes);
    if (ui32ErrorStatus != AM_HAL_STATUS_SUCCESS)
        return -UDRV_INTERNAL_ERR;
    memcpy(recv,sResponse.bytes,*recv_bytes);
    //
    // Re-enable BLE interrupts.
    //
    BLEIFn(ui32Module)->INTCLR = ui32IntEnable;
    BLEIFn(ui32Module)->INTEN = ui32IntEnable;
    return UDRV_RETURN_OK;
}
void uhal_ble_set_dtm_txpower(int tx_power)
{
    HciVscSetRfPowerLevelEx(tx_power);
}

#endif
