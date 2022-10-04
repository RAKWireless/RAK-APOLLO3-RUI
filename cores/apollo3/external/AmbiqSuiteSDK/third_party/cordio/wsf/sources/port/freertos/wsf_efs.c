# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
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
#define LORA_RF_LP 1
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
#define AM_BLE_USE_NVM 1
#define AM_CUSTOM_BDADDR 1
#define AM_NUS_ADD 1
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
#define SOFT_SE 1
#define SECURE_ELEMENT_PRE_PROVISIONED 1
#define LORAMAC_CLASSB_ENABLED 1
#define WISBLOCK_BASE_5005_O 1
#define SUPPORT_BLE 1
#define SUPPORT_SPI 1
#define SUPPORT_AT 1
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
# 23 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 1 3







#define _STRING_H_ 

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_ansi.h" 1 3







#define _ANSIDECL_H_ 

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 1 3







#define __NEWLIB_H__ 1





# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_newlib_version.h" 1 3



#define _NEWLIB_VERSION_H__ 1

#define _NEWLIB_VERSION "3.3.0"
#define __NEWLIB__ 3
#define __NEWLIB_MINOR__ 3
#define __NEWLIB_PATCHLEVEL__ 0
# 15 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 2 3



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
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 1 3
# 22 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3
#define _SYS_FEATURES_H 
# 33 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3
#define __GNUC_PREREQ(maj,min) ((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))






#define __GNUC_PREREQ__(ma,mi) __GNUC_PREREQ(ma, mi)
# 249 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3
#define __ATFILE_VISIBLE 0





#define __BSD_VISIBLE 0





#define __GNU_VISIBLE 0







#define __ISO_C_VISIBLE 1999







#define __LARGEFILE_VISIBLE 0





#define __MISC_VISIBLE 0
# 299 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3
#define __POSIX_VISIBLE 0





#define __SVID_VISIBLE 0
# 319 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3
#define __XSI_VISIBLE 0
# 330 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3
#define __SSP_FORTIFY_LEVEL 0
# 6 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/config.h" 2 3
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
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 1 3





#define _MACHINE__DEFAULT_TYPES_H 
# 15 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3
#define __EXP(x) __ ##x ##__
# 26 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3
#define __have_longlong64 1






#define __have_long32 1







typedef signed char __int8_t;

typedef unsigned char __uint8_t;



#define ___int8_t_defined 1







typedef short int __int16_t;

typedef short unsigned int __uint16_t;



#define ___int16_t_defined 1
# 77 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3
typedef long int __int32_t;

typedef long unsigned int __uint32_t;



#define ___int32_t_defined 1
# 103 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3
typedef long long int __int64_t;

typedef long long unsigned int __uint64_t;



#define ___int64_t_defined 1
# 134 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3
typedef signed char __int_least8_t;

typedef unsigned char __uint_least8_t;



#define ___int_least8_t_defined 1
# 160 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3
typedef short int __int_least16_t;

typedef short unsigned int __uint_least16_t;



#define ___int_least16_t_defined 1
# 182 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3
typedef long int __int_least32_t;

typedef long unsigned int __uint_least32_t;



#define ___int_least32_t_defined 1
# 200 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3
typedef long long int __int_least64_t;

typedef long long unsigned int __uint_least64_t;



#define ___int_least64_t_defined 1







typedef long long int __intmax_t;







typedef long long unsigned int __uintmax_t;







typedef int __intptr_t;

typedef unsigned int __uintptr_t;
# 244 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3
#undef __EXP
# 8 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_types.h" 2 3
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
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 1 3
# 43 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define _SYS_CDEFS_H_ 



# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 48 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 2 3

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
# 78 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __has_extension __has_feature


#define __has_feature(x) 0
# 94 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __BEGIN_DECLS 
#define __END_DECLS 
# 107 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
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
# 177 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __P(protos) protos
#define __CONCAT1(x,y) x ## y
#define __CONCAT(x,y) __CONCAT1(x,y)
#define __STRING(x) #x
#define __XSTRING(x) __STRING(x)

#define __const const
#define __signed signed
#define __volatile volatile
# 230 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __weak_symbol __attribute__((__weak__))
# 243 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
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
# 280 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define _Alignas(x) __aligned(x)






#define _Alignof(x) __alignof(x)
# 296 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define _Atomic(T) struct { T volatile __val; }





