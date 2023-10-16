#ifdef RTT_LOG_ENABLED

#include <stdarg.h>  // VA Lists
#include "am_log.h"

// Spaces and length for maximum file names
#define MAX_FILE_LEN 50 

void am_log_init(void)
{
    //SEGGER_RTT_ConfigUpBuffer(LOG_BUFF, 0, buffer, BUFF_SIZE, SEGGER_RTT_MODE_BLOCK_IF_FIFO_FULL);
    //SEGGER_RTT_ConfigUpBuffer(LOG_BUFF, 0, buffer, BUFF_SIZE, SEGGER_RTT_MODE_NO_BLOCK_SKIP);
    SEGGER_RTT_ConfigUpBuffer(0, NULL, NULL, 0, SEGGER_RTT_MODE_NO_BLOCK_SKIP);
}

void rtt_log_general_print(int terminal, const char* color, const char *file, int line, const char * sFormat, ...) 
{
    // Set Color
    SEGGER_RTT_WriteString(0, color);

    // Print file name
    const char *lastSlash = file;
    const char *current = file;
    while(*current!=0) 
    {
      if(*current == '\\' || *current == '/') 
          lastSlash = current+1;
      current++;
    }

    // Print name/line number
    SEGGER_RTT_printf(0, "%s:%d\t\t", lastSlash, line);	

    // Print actual error message stuff
    va_list ParamList;
    va_start(ParamList, sFormat);
    SEGGER_RTT_vprintf(0, sFormat, &ParamList);

    SEGGER_RTT_WriteString(0, "\r\n");

    // Wait until log is written!!!
    /*
    while(1)
    {
      unsigned int s = SEGGER_RTT_GetBytesInBuffer(0);
      if(s == 0)
        break;
    }
    */
    /* ---- */
}
#endif
