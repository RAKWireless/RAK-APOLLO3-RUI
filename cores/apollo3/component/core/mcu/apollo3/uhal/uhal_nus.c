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
#include "wsf_types.h"
#include "att_api.h"
#include "wsf_trace.h"
#include "bstream.h"
#include "svc_ch.h"
#include "svc_cfg.h"
#include "uhal_nus.h"

//*****************************************************************************
//
// Macro definitions
//
//*****************************************************************************

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************

/**************************************************************************************************
 Static Variables
**************************************************************************************************/
/* UUIDs */
static const uint8_t uhal_nus_char1_uuid[] = {ATT_UUID_NUS_CHAR1};
static const uint8_t uhal_nus_char2_uuid[] = {ATT_UUID_NUS_CHAR2};

/**************************************************************************************************
 Service variables
**************************************************************************************************/

/* NUS service declaration */
static const uint8_t  uhal_nus[] = {ATT_UUID_NUS_SERVICE};
static const uint16_t uhal_nus_len = sizeof(uhal_nus);

/* NUS service characteristic 1 */
static const uint8_t  uhal_nus_char1[] = {/*ATT_PROP_READ |*/ ATT_PROP_WRITE | ATT_PROP_WRITE_NO_RSP, 
                                           UINT16_TO_BYTES(NUS_CHAR1_HDL), 
                                           ATT_UUID_NUS_CHAR1};
static const uint16_t uhal_nus_char1_len = sizeof(uhal_nus_char1);

/* NUS service characteristic 2 */
static const uint8_t  uhal_nus_char2[] = {/*ATT_PROP_READ | ATT_PROP_WRITE_NO_RSP |*/ ATT_PROP_NOTIFY, 
                                           UINT16_TO_BYTES(NUS_CHAR2_HDL), 
                                           ATT_UUID_NUS_CHAR2};
static const uint16_t uhal_nus_char2_len = sizeof(uhal_nus_char2);



/* NUS service characteristic 1 data */
static uint8_t  uhal_nus_char1_data[] = {'R', 'A', 'K', '-', 'R', 'X'};
static uint16_t uhal_nus_char1_data_len = sizeof(uhal_nus_char1_data);
/* ---- */

/* NUS service characteristic 2 data */
static uint8_t  uhal_nus_char2_data[] = {'R', 'A', 'K', '-', 'T', 'X'};
static uint16_t uhal_nus_char2_data_len = sizeof(uhal_nus_char2_data);

/* Proprietary data client characteristic configuration */
static uint8_t uhal_nus_char2_ccc[] = {UINT16_TO_BYTES(0x0000)};
static const uint16_t uhal_nus_char2_ccc_len = sizeof(uhal_nus_char2_ccc);
/* ---- */


/* Attribute list for NUS service group */
static const attsAttr_t uhal_nus_list[] =
{
  // Service Declaration
  {
    attPrimSvcUuid,
    (uint8_t *) uhal_nus,
    (uint16_t *) &uhal_nus_len,
    sizeof(uhal_nus),
    0,
    ATTS_PERMIT_READ
  },
  /*-----*/
  // Characteristic 1 Declaration
  {
    attChUuid,
    (uint8_t *) uhal_nus_char1,
    (uint16_t *) &uhal_nus_char1_len,
    sizeof(uhal_nus_char1),
    0,
    (ATTS_PERMIT_READ)
  },
  // Characteristic 1 Value
  {
    uhal_nus_char1_uuid,
    0, //(uint8_t *) uhal_nus_char1_data,
    0, //(uint16_t *) &uhal_nus_char1_data_len,
    ATT_VALUE_MAX_LEN,
    (ATTS_SET_UUID_128 | ATTS_SET_VARIABLE_LEN | ATTS_SET_WRITE_CBACK /*| ATTS_SET_READ_CBACK*/), // ----
    (ATTS_PERMIT_WRITE) // -----
  },
  /*-----*/
  // Characteristic 2 Declaration
  {
    attChUuid,
    (uint8_t *) uhal_nus_char2,
    (uint16_t *) &uhal_nus_char2_len,
    sizeof(uhal_nus_char2),
    0,
    ATTS_PERMIT_READ
  },
  // Characteristic 2 Value
  {
    uhal_nus_char2_uuid,
    0, /*(uint8_t *) uhal_nus_char2_data,*/
    0, /*(uint16_t *) &uhal_nus_char2_data_len,*/
    ATT_VALUE_MAX_LEN,
    (ATTS_SET_UUID_128 | ATTS_SET_VARIABLE_LEN /*| ATTS_SET_WRITE_CBACK | ATTS_SET_READ_CBACK*/), // ---
    (ATTS_PERMIT_READ | ATTS_PERMIT_WRITE)// ---
  },
  // Characteristic 2 Notify
  {
    attCliChCfgUuid,
    (uint8_t *) uhal_nus_char2_ccc,
    (uint16_t *) &uhal_nus_char2_ccc_len,
    sizeof(uhal_nus_char2_ccc),
    ATTS_SET_CCC,
    (ATTS_PERMIT_READ | ATTS_PERMIT_WRITE)
  }
  /*----*/
};

/* NUS service group structure */
static attsGroup_t uhal_nus_group =
{
  NULL,
  (attsAttr_t *) uhal_nus_list,
  NULL,
  NULL,
  NUS_SERVICE_START_HDL,
  NUS_SERVICE_END_HDL
};

/*************************************************************************************************/
/*!
 *  \fn     UhalNUSAddGroup
 *
 *  \brief  Add the services to the attribute server.
 *
 *  \return None.
 */
/*************************************************************************************************/
void UhalNUSAddGroup(void)
{
  AttsAddGroup(&uhal_nus_group);
}

/*************************************************************************************************/
/*!
 *  \fn     UhalNUSRemoveGroup
 *
 *  \brief  Remove the services from the attribute server.
 *
 *  \return None.
 */
/*************************************************************************************************/
void UhalNUSRemoveGroup(void)
{
  AttsRemoveGroup(NUS_SERVICE_START_HDL);
}

/*************************************************************************************************/
/*!
 *  \fn     UhalNUSCbackRegister
 *
 *  \brief  Register callbacks for the service.
 *
 *  \param  readCback   Read callback function.
 *  \param  writeCback  Write callback function.
 *
 *  \return None.
 */
/*************************************************************************************************/
void UhalNUSCbackRegister(attsReadCback_t readCback, attsWriteCback_t writeCback)
{
  uhal_nus_group.readCback = readCback;
  uhal_nus_group.writeCback = writeCback;
}
