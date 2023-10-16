#ifndef _COMPILER_ABSTRACTION_H
#define _COMPILER_ABSTRACTION_H

/*lint ++flb "Enter library region" */

#ifdef __cplusplus
extern "C" {
#endif

#if defined ( __CC_ARM )

        #define __ASM               __asm
        #define __INLINE            __inline
        #define __WEAK              __weak
        #define __ALIGN(n)          __align(n)
        #define __PACKED            __packed
    
#elif defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)

        #define __ASM               __asm
        #define __INLINE            __inline
        #define __WEAK              __attribute__((weak))
        #define __ALIGN(n)          __attribute__((aligned(n)))
        #define __PACKED            __attribute__((packed, aligned(1)))


#elif defined ( __ICCARM__ )

        #define __ASM               __asm
        #define __INLINE            inline
        #define __WEAK              __weak
        #define STRING_PRAGMA(x) _Pragma(#x)
        #define __ALIGN(n) STRING_PRAGMA(data_alignment = n)
        #define __PACKED            __packed
    

#elif defined   ( __GNUC__ )

        #define __ASM               __asm
        #define __INLINE            inline
        #define __WEAK              __attribute__((weak))
        #define __ALIGN(n)          __attribute__((aligned(n)))

#endif

/*lint --flb "Leave library region" */

#ifdef __cplusplus
}
#endif

#endif
