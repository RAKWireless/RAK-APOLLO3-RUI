#include "uhal_spimst.h"
#include "uhal_gpio.h"
#include "am_bsp_pins.h"
#include "error_check.h"

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

#define IOM_SPI0_MODULE  0
#define IOM_SPI1_MODULE  1

// SCK 5
// MISO 6
// MOSI 7
// CS 1
void    *IOM0_Handle;
uint32_t IOM0_DMATCBBuffer[1024];

// SCK 8
// MISO 9
// MOSI 10
// CS 11
void    *IOM1_Handle;
uint32_t IOM1_DMATCBBuffer[1024];

static am_hal_iom_config_t IOM0_SPIConfig =
{
    .eInterfaceMode = AM_HAL_IOM_SPI_MODE,
    .ui32ClockFreq  = AM_HAL_IOM_4MHZ,
    .eSpiMode       = AM_HAL_IOM_SPI_MODE_0,
    .pNBTxnBuf      = &IOM0_DMATCBBuffer[0],
    .ui32NBTxnBufLength = sizeof(IOM0_DMATCBBuffer) / sizeof(uint32_t)
};

static am_hal_iom_config_t IOM1_SPIConfig =
{
    .eInterfaceMode = AM_HAL_IOM_SPI_MODE,
    .ui32ClockFreq  = AM_HAL_IOM_4MHZ,
    .eSpiMode       = AM_HAL_IOM_SPI_MODE_0,
    .pNBTxnBuf      = 0,
    .ui32NBTxnBufLength = 0
};

typedef struct uhal_spimst_status {
    bool active;
    bool resumed;
} uhal_spimst_status_t;

static uhal_spimst_status_t spimst_status[UDRV_SPIMST_MAX];

static uint8_t udrv_spimst_0_order = 0;
static uint8_t udrv_spimst_1_order = 0;

