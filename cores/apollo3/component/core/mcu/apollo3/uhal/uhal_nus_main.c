//*****************************************************************************
//
// Copyright (c) 2021, Ambiq Micro, Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
// contributors may be used to endorse or promote products derived from this
// software without specific prior written permission.
//
// Third party software included in this distribution is subject to the
// additional license terms as defined in the /docs/licenses directory.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// This is part of revision release_sdk_3_0_0-742e5ac27c of the AmbiqSuite Development Package.
//
//*****************************************************************************
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "wsf_types.h"
#include "wsf_assert.h"
#include "wsf_trace.h"
#include "bstream.h"
#include "att_api.h"
#include "svc_ch.h"
#include "app_api.h"
#include "app_hw.h"
#include "am_util_debug.h"
#include "crc32.h"

#include "am_mcu_apollo.h"
#include "am_bsp.h"
#include "am_util.h"
#include "am_log.h"

#include "uhal_nus.h"
#include "uhal_nus_main.h"
#include "uhal_ble.h"

#if defined(AM_PART_APOLLO4B)
#include "am_hal_security.h"
#endif


//*****************************************************************************
//
// Macro definitions
//
//*****************************************************************************

//
// Connection control block
//
typedef struct
{
    dmConnId_t    connId;               // Connection ID
    bool_t        bleModuleToSend;      // bleModule notify ready to be sent on this channel
}
svcNUSMainConn_t;

/* Control block */
static struct
{
    UhalNUSMainCfg_t        cfg;                  // configurable parameters

    svcNUSMainConn_t        conn[DM_CONN_MAX];    // connection control block
    wsfHandlerId_t          appHandlerId;
}
svcNUSMainCb;

//*****************************************************************************
//
// Connection Open event
//
//*****************************************************************************
static void uhal_nus_main_conn_open(dmEvt_t *pMsg)
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
static void uhal_nus_main_conn_update(dmEvt_t *pMsg)
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
// Find Next Connection to Send on
//
//*****************************************************************************
static svcNUSMainConn_t* uhal_nus_main_find_next2send(void)
{
    svcNUSMainConn_t *pConn = svcNUSMainCb.conn;
    uint8_t i;

    for (i = 0; i < DM_CONN_MAX; i++, pConn++)
    {
        if (pConn->connId != DM_CONN_ID_NONE && pConn->bleModuleToSend)
        {
            //if (AttsCccEnabled(pConn->connId, cccIdx))
            return pConn;
        }
    }
    return NULL;
}

//*****************************************************************************
//
// Send Notification to Client
//
//*****************************************************************************
uint32_t uhal_nus_main_send_data(uint16_t handle, uint8_t *buf, uint16_t len)
{
    svcNUSMainConn_t *pConn = uhal_nus_main_find_next2send();
    
    /* send notification */
    if ( pConn )
    {
        am_log_inf("Send to connId = %d", pConn->connId);
        AttsHandleValueNtf(pConn->connId, handle, len, buf);
        return 0;
    }
    else
    {
        //am_log_inf("Invalid Conn");
        return -1;
    }
}

//*****************************************************************************
//
//! @brief initialize nus service
//!
//! @param handlerId - connection handle
//! @param pCfg - configuration parameters
//!
//! @return None
//
//*****************************************************************************
void uhal_nus_main_init(wsfHandlerId_t handlerId, UhalNUSMainCfg_t *pCfg)
{
    memset(&svcNUSMainCb, 0, sizeof(svcNUSMainCb));
    svcNUSMainCb.appHandlerId = handlerId;
    for (int i = 0; i < DM_CONN_MAX; i++)
    {
        svcNUSMainCb.conn[i].connId = DM_CONN_ID_NONE;
        svcNUSMainCb.conn[i].bleModuleToSend = FALSE;
    }
}

void uhal_nus_main_conn_close(dmConnId_t connId)
{
    /* clear connection */
    svcNUSMainCb.conn[connId - 1].connId = DM_CONN_ID_NONE;
    svcNUSMainCb.conn[connId - 1].bleModuleToSend = FALSE;
}

uint8_t uhal_nus_main_write_cback(dmConnId_t connId, uint16_t handle, uint8_t operation,
                   uint16_t offset, uint16_t len, uint8_t *pValue, attsAttr_t *pAttr)
{
    am_log_inf("[%s]", __func__);
    //am_log_inf("connId           = 0x%02X", connId);
    //am_log_inf("handle           = 0x%02X", handle);
    //am_log_inf("operation        = 0x%02X", operation);
    //am_log_inf("offset           = 0x%04X", offset);
    //am_log_inf("len              = 0x%04X", len);

    if(handle == NUS_CHAR1_HDL)
      am_log_inf("Char1 Write CB");
    if(handle == NUS_CHAR2_HDL)
      am_log_inf("Char2 Write CB");

    //AttsSetAttr(handle, len, pValue);  // Update Attribute table (read caharacteristic)
    uhal_nus_data_handler(pValue, len);

    return ATT_SUCCESS;
}

uint8_t uhal_nus_main_read_cback(dmConnId_t connId, uint16_t handle, uint8_t operation,
                                   uint16_t offset, attsAttr_t *pAttr)
{
    static uint8_t s_readcnt = 0x00;

    am_log_inf("[%s]", __func__);
    //am_log_inf("connId            = 0x%02X", connId);
    //am_log_inf("handle            = 0x%02X", handle);
    //am_log_inf("operation         = 0x%02X", operation);
    //am_log_inf("offset            = 0x%04X", offset);
    //am_log_inf("attsAttr_t.pLen   = 0x%04X", *pAttr->pLen);
    //am_log_inf("attsAttr_t.pValue = 0x%04X", *pAttr->pValue);

    if(handle == NUS_CHAR1_HDL)
      am_log_inf("Char1 Read CB");
    if(handle == NUS_CHAR2_HDL)
      am_log_inf("Char2 Read CB");
  
    AttsSetAttr(handle, *pAttr->pLen, pAttr->pValue);

    return ATT_SUCCESS;
}

void uhal_nus_main_start(dmConnId_t connId, uint8_t NUSCccIdx)
{
    //
    // set conn id
    //
    svcNUSMainCb.conn[connId - 1].connId = connId;
    svcNUSMainCb.conn[connId - 1].bleModuleToSend = TRUE;
}

void uhal_nus_main_stop(dmConnId_t connId)
{
    //
    // clear connection
    //
    svcNUSMainCb.conn[connId - 1].connId = DM_CONN_ID_NONE;
    svcNUSMainCb.conn[connId - 1].bleModuleToSend = FALSE;
}

//*****************************************************************************
//
//! @brief initialize nus service
//!
//! @param pMsg - WSF message
//!
//! @return None
//
//*****************************************************************************
void uhal_nus_main_proc_msg(wsfMsgHdr_t *pMsg)
{
    if (pMsg->event == DM_CONN_OPEN_IND)
    {
        uhal_nus_main_conn_open((dmEvt_t *) pMsg);
    }
    else if (pMsg->event == DM_CONN_UPDATE_IND)
    {
        uhal_nus_main_conn_update((dmEvt_t *) pMsg);
    }
}
