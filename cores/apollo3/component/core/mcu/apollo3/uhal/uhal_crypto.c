#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "mbedtls/config.h"
#include "mbedtls/aes.h"
#include "error_check.h"

#include "uhal_crypto.h"
#include "udrv_errno.h"

#define AES128_SIZE 16
#define AES192_SIZE 24
#define AES256_SIZE 32

typedef enum
{
    TYPE_ENCRYPT = MBEDTLS_AES_ENCRYPT,
    TYPE_DECRYPT = MBEDTLS_AES_DECRYPT
} AES_Crypt_type_t;

/*
Modes:  ECB (Electronic Code Book) 
        CBC (Cipher Block Chaining) 
        CFB (Cipher FeedBack) 
        OFB (Output FeedBack)
        CTR (Counter)
*/ 
typedef enum 
{
    AES_MODE_ECB,
    AES_MODE_CBC,
    //AES_MODE_CFB,
    //AES_MODE_OFB,
    AES_MODE_CTR
} AES_mode_t;

static uint8_t key[AES256_SIZE] = {0};
static uint16_t key_size=0;

static uint8_t iv[16] = {0};
static uint16_t iv_size=16;

static int uhal_crypto_aes_crypt(AES_mode_t mode, AES_Crypt_type_t type,
                             uint8_t *pKey, uint16_t keySize, 
                             unsigned char *pIV, uint16_t ivSize, 
                             char *intputBuffer, uint16_t intputBuffer_size, 
                             unsigned char *outputBuffer, uint16_t outputBuffer_size)
{
    // ASSERT(keySize == AES128_SIZE || keySize == AES192_SIZE || keySize == AES256_SIZE);
    if(keySize != AES128_SIZE && keySize != AES192_SIZE && keySize != AES256_SIZE)
        return -UDRV_INVALID_KEY_LENGTH;

    if(mode == AES_MODE_CBC)
    {
        // ASSERT(ivSize == 16);
        if(ivSize != 16)
            return -UDRV_INVALID_KEY_LENGTH;
    }

    // ASSERT(outputBuffer_size%16 == 0);
    if(outputBuffer_size%16 != 0)
        return -UDRV_INVALID_INPUT_LENGTH;

    /* Declared the variables needed for AES encryption 
    This will have the algorithm context */
    mbedtls_aes_context aes_ctx; 

    int err_code;

    mbedtls_aes_init(&aes_ctx);
    if(type == TYPE_ENCRYPT)
    {
        err_code = mbedtls_aes_setkey_enc(&aes_ctx, pKey, keySize*8);
        // ERROR_CHECK(err_code);
        if(err_code != 0)
            return err_code;    
    }
    else if(type == TYPE_DECRYPT)
    {
        err_code = mbedtls_aes_setkey_dec(&aes_ctx, pKey, keySize*8);
        // ERROR_CHECK(err_code);
        if(err_code != 0)
            return err_code;
    }
    else
    {
        // ERROR_CHECK(-1);
        return -UDRV_WRONG_ARG;
    }

    #define PARTIAL_MESSAGE_SIZE (16u)  // 16 bytes
    // intputBuffer_size must be always multiple of 16 bytes 
    // If not, you must partially encrypt data.

    uint16_t offset = 0;
    while(intputBuffer_size)
    {
        char partial_message[PARTIAL_MESSAGE_SIZE];
        unsigned char output_message[PARTIAL_MESSAGE_SIZE];
        memset(partial_message, 0x00, PARTIAL_MESSAGE_SIZE);
        memset(output_message, 0x00, PARTIAL_MESSAGE_SIZE);
        if(intputBuffer_size < PARTIAL_MESSAGE_SIZE)
        {
            memcpy(partial_message, intputBuffer + offset, intputBuffer_size);
        }
        else
        {
            memcpy(partial_message, intputBuffer + offset, PARTIAL_MESSAGE_SIZE); 
        }
        
        if(mode == AES_MODE_ECB)
        {
            err_code = mbedtls_aes_crypt_ecb(&aes_ctx, (int) type, (const unsigned char*) partial_message, output_message);
            // ERROR_CHECK(err_code);
            if(err_code != 0)
                return err_code;
        }
        else if(mode == AES_MODE_CBC)
        {
            err_code = mbedtls_aes_crypt_cbc(&aes_ctx, (int) type, PARTIAL_MESSAGE_SIZE, pIV, (const unsigned char*) partial_message, output_message);
            // ERROR_CHECK(err_code);
            if(err_code != 0)
                return err_code;        
        }
        else
        {
            return -UDRV_WRONG_ARG;
        }

        if(intputBuffer_size < PARTIAL_MESSAGE_SIZE)
        {
            memcpy(outputBuffer + offset, output_message, outputBuffer_size);
            intputBuffer_size = 0;
            outputBuffer_size = 0;
        }
        else
        {
            memcpy(outputBuffer + offset, output_message, PARTIAL_MESSAGE_SIZE);
            intputBuffer_size -= PARTIAL_MESSAGE_SIZE;
            outputBuffer_size -= PARTIAL_MESSAGE_SIZE;
        }

        offset += PARTIAL_MESSAGE_SIZE;
    }

    mbedtls_aes_free(&aes_ctx);
    return 0;
}

