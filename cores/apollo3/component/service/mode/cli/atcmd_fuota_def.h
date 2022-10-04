/**
 *
 * @page ATCMD AT Command Manual
 *
 * @section ATCMD_fuota Fuota Command
 * 
 * @subsection ATCMD_fuota   AT+FUOTASTART: start fuota 
 *
 * This command is used to start the FUota service
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+FUOTASTART      | --                 | RUI nRF52840 Bootloader v0.6                                      | OK                 |
 *
 *  * @subsection ATCMD_key_id_8 AT+MCROOTKEY: mc root key
 *
 * This command allows the user to get the mc root key.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+MCROOTKEY?         | --                 | AT+APPKEY: get  the mc root  key (16 bytes in hex)             | OK                 |
 * | AT+MCROOTKEY=?        | --                 | \<16 hex\>                                                     | OK                 |
 */

#ifndef _ATCMD_FUOTA_DEF_H_
#define _ATCMD_FUOTA_DEF_H_

#define ATCMD_FUOTASTART            "AT+FUOTASTART"
#define ATCMD_MCROOTKEY             "AT+MCROOTKEY"
#endif //_ATCMD_FUOTA_DEF_H_