#define _Noreturn __dead2
# 331 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define _Thread_local __thread
# 351 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __generic(expr,t,yes,no) __builtin_choose_expr( __builtin_types_compatible_p(__typeof(expr), t), yes, no)
# 366 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
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
# 434 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __restrict restrict
# 467 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __predict_true(exp) __builtin_expect((exp), 1)
#define __predict_false(exp) __builtin_expect((exp), 0)






#define __null_sentinel __attribute__((__sentinel__))
#define __exported __attribute__((__visibility__("default")))


#define __hidden __attribute__((__visibility__("hidden")))
# 489 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __offsetof(type,field) offsetof(type, field)
#define __rangeof(type,start,end) (__offsetof(type, end) - __offsetof(type, start))
# 500 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __containerof(x,s,m) ({ const volatile __typeof(((s *)0)->m) *__x = (x); __DEQUALIFY(s *, (const volatile char *)__x - __offsetof(s, m));})
# 522 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __printflike(fmtarg,firstvararg) __attribute__((__format__ (__printf__, fmtarg, firstvararg)))

#define __scanflike(fmtarg,firstvararg) __attribute__((__format__ (__scanf__, fmtarg, firstvararg)))

#define __format_arg(fmtarg) __attribute__((__format_arg__ (fmtarg)))
#define __strfmonlike(fmtarg,firstvararg) __attribute__((__format__ (__strfmon__, fmtarg, firstvararg)))

#define __strftimelike(fmtarg,firstvararg) __attribute__((__format__ (__strftime__, fmtarg, firstvararg)))
# 539 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __printf0like(fmtarg,firstvararg) 




#define __strong_reference(sym,aliassym) extern __typeof (sym) aliassym __attribute__ ((__alias__ (#sym)))




#define __weak_reference(sym,alias) __asm__(".weak " #alias); __asm__(".equ " #alias ", " #sym)


#define __warn_references(sym,msg) __asm__(".section .gnu.warning." #sym); __asm__(".asciz \"" msg "\""); __asm__(".previous")



#define __sym_compat(sym,impl,verid) __asm__(".symver " #impl ", " #sym "@" #verid)

#define __sym_default(sym,impl,verid) __asm__(".symver " #impl ", " #sym "@@" #verid)
# 593 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
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
# 653 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __arg_type_tag(arg_kind,arg_idx,type_tag_idx) 
#define __datatype_type_tag(kind,type) 
# 672 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
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
# 13 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 2 3


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


# 24 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_types.h" 1
# 23 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_types.h"
#define WSF_TYPES_H 
# 34 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_types.h"
#define TRUE 1



#define FALSE 0
# 48 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_types.h"
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
# 49 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_types.h" 2
# 60 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_types.h"

# 60 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_types.h"
typedef uint8_t bool_t;
# 25 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h" 1
# 24 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
#define WSF_EFS_H 
# 36 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
#define WSF_EFS_MAX_FILES 6




#define WSF_EFS_MAX_MEDIA 4



#define WSF_EFS_SUCCESS 0
#define WSF_EFS_FAILURE 1
#define WSF_EFS_GET_FAILED 0xFFFF
#define WSF_EFS_PUT_FAILED 0xFFFF


#define WSF_EFS_INVALID_HANDLE 0xFFFF
#define WSF_EFS_INVALID_OFFSET 0xFFFFFFFF
#define WSF_EFS_INVALID_SIZE 0xFFFFFFFF
#define WSF_EFS_INVALID_MEDIA 0xFF


#define WSF_EFS_FILE_TYPE_BULK 0
#define WSF_EFS_FILE_TYPE_STREAM 1


#define WSF_EFS_FILE_OFFSET_ANY 0xFFFFFFFF


#define WSF_EFS_REMOTE_PERMISSIONS_MASK 0xFF
#define WSF_EFS_REMOTE_GET_PERMITTED 0x01
#define WSF_EFS_REMOTE_PUT_PERMITTED 0x02
#define WSF_EFS_REMOTE_ERASE_PERMITTED 0x04
#define WSF_EFS_REMOTE_VERIFY_PERMITTED 0x08
#define WSF_EFS_LOCAL_GET_PERMITTED 0x0100
#define WSF_EFS_LOCAL_PUT_PERMITTED 0x0200
#define WSF_EFS_LOCAL_ERASE_PERMITTED 0x0400
#define WSF_EFS_REMOTE_VISIBLE 0x0800


