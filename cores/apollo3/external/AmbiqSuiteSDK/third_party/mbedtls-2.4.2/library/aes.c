# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c"
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3//"
# 1 "<built-in>"
#define __STDC__ 1
#define __STDC_VERSION__ 199901L
#define __STDC_HOSTED__ 1
#define __GNUC__ 10
#define __GNUC_MINOR__ 2
#define __GNUC_PATCHLEVEL__ 1
#define __VERSION__ "10.2.1 20201103 (release)"
#define __ATOMIC_RELAXED 0
#define __ATOMIC_SEQ_CST 5
#define __ATOMIC_ACQUIRE 2
#define __ATOMIC_RELEASE 3
#define __ATOMIC_ACQ_REL 4
#define __ATOMIC_CONSUME 1
#define __OPTIMIZE_SIZE__ 1
#define __OPTIMIZE__ 1
#define __FINITE_MATH_ONLY__ 0
#define __SIZEOF_INT__ 4
#define __SIZEOF_LONG__ 4
#define __SIZEOF_LONG_LONG__ 8
#define __SIZEOF_SHORT__ 2
#define __SIZEOF_FLOAT__ 4
#define __SIZEOF_DOUBLE__ 8
#define __SIZEOF_LONG_DOUBLE__ 8
#define __SIZEOF_SIZE_T__ 4
#define __CHAR_BIT__ 8
#define __BIGGEST_ALIGNMENT__ 8
#define __ORDER_LITTLE_ENDIAN__ 1234
#define __ORDER_BIG_ENDIAN__ 4321
#define __ORDER_PDP_ENDIAN__ 3412
#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#define __FLOAT_WORD_ORDER__ __ORDER_LITTLE_ENDIAN__
#define __SIZEOF_POINTER__ 4
#define __SIZE_TYPE__ unsigned int
#define __PTRDIFF_TYPE__ int
#define __WCHAR_TYPE__ unsigned int
#define __WINT_TYPE__ unsigned int
#define __INTMAX_TYPE__ long long int
#define __UINTMAX_TYPE__ long long unsigned int
#define __CHAR16_TYPE__ short unsigned int
#define __CHAR32_TYPE__ long unsigned int
#define __SIG_ATOMIC_TYPE__ int
#define __INT8_TYPE__ signed char
#define __INT16_TYPE__ short int
#define __INT32_TYPE__ long int
#define __INT64_TYPE__ long long int
#define __UINT8_TYPE__ unsigned char
#define __UINT16_TYPE__ short unsigned int
#define __UINT32_TYPE__ long unsigned int
#define __UINT64_TYPE__ long long unsigned int
#define __INT_LEAST8_TYPE__ signed char
#define __INT_LEAST16_TYPE__ short int
#define __INT_LEAST32_TYPE__ long int
#define __INT_LEAST64_TYPE__ long long int
#define __UINT_LEAST8_TYPE__ unsigned char
#define __UINT_LEAST16_TYPE__ short unsigned int
#define __UINT_LEAST32_TYPE__ long unsigned int
#define __UINT_LEAST64_TYPE__ long long unsigned int
#define __INT_FAST8_TYPE__ int
#define __INT_FAST16_TYPE__ int
#define __INT_FAST32_TYPE__ int
#define __INT_FAST64_TYPE__ long long int
#define __UINT_FAST8_TYPE__ unsigned int
#define __UINT_FAST16_TYPE__ unsigned int
#define __UINT_FAST32_TYPE__ unsigned int
#define __UINT_FAST64_TYPE__ long long unsigned int
#define __INTPTR_TYPE__ int
#define __UINTPTR_TYPE__ unsigned int
#define __GXX_ABI_VERSION 1014
#define __SCHAR_MAX__ 0x7f
#define __SHRT_MAX__ 0x7fff
#define __INT_MAX__ 0x7fffffff
#define __LONG_MAX__ 0x7fffffffL
#define __LONG_LONG_MAX__ 0x7fffffffffffffffLL
#define __WCHAR_MAX__ 0xffffffffU
#define __WCHAR_MIN__ 0U
#define __WINT_MAX__ 0xffffffffU
#define __WINT_MIN__ 0U
#define __PTRDIFF_MAX__ 0x7fffffff
#define __SIZE_MAX__ 0xffffffffU
#define __SCHAR_WIDTH__ 8
#define __SHRT_WIDTH__ 16
#define __INT_WIDTH__ 32
#define __LONG_WIDTH__ 32
#define __LONG_LONG_WIDTH__ 64
#define __WCHAR_WIDTH__ 32
#define __WINT_WIDTH__ 32
#define __PTRDIFF_WIDTH__ 32
#define __SIZE_WIDTH__ 32
#define __INTMAX_MAX__ 0x7fffffffffffffffLL
#define __INTMAX_C(c) c ## LL
#define __UINTMAX_MAX__ 0xffffffffffffffffULL
#define __UINTMAX_C(c) c ## ULL
#define __INTMAX_WIDTH__ 64
#define __SIG_ATOMIC_MAX__ 0x7fffffff
#define __SIG_ATOMIC_MIN__ (-__SIG_ATOMIC_MAX__ - 1)
#define __SIG_ATOMIC_WIDTH__ 32
#define __INT8_MAX__ 0x7f
#define __INT16_MAX__ 0x7fff
#define __INT32_MAX__ 0x7fffffffL
#define __INT64_MAX__ 0x7fffffffffffffffLL
#define __UINT8_MAX__ 0xff
#define __UINT16_MAX__ 0xffff
#define __UINT32_MAX__ 0xffffffffUL
#define __UINT64_MAX__ 0xffffffffffffffffULL
#define __INT_LEAST8_MAX__ 0x7f
#define __INT8_C(c) c
#define __INT_LEAST8_WIDTH__ 8
#define __INT_LEAST16_MAX__ 0x7fff
#define __INT16_C(c) c
#define __INT_LEAST16_WIDTH__ 16
#define __INT_LEAST32_MAX__ 0x7fffffffL
#define __INT32_C(c) c ## L
#define __INT_LEAST32_WIDTH__ 32
#define __INT_LEAST64_MAX__ 0x7fffffffffffffffLL
#define __INT64_C(c) c ## LL
#define __INT_LEAST64_WIDTH__ 64
#define __UINT_LEAST8_MAX__ 0xff
#define __UINT8_C(c) c
#define __UINT_LEAST16_MAX__ 0xffff
#define __UINT16_C(c) c
#define __UINT_LEAST32_MAX__ 0xffffffffUL
#define __UINT32_C(c) c ## UL
#define __UINT_LEAST64_MAX__ 0xffffffffffffffffULL
#define __UINT64_C(c) c ## ULL
#define __INT_FAST8_MAX__ 0x7fffffff
#define __INT_FAST8_WIDTH__ 32
#define __INT_FAST16_MAX__ 0x7fffffff
#define __INT_FAST16_WIDTH__ 32
#define __INT_FAST32_MAX__ 0x7fffffff
#define __INT_FAST32_WIDTH__ 32
#define __INT_FAST64_MAX__ 0x7fffffffffffffffLL
#define __INT_FAST64_WIDTH__ 64
#define __UINT_FAST8_MAX__ 0xffffffffU
#define __UINT_FAST16_MAX__ 0xffffffffU
#define __UINT_FAST32_MAX__ 0xffffffffU
#define __UINT_FAST64_MAX__ 0xffffffffffffffffULL
#define __INTPTR_MAX__ 0x7fffffff
#define __INTPTR_WIDTH__ 32
#define __UINTPTR_MAX__ 0xffffffffU
#define __GCC_IEC_559 0
#define __GCC_IEC_559_COMPLEX 0
#define __FLT_EVAL_METHOD__ 0
#define __FLT_EVAL_METHOD_TS_18661_3__ 0
#define __DEC_EVAL_METHOD__ 2
#define __FLT_RADIX__ 2
#define __FLT_MANT_DIG__ 24
#define __FLT_DIG__ 6
#define __FLT_MIN_EXP__ (-125)
#define __FLT_MIN_10_EXP__ (-37)
#define __FLT_MAX_EXP__ 128
#define __FLT_MAX_10_EXP__ 38
#define __FLT_DECIMAL_DIG__ 9
#define __FLT_MAX__ 3.4028234663852886e+38F
#define __FLT_NORM_MAX__ 3.4028234663852886e+38F
#define __FLT_MIN__ 1.1754943508222875e-38F
#define __FLT_EPSILON__ 1.1920928955078125e-7F
#define __FLT_DENORM_MIN__ 1.4012984643248171e-45F
#define __FLT_HAS_DENORM__ 1
#define __FLT_HAS_INFINITY__ 1
#define __FLT_HAS_QUIET_NAN__ 1
#define __FP_FAST_FMAF 1
#define __DBL_MANT_DIG__ 53
#define __DBL_DIG__ 15
#define __DBL_MIN_EXP__ (-1021)
#define __DBL_MIN_10_EXP__ (-307)
#define __DBL_MAX_EXP__ 1024
#define __DBL_MAX_10_EXP__ 308
#define __DBL_DECIMAL_DIG__ 17
#define __DBL_MAX__ ((double)1.7976931348623157e+308L)
#define __DBL_NORM_MAX__ ((double)1.7976931348623157e+308L)
#define __DBL_MIN__ ((double)2.2250738585072014e-308L)
#define __DBL_EPSILON__ ((double)2.2204460492503131e-16L)
#define __DBL_DENORM_MIN__ ((double)4.9406564584124654e-324L)
#define __DBL_HAS_DENORM__ 1
#define __DBL_HAS_INFINITY__ 1
#define __DBL_HAS_QUIET_NAN__ 1
#define __LDBL_MANT_DIG__ 53
#define __LDBL_DIG__ 15
#define __LDBL_MIN_EXP__ (-1021)
#define __LDBL_MIN_10_EXP__ (-307)
#define __LDBL_MAX_EXP__ 1024
#define __LDBL_MAX_10_EXP__ 308
#define __DECIMAL_DIG__ 17
#define __LDBL_DECIMAL_DIG__ 17
#define __LDBL_MAX__ 1.7976931348623157e+308L
#define __LDBL_NORM_MAX__ 1.7976931348623157e+308L
#define __LDBL_MIN__ 2.2250738585072014e-308L
#define __LDBL_EPSILON__ 2.2204460492503131e-16L
#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324L
#define __LDBL_HAS_DENORM__ 1
#define __LDBL_HAS_INFINITY__ 1
#define __LDBL_HAS_QUIET_NAN__ 1
#define __FLT32_MANT_DIG__ 24
#define __FLT32_DIG__ 6
#define __FLT32_MIN_EXP__ (-125)
#define __FLT32_MIN_10_EXP__ (-37)
#define __FLT32_MAX_EXP__ 128
#define __FLT32_MAX_10_EXP__ 38
#define __FLT32_DECIMAL_DIG__ 9
#define __FLT32_MAX__ 3.4028234663852886e+38F32
#define __FLT32_NORM_MAX__ 3.4028234663852886e+38F32
#define __FLT32_MIN__ 1.1754943508222875e-38F32
#define __FLT32_EPSILON__ 1.1920928955078125e-7F32
#define __FLT32_DENORM_MIN__ 1.4012984643248171e-45F32
#define __FLT32_HAS_DENORM__ 1
#define __FLT32_HAS_INFINITY__ 1
#define __FLT32_HAS_QUIET_NAN__ 1
#define __FP_FAST_FMAF32 1
#define __FLT64_MANT_DIG__ 53
#define __FLT64_DIG__ 15
#define __FLT64_MIN_EXP__ (-1021)
#define __FLT64_MIN_10_EXP__ (-307)
#define __FLT64_MAX_EXP__ 1024
#define __FLT64_MAX_10_EXP__ 308
#define __FLT64_DECIMAL_DIG__ 17
#define __FLT64_MAX__ 1.7976931348623157e+308F64
#define __FLT64_NORM_MAX__ 1.7976931348623157e+308F64
#define __FLT64_MIN__ 2.2250738585072014e-308F64
#define __FLT64_EPSILON__ 2.2204460492503131e-16F64
#define __FLT64_DENORM_MIN__ 4.9406564584124654e-324F64
#define __FLT64_HAS_DENORM__ 1
#define __FLT64_HAS_INFINITY__ 1
#define __FLT64_HAS_QUIET_NAN__ 1
#define __FLT32X_MANT_DIG__ 53
#define __FLT32X_DIG__ 15
#define __FLT32X_MIN_EXP__ (-1021)
#define __FLT32X_MIN_10_EXP__ (-307)
#define __FLT32X_MAX_EXP__ 1024
#define __FLT32X_MAX_10_EXP__ 308
#define __FLT32X_DECIMAL_DIG__ 17
#define __FLT32X_MAX__ 1.7976931348623157e+308F32x
#define __FLT32X_NORM_MAX__ 1.7976931348623157e+308F32x
#define __FLT32X_MIN__ 2.2250738585072014e-308F32x
#define __FLT32X_EPSILON__ 2.2204460492503131e-16F32x
#define __FLT32X_DENORM_MIN__ 4.9406564584124654e-324F32x
#define __FLT32X_HAS_DENORM__ 1
#define __FLT32X_HAS_INFINITY__ 1
#define __FLT32X_HAS_QUIET_NAN__ 1
#define __SFRACT_FBIT__ 7
#define __SFRACT_IBIT__ 0
#define __SFRACT_MIN__ (-0.5HR-0.5HR)
#define __SFRACT_MAX__ 0X7FP-7HR
#define __SFRACT_EPSILON__ 0x1P-7HR
#define __USFRACT_FBIT__ 8
#define __USFRACT_IBIT__ 0
#define __USFRACT_MIN__ 0.0UHR
#define __USFRACT_MAX__ 0XFFP-8UHR
#define __USFRACT_EPSILON__ 0x1P-8UHR
#define __FRACT_FBIT__ 15
#define __FRACT_IBIT__ 0
#define __FRACT_MIN__ (-0.5R-0.5R)
#define __FRACT_MAX__ 0X7FFFP-15R
#define __FRACT_EPSILON__ 0x1P-15R
#define __UFRACT_FBIT__ 16
#define __UFRACT_IBIT__ 0
#define __UFRACT_MIN__ 0.0UR
#define __UFRACT_MAX__ 0XFFFFP-16UR
#define __UFRACT_EPSILON__ 0x1P-16UR
#define __LFRACT_FBIT__ 31
#define __LFRACT_IBIT__ 0
#define __LFRACT_MIN__ (-0.5LR-0.5LR)
#define __LFRACT_MAX__ 0X7FFFFFFFP-31LR
#define __LFRACT_EPSILON__ 0x1P-31LR
#define __ULFRACT_FBIT__ 32
#define __ULFRACT_IBIT__ 0
#define __ULFRACT_MIN__ 0.0ULR
#define __ULFRACT_MAX__ 0XFFFFFFFFP-32ULR
#define __ULFRACT_EPSILON__ 0x1P-32ULR
#define __LLFRACT_FBIT__ 63
#define __LLFRACT_IBIT__ 0
#define __LLFRACT_MIN__ (-0.5LLR-0.5LLR)
#define __LLFRACT_MAX__ 0X7FFFFFFFFFFFFFFFP-63LLR
#define __LLFRACT_EPSILON__ 0x1P-63LLR
#define __ULLFRACT_FBIT__ 64
#define __ULLFRACT_IBIT__ 0
#define __ULLFRACT_MIN__ 0.0ULLR
#define __ULLFRACT_MAX__ 0XFFFFFFFFFFFFFFFFP-64ULLR
#define __ULLFRACT_EPSILON__ 0x1P-64ULLR
#define __SACCUM_FBIT__ 7
#define __SACCUM_IBIT__ 8
#define __SACCUM_MIN__ (-0X1P7HK-0X1P7HK)
#define __SACCUM_MAX__ 0X7FFFP-7HK
#define __SACCUM_EPSILON__ 0x1P-7HK
#define __USACCUM_FBIT__ 8
#define __USACCUM_IBIT__ 8
#define __USACCUM_MIN__ 0.0UHK
#define __USACCUM_MAX__ 0XFFFFP-8UHK
#define __USACCUM_EPSILON__ 0x1P-8UHK
#define __ACCUM_FBIT__ 15
#define __ACCUM_IBIT__ 16
#define __ACCUM_MIN__ (-0X1P15K-0X1P15K)
#define __ACCUM_MAX__ 0X7FFFFFFFP-15K
#define __ACCUM_EPSILON__ 0x1P-15K
#define __UACCUM_FBIT__ 16
#define __UACCUM_IBIT__ 16
#define __UACCUM_MIN__ 0.0UK
#define __UACCUM_MAX__ 0XFFFFFFFFP-16UK
#define __UACCUM_EPSILON__ 0x1P-16UK
#define __LACCUM_FBIT__ 31
#define __LACCUM_IBIT__ 32
#define __LACCUM_MIN__ (-0X1P31LK-0X1P31LK)
#define __LACCUM_MAX__ 0X7FFFFFFFFFFFFFFFP-31LK
#define __LACCUM_EPSILON__ 0x1P-31LK
#define __ULACCUM_FBIT__ 32
#define __ULACCUM_IBIT__ 32
#define __ULACCUM_MIN__ 0.0ULK
#define __ULACCUM_MAX__ 0XFFFFFFFFFFFFFFFFP-32ULK
#define __ULACCUM_EPSILON__ 0x1P-32ULK
#define __LLACCUM_FBIT__ 31
#define __LLACCUM_IBIT__ 32
#define __LLACCUM_MIN__ (-0X1P31LLK-0X1P31LLK)
#define __LLACCUM_MAX__ 0X7FFFFFFFFFFFFFFFP-31LLK
#define __LLACCUM_EPSILON__ 0x1P-31LLK
#define __ULLACCUM_FBIT__ 32
#define __ULLACCUM_IBIT__ 32
#define __ULLACCUM_MIN__ 0.0ULLK
#define __ULLACCUM_MAX__ 0XFFFFFFFFFFFFFFFFP-32ULLK
#define __ULLACCUM_EPSILON__ 0x1P-32ULLK
#define __QQ_FBIT__ 7
#define __QQ_IBIT__ 0
#define __HQ_FBIT__ 15
#define __HQ_IBIT__ 0
#define __SQ_FBIT__ 31
#define __SQ_IBIT__ 0
#define __DQ_FBIT__ 63
#define __DQ_IBIT__ 0
#define __TQ_FBIT__ 127
#define __TQ_IBIT__ 0
#define __UQQ_FBIT__ 8
#define __UQQ_IBIT__ 0
#define __UHQ_FBIT__ 16
#define __UHQ_IBIT__ 0
#define __USQ_FBIT__ 32
#define __USQ_IBIT__ 0
#define __UDQ_FBIT__ 64
#define __UDQ_IBIT__ 0
#define __UTQ_FBIT__ 128
#define __UTQ_IBIT__ 0
#define __HA_FBIT__ 7
#define __HA_IBIT__ 8
#define __SA_FBIT__ 15
#define __SA_IBIT__ 16
#define __DA_FBIT__ 31
#define __DA_IBIT__ 32
#define __TA_FBIT__ 63
#define __TA_IBIT__ 64
#define __UHA_FBIT__ 8
#define __UHA_IBIT__ 8
#define __USA_FBIT__ 16
#define __USA_IBIT__ 16
#define __UDA_FBIT__ 32
#define __UDA_IBIT__ 32
#define __UTA_FBIT__ 64
#define __UTA_IBIT__ 64
#define __REGISTER_PREFIX__ 
#define __USER_LABEL_PREFIX__ 
#define __GNUC_STDC_INLINE__ 1
#define __STRICT_ANSI__ 1
#define __CHAR_UNSIGNED__ 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1
#define __GCC_ATOMIC_BOOL_LOCK_FREE 2
#define __GCC_ATOMIC_CHAR_LOCK_FREE 2
#define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 2
#define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 2
#define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 2
#define __GCC_ATOMIC_SHORT_LOCK_FREE 2
#define __GCC_ATOMIC_INT_LOCK_FREE 2
#define __GCC_ATOMIC_LONG_LOCK_FREE 2
#define __GCC_ATOMIC_LLONG_LOCK_FREE 1
#define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1
#define __GCC_ATOMIC_POINTER_LOCK_FREE 2
#define __HAVE_SPECULATION_SAFE_VALUE 1
#define __GCC_HAVE_DWARF2_CFI_ASM 1
#define __PRAGMA_REDEFINE_EXTNAME 1
#define __SIZEOF_WCHAR_T__ 4
#define __SIZEOF_WINT_T__ 4
#define __SIZEOF_PTRDIFF_T__ 4
#define __ARM_FEATURE_DSP 1
#define __ARM_FEATURE_QBIT 1
#define __ARM_FEATURE_SAT 1
#undef __ARM_FEATURE_CRYPTO
# 1 "<built-in>"
#define __ARM_FEATURE_UNALIGNED 1
#undef __ARM_FEATURE_QRDMX
# 1 "<built-in>"
#undef __ARM_FEATURE_CRC32
# 1 "<built-in>"
#undef __ARM_FEATURE_DOTPROD
# 1 "<built-in>"
#undef __ARM_FEATURE_COMPLEX
# 1 "<built-in>"
#define __ARM_32BIT_STATE 1
#undef __ARM_FEATURE_MVE
# 1 "<built-in>"
#undef __ARM_FEATURE_CMSE
# 1 "<built-in>"
#undef __ARM_FEATURE_LDREX
# 1 "<built-in>"
#define __ARM_FEATURE_LDREX 7
#define __ARM_FEATURE_CLZ 1
#undef __ARM_FEATURE_NUMERIC_MAXMIN
# 1 "<built-in>"
#define __ARM_FEATURE_SIMD32 1
#define __ARM_SIZEOF_MINIMAL_ENUM 1
#define __ARM_SIZEOF_WCHAR_T 4
#undef __ARM_ARCH_PROFILE
# 1 "<built-in>"
#define __ARM_ARCH_PROFILE 77
#define __arm__ 1
#undef __ARM_ARCH
# 1 "<built-in>"
#define __ARM_ARCH 7
#define __APCS_32__ 1
#define __GCC_ASM_FLAG_OUTPUTS__ 1
#define __thumb__ 1
#define __thumb2__ 1
#define __THUMBEL__ 1
#undef __ARM_ARCH_ISA_THUMB
# 1 "<built-in>"
#define __ARM_ARCH_ISA_THUMB 2
#define __ARMEL__ 1
#define __VFP_FP__ 1
#undef __ARM_FP
# 1 "<built-in>"
#define __ARM_FP 4
#undef __ARM_FP16_FORMAT_IEEE
# 1 "<built-in>"
#undef __ARM_FP16_FORMAT_ALTERNATIVE
# 1 "<built-in>"
#undef __ARM_FP16_ARGS
# 1 "<built-in>"
#undef __ARM_FEATURE_FP16_SCALAR_ARITHMETIC
# 1 "<built-in>"
#undef __ARM_FEATURE_FP16_VECTOR_ARITHMETIC
# 1 "<built-in>"
#undef __ARM_FEATURE_FP16_FML
# 1 "<built-in>"
#define __ARM_FEATURE_FMA 1
#undef __ARM_NEON__
# 1 "<built-in>"
#undef __ARM_NEON
# 1 "<built-in>"
#undef __ARM_NEON_FP
# 1 "<built-in>"
#define __THUMB_INTERWORK__ 1
#define __ARM_ARCH_7EM__ 1
#define __ARM_PCS_VFP 1
#define __ARM_EABI__ 1
#undef __FDPIC__
# 1 "<built-in>"
#define __ARM_ARCH_EXT_IDIV__ 1
#define __ARM_FEATURE_IDIV 1
#define __ARM_ASM_SYNTAX_UNIFIED__ 1
#undef __ARM_FEATURE_COPROC
# 1 "<built-in>"
#define __ARM_FEATURE_COPROC 15
#undef __ARM_FEATURE_CDE
# 1 "<built-in>"
#undef __ARM_FEATURE_CDE_COPROC
# 1 "<built-in>"
#undef __ARM_FEATURE_MATMUL_INT8
# 1 "<built-in>"
#undef __ARM_FEATURE_BF16_SCALAR_ARITHMETIC
# 1 "<built-in>"
#undef __ARM_FEATURE_BF16_VECTOR_ARITHMETIC
# 1 "<built-in>"
#undef __ARM_BF16_FORMAT_ALTERNATIVE
# 1 "<built-in>"
#define __GXX_TYPEINFO_EQUALITY_INLINE 0
#define __ELF__ 1
# 1 "<command-line>"
#define __USES_INITFINI__ 1
#define apollo3 1
#define SUPPORT_LORA 1
#define SUPPORT_LORA_P2P 1
#define LORA_IO_SPI_PORT 1
#define SYS_RTC_COUNTER_PORT 2
#define ATCMD_CUST_TABLE_SIZE 64
#define WAN_TYPE 0
#define LORA_STACK_VER 0x040407
#define RAK11720 +RAK5005-O_V1.0 1
#define rak11720 1
#define gcc 1
#define PART_APOLLO3 1
#define AM_PACKAGE_BGA 1
#define AM_PART_APOLLO3 1
#define AM_FREERTOS 1
#define AM_FREERTOS_STIMER_BACKUP 1
#define AM_BLE_USE_NVM 1
#define AM_CUSTOM_BDADDR 1
#define AM_NUS_ADD 1
#define AM_CUS_ADD 1
#define AM_AMOTA_ADD 1
#define AM_UTIL_FAULTISR_PRINT 1
#define SEC_ECC_CFG SEC_ECC_CFG_HCI
#define RTT_LOG_ENABLED 1
#define DEBUG_ENABLED 1
#define rak11720 1
#define SYS_RTC_COUNTER_PORT 2
#define TWI0_ENABLED 1
#define SPI0_ENABLED 1
#define SPI1_ENABLED 1
#define BLE_SUPPORT 1
#define ATCMD_CUST_TABLE_SIZE 64
#define WISBLOCK_BASE_5005_O 1
#define SX1262_CHIP 1
#define REGION_AS923 1
#define REGION_AU915 1
#define REGION_CN470 1
#define REGION_CN779 1
#define REGION_EU433 1
#define REGION_EU868 1
#define REGION_KR920 1
#define REGION_IN865 1
#define REGION_US915 1
#define REGION_RU864 1
#define REGION_LA915 1
#define SOFT_SE 1
#define SECURE_ELEMENT_PRE_PROVISIONED 1
#define LORAMAC_CLASSB_ENABLED 1
#define BLE_CENTRAL_SUPPORT 1
#define WISBLOCK_BASE_5005_O 1
#define SUPPORT_BLE 1
#define SUPPORT_SPI 1
#define SUPPORT_AT 1
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c"
# 29 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c"
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h" 1
# 29 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_CONFIG_H 
# 56 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_HAVE_ASM 
# 80 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_HAVE_TIME 
# 92 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_HAVE_TIME_DATE 
# 341 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_CIPHER_MODE_CBC 






