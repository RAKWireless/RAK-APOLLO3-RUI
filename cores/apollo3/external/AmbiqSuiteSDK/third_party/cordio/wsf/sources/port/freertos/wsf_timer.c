# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
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
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
# 23 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_types.h" 1
# 23 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_types.h"
#define WSF_TYPES_H 






#define NULL 0



#define TRUE 1



#define FALSE 0
# 48 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_types.h"
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdint.h" 1 3 4
# 9 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdint.h" 3 4
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 1 3 4
# 10 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define _STDINT_H 

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 1 3 4





#define _MACHINE__DEFAULT_TYPES_H 

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 1 3 4
# 22 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3 4
#define _SYS_FEATURES_H 





# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_newlib_version.h" 1 3 4



#define _NEWLIB_VERSION_H__ 1

#define _NEWLIB_VERSION "3.3.0"
#define __NEWLIB__ 3
#define __NEWLIB_MINOR__ 3
#define __NEWLIB_PATCHLEVEL__ 0
# 29 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 2 3 4




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
# 13 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 2 3 4
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
# 49 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_types.h" 2
# 60 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_types.h"

# 60 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_types.h"
typedef uint8_t bool_t;
# 24 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_queue.h" 1
# 23 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_queue.h"
#define WSF_QUEUE_H 
# 34 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_queue.h"
#define WSF_QUEUE_INIT(pQueue) {(pQueue)->pHead = NULL; (pQueue)->pTail = NULL;}






typedef struct
{
  void *pHead;
  void *pTail;
} wsfQueue_t;
# 63 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_queue.h"
void WsfQueueEnq(wsfQueue_t *pQueue, void *pElem);
# 76 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_queue.h"
void *WsfQueueDeq(wsfQueue_t *pQueue);
# 90 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_queue.h"
void WsfQueuePush(wsfQueue_t *pQueue, void *pElem);
# 106 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_queue.h"
void WsfQueueInsert(wsfQueue_t *pQueue, void *pElem, void *pPrev);
# 122 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_queue.h"
void WsfQueueRemove(wsfQueue_t *pQueue, void *pElem, void *pPrev);
# 135 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_queue.h"
uint16_t WsfQueueCount(wsfQueue_t *pQueue);
# 148 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_queue.h"
bool_t WsfQueueEmpty(wsfQueue_t *pQueue);
# 25 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_timer.h" 1
# 23 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_timer.h"
#define WSF_TIMER_H 

# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_os.h" 1
# 23 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_os.h"
#define WSF_OS_H 

# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_os_int.h" 1
# 23 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_os_int.h"
#define WSF_OS_INT_H 
# 34 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_os_int.h"
#define WSF_MSG_QUEUE_EVENT 0x01
#define WSF_TIMER_EVENT 0x02
#define WSF_HANDLER_EVENT 0x04


#define WSF_TASK_FROM_ID(handlerID) (((handlerID) >> 4) & 0x0F)


#define WSF_HANDLER_FROM_ID(handlerID) ((handlerID) & 0x0F)






typedef uint8_t wsfHandlerId_t;


typedef uint8_t wsfEventMask_t;


typedef wsfHandlerId_t wsfTaskId_t;


typedef uint8_t wsfTaskEvent_t;
# 75 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_os_int.h"
bool_t wsfOsReadyToSleep(void);
# 88 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_os_int.h"
void WsfOsInit(void);
# 101 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_os_int.h"
void wsfOsDispatcher(void);
# 112 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_os_int.h"
void WsfOsShutdown(void);
# 26 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_os.h" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_queue.h" 1
# 27 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_os.h" 2
# 38 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_os.h"
#define WSF_OS_DIAG FALSE







#define WSF_INVALID_TASK_ID 0xFF




#define WSF_OS_GET_ACTIVE_HANDLER_ID() WSF_INVALID_TASK_ID







extern wsfHandlerId_t WsfActiveHandler;






typedef struct
{
  uint16_t param;
  uint8_t event;
  uint8_t status;
} wsfMsgHdr_t;
# 89 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_os.h"
typedef void (*wsfEventHandler_t)(wsfEventMask_t event, wsfMsgHdr_t *pMsg);
# 107 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_os.h"
void WsfSetEvent(wsfHandlerId_t handlerId, wsfEventMask_t event);
# 118 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_os.h"
void WsfTaskLock(void);
# 129 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_os.h"
void WsfTaskUnlock(void);
# 143 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_os.h"
void WsfTaskSetReady(wsfHandlerId_t handlerId, wsfTaskEvent_t event);
# 156 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_os.h"
wsfQueue_t *WsfTaskMsgQueue(wsfHandlerId_t handlerId);
# 170 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_os.h"
wsfHandlerId_t WsfOsSetNextHandler(wsfEventHandler_t handler);
# 184 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_os.h"
void wsfOsSetEventObject(void *event_object);
# 26 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_timer.h" 2
# 37 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_timer.h"
#define WSF_MS_PER_TICK 10







typedef uint32_t wsfTimerTicks_t;


typedef struct wsfTimer_tag
{
  struct wsfTimer_tag *pNext;
  wsfTimerTicks_t ticks;
  wsfMsgHdr_t msg;
  wsfHandlerId_t handlerId;
  bool_t isStarted;
} wsfTimer_t;
# 72 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_timer.h"
void WsfTimerInit(void);
# 88 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_timer.h"
void WsfTimerStartSec(wsfTimer_t *pTimer, wsfTimerTicks_t sec);
# 102 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_timer.h"
void WsfTimerStartMs(wsfTimer_t *pTimer, wsfTimerTicks_t ms);
# 115 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_timer.h"
void WsfTimerStop(wsfTimer_t *pTimer);
# 129 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_timer.h"
void WsfTimerUpdate(wsfTimerTicks_t ticks);
# 144 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_timer.h"
wsfTimerTicks_t WsfTimerNextExpiration(bool_t *pTimerRunning);
# 158 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_timer.h"
wsfTimer_t *WsfTimerServiceExpired(wsfTaskId_t taskId);


void WsfTimerUpdateTicks(void);
# 26 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_assert.h" 1
# 23 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_assert.h"
#define WSF_ASSERT_H 
# 33 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_assert.h"
void WsfAssert(const char *pFile, uint16_t line);
# 51 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_assert.h"
#define WSF_ASSERT(expr) 
# 65 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_assert.h"
#define WSF_CT_ASSERT(expr) extern char wsf_ct_assert[(expr) ? 1 : -1]
# 27 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_trace.h" 1
# 23 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_trace.h"
#define WSF_TRACE_H 






typedef void (*WsfTokenHandler_t)(void);





void WsfTrace(const char *pStr, ...);
void WsfToken(uint32_t tok, uint32_t var);
void WsfPacketTrace(uint8_t ui8Type, uint32_t ui32Len, uint8_t *pui8Buf);


bool_t WsfTokenService(void);
uint8_t WsfTokenIOWrite(uint8_t *pBuf, uint8_t len);
# 94 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_trace.h"
#define WSF_TRACE0(subsys,stat,msg) 
#define WSF_TRACE1(subsys,stat,msg,var1) 
#define WSF_TRACE2(subsys,stat,msg,var1,var2) 
#define WSF_TRACE3(subsys,stat,msg,var1,var2,var3) 
#define PACKET_TRACE(type,len,buf) 



#define WSF_TRACE_INFO0(msg) 
#define WSF_TRACE_INFO1(msg,var1) 
#define WSF_TRACE_INFO2(msg,var1,var2) 
#define WSF_TRACE_INFO3(msg,var1,var2,var3) 
#define WSF_TRACE_WARN0(msg) WSF_TRACE0("WSF", "WARN", msg)
#define WSF_TRACE_WARN1(msg,var1) WSF_TRACE1("WSF", "WARN", msg, var1)
#define WSF_TRACE_WARN2(msg,var1,var2) WSF_TRACE2("WSF", "WARN", msg, var1, var2)
#define WSF_TRACE_WARN3(msg,var1,var2,var3) WSF_TRACE3("WSF", "WARN", msg, var1, var2, var3)
#define WSF_TRACE_ERR0(msg) WSF_TRACE0("WSF", "ERR", msg)
#define WSF_TRACE_ERR1(msg,var1) WSF_TRACE1("WSF", "ERR", msg, var1)
#define WSF_TRACE_ERR2(msg,var1,var2) WSF_TRACE2("WSF", "ERR", msg, var1, var2)
#define WSF_TRACE_ERR3(msg,var1,var2,var3) WSF_TRACE3("WSF", "ERR", msg, var1, var2, var3)
#define WSF_TRACE_ALLOC0(msg) 
#define WSF_TRACE_ALLOC1(msg,var1) 
#define WSF_TRACE_ALLOC2(msg,var1,var2) 
#define WSF_TRACE_ALLOC3(msg,var1,var2,var3) 
#define WSF_TRACE_FREE0(msg) 
#define WSF_TRACE_FREE1(msg,var1) 
#define WSF_TRACE_FREE2(msg,var1,var2) 
#define WSF_TRACE_FREE3(msg,var1,var2,var3) 
#define WSF_TRACE_MSG0(msg) 
#define WSF_TRACE_MSG1(msg,var1) 
#define WSF_TRACE_MSG2(msg,var1,var2) 
#define WSF_TRACE_MSG3(msg,var1,var2,var3) 
# 146 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_trace.h"
#define HCI_TRACE_INFO0(msg) 
#define HCI_TRACE_INFO1(msg,var1) 
#define HCI_TRACE_INFO2(msg,var1,var2) 
#define HCI_TRACE_INFO3(msg,var1,var2,var3) 
#define HCI_TRACE_WARN0(msg) 
#define HCI_TRACE_WARN1(msg,var1) 
#define HCI_TRACE_WARN2(msg,var1,var2) 
#define HCI_TRACE_WARN3(msg,var1,var2,var3) 
#define HCI_TRACE_ERR0(msg) 
#define HCI_TRACE_ERR1(msg,var1) 
#define HCI_TRACE_ERR2(msg,var1,var2) 
#define HCI_TRACE_ERR3(msg,var1,var2,var3) 

