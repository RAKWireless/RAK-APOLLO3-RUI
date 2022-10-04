#ifndef _DIFF_H
#define _DIFF_H
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
 
#include "udrv_serial.h"
#include "udrv_flash.h"
#include "service_ota_huffman.h"


//接收的数据
typedef struct _data_s
{
	uint8_t  Port;
	uint8_t  RxDatarate;
	uint8_t  Buffer[256];
	uint8_t  BufferSize;
	int16_t  Rssi;
	int8_t   Snr;
}__attribute__ ((packed)) Data_t;


 



 typedef struct _flash_operate_s
{
    uint32_t new_fw_addr; // 新固件存储地址
    uint32_t origin_fw_addr; // 原有固件存储地址
    // int32_t (*write_flash)(uint32_t addr, uint32_t len, uint8_t *buff); // 写flash函数
    // int32_t (*read_flash)(uint32_t addr, uint32_t len, uint8_t *buff ); // 读flash函数
}__attribute__ ((packed)) Flash_operate_t;   




typedef struct boot
{
	uint8_t  A_MD5[16];  //A区固件的MD5
	uint32_t  A_Size;   //A区固件大小
	uint8_t A_Version; //A区固件版本号
    uint8_t  A_valid;   //A区固件有效标志位 
    uint8_t  B_MD5[16];  //B区固件的MD5
	uint32_t B_Size;   //B区固件大小
	uint8_t  B_Version; //B区固件版本号
    uint8_t  B_valid;   //B区固件有效标志位 
    uint8_t  boot_crc;  
}__attribute__ ((packed)) Boot;

  


typedef union
{
    uint8_t value;
    struct HeaderBits_s
    {
        uint8_t ver : 2;
        uint8_t type: 2;
        uint8_t ser : 4;
    } Bits;
}__attribute__ ((packed)) ComHeader_t;


typedef union 
{
    struct DiffCtrl_s
    {
        int32_t offset;
        uint32_t length;
    } Diff;

    struct SameCtrl_s
    {
        int32_t offset;
        uint32_t length;
    } Same;
}__attribute__ ((packed)) FrameCtrl_t;

typedef struct _frame_s
{
    ComHeader_t  fhdr;
    FrameCtrl_t  fctl;
}__attribute__ ((packed)) Frame_t;



typedef enum _Class_E{
    CLASS_DIFF = 0,
    CLASS_MISS,
    CLASS_EXTRA
} Class_t;


extern Flash_operate_t flash_operate ; 
extern uint32_t write_addr;  
extern uint32_t newfw_rec_size;

void variable_init(void);
void difference_reduction(uint8_t *diffData);
void data_reduction(uint8_t *current_data,uint32_t len);
#endif