#define MBEDTLS_CIPHER_MODE_CFB 






#define MBEDTLS_CIPHER_MODE_CTR 
# 401 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_CIPHER_PADDING_PKCS7 
#define MBEDTLS_CIPHER_PADDING_ONE_AND_ZEROS 
#define MBEDTLS_CIPHER_PADDING_ZEROS_AND_LEN 
#define MBEDTLS_CIPHER_PADDING_ZEROS 
# 432 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_REMOVE_ARC4_CIPHERSUITES 
# 442 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_ECP_DP_SECP192R1_ENABLED 
#define MBEDTLS_ECP_DP_SECP224R1_ENABLED 
#define MBEDTLS_ECP_DP_SECP256R1_ENABLED 
#define MBEDTLS_ECP_DP_SECP384R1_ENABLED 
#define MBEDTLS_ECP_DP_SECP521R1_ENABLED 
#define MBEDTLS_ECP_DP_SECP192K1_ENABLED 
#define MBEDTLS_ECP_DP_SECP224K1_ENABLED 
#define MBEDTLS_ECP_DP_SECP256K1_ENABLED 
#define MBEDTLS_ECP_DP_BP256R1_ENABLED 
#define MBEDTLS_ECP_DP_BP384R1_ENABLED 
#define MBEDTLS_ECP_DP_BP512R1_ENABLED 
#define MBEDTLS_ECP_DP_CURVE25519_ENABLED 
# 464 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_ECP_NIST_OPTIM 
# 478 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_ECDSA_DETERMINISTIC 
# 500 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_KEY_EXCHANGE_PSK_ENABLED 
# 524 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_KEY_EXCHANGE_DHE_PSK_ENABLED 
# 544 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED 
# 569 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_KEY_EXCHANGE_RSA_PSK_ENABLED 
# 597 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_KEY_EXCHANGE_RSA_ENABLED 
# 623 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_KEY_EXCHANGE_DHE_RSA_ENABLED 
# 648 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_KEY_EXCHANGE_ECDHE_RSA_ENABLED 
# 672 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_KEY_EXCHANGE_ECDHE_ECDSA_ENABLED 
# 696 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_KEY_EXCHANGE_ECDH_ECDSA_ENABLED 
# 720 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_KEY_EXCHANGE_ECDH_RSA_ENABLED 
# 753 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_PK_PARSE_EC_EXTENDED 
# 768 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_ERROR_STRERROR_DUMMY 
# 777 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_GENPRIME 






#define MBEDTLS_FS_IO 
# 886 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_PK_RSA_ALT_SUPPORT 
# 897 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_PKCS1_V15 
# 908 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_PKCS1_V21 
# 925 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SELF_TEST 
# 955 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_ALL_ALERT_MESSAGES 
# 989 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_ENCRYPT_THEN_MAC 
# 1007 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_EXTENDED_MASTER_SECRET 
# 1024 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_FALLBACK_SCSV 
# 1046 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_CBC_RECORD_SPLITTING 
# 1061 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_RENEGOTIATION 
# 1090 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_MAX_FRAGMENT_LENGTH 
# 1114 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_PROTO_TLS1 
# 1126 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_PROTO_TLS1_1 
# 1138 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_PROTO_TLS1_2 
# 1153 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_PROTO_DTLS 
# 1162 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_ALPN 
# 1177 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_DTLS_ANTI_REPLAY 
# 1195 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_DTLS_HELLO_VERIFY 
# 1211 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_DTLS_CLIENT_PORT_REUSE 
# 1222 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_DTLS_BADMAC_LIMIT 
# 1236 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_SESSION_TICKETS 
# 1246 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_EXPORT_KEYS 
# 1257 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_SERVER_NAME_INDICATION 
# 1266 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_TRUNCATED_HMAC 
# 1301 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_VERSION_FEATURES 
# 1337 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_X509_CHECK_KEY_USAGE 
# 1350 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_X509_CHECK_EXTENDED_KEY_USAGE 
# 1360 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_X509_RSASSA_PSS_SUPPORT 
# 1404 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_AESNI_C 
# 1479 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_AES_C 
# 1502 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_ARC4_C 
# 1516 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_ASN1_PARSE_C 
# 1530 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_ASN1_WRITE_C 
# 1542 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_BASE64_C 
# 1558 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_BIGNUM_C 
# 1567 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_BLOWFISH_C 
# 1622 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_CAMELLIA_C 
# 1636 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_CCM_C 
# 1648 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_CERTS_C 
# 1660 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_CIPHER_C 
# 1687 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_CTR_DRBG_C 
# 1701 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_DEBUG_C 
# 1727 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_DES_C 
# 1741 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_DHM_C 
# 1757 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_ECDH_C 
# 1772 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_ECDSA_C 
# 1805 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_ECP_C 
# 1819 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_ENTROPY_C 
# 1831 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_ERROR_C 
# 1845 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_GCM_C 
# 1882 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_HMAC_DRBG_C 
# 1894 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_MD_C 
# 1933 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_MD5_C 
# 1968 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_NET_C 
# 1991 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_OID_C 
# 2005 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_PADLOCK_C 
# 2023 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_PEM_PARSE_C 
# 2039 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_PEM_WRITE_C 
# 2055 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_PK_C 
# 2070 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_PK_PARSE_C 
# 2084 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_PK_WRITE_C 
# 2097 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_PKCS5_C 
# 2128 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_PKCS12_C 
# 2148 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_PLATFORM_C 
# 2159 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_RIPEMD160_C 
# 2177 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_RSA_C 
# 2193 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SHA1_C 
# 2210 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SHA256_C 
# 2225 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SHA512_C 
# 2237 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_CACHE_C 
# 2247 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_COOKIE_C 
# 2259 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_TICKET_C 
# 2273 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_CLI_C 
# 2287 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_SRV_C 
# 2303 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_SSL_TLS_C 
# 2348 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_TIMING_C 
# 2359 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_VERSION_C 
# 2376 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_X509_USE_C 
# 2392 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_X509_CRT_PARSE_C 
# 2406 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_X509_CRL_PARSE_C 
# 2420 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_X509_CSR_PARSE_C 
# 2433 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_X509_CREATE_C 
# 2446 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_X509_CRT_WRITE_C 
# 2459 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_X509_CSR_WRITE_C 
# 2469 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
#define MBEDTLS_XTEA_C 
# 2598 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h"
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/check_config.h" 1
# 30 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/check_config.h"
#define MBEDTLS_CHECK_CONFIG_H 





# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include-fixed/limits.h" 1 3 4
# 30 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include-fixed/limits.h" 3 4
#define _GCC_LIMITS_H_ 



# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include-fixed/syslimits.h" 1 3 4





#define _GCC_NEXT_LIMITS_H 
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include-fixed/limits.h" 1 3 4
# 195 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include-fixed/limits.h" 3 4
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/limits.h" 1 3 4

#define _LIBC_LIMITS_H_ 1

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 1 3 4







#define __NEWLIB_H__ 1





# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_newlib_version.h" 1 3 4



#define _NEWLIB_VERSION_H__ 1

#define _NEWLIB_VERSION "3.3.0"
#define __NEWLIB__ 3
#define __NEWLIB_MINOR__ 3
#define __NEWLIB_PATCHLEVEL__ 0
# 15 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 2 3 4



#define _WANT_IO_C99_FORMATS 1


#define _WANT_IO_LONG_LONG 1


#define _WANT_REGISTER_FINI 1
# 37 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 3 4
#define _REENT_CHECK_VERIFY 1





#define _MB_LEN_MAX 1
# 53 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 3 4
#define HAVE_INITFINI_ARRAY 1



#define _ATEXIT_DYNAMIC_ALLOC 1


#define _HAVE_LONG_DOUBLE 1


#define _HAVE_CC_INHIBIT_LOOP_TO_LIBCALL 1


#define _LDBL_EQ_DBL 1


#define _FVWRITE_IN_STREAMIO 1


#define _FSEEK_OPTIMIZATION 1


#define _WIDE_ORIENT 1


#define _UNBUF_STREAM_OPT 1
# 95 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 3 4
#define _RETARGETABLE_LOCKING 1
# 5 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/limits.h" 2 3 4
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 1 3 4
# 43 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3 4
#define _SYS_CDEFS_H_ 

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 1 3 4





#define _MACHINE__DEFAULT_TYPES_H 

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 1 3 4
# 22 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3 4
#define _SYS_FEATURES_H 
# 33 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3 4
#define __GNUC_PREREQ(maj,min) ((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))






#define __GNUC_PREREQ__(ma,mi) __GNUC_PREREQ(ma, mi)
# 249 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3 4
#define __ATFILE_VISIBLE 0





#define __BSD_VISIBLE 0





#define __GNU_VISIBLE 0







#define __ISO_C_VISIBLE 1999







#define __LARGEFILE_VISIBLE 0





#define __MISC_VISIBLE 0
# 299 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3 4
#define __POSIX_VISIBLE 0





#define __SVID_VISIBLE 0
# 319 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3 4
#define __XSI_VISIBLE 0
# 330 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3 4
#define __SSP_FORTIFY_LEVEL 0
# 9 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 2 3 4






#define __EXP(x) __ ##x ##__
# 26 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3 4
#define __have_longlong64 1






#define __have_long32 1








# 41 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef signed char __int8_t;

typedef unsigned char __uint8_t;



#define ___int8_t_defined 1







typedef short int __int16_t;

typedef short unsigned int __uint16_t;



#define ___int16_t_defined 1
# 77 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long int __int32_t;

typedef long unsigned int __uint32_t;



#define ___int32_t_defined 1
# 103 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long long int __int64_t;

typedef long long unsigned int __uint64_t;



#define ___int64_t_defined 1
# 134 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef signed char __int_least8_t;

typedef unsigned char __uint_least8_t;



#define ___int_least8_t_defined 1
# 160 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef short int __int_least16_t;

typedef short unsigned int __uint_least16_t;



#define ___int_least16_t_defined 1
# 182 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long int __int_least32_t;

typedef long unsigned int __uint_least32_t;



#define ___int_least32_t_defined 1
# 200 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long long int __int_least64_t;

typedef long long unsigned int __uint_least64_t;



#define ___int_least64_t_defined 1







typedef long long int __intmax_t;







typedef long long unsigned int __uintmax_t;







typedef int __intptr_t;

typedef unsigned int __uintptr_t;
# 244 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3 4
#undef __EXP
# 46 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 2 3 4

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 39 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#define _STDDEF_H 
#define _STDDEF_H_ 

#define _ANSI_STDDEF_H 
# 131 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#define _PTRDIFF_T 
#define _T_PTRDIFF_ 
#define _T_PTRDIFF 
#define __PTRDIFF_T 
#define _PTRDIFF_T_ 
#define _BSD_PTRDIFF_T_ 
#define ___int_ptrdiff_t_h 
#define _GCC_PTRDIFF_T 
#define _PTRDIFF_T_DECLARED 



typedef int ptrdiff_t;
# 155 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_ptrdiff_t
# 181 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#define __size_t__ 
#define __SIZE_T__ 
#define _SIZE_T 
#define _SYS_SIZE_T_H 
#define _T_SIZE_ 
#define _T_SIZE 
#define __SIZE_T 
#define _SIZE_T_ 
#define _BSD_SIZE_T_ 
#define _SIZE_T_DEFINED_ 
#define _SIZE_T_DEFINED 
#define _BSD_SIZE_T_DEFINED_ 
#define _SIZE_T_DECLARED 
#define ___int_size_t_h 
#define _GCC_SIZE_T 
#define _SIZET_ 






#define __size_t 





typedef unsigned int size_t;
# 231 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_size_t
# 260 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#define __wchar_t__ 
#define __WCHAR_T__ 
#define _WCHAR_T 
#define _T_WCHAR_ 
#define _T_WCHAR 
#define __WCHAR_T 
#define _WCHAR_T_ 
#define _BSD_WCHAR_T_ 
#define _WCHAR_T_DEFINED_ 
#define _WCHAR_T_DEFINED 
#define _WCHAR_T_H 
#define ___int_wchar_t_h 
#define __INT_WCHAR_T_H 
#define _GCC_WCHAR_T 
#define _WCHAR_T_DECLARED 
# 287 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef _BSD_WCHAR_T_
# 321 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
typedef unsigned int wchar_t;
# 340 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_wchar_t
# 390 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef NULL




#define NULL ((void *)0)





#undef __need_NULL




#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)
# 48 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 2 3 4