#define HCI_PDUMP_CMD(len,pBuf) 
#define HCI_PDUMP_EVT(len,pBuf) 
#define HCI_PDUMP_TX_ACL(len,pBuf) 
#define HCI_PDUMP_RX_ACL(len,pBuf) 



#define DM_TRACE_INFO0(msg) WSF_TRACE0("DM", "INFO", msg)
#define DM_TRACE_INFO1(msg,var1) WSF_TRACE1("DM", "INFO", msg, var1)
#define DM_TRACE_INFO2(msg,var1,var2) WSF_TRACE2("DM", "INFO", msg, var1, var2)
#define DM_TRACE_INFO3(msg,var1,var2,var3) WSF_TRACE3("DM", "INFO", msg, var1, var2, var3)
#define DM_TRACE_WARN0(msg) WSF_TRACE0("DM", "WARN", msg)
#define DM_TRACE_WARN1(msg,var1) WSF_TRACE1("DM", "WARN", msg, var1)
#define DM_TRACE_WARN2(msg,var1,var2) WSF_TRACE2("DM", "WARN", msg, var1, var2)
#define DM_TRACE_WARN3(msg,var1,var2,var3) WSF_TRACE3("DM", "WARN", msg, var1, var2, var3)
#define DM_TRACE_ERR0(msg) WSF_TRACE0("DM", "ERR", msg)
#define DM_TRACE_ERR1(msg,var1) WSF_TRACE1("DM", "ERR", msg, var1)
#define DM_TRACE_ERR2(msg,var1,var2) WSF_TRACE2("DM", "ERR", msg, var1, var2)
#define DM_TRACE_ERR3(msg,var1,var2,var3) WSF_TRACE3("DM", "ERR", msg, var1, var2, var3)
#define DM_TRACE_ALLOC0(msg) WSF_TRACE0("DM", "ALLOC", msg)
#define DM_TRACE_ALLOC1(msg,var1) WSF_TRACE1("DM", "ALLOC", msg, var1)
#define DM_TRACE_ALLOC2(msg,var1,var2) WSF_TRACE2("DM", "ALLOC", msg, var1, var2)
#define DM_TRACE_ALLOC3(msg,var1,var2,var3) WSF_TRACE3("DM", "ALLOC", msg, var1, var2, var3)
#define DM_TRACE_FREE0(msg) WSF_TRACE0("DM", "FREE", msg)
#define DM_TRACE_FREE1(msg,var1) WSF_TRACE1("DM", "FREE", msg, var1)
#define DM_TRACE_FREE2(msg,var1,var2) WSF_TRACE2("DM", "FREE", msg, var1, var2)
#define DM_TRACE_FREE3(msg,var1,var2,var3) WSF_TRACE3("DM", "FREE", msg, var1, var2, var3)

#define L2C_TRACE_INFO0(msg) WSF_TRACE0("L2C", "INFO", msg)
#define L2C_TRACE_INFO1(msg,var1) WSF_TRACE1("L2C", "INFO", msg, var1)
#define L2C_TRACE_INFO2(msg,var1,var2) WSF_TRACE2("L2C", "INFO", msg, var1, var2)
#define L2C_TRACE_INFO3(msg,var1,var2,var3) WSF_TRACE3("L2C", "INFO", msg, var1, var2, var3)
#define L2C_TRACE_WARN0(msg) WSF_TRACE0("L2C", "WARN", msg)
#define L2C_TRACE_WARN1(msg,var1) WSF_TRACE1("L2C", "WARN", msg, var1)
#define L2C_TRACE_WARN2(msg,var1,var2) WSF_TRACE2("L2C", "WARN", msg, var1, var2)
#define L2C_TRACE_WARN3(msg,var1,var2,var3) WSF_TRACE3("L2C", "WARN", msg, var1, var2, var3)
#define L2C_TRACE_ERR0(msg) WSF_TRACE0("L2C", "ERR", msg)
#define L2C_TRACE_ERR1(msg,var1) WSF_TRACE1("L2C", "ERR", msg, var1)
#define L2C_TRACE_ERR2(msg,var1,var2) WSF_TRACE2("L2C", "ERR", msg, var1, var2)
#define L2C_TRACE_ERR3(msg,var1,var2,var3) WSF_TRACE3("L2C", "ERR", msg, var1, var2, var3)

#define ATT_TRACE_INFO0(msg) WSF_TRACE0("ATT", "INFO", msg)
#define ATT_TRACE_INFO1(msg,var1) WSF_TRACE1("ATT", "INFO", msg, var1)
#define ATT_TRACE_INFO2(msg,var1,var2) WSF_TRACE2("ATT", "INFO", msg, var1, var2)
#define ATT_TRACE_INFO3(msg,var1,var2,var3) WSF_TRACE3("ATT", "INFO", msg, var1, var2, var3)
#define ATT_TRACE_WARN0(msg) WSF_TRACE0("ATT", "WARN", msg)
#define ATT_TRACE_WARN1(msg,var1) WSF_TRACE1("ATT", "WARN", msg, var1)
#define ATT_TRACE_WARN2(msg,var1,var2) WSF_TRACE2("ATT", "WARN", msg, var1, var2)
#define ATT_TRACE_WARN3(msg,var1,var2,var3) WSF_TRACE3("ATT", "WARN", msg, var1, var2, var3)
#define ATT_TRACE_ERR0(msg) WSF_TRACE0("ATT", "ERR", msg)
#define ATT_TRACE_ERR1(msg,var1) WSF_TRACE1("ATT", "ERR", msg, var1)
#define ATT_TRACE_ERR2(msg,var1,var2) WSF_TRACE2("ATT", "ERR", msg, var1, var2)
#define ATT_TRACE_ERR3(msg,var1,var2,var3) WSF_TRACE3("ATT", "ERR", msg, var1, var2, var3)

#define SMP_TRACE_INFO0(msg) WSF_TRACE0("SMP", "INFO", msg)
#define SMP_TRACE_INFO1(msg,var1) WSF_TRACE1("SMP", "INFO", msg, var1)
#define SMP_TRACE_INFO2(msg,var1,var2) WSF_TRACE2("SMP", "INFO", msg, var1, var2)
#define SMP_TRACE_INFO3(msg,var1,var2,var3) WSF_TRACE3("SMP", "INFO", msg, var1, var2, var3)
#define SMP_TRACE_WARN0(msg) WSF_TRACE0("SMP", "WARN", msg)
#define SMP_TRACE_WARN1(msg,var1) WSF_TRACE1("SMP", "WARN", msg, var1)
#define SMP_TRACE_WARN2(msg,var1,var2) WSF_TRACE2("SMP", "WARN", msg, var1, var2)
#define SMP_TRACE_WARN3(msg,var1,var2,var3) WSF_TRACE3("SMP", "WARN", msg, var1, var2, var3)
#define SMP_TRACE_ERR0(msg) WSF_TRACE0("SMP", "ERR", msg)
#define SMP_TRACE_ERR1(msg,var1) WSF_TRACE1("SMP", "ERR", msg, var1)
#define SMP_TRACE_ERR2(msg,var1,var2) WSF_TRACE2("SMP", "ERR", msg, var1, var2)
#define SMP_TRACE_ERR3(msg,var1,var2,var3) WSF_TRACE3("SMP", "ERR", msg, var1, var2, var3)

#define APP_TRACE_INFO0(msg) WSF_TRACE0("APP", "INFO", msg)
#define APP_TRACE_INFO1(msg,var1) WSF_TRACE1("APP", "INFO", msg, var1)
#define APP_TRACE_INFO2(msg,var1,var2) WSF_TRACE2("APP", "INFO", msg, var1, var2)
#define APP_TRACE_INFO3(msg,var1,var2,var3) WSF_TRACE3("APP", "INFO", msg, var1, var2, var3)
#define APP_TRACE_WARN0(msg) WSF_TRACE0("APP", "WARN", msg)
#define APP_TRACE_WARN1(msg,var1) WSF_TRACE1("APP", "WARN", msg, var1)
#define APP_TRACE_WARN2(msg,var1,var2) WSF_TRACE2("APP", "WARN", msg, var1, var2)
#define APP_TRACE_WARN3(msg,var1,var2,var3) WSF_TRACE3("APP", "WARN", msg, var1, var2, var3)
#define APP_TRACE_ERR0(msg) WSF_TRACE0("APP", "ERR", msg)
#define APP_TRACE_ERR1(msg,var1) WSF_TRACE1("APP", "ERR", msg, var1)
#define APP_TRACE_ERR2(msg,var1,var2) WSF_TRACE2("APP", "ERR", msg, var1, var2)
#define APP_TRACE_ERR3(msg,var1,var2,var3) WSF_TRACE3("APP", "ERR", msg, var1, var2, var3)

#define LL_TRACE_INFO0(msg) WSF_TRACE0("LL", "INFO", msg)
#define LL_TRACE_INFO1(msg,var1) WSF_TRACE1("LL", "INFO", msg, var1)
#define LL_TRACE_INFO2(msg,var1,var2) WSF_TRACE2("LL", "INFO", msg, var1, var2)
#define LL_TRACE_INFO3(msg,var1,var2,var3) WSF_TRACE3("LL", "INFO", msg, var1, var2, var3)
#define LL_TRACE_WARN0(msg) WSF_TRACE0("LL", "WARN", msg)
#define LL_TRACE_WARN1(msg,var1) WSF_TRACE1("LL", "WARN", msg, var1)
#define LL_TRACE_WARN2(msg,var1,var2) WSF_TRACE2("LL", "WARN", msg, var1, var2)
#define LL_TRACE_WARN3(msg,var1,var2,var3) WSF_TRACE3("LL", "WARN", msg, var1, var2, var3)
#define LL_TRACE_ERR0(msg) WSF_TRACE0("LL", "ERR", msg)
#define LL_TRACE_ERR1(msg,var1) WSF_TRACE1("LL", "ERR", msg, var1)
#define LL_TRACE_ERR2(msg,var1,var2) WSF_TRACE2("LL", "ERR", msg, var1, var2)
#define LL_TRACE_ERR3(msg,var1,var2,var3) WSF_TRACE3("LL", "ERR", msg, var1, var2, var3)
# 28 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h" 1
# 29 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
#define INC_FREERTOS_H 




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