static inline bool isInISR(void)
{
  return (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0 ;
}

static SemaphoreHandle_t spi0_semaphore = NULL;
static SemaphoreHandle_t spi1_semaphore = NULL;

static void spi0_take_semaphore(void)
{
    if(spi0_semaphore == NULL)
        return;

    if(isInISR())
    {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        if(pdPASS != xSemaphoreTakeFromISR(spi0_semaphore, xHigherPriorityTaskWoken))
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
        if(pdPASS != xSemaphoreTake(spi0_semaphore, portMAX_DELAY))
        {
            return;
        }
    }
}

static void spi0_give_semaphore(void)
{
    if(spi0_semaphore == NULL)
        return;

    if(isInISR())
    {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        if(pdPASS != xSemaphoreGiveFromISR(spi0_semaphore, xHigherPriorityTaskWoken))
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
        if(pdPASS != xSemaphoreGive(spi0_semaphore))
        {
            return;
        }
    }
}

static void spi1_take_semaphore(void)
{
    if(spi1_semaphore == NULL)
        return;

    if(isInISR())
    {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        if(pdPASS != xSemaphoreTakeFromISR(spi1_semaphore, xHigherPriorityTaskWoken))
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
        if(pdPASS != xSemaphoreTake(spi1_semaphore, portMAX_DELAY))
        {
            return;
        }
    }
}

static void spi1_give_semaphore(void)
{
    if(spi1_semaphore == NULL)
        return;

    if(isInISR())
    {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        if(pdPASS != xSemaphoreGiveFromISR(spi1_semaphore, xHigherPriorityTaskWoken))
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
        if(pdPASS != xSemaphoreGive(spi1_semaphore))
        {
            return;
        }
    }
}

static void spi0_set_up(void)
{
    uint32_t err_code;
    
    if(spimst_status[0].resumed == true)
        return;

    spi0_take_semaphore();

    //
    // Initialize the IOM.
    //
    err_code = am_hal_iom_initialize(IOM_SPI0_MODULE, &IOM0_Handle);
    ERROR_CHECK(err_code);
    
    err_code = am_hal_iom_power_ctrl(IOM0_Handle, AM_HAL_SYSCTRL_WAKE, false);
    ERROR_CHECK(err_code);

    //
    // Set the required configuration settings for the IOM.
    //
    err_code = am_hal_iom_configure(IOM0_Handle, &IOM0_SPIConfig);
    ERROR_CHECK(err_code);

    err_code = am_hal_iom_control(IOM0_Handle, AM_HAL_IOM_REQ_SPI_LSB, &udrv_spimst_0_order); // Cause hardfault
    ERROR_CHECK(err_code);

    //
    // Configure the IOM pins.
    //
    //am_bsp_iom_pins_enable(IOM_SPI0_MODULE, AM_HAL_IOM_SPI_MODE);
    err_code = am_hal_gpio_pinconfig(AM_BSP_GPIO_IOM0_SCK,  g_AM_BSP_GPIO_IOM0_SCK);
    ERROR_CHECK(err_code);
    err_code = am_hal_gpio_pinconfig(AM_BSP_GPIO_IOM0_MISO, g_AM_BSP_GPIO_IOM0_MISO);
    ERROR_CHECK(err_code);
    err_code = am_hal_gpio_pinconfig(AM_BSP_GPIO_IOM0_MOSI, g_AM_BSP_GPIO_IOM0_MOSI);
    ERROR_CHECK(err_code);
    //am_hal_gpio_pinconfig(AM_BSP_GPIO_IOM0_CS,   g_AM_BSP_GPIO_IOM0_CS);

    // Enable interrupts for NB send to work
    err_code = am_hal_iom_interrupt_enable(IOM0_Handle, 0xFD);
    ERROR_CHECK(err_code);

    NVIC_SetPriority((IRQn_Type) (IOMSTR0_IRQn), NVIC_configMAX_SYSCALL_INTERRUPT_PRIORITY);
    NVIC_EnableIRQ(IOMSTR0_IRQn);

    //
    // Enable the IOM.
    //
    err_code = am_hal_iom_enable(IOM0_Handle);
    ERROR_CHECK(err_code);

    spimst_status[0].resumed = true;

    spi0_give_semaphore();
}

static void spi1_set_up(void)
{
    uint32_t err_code;

    if(spimst_status[1].resumed == true)
        return;

    spi1_take_semaphore();

    //
    // Initialize the IOM.
    //
    err_code = am_hal_iom_initialize(IOM_SPI1_MODULE, &IOM1_Handle);
    ERROR_CHECK(err_code);

    err_code = am_hal_iom_power_ctrl(IOM1_Handle, AM_HAL_SYSCTRL_WAKE, false);
    ERROR_CHECK(err_code);

    //
    // Set the required configuration settings for the IOM.
    //
    err_code = am_hal_iom_configure(IOM1_Handle, &IOM1_SPIConfig);
    ERROR_CHECK(err_code);
    
    err_code = am_hal_iom_control(IOM1_Handle, AM_HAL_IOM_REQ_SPI_LSB, &udrv_spimst_1_order); // Cause hardfault
    ERROR_CHECK(err_code);

    //
    // Configure the IOM pins.
    //
    //am_bsp_iom_pins_enable(IOM_SPI1_MODULE, AM_HAL_IOM_SPI_MODE);
    err_code = am_hal_gpio_pinconfig(AM_BSP_GPIO_IOM1_SCK,  g_AM_BSP_GPIO_IOM1_SCK);
    ERROR_CHECK(err_code);
    err_code = am_hal_gpio_pinconfig(AM_BSP_GPIO_IOM1_MISO, g_AM_BSP_GPIO_IOM1_MISO);
    ERROR_CHECK(err_code);
    err_code = am_hal_gpio_pinconfig(AM_BSP_GPIO_IOM1_MOSI, g_AM_BSP_GPIO_IOM1_MOSI);
    ERROR_CHECK(err_code);
    //am_hal_gpio_pinconfig(AM_BSP_GPIO_IOM1_CS,   g_AM_BSP_GPIO_IOM1_CS);

    // Enable interrupts for NB send to work
    err_code = am_hal_iom_interrupt_enable(IOM1_Handle, 0xFD);
    ERROR_CHECK(err_code);

    NVIC_SetPriority((IRQn_Type) (IOMSTR1_IRQn), NVIC_configMAX_SYSCALL_INTERRUPT_PRIORITY);
    NVIC_EnableIRQ(IOMSTR1_IRQn);

    //
    // Enable the IOM.
    //
    err_code = am_hal_iom_enable(IOM1_Handle);
    ERROR_CHECK(err_code);

    spimst_status[1].resumed = true;

    spi1_give_semaphore();
}

static void spi0_clean_up(void)
{
    uint32_t err_code;

    if(spimst_status[0].active == false)
        return;

    if(spimst_status[0].resumed == false)
        return;

    spi0_take_semaphore();

    //
    // Turn off the IOM for this operation.
    //
    err_code = am_hal_iom_disable(IOM0_Handle);
    ERROR_CHECK(err_code);
    
    //
    // Clean up IOM I2C pins. Attributes are set in am_bsp_gpio.h.
    //
    //am_bsp_iom_pins_disable(IOM_SPI0_MODULE, AM_HAL_IOM_SPI_MODE);
    err_code = am_hal_gpio_pinconfig(AM_BSP_GPIO_IOM0_SCK,  g_AM_HAL_GPIO_DISABLE);
    ERROR_CHECK(err_code);
    err_code = am_hal_gpio_pinconfig(AM_BSP_GPIO_IOM0_MISO, g_AM_HAL_GPIO_DISABLE);
    ERROR_CHECK(err_code);
    err_code = am_hal_gpio_pinconfig(AM_BSP_GPIO_IOM0_MOSI, g_AM_HAL_GPIO_DISABLE);
    ERROR_CHECK(err_code);
    //am_hal_gpio_pinconfig(AM_BSP_GPIO_IOM0_CS,   g_AM_HAL_GPIO_DISABLE);
    
    //
    // Disable power to IOM.
    //
    err_code = am_hal_iom_power_ctrl(IOM0_Handle, AM_HAL_SYSCTRL_DEEPSLEEP, false);
    ERROR_CHECK(err_code);

    err_code = am_hal_iom_uninitialize(IOM0_Handle);
    ERROR_CHECK(err_code);

    spimst_status[0].resumed = false;

    spi0_give_semaphore();
}

static void spi1_clean_up(void)
{
    uint32_t err_code;

    if(spimst_status[1].active == false)
        return;

    if(spimst_status[1].resumed == false)
        return;

    spi1_take_semaphore();

    //
    // Turn off the IOM for this operation.
    //
    err_code = am_hal_iom_disable(IOM1_Handle);
    ERROR_CHECK(err_code);
    
    //
    // Clean up IOM I2C pins. Attributes are set in am_bsp_gpio.h.
    //
    //am_bsp_iom_pins_disable(IOM_SPI1_MODULE, AM_HAL_IOM_SPI_MODE);
    err_code = am_hal_gpio_pinconfig(AM_BSP_GPIO_IOM1_SCK,  g_AM_HAL_GPIO_DISABLE);
    ERROR_CHECK(err_code);
    err_code = am_hal_gpio_pinconfig(AM_BSP_GPIO_IOM1_MISO, g_AM_HAL_GPIO_DISABLE);
    ERROR_CHECK(err_code);
    err_code = am_hal_gpio_pinconfig(AM_BSP_GPIO_IOM1_MOSI, g_AM_HAL_GPIO_DISABLE);
    ERROR_CHECK(err_code);
    //am_hal_gpio_pinconfig(AM_BSP_GPIO_IOM1_CS,   g_AM_HAL_GPIO_DISABLE);

    //
    // Disable power to IOM.
    //
    err_code = am_hal_iom_power_ctrl(IOM1_Handle, AM_HAL_SYSCTRL_DEEPSLEEP, false);
    ERROR_CHECK(err_code);

    err_code = am_hal_iom_uninitialize(IOM1_Handle);
    ERROR_CHECK(err_code);

    spimst_status[1].resumed = false;

    spi1_give_semaphore();
}

void uhal_spimst_setup_mode(udrv_spimst_port port, ENUM_SPI_MST_CPHA_T CPHA, ENUM_SPI_MST_CPOL_T CPOL) {

#if SPI0_ENABLED
    if (port == UDRV_SPIMST_0) {
        if (CPOL == SPI_MST_CPOL_0 && CPHA == SPI_MST_CPHA_0) {
            IOM0_SPIConfig.eSpiMode = AM_HAL_IOM_SPI_MODE_0;
        } else if (CPOL == SPI_MST_CPOL_0 && CPHA == SPI_MST_CPHA_1) {
            IOM0_SPIConfig.eSpiMode = AM_HAL_IOM_SPI_MODE_1;
        } else if (CPOL == SPI_MST_CPOL_1 && CPHA == SPI_MST_CPHA_0) {
            IOM0_SPIConfig.eSpiMode = AM_HAL_IOM_SPI_MODE_2;
        } else if (CPOL == SPI_MST_CPOL_1 && CPHA == SPI_MST_CPHA_1) {
            IOM0_SPIConfig.eSpiMode = AM_HAL_IOM_SPI_MODE_3;
        } else {
            IOM0_SPIConfig.eSpiMode = AM_HAL_IOM_SPI_MODE_0;
        }
    } else
#endif
#if SPI1_ENABLED
    if (port == UDRV_SPIMST_1) {
        if (CPOL == SPI_MST_CPOL_0 && CPHA == SPI_MST_CPHA_0) {
            IOM1_SPIConfig.eSpiMode = AM_HAL_IOM_SPI_MODE_0;
        } else if (CPOL == SPI_MST_CPOL_0 && CPHA == SPI_MST_CPHA_1) {
            IOM1_SPIConfig.eSpiMode = AM_HAL_IOM_SPI_MODE_1;
        } else if (CPOL == SPI_MST_CPOL_1 && CPHA == SPI_MST_CPHA_0) {
            IOM1_SPIConfig.eSpiMode = AM_HAL_IOM_SPI_MODE_2;
        } else if (CPOL == SPI_MST_CPOL_1 && CPHA == SPI_MST_CPHA_1) {
            IOM1_SPIConfig.eSpiMode = AM_HAL_IOM_SPI_MODE_3;
        } else {
            IOM1_SPIConfig.eSpiMode = AM_HAL_IOM_SPI_MODE_0;
        }
    } else
#endif
#if SPI2_ENABLED
    if (port == UDRV_SPIMST_2) {
    } else
#endif
#if SPI3_ENABLED
    if (port == UDRV_SPIMST_3) {
    } else
#endif
    {
        //should not be here
    }
}

void uhal_spimst_setup_freq(udrv_spimst_port port, uint32_t clk_Hz) {
#if SPI0_ENABLED
    if (port == UDRV_SPIMST_0) {
        if (clk_Hz <= 125000) {
            IOM0_SPIConfig.ui32ClockFreq = AM_HAL_IOM_125KHZ;
        } else if (clk_Hz <= 250000) {
            IOM0_SPIConfig.ui32ClockFreq = AM_HAL_IOM_250KHZ;
        } else if (clk_Hz <= 500000) {
            IOM0_SPIConfig.ui32ClockFreq = AM_HAL_IOM_500KHZ;
        } else if (clk_Hz <= 1000000) {
            IOM0_SPIConfig.ui32ClockFreq = AM_HAL_IOM_1MHZ;
        } else if (clk_Hz <= 2000000) {
            IOM0_SPIConfig.ui32ClockFreq = AM_HAL_IOM_2MHZ;
        } else if (clk_Hz <= 4000000) {
            IOM0_SPIConfig.ui32ClockFreq = AM_HAL_IOM_4MHZ;
        } else {
            IOM0_SPIConfig.ui32ClockFreq = AM_HAL_IOM_8MHZ;
        }
    } else
#endif
#if SPI1_ENABLED
    if (port == UDRV_SPIMST_1) {
        if (clk_Hz <= 125000) {
            IOM1_SPIConfig.ui32ClockFreq = AM_HAL_IOM_125KHZ;
        } else if (clk_Hz <= 250000) {
            IOM1_SPIConfig.ui32ClockFreq = AM_HAL_IOM_250KHZ;
        } else if (clk_Hz <= 500000) {
            IOM1_SPIConfig.ui32ClockFreq = AM_HAL_IOM_500KHZ;
        } else if (clk_Hz <= 1000000) {
            IOM1_SPIConfig.ui32ClockFreq = AM_HAL_IOM_1MHZ;
        } else if (clk_Hz <= 2000000) {
            IOM0_SPIConfig.ui32ClockFreq = AM_HAL_IOM_2MHZ;
        } else if (clk_Hz <= 4000000) {
            IOM1_SPIConfig.ui32ClockFreq = AM_HAL_IOM_4MHZ;
        } else {
            IOM0_SPIConfig.ui32ClockFreq = AM_HAL_IOM_8MHZ;
        }
    } else
#endif
#if SPI2_ENABLED
    if (port == UDRV_SPIMST_2) {
    } else
#endif
#if SPI3_ENABLED
    if (port == UDRV_SPIMST_3) {
    } else
#endif
    {
        //should not be here
    }
}

void uhal_spimst_setup_byte_order(udrv_spimst_port port, bool msb_first) {
#if SPI0_ENABLED
    if (port == UDRV_SPIMST_0) {
        if (msb_first) {
          udrv_spimst_0_order = 0; // MSB
        } else {
          udrv_spimst_0_order = 1; // LSB
        }
    } else
#endif
#if SPI1_ENABLED
    if (port == UDRV_SPIMST_1) {
        if (msb_first) {
          udrv_spimst_1_order = 0; // MSB
        } else {
          udrv_spimst_1_order = 1; // LSB
        }
    } else
#endif
#if SPI2_ENABLED
    if (port == UDRV_SPIMST_2) {
    } else
#endif
#if SPI3_ENABLED
    if (port == UDRV_SPIMST_3) {
    } else
#endif
    {
        //should not be here
    }
}

static void spimst_init(udrv_spimst_port port) {
#if SPI0_ENABLED
    if (port == UDRV_SPIMST_0) {
        if(spi0_semaphore == NULL)
            spi0_semaphore = xSemaphoreCreateMutex();
        spi0_set_up();
    } else
#endif
#if SPI1_ENABLED
    if (port == UDRV_SPIMST_1) {
        if(spi1_semaphore == NULL)
            spi1_semaphore = xSemaphoreCreateMutex();
        spi1_set_up();
    } else
#endif
#if SPI2_ENABLED
    if (port == UDRV_SPIMST_2) {
    } else
#endif
#if SPI3_ENABLED
    if (port == UDRV_SPIMST_3) {
    } else
#endif
    {
        //should not be here
    }
}

void uhal_spimst_init(udrv_spimst_port port) {
    if (port >= UDRV_SPIMST_MAX) {
        return;
    }

    spimst_init(port);

    spimst_status[port].active = true;
}

static void spimst_deinit(udrv_spimst_port port) {
#if SPI0_ENABLED
    if (port == UDRV_SPIMST_0) {
        spi0_clean_up();
    } else
#endif
#if SPI1_ENABLED
    if (port == UDRV_SPIMST_1) {
        spi1_clean_up();
    } else
#endif
#if SPI2_ENABLED
    if (port == UDRV_SPIMST_2) {
    } else
#endif
#if SPI3_ENABLED
    if (port == UDRV_SPIMST_3) {
    } else
#endif
    {
        //should not be here
    }
}

void uhal_spimst_deinit(udrv_spimst_port port) {
    if (port >= UDRV_SPIMST_MAX) {
        return;
    }

    spimst_deinit(port);

    spimst_status[port].active = false;
}

int8_t uhal_spimst_trx(udrv_spimst_port port, uint8_t *write_data, uint32_t write_length, uint8_t *read_data, uint32_t read_length, uint32_t csn) {
    uint32_t err_code;
    
    if (port >= UDRV_SPIMST_MAX) 
        return -1;

    if(spimst_status[port].resumed == false)
        return -1;

    bool set_logic = false;
#if SPI0_ENABLED
    if (port == UDRV_SPIMST_0) {
        spi0_take_semaphore();

        am_hal_iom_transfer_t tx;
        am_hal_iom_transfer_t rx;
        memset(&tx, 0, sizeof(am_hal_iom_transfer_t));
        memset(&rx, 0, sizeof(am_hal_iom_transfer_t));

        // Direction
        if ((write_data != NULL) && (read_data != NULL))
        {
            tx.ui32InstrLen    = 0;
            tx.ui32Instr       = 0;
            tx.eDirection      = AM_HAL_IOM_FULLDUPLEX;
            tx.ui32NumBytes    = write_length;
            tx.pui32TxBuffer   = (uint32_t *) write_data;
            tx.pui32RxBuffer   = (uint32_t *) read_data;
            tx.bContinue       = false;
            tx.ui8RepeatCount  = 0;
            tx.ui32PauseCondition = 0;
            tx.ui32StatusSetClr = 0;
            tx.uPeerInfo.ui32SpiChipSelect = 0xFF;
        }
        else if (write_data != NULL)
        {
            tx.ui32InstrLen    = 0;
            tx.ui32Instr       = 0;
            tx.eDirection      = AM_HAL_IOM_TX;
            tx.ui32NumBytes    = write_length;
            tx.pui32TxBuffer   = (uint32_t *) write_data;
            tx.bContinue       = false;
            tx.ui8RepeatCount  = 0;
            tx.ui32PauseCondition = 0;
            tx.ui32StatusSetClr = 0;
            tx.uPeerInfo.ui32SpiChipSelect = 0xFF;
        }
        else if (read_data != NULL)
        {
            rx.ui32InstrLen    = 0;
            rx.ui32Instr       = 0;
            rx.eDirection      = AM_HAL_IOM_RX;
            rx.ui32NumBytes    = read_length;
            rx.pui32RxBuffer   = (uint32_t *) read_data;
            rx.bContinue       = false;
            rx.ui8RepeatCount  = 0;
            rx.ui32PauseCondition = 0;
            rx.ui32StatusSetClr = 0;
            rx.uPeerInfo.ui32SpiChipSelect = 0xFF;
        }

        uhal_gpio_set_dir(csn, GPIO_DIR_OUT);
         
        if (uhal_gpio_get_logic(csn) != GPIO_LOGIC_LOW)
        {
            uhal_gpio_set_logic(csn, GPIO_LOGIC_LOW);
            set_logic = true;
        }



        // Direction
        if ((write_data != NULL) && (read_data != NULL))
        {            
            err_code = am_hal_iom_spi_blocking_fullduplex(IOM0_Handle, &tx);
            ERROR_CHECK(err_code);
        }
        else if (write_data != NULL)
        {
            err_code = am_hal_iom_blocking_transfer(IOM0_Handle, &tx);
            ERROR_CHECK(err_code);
        }
        else if (read_data != NULL)
        {
            err_code = am_hal_iom_blocking_transfer(IOM0_Handle, &rx);
            ERROR_CHECK(err_code);
        }

        if (set_logic)
        {
            uhal_gpio_set_logic(csn, GPIO_LOGIC_HIGH);
        }
        spi0_give_semaphore();

        if(err_code == 0)
            return 0;
        else
            return -1;
    } else
#endif
#if SPI1_ENABLED
    if (port == UDRV_SPIMST_1) {
        spi1_take_semaphore();

        am_hal_iom_transfer_t tx;
        am_hal_iom_transfer_t rx;
        memset(&tx, 0, sizeof(am_hal_iom_transfer_t));
        memset(&rx, 0, sizeof(am_hal_iom_transfer_t));

        // Direction
        if ((write_data != NULL) && (read_data != NULL))
        {
            tx.ui32InstrLen    = 0;
            tx.ui32Instr       = 0;
            tx.eDirection      = AM_HAL_IOM_FULLDUPLEX;
            tx.ui32NumBytes    = write_length;
            tx.pui32TxBuffer   = (uint32_t *) write_data;
            tx.pui32RxBuffer   = (uint32_t *) read_data;
            tx.bContinue       = false;
            tx.ui8RepeatCount  = 0;
            tx.ui32PauseCondition = 0;
            tx.ui32StatusSetClr = 0;
            tx.uPeerInfo.ui32SpiChipSelect = 0xFF;
        }
        else if (write_data != NULL)
        {
            tx.ui32InstrLen    = 0;
            tx.ui32Instr       = 0;
            tx.eDirection      = AM_HAL_IOM_TX;
            tx.ui32NumBytes    = write_length;
            tx.pui32TxBuffer   = (uint32_t *) write_data;
            tx.bContinue       = false;
            tx.ui8RepeatCount  = 0;
            tx.ui32PauseCondition = 0;
            tx.ui32StatusSetClr = 0;
            tx.uPeerInfo.ui32SpiChipSelect = 0xFF;
        }
        else if (read_data != NULL)
        {
            rx.ui32InstrLen    = 0;
            rx.ui32Instr       = 0;
            rx.eDirection      = AM_HAL_IOM_RX;
            rx.ui32NumBytes    = read_length;
            rx.pui32RxBuffer   = (uint32_t *) read_data;
            rx.bContinue       = false;
            rx.ui8RepeatCount  = 0;
            rx.ui32PauseCondition = 0;
            rx.ui32StatusSetClr = 0;
            rx.uPeerInfo.ui32SpiChipSelect = 0xFF;
        }

        uhal_gpio_set_dir(csn, GPIO_DIR_OUT);
        if (uhal_gpio_get_logic(csn) != GPIO_LOGIC_LOW)
        {
            uhal_gpio_set_logic(csn, GPIO_LOGIC_LOW);
            set_logic = true;
        }
        // Direction
        if ((write_data != NULL) && (read_data != NULL))
        {
            err_code = am_hal_iom_spi_blocking_fullduplex(IOM1_Handle, &tx);
            ERROR_CHECK(err_code);
        }
        else if (write_data != NULL)
        {
            err_code = am_hal_iom_blocking_transfer(IOM1_Handle, &tx);
            ERROR_CHECK(err_code);
        }
        else if (read_data != NULL)
        {
            err_code = am_hal_iom_blocking_transfer(IOM1_Handle, &rx);
            ERROR_CHECK(err_code);
        }

        if (set_logic)
        {
            uhal_gpio_set_logic(csn, GPIO_LOGIC_HIGH);
        }
        spi1_give_semaphore();

        if(err_code == 0)
            return 0;
        else
            return -1;
    } else
#endif
#if SPI2_ENABLED
    if (port == UDRV_SPIMST_2) {
    } else
#endif
#if SPI3_ENABLED
    if (port == UDRV_SPIMST_3) {
    } else
#endif
    {
        //should not be here
        return -1;
    }

    return -1;
}

void uhal_spimst_suspend(void) {
    for (int i = UDRV_SPIMST_0 ; i < UDRV_SPIMST_MAX ; i++) {
        if (spimst_status[i].active == true) {
            spimst_deinit(i);
        }
    }
}

void uhal_spimst_resume(void) {
    for (int i = UDRV_SPIMST_0 ; i < UDRV_SPIMST_MAX ; i++) {
        if (spimst_status[i].active == true) {
            spimst_init(i);
        }
    }
}