#define __PMT(args) args
#define __DOTS , ...
#define __THROW 


#define __ASMNAME(cname) __XSTRING (__USER_LABEL_PREFIX__) cname


#define __ptr_t void *
#define __long_double_t long double

#define __attribute_malloc__ 
#define __attribute_pure__ 
#define __attribute_format_strfmon__(a,b) 
#define __flexarr [0]


#define __bounded 
#define __unbounded 
#define __ptrvalue 
# 78 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3 4
#define __has_extension __has_feature


#define __has_feature(x) 0
# 94 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3 4
#define __BEGIN_DECLS 
#define __END_DECLS 
# 107 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3 4
#define __GNUCLIKE_ASM 3
#define __GNUCLIKE_MATH_BUILTIN_CONSTANTS 



#define __GNUCLIKE___TYPEOF 1
#define __GNUCLIKE___OFFSETOF 1
#define __GNUCLIKE___SECTION 1


#define __GNUCLIKE_CTOR_SECTION_HANDLING 1


#define __GNUCLIKE_BUILTIN_CONSTANT_P 1






#define __GNUCLIKE_BUILTIN_VARARGS 1
#define __GNUCLIKE_BUILTIN_STDARG 1
#define __GNUCLIKE_BUILTIN_VAALIST 1



#define __GNUC_VA_LIST_COMPATIBILITY 1






#define __compiler_membar() __asm __volatile(" " : : : "memory")



#define __GNUCLIKE_BUILTIN_NEXT_ARG 1
#define __GNUCLIKE_MATH_BUILTIN_RELOPS 


#define __GNUCLIKE_BUILTIN_MEMCPY 1


#define __CC_SUPPORTS_INLINE 1
#define __CC_SUPPORTS___INLINE 1
#define __CC_SUPPORTS___INLINE__ 1

#define __CC_SUPPORTS___FUNC__ 1
#define __CC_SUPPORTS_WARNING 1

#define __CC_SUPPORTS_VARADIC_XXX 1

#define __CC_SUPPORTS_DYNAMIC_ARRAY_INIT 1
# 177 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3 4
#define __P(protos) protos
#define __CONCAT1(x,y) x ## y
#define __CONCAT(x,y) __CONCAT1(x,y)
#define __STRING(x) #x
#define __XSTRING(x) __STRING(x)

#define __const const
#define __signed signed
#define __volatile volatile
# 230 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3 4
#define __weak_symbol __attribute__((__weak__))
# 243 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3 4
#define __dead2 __attribute__((__noreturn__))
#define __pure2 __attribute__((__const__))
#define __unused __attribute__((__unused__))
#define __used __attribute__((__used__))
#define __packed __attribute__((__packed__))
#define __aligned(x) __attribute__((__aligned__(x)))
#define __section(x) __attribute__((__section__(x)))


#define __alloc_size(x) __attribute__((__alloc_size__(x)))
#define __alloc_size2(n,x) __attribute__((__alloc_size__(n, x)))





#define __alloc_align(x) __attribute__((__alloc_align__(x)))
# 280 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3 4
#define _Alignas(x) __aligned(x)






#define _Alignof(x) __alignof(x)
# 296 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3 4
#define _Atomic(T) struct { T volatile __val; }





#define _Noreturn __dead2
# 331 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3 4
#define _Thread_local __thread
# 351 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3 4
#define __generic(expr,t,yes,no) __builtin_choose_expr( __builtin_types_compatible_p(__typeof(expr), t), yes, no)
# 366 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3 4
#define __min_size(x) static (x)





#define __malloc_like __attribute__((__malloc__))
#define __pure __attribute__((__pure__))






#define __always_inline __inline__ __attribute__((__always_inline__))





#define __noinline __attribute__ ((__noinline__))





#define __nonnull(x) __attribute__((__nonnull__ x))
#define __nonnull_all __attribute__((__nonnull__))






#define __fastcall __attribute__((__fastcall__))
#define __result_use_check __attribute__((__warn_unused_result__))






#define __returns_twice __attribute__((__returns_twice__))





#define __unreachable() __builtin_unreachable()
# 434 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3 4
#define __restrict restrict
# 467 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3 4
#define __predict_true(exp) __builtin_expect((exp), 1)
#define __predict_false(exp) __builtin_expect((exp), 0)






#define __null_sentinel __attribute__((__sentinel__))
#define __exported __attribute__((__visibility__("default")))


#define __hidden __attribute__((__visibility__("hidden")))
# 489 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3 4
#define __offsetof(type,field) offsetof(type, field)
#define __rangeof(type,start,end) (__offsetof(type, end) - __offsetof(type, start))
# 500 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3 4
#define __containerof(x,s,m) ({ const volatile __typeof(((s *)0)->m) *__x = (x); __DEQUALIFY(s *, (const volatile char *)__x - __offsetof(s, m));})
# 522 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3 4
#define __printflike(fmtarg,firstvararg) __attribute__((__format__ (__printf__, fmtarg, firstvararg)))

#define __scanflike(fmtarg,firstvararg) __attribute__((__format__ (__scanf__, fmtarg, firstvararg)))

#define __format_arg(fmtarg) __attribute__((__format_arg__ (fmtarg)))
#define __strfmonlike(fmtarg,firstvararg) __attribute__((__format__ (__strfmon__, fmtarg, firstvararg)))

#define __strftimelike(fmtarg,firstvararg) __attribute__((__format__ (__strftime__, fmtarg, firstvararg)))
# 539 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3 4
#define __printf0like(fmtarg,firstvararg) 




#define __strong_reference(sym,aliassym) extern __typeof (sym) aliassym __attribute__ ((__alias__ (#sym)))




#define __weak_reference(sym,alias) __asm__(".weak " #alias); __asm__(".equ " #alias ", " #sym)


#define __warn_references(sym,msg) __asm__(".section .gnu.warning." #sym); __asm__(".asciz \"" msg "\""); __asm__(".previous")



#define __sym_compat(sym,impl,verid) __asm__(".symver " #impl ", " #sym "@" #verid)

#define __sym_default(sym,impl,verid) __asm__(".symver " #impl ", " #sym "@@" #verid)
# 593 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3 4
#define __FBSDID(s) struct __hack



#define __RCSID(s) struct __hack



#define __RCSID_SOURCE(s) struct __hack



#define __SCCSID(s) struct __hack



#define __COPYRIGHT(s) struct __hack



#define __DECONST(type,var) ((type)(__uintptr_t)(const void *)(var))



#define __DEVOLATILE(type,var) ((type)(__uintptr_t)(volatile void *)(var))



#define __DEQUALIFY(type,var) ((type)(__uintptr_t)(const volatile void *)(var))






#define _Nonnull 
#define _Nullable 
#define _Null_unspecified 
#define __NULLABILITY_PRAGMA_PUSH 
#define __NULLABILITY_PRAGMA_POP 
# 653 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3 4
#define __arg_type_tag(arg_kind,arg_idx,type_tag_idx) 
#define __datatype_type_tag(kind,type) 
# 672 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3 4
#define __lock_annotate(x) 





#define __lockable __lock_annotate(lockable)


#define __locks_exclusive(...) __lock_annotate(exclusive_lock_function(__VA_ARGS__))

#define __locks_shared(...) __lock_annotate(shared_lock_function(__VA_ARGS__))



#define __trylocks_exclusive(...) __lock_annotate(exclusive_trylock_function(__VA_ARGS__))

#define __trylocks_shared(...) __lock_annotate(shared_trylock_function(__VA_ARGS__))



#define __unlocks(...) __lock_annotate(unlock_function(__VA_ARGS__))


#define __asserts_exclusive(...) __lock_annotate(assert_exclusive_lock(__VA_ARGS__))

#define __asserts_shared(...) __lock_annotate(assert_shared_lock(__VA_ARGS__))



#define __requires_exclusive(...) __lock_annotate(exclusive_locks_required(__VA_ARGS__))

#define __requires_shared(...) __lock_annotate(shared_locks_required(__VA_ARGS__))

#define __requires_unlocked(...) __lock_annotate(locks_excluded(__VA_ARGS__))



#define __no_lock_analysis __lock_annotate(no_thread_safety_analysis)


#define __guarded_by(x) __lock_annotate(guarded_by(x))
#define __pt_guarded_by(x) __lock_annotate(pt_guarded_by(x))
# 6 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/limits.h" 2 3 4
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/syslimits.h" 1 3 4
# 38 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/syslimits.h" 3 4
#define _SYS_SYSLIMITS_H_ 

#define ARG_MAX 65536

#define CHILD_MAX 40

#define LINK_MAX 32767
#define MAX_CANON 255
#define MAX_INPUT 255
#define NAME_MAX 255
#define NGROUPS_MAX 16

#define OPEN_MAX 64

#define PATH_MAX 1024
#define PIPE_BUF 512
#define IOV_MAX 1024

#define BC_BASE_MAX 99
#define BC_DIM_MAX 2048
#define BC_SCALE_MAX 99
#define BC_STRING_MAX 1000
#define COLL_WEIGHTS_MAX 0
#define EXPR_NEST_MAX 32
#define LINE_MAX 2048
#define RE_DUP_MAX 255
# 7 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/limits.h" 2 3 4


#define MB_LEN_MAX _MB_LEN_MAX






#define NL_ARGMAX 32
# 138 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/limits.h" 3 4
#define _POSIX2_RE_DUP_MAX 255
# 196 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include-fixed/limits.h" 2 3 4
# 8 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include-fixed/syslimits.h" 2 3 4
#undef _GCC_NEXT_LIMITS_H
# 35 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include-fixed/limits.h" 2 3 4
# 60 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include-fixed/limits.h" 3 4
#define _LIMITS_H___ 


#undef CHAR_BIT
#define CHAR_BIT __CHAR_BIT__







#undef SCHAR_MIN
#define SCHAR_MIN (-SCHAR_MAX - 1)
#undef SCHAR_MAX
#define SCHAR_MAX __SCHAR_MAX__


#undef UCHAR_MAX



#define UCHAR_MAX (SCHAR_MAX * 2 + 1)




#undef CHAR_MIN



#define CHAR_MIN 0

#undef CHAR_MAX
#define CHAR_MAX UCHAR_MAX
# 103 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include-fixed/limits.h" 3 4
#undef SHRT_MIN
#define SHRT_MIN (-SHRT_MAX - 1)
#undef SHRT_MAX
#define SHRT_MAX __SHRT_MAX__


#undef USHRT_MAX



#define USHRT_MAX (SHRT_MAX * 2 + 1)



#undef INT_MIN
#define INT_MIN (-INT_MAX - 1)
#undef INT_MAX
#define INT_MAX __INT_MAX__


#undef UINT_MAX
#define UINT_MAX (INT_MAX * 2U + 1U)



#undef LONG_MIN
#define LONG_MIN (-LONG_MAX - 1L)
#undef LONG_MAX
#define LONG_MAX __LONG_MAX__


#undef ULONG_MAX
#define ULONG_MAX (LONG_MAX * 2UL + 1UL)



#undef LLONG_MIN
#define LLONG_MIN (-LLONG_MAX - 1LL)
#undef LLONG_MAX
#define LLONG_MAX __LONG_LONG_MAX__


#undef ULLONG_MAX
#define ULLONG_MAX (LLONG_MAX * 2ULL + 1ULL)
# 37 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/check_config.h" 2
# 583 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/check_config.h"
#undef MBEDTLS_THREADING_IMPL
# 626 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/check_config.h"

# 626 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/check_config.h"
typedef int mbedtls_iso_c_forbids_empty_translation_units;
# 2599 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h" 2
# 30 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c" 2






# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 1 3







#define _STRING_H_ 

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_ansi.h" 1 3







#define _ANSIDECL_H_ 


# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/config.h" 1 3

#define __SYS_CONFIG_H__ 

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/ieeefp.h" 1 3
# 77 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/ieeefp.h" 3
#define __IEEE_LITTLE_ENDIAN 
# 473 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/ieeefp.h" 3
#define __OBSOLETE_MATH_DEFAULT 1


#define __OBSOLETE_MATH __OBSOLETE_MATH_DEFAULT
# 5 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/config.h" 2 3
# 224 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/config.h" 3
#define _POINTER_INT long





#undef __RAND_MAX



#define __RAND_MAX 0x7fffffff
# 250 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/config.h" 3
#define __EXPORT 



#define __IMPORT 






#define _READ_WRITE_RETURN_TYPE int





#define _READ_WRITE_BUFSIZE_TYPE int
# 12 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_ansi.h" 2 3
# 31 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_ansi.h" 3
#define _BEGIN_STD_C 
#define _END_STD_C 
#define _NOTHROW 



#define _LONG_DOUBLE long double





#define _ATTRIBUTE(attrs) __attribute__ (attrs)
# 69 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_ansi.h" 3
#define _ELIDABLE_INLINE static __inline__



#define _NOINLINE __attribute__ ((__noinline__))
#define _NOINLINE_STATIC _NOINLINE static
# 11 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 2 3
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 1 3
# 11 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
#define _SYS_REENT_H_ 

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_ansi.h" 1 3
# 14 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 2 3
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 15 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 2 3
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 1 3
# 20 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 3
#define _SYS__TYPES_H 

#define __need_size_t 
#define __need_wint_t 
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 155 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_ptrdiff_t
# 231 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_size_t
# 340 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_wchar_t




#define _WINT_T 





# 350 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
typedef unsigned int wint_t;

#undef __need_wint_t
# 390 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef NULL




#define NULL ((void *)0)





#undef __need_NULL




#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)
# 25 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 2 3


# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_types.h" 1 3





#define _MACHINE__TYPES_H 
# 28 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 2 3


typedef long __blkcnt_t;



typedef long __blksize_t;



typedef __uint64_t __fsblkcnt_t;



typedef __uint32_t __fsfilcnt_t;



typedef long _off_t;





typedef int __pid_t;



typedef short __dev_t;



typedef unsigned short __uid_t;


typedef unsigned short __gid_t;



typedef __uint32_t __id_t;







typedef unsigned short __ino_t;
# 90 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 3
typedef __uint32_t __mode_t;





__extension__ typedef long long _off64_t;





typedef _off_t __off_t;


typedef _off64_t __loff_t;


typedef long __key_t;







typedef long _fpos_t;
# 127 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 3
#undef __size_t



typedef unsigned int __size_t;
# 146 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 3
#define unsigned signed
typedef signed int _ssize_t;
#undef unsigned
# 158 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 3
typedef _ssize_t __ssize_t;



typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    unsigned char __wchb[4];
  } __value;
} _mbstate_t;




typedef void *_iconv_t;



#define _CLOCK_T_ unsigned long


typedef unsigned long __clock_t;




#define _TIME_T_ __int_least64_t

typedef __int_least64_t __time_t;


#define _CLOCKID_T_ unsigned long


typedef unsigned long __clockid_t;

#define _TIMER_T_ unsigned long
typedef unsigned long __timer_t;


typedef __uint8_t __sa_family_t;



typedef __uint32_t __socklen_t;


typedef int __nl_item;
typedef unsigned short __nlink_t;
typedef long __suseconds_t;
typedef unsigned long __useconds_t;







typedef __builtin_va_list __va_list;
# 16 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 2 3

#define _NULL 0



#define __Long long
typedef unsigned long __ULong;
# 34 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/lock.h" 1 3

#define __SYS_LOCK_H__ 
# 33 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/lock.h" 3
struct __lock;
typedef struct __lock * _LOCK_T;
#define _LOCK_RECURSIVE_T _LOCK_T

#define __LOCK_INIT(class,lock) extern struct __lock __lock_ ## lock; class _LOCK_T lock = &__lock_ ## lock

#define __LOCK_INIT_RECURSIVE(class,lock) __LOCK_INIT(class,lock)

extern void __retarget_lock_init(_LOCK_T *lock);
#define __lock_init(lock) __retarget_lock_init(&lock)
extern void __retarget_lock_init_recursive(_LOCK_T *lock);
#define __lock_init_recursive(lock) __retarget_lock_init_recursive(&lock)
extern void __retarget_lock_close(_LOCK_T lock);
#define __lock_close(lock) __retarget_lock_close(lock)
extern void __retarget_lock_close_recursive(_LOCK_T lock);
#define __lock_close_recursive(lock) __retarget_lock_close_recursive(lock)
extern void __retarget_lock_acquire(_LOCK_T lock);
#define __lock_acquire(lock) __retarget_lock_acquire(lock)
extern void __retarget_lock_acquire_recursive(_LOCK_T lock);
#define __lock_acquire_recursive(lock) __retarget_lock_acquire_recursive(lock)
extern int __retarget_lock_try_acquire(_LOCK_T lock);
#define __lock_try_acquire(lock) __retarget_lock_try_acquire(lock)
extern int __retarget_lock_try_acquire_recursive(_LOCK_T lock);
#define __lock_try_acquire_recursive(lock) __retarget_lock_try_acquire_recursive(lock)

extern void __retarget_lock_release(_LOCK_T lock);
#define __lock_release(lock) __retarget_lock_release(lock)
extern void __retarget_lock_release_recursive(_LOCK_T lock);
#define __lock_release_recursive(lock) __retarget_lock_release_recursive(lock)
# 35 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 2 3
typedef _LOCK_T _flock_t;







struct _reent;

struct __locale_t;






struct _Bigint
{
  struct _Bigint *_next;
  int _k, _maxwds, _sign, _wds;
  __ULong _x[1];
};


struct __tm
{
  int __tm_sec;
  int __tm_min;
  int __tm_hour;
  int __tm_mday;
  int __tm_mon;
  int __tm_year;
  int __tm_wday;
  int __tm_yday;
  int __tm_isdst;
};





#define _ATEXIT_SIZE 32

struct _on_exit_args {
 void * _fnargs[32];
 void * _dso_handle[32];

 __ULong _fntypes;


 __ULong _is_cxa;
};
# 98 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
struct _atexit {
 struct _atexit *_next;
 int _ind;

 void (*_fns[32])(void);
        struct _on_exit_args _on_exit_args;
};
#define _ATEXIT_INIT {_NULL, 0, {_NULL}, {{_NULL}, {_NULL}, 0, 0}}





#define _REENT_INIT_ATEXIT _NULL, _ATEXIT_INIT,
# 122 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
struct __sbuf {
 unsigned char *_base;
 int _size;
};
# 183 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
#define _REENT_SMALL_CHECK_INIT(ptr) 


struct __sFILE {
  unsigned char *_p;
  int _r;
  int _w;
  short _flags;
  short _file;
  struct __sbuf _bf;
  int _lbfsize;






  void * _cookie;

  int (*_read) (struct _reent *, void *,
        char *, int);
  int (*_write) (struct _reent *, void *,
         const char *,
         int);
  _fpos_t (*_seek) (struct _reent *, void *, _fpos_t, int);
  int (*_close) (struct _reent *, void *);


  struct __sbuf _ub;
  unsigned char *_up;
  int _ur;


  unsigned char _ubuf[3];
  unsigned char _nbuf[1];


  struct __sbuf _lb;


  int _blksize;
  _off_t _offset;


  struct _reent *_data;



  _flock_t _lock;

  _mbstate_t _mbstate;
  int _flags2;
};
# 292 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
typedef struct __sFILE __FILE;



struct _glue
{
  struct _glue *_next;
  int _niobs;
  __FILE *_iobs;
};
# 317 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
#define _RAND48_SEED_0 (0x330e)
#define _RAND48_SEED_1 (0xabcd)
#define _RAND48_SEED_2 (0x1234)
#define _RAND48_MULT_0 (0xe66d)
#define _RAND48_MULT_1 (0xdeec)
#define _RAND48_MULT_2 (0x0005)
#define _RAND48_ADD (0x000b)
struct _rand48 {
  unsigned short _seed[3];
  unsigned short _mult[3];
  unsigned short _add;




};