# 143 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
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
# 35 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h" 2
# 56 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/component/core/board/rak11720/FreeRTOSConfig.h" 1
# 47 "/home/jenkins/workspace/RUI_Release/rui-v3/component/core/board/rak11720/FreeRTOSConfig.h"
#define FREERTOS_CONFIG_H 






#define configUSE_PREEMPTION 1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 0


#define configCPU_CLOCK_HZ 48000000UL



#define configTICK_RATE_HZ 1000
#define configMAX_PRIORITIES 5
#define configMINIMAL_STACK_SIZE (256)
#define configTOTAL_HEAP_SIZE (66 * 1024)
#define configMAX_TASK_NAME_LEN 16
#define configUSE_16_BIT_TICKS 0
#define configIDLE_SHOULD_YIELD 1

#define configUSE_MUTEXES 1
#define configUSE_RECURSIVE_MUTEXES 0
#define configUSE_COUNTING_SEMAPHORES 1
#define configUSE_ALTERNATIVE_API 0
#define configQUEUE_REGISTRY_SIZE 0
#define configUSE_QUEUE_SETS 0
#define configUSE_TIME_SLICING 0
#define configUSE_NEWLIB_REENTRANT 1
#define configENABLE_BACKWARD_COMPATIBILITY 0


#define configUSE_IDLE_HOOK 0
#define configUSE_TICK_HOOK 0
#define configCHECK_FOR_STACK_OVERFLOW 2
#define configUSE_MALLOC_FAILED_HOOK 1


#define configGENERATE_RUN_TIME_STATS 0
#define configUSE_TRACE_FACILITY 0
#define configUSE_STATS_FORMATTING_FUNCTIONS 0


#define configUSE_TIMERS 1
#define configTIMER_TASK_PRIORITY 3
#define configTIMER_QUEUE_LENGTH 15
#define configTIMER_TASK_STACK_DEPTH configMINIMAL_STACK_SIZE*8


#define configKERNEL_INTERRUPT_PRIORITY (0x7 << 5)
#define configMAX_SYSCALL_INTERRUPT_PRIORITY (0x4 << 5)
#define NVIC_configKERNEL_INTERRUPT_PRIORITY (0x7)
#define NVIC_configMAX_SYSCALL_INTERRUPT_PRIORITY (0x4)


#define configASSERT(x) if (( x ) == 0) while(1);


#define configINCLUDE_APPLICATION_DEFINED_PRIVILEGED_FUNCTIONS 0


#define INCLUDE_vTaskPrioritySet 0
#define INCLUDE_uxTaskPriorityGet 0
#define INCLUDE_vTaskDelete 1
#define INCLUDE_vTaskSuspend 1
#define INCLUDE_xResumeFromISR 0
#define INCLUDE_vTaskDelayUntil 1
#define INCLUDE_vTaskDelay 1
#define INCLUDE_xTaskGetSchedulerState 0
#define INCLUDE_xTaskGetCurrentTaskHandle 0
#define INCLUDE_uxTaskGetStackHighWaterMark 0
#define INCLUDE_xTaskGetIdleTaskHandle 0
#define INCLUDE_xTimerGetTimerDaemonTaskHandle 0
#define INCLUDE_pcTaskGetTaskName 0
#define INCLUDE_eTaskGetState 0
#define INCLUDE_xEventGroupSetBitFromISR 1
#define INCLUDE_xTimerPendFunctionCall 1

#define vPortSVCHandler SVC_Handler
#define xPortPendSVHandler PendSV_Handler
#define xPortSysTickHandler SysTick_Handler

#define configOVERRIDE_DEFAULT_TICK_CONFIGURATION 1
#define configUSE_TICKLESS_IDLE 2



# 135 "/home/jenkins/workspace/RUI_Release/rui-v3/component/core/board/rak11720/FreeRTOSConfig.h"
extern uint32_t am_freertos_sleep(uint32_t);
extern void am_freertos_wakeup(uint32_t);

#define configPRE_SLEEP_PROCESSING(time) do { (time) = am_freertos_sleep(time); } while (0);




#define configPOST_SLEEP_PROCESSING(time) am_freertos_wakeup(time)



#define AM_FREERTOS_USE_STIMER_FOR_TICK 



#define configSTIMER_CLOCK_HZ 32768
#define configSTIMER_CLOCK AM_HAL_STIMER_XTAL_32KHZ
# 57 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h" 2


# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/projdefs.h" 1
# 29 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/projdefs.h"
#define PROJDEFS_H 





typedef void (*TaskFunction_t)( void * );





#define pdMS_TO_TICKS(xTimeInMs) ( ( TickType_t ) ( ( ( TickType_t ) ( xTimeInMs ) * ( TickType_t ) configTICK_RATE_HZ ) / ( TickType_t ) 1000 ) )


#define pdFALSE ( ( BaseType_t ) 0 )
#define pdTRUE ( ( BaseType_t ) 1 )

#define pdPASS ( pdTRUE )
#define pdFAIL ( pdFALSE )
#define errQUEUE_EMPTY ( ( BaseType_t ) 0 )
#define errQUEUE_FULL ( ( BaseType_t ) 0 )


#define errCOULD_NOT_ALLOCATE_REQUIRED_MEMORY ( -1 )
#define errQUEUE_BLOCKED ( -4 )
#define errQUEUE_YIELD ( -5 )



#define configUSE_LIST_DATA_INTEGRITY_CHECK_BYTES 0





#define pdINTEGRITY_CHECK_VALUE 0x5a5a5a5aUL




#define pdFREERTOS_ERRNO_NONE 0
#define pdFREERTOS_ERRNO_ENOENT 2
#define pdFREERTOS_ERRNO_EINTR 4
#define pdFREERTOS_ERRNO_EIO 5
#define pdFREERTOS_ERRNO_ENXIO 6
#define pdFREERTOS_ERRNO_EBADF 9
#define pdFREERTOS_ERRNO_EAGAIN 11
#define pdFREERTOS_ERRNO_EWOULDBLOCK 11
#define pdFREERTOS_ERRNO_ENOMEM 12
#define pdFREERTOS_ERRNO_EACCES 13
#define pdFREERTOS_ERRNO_EFAULT 14
#define pdFREERTOS_ERRNO_EBUSY 16
#define pdFREERTOS_ERRNO_EEXIST 17
#define pdFREERTOS_ERRNO_EXDEV 18
#define pdFREERTOS_ERRNO_ENODEV 19
#define pdFREERTOS_ERRNO_ENOTDIR 20
#define pdFREERTOS_ERRNO_EISDIR 21
#define pdFREERTOS_ERRNO_EINVAL 22
#define pdFREERTOS_ERRNO_ENOSPC 28
#define pdFREERTOS_ERRNO_ESPIPE 29
#define pdFREERTOS_ERRNO_EROFS 30
#define pdFREERTOS_ERRNO_EUNATCH 42
#define pdFREERTOS_ERRNO_EBADE 50
#define pdFREERTOS_ERRNO_EFTYPE 79
#define pdFREERTOS_ERRNO_ENMFILE 89
#define pdFREERTOS_ERRNO_ENOTEMPTY 90
#define pdFREERTOS_ERRNO_ENAMETOOLONG 91
#define pdFREERTOS_ERRNO_EOPNOTSUPP 95
#define pdFREERTOS_ERRNO_ENOBUFS 105
#define pdFREERTOS_ERRNO_ENOPROTOOPT 109
#define pdFREERTOS_ERRNO_EADDRINUSE 112
#define pdFREERTOS_ERRNO_ETIMEDOUT 116
#define pdFREERTOS_ERRNO_EINPROGRESS 119
#define pdFREERTOS_ERRNO_EALREADY 120
#define pdFREERTOS_ERRNO_EADDRNOTAVAIL 125
#define pdFREERTOS_ERRNO_EISCONN 127
#define pdFREERTOS_ERRNO_ENOTCONN 128
#define pdFREERTOS_ERRNO_ENOMEDIUM 135
#define pdFREERTOS_ERRNO_EILSEQ 138
#define pdFREERTOS_ERRNO_ECANCELED 140



#define pdFREERTOS_LITTLE_ENDIAN 0
#define pdFREERTOS_BIG_ENDIAN 1


#define pdLITTLE_ENDIAN pdFREERTOS_LITTLE_ENDIAN
#define pdBIG_ENDIAN pdFREERTOS_BIG_ENDIAN
# 60 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h" 2


# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/portable.h" 1
# 33 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/portable.h"
#define PORTABLE_H 
# 45 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/portable.h"
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/deprecated_definitions.h" 1
# 29 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/deprecated_definitions.h"
#define DEPRECATED_DEFINITIONS_H 
# 46 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/portable.h" 2






# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/portable/GCC/AMapollo2/portmacro.h" 1
# 30 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/portable/GCC/AMapollo2/portmacro.h"
#define PORTMACRO_H 
# 47 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/portable/GCC/AMapollo2/portmacro.h"
#define portCHAR char
#define portFLOAT float
#define portDOUBLE double
#define portLONG long
#define portSHORT short
#define portSTACK_TYPE uint32_t
#define portBASE_TYPE long

typedef uint32_t StackType_t;
typedef long BaseType_t;
typedef unsigned long UBaseType_t;





 typedef uint32_t TickType_t;
#define portMAX_DELAY ( TickType_t ) 0xffffffffUL



#define portTICK_TYPE_IS_ATOMIC 1




#define portSTACK_GROWTH ( -1 )
#define portTICK_PERIOD_MS ( ( TickType_t ) 1000 / configTICK_RATE_HZ )
#define portBYTE_ALIGNMENT 8



