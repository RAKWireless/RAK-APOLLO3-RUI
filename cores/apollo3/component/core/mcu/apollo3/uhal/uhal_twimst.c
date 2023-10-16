#include "uhal_twimst.h"
#include "am_bsp_pins.h"
#include "stdbool.h"

//*****************************************************************************
//
// FreeRTOS include files.
//
//*****************************************************************************
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"
#include "portable.h"
#include "semphr.h"
#include "event_groups.h"
#include "rtos.h"

#define IOM_I2C_MODULE  2
#define TWI_TIMEOUT	10000

void    *IOM2_Handle;

static am_hal_iom_config_t IOM2_I2cConfig =
{
    .eInterfaceMode = AM_HAL_IOM_I2C_MODE,
    .ui32ClockFreq  = AM_HAL_IOM_400KHZ
};

static uint8_t udrv_spimst_0_order = 0;
static uint8_t udrv_spimst_1_order = 0;

static inline bool isInISR(void)
{
  return (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0 ;
}

static SemaphoreHandle_t twi2_semaphore = NULL;

static void twi2_take_semaphore(void)
{
    if(twi2_semaphore == NULL)
        return;

    if(isInISR())
    {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        if(pdPASS != xSemaphoreTakeFromISR(twi2_semaphore, xHigherPriorityTaskWoken))
        {
            return;
        }

        if(xHigherPriorityTaskWoken != pdFALSE)
        {
            portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }
    }
    else
    {
        if(pdPASS != xSemaphoreTake(twi2_semaphore, portMAX_DELAY))
        {
            return;
        }
    }
}

static void twi2_give_semaphore(void)
{
    if(twi2_semaphore == NULL)
        return;

    if(isInISR())
    {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        if(pdPASS != xSemaphoreGiveFromISR(twi2_semaphore, xHigherPriorityTaskWoken))
        {
            return;
        }

        if(xHigherPriorityTaskWoken != pdFALSE)
        {
            portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }
    }
    else
    {
        if(pdPASS != xSemaphoreGive(twi2_semaphore))
        {
            return;
        }
    }
}

void am_iomaster2_isr()
{
    uint32_t ui32Status;

    if (!am_hal_iom_interrupt_status_get(IOM2_Handle, true, &ui32Status))
    {
        if ( ui32Status )
        {
            am_hal_iom_interrupt_clear(IOM2_Handle, ui32Status);
            am_hal_iom_interrupt_service(IOM2_Handle, ui32Status);
        }
    }
}

static void iom_set_up(void)
{
    twi2_take_semaphore();

    //
    // Initialize the IOM.
    //
    am_hal_iom_initialize(IOM_I2C_MODULE, &IOM2_Handle);

    am_hal_iom_power_ctrl(IOM2_Handle, AM_HAL_SYSCTRL_WAKE, false);

    //
    // Set the required configuration settings for the IOM.
    //
    am_hal_iom_configure(IOM2_Handle, &IOM2_I2cConfig);

    //
    // Configure the IOM pins.
    //
    am_hal_gpio_pinconfig(AM_BSP_GPIO_IOM2_SCL,  g_AM_BSP_GPIO_IOM2_SCL);
    am_hal_gpio_pinconfig(AM_BSP_GPIO_IOM2_SDA,  g_AM_BSP_GPIO_IOM2_SDA);

    // Enable interrupts for NB send to work
    am_hal_iom_interrupt_enable(IOM2_Handle, 0xFF);
    NVIC_EnableIRQ(IOMSTR2_IRQn);

    //
    // Enable the IOM.
    //
    am_hal_iom_enable(IOM2_Handle);

    twi2_give_semaphore();
}

static uint32_t i2c_read(uint8_t slave_address, uint8_t *p_data, uint32_t length)
{
    uint32_t err_code = 0;
    am_hal_iom_transfer_t Transaction;
    
    twi2_take_semaphore();

    Transaction.ui32InstrLen    = 0;
    Transaction.ui32Instr       = 0;
    Transaction.eDirection      = AM_HAL_IOM_RX;
    Transaction.ui32NumBytes    = length;
    Transaction.pui32RxBuffer   = (uint32_t *) p_data;
    Transaction.bContinue       = false;
    Transaction.ui8RepeatCount  = 0;
    Transaction.ui32PauseCondition = 0;
    Transaction.ui32StatusSetClr = 0;

    Transaction.uPeerInfo.ui32I2CDevAddr = (uint32_t) slave_address;

    err_code = am_hal_iom_blocking_transfer(IOM2_Handle, &Transaction);

    twi2_give_semaphore();

    return err_code;
}

static uint32_t i2c_write(uint8_t slave_address, uint8_t *p_data, uint32_t length, bool send_stop)
{
    uint32_t err_code = 0;
    am_hal_iom_transfer_t Transaction;

    twi2_take_semaphore();

    Transaction.ui32InstrLen    = 0;
    Transaction.ui32Instr       = 0;
    Transaction.eDirection      = AM_HAL_IOM_TX;
    Transaction.ui32NumBytes    = length;
    Transaction.pui32TxBuffer   = (uint32_t *) p_data;
    Transaction.bContinue       = (send_stop ? false : true);
    Transaction.ui8RepeatCount  = 0;
    Transaction.ui32PauseCondition = 0;
    Transaction.ui32StatusSetClr = 0;

    Transaction.uPeerInfo.ui32I2CDevAddr = (uint32_t) slave_address;

    err_code = am_hal_iom_blocking_transfer(IOM2_Handle, &Transaction);

    twi2_give_semaphore();

    return err_code;
}

static void iom_clean_up(void)
{
    twi2_take_semaphore();

    //
    // Turn off the IOM for this operation.
    //
    am_hal_iom_disable(IOM2_Handle);

    //
    // Clean up IOM I2C pins. Attributes are set in am_bsp_gpio.h.
    //
    am_hal_gpio_pinconfig(AM_BSP_GPIO_IOM2_SCL,  g_AM_HAL_GPIO_DISABLE);
    am_hal_gpio_pinconfig(AM_BSP_GPIO_IOM2_SDA,  g_AM_HAL_GPIO_DISABLE);

    //
    // Disable power to IOM.
    //
    am_hal_iom_power_ctrl(IOM2_Handle, AM_HAL_SYSCTRL_DEEPSLEEP, false);

    twi2_give_semaphore();
}
/* ----- */



typedef struct uhal_twimst_status {
    bool active;
} uhal_twimst_status_t;

static uhal_twimst_status_t twimst_status[UDRV_TWIMST_MAX];

static void twimst_init(udrv_twimst_port port) {
    if (port == UDRV_TWIMST_0) {
        #if TWI0_ENABLED
        if(twi2_semaphore == NULL)
            twi2_semaphore = xSemaphoreCreateMutex();
        iom_set_up();
        #endif
    } else if (port == UDRV_TWIMST_1) {
        #if TWI1_ENABLED
        #endif
    }
}

void uhal_twimst_init(udrv_twimst_port port) {
    twimst_init(port);

    twimst_status[port].active = true;
}

static void twimst_deinit(udrv_twimst_port port) {
    if (port == UDRV_TWIMST_0) {
        #if TWI0_ENABLED
        iom_clean_up();
        #endif
    } else if (port == UDRV_TWIMST_1) {
        #if TWI1_ENABLED
        #endif
    }
}

void uhal_twimst_deinit(udrv_twimst_port port) {
    twimst_deinit(port);

    twimst_status[port].active = false;
}

void uhal_twimst_setup_freq(udrv_twimst_port port, uint32_t clk_Hz) {
    if (port == UDRV_TWIMST_0) {
        #if TWI0_ENABLED
        if (clk_Hz <= 100000) {
            IOM2_I2cConfig.ui32ClockFreq = AM_HAL_IOM_100KHZ;
        } else if (clk_Hz <= 250000) {
            IOM2_I2cConfig.ui32ClockFreq = AM_HAL_IOM_250KHZ;
        } else {
            IOM2_I2cConfig.ui32ClockFreq = AM_HAL_IOM_400KHZ;
        }
        #endif
    } else {
    }
}	

int32_t uhal_twimst_write(udrv_twimst_port port, uint8_t twi_addr, uint8_t *data, uint16_t len, bool send_stop)
{
    uint32_t err_code = -1;

    if (port == UDRV_TWIMST_0) {
        #if TWI0_ENABLED
        err_code = i2c_write(twi_addr, data, len, send_stop);
        #endif
    } else if (port == UDRV_TWIMST_1) {
    }

    switch (err_code) {
        case AM_HAL_STATUS_SUCCESS:
            return UDRV_RETURN_OK;
        default:
            return -UDRV_NACK;
    }
}

int32_t uhal_twimst_read(udrv_twimst_port port, uint8_t twi_addr, uint8_t * data, uint16_t len)
{
    uint32_t err_code = AM_HAL_STATUS_HW_ERR;

    if (port == UDRV_TWIMST_0) {
        #if TWI0_ENABLED
        err_code = i2c_read(twi_addr, data, len);
        #endif
    } else if (port == UDRV_TWIMST_1) {
    }

    switch (err_code) {
        case AM_HAL_STATUS_SUCCESS:
            return UDRV_RETURN_OK;
        default:
            return -UDRV_NACK;
    }
}

uint8_t uhal_twimst_suspend(void)
{
    for (int i = UDRV_TWIMST_0 ; i < UDRV_TWIMST_MAX ; i++) {
        if (twimst_status[i].active == true) {
            twimst_deinit(i);
	}
    }

     return 0;
}

uint8_t uhal_twimst_resume(void)
{
    for (int i = UDRV_TWIMST_0 ; i < UDRV_TWIMST_MAX ; i++) {
        if (twimst_status[i].active == true) {
            twimst_init(i);
	}
    }

    return 0;
}