#define _REENT_EMERGENCY_SIZE 25
#define _REENT_ASCTIME_SIZE 26
#define _REENT_SIGNAL_SIZE 24
# 613 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
struct _reent
{
  int _errno;




  __FILE *_stdin, *_stdout, *_stderr;

  int _inc;
  char _emergency[25];


  int _unspecified_locale_info;
  struct __locale_t *_locale;

  int __sdidinit;

  void (*__cleanup) (struct _reent *);


  struct _Bigint *_result;
  int _result_k;
  struct _Bigint *_p5s;
  struct _Bigint **_freelist;


  int _cvtlen;
  char *_cvtbuf;

  union
    {
      struct
        {
          unsigned int _unused_rand;
          char * _strtok_last;
          char _asctime_buf[26];
          struct __tm _localtime_buf;
          int _gamma_signgam;
          __extension__ unsigned long long _rand_next;
          struct _rand48 _r48;
          _mbstate_t _mblen_state;
          _mbstate_t _mbtowc_state;
          _mbstate_t _wctomb_state;
          char _l64a_buf[8];
          char _signal_buf[24];
          int _getdate_err;
          _mbstate_t _mbrlen_state;
          _mbstate_t _mbrtowc_state;
          _mbstate_t _mbsrtowcs_state;
          _mbstate_t _wcrtomb_state;
          _mbstate_t _wcsrtombs_state;
   int _h_errno;
        } _reent;



      struct
        {
#define _N_LISTS 30
          unsigned char * _nextf[30];
          unsigned int _nmalloc[30];
        } _unused;
    } _new;



  struct _atexit *_atexit;
  struct _atexit _atexit0;



  void (**(_sig_func))(int);




  struct _glue __sglue;

  __FILE __sf[3];

};





#define _REENT_STDIO_STREAM(var,index) &(var)->__sf[index]


#define _REENT_INIT(var) { 0, _REENT_STDIO_STREAM(&(var), 0), _REENT_STDIO_STREAM(&(var), 1), _REENT_STDIO_STREAM(&(var), 2), 0, "", 0, _NULL, 0, _NULL, _NULL, 0, _NULL, _NULL, 0, _NULL, { { 0, _NULL, "", {0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 1, { {_RAND48_SEED_0, _RAND48_SEED_1, _RAND48_SEED_2}, {_RAND48_MULT_0, _RAND48_MULT_1, _RAND48_MULT_2}, _RAND48_ADD }, {0, {0}}, {0, {0}}, {0, {0}}, "", "", 0, {0, {0}}, {0, {0}}, {0, {0}}, {0, {0}}, {0, {0}} } }, _REENT_INIT_ATEXIT _NULL, {_NULL, 0, _NULL} }
# 751 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
#define _REENT_INIT_PTR_ZEROED(var) { (var)->_stdin = _REENT_STDIO_STREAM(var, 0); (var)->_stdout = _REENT_STDIO_STREAM(var, 1); (var)->_stderr = _REENT_STDIO_STREAM(var, 2); (var)->_new._reent._rand_next = 1; (var)->_new._reent._r48._seed[0] = _RAND48_SEED_0; (var)->_new._reent._r48._seed[1] = _RAND48_SEED_1; (var)->_new._reent._r48._seed[2] = _RAND48_SEED_2; (var)->_new._reent._r48._mult[0] = _RAND48_MULT_0; (var)->_new._reent._r48._mult[1] = _RAND48_MULT_1; (var)->_new._reent._r48._mult[2] = _RAND48_MULT_2; (var)->_new._reent._r48._add = _RAND48_ADD; }
# 765 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
#define _REENT_CHECK_RAND48(ptr) 
#define _REENT_CHECK_MP(ptr) 
#define _REENT_CHECK_TM(ptr) 
#define _REENT_CHECK_ASCTIME_BUF(ptr) 
#define _REENT_CHECK_EMERGENCY(ptr) 
#define _REENT_CHECK_MISC(ptr) 
#define _REENT_CHECK_SIGNAL_BUF(ptr) 

#define _REENT_SIGNGAM(ptr) ((ptr)->_new._reent._gamma_signgam)
#define _REENT_RAND_NEXT(ptr) ((ptr)->_new._reent._rand_next)
#define _REENT_RAND48_SEED(ptr) ((ptr)->_new._reent._r48._seed)
#define _REENT_RAND48_MULT(ptr) ((ptr)->_new._reent._r48._mult)
#define _REENT_RAND48_ADD(ptr) ((ptr)->_new._reent._r48._add)
#define _REENT_MP_RESULT(ptr) ((ptr)->_result)
#define _REENT_MP_RESULT_K(ptr) ((ptr)->_result_k)
#define _REENT_MP_P5S(ptr) ((ptr)->_p5s)
#define _REENT_MP_FREELIST(ptr) ((ptr)->_freelist)
#define _REENT_ASCTIME_BUF(ptr) ((ptr)->_new._reent._asctime_buf)
#define _REENT_TM(ptr) (&(ptr)->_new._reent._localtime_buf)
#define _REENT_EMERGENCY(ptr) ((ptr)->_emergency)
#define _REENT_STRTOK_LAST(ptr) ((ptr)->_new._reent._strtok_last)
#define _REENT_MBLEN_STATE(ptr) ((ptr)->_new._reent._mblen_state)
#define _REENT_MBTOWC_STATE(ptr) ((ptr)->_new._reent._mbtowc_state)
#define _REENT_WCTOMB_STATE(ptr) ((ptr)->_new._reent._wctomb_state)
#define _REENT_MBRLEN_STATE(ptr) ((ptr)->_new._reent._mbrlen_state)
#define _REENT_MBRTOWC_STATE(ptr) ((ptr)->_new._reent._mbrtowc_state)
#define _REENT_MBSRTOWCS_STATE(ptr) ((ptr)->_new._reent._mbsrtowcs_state)
#define _REENT_WCRTOMB_STATE(ptr) ((ptr)->_new._reent._wcrtomb_state)
#define _REENT_WCSRTOMBS_STATE(ptr) ((ptr)->_new._reent._wcsrtombs_state)
#define _REENT_L64A_BUF(ptr) ((ptr)->_new._reent._l64a_buf)
#define _REENT_SIGNAL_BUF(ptr) ((ptr)->_new._reent._signal_buf)
#define _REENT_GETDATE_ERR_P(ptr) (&((ptr)->_new._reent._getdate_err))



#define _REENT_INIT_PTR(var) { memset((var), 0, sizeof(*(var))); _REENT_INIT_PTR_ZEROED(var); }







#define _Kmax (sizeof (size_t) << 3)







#define __ATTRIBUTE_IMPURE_PTR__ 


extern struct _reent *_impure_ptr ;
extern struct _reent *const _global_impure_ptr ;

void _reclaim_reent (struct _reent *);
# 832 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
#define _REENT _impure_ptr


#define _GLOBAL_REENT _global_impure_ptr





#define _GLOBAL_ATEXIT (_GLOBAL_REENT->_atexit)
# 12 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 2 3



#define __need_size_t 
#define __need_NULL 
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 155 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_ptrdiff_t
# 231 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_size_t
# 340 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_wchar_t
# 390 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef NULL




#define NULL ((void *)0)





#undef __need_NULL




#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)
# 18 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 2 3
# 27 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 3


void * memchr (const void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void * memcpy (void *restrict, const void *restrict, size_t);
void * memmove (void *, const void *, size_t);
void * memset (void *, int, size_t);
char *strcat (char *restrict, const char *restrict);
char *strchr (const char *, int);
int strcmp (const char *, const char *);
int strcoll (const char *, const char *);
char *strcpy (char *restrict, const char *restrict);
size_t strcspn (const char *, const char *);
char *strerror (int);
size_t strlen (const char *);
char *strncat (char *restrict, const char *restrict, size_t);
int strncmp (const char *, const char *, size_t);
char *strncpy (char *restrict, const char *restrict, size_t);
char *strpbrk (const char *, const char *);
char *strrchr (const char *, int);
size_t strspn (const char *, const char *);
char *strstr (const char *, const char *);

char *strtok (char *restrict, const char *restrict);

size_t strxfrm (char *restrict, const char *restrict, size_t);
# 86 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 3
char *_strdup_r (struct _reent *, const char *);



char *_strndup_r (struct _reent *, const char *, size_t);
# 112 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 3
char * _strerror_r (struct _reent *, int, int, int *);
# 134 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 3
char *strsignal (int __signo);
# 175 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 3
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/string.h" 1 3
# 176 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 2 3


# 37 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c" 2

# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/aes.h" 1
# 24 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/aes.h"
#define MBEDTLS_AES_H 


# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/config.h" 1
# 28 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/aes.h" 2




# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 33 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/aes.h" 2
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdint.h" 1 3 4
# 9 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdint.h" 3 4
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 1 3 4
# 10 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define _STDINT_H 


# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 1 3 4
# 10 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define _SYS__INTSUP_H 





#define __STDINT_EXP(x) __ ##x ##__
# 35 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
       
       
       
       
       
       
       
       
#undef signed
#undef unsigned
#undef char
#undef short
#undef int
#undef __int20
#undef __int20__
#undef long
#define signed +0
#define unsigned +0
#define char +0
#define short +1
#define __int20 +2
#define __int20__ +2
#define int +2
#define long +4
# 67 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define _INTPTR_EQ_INT 






#define _INT32_EQ_LONG 







#define __INT8 "hh"
# 93 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __INT16 "h"
# 104 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __INT32 "l"
# 113 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __INT64 "ll"






#define __FAST8 
# 129 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __FAST16 






#define __FAST32 
# 147 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __FAST64 "ll"



#define __LEAST8 "hh"
# 162 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __LEAST16 "h"
# 173 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __LEAST32 "l"
# 182 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __LEAST64 "ll"

#undef signed
#undef unsigned
#undef char
#undef short
#undef int
#undef long
       
       
       
       
       
# 194 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#undef __int20
       
# 195 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#undef __int20__
       
       
# 14 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 2 3 4
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_stdint.h" 1 3 4
# 10 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_stdint.h" 3 4
#define _SYS__STDINT_H 
# 20 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_stdint.h" 3 4
typedef __int8_t int8_t ;
#define _INT8_T_DECLARED 


typedef __uint8_t uint8_t ;
#define _UINT8_T_DECLARED 

#define __int8_t_defined 1




typedef __int16_t int16_t ;
#define _INT16_T_DECLARED 


typedef __uint16_t uint16_t ;
#define _UINT16_T_DECLARED 

#define __int16_t_defined 1




typedef __int32_t int32_t ;
#define _INT32_T_DECLARED 


typedef __uint32_t uint32_t ;
#define _UINT32_T_DECLARED 

#define __int32_t_defined 1




typedef __int64_t int64_t ;
#define _INT64_T_DECLARED 


typedef __uint64_t uint64_t ;
#define _UINT64_T_DECLARED 

#define __int64_t_defined 1



typedef __intmax_t intmax_t;
#define _INTMAX_T_DECLARED 



typedef __uintmax_t uintmax_t;
#define _UINTMAX_T_DECLARED 



typedef __intptr_t intptr_t;
#define _INTPTR_T_DECLARED 



typedef __uintptr_t uintptr_t;
#define _UINTPTR_T_DECLARED 
# 15 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 2 3 4






typedef __int_least8_t int_least8_t;
typedef __uint_least8_t uint_least8_t;
#define __int_least8_t_defined 1



typedef __int_least16_t int_least16_t;
typedef __uint_least16_t uint_least16_t;
#define __int_least16_t_defined 1



typedef __int_least32_t int_least32_t;
typedef __uint_least32_t uint_least32_t;
#define __int_least32_t_defined 1



typedef __int_least64_t int_least64_t;
typedef __uint_least64_t uint_least64_t;
#define __int_least64_t_defined 1
# 51 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
  typedef int int_fast8_t;
  typedef unsigned int uint_fast8_t;
#define __int_fast8_t_defined 1







  typedef int int_fast16_t;
  typedef unsigned int uint_fast16_t;
#define __int_fast16_t_defined 1







  typedef int int_fast32_t;
  typedef unsigned int uint_fast32_t;
#define __int_fast32_t_defined 1







  typedef long long int int_fast64_t;
  typedef long long unsigned int uint_fast64_t;
#define __int_fast64_t_defined 1
# 128 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INTPTR_MIN (-__INTPTR_MAX__ - 1)
#define INTPTR_MAX (__INTPTR_MAX__)
#define UINTPTR_MAX (__UINTPTR_MAX__)
# 152 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT8_MIN (-__INT8_MAX__ - 1)
#define INT8_MAX (__INT8_MAX__)
#define UINT8_MAX (__UINT8_MAX__)







#define INT_LEAST8_MIN (-__INT_LEAST8_MAX__ - 1)
#define INT_LEAST8_MAX (__INT_LEAST8_MAX__)
#define UINT_LEAST8_MAX (__UINT_LEAST8_MAX__)
# 174 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT16_MIN (-__INT16_MAX__ - 1)
#define INT16_MAX (__INT16_MAX__)
#define UINT16_MAX (__UINT16_MAX__)







#define INT_LEAST16_MIN (-__INT_LEAST16_MAX__ - 1)
#define INT_LEAST16_MAX (__INT_LEAST16_MAX__)
#define UINT_LEAST16_MAX (__UINT_LEAST16_MAX__)
# 196 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT32_MIN (-__INT32_MAX__ - 1)
#define INT32_MAX (__INT32_MAX__)
#define UINT32_MAX (__UINT32_MAX__)
# 212 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT_LEAST32_MIN (-__INT_LEAST32_MAX__ - 1)
#define INT_LEAST32_MAX (__INT_LEAST32_MAX__)
#define UINT_LEAST32_MAX (__UINT_LEAST32_MAX__)
# 230 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT64_MIN (-__INT64_MAX__ - 1)
#define INT64_MAX (__INT64_MAX__)
#define UINT64_MAX (__UINT64_MAX__)
# 246 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT_LEAST64_MIN (-__INT_LEAST64_MAX__ - 1)
#define INT_LEAST64_MAX (__INT_LEAST64_MAX__)
#define UINT_LEAST64_MAX (__UINT_LEAST64_MAX__)
# 262 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT_FAST8_MIN (-__INT_FAST8_MAX__ - 1)
#define INT_FAST8_MAX (__INT_FAST8_MAX__)
#define UINT_FAST8_MAX (__UINT_FAST8_MAX__)
# 278 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT_FAST16_MIN (-__INT_FAST16_MAX__ - 1)
#define INT_FAST16_MAX (__INT_FAST16_MAX__)
#define UINT_FAST16_MAX (__UINT_FAST16_MAX__)
# 294 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT_FAST32_MIN (-__INT_FAST32_MAX__ - 1)
#define INT_FAST32_MAX (__INT_FAST32_MAX__)
#define UINT_FAST32_MAX (__UINT_FAST32_MAX__)
# 310 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT_FAST64_MIN (-__INT_FAST64_MAX__ - 1)
#define INT_FAST64_MAX (__INT_FAST64_MAX__)
#define UINT_FAST64_MAX (__UINT_FAST64_MAX__)
# 326 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INTMAX_MAX (__INTMAX_MAX__)
#define INTMAX_MIN (-INTMAX_MAX - 1)







#define UINTMAX_MAX (__UINTMAX_MAX__)







#define SIZE_MAX (__SIZE_MAX__)





#define SIG_ATOMIC_MIN (-__STDINT_EXP(INT_MAX) - 1)
#define SIG_ATOMIC_MAX (__STDINT_EXP(INT_MAX))



#define PTRDIFF_MAX (__PTRDIFF_MAX__)



#define PTRDIFF_MIN (-PTRDIFF_MAX - 1)




#define WCHAR_MIN (__WCHAR_MIN__)
# 374 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define WCHAR_MAX (__WCHAR_MAX__)
# 384 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define WINT_MAX (__WINT_MAX__)




#define WINT_MIN (__WINT_MIN__)






#define INT8_C(x) __INT8_C(x)
#define UINT8_C(x) __UINT8_C(x)
# 408 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT16_C(x) __INT16_C(x)
#define UINT16_C(x) __UINT16_C(x)
# 420 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT32_C(x) __INT32_C(x)
#define UINT32_C(x) __UINT32_C(x)
# 433 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT64_C(x) __INT64_C(x)
#define UINT64_C(x) __UINT64_C(x)
# 449 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INTMAX_C(x) __INTMAX_C(x)
#define UINTMAX_C(x) __UINTMAX_C(x)
# 10 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdint.h" 2 3 4



#define _GCC_WRAP_STDINT_H 
# 34 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/aes.h" 2


#define MBEDTLS_AES_ENCRYPT 1
#define MBEDTLS_AES_DECRYPT 0

#define MBEDTLS_ERR_AES_INVALID_KEY_LENGTH -0x0020
#define MBEDTLS_ERR_AES_INVALID_INPUT_LENGTH -0x0022
# 58 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/aes.h"

# 58 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/aes.h"
typedef struct
{
    int nr;
    uint32_t *rk;
    uint32_t buf[68];
}
mbedtls_aes_context;






void mbedtls_aes_init( mbedtls_aes_context *ctx );






void mbedtls_aes_free( mbedtls_aes_context *ctx );
# 89 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/aes.h"
int mbedtls_aes_setkey_enc( mbedtls_aes_context *ctx, const unsigned char *key,
                    unsigned int keybits );
# 101 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/aes.h"
int mbedtls_aes_setkey_dec( mbedtls_aes_context *ctx, const unsigned char *key,
                    unsigned int keybits );
# 114 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/aes.h"
int mbedtls_aes_crypt_ecb( mbedtls_aes_context *ctx,
                    int mode,
                    const unsigned char input[16],
                    unsigned char output[16] );
# 142 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/aes.h"
int mbedtls_aes_crypt_cbc( mbedtls_aes_context *ctx,
                    int mode,
                    size_t length,
                    unsigned char iv[16],
                    const unsigned char *input,
                    unsigned char *output );
# 176 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/aes.h"
int mbedtls_aes_crypt_cfb128( mbedtls_aes_context *ctx,
                       int mode,
                       size_t length,
                       size_t *iv_off,
                       unsigned char iv[16],
                       const unsigned char *input,
                       unsigned char *output );
# 208 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/aes.h"
int mbedtls_aes_crypt_cfb8( mbedtls_aes_context *ctx,
                    int mode,
                    size_t length,
                    unsigned char iv[16],
                    const unsigned char *input,
                    unsigned char *output );
# 239 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/aes.h"
int mbedtls_aes_crypt_ctr( mbedtls_aes_context *ctx,
                       size_t length,
                       size_t *nc_off,
                       unsigned char nonce_counter[16],
                       unsigned char stream_block[16],
                       const unsigned char *input,
                       unsigned char *output );
# 257 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/aes.h"
void mbedtls_aes_encrypt( mbedtls_aes_context *ctx,
                          const unsigned char input[16],
                          unsigned char output[16] );
# 270 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/aes.h"
void mbedtls_aes_decrypt( mbedtls_aes_context *ctx,
                          const unsigned char input[16],
                          unsigned char output[16] );
# 291 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/aes.h"
int mbedtls_aes_self_test( int verbose );
# 39 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c" 2

# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/padlock.h" 1
# 25 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/padlock.h"
#define MBEDTLS_PADLOCK_H 

# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/aes.h" 1
# 28 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/padlock.h" 2

#define MBEDTLS_ERR_PADLOCK_DATA_MISALIGNED -0x0030
# 41 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c" 2


# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/aesni.h" 1
# 24 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/aesni.h"
#define MBEDTLS_AESNI_H 



#define MBEDTLS_AESNI_AES 0x02000000u
#define MBEDTLS_AESNI_CLMUL 0x00000002u
# 44 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c" 2




# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/platform.h" 1
# 24 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/platform.h"
#define MBEDTLS_PLATFORM_H 
# 33 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/platform.h"
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/platform_time.h" 1
# 24 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/platform_time.h"
#define MBEDTLS_PLATFORM_TIME_H 
# 51 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/platform_time.h"
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/time.h" 1 3







#define _TIME_H_ 





#define __need_size_t 
#define __need_NULL 
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 155 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_ptrdiff_t
# 231 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_size_t
# 340 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_wchar_t
# 390 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef NULL




#define NULL ((void *)0)





#undef __need_NULL




#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)
# 17 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/time.h" 2 3


# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/time.h" 1 3

#define _MACHTIME_H_ 




#define _CLOCKS_PER_SEC_ 100
# 20 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/time.h" 2 3





#define CLOCKS_PER_SEC _CLOCKS_PER_SEC_
#define CLK_TCK CLOCKS_PER_SEC

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/types.h" 1 3
# 28 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/types.h" 3

# 28 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/types.h" 3
typedef __uint8_t u_int8_t;


typedef __uint16_t u_int16_t;


typedef __uint32_t u_int32_t;


typedef __uint64_t u_int64_t;

typedef __intptr_t register_t;
#define __BIT_TYPES_DEFINED__ 1



#define _SYS_TYPES_H 
# 97 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/types.h" 3
typedef __blkcnt_t blkcnt_t;
#define _BLKCNT_T_DECLARED 



typedef __blksize_t blksize_t;
#define _BLKSIZE_T_DECLARED 



typedef unsigned long clock_t;
#define __clock_t_defined 
#define _CLOCK_T_DECLARED 



typedef __int_least64_t time_t;
#define __time_t_defined 
#define _TIME_T_DECLARED 



typedef long daddr_t;
#define __daddr_t_defined 


typedef char * caddr_t;
#define __caddr_t_defined 



typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
#define _FSBLKCNT_T_DECLARED 



typedef __id_t id_t;
#define _ID_T_DECLARED 



typedef __ino_t ino_t;
#define _INO_T_DECLARED 
# 157 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/types.h" 3
typedef __off_t off_t;
#define _OFF_T_DECLARED 


typedef __dev_t dev_t;
#define _DEV_T_DECLARED 


typedef __uid_t uid_t;
#define _UID_T_DECLARED 


typedef __gid_t gid_t;
#define _GID_T_DECLARED 



typedef __pid_t pid_t;
#define _PID_T_DECLARED 



typedef __key_t key_t;
#define _KEY_T_DECLARED 



typedef _ssize_t ssize_t;
#define _SSIZE_T_DECLARED 



typedef __mode_t mode_t;
#define _MODE_T_DECLARED 



typedef __nlink_t nlink_t;
#define _NLINK_T_DECLARED 



typedef __clockid_t clockid_t;
#define __clockid_t_defined 
#define _CLOCKID_T_DECLARED 



typedef __timer_t timer_t;
#define __timer_t_defined 
#define _TIMER_T_DECLARED 



typedef __useconds_t useconds_t;
#define _USECONDS_T_DECLARED 



typedef __suseconds_t suseconds_t;
#define _SUSECONDS_T_DECLARED 


typedef __int64_t sbintime_t;


# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_pthreadtypes.h" 1 3
# 19 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_pthreadtypes.h" 3
#define _SYS__PTHREADTYPES_H_ 
# 224 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/types.h" 2 3
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/types.h" 1 3
# 225 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/types.h" 2 3



#undef __need_inttypes
# 29 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/time.h" 2 3
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/timespec.h" 1 3
# 35 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/timespec.h" 3
#define _SYS_TIMESPEC_H_ 


# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_timespec.h" 1 3
# 37 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_timespec.h" 3
#define _SYS__TIMESPEC_H_ 
# 47 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_timespec.h" 3
struct timespec {
 time_t tv_sec;
 long tv_nsec;
};
# 39 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/timespec.h" 2 3
# 58 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/timespec.h" 3
struct itimerspec {
 struct timespec it_interval;
 struct timespec it_value;
};
# 30 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/time.h" 2 3







struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;






};

