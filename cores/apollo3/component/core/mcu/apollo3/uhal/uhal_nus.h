#ifndef UHAL_NUS_H__
#define UHAL_NUS_H__

//
// Put additional includes here if necessary.
//

#ifdef __cplusplus
extern "C"
{
#endif

#include "att_api.h"
#include "wsf_types.h"

//*****************************************************************************
//
// Macro definitions
//
//*****************************************************************************

//0x6E, 0x40, 0x00, 0x01, 
//0xB5, 0xA3, 0xF3, 0x93, 
//0xE0, 0xA9, 0xE5, 0x0E, 
//0x24, 0xDC, 0xCA, 0x9E

/*! Macro for building Ambiq UUIDs */
#define ATT_UUID_NUS_BUILD(part)         0x9E, 0xCA, 0xDC, 0x24, \
                                         0x0E, 0xE5, 0xA9, 0xE0, \
                                         0x93, 0xF3, 0xA3, 0xB5, \
                                         UINT16_TO_BYTES(part), 0x40, 0x6E \

/*! Partial NUS service UUIDs */
#define ATT_UUID_NUS_SERVICE_PART        0x0001

/*! Partial NUS characteristic 1 UUIDs */
#define ATT_UUID_NUS_CHAR1_PART          0x0002

/*! Partial NUS characteristic 2 UUIDs */
#define ATT_UUID_NUS_CHAR2_PART          0x0003

/* NUS service */
#define ATT_UUID_NUS_SERVICE          ATT_UUID_NUS_BUILD(ATT_UUID_NUS_SERVICE_PART)

/* NUS characteristics */
#define ATT_UUID_NUS_CHAR1            ATT_UUID_NUS_BUILD(ATT_UUID_NUS_CHAR1_PART)
#define ATT_UUID_NUS_CHAR2            ATT_UUID_NUS_BUILD(ATT_UUID_NUS_CHAR2_PART)

// NUS Service
#define NUS_SERVICE_START_HDL               0x0700
#define NUS_SERVICE_END_HDL                 (NUS_MAX_HDL - 1)


/* NUS Service Handles */
enum
{
  NUS_HDL = NUS_SERVICE_START_HDL,    /* NUS service declaration */
  NUS_CHAR1_CH_HDL,                             /* NUS write command characteristic */
  NUS_CHAR1_HDL,                                /* NUS write command data */
  NUS_CHAR2_CH_HDL,                             /* NUS notify characteristic */
  NUS_CHAR2_HDL,                                /* NUS notify data */
  NUS_CHAR2_CH_CCC_HDL,                         /* NUS notify client characteristic configuration */
  NUS_MAX_HDL
};


//*****************************************************************************
//
// External variable definitions
//
//*****************************************************************************

//*****************************************************************************
//
// Function definitions.
//
//*****************************************************************************
void UhalNUSAddGroup(void);
void UhalNUSRemoveGroup(void);
void UhalNUSCbackRegister(attsReadCback_t readCback, attsWriteCback_t writeCback);

#ifdef __cplusplus
}
#endif

#endif // UHAL_NUS_H__
