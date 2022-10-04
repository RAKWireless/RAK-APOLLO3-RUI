#ifdef SUPPORT_AT
#include <string.h>

#include "atcmd.h"
 
#include "udrv_errno.h"
#include "udrv_serial.h"
#include "service_lora.h"
 

#ifdef SUPPORT_FUOTA

static void dump_hex2str(uint8_t *buf , uint8_t len)
{
    for(uint8_t i=0; i<len; i++) {
        atcmd_printf("%02X", buf[i]);
    }
    atcmd_printf("\r\n");
}



int At_Fuotastart (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 0) {
 
        udrv_serial_log_printf ("okokokok");
 
    } else {
        return AT_PARAM_ERROR;
    }
}


int At_McRootkey (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        uint8_t rbuff[16];
        if (service_lora_get_McRoot_key(rbuff) != true) {
            return AT_ERROR;
        }
        atcmd_printf("%s=", cmd);
        dump_hex2str(rbuff, 16);
        return AT_OK;
    } else if (param->argc == 1) {
        char lora_id[32];
        char hex_num[3] = {0};
        int32_t ret;

	if (strlen(param->argv[0]) != 32) {
            return AT_PARAM_ERROR;
	}
 
    } else {
        return AT_PARAM_ERROR;
    }
}



#endif
#endif