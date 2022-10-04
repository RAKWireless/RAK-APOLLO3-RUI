#ifdef SUPPORT_FUOTA
#include <stddef.h>
#include <stdint.h>
#include "udrv_errno.h"
#include "udrv_serial.h"
#include "udrv_system.h"
#include "udrv_rtc.h"
#include "udrv_gpio.h"
#include "udrv_flash.h"
#include "board_basic.h"
#include "service_nvm.h"
#include "service_lora.h"
#include "LoRaMac.h"
#include "Region.h"
#include "LmhPackage.h"
#include "LmhpCompliance.h"
#include "service_lora_fuota.h"
#include "LmhpClockSync.h"
#include "LmhpRemoteMcastSetup.h"
#include "LmhpFragmentation.h"
#include "service_ota_huffman.h"
#include "service_ota_md5.h"
#include "service_ota_diff.h"


static volatile bool IsClockSynched = false;
/*!
 * Defines the application data transmission duty cycle. 10s, value in [ms].
 */
#define APP_TX_DUTYCYCLE                            25000
/*!
 * Defines a random delay for application data transmission duty cycle. 5s,
 * value in [ms].
 */
#define APP_TX_DUTYCYCLE_RND                        5000





// #define LORAWAN_APP_DATA_BUFFER_MAX_SIZE            242
static uint8_t AppDataBuffer[242];
/*!
 * Indicates if a Tx frame is pending.
 *
 * \warning Set to 1 when OnTxTimerEvent raised
 */
volatile uint8_t IsTxFramePending = 0;
/*
 * MC Session Started
 */
volatile bool IsMcSessionStarted = false;
/*
 * Indicates if the file transfer is done
 */
static volatile bool IsFileTransferDone = false;

/*
 *  Received file computed CRC32
 */
static volatile uint32_t FileRxCrc = 0;

/*!
 * Timer to handle the application data transmission duty cycle
 */
TimerEvent_t TxTimer;            /* to open the timer to the RemoteMulticast*/

static void change_str(unsigned char* dest, unsigned char* dest_md5)
{
    uint8_t i;
    char temp[8]={0};
    uint8_t decrypt32[64]={0};

    strcpy((char*)decrypt32,"");
    for(i=0;i<16;i++)
    {
        sprintf(temp,"%02x",dest[i]);
        strcat((char*)decrypt32,temp);
    }
    strcpy((char *)dest_md5,(char *)decrypt32);
}


static void hexdump(uint8_t * data, size_t size, bool line)
{
    size_t i = 1;
	size_t j = 0;
  for( i = 1; i <= size; i++ )
	{
        udrv_serial_log_printf("%02x ", data[j]);
		if(!line )
		{
            if(i % 16 == 0)
			{   
				udrv_serial_log_printf("\r\n");
			}	
        }
		j++;
       
    }
	udrv_serial_log_printf("\r\n");
}


static uint32_t crc32(uint8_t *buffer, uint16_t length)
{
  // The CRC calculation follows CCITT - 0x04C11DB7
  const uint32_t reversedPolynom = 0xEDB88320;

  // CRC initial value
  uint32_t crc = 0xFFFFFFFF;

  if (buffer == NULL)
  {
    return 0;
  }

  for (uint16_t i = 0; i < length; ++i)
  {
    crc ^= (uint32_t)buffer[i];
    for (uint16_t i = 0; i < 8; i++)
    {
      crc = (crc >> 1) ^ (reversedPolynom & ~((crc & 0x01) - 1));
    }
  }

  return ~crc;
}

#ifdef SUPPORT_FUOTA  
LmhpFragmentationParams_t LmhpFragmentationParams =
{
  .DecoderCallbacks =
  {
        .FragDecoderWrite = udrv_flash_write,
        .FragDecoderRead = udrv_flash_read,
  },
  .OnProgress = OnFragProgress,           // should be OnUpdateAgentFragProgress to use Actility lib handling progress
  .OnDone = OnFragDone         // the only API hook with Actility lib right now
};
#endif   //FUOTA