#define WSF_EFS_NAME_LEN 16


#define WSF_EFS_VERSION_LEN 16


#define WSF_EFS_WDXS_PUT_COMPLETE_CMD 0x00
#define WSF_EFS_VALIDATE_CMD 0x01


#define WSF_EFS_USER_CMD 0x80






typedef uint16_t wsfEfsHandle_t;


typedef struct
{
  char name[16];
  char version[16];
  uint16_t permissions;
  uint8_t type;
} wsfEsfAttributes_t;


typedef struct
{
  uint32_t maxSize;
  uint32_t address;
  uint8_t media;
  uint32_t size;
  wsfEsfAttributes_t attributes;
} wsfEfsControl_t;


typedef struct
{
  wsfEfsHandle_t handle;
  uint32_t size;
  wsfEsfAttributes_t attributes;
} wsfEfsFileInfo_t;
# 132 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
typedef uint8_t wsfMediaInitFunc_t(void);
# 146 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
typedef uint8_t wsfMediaEraseFunc_t(uint32_t address, uint32_t size);
# 161 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
typedef uint8_t wsfMediaReadFunc_t(uint8_t *pBuf, uint32_t address, uint32_t size);
# 176 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
typedef uint8_t wsfMediaWriteFunc_t(const uint8_t *pBuf, uint32_t address, uint32_t size);
# 190 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
typedef uint8_t wsfMediaHandleCmdFunc_t(uint8_t cmd, uint32_t param);


typedef struct
{
  uint32_t startAddress;
  uint32_t endAddress;
  uint32_t pageSize;
  wsfMediaInitFunc_t *init;
  wsfMediaEraseFunc_t *erase;
  wsfMediaReadFunc_t *read;
  wsfMediaWriteFunc_t *write;
  wsfMediaHandleCmdFunc_t *handleCmd;
} wsfEfsMedia_t;


typedef const wsfEfsMedia_t *pWsfEfsMedia_t;
# 221 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
void WsfEfsInit(void);
# 237 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
wsfEfsHandle_t WsfEfsAddFile(uint32_t maxSize, uint8_t media, wsfEsfAttributes_t *pAttr, uint32_t offset);
# 250 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
uint8_t WsfEfsRemoveFile(wsfEfsHandle_t handle);
# 263 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
uint8_t WsfEfsErase(wsfEfsHandle_t handle);
# 277 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
uint8_t WsfEfsGetAttributes(wsfEfsHandle_t handle, wsfEsfAttributes_t *pAttr);
# 291 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
uint8_t WsfEfsSetAttributes(wsfEfsHandle_t handle, wsfEsfAttributes_t *pInfo);
# 307 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
uint16_t WsfEfsGet(wsfEfsHandle_t handle, uint32_t offset, uint8_t *pBuffer, uint16_t len);
# 323 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
uint16_t WsfEfsPut(wsfEfsHandle_t handle, uint32_t offset, const uint8_t *pBuffer, uint16_t len);
# 337 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
uint8_t WsfEfsRegisterMedia(const wsfEfsMedia_t *pMediaCtrl, uint8_t mediaID);
# 350 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
wsfEfsControl_t *WsfEfsGetFileByHandle(wsfEfsHandle_t handle);
# 363 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
char *WsfEfsGetFileName(wsfEfsHandle_t handle);
# 376 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
char *WsfEfsGetFileVersion(wsfEfsHandle_t handle);
# 389 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
uint32_t WsfEfsGetFileSize(wsfEfsHandle_t handle);
# 402 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
uint32_t WsfEfsGetFileMaxSize(wsfEfsHandle_t handle);
# 415 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
uint8_t WsfEfsGetFileType(wsfEfsHandle_t handle);
# 428 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
uint16_t WsfEfsGetFilePermissions(wsfEfsHandle_t handle);
# 443 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/include/wsf_efs.h"
uint8_t WsfEfsMediaSpecificCommand(wsfEfsHandle_t handle, uint8_t cmd, uint32_t param);
# 26 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_assert.h" 1
# 23 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_assert.h"
#define WSF_ASSERT_H 
# 33 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_assert.h"
void WsfAssert(const char *pFile, uint16_t line);
# 51 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_assert.h"
#define WSF_ASSERT(expr) 
# 65 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_assert.h"
#define WSF_CT_ASSERT(expr) extern char wsf_ct_assert[(expr) ? 1 : -1]
# 27 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c" 2
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
# 28 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_cs.h" 1
# 23 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_cs.h"
#define WSF_CS_H 

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
# 26 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_cs.h" 2
# 44 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_cs.h"
#define WSF_CS_INIT(cs) 
# 55 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_cs.h"
#define WSF_CS_ENTER(cs) WsfCsEnter()
# 66 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_cs.h"
#define WSF_CS_EXIT(cs) WsfCsExit()




