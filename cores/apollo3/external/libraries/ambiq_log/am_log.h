#ifndef AM_LOG_H__
#define AM_LOG_H__

#ifdef __cplusplus
extern "C" {
#endif 

#ifdef RTT_LOG_ENABLED

#include"SEGGER_RTT.h"

#define LOG_FLOAT_MARKER "%s%d.%03d"

/**
 * @brief Macro for dissecting a float number into two numbers (integer and residuum).
 */
#define LOG_FLOAT(val) (uint32_t) (((val) < 0 && (val) > -1.0) ? "-" : ""),   \
                       (int32_t) (val),                                       \
                       (int32_t) ((((val) > 0) ? (val) - ((int32_t) (val))    \
                                                : ((int32_t) (val)) - (val))*1000)

// Function Declarations
void rtt_log_general_print(int terminal, const char* color, const char *file, int line, const char *sFormat, ...);

// LOG INIT
void am_log_init(void);

// Log ERROR - Warning - Info
#define am_log_err(...)	rtt_log_general_print(0,RTT_CTRL_TEXT_BRIGHT_RED,__FILE__,__LINE__,__VA_ARGS__)
#define am_log_wrn(...)	rtt_log_general_print(0,RTT_CTRL_TEXT_BRIGHT_YELLOW,__FILE__,__LINE__,__VA_ARGS__)
#define am_log_inf(...)	rtt_log_general_print(0,RTT_CTRL_TEXT_BRIGHT_WHITE,__FILE__,__LINE__,__VA_ARGS__)

#else

#define am_log_err(...) 
#define am_log_wrn(...)
#define am_log_inf(...)
#define am_log_init() 

#endif // RTT_LOG_ENABLED

#ifdef __cplusplus
}
#endif

#endif // AM_LOG_H__
