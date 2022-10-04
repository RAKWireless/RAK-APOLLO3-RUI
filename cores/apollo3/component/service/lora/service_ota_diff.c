#include"service_ota_diff.h"

Flash_operate_t flash_operate ; 

uint32_t newFwOffset = 0;
uint32_t PreNum = 0;	
Frame_t frm;  
uint32_t frmLen = sizeof(Frame_t);
uint8_t LastData[4096] = {0}; //用于组合差分数据包
uint32_t newfw_rec_size = 0;
uint32_t write_addr; 


void variable_init(void)  //全局变量初始化函数
{
    newFwOffset = 0;   
    PreNum = 0;			
    number = 0;  //保持为字典数据根节点
    newfw_rec_size = 0;
    memset(LastData,0,4096);
}



 /********************************************
 * Name:  difference_reduction
 * Function: 提取出完整的数据段
 * Parameter:    
 * Returned value:  
 * Brief:  
 *******************************************/
 
void difference_reduction(uint8_t *diffData)
{
     // restore ota firmware
	uint32_t len = 1024;
	uint32_t length = 0;
	uint32_t i = 0;
	uint8_t newFwData[1024] = "\0";
	uint8_t diffFwData[1024] = "\0";
	uint8_t oldFwData[1024] = "\0";
    uint32_t oldFwOffset = 0;
    uint32_t diffFwOffset = 0;
	uint32_t old_addr = 0;
	
    // 获取当前整包数据的头
    memcpy(&frm, diffData, frmLen);
    if(frm.fhdr.Bits.type != CLASS_DIFF && frm.fhdr.Bits.type != CLASS_MISS && frm.fhdr.Bits.type != CLASS_EXTRA
    || frm.fctl.Diff.length <= 0)
    {
        udrv_serial_log_printf("bad data type!!!\r\n");
        return;
    }

	newfw_rec_size += frm.fctl.Diff.length;
	length = frm.fctl.Diff.length;
	
    diffFwOffset = frmLen;
	
	// get offset of old Fw
	oldFwOffset = newFwOffset - frm.fctl.Diff.offset;
	newFwOffset += frm.fctl.Diff.length;
	old_addr =  flash_operate.origin_fw_addr + oldFwOffset;	
	while(1)
	{
		len = (((length / len) > 0)  ?  1024 : length);
		// 判断是否与原固件不同
		if(frm.fhdr.Bits.type == CLASS_DIFF)
		{
			// 提取出新固件数据
			memcpy(diffFwData, diffData+diffFwOffset,len);
			diffFwOffset += len;
			//udrv_flash_read(old_addr,len, oldFwData);
			memcpy(oldFwData,(void *)old_addr,len);
			old_addr += len;
			for(i=0; i< len; i++)
			{
				newFwData[i] = oldFwData[i] ^ diffFwData[i];
			}
		}
		// 判断是否与原固件相同
		else if(frm.fhdr.Bits.type == CLASS_MISS)
		{
			if(len > 0)
			{
				// 从flash的固件读出length长度的数据存入newFwData
				//udrv_flash_read(old_addr, len, newFwData);
				memcpy(newFwData,(void *)old_addr, len);
				old_addr += len;
			}

		}
		// 判断是否是新添加的固件数据
		else if(frm.fhdr.Bits.type == CLASS_EXTRA)
		{
			// 提取出新添加数据
			memcpy(newFwData, diffData+diffFwOffset, len);
			diffFwOffset += len;
		}
		else 
		{
            udrv_serial_log_printf("bad data type!!!\r\n");
            break;
        }	
		// 将新固件写入到flash中 
		udrv_flash_write(write_addr,len, newFwData);
        //memcpy((void *)write_addr,newFwData,len);
		write_addr += len;
		if(!(length -= len)) break;
	}
	memset(&frm,0,frmLen);
}
  
  
 /********************************************
 * Name:  data_reduction
 * Function: 提取出完整的数据段
 * Parameter:    
 * Returned value:  
 * Brief:  
 *******************************************/
void data_reduction(uint8_t *current_data,uint32_t len)
 {
	uint8_t diff_data[4096]; //存储一包完整包
	uint32_t offset = 0;
	uint32_t last_len = 0;

	//将当前数据复制到last里面做处理
	memcpy(LastData+PreNum, current_data, len);
    PreNum += len;
	last_len = PreNum;
	while(1)
	{			
		if(PreNum < frmLen)
		{
			break ;
		}	 
		//读当前块的第一个数据头
		memcpy(&frm,LastData+offset,frmLen);
		if((frm.fhdr.Bits.type != CLASS_MISS) && (frm.fctl.Diff.length > (PreNum - frmLen)))  //不够长
		{
			//Last中数据长度
			break;
		}
		else//够长
		{
			// 循环判断last里面的数据直到不够完整的一包
			if(frm.fhdr.Bits.type == CLASS_MISS)
			{
				//将相同的数据头进行差分还原
				memcpy(diff_data,LastData+offset,frmLen);	
				// 还原完一整包数据偏移值就叠加
				offset += frmLen;			
			}
			else
			{
				// 将本包完整数据复制到diff_data
				memcpy(diff_data,LastData+offset,frmLen+frm.fctl.Diff.length);	
				// 还原完一整包数据偏移值就叠加
				offset += (frmLen + frm.fctl.Diff.length);		
			}
			// 将这一包数据进行还原并存到flash
			difference_reduction(diff_data);
			memset(diff_data,0,4096);
			// 还原完一整包数据后，剩余需还原数据的长度
			PreNum = last_len - offset;
		}
	}
	// 将最后多余的复制到last中
	memcpy(LastData, LastData+offset, PreNum);
	memset(&frm,0,frmLen);
 }