#define portYIELD() { portNVIC_INT_CTRL_REG = portNVIC_PENDSVSET_BIT; __asm volatile( "dsb" ::: "memory" ); __asm volatile( "isb" ); }
# 90 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/portable/GCC/AMapollo2/portmacro.h"
#define portNVIC_INT_CTRL_REG ( * ( ( volatile uint32_t * ) 0xe000ed04 ) )
#define portNVIC_PENDSVSET_BIT ( 1UL << 28UL )
#define portEND_SWITCHING_ISR(xSwitchRequired) if( xSwitchRequired != pdFALSE ) portYIELD()
#define portYIELD_FROM_ISR(x) portEND_SWITCHING_ISR( x )



extern void vPortEnterCritical( void );
extern void vPortExitCritical( void );
#define portSET_INTERRUPT_MASK_FROM_ISR() ulPortRaiseBASEPRI()
#define portCLEAR_INTERRUPT_MASK_FROM_ISR(x) vPortSetBASEPRI(x)
#define portDISABLE_INTERRUPTS() vPortRaiseBASEPRI()
#define portENABLE_INTERRUPTS() vPortSetBASEPRI(0)
#define portENTER_CRITICAL() vPortEnterCritical()
#define portEXIT_CRITICAL() vPortExitCritical()






#define portTASK_FUNCTION_PROTO(vFunction,pvParameters) void vFunction( void *pvParameters )
#define portTASK_FUNCTION(vFunction,pvParameters) void vFunction( void *pvParameters )




 extern void vPortSuppressTicksAndSleep( TickType_t xExpectedIdleTime );
#define portSUPPRESS_TICKS_AND_SLEEP(xExpectedIdleTime) vPortSuppressTicksAndSleep( xExpectedIdleTime )
# 156 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/portable/GCC/AMapollo2/portmacro.h"
 void vPortValidateInterruptPriority( void );
#define portASSERT_IF_INTERRUPT_PRIORITY_INVALID() vPortValidateInterruptPriority()



#define portNOP() 

#define portINLINE __inline


#define portFORCE_INLINE inline __attribute__(( always_inline))


inline __attribute__(( always_inline)) static BaseType_t xPortIsInsideInterrupt( void )
{
uint32_t ulCurrentInterrupt;
BaseType_t xReturn;


 __asm volatile( "mrs %0, ipsr" : "=r"( ulCurrentInterrupt ) :: "memory" );

 if( ulCurrentInterrupt == 0 )
 {
  xReturn = ( ( BaseType_t ) 0 );
 }
 else
 {
  xReturn = ( ( BaseType_t ) 1 );
 }

 return xReturn;
}



inline __attribute__(( always_inline)) static void vPortRaiseBASEPRI( void )
{
uint32_t ulNewBASEPRI;

 __asm volatile
 (
  "	mov %0, %1												\n"
  "	msr basepri, %0											\n"
  "	isb														\n"
  "	dsb														\n"
  :"=r" (ulNewBASEPRI) : "i" ( (0x4 << 5) ) : "memory"
 );
}



inline __attribute__(( always_inline)) static uint32_t ulPortRaiseBASEPRI( void )
{
uint32_t ulOriginalBASEPRI, ulNewBASEPRI;

 __asm volatile
 (
  "	mrs %0, basepri											\n"
  "	mov %1, %2												\n"
  "	msr basepri, %1											\n"
  "	isb														\n"
  "	dsb														\n"
  :"=r" (ulOriginalBASEPRI), "=r" (ulNewBASEPRI) : "i" ( (0x4 << 5) ) : "memory"
 );



 return ulOriginalBASEPRI;
}


inline __attribute__(( always_inline)) static void vPortSetBASEPRI( uint32_t ulNewMaskValue )
{
 __asm volatile
 (
  "	msr basepri, %0	" :: "r" ( ulNewMaskValue ) : "memory"
 );
}
# 53 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/portable.h" 2
# 64 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/portable.h"
#define portBYTE_ALIGNMENT_MASK ( 0x0007 )
# 84 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/portable.h"
#define portNUM_CONFIGURABLE_REGIONS 1






# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/mpu_wrappers.h" 1
# 29 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/mpu_wrappers.h"
#define MPU_WRAPPERS_H 
# 174 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/mpu_wrappers.h"
#define PRIVILEGED_FUNCTION 
#define PRIVILEGED_DATA 
#define portUSING_MPU_WRAPPERS 0
# 92 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/portable.h" 2
# 102 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/portable.h"
 StackType_t *pxPortInitialiseStack( StackType_t *pxTopOfStack, TaskFunction_t pxCode, void *pvParameters ) ;



typedef struct HeapRegion
{
 uint8_t *pucStartAddress;
 size_t xSizeInBytes;
} HeapRegion_t;
# 123 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/portable.h"
void vPortDefineHeapRegions( const HeapRegion_t * const pxHeapRegions ) ;





void *pvPortMalloc( size_t xSize ) ;
void vPortFree( void *pv ) ;
void vPortInitialiseBlocks( void ) ;
size_t xPortGetFreeHeapSize( void ) ;
size_t xPortGetMinimumEverFreeHeapSize( void ) ;





BaseType_t xPortStartScheduler( void ) ;






void vPortEndScheduler( void ) ;
# 63 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h" 2
# 71 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/reent.h" 1 3
# 91 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/reent.h" 3
#define _REENT_H_ 

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 1 3
# 11 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
#define _SYS_REENT_H_ 

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_ansi.h" 1 3







#define _ANSIDECL_H_ 

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 1 3







#define __NEWLIB_H__ 1
# 18 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 3
#define _WANT_IO_C99_FORMATS 1


#define _WANT_IO_LONG_LONG 1


#define _WANT_REGISTER_FINI 1
# 37 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 3
#define _REENT_CHECK_VERIFY 1





#define _MB_LEN_MAX 1
# 53 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 3
#define HAVE_INITFINI_ARRAY 1



#define _ATEXIT_DYNAMIC_ALLOC 1


#define _HAVE_LONG_DOUBLE 1


#define _HAVE_CC_INHIBIT_LOOP_TO_LIBCALL 1


#define _LDBL_EQ_DBL 1


#define _FVWRITE_IN_STREAMIO 1


#define _FSEEK_OPTIMIZATION 1


#define _WIDE_ORIENT 1


#define _UNBUF_STREAM_OPT 1
# 95 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 3
#define _RETARGETABLE_LOCKING 1
# 11 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_ansi.h" 2 3
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
# 94 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/reent.h" 2 3


#define __need_size_t 
#define __need_ptrdiff_t 
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
# 99 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/reent.h" 2 3


struct stat;
struct tms;
struct timeval;
struct timezone;
# 139 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/reent.h" 3
extern int _close_r (struct _reent *, int);
extern int _execve_r (struct _reent *, const char *, char *const *, char *const *);
extern int _fcntl_r (struct _reent *, int, int, int);
extern int _fork_r (struct _reent *);
extern int _fstat_r (struct _reent *, int, struct stat *);
extern int _getpid_r (struct _reent *);
extern int _isatty_r (struct _reent *, int);
extern int _kill_r (struct _reent *, int, int);
extern int _link_r (struct _reent *, const char *, const char *);
extern _off_t _lseek_r (struct _reent *, int, _off_t, int);
extern int _mkdir_r (struct _reent *, const char *, int);
extern int _open_r (struct _reent *, const char *, int, int);
extern _ssize_t _read_r (struct _reent *, int, void *, size_t);
extern int _rename_r (struct _reent *, const char *, const char *);
extern void *_sbrk_r (struct _reent *, ptrdiff_t);
extern int _stat_r (struct _reent *, const char *, struct stat *);
extern unsigned long _times_r (struct _reent *, struct tms *);
extern int _unlink_r (struct _reent *, const char *);
extern int _wait_r (struct _reent *, int *);
extern _ssize_t _write_r (struct _reent *, int, const void *, size_t);


extern int _gettimeofday_r (struct _reent *, struct timeval *__tp, void *__tzp);
# 72 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h" 2
# 108 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
#define configUSE_CO_ROUTINES 0
# 140 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
#define INCLUDE_xTaskAbortDelay 0



#define INCLUDE_xQueueGetMutexHolder 0



#define INCLUDE_xSemaphoreGetMutexHolder INCLUDE_xQueueGetMutexHolder



#define INCLUDE_xTaskGetHandle 0
# 164 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
#define INCLUDE_xTaskResumeFromISR 1
# 186 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
#define configUSE_DAEMON_TASK_STARTUP_HOOK 0



#define configUSE_APPLICATION_TASK_TAG 0



#define configNUM_THREAD_LOCAL_STORAGE_POINTERS 0
# 218 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
#define portCRITICAL_NESTING_IN_TCB 0
# 237 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
#define configASSERT_DEFINED 1
# 266 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
#define portCLEAN_UP_TCB(pxTCB) ( void ) pxTCB



#define portPRE_TASK_DELETE_HOOK(pvTaskToDelete,pxYieldPending) 



#define portSETUP_TCB(pxTCB) ( void ) pxTCB







#define vQueueAddToRegistry(xQueue,pcName) 
#define vQueueUnregisterQueue(xQueue) 
#define pcQueueGetName(xQueue) 



#define portPOINTER_SIZE_TYPE uint32_t






#define traceSTART() 





#define traceEND() 





#define traceTASK_SWITCHED_IN() 





#define traceINCREASE_TICK_COUNT(x) 




#define traceLOW_POWER_IDLE_BEGIN() 




#define traceLOW_POWER_IDLE_END() 





#define traceTASK_SWITCHED_OUT() 
# 338 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
#define traceTASK_PRIORITY_INHERIT(pxTCBOfMutexHolder,uxInheritedPriority) 







#define traceTASK_PRIORITY_DISINHERIT(pxTCBOfMutexHolder,uxOriginalPriority) 







#define traceBLOCKING_ON_QUEUE_RECEIVE(pxQueue) 







