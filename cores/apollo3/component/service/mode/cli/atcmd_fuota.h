#ifndef _ATCMD_FUOTA_H_
#define _ATCMD_FUOTA_H_
#include "atcmd.h"

#ifdef SUPPORT_FUOTA
int At_Fuotastart(SERIAL_PORT port, char *cmd, stParam *param);
int At_McRootkey (SERIAL_PORT port, char *cmd, stParam *param);
#endif

#endif //_ATCMD_BOOTLOADER_H_