static int uhal_crypto_aes_ctr_crypt( uint8_t *pKey, uint16_t keySize, 
                             size_t *nc_off, unsigned char nonce_counter[16], unsigned char stream_block[16],
                             char *intputBuffer, uint16_t inputBuffer_length,
                             unsigned char *outputBuffer)
{
    // ASSERT(keySize == AES128_SIZE || keySize == AES192_SIZE || keySize == AES256_SIZE);
    if(keySize != AES128_SIZE && keySize != AES192_SIZE && keySize != AES256_SIZE)
        return -UDRV_INVALID_KEY_LENGTH;

    /* Declared the variables needed for AES encryption 
       This will have the algorithm context */
    mbedtls_aes_context aes_ctx; 

    int err_code;

    mbedtls_aes_init(&aes_ctx);

    err_code = mbedtls_aes_setkey_enc(&aes_ctx, pKey, keySize*8);
    // ERROR_CHECK(err_code);
    if(err_code != 0)
        return err_code;

    err_code = mbedtls_aes_crypt_ctr(&aes_ctx, inputBuffer_length, nc_off, nonce_counter, stream_block, (const unsigned char*) intputBuffer, outputBuffer);
    // ERROR_CHECK(err_code);
    if(err_code != 0)
        return err_code;

    mbedtls_aes_free(&aes_ctx);
    return 0;
}



int uhal_cyrpto_set_key(uint8_t *pKey, uint16_t keySize)
{
    // ASSERT(keySize == AES128_SIZE || keySize == AES192_SIZE || keySize == AES256_SIZE);
    if(keySize != AES128_SIZE && keySize != AES192_SIZE && keySize != AES256_SIZE)
         return -UDRV_INVALID_KEY_LENGTH;

    memcpy(key, pKey, keySize);
    key_size = keySize;
    return 0;
}

int uhal_cyrpto_set_iv(unsigned char *pIV, uint16_t ivSize)
{
    // ASSERT(ivSize == 16);
    if(ivSize != 16)
        return -UDRV_INVALID_KEY_LENGTH;

    memcpy(iv, pIV, ivSize);
    iv_size = ivSize;
    return 0;
}

int uhal_crypto_aes_ecb_encrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize)
{
    // Encryption with AES-ECB
    return uhal_crypto_aes_crypt(AES_MODE_ECB, TYPE_ENCRYPT,
                          (uint8_t *) key, key_size,
                          NULL, 0,
                          input, inputSize, 
                          output, outputSize);
}

int uhal_crypto_aes_ecb_decrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize)
{
    // Decryption with AES-ECB
    return uhal_crypto_aes_crypt(AES_MODE_ECB, TYPE_DECRYPT,
                          (uint8_t *) key, key_size,
                          NULL, 0,
                          input, inputSize, 
                          output, outputSize);
}

int uhal_crypto_aes_cbc_encrypt(char *input, uint16_t inputSize, 
                                 unsigned char *output, uint16_t outputSize)
{
    uint8_t iv_enc[16] = {0};

    memcpy(iv_enc, iv, iv_size);

    // Encryption with AES128-CBC
    return uhal_crypto_aes_crypt(AES_MODE_CBC, TYPE_ENCRYPT,
                          (uint8_t *) key, key_size,
                          (uint8_t *) iv_enc, sizeof(iv_enc),
                          input, inputSize, 
                          output, outputSize);
}

int uhal_crypto_aes_cbc_decrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize)
{
    uint8_t iv_dec[16] = {0};

    memcpy(iv_dec, iv, iv_size);

    // Encryption with AES128-CBC
    return uhal_crypto_aes_crypt(AES_MODE_CBC, TYPE_DECRYPT,
                          (uint8_t *) key, key_size,
                          (uint8_t *) iv_dec, sizeof(iv_dec),
                          input, inputSize, 
                          output, outputSize);    
}

int uhal_crypto_aes_ctr_encrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize)
{
    unsigned int nc_off_enc = 0;
    unsigned char nonce_counter_enc[16] = {0};
    unsigned char stream_block_enc[16] = {0};

    // Encryption with AES-CTR
    return uhal_crypto_aes_ctr_crypt( (uint8_t *) key, key_size,
                                &nc_off_enc, nonce_counter_enc, stream_block_enc,
                                input, inputSize, 
                                output);
}

int uhal_crypto_aes_ctr_decrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize)
{
    unsigned int nc_off_enc = 0;
    unsigned char nonce_counter_enc[16] = {0};
    unsigned char stream_block_enc[16] = {0};

    // Encryption with AES-CTR
    return uhal_crypto_aes_ctr_crypt( (uint8_t *) key, key_size,
                                &nc_off_enc, nonce_counter_enc, stream_block_enc,
                                input, inputSize, 
                                output);    
}