//creat_start_timer
void creat_start_timer(TimerID_E timer_id, timer_handler tmr_handler,uint32_t count)
{
  udrv_timer_create (timer_id, tmr_handler,HTMR_PERIODIC);
	udrv_timer_start (timer_id, count, NULL);
}
 

/*!
 * Function executed on TxTimer event
 */
static void OnTxTimerEvent(void *context)
{
  udrv_timer_stop (TIMER_1);

  IsTxFramePending = 1;

  // Schedule next transmission
  creat_start_timer(TIMER_1,  OnTxTimerEvent,APP_TX_DUTYCYCLE);
}



void LoraStartTx(void)
{
  /* send every time timer elapses */
  OnTxTimerEvent(NULL);

}
 
 
void UplinkProcess( void )
{
  LmHandlerErrorStatus_t status = LORAMAC_HANDLER_ERROR;

  if (IsTxFramePending == 1)
  {

    if (IsMcSessionStarted == false)    /* we are in Class A*/
    {
      if (IsClockSynched == false)    /* we request AppTimeReq to allow FUOTA */
      {
        status = LmhpClockSyncAppTimeReq();
        //udrv_serial_log_printf("status:%d\r\n",status);
      }
      else if(service_lora_get_class() == SERVICE_LORA_CLASS_A)
      {
        AppDataBuffer[0] = randr(0, 255);
        /* Send random packet */
        LmHandlerAppData_t appData =
        {
          .Buffer = AppDataBuffer,
          .BufferSize = 1,
          .Port = 1
        };
        status = LmHandlerSend(&appData, LORAMAC_HANDLER_UNCONFIRMED_MSG);
        udrv_serial_log_printf(" has send up data!\n\r"); // *olg*TMP
      }
      }
    else  /* Now we are in Class C or in Class B -- FUOTA feature could be activated */
    {
      if (IsFileTransferDone == false)
      {
        /* do nothing up to the transfer done or sent a data user */
      }
      else
      {
/*
        AppDataBuffer[0] = 0x05; // FragDataBlockAuthReq
        AppDataBuffer[1] = FileRxCrc & 0x000000FF;
        AppDataBuffer[2] = (FileRxCrc >> 8) & 0x000000FF;
        AppDataBuffer[3] = (FileRxCrc >> 16) & 0x000000FF;
        AppDataBuffer[4] = (FileRxCrc >> 24) & 0x000000FF;
*/
        /* Send FragAuthReq */
/*
        LmHandlerAppData_t appData =
        {
          .Buffer = AppDataBuffer,
          .BufferSize = 5,
          .Port = 201
        };
        status = LmHandlerSend(&appData, LORAMAC_HANDLER_UNCONFIRMED_MSG);
*/
      }

      IsFileTransferDone = false;
/*
      if (status == LORAMAC_HANDLER_SUCCESS)
      {
*/
        /* The fragmented transport layer V1.0 doesn't specify any behavior*/
        /* we keep the interop test behavior - CRC32 is returned to the server*/
/*
        udrv_serial_log_printf(" CRC send \n\r");
      }
*/
    }
    /* send application frame - could be put in conditional compilation*/
    /*  Send(NULL);  comment the sending to avoid interference during multicast*/
  }
    IsTxFramePending = 0;
}
  

void OnSysTimeUpdate(void)
{
    IsClockSynched = true;
}




void OnFragProgress(uint16_t fragCounter, uint16_t fragNb, uint8_t fragSize, uint16_t fragNbLost)
{
  udrv_serial_log_printf("\r\n....... FRAG_DECODER in Progress .......\r\n");
  udrv_serial_log_printf("RECEIVED    : %5d / %5d Fragments\r\n", fragCounter, fragNb);
  udrv_serial_log_printf("              %5d / %5d Bytes\r\n", fragCounter * fragSize, fragNb * fragSize);
  udrv_serial_log_printf("LOST        :       %7d Fragments\r\n\r\n", fragNbLost);
}


