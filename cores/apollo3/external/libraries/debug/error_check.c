#include "stdbool.h"
#include "error_check.h"
#include "critical_state.h"
#include "apollo3.h"
#include "am_log.h"

void assert_callback(uint16_t line_num, const uint8_t * file_name, uint32_t err_code)
{
    error_info_t error_info =
    {
        .line_num    = line_num,
        .p_file_name = file_name,
	.err_code    = err_code,
    };
    error_fault_handler((uint32_t)(&error_info));
}

__WEAK void error_fault_handler(uint32_t info)
{
    critical_state_enter();
		
#ifndef DEBUG_ENABLED
    // LOG --> "System reset"
    NVIC_SystemReset();
#else
    // The following variable helps Keil keep the call stack visible, in addition, it can be set to
    // 0 in the debugger to continue executing code after the error check.
    volatile bool loop = true;
    ((void)(loop));

    error_info_t *error_info = (error_info_t *) info;
    am_log_err("Error at %s:%d", error_info->p_file_name, error_info->line_num);
    am_log_err("Error code: %d", error_info->err_code);

    // If printing is disrupted, remove the irq calls, or set the loop variable to 0 in the debugger.
    critical_state_enter();
    while (loop);

    critical_state_exit();
#endif // DEBUG
}
/*lint -restore */