#define traceBLOCKING_ON_QUEUE_PEEK(pxQueue) 







#define traceBLOCKING_ON_QUEUE_SEND(pxQueue) 







#define configRECORD_STACK_HIGH_ADDRESS 0



#define configINCLUDE_FREERTOS_TASK_C_ADDITIONS_H 0





#define traceMOVED_TASK_TO_READY_STATE(pxTCB) 



#define tracePOST_MOVED_TASK_TO_READY_STATE(pxTCB) 



#define traceQUEUE_CREATE(pxNewQueue) 



#define traceQUEUE_CREATE_FAILED(ucQueueType) 



#define traceCREATE_MUTEX(pxNewQueue) 



#define traceCREATE_MUTEX_FAILED() 



#define traceGIVE_MUTEX_RECURSIVE(pxMutex) 



#define traceGIVE_MUTEX_RECURSIVE_FAILED(pxMutex) 



#define traceTAKE_MUTEX_RECURSIVE(pxMutex) 



#define traceTAKE_MUTEX_RECURSIVE_FAILED(pxMutex) 



#define traceCREATE_COUNTING_SEMAPHORE() 



#define traceCREATE_COUNTING_SEMAPHORE_FAILED() 



#define traceQUEUE_SEND(pxQueue) 



#define traceQUEUE_SEND_FAILED(pxQueue) 



#define traceQUEUE_RECEIVE(pxQueue) 



#define traceQUEUE_PEEK(pxQueue) 



#define traceQUEUE_PEEK_FAILED(pxQueue) 



#define traceQUEUE_PEEK_FROM_ISR(pxQueue) 



#define traceQUEUE_RECEIVE_FAILED(pxQueue) 



#define traceQUEUE_SEND_FROM_ISR(pxQueue) 



#define traceQUEUE_SEND_FROM_ISR_FAILED(pxQueue) 



#define traceQUEUE_RECEIVE_FROM_ISR(pxQueue) 



#define traceQUEUE_RECEIVE_FROM_ISR_FAILED(pxQueue) 



#define traceQUEUE_PEEK_FROM_ISR_FAILED(pxQueue) 



#define traceQUEUE_DELETE(pxQueue) 



#define traceTASK_CREATE(pxNewTCB) 



#define traceTASK_CREATE_FAILED() 



#define traceTASK_DELETE(pxTaskToDelete) 



#define traceTASK_DELAY_UNTIL(x) 



#define traceTASK_DELAY() 



#define traceTASK_PRIORITY_SET(pxTask,uxNewPriority) 



#define traceTASK_SUSPEND(pxTaskToSuspend) 



#define traceTASK_RESUME(pxTaskToResume) 



#define traceTASK_RESUME_FROM_ISR(pxTaskToResume) 



#define traceTASK_INCREMENT_TICK(xTickCount) 



#define traceTIMER_CREATE(pxNewTimer) 



#define traceTIMER_CREATE_FAILED() 



#define traceTIMER_COMMAND_SEND(xTimer,xMessageID,xMessageValueValue,xReturn) 



#define traceTIMER_EXPIRED(pxTimer) 



#define traceTIMER_COMMAND_RECEIVED(pxTimer,xMessageID,xMessageValue) 



#define traceMALLOC(pvAddress,uiSize) 



#define traceFREE(pvAddress,uiSize) 



#define traceEVENT_GROUP_CREATE(xEventGroup) 



#define traceEVENT_GROUP_CREATE_FAILED() 



#define traceEVENT_GROUP_SYNC_BLOCK(xEventGroup,uxBitsToSet,uxBitsToWaitFor) 



#define traceEVENT_GROUP_SYNC_END(xEventGroup,uxBitsToSet,uxBitsToWaitFor,xTimeoutOccurred) ( void ) xTimeoutOccurred



#define traceEVENT_GROUP_WAIT_BITS_BLOCK(xEventGroup,uxBitsToWaitFor) 



#define traceEVENT_GROUP_WAIT_BITS_END(xEventGroup,uxBitsToWaitFor,xTimeoutOccurred) ( void ) xTimeoutOccurred



#define traceEVENT_GROUP_CLEAR_BITS(xEventGroup,uxBitsToClear) 



#define traceEVENT_GROUP_CLEAR_BITS_FROM_ISR(xEventGroup,uxBitsToClear) 



#define traceEVENT_GROUP_SET_BITS(xEventGroup,uxBitsToSet) 



#define traceEVENT_GROUP_SET_BITS_FROM_ISR(xEventGroup,uxBitsToSet) 



#define traceEVENT_GROUP_DELETE(xEventGroup) 



#define tracePEND_FUNC_CALL(xFunctionToPend,pvParameter1,ulParameter2,ret) 



#define tracePEND_FUNC_CALL_FROM_ISR(xFunctionToPend,pvParameter1,ulParameter2,ret) 



#define traceQUEUE_REGISTRY_ADD(xQueue,pcQueueName) 



#define traceTASK_NOTIFY_TAKE_BLOCK() 



#define traceTASK_NOTIFY_TAKE() 



#define traceTASK_NOTIFY_WAIT_BLOCK() 



#define traceTASK_NOTIFY_WAIT() 



#define traceTASK_NOTIFY() 



#define traceTASK_NOTIFY_FROM_ISR() 



#define traceTASK_NOTIFY_GIVE_FROM_ISR() 



#define traceSTREAM_BUFFER_CREATE_FAILED(xIsMessageBuffer) 



#define traceSTREAM_BUFFER_CREATE_STATIC_FAILED(xReturn,xIsMessageBuffer) 



#define traceSTREAM_BUFFER_CREATE(pxStreamBuffer,xIsMessageBuffer) 



#define traceSTREAM_BUFFER_DELETE(xStreamBuffer) 



#define traceSTREAM_BUFFER_RESET(xStreamBuffer) 



#define traceBLOCKING_ON_STREAM_BUFFER_SEND(xStreamBuffer) 



#define traceSTREAM_BUFFER_SEND(xStreamBuffer,xBytesSent) 



#define traceSTREAM_BUFFER_SEND_FAILED(xStreamBuffer) 



#define traceSTREAM_BUFFER_SEND_FROM_ISR(xStreamBuffer,xBytesSent) 



#define traceBLOCKING_ON_STREAM_BUFFER_RECEIVE(xStreamBuffer) 



#define traceSTREAM_BUFFER_RECEIVE(xStreamBuffer,xReceivedLength) 



#define traceSTREAM_BUFFER_RECEIVE_FAILED(xStreamBuffer) 



#define traceSTREAM_BUFFER_RECEIVE_FROM_ISR(xStreamBuffer,xReceivedLength) 
# 710 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS() 







#define portPRIVILEGE_BIT ( ( UBaseType_t ) 0x00 )



#define portYIELD_WITHIN_API portYIELD







#define configEXPECTED_IDLE_TIME_BEFORE_SLEEP 2
# 742 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
#define configPRE_SUPPRESS_TICKS_AND_SLEEP_PROCESSING(x) 
# 758 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
#define portTASK_USES_FLOATING_POINT() 



#define portTASK_CALLS_SECURE_FUNCTIONS() 
# 786 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
#define mtCOVERAGE_TEST_MARKER() 



#define mtCOVERAGE_TEST_DELAY() 



#define portASSERT_IF_IN_ISR() 







#define configAPPLICATION_ALLOCATED_HEAP 0



#define configUSE_TASK_NOTIFICATIONS 1



#define configUSE_POSIX_ERRNO 0
# 819 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
#define configSUPPORT_STATIC_ALLOCATION 0




#define configSUPPORT_DYNAMIC_ALLOCATION 1





#define configSTACK_DEPTH_TYPE uint16_t






#define configMESSAGE_BUFFER_LENGTH_TYPE size_t
# 856 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
#define configINITIAL_TICK_COUNT 0
# 870 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
#define portTICK_TYPE_ENTER_CRITICAL() 
#define portTICK_TYPE_EXIT_CRITICAL() 
#define portTICK_TYPE_SET_INTERRUPT_MASK_FROM_ISR() 0
#define portTICK_TYPE_CLEAR_INTERRUPT_MASK_FROM_ISR(x) ( void ) x
# 893 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
#define configPRINTF(X) 





#define configMAX(a,b) ( ( ( a ) > ( b ) ) ? ( a ) : ( b ) )





#define configMIN(a,b) ( ( ( a ) < ( b ) ) ? ( a ) : ( b ) )
# 950 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
#define configUSE_TASK_FPU_SUPPORT 1
# 963 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"

# 963 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
struct xSTATIC_LIST_ITEM
{
 TickType_t xDummy1;
 void *pvDummy2[ 4 ];
};
typedef struct xSTATIC_LIST_ITEM StaticListItem_t;


struct xSTATIC_MINI_LIST_ITEM
{
 TickType_t xDummy1;
 void *pvDummy2[ 2 ];
};
typedef struct xSTATIC_MINI_LIST_ITEM StaticMiniListItem_t;


typedef struct xSTATIC_LIST
{
 UBaseType_t uxDummy1;
 void *pvDummy2;
 StaticMiniListItem_t xDummy3;
} StaticList_t;
# 999 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
typedef struct xSTATIC_TCB
{
 void *pxDummy1;



 StaticListItem_t xDummy3[ 2 ];
 UBaseType_t uxDummy5;
 void *pxDummy6;
 uint8_t ucDummy7[ 16 ];
# 1019 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
  UBaseType_t uxDummy12[ 2 ];
# 1031 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
  struct _reent xDummy17;


  uint32_t ulDummy18;
  uint8_t ucDummy19;
# 1047 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
} StaticTask_t;
# 1063 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
typedef struct xSTATIC_QUEUE
{
 void *pvDummy1[ 3 ];

 union
 {
  void *pvDummy2;
  UBaseType_t uxDummy2;
 } u;

 StaticList_t xDummy3[ 2 ];
 UBaseType_t uxDummy4[ 3 ];
 uint8_t ucDummy5[ 2 ];
# 1090 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
} StaticQueue_t;
typedef StaticQueue_t StaticSemaphore_t;
# 1107 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
typedef struct xSTATIC_EVENT_GROUP
{
 TickType_t xDummy1;
 StaticList_t xDummy2;
# 1120 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
} StaticEventGroup_t;
# 1136 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
typedef struct xSTATIC_TIMER
{
 void *pvDummy1;
 StaticListItem_t xDummy2;
 TickType_t xDummy3;
 UBaseType_t uxDummy4;
 void *pvDummy5;
 TaskFunction_t pvDummy6;
# 1152 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
} StaticTimer_t;
# 1168 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/FreeRTOS.h"
typedef struct xSTATIC_STREAM_BUFFER
{
 size_t uxDummy1[ 4 ];
 void * pvDummy2[ 3 ];
 uint8_t ucDummy3;



} StaticStreamBuffer_t;