void WsfCsEnter(void);
void WsfCsExit(void);
# 29 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/util/bstream.h" 1
# 23 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/util/bstream.h"
#define BSTREAM_H 

# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/util/bda.h" 1
# 23 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/util/bda.h"
#define BDA_H 
# 34 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/util/bda.h"
#define BDA_ADDR_LEN 6


#define BDA_ADDR_STR_LEN (BDA_ADDR_LEN * 2)


#define BDA_ADDR_IS_RPA(bda) (((bda)[5] & 0xC0) == 0x40)


#define BDA_ADDR_IS_NRPA(bda) (((bda)[5] & 0xC0) == 0x00)


#define BDA_ADDR_IS_STATIC(bda) (((bda)[5] & 0xC0) == 0xC0)


#define BDA64_ADDR_IS_RPA(bda64) ((((bda64) >> 40) & 0xC0) == 0x40)


#define BDA64_ADDR_IS_NRPA(bda64) ((((bda64) >> 40) & 0xC0) == 0x00)


#define BDA64_ADDR_IS_STATIC(bda64) ((((bda64) >> 40) & 0xC0) == 0xC0)






typedef uint8_t bdAddr_t[6];
# 80 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/util/bda.h"
void BdaCpy(uint8_t *pDst, const uint8_t *pSrc);
# 95 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/util/bda.h"
bool_t BdaCmp(const uint8_t *pAddr1, const uint8_t *pAddr2);
# 108 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/util/bda.h"
uint8_t *BdaClr(uint8_t *pDst);
# 121 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/util/bda.h"
bool_t BdaIsZeros(const uint8_t *pAddr);
# 134 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/util/bda.h"
char *Bda2Str(const uint8_t *pAddr);
# 26 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/util/bstream.h" 2
# 38 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/util/bstream.h"
#define BYTES_TO_UINT16(n,p) {n = ((uint16_t)(p)[0] + ((uint16_t)(p)[1] << 8));}

#define BYTES_TO_UINT24(n,p) {n = ((uint16_t)(p)[0] + ((uint16_t)(p)[1] << 8) + ((uint16_t)(p)[2] << 16));}


#define BYTES_TO_UINT32(n,p) {n = ((uint32_t)(p)[0] + ((uint32_t)(p)[1] << 8) + ((uint32_t)(p)[2] << 16) + ((uint32_t)(p)[3] << 24));}


#define BYTES_TO_UINT40(n,p) {n = ((uint64_t)(p)[0] + ((uint64_t)(p)[1] << 8) + ((uint64_t)(p)[2] << 16) + ((uint64_t)(p)[3] << 24) + ((uint64_t)(p)[4] << 32));}



#define BYTES_TO_UINT64(n,p) {n = ((uint64_t)(p)[0] + ((uint64_t)(p)[1] << 8) + ((uint64_t)(p)[2] << 16) + ((uint64_t)(p)[3] << 24) + ((uint64_t)(p)[4] << 32) + ((uint64_t)(p)[5] << 40) + ((uint64_t)(p)[6] << 48) + ((uint64_t)(p)[7] << 56));}







#define UINT16_TO_BYTES(n) ((uint8_t) (n)), ((uint8_t)((n) >> 8))
#define UINT32_TO_BYTES(n) ((uint8_t) (n)), ((uint8_t)((n) >> 8)), ((uint8_t)((n) >> 16)), ((uint8_t)((n) >> 24))




#define UINT16_TO_BYTE0(n) ((uint8_t) (n))
#define UINT16_TO_BYTE1(n) ((uint8_t) ((n) >> 8))

#define UINT32_TO_BYTE0(n) ((uint8_t) (n))
#define UINT32_TO_BYTE1(n) ((uint8_t) ((n) >> 8))
#define UINT32_TO_BYTE2(n) ((uint8_t) ((n) >> 16))
#define UINT32_TO_BYTE3(n) ((uint8_t) ((n) >> 24))