clock_t clock (void);
double difftime (time_t _time2, time_t _time1);
time_t mktime (struct tm *_timeptr);
time_t time (time_t *_timer);

char *asctime (const struct tm *_tblock);
char *ctime (const time_t *_time);
struct tm *gmtime (const time_t *_timer);
struct tm *localtime (const time_t *_timer);

size_t strftime (char *restrict _s,
        size_t _maxsize, const char *restrict _fmt,
        const struct tm *restrict _t);







char *asctime_r (const struct tm *restrict,
     char *restrict);
char *ctime_r (const time_t *, char *);
struct tm *gmtime_r (const time_t *restrict,
     struct tm *restrict);
struct tm *localtime_r (const time_t *restrict,
     struct tm *restrict);


# 103 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/time.h" 3
void _tzset_r (struct _reent *);

typedef struct __tzrule_struct
{
  char ch;
  int m;
  int n;
  int d;
  int s;
  time_t change;
  long offset;
} __tzrule_type;

typedef struct __tzinfo_struct
{
  int __tznorth;
  int __tzyear;
  __tzrule_type __tzrule[2];
} __tzinfo_type;

__tzinfo_type *__gettzinfo (void);
# 240 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/time.h" 3
#define CLOCK_ENABLED 1
#define CLOCK_DISABLED 0



#define CLOCK_ALLOWED 1


#define CLOCK_DISALLOWED 0






#define TIMER_ABSTIME 4







#define CLOCK_REALTIME ((clockid_t) 1)
# 52 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/platform_time.h" 2

# 52 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/platform_time.h"
typedef time_t mbedtls_time_t;
# 73 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/platform_time.h"
#define mbedtls_time time
# 34 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/platform.h" 2
# 49 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/platform.h"
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdio.h" 1 3
# 27 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdio.h" 3
#define _STDIO_H_ 



#define _FSTDIO 

#define __need_size_t 
#define __need_NULL 

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 155 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_ptrdiff_t
# 231 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_size_t
# 340 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_wchar_t
# 390 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef NULL




#define NULL ((void *)0)





#undef __need_NULL




#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)
# 37 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdio.h" 2 3


#define __need___va_list 
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdarg.h" 1 3 4
# 34 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdarg.h" 3 4
#undef __need___va_list




#define __GNUC_VA_LIST 

# 40 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 41 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdio.h" 2 3
# 63 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdio.h" 3



typedef __FILE FILE;
#define __FILE_defined 





typedef _fpos_t fpos_t;





# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/stdio.h" 1 3

#define _NEWLIB_STDIO_H 
# 13 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/stdio.h" 3
#define _flockfile(fp) (((fp)->_flags & __SSTR) ? 0 : __lock_acquire_recursive((fp)->_lock))







#define _funlockfile(fp) (((fp)->_flags & __SSTR) ? 0 : __lock_release_recursive((fp)->_lock))
# 80 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdio.h" 2 3

#define __SLBF 0x0001
#define __SNBF 0x0002
#define __SRD 0x0004
#define __SWR 0x0008

#define __SRW 0x0010
#define __SEOF 0x0020
#define __SERR 0x0040
#define __SMBF 0x0080
#define __SAPP 0x0100
#define __SSTR 0x0200
#define __SOPT 0x0400
#define __SNPT 0x0800
#define __SOFF 0x1000
#define __SORD 0x2000



#define __SL64 0x8000


#define __SNLK 0x0001
#define __SWID 0x2000
# 114 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdio.h" 3
#define _IOFBF 0
#define _IOLBF 1
#define _IONBF 2

#define EOF (-1)




#define BUFSIZ 1024





#define FOPEN_MAX 20





#define FILENAME_MAX 1024





#define L_tmpnam FILENAME_MAX







#define SEEK_SET 0


#define SEEK_CUR 1


#define SEEK_END 2


#define TMP_MAX 26

#define stdin (_REENT->_stdin)
#define stdout (_REENT->_stdout)
#define stderr (_REENT->_stderr)

#define _stdin_r(x) ((x)->_stdin)
#define _stdout_r(x) ((x)->_stdout)
#define _stderr_r(x) ((x)->_stderr)







#define __VALIST __gnuc_va_list
# 186 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdio.h" 3
FILE * tmpfile (void);
char * tmpnam (char *);



int fclose (FILE *);
int fflush (FILE *);
FILE * freopen (const char *restrict, const char *restrict, FILE *restrict);
void setbuf (FILE *restrict, char *restrict);
int setvbuf (FILE *restrict, char *restrict, int, size_t);
int fprintf (FILE *restrict, const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 2, 3)));
int fscanf (FILE *restrict, const char *restrict, ...)
               __attribute__ ((__format__ (__scanf__, 2, 3)));
int printf (const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 1, 2)));
int scanf (const char *restrict, ...)
               __attribute__ ((__format__ (__scanf__, 1, 2)));
int sscanf (const char *restrict, const char *restrict, ...)
               __attribute__ ((__format__ (__scanf__, 2, 3)));
int vfprintf (FILE *restrict, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 2, 0)));
int vprintf (const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 1, 0)));
int vsprintf (char *restrict, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 2, 0)));
int fgetc (FILE *);
char * fgets (char *restrict, int, FILE *restrict);
int fputc (int, FILE *);
int fputs (const char *restrict, FILE *restrict);
int getc (FILE *);
int getchar (void);
char * gets (char *);
int putc (int, FILE *);
int putchar (int);
int puts (const char *);
int ungetc (int, FILE *);
size_t fread (void *restrict, size_t _size, size_t _n, FILE *restrict);
size_t fwrite (const void *restrict , size_t _size, size_t _n, FILE *);



int fgetpos (FILE *restrict, fpos_t *restrict);

int fseek (FILE *, long, int);



int fsetpos (FILE *, const fpos_t *);

long ftell ( FILE *);
void rewind (FILE *);
void clearerr (FILE *);
int feof (FILE *);
int ferror (FILE *);
void perror (const char *);

FILE * fopen (const char *restrict _name, const char *restrict _type);
int sprintf (char *restrict, const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 2, 3)));
int remove (const char *);
int rename (const char *, const char *);
# 266 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdio.h" 3
int snprintf (char *restrict, size_t, const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 3, 4)));
int vsnprintf (char *restrict, size_t, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 3, 0)));
int vfscanf (FILE *restrict, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__scanf__, 2, 0)));
int vscanf (const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__scanf__, 1, 0)));
int vsscanf (const char *restrict, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__scanf__, 2, 0)));
# 396 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdio.h" 3
int _asiprintf_r (struct _reent *, char **, const char *, ...)
               __attribute__ ((__format__ (__printf__, 3, 4)));
char * _asniprintf_r (struct _reent *, char *, size_t *, const char *, ...)
               __attribute__ ((__format__ (__printf__, 4, 5)));
char * _asnprintf_r (struct _reent *, char *restrict, size_t *restrict, const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 4, 5)));
int _asprintf_r (struct _reent *, char **restrict, const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 3, 4)));
int _diprintf_r (struct _reent *, int, const char *, ...)
               __attribute__ ((__format__ (__printf__, 3, 4)));
int _dprintf_r (struct _reent *, int, const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 3, 4)));
int _fclose_r (struct _reent *, FILE *);
int _fcloseall_r (struct _reent *);
FILE * _fdopen_r (struct _reent *, int, const char *);
int _fflush_r (struct _reent *, FILE *);
int _fgetc_r (struct _reent *, FILE *);
int _fgetc_unlocked_r (struct _reent *, FILE *);
char * _fgets_r (struct _reent *, char *restrict, int, FILE *restrict);
char * _fgets_unlocked_r (struct _reent *, char *restrict, int, FILE *restrict);




int _fgetpos_r (struct _reent *, FILE *, fpos_t *);
int _fsetpos_r (struct _reent *, FILE *, const fpos_t *);

int _fiprintf_r (struct _reent *, FILE *, const char *, ...)
               __attribute__ ((__format__ (__printf__, 3, 4)));
int _fiscanf_r (struct _reent *, FILE *, const char *, ...)
               __attribute__ ((__format__ (__scanf__, 3, 4)));
FILE * _fmemopen_r (struct _reent *, void *restrict, size_t, const char *restrict);
FILE * _fopen_r (struct _reent *, const char *restrict, const char *restrict);
FILE * _freopen_r (struct _reent *, const char *restrict, const char *restrict, FILE *restrict);
int _fprintf_r (struct _reent *, FILE *restrict, const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 3, 4)));
int _fpurge_r (struct _reent *, FILE *);
int _fputc_r (struct _reent *, int, FILE *);
int _fputc_unlocked_r (struct _reent *, int, FILE *);
int _fputs_r (struct _reent *, const char *restrict, FILE *restrict);
int _fputs_unlocked_r (struct _reent *, const char *restrict, FILE *restrict);
size_t _fread_r (struct _reent *, void *restrict, size_t _size, size_t _n, FILE *restrict);
size_t _fread_unlocked_r (struct _reent *, void *restrict, size_t _size, size_t _n, FILE *restrict);
int _fscanf_r (struct _reent *, FILE *restrict, const char *restrict, ...)
               __attribute__ ((__format__ (__scanf__, 3, 4)));
int _fseek_r (struct _reent *, FILE *, long, int);
int _fseeko_r (struct _reent *, FILE *, _off_t, int);
long _ftell_r (struct _reent *, FILE *);
_off_t _ftello_r (struct _reent *, FILE *);
void _rewind_r (struct _reent *, FILE *);
size_t _fwrite_r (struct _reent *, const void *restrict, size_t _size, size_t _n, FILE *restrict);
size_t _fwrite_unlocked_r (struct _reent *, const void *restrict, size_t _size, size_t _n, FILE *restrict);
int _getc_r (struct _reent *, FILE *);
int _getc_unlocked_r (struct _reent *, FILE *);
int _getchar_r (struct _reent *);
int _getchar_unlocked_r (struct _reent *);
char * _gets_r (struct _reent *, char *);
int _iprintf_r (struct _reent *, const char *, ...)
               __attribute__ ((__format__ (__printf__, 2, 3)));
int _iscanf_r (struct _reent *, const char *, ...)
               __attribute__ ((__format__ (__scanf__, 2, 3)));
FILE * _open_memstream_r (struct _reent *, char **, size_t *);
void _perror_r (struct _reent *, const char *);
int _printf_r (struct _reent *, const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 2, 3)));
int _putc_r (struct _reent *, int, FILE *);
int _putc_unlocked_r (struct _reent *, int, FILE *);
int _putchar_unlocked_r (struct _reent *, int);
int _putchar_r (struct _reent *, int);
int _puts_r (struct _reent *, const char *);
int _remove_r (struct _reent *, const char *);
int _rename_r (struct _reent *,
      const char *_old, const char *_new);
int _scanf_r (struct _reent *, const char *restrict, ...)
               __attribute__ ((__format__ (__scanf__, 2, 3)));
int _siprintf_r (struct _reent *, char *, const char *, ...)
               __attribute__ ((__format__ (__printf__, 3, 4)));
int _siscanf_r (struct _reent *, const char *, const char *, ...)
               __attribute__ ((__format__ (__scanf__, 3, 4)));
int _sniprintf_r (struct _reent *, char *, size_t, const char *, ...)
               __attribute__ ((__format__ (__printf__, 4, 5)));
int _snprintf_r (struct _reent *, char *restrict, size_t, const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 4, 5)));
int _sprintf_r (struct _reent *, char *restrict, const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 3, 4)));
int _sscanf_r (struct _reent *, const char *restrict, const char *restrict, ...)
               __attribute__ ((__format__ (__scanf__, 3, 4)));
char * _tempnam_r (struct _reent *, const char *, const char *);
FILE * _tmpfile_r (struct _reent *);
char * _tmpnam_r (struct _reent *, char *);
int _ungetc_r (struct _reent *, int, FILE *);
int _vasiprintf_r (struct _reent *, char **, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 3, 0)));
char * _vasniprintf_r (struct _reent*, char *, size_t *, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 4, 0)));
char * _vasnprintf_r (struct _reent*, char *, size_t *, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 4, 0)));
int _vasprintf_r (struct _reent *, char **, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 3, 0)));
int _vdiprintf_r (struct _reent *, int, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 3, 0)));
int _vdprintf_r (struct _reent *, int, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 3, 0)));
int _vfiprintf_r (struct _reent *, FILE *, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 3, 0)));
int _vfiscanf_r (struct _reent *, FILE *, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__scanf__, 3, 0)));
int _vfprintf_r (struct _reent *, FILE *restrict, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 3, 0)));
int _vfscanf_r (struct _reent *, FILE *restrict, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__scanf__, 3, 0)));
int _viprintf_r (struct _reent *, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 2, 0)));
int _viscanf_r (struct _reent *, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__scanf__, 2, 0)));
int _vprintf_r (struct _reent *, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 2, 0)));
int _vscanf_r (struct _reent *, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__scanf__, 2, 0)));
int _vsiprintf_r (struct _reent *, char *, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 3, 0)));
int _vsiscanf_r (struct _reent *, const char *, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__scanf__, 3, 0)));
int _vsniprintf_r (struct _reent *, char *, size_t, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 4, 0)));
int _vsnprintf_r (struct _reent *, char *restrict, size_t, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 4, 0)));
int _vsprintf_r (struct _reent *, char *restrict, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 3, 0)));
int _vsscanf_r (struct _reent *, const char *restrict, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__scanf__, 3, 0)));



int fpurge (FILE *);
ssize_t __getdelim (char **, size_t *, int, FILE *);
ssize_t __getline (char **, size_t *, FILE *);
# 577 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdio.h" 3
int __srget_r (struct _reent *, FILE *);
int __swbuf_r (struct _reent *, int, FILE *);
# 654 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdio.h" 3
#define __sgetc_raw_r(__ptr,__f) (--(__f)->_r < 0 ? __srget_r(__ptr, __f) : (int)(*(__f)->_p++))
# 683 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdio.h" 3
#define __sgetc_r(__ptr,__p) __sgetc_raw_r(__ptr, __p)



static __inline__ int __sputc_r(struct _reent *_ptr, int _c, FILE *_p) {




 if (--_p->_w >= 0 || (_p->_w >= _p->_lbfsize && (char)_c != '\n'))
  return (*_p->_p++ = _c);
 else
  return (__swbuf_r(_ptr, _c, _p));
}
# 719 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdio.h" 3
#define __sfeof(p) ((int)(((p)->_flags & __SEOF) != 0))
#define __sferror(p) ((int)(((p)->_flags & __SERR) != 0))
#define __sclearerr(p) ((void)((p)->_flags &= ~(__SERR|__SEOF)))
#define __sfileno(p) ((p)->_file)



#define feof(p) __sfeof(p)
#define ferror(p) __sferror(p)
#define clearerr(p) __sclearerr(p)
# 741 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdio.h" 3
static __inline int
_getchar_unlocked(void)
{
 struct _reent *_ptr;

 _ptr = _impure_ptr;
 return ((--(((_ptr)->_stdin))->_r < 0 ? __srget_r(_ptr, ((_ptr)->_stdin)) : (int)(*(((_ptr)->_stdin))->_p++)));
}

static __inline int
_putchar_unlocked(int _c)
{
 struct _reent *_ptr;

 _ptr = _impure_ptr;
 return (__sputc_r(_ptr, _c, ((_ptr)->_stdout)));
}
# 797 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdio.h" 3

# 50 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/platform.h" 2
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 1 3







#define _STDLIB_H_ 

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/ieeefp.h" 1 3
# 11 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 2 3