typedef StaticStreamBuffer_t StaticMessageBuffer_t;
# 29 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h" 1
# 30 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h"
#define TIMERS_H 







# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h" 1
# 30 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
#define INC_TASK_H 





# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/list.h" 1
# 61 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/list.h"
#define LIST_H 
# 92 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/list.h"
#define configLIST_VOLATILE 
# 106 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/list.h"
#define listFIRST_LIST_ITEM_INTEGRITY_CHECK_VALUE 
#define listSECOND_LIST_ITEM_INTEGRITY_CHECK_VALUE 
#define listFIRST_LIST_INTEGRITY_CHECK_VALUE 
#define listSECOND_LIST_INTEGRITY_CHECK_VALUE 
#define listSET_FIRST_LIST_ITEM_INTEGRITY_CHECK_VALUE(pxItem) 
#define listSET_SECOND_LIST_ITEM_INTEGRITY_CHECK_VALUE(pxItem) 
#define listSET_LIST_INTEGRITY_CHECK_1_VALUE(pxList) 
#define listSET_LIST_INTEGRITY_CHECK_2_VALUE(pxList) 
#define listTEST_LIST_ITEM_INTEGRITY(pxItem) 
#define listTEST_LIST_INTEGRITY(pxList) 
# 139 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/list.h"
struct xLIST;
struct xLIST_ITEM
{

 TickType_t xItemValue;
 struct xLIST_ITEM * pxNext;
 struct xLIST_ITEM * pxPrevious;
 void * pvOwner;
 struct xLIST * pxContainer;

};
typedef struct xLIST_ITEM ListItem_t;

struct xMINI_LIST_ITEM
{

 TickType_t xItemValue;
 struct xLIST_ITEM * pxNext;
 struct xLIST_ITEM * pxPrevious;
};
typedef struct xMINI_LIST_ITEM MiniListItem_t;




typedef struct xLIST
{

 volatile UBaseType_t uxNumberOfItems;
 ListItem_t * pxIndex;
 MiniListItem_t xListEnd;

} List_t;
# 180 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/list.h"
#define listSET_LIST_ITEM_OWNER(pxListItem,pxOwner) ( ( pxListItem )->pvOwner = ( void * ) ( pxOwner ) )
# 189 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/list.h"
#define listGET_LIST_ITEM_OWNER(pxListItem) ( ( pxListItem )->pvOwner )
# 198 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/list.h"
#define listSET_LIST_ITEM_VALUE(pxListItem,xValue) ( ( pxListItem )->xItemValue = ( xValue ) )
# 208 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/list.h"
#define listGET_LIST_ITEM_VALUE(pxListItem) ( ( pxListItem )->xItemValue )
# 217 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/list.h"
#define listGET_ITEM_VALUE_OF_HEAD_ENTRY(pxList) ( ( ( pxList )->xListEnd ).pxNext->xItemValue )







#define listGET_HEAD_ENTRY(pxList) ( ( ( pxList )->xListEnd ).pxNext )







#define listGET_NEXT(pxListItem) ( ( pxListItem )->pxNext )







#define listGET_END_MARKER(pxList) ( ( ListItem_t const * ) ( &( ( pxList )->xListEnd ) ) )
# 250 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/list.h"
#define listLIST_IS_EMPTY(pxList) ( ( ( pxList )->uxNumberOfItems == ( UBaseType_t ) 0 ) ? pdTRUE : pdFALSE )




#define listCURRENT_LIST_LENGTH(pxList) ( ( pxList )->uxNumberOfItems )
# 277 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/list.h"
#define listGET_OWNER_OF_NEXT_ENTRY(pxTCB,pxList) { List_t * const pxConstList = ( pxList ); ( pxConstList )->pxIndex = ( pxConstList )->pxIndex->pxNext; if( ( void * ) ( pxConstList )->pxIndex == ( void * ) &( ( pxConstList )->xListEnd ) ) { ( pxConstList )->pxIndex = ( pxConstList )->pxIndex->pxNext; } ( pxTCB ) = ( pxConstList )->pxIndex->pvOwner; }
# 307 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/list.h"
#define listGET_OWNER_OF_HEAD_ENTRY(pxList) ( (&( ( pxList )->xListEnd ))->pxNext->pvOwner )
# 318 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/list.h"
#define listIS_CONTAINED_WITHIN(pxList,pxListItem) ( ( ( pxListItem )->pxContainer == ( pxList ) ) ? ( pdTRUE ) : ( pdFALSE ) )







#define listLIST_ITEM_CONTAINER(pxListItem) ( ( pxListItem )->pxContainer )






#define listLIST_IS_INITIALISED(pxList) ( ( pxList )->xListEnd.xItemValue == portMAX_DELAY )
# 345 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/list.h"
void vListInitialise( List_t * const pxList ) ;
# 356 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/list.h"
void vListInitialiseItem( ListItem_t * const pxItem ) ;
# 369 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/list.h"
void vListInsert( List_t * const pxList, ListItem_t * const pxNewListItem ) ;
# 390 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/list.h"
void vListInsertEnd( List_t * const pxList, ListItem_t * const pxNewListItem ) ;
# 405 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/list.h"
UBaseType_t uxListRemove( ListItem_t * const pxItemToRemove ) ;
# 37 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h" 2
# 46 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
#define tskKERNEL_VERSION_NUMBER "V10.1.1"
#define tskKERNEL_VERSION_MAJOR 10
#define tskKERNEL_VERSION_MINOR 1
#define tskKERNEL_VERSION_BUILD 1
# 61 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
struct tskTaskControlBlock;
typedef struct tskTaskControlBlock* TaskHandle_t;





typedef BaseType_t (*TaskHookFunction_t)( void * );


typedef enum
{
 eRunning = 0,
 eReady,
 eBlocked,
 eSuspended,
 eDeleted,
 eInvalid
} eTaskState;


typedef enum
{
 eNoAction = 0,
 eSetBits,
 eIncrement,
 eSetValueWithOverwrite,
 eSetValueWithoutOverwrite
} eNotifyAction;




typedef struct xTIME_OUT
{
 BaseType_t xOverflowCount;
 TickType_t xTimeOnEntering;
} TimeOut_t;




typedef struct xMEMORY_REGION
{
 void *pvBaseAddress;
 uint32_t ulLengthInBytes;
 uint32_t ulParameters;
} MemoryRegion_t;




typedef struct xTASK_PARAMETERS
{
 TaskFunction_t pvTaskCode;
 const char * const pcName;
 uint16_t usStackDepth;
 void *pvParameters;
 UBaseType_t uxPriority;
 StackType_t *puxStackBuffer;
 MemoryRegion_t xRegions[ 1 ];



} TaskParameters_t;



typedef struct xTASK_STATUS
{
 TaskHandle_t xHandle;
 const char *pcTaskName;
 UBaseType_t xTaskNumber;
 eTaskState eCurrentState;
 UBaseType_t uxCurrentPriority;
 UBaseType_t uxBasePriority;
 uint32_t ulRunTimeCounter;
 StackType_t *pxStackBase;
 uint16_t usStackHighWaterMark;
} TaskStatus_t;


typedef enum
{
 eAbortSleep = 0,
 eStandardSleep,
 eNoTasksWaitingTimeout
} eSleepModeStatus;






#define tskIDLE_PRIORITY ( ( UBaseType_t ) 0U )
# 165 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
#define taskYIELD() portYIELD()
# 179 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
#define taskENTER_CRITICAL() portENTER_CRITICAL()
#define taskENTER_CRITICAL_FROM_ISR() portSET_INTERRUPT_MASK_FROM_ISR()
# 194 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
#define taskEXIT_CRITICAL() portEXIT_CRITICAL()
#define taskEXIT_CRITICAL_FROM_ISR(x) portCLEAR_INTERRUPT_MASK_FROM_ISR( x )
# 204 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
#define taskDISABLE_INTERRUPTS() portDISABLE_INTERRUPTS()
# 214 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
#define taskENABLE_INTERRUPTS() portENABLE_INTERRUPTS()




#define taskSCHEDULER_SUSPENDED ( ( BaseType_t ) 0 )
#define taskSCHEDULER_NOT_STARTED ( ( BaseType_t ) 1 )
#define taskSCHEDULER_RUNNING ( ( BaseType_t ) 2 )
# 322 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
 BaseType_t xTaskCreate( TaskFunction_t pxTaskCode,
       const char * const pcName,
       const uint16_t usStackDepth,
       void * const pvParameters,
       UBaseType_t uxPriority,
       TaskHandle_t * const pxCreatedTask ) ;
# 657 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
void vTaskAllocateMPURegions( TaskHandle_t xTask, const MemoryRegion_t * const pxRegions ) ;
# 698 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
void vTaskDelete( TaskHandle_t xTaskToDelete ) ;
# 750 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
void vTaskDelay( const TickType_t xTicksToDelay ) ;
# 809 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
void vTaskDelayUntil( TickType_t * const pxPreviousWakeTime, const TickType_t xTimeIncrement ) ;
# 834 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
BaseType_t xTaskAbortDelay( TaskHandle_t xTask ) ;
# 881 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
UBaseType_t uxTaskPriorityGet( const TaskHandle_t xTask ) ;