#define BSTREAM_TO_INT8(n,p) {n = (int8_t)(*(p)++);}
#define BSTREAM_TO_UINT8(n,p) {n = (uint8_t)(*(p)++);}
#define BSTREAM_TO_UINT16(n,p) {BYTES_TO_UINT16(n, p); p += 2;}
#define BSTREAM_TO_UINT24(n,p) {BYTES_TO_UINT24(n, p); p += 3;}
#define BSTREAM_TO_UINT32(n,p) {BYTES_TO_UINT32(n, p); p += 4;}
#define BSTREAM_TO_UINT40(n,p) {BYTES_TO_UINT40(n, p); p += 5;}
#define BSTREAM_TO_UINT64(n,p) {n = BstreamToUint64(p); p += 8;}
#define BSTREAM_TO_BDA(bda,p) {BdaCpy(bda, p); p += BDA_ADDR_LEN;}
#define BSTREAM_TO_BDA64(bda,p) {bda = BstreamToBda64(p); p += BDA_ADDR_LEN;}




#define UINT8_TO_BSTREAM(p,n) {*(p)++ = (uint8_t)(n);}
#define UINT16_TO_BSTREAM(p,n) {*(p)++ = (uint8_t)(n); *(p)++ = (uint8_t)((n) >> 8);}
#define UINT24_TO_BSTREAM(p,n) {*(p)++ = (uint8_t)(n); *(p)++ = (uint8_t)((n) >> 8); *(p)++ = (uint8_t)((n) >> 16);}

#define UINT32_TO_BSTREAM(p,n) {*(p)++ = (uint8_t)(n); *(p)++ = (uint8_t)((n) >> 8); *(p)++ = (uint8_t)((n) >> 16); *(p)++ = (uint8_t)((n) >> 24);}

#define UINT40_TO_BSTREAM(p,n) {*(p)++ = (uint8_t)(n); *(p)++ = (uint8_t)((n) >> 8); *(p)++ = (uint8_t)((n) >> 16); *(p)++ = (uint8_t)((n) >> 24); *(p)++ = (uint8_t)((n) >> 32);}


#define UINT64_TO_BSTREAM(p,n) {Uint64ToBstream(p, n); p += sizeof(uint64_t);}
#define BDA_TO_BSTREAM(p,bda) {BdaCpy(p, bda); p += BDA_ADDR_LEN;}
#define BDA64_TO_BSTREAM(p,bda) {Bda64ToBstream(p, bda); p += BDA_ADDR_LEN;}




#define UINT16_TO_BUF(p,n) {(p)[0] = (uint8_t)(n); (p)[1] = (uint8_t)((n) >> 8);}
#define UINT24_TO_BUF(p,n) {(p)[0] = (uint8_t)(n); (p)[1] = (uint8_t)((n) >> 8); (p)[2] = (uint8_t)((n) >> 16);}

#define UINT32_TO_BUF(p,n) {(p)[0] = (uint8_t)(n); (p)[1] = (uint8_t)((n) >> 8); (p)[2] = (uint8_t)((n) >> 16); (p)[3] = (uint8_t)((n) >> 24);}

#define UINT40_TO_BUF(p,n) {(p)[0] = (uint8_t)(n); (p)[1] = (uint8_t)((n) >> 8); (p)[2] = (uint8_t)((n) >> 16); (p)[3] = (uint8_t)((n) >> 24); (p)[4] = (uint8_t)((n) >> 32);}






#define BYTES_UINT16_CMP(p,n) ((p)[1] == UINT16_TO_BYTE1(n) && (p)[0] == UINT16_TO_BYTE0(n))




#define FLT_TO_UINT32(m,e) ((m) | ((int32_t)(e) << 24))
#define UINT32_TO_FLT(m,e,n) {m = UINT32_TO_FLT_M(n); e = UINT32_TO_FLT_E(n);}
#define UINT32_TO_FLT_M(n) ((((n) & 0x00FFFFFF) >= 0x00800000) ? ((int32_t)(((n) | 0xFF000000))) : ((int32_t)((n) & 0x00FFFFFF)))

#define UINT32_TO_FLT_E(n) ((int8_t)(n >> 24))



