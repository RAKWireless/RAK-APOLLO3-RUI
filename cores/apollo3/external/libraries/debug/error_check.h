#ifndef ERROR_CHECK_H_
#define ERROR_CHECK_H_

#include <stdint.h>
#include "compiler_abstraction.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    uint32_t        line_num;    /**< The line number where the error occurred. */
    uint8_t const * p_file_name; /**< The file in which the error occurred. */
    uint32_t        err_code;    /**< The error code representing the error that occurred. */
} error_info_t;

void assert_callback(uint16_t line_num, const uint8_t *file_name, uint32_t err_code);
void error_fault_handler(uint32_t info);

#ifdef DEBUG_ENABLED
#define ERROR_CHECK(ERR_CODE)                                    					\
    do                                                                		\
    {                                                                 		\
        const uint32_t LOCAL_ERR_CODE = (ERR_CODE);         							\
        if (LOCAL_ERR_CODE != 0)                  												\
        {                                                   							\
            assert_callback(__LINE__, (uint8_t*) __FILE__, ERR_CODE);  		\
        }                                                   							\
    } while (0)
#else
#define ERROR_CHECK(ERR_CODE)                             	\
    do                                                      \
    {                                                       \
        const uint32_t LOCAL_ERR_CODE = (ERR_CODE);         \
        if (LOCAL_ERR_CODE != 0)                  					\
        {                                                   \
            assert_callback(0, 0, ERR_CODE);  							\
        }                                                   \
    } while (0)
#endif

	
#if (defined(ASSERT_ENABLED))
#define ASSERT_PRESENT 1
#else
#define ASSERT_PRESENT 0
#endif
		
		
#define ASSERT(expr)                                                          		\
if (ASSERT_PRESENT)                                                           		\
{                                                                             		\
    if (expr)                                                                 		\
    {                                                                         		\
    }                                                                         		\
    else                                                                      		\
    {                                                                         		\
        assert_callback((uint16_t)__LINE__, (uint8_t *)__FILE__, 0xFFFFFFFF);     \
    }                                                                         		\
}


#ifdef __cplusplus
}
#endif

#endif /* ERROR_CHECK_H_ */