UBaseType_t uxTaskPriorityGetFromISR( const TaskHandle_t xTask ) ;
# 907 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
eTaskState eTaskGetState( TaskHandle_t xTask ) ;
# 963 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
void vTaskGetInfo( TaskHandle_t xTask, TaskStatus_t *pxTaskStatus, BaseType_t xGetFreeStackSpace, eTaskState eState ) ;
# 1005 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
void vTaskPrioritySet( TaskHandle_t xTask, UBaseType_t uxNewPriority ) ;
# 1056 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
void vTaskSuspend( TaskHandle_t xTaskToSuspend ) ;
# 1105 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
void vTaskResume( TaskHandle_t xTaskToResume ) ;
# 1134 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
BaseType_t xTaskResumeFromISR( TaskHandle_t xTaskToResume ) ;
# 1167 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
void vTaskStartScheduler( void ) ;
# 1223 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
void vTaskEndScheduler( void ) ;
# 1274 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
void vTaskSuspendAll( void ) ;
# 1328 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
BaseType_t xTaskResumeAll( void ) ;
# 1343 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
TickType_t xTaskGetTickCount( void ) ;
# 1359 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
TickType_t xTaskGetTickCountFromISR( void ) ;
# 1373 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
UBaseType_t uxTaskGetNumberOfTasks( void ) ;
# 1386 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
char *pcTaskGetName( TaskHandle_t xTaskToQuery ) ;
# 1402 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
TaskHandle_t xTaskGetHandle( const char *pcNameToQuery ) ;
# 1423 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
UBaseType_t uxTaskGetStackHighWaterMark( TaskHandle_t xTask ) ;
# 1476 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
BaseType_t xTaskCallApplicationTaskHook( TaskHandle_t xTask, void *pvParameter ) ;
# 1485 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
TaskHandle_t xTaskGetIdleTaskHandle( void ) ;
# 1584 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
UBaseType_t uxTaskGetSystemState( TaskStatus_t * const pxTaskStatusArray, const UBaseType_t uxArraySize, uint32_t * const pulTotalRunTime ) ;
# 1631 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
void vTaskList( char * pcWriteBuffer ) ;
# 1685 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
void vTaskGetRunTimeStats( char *pcWriteBuffer ) ;
# 1766 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
BaseType_t xTaskGenericNotify( TaskHandle_t xTaskToNotify, uint32_t ulValue, eNotifyAction eAction, uint32_t *pulPreviousNotificationValue ) ;
#define xTaskNotify(xTaskToNotify,ulValue,eAction) xTaskGenericNotify( ( xTaskToNotify ), ( ulValue ), ( eAction ), NULL )
#define xTaskNotifyAndQuery(xTaskToNotify,ulValue,eAction,pulPreviousNotifyValue) xTaskGenericNotify( ( xTaskToNotify ), ( ulValue ), ( eAction ), ( pulPreviousNotifyValue ) )
# 1857 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
BaseType_t xTaskGenericNotifyFromISR( TaskHandle_t xTaskToNotify, uint32_t ulValue, eNotifyAction eAction, uint32_t *pulPreviousNotificationValue, BaseType_t *pxHigherPriorityTaskWoken ) ;
#define xTaskNotifyFromISR(xTaskToNotify,ulValue,eAction,pxHigherPriorityTaskWoken) xTaskGenericNotifyFromISR( ( xTaskToNotify ), ( ulValue ), ( eAction ), NULL, ( pxHigherPriorityTaskWoken ) )
#define xTaskNotifyAndQueryFromISR(xTaskToNotify,ulValue,eAction,pulPreviousNotificationValue,pxHigherPriorityTaskWoken) xTaskGenericNotifyFromISR( ( xTaskToNotify ), ( ulValue ), ( eAction ), ( pulPreviousNotificationValue ), ( pxHigherPriorityTaskWoken ) )
# 1934 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
BaseType_t xTaskNotifyWait( uint32_t ulBitsToClearOnEntry, uint32_t ulBitsToClearOnExit, uint32_t *pulNotificationValue, TickType_t xTicksToWait ) ;
# 1980 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
#define xTaskNotifyGive(xTaskToNotify) xTaskGenericNotify( ( xTaskToNotify ), ( 0 ), eIncrement, NULL )
# 2035 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
void vTaskNotifyGiveFromISR( TaskHandle_t xTaskToNotify, BaseType_t *pxHigherPriorityTaskWoken ) ;
# 2104 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
uint32_t ulTaskNotifyTake( BaseType_t xClearCountOnExit, TickType_t xTicksToWait ) ;
# 2120 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
BaseType_t xTaskNotifyStateClear( TaskHandle_t xTask );
# 2141 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
BaseType_t xTaskIncrementTick( void ) ;
# 2174 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
void vTaskPlaceOnEventList( List_t * const pxEventList, const TickType_t xTicksToWait ) ;
void vTaskPlaceOnUnorderedEventList( List_t * pxEventList, const TickType_t xItemValue, const TickType_t xTicksToWait ) ;
# 2188 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
void vTaskPlaceOnEventListRestricted( List_t * const pxEventList, TickType_t xTicksToWait, const BaseType_t xWaitIndefinitely ) ;
# 2214 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
BaseType_t xTaskRemoveFromEventList( const List_t * const pxEventList ) ;
void vTaskRemoveFromUnorderedEventList( ListItem_t * pxEventListItem, const TickType_t xItemValue ) ;
# 2225 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
void vTaskSwitchContext( void ) ;





TickType_t uxTaskResetEventItemValue( void ) ;




TaskHandle_t xTaskGetCurrentTaskHandle( void ) ;




void vTaskSetTimeOutState( TimeOut_t * const pxTimeOut ) ;





BaseType_t xTaskCheckForTimeOut( TimeOut_t * const pxTimeOut, TickType_t * const pxTicksToWait ) ;





void vTaskMissedYield( void ) ;





BaseType_t xTaskGetSchedulerState( void ) ;





BaseType_t xTaskPriorityInherit( TaskHandle_t const pxMutexHolder ) ;





BaseType_t xTaskPriorityDisinherit( TaskHandle_t const pxMutexHolder ) ;
# 2281 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
void vTaskPriorityDisinheritAfterTimeout( TaskHandle_t const pxMutexHolder, UBaseType_t uxHighestPriorityWaitingTask ) ;




UBaseType_t uxTaskGetTaskNumber( TaskHandle_t xTask ) ;





void vTaskSetTaskNumber( TaskHandle_t xTask, const UBaseType_t uxHandle ) ;
# 2302 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
void vTaskStepTick( const TickType_t xTicksToJump ) ;
# 2318 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/task.h"
eSleepModeStatus eTaskConfirmSleepModeStatus( void ) ;





TaskHandle_t pvTaskIncrementMutexHeldCount( void ) ;





void vTaskInternalSetTimeOutState( TimeOut_t * const pxTimeOut ) ;
# 39 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h" 2
# 54 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h"
#define tmrCOMMAND_EXECUTE_CALLBACK_FROM_ISR ( ( BaseType_t ) -2 )
#define tmrCOMMAND_EXECUTE_CALLBACK ( ( BaseType_t ) -1 )
#define tmrCOMMAND_START_DONT_TRACE ( ( BaseType_t ) 0 )
#define tmrCOMMAND_START ( ( BaseType_t ) 1 )
#define tmrCOMMAND_RESET ( ( BaseType_t ) 2 )
#define tmrCOMMAND_STOP ( ( BaseType_t ) 3 )
#define tmrCOMMAND_CHANGE_PERIOD ( ( BaseType_t ) 4 )
#define tmrCOMMAND_DELETE ( ( BaseType_t ) 5 )

#define tmrFIRST_FROM_ISR_COMMAND ( ( BaseType_t ) 6 )
#define tmrCOMMAND_START_FROM_ISR ( ( BaseType_t ) 6 )
#define tmrCOMMAND_RESET_FROM_ISR ( ( BaseType_t ) 7 )
#define tmrCOMMAND_STOP_FROM_ISR ( ( BaseType_t ) 8 )
#define tmrCOMMAND_CHANGE_PERIOD_FROM_ISR ( ( BaseType_t ) 9 )
# 76 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h"
struct tmrTimerControl;
typedef struct tmrTimerControl * TimerHandle_t;




typedef void (*TimerCallbackFunction_t)( TimerHandle_t xTimer );





typedef void (*PendedFunction_t)( void *, uint32_t );
# 228 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h"
 TimerHandle_t xTimerCreate( const char * const pcTimerName,
        const TickType_t xTimerPeriodInTicks,
        const UBaseType_t uxAutoReload,
        void * const pvTimerID,
        TimerCallbackFunction_t pxCallbackFunction ) ;
# 386 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h"
void *pvTimerGetTimerID( const TimerHandle_t xTimer ) ;
# 407 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h"
void vTimerSetTimerID( TimerHandle_t xTimer, void *pvNewID ) ;
# 444 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h"
BaseType_t xTimerIsTimerActive( TimerHandle_t xTimer ) ;