#define SFLT_TO_UINT16(m,e) ((m) | ((int16_t)(e) << 12))
#define UINT16_TO_SFLT(m,e,n) {m = UINT16_TO_SFLT_M(n); e = UINT16_TO_SFLT_E(n);}
#define UINT16_TO_SFLT_M(n) ((((n) & 0x0FFF) >= 0x0800) ? ((int16_t)(((n) | 0xF000))) : ((int16_t)((n) & 0x0FFF)))

#define UINT16_TO_SFLT_E(n) (((n >> 12) >= 0x0008) ? ((int8_t)(((n >> 12) | 0xF0))) : ((int8_t)(n >> 12)))






uint64_t BstreamToBda64(const uint8_t *p);
uint64_t BstreamToUint64(const uint8_t *p);
void Bda64ToBstream(uint8_t *p, uint64_t bda);
void Uint64ToBstream(uint8_t *p, uint64_t n);
# 30 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c" 2


static pWsfEfsMedia_t wsfEfsMediaTbl[4];


static wsfEfsControl_t wsfEfsFileTbl[6];
# 48 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
static bool_t wsfEfsMediaValid(uint8_t media)
{
  if (media < 4 && wsfEfsMediaTbl[media])
  {
    return 1;
  }

  return 0;
}
# 69 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
wsfEfsControl_t *WsfEfsGetFileByHandle(wsfEfsHandle_t handle)
{
  if ((handle < 6) &&
      (wsfEfsFileTbl[handle].maxSize != 0xFFFFFFFF))
  {
    return &wsfEfsFileTbl[handle];
  }

  return 
# 77 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c" 3 4
        ((void *)0)
# 77 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
            ;
}
# 94 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
static bool_t wsfEfsFileOverlap(wsfEfsHandle_t handle, uint8_t media, uint32_t address, uint32_t size)
{
  if (wsfEfsMediaValid(media))
  {

    if (size && (wsfEfsFileTbl[handle].maxSize) &&
        (wsfEfsFileTbl[handle].maxSize != 0xFFFFFFFF) &&
        (wsfEfsFileTbl[handle].media == media))
    {

      uint32_t top1 = wsfEfsFileTbl[handle].address;
      uint32_t bottom1 = wsfEfsFileTbl[handle].address + wsfEfsFileTbl[handle].maxSize - 1;
      uint32_t top2 = address;
      uint32_t bottom2 = address + size - 1;


      if ((top2 >= top1) && (top2 <= bottom1))
        return 1;

      if ((bottom2 >= top1) && (bottom2 <= bottom1))
        return 1;
    }
  }

  return 0;
}
# 134 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
static uint32_t wsfEfsFindAvailableOffset(uint8_t media, uint32_t size)
{
  if (wsfEfsMediaValid(media))
  {
    int8_t i;
    uint32_t address = wsfEfsMediaTbl[media]->startAddress;

    for (i=0; i<6; i++)
    {
      if (wsfEfsFileOverlap(i, media, address, size))
      {


        address = wsfEfsFileTbl[i].address + wsfEfsFileTbl[i].maxSize;
        address += address % wsfEfsMediaTbl[media]->pageSize;
        i = -1;

        if (address + size > wsfEfsMediaTbl[media]->endAddress)
          return 0xFFFFFFFF;
      }
    }

    return address;
  }

  return 0xFFFFFFFF;
}
# 171 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
void WsfEfsInit(void)
{
  int8_t i;


  memset((void *) wsfEfsMediaTbl, 0, sizeof(wsfEfsMediaTbl));


  for (i=0; i<6; i++)
  {
    wsfEfsFileTbl[i].maxSize = 0xFFFFFFFF;
  }
}
# 199 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
wsfEfsHandle_t WsfEfsAddFile(uint32_t maxSize, uint8_t media, wsfEsfAttributes_t *pAttr, uint32_t offset)
{
  wsfEfsHandle_t handle;
  uint32_t address = offset;
  wsfEfsControl_t *pFile = 
# 203 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c" 3 4
                          ((void *)0)
# 203 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
                              ;

  if (wsfEfsMediaValid(media))
  {

    for (handle = 0; handle < 6; handle++)
    {
      if (wsfEfsFileTbl[handle].maxSize == 0xFFFFFFFF)
      {
        pFile = &wsfEfsFileTbl[handle];
        break;
      }
    }

    if (pFile)
    {
      if (address == 0xFFFFFFFF)
      {
        address = wsfEfsFindAvailableOffset(media, maxSize);

        if (address == 0xFFFFFFFF)
          return 0xFFFF;
      }
      else
      {
        int i;




        address += wsfEfsMediaTbl[media]->startAddress;


        if (wsfEfsMediaTbl[media]->pageSize)
        {
          address += address % wsfEfsMediaTbl[media]->pageSize;
        }


        for (i=0; i<6; i++)
        {
          if (wsfEfsFileOverlap(i, media, address, maxSize) == 1)
            return 0xFFFF;
        }
      }


      pFile->size = 0;
      pFile->media = media;
      pFile->address = address;
      memcpy(&pFile->attributes, pAttr, sizeof(wsfEsfAttributes_t));



      pFile->maxSize = maxSize;
      if (wsfEfsMediaTbl[media]->pageSize)
      {
        pFile->maxSize += maxSize % wsfEfsMediaTbl[media]->pageSize;
      }

      return handle;
    }
  }

  return 0xFFFF;
}
# 281 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
uint8_t WsfEfsRemoveFile(wsfEfsHandle_t handle)
{
  if (handle < 6)
  {
    wsfEfsFileTbl[handle].maxSize = 0xFFFFFFFF;
    return 0;
  }

  return 1;
}
# 303 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
uint8_t WsfEfsErase(wsfEfsHandle_t handle)
{
  uint8_t status = 1;
  wsfEfsControl_t *pFile;

  if ((pFile = WsfEfsGetFileByHandle(handle)) != 
# 308 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c" 3 4
                                                ((void *)0)
# 308 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
                                                    )
  {
    if (pFile->attributes.permissions & (0x04 | 0x0400))
    {
      uint8_t media = pFile->media;

      if (wsfEfsMediaTbl[media]->erase)
      {
        uint32_t address = pFile->address;
        uint32_t size = pFile->maxSize;

        status = wsfEfsMediaTbl[media]->erase(address, size);
        pFile->size = 0;
      }
    }
  }

  return status;
}
# 340 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
uint8_t WsfEfsGetAttributes(wsfEfsHandle_t handle, wsfEsfAttributes_t *pAttr)
{
  wsfEfsControl_t *pFile;

  if (((pFile = WsfEfsGetFileByHandle(handle)) != 
# 344 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c" 3 4
                                                 ((void *)0)
# 344 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
                                                     ) && pAttr)
  {
    memcpy(pAttr, &pFile->attributes, sizeof(wsfEsfAttributes_t));
    return 0;
  }

  return 1;
}
# 365 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
uint8_t WsfEfsSetAttributes(wsfEfsHandle_t handle, wsfEsfAttributes_t *pAttr)
{
  wsfEfsControl_t *pFile;

  if (((pFile = WsfEfsGetFileByHandle(handle)) != 
# 369 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c" 3 4
                                                 ((void *)0)
# 369 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
                                                     ) && pAttr)
  {
    memcpy(&pFile->attributes, pAttr, sizeof(wsfEsfAttributes_t));
    return 0;
  }

  return 1;
}
# 392 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
uint16_t WsfEfsGet(wsfEfsHandle_t handle, uint32_t offset, uint8_t *pBuffer, uint16_t len)
{
  wsfEfsControl_t *pFile;

  if (((pFile = WsfEfsGetFileByHandle(handle)) != 
# 396 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c" 3 4
                                                 ((void *)0)
# 396 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
                                                     ) && pBuffer)
  {
    if (pFile->attributes.permissions & (0x01 | 0x0100))
    {
      uint8_t media = pFile->media;

      if (wsfEfsMediaTbl[media]->read)
      {
        if (pFile->attributes.type == 1)
        {
          wsfEfsMediaTbl[media]->read(pBuffer, 0, len);
          return len;
        }
        else if (offset < pFile->size)
        {
          uint32_t address = pFile->address + offset;

          if (offset + len > pFile->size)
          {
            len = (uint16_t) (pFile->size - offset);
          }

          wsfEfsMediaTbl[media]->read(pBuffer, address, len);

          return len;
        }
      }
    }
  }

  return 0;
}
# 443 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
uint16_t WsfEfsPut(wsfEfsHandle_t handle, uint32_t offset, const uint8_t *pBuffer, uint16_t len)
{
  wsfEfsControl_t *pFile;

  if (((pFile = WsfEfsGetFileByHandle(handle)) != 
# 447 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c" 3 4
                                                 ((void *)0)
# 447 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
                                                     ) && pBuffer)
  {
    if (pFile->attributes.permissions & (0x02 | 0x0200))
    {
      uint8_t media = pFile->media;

      if (wsfEfsMediaTbl[media]->write)
      {
        if (pFile->attributes.type == 1)
        {
          wsfEfsMediaTbl[media]->write(pBuffer, 0, len);
          return len;
        }
        else if (offset < pFile->maxSize)
        {
          uint32_t address = pFile->address + offset;

          if (offset + len > pFile->maxSize)
          {
            len = (uint16_t) (pFile->maxSize - offset);
          }

          wsfEfsMediaTbl[media]->write(pBuffer, address, len);


          if (offset + len > pFile->size)
          {
            pFile->size = offset + len;
          }

          return len;
        }
      }
    }
  }

  return 0;
}
# 497 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
char *WsfEfsGetFileName(wsfEfsHandle_t handle)
{
  wsfEfsControl_t *pFile;

  if (((pFile = WsfEfsGetFileByHandle(handle)) != 
# 501 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c" 3 4
                                                 ((void *)0)
# 501 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
                                                     ))
  {
    return pFile->attributes.name;
  }

  return "Unknown";
}
# 520 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
char *WsfEfsGetFileVersion(wsfEfsHandle_t handle)
{
  wsfEfsControl_t *pFile;

  if (((pFile = WsfEfsGetFileByHandle(handle)) != 
# 524 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c" 3 4
                                                 ((void *)0)
# 524 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
                                                     ))
  {
    return pFile->attributes.version;
  }

  return "Unknown";
}
# 543 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
uint32_t WsfEfsGetFileMaxSize(wsfEfsHandle_t handle)
{
  wsfEfsControl_t *pFile;

  if (((pFile = WsfEfsGetFileByHandle(handle)) != 
# 547 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c" 3 4
                                                 ((void *)0)
# 547 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
                                                     ))
  {
    return pFile->maxSize;
  }

  return 0;
}
# 566 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
uint32_t WsfEfsGetFileSize(wsfEfsHandle_t handle)
{
  wsfEfsControl_t *pFile;

  if (((pFile = WsfEfsGetFileByHandle(handle)) != 
# 570 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c" 3 4
                                                 ((void *)0)
# 570 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
                                                     ))
  {
    return pFile->size;
  }

  return 0;
}
# 589 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
uint8_t WsfEfsGetFileType(wsfEfsHandle_t handle)
{
  wsfEfsControl_t *pFile;

  if (((pFile = WsfEfsGetFileByHandle(handle)) != 
# 593 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c" 3 4
                                                 ((void *)0)
# 593 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
                                                     ))
  {
    return pFile->attributes.type;
  }

  return 0;
}
# 612 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
uint16_t WsfEfsGetFilePermissions(wsfEfsHandle_t handle)
{
  wsfEfsControl_t *pFile;

  if (((pFile = WsfEfsGetFileByHandle(handle)) != 
# 616 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c" 3 4
                                                 ((void *)0)
# 616 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
                                                     ))
  {
    return pFile->attributes.permissions;
  }

  return 0;
}
# 637 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
uint8_t WsfEfsMediaSpecificCommand(wsfEfsHandle_t handle, uint8_t cmd, uint32_t param)
{
  if (WsfEfsGetFileByHandle(handle))
  {
    uint8_t media = wsfEfsFileTbl[handle].media;


    if (wsfEfsMediaTbl[media]->handleCmd)
    {
      return wsfEfsMediaTbl[media]->handleCmd(cmd, param);
    }
  }

  return 0;
}
# 665 "/home/jenkins/workspace/RUI_Release/rui-v3/external/AmbiqSuiteSDK/third_party/cordio/wsf/sources/port/freertos/wsf_efs.c"
uint8_t WsfEfsRegisterMedia(const wsfEfsMedia_t *pMediaCtrl, uint8_t mediaID)
{
  if (mediaID < 4 && pMediaCtrl)
  {
    wsfEfsMediaTbl[mediaID] = pMediaCtrl;


    if (pMediaCtrl->init)
    {
      pMediaCtrl->init();
    }

    return 0;
  }

  return 1;
}
