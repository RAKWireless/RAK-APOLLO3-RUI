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
#ifndef UHAL_NUS_MAIN_H__
#define UHAL_NUS_MAIN_H__

#include "wsf_timer.h"
#include "att_api.h"

#ifdef __cplusplus
extern "C"
{
#endif

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
} UhalNUSMainCfg_t;

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

void uhal_nus_main_init(wsfHandlerId_t handlerId, UhalNUSMainCfg_t *pCfg);

void uhal_nus_main_proc_msg(wsfMsgHdr_t *pMsg);

uint8_t uhal_nus_main_write_cback(dmConnId_t connId, uint16_t handle, uint8_t operation,
                                    uint16_t offset, uint16_t len, uint8_t *pValue, attsAttr_t *pAttr);

uint8_t uhal_nus_main_read_cback(dmConnId_t connId, uint16_t handle, uint8_t operation,
                                   uint16_t offset, attsAttr_t *pAttr);

void uhal_nus_main_start(dmConnId_t connId, uint8_t NUSCccIdx);

void uhal_nus_main_stop(dmConnId_t connId);

uint32_t uhal_nus_main_send_data(uint16_t handle, uint8_t *buf, uint16_t len);

extern void uhal_nus_main_conn_close(dmConnId_t connId);

#ifdef __cplusplus
}
#endif

#endif // UHAL_NUS_MAIN_H__