void OnFragDone(int32_t status, uint32_t size)
{
    IsFileTransferDone = true;
    uint8_t file_md5[16]= "\0";
    uint8_t calc_file_md5[36]= "\0";
	  uint8_t str_file_md5[36] = "\0";
    huffman_node* root = NULL;
    huffman_node* l_p = NULL;
    uint32_t pData_Bytes = 0;
    uint32_t huff_len = 0;
    uint8_t *data_addr = NULL;
    uint32_t data_len = 0;
    uint8_t bufout[4096] = "\0";
	  uint32_t bufoutlen;
    uint32_t len = 1024;
    uint32_t fw_location;

    /* copy the file from RAM to FLASH & ASK to reboot the device*/

    uint8_t *comp_diff_data = (uint8_t *)malloc(size);
    if (comp_diff_data == NULL) {
        udrv_serial_log_printf("malloc error!!!");
        return;
    }
    memset(comp_diff_data,'\0',size);
    Boot boot_info;
    udrv_flash_read(FW_LOAD_INFO,sizeof(boot_info), (uint8_t*)&boot_info);
    fw_location = (boot_info.A_valid == 1) ? SECTOR_B_ADDR:SECTOR_A_ADDR;
    write_addr =  fw_location;
    udrv_serial_log_printf("fw_location:%x\r\n",fw_location);
    memcpy(comp_diff_data,fw_location, size);
    memcpy(file_md5,comp_diff_data, 16);
    hexdump(comp_diff_data,size,false);
    calc_md5_flash(fw_location+18, size-18, calc_file_md5);
    change_str(file_md5, str_file_md5);
    udrv_serial_log_printf("file_md5:%s\r\n",str_file_md5);
    udrv_serial_log_printf("calc_file_md5:%s\r\n",calc_file_md5);
    if(strcmp((char *)calc_file_md5,(char *)str_file_md5) == 0)   //校验MD5
	{
        if(fw_location == SECTOR_A_ADDR)
        {
            flash_operate.new_fw_addr = SECTOR_A_ADDR;
            flash_operate.origin_fw_addr = SECTOR_B_ADDR;
        }
        else
        {
            flash_operate.new_fw_addr = SECTOR_B_ADDR;
            flash_operate.origin_fw_addr = SECTOR_A_ADDR;
        }
        variable_init();
        //对压缩后的差分数据进行解压
        root = read_code_table_from_memory(comp_diff_data+18,size-18,&pData_Bytes,&huff_len);
         udrv_serial_log_printf("pData_Bytes:%d \r\n",pData_Bytes);
        udrv_serial_log_printf("huff_len:%d \r\n",huff_len);
        if(!root)
        {
            udrv_serial_log_printf("read_code_table_from_memory failed!\r\n");
            return;
        }
        data_addr = comp_diff_data + 18 + huff_len;    //差分数据起始位置
        data_len = size - 18 - huff_len;   //差分数据长度
        while(1)
        {
            udrv_serial_log_printf("data_len:%d \r\n",data_len);
            len = (((data_len / len) > 0)  ?  1024 : data_len);
            l_p = huffman_decode_memory(data_addr,len, bufout, &bufoutlen, root, l_p , &pData_Bytes);
            //打印解压出来的差分数据
            udrv_serial_log_printf("***************************************************************************************\r\n");
            //还原差分数据
            data_reduction(bufout, bufoutlen);
            data_addr += len;
            if(!(data_len -= len)) break;
        }
        udrv_serial_log_printf("\r\n");
        udrv_serial_log_printf("newfw_rec_size: %d  \r\n",newfw_rec_size);
        calc_md5_flash(fw_location, newfw_rec_size, file_md5);
        udrv_serial_log_printf("\r\n");


        if(fw_location == SECTOR_A_ADDR)
        {
            boot_info.A_valid  = 1;
            boot_info.B_valid  = 0;
        }
        else
        {
            boot_info.A_valid  = 0;
            boot_info.B_valid  = 1;
        }
        udrv_flash_write(FW_LOAD_INFO,sizeof(boot_info), (uint8_t *)&boot_info);
        // 软件复位
        free(comp_diff_data);
        NVIC_SystemReset();

	}
    free(comp_diff_data);

}
 

 #endif //FUOTA