#define __need_size_t 
#define __need_wchar_t 
#define __need_NULL 
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 155 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_ptrdiff_t
# 231 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_size_t
# 340 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_wchar_t
# 390 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef NULL




#define NULL ((void *)0)





#undef __need_NULL




#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)
# 17 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 2 3



# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/stdlib.h" 1 3

#define _MACHSTDLIB_H_ 
# 21 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 2 3
# 33 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 3


typedef struct
{
  int quot;
  int rem;
} div_t;

typedef struct
{
  long quot;
  long rem;
} ldiv_t;


typedef struct
{
  long long int quot;
  long long int rem;
} lldiv_t;



#define __compar_fn_t_defined 
typedef int (*__compar_fn_t) (const void *, const void *);


#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#define RAND_MAX __RAND_MAX

int __locale_mb_cur_max (void);

#define MB_CUR_MAX __locale_mb_cur_max()

void abort (void) __attribute__ ((__noreturn__));
int abs (int);





int atexit (void (*__func)(void));
double atof (const char *__nptr);



int atoi (const char *__nptr);
int _atoi_r (struct _reent *, const char *__nptr);
long atol (const char *__nptr);
long _atol_r (struct _reent *, const char *__nptr);
void * bsearch (const void *__key,
         const void *__base,
         size_t __nmemb,
         size_t __size,
         __compar_fn_t _compar);
void *calloc(size_t, size_t) __attribute__((__malloc__)) __attribute__((__warn_unused_result__))
      __attribute__((__alloc_size__(1, 2))) ;
div_t div (int __numer, int __denom);
void exit (int __status) __attribute__ ((__noreturn__));
void free (void *) ;
char * getenv (const char *__string);
char * _getenv_r (struct _reent *, const char *__string);



char * _findenv (const char *, int *);
char * _findenv_r (struct _reent *, const char *, int *);




long labs (long);
ldiv_t ldiv (long __numer, long __denom);
void *malloc(size_t) __attribute__((__malloc__)) __attribute__((__warn_unused_result__)) __attribute__((__alloc_size__(1))) ;
int mblen (const char *, size_t);
int _mblen_r (struct _reent *, const char *, size_t, _mbstate_t *);
int mbtowc (wchar_t *restrict, const char *restrict, size_t);
int _mbtowc_r (struct _reent *, wchar_t *restrict, const char *restrict, size_t, _mbstate_t *);
int wctomb (char *, wchar_t);
int _wctomb_r (struct _reent *, char *, wchar_t, _mbstate_t *);
size_t mbstowcs (wchar_t *restrict, const char *restrict, size_t);
size_t _mbstowcs_r (struct _reent *, wchar_t *restrict, const char *restrict, size_t, _mbstate_t *);
size_t wcstombs (char *restrict, const wchar_t *restrict, size_t);
size_t _wcstombs_r (struct _reent *, char *restrict, const wchar_t *restrict, size_t, _mbstate_t *);
# 137 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 3
char * _mkdtemp_r (struct _reent *, char *);
int _mkostemp_r (struct _reent *, char *, int);
int _mkostemps_r (struct _reent *, char *, int, int);
int _mkstemp_r (struct _reent *, char *);
int _mkstemps_r (struct _reent *, char *, int);
char * _mktemp_r (struct _reent *, char *) __attribute__ ((__deprecated__("the use of `mktemp' is dangerous; use `mkstemp' instead")));
void qsort (void *__base, size_t __nmemb, size_t __size, __compar_fn_t _compar);
int rand (void);
void *realloc(void *, size_t) __attribute__((__warn_unused_result__)) __attribute__((__alloc_size__(2))) ;
# 159 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 3
void srand (unsigned __seed);
double strtod (const char *restrict __n, char **restrict __end_PTR);
double _strtod_r (struct _reent *,const char *restrict __n, char **restrict __end_PTR);

float strtof (const char *restrict __n, char **restrict __end_PTR);







long strtol (const char *restrict __n, char **restrict __end_PTR, int __base);
long _strtol_r (struct _reent *,const char *restrict __n, char **restrict __end_PTR, int __base);
unsigned long strtoul (const char *restrict __n, char **restrict __end_PTR, int __base);
unsigned long _strtoul_r (struct _reent *,const char *restrict __n, char **restrict __end_PTR, int __base);
# 191 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 3
int system (const char *__string);
# 202 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 3
void _Exit (int __status) __attribute__ ((__noreturn__));




int _putenv_r (struct _reent *, char *__string);
void * _reallocf_r (struct _reent *, void *, size_t);



int _setenv_r (struct _reent *, const char *__string, const char *__value, int __overwrite);
# 224 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 3
char * __itoa (int, char *, int);
char * __utoa (unsigned, char *, int);
# 263 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 3
long long atoll (const char *__nptr);

long long _atoll_r (struct _reent *, const char *__nptr);

long long llabs (long long);
lldiv_t lldiv (long long __numer, long long __denom);
long long strtoll (const char *restrict __n, char **restrict __end_PTR, int __base);

long long _strtoll_r (struct _reent *, const char *restrict __n, char **restrict __end_PTR, int __base);

unsigned long long strtoull (const char *restrict __n, char **restrict __end_PTR, int __base);

unsigned long long _strtoull_r (struct _reent *, const char *restrict __n, char **restrict __end_PTR, int __base);
# 284 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 3
int _unsetenv_r (struct _reent *, const char *__string);







char * _dtoa_r (struct _reent *, double, int, int, int *, int*, char**);

void * _malloc_r (struct _reent *, size_t) ;
void * _calloc_r (struct _reent *, size_t, size_t) ;
void _free_r (struct _reent *, void *) ;
void * _realloc_r (struct _reent *, void *, size_t) ;
void _mstats_r (struct _reent *, char *);

int _system_r (struct _reent *, const char *);

void __eprintf (const char *, const char *, unsigned int, const char *);
# 322 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 3
extern long double _strtold_r (struct _reent *, const char *restrict, char **restrict);

extern long double strtold (const char *restrict, char **restrict);
# 339 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 3

# 51 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/platform.h" 2





#define MBEDTLS_PLATFORM_STD_SNPRINTF snprintf



#define MBEDTLS_PLATFORM_STD_PRINTF printf


#define MBEDTLS_PLATFORM_STD_FPRINTF fprintf


#define MBEDTLS_PLATFORM_STD_CALLOC calloc


#define MBEDTLS_PLATFORM_STD_FREE free


#define MBEDTLS_PLATFORM_STD_EXIT exit


#define MBEDTLS_PLATFORM_STD_TIME time


#define MBEDTLS_PLATFORM_STD_EXIT_SUCCESS EXIT_SUCCESS


#define MBEDTLS_PLATFORM_STD_EXIT_FAILURE EXIT_FAILURE



#define MBEDTLS_PLATFORM_STD_NV_SEED_READ mbedtls_platform_std_nv_seed_read


#define MBEDTLS_PLATFORM_STD_NV_SEED_WRITE mbedtls_platform_std_nv_seed_write


#define MBEDTLS_PLATFORM_STD_NV_SEED_FILE "seedfile"
# 129 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/platform.h"
#define mbedtls_free free
#define mbedtls_calloc calloc
# 154 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/platform.h"
#define mbedtls_fprintf fprintf
# 176 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/platform.h"
#define mbedtls_printf printf
# 210 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/platform.h"
#define mbedtls_snprintf snprintf
# 232 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/include/mbedtls/platform.h"
#define mbedtls_exit exit







#define MBEDTLS_EXIT_SUCCESS MBEDTLS_PLATFORM_STD_EXIT_SUCCESS




#define MBEDTLS_EXIT_FAILURE MBEDTLS_PLATFORM_STD_EXIT_FAILURE
# 49 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c" 2
# 58 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c"

# 58 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c"
static void mbedtls_zeroize( void *v, size_t n ) {
    volatile unsigned char *p = (unsigned char*)v; while( n-- ) *p++ = 0;
}





#define GET_UINT32_LE(n,b,i) { (n) = ( (uint32_t) (b)[(i) ] ) | ( (uint32_t) (b)[(i) + 1] << 8 ) | ( (uint32_t) (b)[(i) + 2] << 16 ) | ( (uint32_t) (b)[(i) + 3] << 24 ); }
# 76 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c"
#define PUT_UINT32_LE(n,b,i) { (b)[(i) ] = (unsigned char) ( ( (n) ) & 0xFF ); (b)[(i) + 1] = (unsigned char) ( ( (n) >> 8 ) & 0xFF ); (b)[(i) + 2] = (unsigned char) ( ( (n) >> 16 ) & 0xFF ); (b)[(i) + 3] = (unsigned char) ( ( (n) >> 24 ) & 0xFF ); }
# 360 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c"
static unsigned char FSb[256];
static uint32_t FT0[256];
static uint32_t FT1[256];
static uint32_t FT2[256];
static uint32_t FT3[256];




static unsigned char RSb[256];
static uint32_t RT0[256];
static uint32_t RT1[256];
static uint32_t RT2[256];
static uint32_t RT3[256];




static uint32_t RCON[10];




#define ROTL8(x) ( ( x << 8 ) & 0xFFFFFFFF ) | ( x >> 24 )
#define XTIME(x) ( ( x << 1 ) ^ ( ( x & 0x80 ) ? 0x1B : 0x00 ) )
#define MUL(x,y) ( ( x && y ) ? pow[(log[x]+log[y]) % 255] : 0 )

static int aes_init_done = 0;

static void aes_gen_tables( void )
{
    int i, x, y, z;
    int pow[256];
    int log[256];




    for( i = 0, x = 1; i < 256; i++ )
    {
        pow[i] = x;
        log[x] = i;
        x = ( x ^ ( ( x << 1 ) ^ ( ( x & 0x80 ) ? 0x1B : 0x00 ) ) ) & 0xFF;
    }




    for( i = 0, x = 1; i < 10; i++ )
    {
        RCON[i] = (uint32_t) x;
        x = ( ( x << 1 ) ^ ( ( x & 0x80 ) ? 0x1B : 0x00 ) ) & 0xFF;
    }




    FSb[0x00] = 0x63;
    RSb[0x63] = 0x00;

    for( i = 1; i < 256; i++ )
    {
        x = pow[255 - log[i]];

        y = x; y = ( ( y << 1 ) | ( y >> 7 ) ) & 0xFF;
        x ^= y; y = ( ( y << 1 ) | ( y >> 7 ) ) & 0xFF;
        x ^= y; y = ( ( y << 1 ) | ( y >> 7 ) ) & 0xFF;
        x ^= y; y = ( ( y << 1 ) | ( y >> 7 ) ) & 0xFF;
        x ^= y ^ 0x63;

        FSb[i] = (unsigned char) x;
        RSb[x] = (unsigned char) i;
    }




    for( i = 0; i < 256; i++ )
    {
        x = FSb[i];
        y = ( ( x << 1 ) ^ ( ( x & 0x80 ) ? 0x1B : 0x00 ) ) & 0xFF;
        z = ( y ^ x ) & 0xFF;

        FT0[i] = ( (uint32_t) y ) ^
                 ( (uint32_t) x << 8 ) ^
                 ( (uint32_t) x << 16 ) ^
                 ( (uint32_t) z << 24 );

        FT1[i] = ( ( FT0[i] << 8 ) & 0xFFFFFFFF ) | ( FT0[i] >> 24 );
        FT2[i] = ( ( FT1[i] << 8 ) & 0xFFFFFFFF ) | ( FT1[i] >> 24 );
        FT3[i] = ( ( FT2[i] << 8 ) & 0xFFFFFFFF ) | ( FT2[i] >> 24 );

        x = RSb[i];

        RT0[i] = ( (uint32_t) ( ( 0x0E && x ) ? pow[(log[0x0E]+log[x]) % 255] : 0 ) ) ^
                 ( (uint32_t) ( ( 0x09 && x ) ? pow[(log[0x09]+log[x]) % 255] : 0 ) << 8 ) ^
                 ( (uint32_t) ( ( 0x0D && x ) ? pow[(log[0x0D]+log[x]) % 255] : 0 ) << 16 ) ^
                 ( (uint32_t) ( ( 0x0B && x ) ? pow[(log[0x0B]+log[x]) % 255] : 0 ) << 24 );

        RT1[i] = ( ( RT0[i] << 8 ) & 0xFFFFFFFF ) | ( RT0[i] >> 24 );
        RT2[i] = ( ( RT1[i] << 8 ) & 0xFFFFFFFF ) | ( RT1[i] >> 24 );
        RT3[i] = ( ( RT2[i] << 8 ) & 0xFFFFFFFF ) | ( RT2[i] >> 24 );
    }
}



void mbedtls_aes_init( mbedtls_aes_context *ctx )
{
    memset( ctx, 0, sizeof( mbedtls_aes_context ) );
}

void mbedtls_aes_free( mbedtls_aes_context *ctx )
{
    if( ctx == 
# 474 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c" 3 4
              ((void *)0) 
# 474 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c"
                   )
        return;

    mbedtls_zeroize( ctx, sizeof( mbedtls_aes_context ) );
}





int mbedtls_aes_setkey_enc( mbedtls_aes_context *ctx, const unsigned char *key,
                    unsigned int keybits )
{
    unsigned int i;
    uint32_t *RK;


    if( aes_init_done == 0 )
    {
        aes_gen_tables();
        aes_init_done = 1;

    }


    switch( keybits )
    {
        case 128: ctx->nr = 10; break;
        case 192: ctx->nr = 12; break;
        case 256: ctx->nr = 14; break;
        default : return( -0x0020 );
    }
# 515 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c"
    ctx->rk = RK = ctx->buf;






    for( i = 0; i < ( keybits >> 5 ); i++ )
    {
        { (RK[i]) = ( (uint32_t) (key)[(i << 2) ] ) | ( (uint32_t) (key)[(i << 2) + 1] << 8 ) | ( (uint32_t) (key)[(i << 2) + 2] << 16 ) | ( (uint32_t) (key)[(i << 2) + 3] << 24 ); };
    }

    switch( ctx->nr )
    {
        case 10:

            for( i = 0; i < 10; i++, RK += 4 )
            {
                RK[4] = RK[0] ^ RCON[i] ^
                ( (uint32_t) FSb[ ( RK[3] >> 8 ) & 0xFF ] ) ^
                ( (uint32_t) FSb[ ( RK[3] >> 16 ) & 0xFF ] << 8 ) ^
                ( (uint32_t) FSb[ ( RK[3] >> 24 ) & 0xFF ] << 16 ) ^
                ( (uint32_t) FSb[ ( RK[3] ) & 0xFF ] << 24 );

                RK[5] = RK[1] ^ RK[4];
                RK[6] = RK[2] ^ RK[5];
                RK[7] = RK[3] ^ RK[6];
            }
            break;

        case 12:

            for( i = 0; i < 8; i++, RK += 6 )
            {
                RK[6] = RK[0] ^ RCON[i] ^
                ( (uint32_t) FSb[ ( RK[5] >> 8 ) & 0xFF ] ) ^
                ( (uint32_t) FSb[ ( RK[5] >> 16 ) & 0xFF ] << 8 ) ^
                ( (uint32_t) FSb[ ( RK[5] >> 24 ) & 0xFF ] << 16 ) ^
                ( (uint32_t) FSb[ ( RK[5] ) & 0xFF ] << 24 );

                RK[7] = RK[1] ^ RK[6];
                RK[8] = RK[2] ^ RK[7];
                RK[9] = RK[3] ^ RK[8];
                RK[10] = RK[4] ^ RK[9];
                RK[11] = RK[5] ^ RK[10];
            }
            break;

        case 14:

            for( i = 0; i < 7; i++, RK += 8 )
            {
                RK[8] = RK[0] ^ RCON[i] ^
                ( (uint32_t) FSb[ ( RK[7] >> 8 ) & 0xFF ] ) ^
                ( (uint32_t) FSb[ ( RK[7] >> 16 ) & 0xFF ] << 8 ) ^
                ( (uint32_t) FSb[ ( RK[7] >> 24 ) & 0xFF ] << 16 ) ^
                ( (uint32_t) FSb[ ( RK[7] ) & 0xFF ] << 24 );

                RK[9] = RK[1] ^ RK[8];
                RK[10] = RK[2] ^ RK[9];
                RK[11] = RK[3] ^ RK[10];

                RK[12] = RK[4] ^
                ( (uint32_t) FSb[ ( RK[11] ) & 0xFF ] ) ^
                ( (uint32_t) FSb[ ( RK[11] >> 8 ) & 0xFF ] << 8 ) ^
                ( (uint32_t) FSb[ ( RK[11] >> 16 ) & 0xFF ] << 16 ) ^
                ( (uint32_t) FSb[ ( RK[11] >> 24 ) & 0xFF ] << 24 );

                RK[13] = RK[5] ^ RK[12];
                RK[14] = RK[6] ^ RK[13];
                RK[15] = RK[7] ^ RK[14];
            }
            break;
    }

    return( 0 );
}






int mbedtls_aes_setkey_dec( mbedtls_aes_context *ctx, const unsigned char *key,
                    unsigned int keybits )
{
    int i, j, ret;
    mbedtls_aes_context cty;
    uint32_t *RK;
    uint32_t *SK;

    mbedtls_aes_init( &cty );
# 616 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c"
    ctx->rk = RK = ctx->buf;


    if( ( ret = mbedtls_aes_setkey_enc( &cty, key, keybits ) ) != 0 )
        goto exit;

    ctx->nr = cty.nr;
# 633 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c"
    SK = cty.rk + cty.nr * 4;

    *RK++ = *SK++;
    *RK++ = *SK++;
    *RK++ = *SK++;
    *RK++ = *SK++;

    for( i = ctx->nr - 1, SK -= 8; i > 0; i--, SK -= 8 )
    {
        for( j = 0; j < 4; j++, SK++ )
        {
            *RK++ = RT0[ FSb[ ( *SK ) & 0xFF ] ] ^
                    RT1[ FSb[ ( *SK >> 8 ) & 0xFF ] ] ^
                    RT2[ FSb[ ( *SK >> 16 ) & 0xFF ] ] ^
                    RT3[ FSb[ ( *SK >> 24 ) & 0xFF ] ];
        }
    }

    *RK++ = *SK++;
    *RK++ = *SK++;
    *RK++ = *SK++;
    *RK++ = *SK++;

exit:
    mbedtls_aes_free( &cty );

    return( ret );
}