TaskHandle_t xTimerGetTimerDaemonTaskHandle( void ) ;
# 504 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h"
#define xTimerStart(xTimer,xTicksToWait) xTimerGenericCommand( ( xTimer ), tmrCOMMAND_START, ( xTaskGetTickCount() ), NULL, ( xTicksToWait ) )
# 546 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h"
#define xTimerStop(xTimer,xTicksToWait) xTimerGenericCommand( ( xTimer ), tmrCOMMAND_STOP, 0U, NULL, ( xTicksToWait ) )
# 626 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h"
#define xTimerChangePeriod(xTimer,xNewPeriod,xTicksToWait) xTimerGenericCommand( ( xTimer ), tmrCOMMAND_CHANGE_PERIOD, ( xNewPeriod ), NULL, ( xTicksToWait ) )
# 664 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h"
#define xTimerDelete(xTimer,xTicksToWait) xTimerGenericCommand( ( xTimer ), tmrCOMMAND_DELETE, 0U, NULL, ( xTicksToWait ) )
# 788 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h"
#define xTimerReset(xTimer,xTicksToWait) xTimerGenericCommand( ( xTimer ), tmrCOMMAND_RESET, ( xTaskGetTickCount() ), NULL, ( xTicksToWait ) )
# 874 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h"
#define xTimerStartFromISR(xTimer,pxHigherPriorityTaskWoken) xTimerGenericCommand( ( xTimer ), tmrCOMMAND_START_FROM_ISR, ( xTaskGetTickCountFromISR() ), ( pxHigherPriorityTaskWoken ), 0U )
# 937 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h"
#define xTimerStopFromISR(xTimer,pxHigherPriorityTaskWoken) xTimerGenericCommand( ( xTimer ), tmrCOMMAND_STOP_FROM_ISR, 0, ( pxHigherPriorityTaskWoken ), 0U )
# 1010 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h"
#define xTimerChangePeriodFromISR(xTimer,xNewPeriod,pxHigherPriorityTaskWoken) xTimerGenericCommand( ( xTimer ), tmrCOMMAND_CHANGE_PERIOD_FROM_ISR, ( xNewPeriod ), ( pxHigherPriorityTaskWoken ), 0U )
# 1096 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h"
#define xTimerResetFromISR(xTimer,pxHigherPriorityTaskWoken) xTimerGenericCommand( ( xTimer ), tmrCOMMAND_RESET_FROM_ISR, ( xTaskGetTickCountFromISR() ), ( pxHigherPriorityTaskWoken ), 0U )
# 1187 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h"
BaseType_t xTimerPendFunctionCallFromISR( PendedFunction_t xFunctionToPend, void *pvParameter1, uint32_t ulParameter2, BaseType_t *pxHigherPriorityTaskWoken ) ;
# 1221 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h"
BaseType_t xTimerPendFunctionCall( PendedFunction_t xFunctionToPend, void *pvParameter1, uint32_t ulParameter2, TickType_t xTicksToWait ) ;
# 1232 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h"
const char * pcTimerGetName( TimerHandle_t xTimer ) ;
# 1243 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h"
TickType_t xTimerGetPeriod( TimerHandle_t xTimer ) ;
# 1258 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/FreeRTOSv10.1.1/Source/include/timers.h"
TickType_t xTimerGetExpiryTime( TimerHandle_t xTimer ) ;





BaseType_t xTimerCreateTimerTask( void ) ;
BaseType_t xTimerGenericCommand( TimerHandle_t xTimer, const BaseType_t xCommandID, const TickType_t xOptionalValue, BaseType_t * const pxHigherPriorityTaskWoken, const TickType_t xTicksToWait ) ;
# 30 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 2






#define WSF_TIMER_SEC_TO_TICKS(sec) ((1000 / WSF_MS_PER_TICK) * (sec))


#define WSF_TIMER_MS_TO_TICKS(ms) ((ms) / WSF_MS_PER_TICK)

#define CLK_TICKS_PER_WSF_TICKS (WSF_MS_PER_TICK*configTICK_RATE_HZ/1000)





wsfQueue_t wsfTimerTimerQueue;
TimerHandle_t xWsfTimer;
static uint32_t g_ui32LastTime = 0;
# 62 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
static void wsfTimerRemove(wsfTimer_t *pTimer)
{
  wsfTimer_t *pElem;
  wsfTimer_t *pPrev = 
# 65 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 3 4
                      ((void *)0)
# 65 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
                          ;

  pElem = (wsfTimer_t *) wsfTimerTimerQueue.pHead;


  while (pElem != 
# 70 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 3 4
                 ((void *)0)
# 70 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
                     )
  {
    if (pElem == pTimer)
    {
      break;
    }
    pPrev = pElem;
    pElem = pElem->pNext;
  }


  if (pElem != 
# 81 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 3 4
              ((void *)0)
# 81 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
                  )
  {
    WsfQueueRemove(&wsfTimerTimerQueue, pTimer, pPrev);

    pTimer->isStarted = 0;
  }
}
# 101 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
static void wsfTimerInsert(wsfTimer_t *pTimer, wsfTimerTicks_t ticks)
{
  wsfTimer_t *pElem;
  wsfTimer_t *pPrev = 
# 104 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 3 4
                      ((void *)0)
# 104 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
                          ;


  WsfTaskLock();


  if (pTimer->isStarted)
  {
    wsfTimerRemove(pTimer);
  }

  pTimer->isStarted = 1;
  pTimer->ticks = ticks;

  pElem = (wsfTimer_t *) wsfTimerTimerQueue.pHead;


  while (pElem != 
# 121 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 3 4
                 ((void *)0)
# 121 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
                     )
  {
    if (pTimer->ticks < pElem->ticks)
    {
      break;
    }
    pPrev = pElem;
    pElem = pElem->pNext;
  }


  WsfQueueInsert(&wsfTimerTimerQueue, pTimer, pPrev);


  WsfTaskUnlock();
}

static void WsfTimer_handler(TimerHandle_t xTimer)
{
  WsfTaskSetReady(0, 0x02);
}
# 153 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
void WsfTimerInit(void)
{
  {(&wsfTimerTimerQueue)->pHead = 
# 155 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 3 4
 ((void *)0)
# 155 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
 ; (&wsfTimerTimerQueue)->pTail = 
# 155 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 3 4
 ((void *)0)
# 155 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
 ;};

  if(xWsfTimer == 
# 157 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 3 4
                 ((void *)0)
# 157 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
                     )
  {
    xWsfTimer = xTimerCreate("WSF Timer", ( ( TickType_t ) ( ( ( TickType_t ) ( 10 ) * ( TickType_t ) 1000 ) / ( TickType_t ) 1000 ) ),
          ( ( BaseType_t ) 0 ), 
# 160 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 3 4
                  ((void *)0)
# 160 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
                      , WsfTimer_handler);
    if (( xWsfTimer ) == 0) while(1);;
    g_ui32LastTime = xTaskGetTickCount();
  }
}
# 178 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
void WsfTimerStartSec(wsfTimer_t *pTimer, wsfTimerTicks_t sec)
{
  ;


  wsfTimerInsert(pTimer, ((1000 / 10) * (sec)));
}
# 198 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
void WsfTimerStartMs(wsfTimer_t *pTimer, wsfTimerTicks_t ms)
{
  ;


  wsfTimerInsert(pTimer, ((ms) / 10));
}
# 217 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
void WsfTimerStop(wsfTimer_t *pTimer)
{
  ;


  WsfTaskLock();

  wsfTimerRemove(pTimer);


  WsfTaskUnlock();
}
# 241 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
void WsfTimerUpdate(wsfTimerTicks_t ticks)
{
  wsfTimer_t *pElem;


  WsfTaskLock();

  pElem = (wsfTimer_t *) wsfTimerTimerQueue.pHead;


  while (pElem != 
# 251 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 3 4
                 ((void *)0)
# 251 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
                     )
  {

    if (pElem->ticks > ticks)
    {
      pElem->ticks -= ticks;
    }
    else
    {
      pElem->ticks = 0;


      WsfTaskSetReady(pElem->handlerId, 0x02);
    }

    pElem = pElem->pNext;
  }


  WsfTaskUnlock();
}
# 286 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
wsfTimerTicks_t WsfTimerNextExpiration(bool_t *pTimerRunning)
{
  wsfTimerTicks_t ticks;


  WsfTaskLock();

  if (wsfTimerTimerQueue.pHead == 
# 293 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 3 4
                                 ((void *)0)
# 293 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
                                     )
  {
    *pTimerRunning = 0;
    ticks = 0;
  }
  else
  {
    *pTimerRunning = 1;
    ticks = ((wsfTimer_t *) wsfTimerTimerQueue.pHead)->ticks;
  }


  WsfTaskUnlock();

  return ticks;
}
# 321 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
wsfTimer_t *WsfTimerServiceExpired(wsfTaskId_t taskId)
{
  wsfTimer_t *pElem;
  wsfTimer_t *pPrev = 
# 324 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 3 4
                      ((void *)0)
# 324 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
                          ;


  (void)taskId;


  WsfTaskLock();


  if (((pElem = (wsfTimer_t *) wsfTimerTimerQueue.pHead) != 
# 333 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 3 4
                                                           ((void *)0)
# 333 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
                                                               ) &&
      (pElem->ticks == 0))
  {

    WsfQueueRemove(&wsfTimerTimerQueue, pElem, pPrev);

    pElem->isStarted = 0;


    WsfTaskUnlock();

    ;


    return pElem;
  }


  WsfTaskUnlock();

  return 
# 353 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 3 4
        ((void *)0)
# 353 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
            ;
}






void WsfTimerUpdateTicks(void)
{
    uint32_t ui32CurrentTime, ui32ElapsedTime;
    bool_t bTimerRunning;
    wsfTimerTicks_t xNextExpiration;




    ui32CurrentTime = xTaskGetTickCount();






    ui32ElapsedTime = ui32CurrentTime - g_ui32LastTime;




    if ( (ui32ElapsedTime / (10*1000/1000)) > 0 )
    {




        WsfTimerUpdate(ui32ElapsedTime / (10*1000/1000));

        g_ui32LastTime = ui32CurrentTime;
    }




    xNextExpiration = WsfTimerNextExpiration(&bTimerRunning);





    if ( xNextExpiration )
    {
        if (( ( ( ( BaseType_t ) 1 ) ) == xTimerGenericCommand( ( xWsfTimer ), ( ( BaseType_t ) 4 ), ( ( ( TickType_t ) ( ( ( TickType_t ) ( xNextExpiration*(10*1000/1000) ) * ( TickType_t ) 1000 ) / ( TickType_t ) 1000 ) ) ), 
# 404 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c" 3 4
       ((void *)0)
# 404 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_timer.c"
       , ( 100 ) ) ) == 0) while(1);
                                                                              ;
    }
}