#define AES_FROUND(X0,X1,X2,X3,Y0,Y1,Y2,Y3) { X0 = *RK++ ^ FT0[ ( Y0 ) & 0xFF ] ^ FT1[ ( Y1 >> 8 ) & 0xFF ] ^ FT2[ ( Y2 >> 16 ) & 0xFF ] ^ FT3[ ( Y3 >> 24 ) & 0xFF ]; X1 = *RK++ ^ FT0[ ( Y1 ) & 0xFF ] ^ FT1[ ( Y2 >> 8 ) & 0xFF ] ^ FT2[ ( Y3 >> 16 ) & 0xFF ] ^ FT3[ ( Y0 >> 24 ) & 0xFF ]; X2 = *RK++ ^ FT0[ ( Y2 ) & 0xFF ] ^ FT1[ ( Y3 >> 8 ) & 0xFF ] ^ FT2[ ( Y0 >> 16 ) & 0xFF ] ^ FT3[ ( Y1 >> 24 ) & 0xFF ]; X3 = *RK++ ^ FT0[ ( Y3 ) & 0xFF ] ^ FT1[ ( Y0 >> 8 ) & 0xFF ] ^ FT2[ ( Y1 >> 16 ) & 0xFF ] ^ FT3[ ( Y2 >> 24 ) & 0xFF ]; }
# 686 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c"
#define AES_RROUND(X0,X1,X2,X3,Y0,Y1,Y2,Y3) { X0 = *RK++ ^ RT0[ ( Y0 ) & 0xFF ] ^ RT1[ ( Y3 >> 8 ) & 0xFF ] ^ RT2[ ( Y2 >> 16 ) & 0xFF ] ^ RT3[ ( Y1 >> 24 ) & 0xFF ]; X1 = *RK++ ^ RT0[ ( Y1 ) & 0xFF ] ^ RT1[ ( Y0 >> 8 ) & 0xFF ] ^ RT2[ ( Y3 >> 16 ) & 0xFF ] ^ RT3[ ( Y2 >> 24 ) & 0xFF ]; X2 = *RK++ ^ RT0[ ( Y2 ) & 0xFF ] ^ RT1[ ( Y1 >> 8 ) & 0xFF ] ^ RT2[ ( Y0 >> 16 ) & 0xFF ] ^ RT3[ ( Y3 >> 24 ) & 0xFF ]; X3 = *RK++ ^ RT0[ ( Y3 ) & 0xFF ] ^ RT1[ ( Y2 >> 8 ) & 0xFF ] ^ RT2[ ( Y1 >> 16 ) & 0xFF ] ^ RT3[ ( Y0 >> 24 ) & 0xFF ]; }
# 713 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c"
void mbedtls_aes_encrypt( mbedtls_aes_context *ctx,
                          const unsigned char input[16],
                          unsigned char output[16] )
{
    int i;
    uint32_t *RK, X0, X1, X2, X3, Y0, Y1, Y2, Y3;

    RK = ctx->rk;

    { (X0) = ( (uint32_t) (input)[(0) ] ) | ( (uint32_t) (input)[(0) + 1] << 8 ) | ( (uint32_t) (input)[(0) + 2] << 16 ) | ( (uint32_t) (input)[(0) + 3] << 24 ); }; X0 ^= *RK++;
    { (X1) = ( (uint32_t) (input)[(4) ] ) | ( (uint32_t) (input)[(4) + 1] << 8 ) | ( (uint32_t) (input)[(4) + 2] << 16 ) | ( (uint32_t) (input)[(4) + 3] << 24 ); }; X1 ^= *RK++;
    { (X2) = ( (uint32_t) (input)[(8) ] ) | ( (uint32_t) (input)[(8) + 1] << 8 ) | ( (uint32_t) (input)[(8) + 2] << 16 ) | ( (uint32_t) (input)[(8) + 3] << 24 ); }; X2 ^= *RK++;
    { (X3) = ( (uint32_t) (input)[(12) ] ) | ( (uint32_t) (input)[(12) + 1] << 8 ) | ( (uint32_t) (input)[(12) + 2] << 16 ) | ( (uint32_t) (input)[(12) + 3] << 24 ); }; X3 ^= *RK++;

    for( i = ( ctx->nr >> 1 ) - 1; i > 0; i-- )
    {
        { Y0 = *RK++ ^ FT0[ ( X0 ) & 0xFF ] ^ FT1[ ( X1 >> 8 ) & 0xFF ] ^ FT2[ ( X2 >> 16 ) & 0xFF ] ^ FT3[ ( X3 >> 24 ) & 0xFF ]; Y1 = *RK++ ^ FT0[ ( X1 ) & 0xFF ] ^ FT1[ ( X2 >> 8 ) & 0xFF ] ^ FT2[ ( X3 >> 16 ) & 0xFF ] ^ FT3[ ( X0 >> 24 ) & 0xFF ]; Y2 = *RK++ ^ FT0[ ( X2 ) & 0xFF ] ^ FT1[ ( X3 >> 8 ) & 0xFF ] ^ FT2[ ( X0 >> 16 ) & 0xFF ] ^ FT3[ ( X1 >> 24 ) & 0xFF ]; Y3 = *RK++ ^ FT0[ ( X3 ) & 0xFF ] ^ FT1[ ( X0 >> 8 ) & 0xFF ] ^ FT2[ ( X1 >> 16 ) & 0xFF ] ^ FT3[ ( X2 >> 24 ) & 0xFF ]; };
        { X0 = *RK++ ^ FT0[ ( Y0 ) & 0xFF ] ^ FT1[ ( Y1 >> 8 ) & 0xFF ] ^ FT2[ ( Y2 >> 16 ) & 0xFF ] ^ FT3[ ( Y3 >> 24 ) & 0xFF ]; X1 = *RK++ ^ FT0[ ( Y1 ) & 0xFF ] ^ FT1[ ( Y2 >> 8 ) & 0xFF ] ^ FT2[ ( Y3 >> 16 ) & 0xFF ] ^ FT3[ ( Y0 >> 24 ) & 0xFF ]; X2 = *RK++ ^ FT0[ ( Y2 ) & 0xFF ] ^ FT1[ ( Y3 >> 8 ) & 0xFF ] ^ FT2[ ( Y0 >> 16 ) & 0xFF ] ^ FT3[ ( Y1 >> 24 ) & 0xFF ]; X3 = *RK++ ^ FT0[ ( Y3 ) & 0xFF ] ^ FT1[ ( Y0 >> 8 ) & 0xFF ] ^ FT2[ ( Y1 >> 16 ) & 0xFF ] ^ FT3[ ( Y2 >> 24 ) & 0xFF ]; };
    }

    { Y0 = *RK++ ^ FT0[ ( X0 ) & 0xFF ] ^ FT1[ ( X1 >> 8 ) & 0xFF ] ^ FT2[ ( X2 >> 16 ) & 0xFF ] ^ FT3[ ( X3 >> 24 ) & 0xFF ]; Y1 = *RK++ ^ FT0[ ( X1 ) & 0xFF ] ^ FT1[ ( X2 >> 8 ) & 0xFF ] ^ FT2[ ( X3 >> 16 ) & 0xFF ] ^ FT3[ ( X0 >> 24 ) & 0xFF ]; Y2 = *RK++ ^ FT0[ ( X2 ) & 0xFF ] ^ FT1[ ( X3 >> 8 ) & 0xFF ] ^ FT2[ ( X0 >> 16 ) & 0xFF ] ^ FT3[ ( X1 >> 24 ) & 0xFF ]; Y3 = *RK++ ^ FT0[ ( X3 ) & 0xFF ] ^ FT1[ ( X0 >> 8 ) & 0xFF ] ^ FT2[ ( X1 >> 16 ) & 0xFF ] ^ FT3[ ( X2 >> 24 ) & 0xFF ]; };

    X0 = *RK++ ^
            ( (uint32_t) FSb[ ( Y0 ) & 0xFF ] ) ^
            ( (uint32_t) FSb[ ( Y1 >> 8 ) & 0xFF ] << 8 ) ^
            ( (uint32_t) FSb[ ( Y2 >> 16 ) & 0xFF ] << 16 ) ^
            ( (uint32_t) FSb[ ( Y3 >> 24 ) & 0xFF ] << 24 );

    X1 = *RK++ ^
            ( (uint32_t) FSb[ ( Y1 ) & 0xFF ] ) ^
            ( (uint32_t) FSb[ ( Y2 >> 8 ) & 0xFF ] << 8 ) ^
            ( (uint32_t) FSb[ ( Y3 >> 16 ) & 0xFF ] << 16 ) ^
            ( (uint32_t) FSb[ ( Y0 >> 24 ) & 0xFF ] << 24 );

    X2 = *RK++ ^
            ( (uint32_t) FSb[ ( Y2 ) & 0xFF ] ) ^
            ( (uint32_t) FSb[ ( Y3 >> 8 ) & 0xFF ] << 8 ) ^
            ( (uint32_t) FSb[ ( Y0 >> 16 ) & 0xFF ] << 16 ) ^
            ( (uint32_t) FSb[ ( Y1 >> 24 ) & 0xFF ] << 24 );

    X3 = *RK++ ^
            ( (uint32_t) FSb[ ( Y3 ) & 0xFF ] ) ^
            ( (uint32_t) FSb[ ( Y0 >> 8 ) & 0xFF ] << 8 ) ^
            ( (uint32_t) FSb[ ( Y1 >> 16 ) & 0xFF ] << 16 ) ^
            ( (uint32_t) FSb[ ( Y2 >> 24 ) & 0xFF ] << 24 );

    { (output)[(0) ] = (unsigned char) ( ( (X0) ) & 0xFF ); (output)[(0) + 1] = (unsigned char) ( ( (X0) >> 8 ) & 0xFF ); (output)[(0) + 2] = (unsigned char) ( ( (X0) >> 16 ) & 0xFF ); (output)[(0) + 3] = (unsigned char) ( ( (X0) >> 24 ) & 0xFF ); };
    { (output)[(4) ] = (unsigned char) ( ( (X1) ) & 0xFF ); (output)[(4) + 1] = (unsigned char) ( ( (X1) >> 8 ) & 0xFF ); (output)[(4) + 2] = (unsigned char) ( ( (X1) >> 16 ) & 0xFF ); (output)[(4) + 3] = (unsigned char) ( ( (X1) >> 24 ) & 0xFF ); };
    { (output)[(8) ] = (unsigned char) ( ( (X2) ) & 0xFF ); (output)[(8) + 1] = (unsigned char) ( ( (X2) >> 8 ) & 0xFF ); (output)[(8) + 2] = (unsigned char) ( ( (X2) >> 16 ) & 0xFF ); (output)[(8) + 3] = (unsigned char) ( ( (X2) >> 24 ) & 0xFF ); };
    { (output)[(12) ] = (unsigned char) ( ( (X3) ) & 0xFF ); (output)[(12) + 1] = (unsigned char) ( ( (X3) >> 8 ) & 0xFF ); (output)[(12) + 2] = (unsigned char) ( ( (X3) >> 16 ) & 0xFF ); (output)[(12) + 3] = (unsigned char) ( ( (X3) >> 24 ) & 0xFF ); };
}






void mbedtls_aes_decrypt( mbedtls_aes_context *ctx,
                          const unsigned char input[16],
                          unsigned char output[16] )
{
    int i;
    uint32_t *RK, X0, X1, X2, X3, Y0, Y1, Y2, Y3;

    RK = ctx->rk;

    { (X0) = ( (uint32_t) (input)[(0) ] ) | ( (uint32_t) (input)[(0) + 1] << 8 ) | ( (uint32_t) (input)[(0) + 2] << 16 ) | ( (uint32_t) (input)[(0) + 3] << 24 ); }; X0 ^= *RK++;
    { (X1) = ( (uint32_t) (input)[(4) ] ) | ( (uint32_t) (input)[(4) + 1] << 8 ) | ( (uint32_t) (input)[(4) + 2] << 16 ) | ( (uint32_t) (input)[(4) + 3] << 24 ); }; X1 ^= *RK++;
    { (X2) = ( (uint32_t) (input)[(8) ] ) | ( (uint32_t) (input)[(8) + 1] << 8 ) | ( (uint32_t) (input)[(8) + 2] << 16 ) | ( (uint32_t) (input)[(8) + 3] << 24 ); }; X2 ^= *RK++;
    { (X3) = ( (uint32_t) (input)[(12) ] ) | ( (uint32_t) (input)[(12) + 1] << 8 ) | ( (uint32_t) (input)[(12) + 2] << 16 ) | ( (uint32_t) (input)[(12) + 3] << 24 ); }; X3 ^= *RK++;

    for( i = ( ctx->nr >> 1 ) - 1; i > 0; i-- )
    {
        { Y0 = *RK++ ^ RT0[ ( X0 ) & 0xFF ] ^ RT1[ ( X3 >> 8 ) & 0xFF ] ^ RT2[ ( X2 >> 16 ) & 0xFF ] ^ RT3[ ( X1 >> 24 ) & 0xFF ]; Y1 = *RK++ ^ RT0[ ( X1 ) & 0xFF ] ^ RT1[ ( X0 >> 8 ) & 0xFF ] ^ RT2[ ( X3 >> 16 ) & 0xFF ] ^ RT3[ ( X2 >> 24 ) & 0xFF ]; Y2 = *RK++ ^ RT0[ ( X2 ) & 0xFF ] ^ RT1[ ( X1 >> 8 ) & 0xFF ] ^ RT2[ ( X0 >> 16 ) & 0xFF ] ^ RT3[ ( X3 >> 24 ) & 0xFF ]; Y3 = *RK++ ^ RT0[ ( X3 ) & 0xFF ] ^ RT1[ ( X2 >> 8 ) & 0xFF ] ^ RT2[ ( X1 >> 16 ) & 0xFF ] ^ RT3[ ( X0 >> 24 ) & 0xFF ]; };
        { X0 = *RK++ ^ RT0[ ( Y0 ) & 0xFF ] ^ RT1[ ( Y3 >> 8 ) & 0xFF ] ^ RT2[ ( Y2 >> 16 ) & 0xFF ] ^ RT3[ ( Y1 >> 24 ) & 0xFF ]; X1 = *RK++ ^ RT0[ ( Y1 ) & 0xFF ] ^ RT1[ ( Y0 >> 8 ) & 0xFF ] ^ RT2[ ( Y3 >> 16 ) & 0xFF ] ^ RT3[ ( Y2 >> 24 ) & 0xFF ]; X2 = *RK++ ^ RT0[ ( Y2 ) & 0xFF ] ^ RT1[ ( Y1 >> 8 ) & 0xFF ] ^ RT2[ ( Y0 >> 16 ) & 0xFF ] ^ RT3[ ( Y3 >> 24 ) & 0xFF ]; X3 = *RK++ ^ RT0[ ( Y3 ) & 0xFF ] ^ RT1[ ( Y2 >> 8 ) & 0xFF ] ^ RT2[ ( Y1 >> 16 ) & 0xFF ] ^ RT3[ ( Y0 >> 24 ) & 0xFF ]; };
    }

    { Y0 = *RK++ ^ RT0[ ( X0 ) & 0xFF ] ^ RT1[ ( X3 >> 8 ) & 0xFF ] ^ RT2[ ( X2 >> 16 ) & 0xFF ] ^ RT3[ ( X1 >> 24 ) & 0xFF ]; Y1 = *RK++ ^ RT0[ ( X1 ) & 0xFF ] ^ RT1[ ( X0 >> 8 ) & 0xFF ] ^ RT2[ ( X3 >> 16 ) & 0xFF ] ^ RT3[ ( X2 >> 24 ) & 0xFF ]; Y2 = *RK++ ^ RT0[ ( X2 ) & 0xFF ] ^ RT1[ ( X1 >> 8 ) & 0xFF ] ^ RT2[ ( X0 >> 16 ) & 0xFF ] ^ RT3[ ( X3 >> 24 ) & 0xFF ]; Y3 = *RK++ ^ RT0[ ( X3 ) & 0xFF ] ^ RT1[ ( X2 >> 8 ) & 0xFF ] ^ RT2[ ( X1 >> 16 ) & 0xFF ] ^ RT3[ ( X0 >> 24 ) & 0xFF ]; };

    X0 = *RK++ ^
            ( (uint32_t) RSb[ ( Y0 ) & 0xFF ] ) ^
            ( (uint32_t) RSb[ ( Y3 >> 8 ) & 0xFF ] << 8 ) ^
            ( (uint32_t) RSb[ ( Y2 >> 16 ) & 0xFF ] << 16 ) ^
            ( (uint32_t) RSb[ ( Y1 >> 24 ) & 0xFF ] << 24 );

    X1 = *RK++ ^
            ( (uint32_t) RSb[ ( Y1 ) & 0xFF ] ) ^
            ( (uint32_t) RSb[ ( Y0 >> 8 ) & 0xFF ] << 8 ) ^
            ( (uint32_t) RSb[ ( Y3 >> 16 ) & 0xFF ] << 16 ) ^
            ( (uint32_t) RSb[ ( Y2 >> 24 ) & 0xFF ] << 24 );

    X2 = *RK++ ^
            ( (uint32_t) RSb[ ( Y2 ) & 0xFF ] ) ^
            ( (uint32_t) RSb[ ( Y1 >> 8 ) & 0xFF ] << 8 ) ^
            ( (uint32_t) RSb[ ( Y0 >> 16 ) & 0xFF ] << 16 ) ^
            ( (uint32_t) RSb[ ( Y3 >> 24 ) & 0xFF ] << 24 );

    X3 = *RK++ ^
            ( (uint32_t) RSb[ ( Y3 ) & 0xFF ] ) ^
            ( (uint32_t) RSb[ ( Y2 >> 8 ) & 0xFF ] << 8 ) ^
            ( (uint32_t) RSb[ ( Y1 >> 16 ) & 0xFF ] << 16 ) ^
            ( (uint32_t) RSb[ ( Y0 >> 24 ) & 0xFF ] << 24 );

    { (output)[(0) ] = (unsigned char) ( ( (X0) ) & 0xFF ); (output)[(0) + 1] = (unsigned char) ( ( (X0) >> 8 ) & 0xFF ); (output)[(0) + 2] = (unsigned char) ( ( (X0) >> 16 ) & 0xFF ); (output)[(0) + 3] = (unsigned char) ( ( (X0) >> 24 ) & 0xFF ); };
    { (output)[(4) ] = (unsigned char) ( ( (X1) ) & 0xFF ); (output)[(4) + 1] = (unsigned char) ( ( (X1) >> 8 ) & 0xFF ); (output)[(4) + 2] = (unsigned char) ( ( (X1) >> 16 ) & 0xFF ); (output)[(4) + 3] = (unsigned char) ( ( (X1) >> 24 ) & 0xFF ); };
    { (output)[(8) ] = (unsigned char) ( ( (X2) ) & 0xFF ); (output)[(8) + 1] = (unsigned char) ( ( (X2) >> 8 ) & 0xFF ); (output)[(8) + 2] = (unsigned char) ( ( (X2) >> 16 ) & 0xFF ); (output)[(8) + 3] = (unsigned char) ( ( (X2) >> 24 ) & 0xFF ); };
    { (output)[(12) ] = (unsigned char) ( ( (X3) ) & 0xFF ); (output)[(12) + 1] = (unsigned char) ( ( (X3) >> 8 ) & 0xFF ); (output)[(12) + 2] = (unsigned char) ( ( (X3) >> 16 ) & 0xFF ); (output)[(12) + 3] = (unsigned char) ( ( (X3) >> 24 ) & 0xFF ); };
}





int mbedtls_aes_crypt_ecb( mbedtls_aes_context *ctx,
                    int mode,
                    const unsigned char input[16],
                    unsigned char output[16] )
{
# 848 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c"
    if( mode == 1 )
        mbedtls_aes_encrypt( ctx, input, output );
    else
        mbedtls_aes_decrypt( ctx, input, output );

    return( 0 );
}





int mbedtls_aes_crypt_cbc( mbedtls_aes_context *ctx,
                    int mode,
                    size_t length,
                    unsigned char iv[16],
                    const unsigned char *input,
                    unsigned char *output )
{
    int i;
    unsigned char temp[16];

    if( length % 16 )
        return( -0x0022 );
# 885 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c"
    if( mode == 0 )
    {
        while( length > 0 )
        {
            memcpy( temp, input, 16 );
            mbedtls_aes_crypt_ecb( ctx, mode, input, output );

            for( i = 0; i < 16; i++ )
                output[i] = (unsigned char)( output[i] ^ iv[i] );

            memcpy( iv, temp, 16 );

            input += 16;
            output += 16;
            length -= 16;
        }
    }
    else
    {
        while( length > 0 )
        {
            for( i = 0; i < 16; i++ )
                output[i] = (unsigned char)( input[i] ^ iv[i] );

            mbedtls_aes_crypt_ecb( ctx, mode, output, output );
            memcpy( iv, output, 16 );

            input += 16;
            output += 16;
            length -= 16;
        }
    }

    return( 0 );
}






int mbedtls_aes_crypt_cfb128( mbedtls_aes_context *ctx,
                       int mode,
                       size_t length,
                       size_t *iv_off,
                       unsigned char iv[16],
                       const unsigned char *input,
                       unsigned char *output )
{
    int c;
    size_t n = *iv_off;

    if( mode == 0 )
    {
        while( length-- )
        {
            if( n == 0 )
                mbedtls_aes_crypt_ecb( ctx, 1, iv, iv );

            c = *input++;
            *output++ = (unsigned char)( c ^ iv[n] );
            iv[n] = (unsigned char) c;

            n = ( n + 1 ) & 0x0F;
        }
    }
    else
    {
        while( length-- )
        {
            if( n == 0 )
                mbedtls_aes_crypt_ecb( ctx, 1, iv, iv );

            iv[n] = *output++ = (unsigned char)( iv[n] ^ *input++ );

            n = ( n + 1 ) & 0x0F;
        }
    }

    *iv_off = n;

    return( 0 );
}




int mbedtls_aes_crypt_cfb8( mbedtls_aes_context *ctx,
                       int mode,
                       size_t length,
                       unsigned char iv[16],
                       const unsigned char *input,
                       unsigned char *output )
{
    unsigned char c;
    unsigned char ov[17];

    while( length-- )
    {
        memcpy( ov, iv, 16 );
        mbedtls_aes_crypt_ecb( ctx, 1, iv, iv );

        if( mode == 0 )
            ov[16] = *input;

        c = *output++ = (unsigned char)( iv[0] ^ *input++ );

        if( mode == 1 )
            ov[16] = c;

        memcpy( iv, ov + 1, 16 );
    }

    return( 0 );
}






int mbedtls_aes_crypt_ctr( mbedtls_aes_context *ctx,
                       size_t length,
                       size_t *nc_off,
                       unsigned char nonce_counter[16],
                       unsigned char stream_block[16],
                       const unsigned char *input,
                       unsigned char *output )
{
    int c, i;
    size_t n = *nc_off;

    while( length-- )
    {
        if( n == 0 ) {
            mbedtls_aes_crypt_ecb( ctx, 1, nonce_counter, stream_block );

            for( i = 16; i > 0; i-- )
                if( ++nonce_counter[i - 1] != 0 )
                    break;
        }
        c = *input++;
        *output++ = (unsigned char)( c ^ stream_block[n] );

        n = ( n + 1 ) & 0x0F;
    }

    *nc_off = n;

    return( 0 );
}
# 1046 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c"
static const unsigned char aes_test_ecb_dec[3][16] =
{
    { 0x44, 0x41, 0x6A, 0xC2, 0xD1, 0xF5, 0x3C, 0x58,
      0x33, 0x03, 0x91, 0x7E, 0x6B, 0xE9, 0xEB, 0xE0 },
    { 0x48, 0xE3, 0x1E, 0x9E, 0x25, 0x67, 0x18, 0xF2,
      0x92, 0x29, 0x31, 0x9C, 0x19, 0xF1, 0x5B, 0xA4 },
    { 0x05, 0x8C, 0xCF, 0xFD, 0xBB, 0xCB, 0x38, 0x2D,
      0x1F, 0x6F, 0x56, 0x58, 0x5D, 0x8A, 0x4A, 0xDE }
};

static const unsigned char aes_test_ecb_enc[3][16] =
{
    { 0xC3, 0x4C, 0x05, 0x2C, 0xC0, 0xDA, 0x8D, 0x73,
      0x45, 0x1A, 0xFE, 0x5F, 0x03, 0xBE, 0x29, 0x7F },
    { 0xF3, 0xF6, 0x75, 0x2A, 0xE8, 0xD7, 0x83, 0x11,
      0x38, 0xF0, 0x41, 0x56, 0x06, 0x31, 0xB1, 0x14 },
    { 0x8B, 0x79, 0xEE, 0xCC, 0x93, 0xA0, 0xEE, 0x5D,
      0xFF, 0x30, 0xB4, 0xEA, 0x21, 0x63, 0x6D, 0xA4 }
};


static const unsigned char aes_test_cbc_dec[3][16] =
{
    { 0xFA, 0xCA, 0x37, 0xE0, 0xB0, 0xC8, 0x53, 0x73,
      0xDF, 0x70, 0x6E, 0x73, 0xF7, 0xC9, 0xAF, 0x86 },
    { 0x5D, 0xF6, 0x78, 0xDD, 0x17, 0xBA, 0x4E, 0x75,
      0xB6, 0x17, 0x68, 0xC6, 0xAD, 0xEF, 0x7C, 0x7B },
    { 0x48, 0x04, 0xE1, 0x81, 0x8F, 0xE6, 0x29, 0x75,
      0x19, 0xA3, 0xE8, 0x8C, 0x57, 0x31, 0x04, 0x13 }
};

static const unsigned char aes_test_cbc_enc[3][16] =
{
    { 0x8A, 0x05, 0xFC, 0x5E, 0x09, 0x5A, 0xF4, 0x84,
      0x8A, 0x08, 0xD3, 0x28, 0xD3, 0x68, 0x8E, 0x3D },
    { 0x7B, 0xD9, 0x66, 0xD5, 0x3A, 0xD8, 0xC1, 0xBB,
      0x85, 0xD2, 0xAD, 0xFA, 0xE8, 0x7B, 0xB1, 0x04 },
    { 0xFE, 0x3C, 0x53, 0x65, 0x3E, 0x2F, 0x45, 0xB5,
      0x6F, 0xCD, 0x88, 0xB2, 0xCC, 0x89, 0x8F, 0xF0 }
};
# 1094 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c"
static const unsigned char aes_test_cfb128_key[3][32] =
{
    { 0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6,
      0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C },
    { 0x8E, 0x73, 0xB0, 0xF7, 0xDA, 0x0E, 0x64, 0x52,
      0xC8, 0x10, 0xF3, 0x2B, 0x80, 0x90, 0x79, 0xE5,
      0x62, 0xF8, 0xEA, 0xD2, 0x52, 0x2C, 0x6B, 0x7B },
    { 0x60, 0x3D, 0xEB, 0x10, 0x15, 0xCA, 0x71, 0xBE,
      0x2B, 0x73, 0xAE, 0xF0, 0x85, 0x7D, 0x77, 0x81,
      0x1F, 0x35, 0x2C, 0x07, 0x3B, 0x61, 0x08, 0xD7,
      0x2D, 0x98, 0x10, 0xA3, 0x09, 0x14, 0xDF, 0xF4 }
};

static const unsigned char aes_test_cfb128_iv[16] =
{
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
};

static const unsigned char aes_test_cfb128_pt[64] =
{
    0x6B, 0xC1, 0xBE, 0xE2, 0x2E, 0x40, 0x9F, 0x96,
    0xE9, 0x3D, 0x7E, 0x11, 0x73, 0x93, 0x17, 0x2A,
    0xAE, 0x2D, 0x8A, 0x57, 0x1E, 0x03, 0xAC, 0x9C,
    0x9E, 0xB7, 0x6F, 0xAC, 0x45, 0xAF, 0x8E, 0x51,
    0x30, 0xC8, 0x1C, 0x46, 0xA3, 0x5C, 0xE4, 0x11,
    0xE5, 0xFB, 0xC1, 0x19, 0x1A, 0x0A, 0x52, 0xEF,
    0xF6, 0x9F, 0x24, 0x45, 0xDF, 0x4F, 0x9B, 0x17,
    0xAD, 0x2B, 0x41, 0x7B, 0xE6, 0x6C, 0x37, 0x10
};

static const unsigned char aes_test_cfb128_ct[3][64] =
{
    { 0x3B, 0x3F, 0xD9, 0x2E, 0xB7, 0x2D, 0xAD, 0x20,
      0x33, 0x34, 0x49, 0xF8, 0xE8, 0x3C, 0xFB, 0x4A,
      0xC8, 0xA6, 0x45, 0x37, 0xA0, 0xB3, 0xA9, 0x3F,
      0xCD, 0xE3, 0xCD, 0xAD, 0x9F, 0x1C, 0xE5, 0x8B,
      0x26, 0x75, 0x1F, 0x67, 0xA3, 0xCB, 0xB1, 0x40,
      0xB1, 0x80, 0x8C, 0xF1, 0x87, 0xA4, 0xF4, 0xDF,
      0xC0, 0x4B, 0x05, 0x35, 0x7C, 0x5D, 0x1C, 0x0E,
      0xEA, 0xC4, 0xC6, 0x6F, 0x9F, 0xF7, 0xF2, 0xE6 },
    { 0xCD, 0xC8, 0x0D, 0x6F, 0xDD, 0xF1, 0x8C, 0xAB,
      0x34, 0xC2, 0x59, 0x09, 0xC9, 0x9A, 0x41, 0x74,
      0x67, 0xCE, 0x7F, 0x7F, 0x81, 0x17, 0x36, 0x21,
      0x96, 0x1A, 0x2B, 0x70, 0x17, 0x1D, 0x3D, 0x7A,
      0x2E, 0x1E, 0x8A, 0x1D, 0xD5, 0x9B, 0x88, 0xB1,
      0xC8, 0xE6, 0x0F, 0xED, 0x1E, 0xFA, 0xC4, 0xC9,
      0xC0, 0x5F, 0x9F, 0x9C, 0xA9, 0x83, 0x4F, 0xA0,
      0x42, 0xAE, 0x8F, 0xBA, 0x58, 0x4B, 0x09, 0xFF },
    { 0xDC, 0x7E, 0x84, 0xBF, 0xDA, 0x79, 0x16, 0x4B,
      0x7E, 0xCD, 0x84, 0x86, 0x98, 0x5D, 0x38, 0x60,
      0x39, 0xFF, 0xED, 0x14, 0x3B, 0x28, 0xB1, 0xC8,
      0x32, 0x11, 0x3C, 0x63, 0x31, 0xE5, 0x40, 0x7B,
      0xDF, 0x10, 0x13, 0x24, 0x15, 0xE5, 0x4B, 0x92,
      0xA1, 0x3E, 0xD0, 0xA8, 0x26, 0x7A, 0xE2, 0xF9,
      0x75, 0xA3, 0x85, 0x74, 0x1A, 0xB9, 0xCE, 0xF8,
      0x20, 0x31, 0x62, 0x3D, 0x55, 0xB1, 0xE4, 0x71 }
};
# 1161 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/mbedtls-2.4.2/library/aes.c"
static const unsigned char aes_test_ctr_key[3][16] =
{
    { 0xAE, 0x68, 0x52, 0xF8, 0x12, 0x10, 0x67, 0xCC,
      0x4B, 0xF7, 0xA5, 0x76, 0x55, 0x77, 0xF3, 0x9E },
    { 0x7E, 0x24, 0x06, 0x78, 0x17, 0xFA, 0xE0, 0xD7,
      0x43, 0xD6, 0xCE, 0x1F, 0x32, 0x53, 0x91, 0x63 },
    { 0x76, 0x91, 0xBE, 0x03, 0x5E, 0x50, 0x20, 0xA8,
      0xAC, 0x6E, 0x61, 0x85, 0x29, 0xF9, 0xA0, 0xDC }
};

static const unsigned char aes_test_ctr_nonce_counter[3][16] =
{
    { 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 },
    { 0x00, 0x6C, 0xB6, 0xDB, 0xC0, 0x54, 0x3B, 0x59,
      0xDA, 0x48, 0xD9, 0x0B, 0x00, 0x00, 0x00, 0x01 },
    { 0x00, 0xE0, 0x01, 0x7B, 0x27, 0x77, 0x7F, 0x3F,
      0x4A, 0x17, 0x86, 0xF0, 0x00, 0x00, 0x00, 0x01 }
};

static const unsigned char aes_test_ctr_pt[3][48] =
{
    { 0x53, 0x69, 0x6E, 0x67, 0x6C, 0x65, 0x20, 0x62,
      0x6C, 0x6F, 0x63, 0x6B, 0x20, 0x6D, 0x73, 0x67 },

    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
      0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
      0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
      0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F },

    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
      0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
      0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
      0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
      0x20, 0x21, 0x22, 0x23 }
};

static const unsigned char aes_test_ctr_ct[3][48] =
{
    { 0xE4, 0x09, 0x5D, 0x4F, 0xB7, 0xA7, 0xB3, 0x79,
      0x2D, 0x61, 0x75, 0xA3, 0x26, 0x13, 0x11, 0xB8 },
    { 0x51, 0x04, 0xA1, 0x06, 0x16, 0x8A, 0x72, 0xD9,
      0x79, 0x0D, 0x41, 0xEE, 0x8E, 0xDA, 0xD3, 0x88,
      0xEB, 0x2E, 0x1E, 0xFC, 0x46, 0xDA, 0x57, 0xC8,
      0xFC, 0xE6, 0x30, 0xDF, 0x91, 0x41, 0xBE, 0x28 },
    { 0xC1, 0xCF, 0x48, 0xA8, 0x9F, 0x2F, 0xFD, 0xD9,
      0xCF, 0x46, 0x52, 0xE9, 0xEF, 0xDB, 0x72, 0xD7,
      0x45, 0x40, 0xA4, 0x2B, 0xDE, 0x6D, 0x78, 0x36,
      0xD5, 0x9A, 0x5C, 0xEA, 0xAE, 0xF3, 0x10, 0x53,
      0x25, 0xB2, 0x07, 0x2F }
};

static const int aes_test_ctr_len[3] =
    { 16, 32, 36 };





int mbedtls_aes_self_test( int verbose )
{
    int ret = 0, i, j, u, v;
    unsigned char key[32];
    unsigned char buf[64];

    unsigned char iv[16];


    unsigned char prv[16];


    size_t offset;


    int len;
    unsigned char nonce_counter[16];
    unsigned char stream_block[16];

    mbedtls_aes_context ctx;

    memset( key, 0, 32 );
    mbedtls_aes_init( &ctx );




    for( i = 0; i < 6; i++ )
    {
        u = i >> 1;
        v = i & 1;

        if( verbose != 0 )
            printf( "  AES-ECB-%3d (%s): ", 128 + u * 64,
                             ( v == 0 ) ? "dec" : "enc" );

        memset( buf, 0, 16 );

        if( v == 0 )
        {
            mbedtls_aes_setkey_dec( &ctx, key, 128 + u * 64 );

            for( j = 0; j < 10000; j++ )
                mbedtls_aes_crypt_ecb( &ctx, v, buf, buf );

            if( memcmp( buf, aes_test_ecb_dec[u], 16 ) != 0 )
            {
                if( verbose != 0 )
                    printf( "failed\n" );

                ret = 1;
                goto exit;
            }
        }
        else
        {
            mbedtls_aes_setkey_enc( &ctx, key, 128 + u * 64 );

            for( j = 0; j < 10000; j++ )
                mbedtls_aes_crypt_ecb( &ctx, v, buf, buf );

            if( memcmp( buf, aes_test_ecb_enc[u], 16 ) != 0 )
            {
                if( verbose != 0 )
                    printf( "failed\n" );

                ret = 1;
                goto exit;
            }
        }

        if( verbose != 0 )
            printf( "passed\n" );
    }

    if( verbose != 0 )
        printf( "\n" );





    for( i = 0; i < 6; i++ )
    {
        u = i >> 1;
        v = i & 1;

        if( verbose != 0 )
            printf( "  AES-CBC-%3d (%s): ", 128 + u * 64,
                             ( v == 0 ) ? "dec" : "enc" );

        memset( iv , 0, 16 );
        memset( prv, 0, 16 );
        memset( buf, 0, 16 );

        if( v == 0 )
        {
            mbedtls_aes_setkey_dec( &ctx, key, 128 + u * 64 );

            for( j = 0; j < 10000; j++ )
                mbedtls_aes_crypt_cbc( &ctx, v, 16, iv, buf, buf );

            if( memcmp( buf, aes_test_cbc_dec[u], 16 ) != 0 )
            {
                if( verbose != 0 )
                    printf( "failed\n" );

                ret = 1;
                goto exit;
            }
        }
        else
        {
            mbedtls_aes_setkey_enc( &ctx, key, 128 + u * 64 );

            for( j = 0; j < 10000; j++ )
            {
                unsigned char tmp[16];

                mbedtls_aes_crypt_cbc( &ctx, v, 16, iv, buf, buf );

                memcpy( tmp, prv, 16 );
                memcpy( prv, buf, 16 );
                memcpy( buf, tmp, 16 );
            }

            if( memcmp( prv, aes_test_cbc_enc[u], 16 ) != 0 )
            {
                if( verbose != 0 )
                    printf( "failed\n" );

                ret = 1;
                goto exit;
            }
        }

        if( verbose != 0 )
            printf( "passed\n" );
    }

    if( verbose != 0 )
        printf( "\n" );






    for( i = 0; i < 6; i++ )
    {
        u = i >> 1;
        v = i & 1;

        if( verbose != 0 )
            printf( "  AES-CFB128-%3d (%s): ", 128 + u * 64,
                             ( v == 0 ) ? "dec" : "enc" );

        memcpy( iv, aes_test_cfb128_iv, 16 );
        memcpy( key, aes_test_cfb128_key[u], 16 + u * 8 );

        offset = 0;
        mbedtls_aes_setkey_enc( &ctx, key, 128 + u * 64 );

        if( v == 0 )
        {
            memcpy( buf, aes_test_cfb128_ct[u], 64 );
            mbedtls_aes_crypt_cfb128( &ctx, v, 64, &offset, iv, buf, buf );

            if( memcmp( buf, aes_test_cfb128_pt, 64 ) != 0 )
            {
                if( verbose != 0 )
                    printf( "failed\n" );

                ret = 1;
                goto exit;
            }
        }
        else
        {
            memcpy( buf, aes_test_cfb128_pt, 64 );
            mbedtls_aes_crypt_cfb128( &ctx, v, 64, &offset, iv, buf, buf );

            if( memcmp( buf, aes_test_cfb128_ct[u], 64 ) != 0 )
            {
                if( verbose != 0 )
                    printf( "failed\n" );

                ret = 1;
                goto exit;
            }
        }

        if( verbose != 0 )
            printf( "passed\n" );
    }

    if( verbose != 0 )
        printf( "\n" );






    for( i = 0; i < 6; i++ )
    {
        u = i >> 1;
        v = i & 1;

        if( verbose != 0 )
            printf( "  AES-CTR-128 (%s): ",
                             ( v == 0 ) ? "dec" : "enc" );

        memcpy( nonce_counter, aes_test_ctr_nonce_counter[u], 16 );
        memcpy( key, aes_test_ctr_key[u], 16 );

        offset = 0;
        mbedtls_aes_setkey_enc( &ctx, key, 128 );

        if( v == 0 )
        {
            len = aes_test_ctr_len[u];
            memcpy( buf, aes_test_ctr_ct[u], len );

            mbedtls_aes_crypt_ctr( &ctx, len, &offset, nonce_counter, stream_block,
                           buf, buf );

            if( memcmp( buf, aes_test_ctr_pt[u], len ) != 0 )
            {
                if( verbose != 0 )
                    printf( "failed\n" );

                ret = 1;
                goto exit;
            }
        }
        else
        {
            len = aes_test_ctr_len[u];
            memcpy( buf, aes_test_ctr_pt[u], len );

            mbedtls_aes_crypt_ctr( &ctx, len, &offset, nonce_counter, stream_block,
                           buf, buf );

            if( memcmp( buf, aes_test_ctr_ct[u], len ) != 0 )
            {
                if( verbose != 0 )
                    printf( "failed\n" );

                ret = 1;
                goto exit;
            }
        }

        if( verbose != 0 )
            printf( "passed\n" );
    }

    if( verbose != 0 )
        printf( "\n" );


    ret = 0;

exit:
    mbedtls_aes_free( &ctx );

    return( ret );
}