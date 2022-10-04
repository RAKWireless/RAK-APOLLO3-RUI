#include <stdarg.h>
#include "uhal_uart.h"
#include "uhal_delay.h"
#include "pin_define.h"
#include "fund_circular_queue.h"
#include "udrv_system.h"

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

#include "am_mcu_apollo.h"
#include "am_bsp.h"
#include "am_util.h"
#include "am_log.h"
#include "error_check.h"

#define MAX_READ_BYTES      23
#define UART_RX_TIMEOUT_MS  0

#define UART_RX_QUEUE_SIZE  1     // 1 byte per item
#define UART_RX_QUEUE_LEN   1024  // 1024 items

#define UART_TX_QUEUE_SIZE  1     // 1 byte per item
#define UART_TX_QUEUE_LEN   1024  // 1024 items

static QueueHandle_t       UART0_RxQueue;
static SemaphoreHandle_t   UART0_RxSemaphore;
static TaskHandle_t        UART0_RxTask;

static QueueHandle_t       UART0_TxQueue;
static SemaphoreHandle_t   UART0_TxSemaphore;
static SemaphoreHandle_t   UART0_TxMutex;
static TaskHandle_t        UART0_TxTask;
  
static QueueHandle_t       UART1_RxQueue;
static SemaphoreHandle_t   UART1_RxSemaphore;
static TaskHandle_t        UART1_RxTask;

static QueueHandle_t       UART1_TxQueue;
static SemaphoreHandle_t   UART1_TxSemaphore;
static SemaphoreHandle_t   UART1_TxMutex;
static TaskHandle_t        UART1_TxTask;

FUND_CIRCULAR_QUEUE_INIT(uint8_t, SERIAL_UART0_rxq, UART_RX_QUEUE_LEN);
FUND_CIRCULAR_QUEUE_INIT(uint8_t, SERIAL_UART1_rxq, UART_RX_QUEUE_LEN);

static am_hal_uart_state_t *DRV_UART0 = NULL;
static am_hal_uart_state_t *DRV_UART1 = NULL;

static void (*CLI_HANDLER)(void *);
static void (*LOCK_HANDLER)(void *);
static void (*WAKEUP_HANDLER)(void *);
static void (*ONEWIRE_HANDLER) (void *);

typedef struct uhal_uart_status {
    bool active;
    uint32_t baudrate;
} uhal_uart_status_t;

static uhal_uart_status_t uart_status[UHAL_UART_MAX];
static SERIAL_WIRE_MODE_E uart_wire_mode[UHAL_UART_MAX];

typedef enum _SINGLE_WIRE_MODE_E {
    SINGLE_WIRE_MODE_RX = 0,
    SINGLE_WIRE_MODE_TX = 1,
} SINGLE_WIRE_MODE_E;

extern bool udrv_powersave_in_sleep;
static udrv_system_event_t rui_uart_event = {.request = UDRV_SYS_EVT_OP_SERIAL_UART, .p_context = NULL};

// This file exists solely for compilation compatibility with legacy libraries
// Test if in interrupt mode
static inline bool isInISR(void)
{
  return (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0 ;
}

static size_t uart_read(SERIAL_PORT port, char* buf, size_t len)
{
    uint32_t ui32BytesRead = 0x00;

    if(port == SERIAL_UART0)
    {
        am_hal_uart_transfer_t sRead = {
            .ui32Direction = AM_HAL_UART_READ,
            .pui8Data = (uint8_t*)buf,
            .ui32NumBytes = len,
            .ui32TimeoutMs = UART_RX_TIMEOUT_MS,
            .pui32BytesTransferred = &ui32BytesRead,
        };

        am_hal_uart_transfer(DRV_UART0, &sRead);
    }
    else if(port == SERIAL_UART1)
    {
        am_hal_uart_transfer_t sRead = {
            .ui32Direction = AM_HAL_UART_READ,
            .pui8Data = (uint8_t*)buf,
            .ui32NumBytes = len,
            .ui32TimeoutMs = UART_RX_TIMEOUT_MS,
            .pui32BytesTransferred = &ui32BytesRead,
        };

        am_hal_uart_transfer(DRV_UART1, &sRead);
    }
    
    return ui32BytesRead;
}

volatile bool uart0_tx_flag = false;
void am_uart_isr(void)
{
    // Service the FIFOs as necessary, and clear the interrupts.
    uint32_t err_code, ui32Status, ui32Idle;
    err_code = am_hal_uart_interrupt_status_get(DRV_UART0, &ui32Status, true);
    ERROR_CHECK(err_code);
    err_code = am_hal_uart_interrupt_clear(DRV_UART0, ui32Status);
    ERROR_CHECK(err_code);
    err_code = am_hal_uart_interrupt_service(DRV_UART0, ui32Status, &ui32Idle);
    ERROR_CHECK(err_code);

    //
    // If there's an RX interrupt, handle it in a way that preserves the
    // timeout interrupt on gaps between packets.
    //
    if (ui32Status & (AM_HAL_UART_INT_TXCMP)) {
        uart0_tx_flag = true;
    }
    else if (ui32Status & (AM_HAL_UART_INT_RX_TMOUT | AM_HAL_UART_INT_RX))
    {
        uint8_t rxBuf[MAX_READ_BYTES] = {0};
        uint32_t ui32BytesRead =  uart_read(0, (char *) rxBuf, MAX_READ_BYTES);
        
        BaseType_t xHigherPriorityTaskWoken, xResult;
        for(uint16_t i = 0; i < (ui32BytesRead); i++)
        {
            xResult = xQueueSendToBackFromISR(UART0_RxQueue, &rxBuf[i], &xHigherPriorityTaskWoken);
            if (xResult != pdFAIL)
                portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }

        //
        // If there is a TMOUT interrupt, assume we have a compete packet
        //
        if (ui32Status & (AM_HAL_UART_INT_RX_TMOUT))
        {
            xResult = xSemaphoreGiveFromISR(UART0_RxSemaphore, &xHigherPriorityTaskWoken);
            if (xResult != pdFAIL)
                portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }
    }
}


volatile bool uart1_tx_flag = false;
void am_uart1_isr(void)
{
    // Service the FIFOs as necessary, and clear the interrupts.
    uint32_t err_code, ui32Status, ui32Idle;
    err_code = am_hal_uart_interrupt_status_get(DRV_UART1, &ui32Status, true);
    ERROR_CHECK(err_code);
    err_code = am_hal_uart_interrupt_clear(DRV_UART1, ui32Status);
    ERROR_CHECK(err_code);
    err_code = am_hal_uart_interrupt_service(DRV_UART1, ui32Status, &ui32Idle);
    ERROR_CHECK(err_code);

    //
    // If there's an RX interrupt, handle it in a way that preserves the
    // timeout interrupt on gaps between packets.
    //
    if (ui32Status & (AM_HAL_UART_INT_TXCMP)) {
        uart1_tx_flag = true;
    }
    else if (ui32Status & (AM_HAL_UART_INT_RX_TMOUT | AM_HAL_UART_INT_RX))
    {
        uint8_t rxBuf[MAX_READ_BYTES] = {0};
        uint32_t ui32BytesRead =  uart_read(1, (char *) rxBuf, MAX_READ_BYTES);
        
        BaseType_t xHigherPriorityTaskWoken, xResult;
        for(uint16_t i = 0; i < (ui32BytesRead); i++)
        {
            xResult = xQueueSendToBackFromISR(UART1_RxQueue, &rxBuf[i], &xHigherPriorityTaskWoken);
            if (xResult != pdFAIL)
                portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }
        
        //
        // If there is a TMOUT interrupt, assume we have a compete packet
        //
        if (ui32Status & (AM_HAL_UART_INT_RX_TMOUT))
        {
            xResult = xSemaphoreGiveFromISR(UART1_RxSemaphore, &xHigherPriorityTaskWoken);
            if (xResult != pdFAIL)
                portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }
    }
}

// TX Task to send data over UART
void UART0_taskTx(void *pvPaParameters)
{
    static uint8_t tx_buffer[UART_TX_QUEUE_LEN] = {0};
    uint8_t c = 0;

    while(1)
    {
        xSemaphoreTake(UART0_TxSemaphore, portMAX_DELAY);

        uint16_t size = uxQueueMessagesWaiting(UART0_TxQueue);
        if(size != 0)
        {
            for(uint16_t i = 0; i < size; i++)
            {
                xQueueReceive(UART0_TxQueue, &c, portMAX_DELAY);
                tx_buffer[i] = c;        
            }

            uint32_t ui32BytesWritten = 0;
            const am_hal_uart_transfer_t sUartWrite =
            {
                .ui32Direction = AM_HAL_UART_WRITE,
                .pui8Data = (uint8_t*) tx_buffer,
                .ui32NumBytes = size,
                .ui32TimeoutMs = AM_HAL_UART_WAIT_FOREVER,
                .pui32BytesTransferred = &ui32BytesWritten,
            };

            am_hal_uart_transfer(DRV_UART0, &sUartWrite);
        }
    }
}

// RX Task to handle incoming data via UART
void UART0_taskRx(void *pvPaParameters)
{
    uint8_t c = 0;

    while(1)
    {
        xSemaphoreTake(UART0_RxSemaphore, portMAX_DELAY);

        uint16_t size = uxQueueMessagesWaiting(UART0_RxQueue);
        for(uint16_t i = 0; i < size; i++)
        {
          xQueueReceive(UART0_RxQueue, &c, portMAX_DELAY);
          serial_fallback_handler(SERIAL_UART0,  c);
          fund_circular_queue_in(&SERIAL_UART0_rxq, &c, 1);
        }

        udrv_system_event_produce(&rui_uart_event);
        am_log_inf("UART0: udrv_system_event_produce");
    }
}

// TX Task to send data over UART
void UART1_taskTx(void *pvPaParameters)
{
    static uint8_t tx_buffer[UART_TX_QUEUE_LEN] = {0};

    while(1)
    {
        xSemaphoreTake(UART1_TxSemaphore, portMAX_DELAY);

        uint16_t size = uxQueueMessagesWaiting(UART1_TxQueue);
        if(size != 0)
        {
            uint8_t c = 0;

            for(uint16_t i = 0; i < size; i++)
            {
              xQueueReceive(UART1_TxQueue, &c, portMAX_DELAY);
              tx_buffer[i] = c;        
            }
            tx_buffer[size] = 0;

            uint32_t ui32BytesWritten = 0;
            const am_hal_uart_transfer_t sUartWrite =
            {
                .ui32Direction = AM_HAL_UART_WRITE,
                .pui8Data = (uint8_t*) tx_buffer,
                .ui32NumBytes = size,
                .ui32TimeoutMs = AM_HAL_UART_WAIT_FOREVER,
                .pui32BytesTransferred = &ui32BytesWritten,
            };
            // size must be equal to ui32BytesWritten value!!!
            
            am_hal_uart_transfer(DRV_UART1, &sUartWrite);
        }
    }
}

// RX Task to handle incoming data via UART
void UART1_taskRx(void *pvPaParameters)
{
    uint8_t c = 0;
    bool first = true;

    while(1)
    {
        xSemaphoreTake(UART1_RxSemaphore, portMAX_DELAY);

        uint16_t size = uxQueueMessagesWaiting(UART1_RxQueue);
        for(uint16_t i = 0; i < size; i++)
        {
          xQueueReceive(UART1_RxQueue, &c, portMAX_DELAY);
          serial_fallback_handler(SERIAL_UART1,  c);
          fund_circular_queue_in(&SERIAL_UART1_rxq, &c, 1);
        }

        udrv_system_event_produce(&rui_uart_event);
        am_log_inf("UART1: udrv_system_event_produce");
    }
}

static uint32_t get_apollo_uart_baudrate(uint32_t baudrate)
{
    if (baudrate > 0 && baudrate <= 1800/* (1200+2400)/2 */) {
        return 1200;
    } else if (baudrate > 1800/* (1200+2400)/2 */ && baudrate <= 3600/* (2400+4800)/2 */) {
        return 2400;
    } else if (baudrate > 3600/* (2400+4800)/2 */ && baudrate <= 7200/* (4800+9600)/2 */) {
        return 4800;
    } else if (baudrate > 7200/* (4800+9600)/2 */ && baudrate <= 12000/* (9600+14400)/2 */) {
        return 9600;
    } else if (baudrate > 12000/* (9600+14400)/2 */ && baudrate <= 16800/* (14400+19200)/2 */) {
        return 14400;
    } else if (baudrate > 16800/* (14400+19200)/2 */ && baudrate <= 24000/* (19200+28800)/2 */) {
        return 19200;
    } else if (baudrate > 24000/* (19200+28800)/2 */ && baudrate <= 30025/* (28800+31250)/2 */) {
        return 28800;
    } else if (baudrate > 30025/* (28800+31250)/2 */ && baudrate <= 34825/* (31250+38400)/2 */) {
        return 31250;
    } else if (baudrate > 34825/* (31250+38400)/2 */ && baudrate <= 47200/* (38400+56000)/2 */) {
        return 38400;
    } else if (baudrate > 47200/* (38400+56000)/2 */ && baudrate <= 56800/* (56000+57600)/2 */) {
        return 56000;
    } else if (baudrate > 56800/* (56000+57600)/2 */ && baudrate <= 67200/* (57600+76800)/2 */) {
        return 57600;
    } else if (baudrate > 67200/* (57600+76800)/2 */ && baudrate <= 96000/* (76800+115200)/2 */) {
        return 76800;
    } else if (baudrate > 96000/* (76800+115200)/2 */ && baudrate <= 172800/* (115200+230400)/2 */) {
        return 115200;
    } else if (baudrate > 172800/* (115200+230400)/2 */ && baudrate <= 240200/* (230400+250000)/2 */) {
        return 230400;
    } else if (baudrate > 240200/* (230400+250000)/2 */ && baudrate <= 355400/* (250000+460800)/2 */) {
        return 250000;
    } else if (baudrate > 355400/* (250000+460800)/2 */ && baudrate <= 691200/* (460800+921600)/2 */) {
        return 460800;
    } else if (baudrate > 691200/* (460800+921600)/2 */ && baudrate <= 960800/* (921600+1000000)/2 */) {
        return 921600;
    } else if (baudrate > 960800/* (921600+1000000)/2 */) {
        return 1000000;
    }

    return -1;
}

// FIXME
static am_hal_uart_state_t DRV_UART0_COPY;
static am_hal_uart_state_t DRV_UART1_COPY;

static void uart_init(SERIAL_PORT port, uint32_t baudrate, SERIAL_WIRE_MODE_E WireMode)
{
    uint32_t err_code=0;

    am_hal_gpio_pincfg_t uart_tx_pinconfig;
    am_hal_gpio_pincfg_t uart_rx_pinconfig;

    memset(&uart_tx_pinconfig, 0, sizeof(am_hal_gpio_pincfg_t));
    memset(&uart_rx_pinconfig, 0, sizeof(am_hal_gpio_pincfg_t));

    if(port == SERIAL_UART0)
    {
      uart_tx_pinconfig.uFuncSel = UART0_TXD_PAD;
      uart_tx_pinconfig.eDriveStrength = AM_HAL_GPIO_PIN_DRIVESTRENGTH_2MA;
      uart_rx_pinconfig.uFuncSel = UART0_RXD_PAD;
      uart_rx_pinconfig.eDriveStrength = AM_HAL_GPIO_PIN_DRIVESTRENGTH_2MA;    
    }
    else if(port == SERIAL_UART1)
    {
      uart_tx_pinconfig.uFuncSel = UART1_TXD_PAD;
      uart_tx_pinconfig.eDriveStrength = AM_HAL_GPIO_PIN_DRIVESTRENGTH_2MA;
      uart_rx_pinconfig.uFuncSel = UART1_RXD_PAD;
      uart_rx_pinconfig.eDriveStrength = AM_HAL_GPIO_PIN_DRIVESTRENGTH_2MA; 
      uart_rx_pinconfig.ePullup =  AM_HAL_GPIO_PIN_PULLUP_24K;
    }
    else
    {
      return;
    }

    const am_hal_uart_config_t uart_config = 
    {
        // Standard UART settings: 115200-8-N-1
        .ui32BaudRate = get_apollo_uart_baudrate(baudrate),
        .ui32DataBits = AM_HAL_UART_DATA_BITS_8,
        .ui32Parity = AM_HAL_UART_PARITY_NONE,
        .ui32StopBits = AM_HAL_UART_ONE_STOP_BIT,
        .ui32FlowControl = AM_HAL_UART_FLOW_CTRL_NONE,

        // Set TX and RX FIFOs to interrupt at half-full.
        .ui32FifoLevels = (AM_HAL_UART_TX_FIFO_3_4 |
                           AM_HAL_UART_RX_FIFO_3_4),
        //
        // Buffers
        //
        .pui8TxBuffer = 0,
        .ui32TxBufferSize = 0,
        .pui8RxBuffer = 0,
        .ui32RxBufferSize = 0,
    };

    if(port == SERIAL_UART0)
    {
        // Initialize the printf interface for UART output.
        err_code=am_hal_uart_initialize(port, &DRV_UART0);
        ERROR_CHECK(err_code);
        err_code=am_hal_uart_power_control(DRV_UART0, AM_HAL_SYSCTRL_WAKE, false);
        ERROR_CHECK(err_code);
        err_code=am_hal_uart_configure(DRV_UART0, &uart_config);
        ERROR_CHECK(err_code);

        // Enable the UART pins.
        err_code=am_hal_gpio_pinconfig(UART0_TXD_PIN, uart_tx_pinconfig);
        ERROR_CHECK(err_code);        
        err_code=am_hal_gpio_pinconfig(UART0_RXD_PIN, uart_rx_pinconfig);
        ERROR_CHECK(err_code);

        // Create Tasks
        if(UART0_RxSemaphore == NULL)
          UART0_RxSemaphore = xSemaphoreCreateBinary();
        if(UART0_RxQueue == NULL)
          UART0_RxQueue = xQueueCreate(UART_RX_QUEUE_LEN, UART_RX_QUEUE_SIZE);
        if(UART0_TxSemaphore == NULL)
          UART0_TxSemaphore = xSemaphoreCreateBinary();
        if(UART0_TxQueue == NULL)
          UART0_TxQueue = xQueueCreate(UART_TX_QUEUE_LEN, UART_TX_QUEUE_SIZE);

        // Create mutex before starting tasks
        if(UART0_TxMutex == NULL)
          UART0_TxMutex = xSemaphoreCreateMutex();

        static bool UART0_taskRx_status = false;
        if(UART0_taskRx_status == false)
        {
          xTaskCreate(
              (TaskFunction_t) UART0_taskRx,
              "UART0_taskRx",
              configMINIMAL_STACK_SIZE,
              NULL,
              RAK_TASK_PRIO_NORMAL,
              &UART0_RxTask
          );

          UART0_taskRx_status = true;
        }

        static bool UART0_taskTx_status = false;
        if(UART0_taskTx_status == false)
        {
          xTaskCreate(
              (TaskFunction_t) UART0_taskTx,
              "UART0_taskTx",
              configMINIMAL_STACK_SIZE,
              NULL,
              RAK_TASK_PRIO_NORMAL,
              &UART0_TxTask
          );

          UART0_taskTx_status = true;
        }

        // Enable interrupts.
        NVIC_SetPriority((IRQn_Type)(UART0_IRQn + port), NVIC_configMAX_SYSCALL_INTERRUPT_PRIORITY);
        NVIC_EnableIRQ((IRQn_Type)(UART0_IRQn + port));
        err_code=am_hal_uart_interrupt_enable(DRV_UART0, (AM_HAL_UART_INT_TXCMP | AM_HAL_UART_INT_RX | AM_HAL_UART_INT_RX_TMOUT));
        ERROR_CHECK(err_code);

        memcpy(&DRV_UART0_COPY, DRV_UART0, sizeof(am_hal_uart_state_t));
    }
    else if(port == SERIAL_UART1)
    {
        // Initialize the printf interface for UART output.
        err_code=am_hal_uart_initialize(port, &DRV_UART1);
        ERROR_CHECK(err_code);
        err_code=am_hal_uart_power_control(DRV_UART1, AM_HAL_SYSCTRL_WAKE, false);
        ERROR_CHECK(err_code);
        err_code=am_hal_uart_configure(DRV_UART1, &uart_config);
        ERROR_CHECK(err_code);

        // Enable the UART pins.
        err_code=am_hal_gpio_pinconfig(UART1_TXD_PIN, uart_tx_pinconfig);
        ERROR_CHECK(err_code);
        err_code=am_hal_gpio_pinconfig(UART1_RXD_PIN, uart_rx_pinconfig);
        ERROR_CHECK(err_code);

        // Create Tasks
        if(UART1_RxSemaphore == NULL)
          UART1_RxSemaphore = xSemaphoreCreateBinary();
        if(UART1_RxQueue == NULL)
          UART1_RxQueue = xQueueCreate(UART_RX_QUEUE_LEN, UART_RX_QUEUE_SIZE);
        if(UART1_TxSemaphore == NULL)
          UART1_TxSemaphore = xSemaphoreCreateBinary();
        if(UART1_TxQueue == NULL)
          UART1_TxQueue = xQueueCreate(UART_TX_QUEUE_LEN, UART_TX_QUEUE_SIZE);

        // Create mutex before starting tasks
        if(UART1_TxMutex == NULL)
          UART1_TxMutex = xSemaphoreCreateMutex();

        static bool UART1_taskRx_status = false;
        if(UART1_taskRx_status == false)
        {
          xTaskCreate(
              (TaskFunction_t) UART1_taskRx,
              "UART1_taskRx",
              configMINIMAL_STACK_SIZE,
              NULL,
              RAK_TASK_PRIO_NORMAL,
              &UART1_RxTask
          );

          UART1_taskRx_status = true;
        }

        static bool UART1_taskTx_status = false;
        if(UART1_taskTx_status == false)
        {
          xTaskCreate(
              (TaskFunction_t) UART1_taskTx,
              "UART1_taskTx",
              configMINIMAL_STACK_SIZE,
              NULL,
              RAK_TASK_PRIO_NORMAL,
              &UART1_TxTask
          );

          UART1_taskTx_status = true;
        }

        // Enable interrupts.
        NVIC_SetPriority((IRQn_Type)(UART0_IRQn + port), NVIC_configMAX_SYSCALL_INTERRUPT_PRIORITY);
        NVIC_EnableIRQ((IRQn_Type)(UART0_IRQn + port));
        err_code=am_hal_uart_interrupt_enable(DRV_UART1, (AM_HAL_UART_INT_TXCMP | AM_HAL_UART_INT_RX | AM_HAL_UART_INT_RX_TMOUT));
        ERROR_CHECK(err_code);

        memcpy(&DRV_UART1_COPY, DRV_UART1, sizeof(am_hal_uart_state_t));
    }
    else
    {
        return;
    }
}

static void uart_deinit(SERIAL_PORT port)
{
    uint32_t err_code = 0;

    if (port == SERIAL_UART0) {
        //vSemaphoreDelete(UART0_RxSemaphore);
        //vQueueDelete(UART0_RxQueue);
        //vSemaphoreDelete(UART0_TxSemaphore);
        //vQueueDelete(UART0_TxQueue);
        //vSemaphoreDelete(UART0_TxMutex);
        //vTaskDelete(UART0_RxTask);
        //vTaskDelete(UART0_TxTask);

        // Disable interrupts.
        NVIC_DisableIRQ((IRQn_Type)(UART0_IRQn + port));
        NVIC_ClearPendingIRQ((IRQn_Type)(UART0_IRQn + port));
        err_code = am_hal_uart_interrupt_disable(DRV_UART0, (AM_HAL_UART_INT_TXCMP | AM_HAL_UART_INT_RX | AM_HAL_UART_INT_RX_TMOUT));
        ERROR_CHECK(err_code);
        
        // Disable the UART pins.
        err_code = am_hal_gpio_pinconfig(UART0_TXD_PIN, g_AM_HAL_GPIO_DISABLE);
        ERROR_CHECK(err_code);
        err_code = am_hal_gpio_pinconfig(UART0_RXD_PIN, g_AM_HAL_GPIO_DISABLE);
        ERROR_CHECK(err_code);

        // Deinitialize the UART printf interface.
        err_code = am_hal_uart_power_control(DRV_UART0, AM_HAL_SYSCTRL_DEEPSLEEP, false);
        ERROR_CHECK(err_code);        
        err_code = am_hal_uart_deinitialize(DRV_UART0);
        ERROR_CHECK(err_code);

        // Re-enable that pesky FIFO
        //UARTn(port)->LCRH_b.FEN = 1;
    } 
    else if (port == SERIAL_UART1) {

        //vSemaphoreDelete(UART1_RxSemaphore);
        //vQueueDelete(UART1_RxQueue);
        //vSemaphoreDelete(UART1_TxSemaphore);
        //vQueueDelete(UART1_TxQueue);
        //vSemaphoreDelete(UART1_TxMutex);
        //vTaskDelete(UART1_RxTask);
        //vTaskDelete(UART1_TxTask);

        // Disable interrupts.
        NVIC_DisableIRQ((IRQn_Type)(UART1_IRQn));
        NVIC_ClearPendingIRQ((IRQn_Type)(UART1_IRQn));
        err_code = am_hal_uart_interrupt_disable(DRV_UART1, (AM_HAL_UART_INT_TXCMP | AM_HAL_UART_INT_RX | AM_HAL_UART_INT_RX_TMOUT));
        ERROR_CHECK(err_code);
        
        // Disable the UART pins.
        err_code = am_hal_gpio_pinconfig(UART1_TXD_PIN, g_AM_HAL_GPIO_DISABLE);
        ERROR_CHECK(err_code);
        err_code = am_hal_gpio_pinconfig(UART1_RXD_PIN, g_AM_HAL_GPIO_DISABLE);
        ERROR_CHECK(err_code);
        
        // Deinitialize the UART printf interface.
        err_code = am_hal_uart_power_control(DRV_UART1, AM_HAL_SYSCTRL_DEEPSLEEP, false);
        ERROR_CHECK(err_code);        
        err_code = am_hal_uart_deinitialize(DRV_UART1);
        ERROR_CHECK(err_code);

        // Re-enable that pesky FIFO
        //UARTn(port)->LCRH_b.FEN = 1;
    }
}

void uhal_uart_register_onewire_handler (SERIAL_CLI_HANDLER handler)
{
    ONEWIRE_HANDLER = handler;
}

void uhal_uart_register_cli_handler(SERIAL_CLI_HANDLER handler)
{
    CLI_HANDLER = handler;
}

void uhal_uart_register_lock_handler(SERIAL_CLI_HANDLER handler)
{
    LOCK_HANDLER = handler;
}

void uhal_uart_register_wakeup_handler(SERIAL_CLI_HANDLER handler)
{
    WAKEUP_HANDLER = handler;
}


void uhal_uart_init (SERIAL_PORT Port, uint32_t BaudRate, SERIAL_WORD_LEN_E DataBits, SERIAL_STOP_BIT_E StopBits, SERIAL_PARITY_E Parity, SERIAL_WIRE_MODE_E WireMode)
{
    uart_init(Port, BaudRate, WireMode);

    uart_status[Port].active = true;
    uart_status[Port].baudrate = BaudRate;
    return;
}

void uhal_uart_deinit (SERIAL_PORT Port)
{
    uart_deinit(Port);

    uart_status[Port].active = false;
    return;
}

static void uart_write(SERIAL_PORT port, const uint8_t  *buf, int32_t len)
{
    if(len == 0)
        return;

    // FIXME -- Edited by Sercan ERAT
    if(memcmp(&DRV_UART0_COPY, DRV_UART0, sizeof(am_hal_uart_state_t)) == 0)
    {

    }
    else
    {
        //memcpy(DRV_UART0, &DRV_UART0_COPY, sizeof(am_hal_uart_state_t));
        am_log_inf("Error U0");
    }

    if(memcmp(&DRV_UART1_COPY, DRV_UART1, sizeof(am_hal_uart_state_t)) == 0)
    {

    }
    else
    {
        //memcpy(DRV_UART1, &DRV_UART1_COPY, sizeof(am_hal_uart_state_t));
        am_log_inf("Error U1");
    }
    /*
    am_log_inf("u: %d, br: %d, TxQueue: %d, RxQueue: %d -- %D", DRV_UART0->ui32Module, 
                                                          DRV_UART0->ui32BaudRate,
                                                          DRV_UART0->bEnableTxQueue,
                                                          DRV_UART0->bEnableRxQueue,
                                                          len);

    am_log_inf("u: %d, br: %d, TxQueue: %d, RxQueue: %d", DRV_UART1->ui32Module, 
                                                          DRV_UART1->ui32BaudRate,
                                                          DRV_UART1->bEnableTxQueue,
                                                          DRV_UART1->bEnableRxQueue);
    */
   
    if(port == SERIAL_UART0)
    {
        uint32_t ui32BytesWritten = 0;
        const am_hal_uart_transfer_t sUartWrite =
        {
            .ui32Direction = AM_HAL_UART_WRITE,
            .pui8Data = (uint8_t*) buf,
            .ui32NumBytes = (uint32_t) len,
            .ui32TimeoutMs = AM_HAL_UART_WAIT_FOREVER,
            .pui32BytesTransferred = &ui32BytesWritten,
        };
        // size must be equal to ui32BytesWritten value!!!

        uart0_tx_flag = false;
        am_hal_uart_transfer(DRV_UART0, &sUartWrite);
        volatile uint32_t timeout = 1000000;
        while(uart0_tx_flag == false)
        {
            //timeout--;
            //if(timeout == 0)
            //    break;
        }
    }
    else if(port == SERIAL_UART1)
    {
        uint32_t ui32BytesWritten = 0;
        const am_hal_uart_transfer_t sUartWrite =
        {
            .ui32Direction = AM_HAL_UART_WRITE,
            .pui8Data = (uint8_t*) buf,
            .ui32NumBytes = len,
            .ui32TimeoutMs = AM_HAL_UART_WAIT_FOREVER,
            .pui32BytesTransferred = &ui32BytesWritten,
        };
        // size must be equal to ui32BytesWritten value!!!

        uart1_tx_flag = false;
        am_hal_uart_transfer(DRV_UART1, &sUartWrite);
        volatile uint32_t timeout = 1000000;
        while(uart1_tx_flag == false)
        {
            //timeout--;
            //if(timeout == 0)
            //    break;
        }
    }
}

int32_t uhal_uart_write (SERIAL_PORT Port, uint8_t const *Buffer, int32_t NumberOfBytes, uint32_t Timeout)
{
    if (Buffer == NULL) {
        return -UDRV_WRONG_ARG;
    }

    //if (uart_wire_mode[Port] == SERIAL_ONE_WIRE_TX_PIN_MODE || uart_wire_mode[Port] == SERIAL_ONE_WIRE_RX_PIN_MODE) {
    //    if (single_wire_mode[Port] != SINGLE_WIRE_MODE_TX) {
    //        uhal_single_wire_tx_mode(Port);
    //    }
    //}

    if (Port == SERIAL_UART0) {
        uart_write(Port, Buffer, NumberOfBytes);
        //err_code = nrf_serial_write(&serial_uart0, Buffer, NumberOfBytes, &Count, Timeout);
        //if (uart_wire_mode[Port] == SERIAL_ONE_WIRE_TX_PIN_MODE || uart_wire_mode[Port] == SERIAL_ONE_WIRE_RX_PIN_MODE) {
        //    nrf_serial_flush(&serial_uart0, Timeout);
        //}
    } else if (Port == SERIAL_UART1) {
        uart_write(Port, Buffer, NumberOfBytes);
        //err_code = nrf_serial_write(&serial_uart1, Buffer, NumberOfBytes, &Count, Timeout);
        //if (uart_wire_mode[Port] == SERIAL_ONE_WIRE_TX_PIN_MODE || uart_wire_mode[Port] == SERIAL_ONE_WIRE_RX_PIN_MODE) {
        //    nrf_serial_flush(&serial_uart1, Timeout);
        //}
    }

    //if (uart_wire_mode[Port] == SERIAL_ONE_WIRE_TX_PIN_MODE || uart_wire_mode[Port] == SERIAL_ONE_WIRE_RX_PIN_MODE) {
    //    if (single_wire_mode[Port] != SINGLE_WIRE_MODE_RX) {
    //        uhal_single_wire_rx_mode(Port);
    //    }
    //}

    //switch (err_code) {
    //    case NRF_SUCCESS:
    //        return Count;
    //    case NRF_ERROR_BUSY:
    //        return -UDRV_BUSY;
    //    case NRF_ERROR_INVALID_STATE:
    //    default:
    //        return -UDRV_INTERNAL_ERR;
    //}

    return 0;
}

void uhal_uart_write_buffer (SERIAL_PORT Port, uint8_t const *Buffer, int32_t NumberOfBytes, uint32_t Timeout)
{
    if(NumberOfBytes == 0)
        return;

    // FIXME -- Edited by Sercan ERAT
    if(memcmp(&DRV_UART0_COPY, DRV_UART0, sizeof(am_hal_uart_state_t)) == 0)
    {

    }
    else
    {
        //memcpy(DRV_UART0, &DRV_UART0_COPY, sizeof(am_hal_uart_state_t));
        am_log_inf("Error U0");
    }

    if(memcmp(&DRV_UART1_COPY, DRV_UART1, sizeof(am_hal_uart_state_t)) == 0)
    {

    }
    else
    {
        //memcpy(DRV_UART1, &DRV_UART1_COPY, sizeof(am_hal_uart_state_t));
        am_log_inf("Error U1");
    }
    /*
    am_log_inf("u: %d, br: %d, TxQueue: %d, RxQueue: %d -- %D", DRV_UART0->ui32Module, 
                                                          DRV_UART0->ui32BaudRate,
                                                          DRV_UART0->bEnableTxQueue,
                                                          DRV_UART0->bEnableRxQueue,
                                                          len);

    am_log_inf("u: %d, br: %d, TxQueue: %d, RxQueue: %d", DRV_UART1->ui32Module, 
                                                          DRV_UART1->ui32BaudRate,
                                                          DRV_UART1->bEnableTxQueue,
                                                          DRV_UART1->bEnableRxQueue);
    */
   
    if(Port == SERIAL_UART0)
    {
        
        BaseType_t xHigherPriorityTaskWoken, xResult;

        // Take the mutex
        if(isInISR())
        {
            xResult = xSemaphoreTakeFromISR(UART0_TxMutex, &xHigherPriorityTaskWoken);
            if (xResult != pdFAIL)
                portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }
        else
            xSemaphoreTake(UART0_TxMutex, portMAX_DELAY);
    
        for(uint16_t i = 0; i < NumberOfBytes; i++)
        {
            if(isInISR())
            {
                xResult = xQueueSendToBackFromISR(UART0_TxQueue, &Buffer[i], &xHigherPriorityTaskWoken);
                if (xResult != pdFAIL)
                    portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
            }
            else
            xQueueSendToBack(UART0_TxQueue, &Buffer[i], 2);
        }

        if(isInISR())
        {
            xResult = xSemaphoreGiveFromISR(UART0_TxSemaphore, &xHigherPriorityTaskWoken);
            if (xResult != pdFAIL)
                portYIELD_FROM_ISR( xHigherPriorityTaskWoken );

        }
        else
            xSemaphoreGive(UART0_TxSemaphore);

        // Release the mutex so that the creating function can finish
        if(isInISR())
        {
            xResult = xSemaphoreGiveFromISR(UART0_TxMutex, &xHigherPriorityTaskWoken);
            if (xResult != pdFAIL)
                    portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }
        else
            xSemaphoreGive(UART0_TxMutex);
    }
    else if(Port == SERIAL_UART1)
    {
        BaseType_t xHigherPriorityTaskWoken, xResult;

        // Take the mutex
        if(isInISR())
        {
            xResult = xSemaphoreTakeFromISR(UART1_TxMutex, &xHigherPriorityTaskWoken);
            if (xResult != pdFAIL)
                portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }
        else
            xSemaphoreTake(UART1_TxMutex, portMAX_DELAY);
    
        for(uint16_t i = 0; i < NumberOfBytes; i++)
        {
            if(isInISR())
            {
                xResult = xQueueSendToBackFromISR(UART1_TxQueue, &Buffer[i], &xHigherPriorityTaskWoken);
                if (xResult != pdFAIL)
                    portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
            }
            else
            xQueueSendToBack(UART0_TxQueue, &Buffer[i], 2);
        }

        if(isInISR())
        {
            xResult = xSemaphoreGiveFromISR(UART1_TxSemaphore, &xHigherPriorityTaskWoken);
            if (xResult != pdFAIL)
                portYIELD_FROM_ISR( xHigherPriorityTaskWoken );

        }
        else
            xSemaphoreGive(UART1_TxSemaphore);

        // Release the mutex so that the creating function can finish
        if(isInISR())
        {
            xResult = xSemaphoreGiveFromISR(UART1_TxMutex, &xHigherPriorityTaskWoken);
            if (xResult != pdFAIL)
                portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }
        else
            xSemaphoreGive(UART1_TxMutex);
    }

    return 0;
}


int32_t uhal_uart_read(SERIAL_PORT Port, uint8_t *Buffer, int32_t NumberOfBytes, uint32_t Timeout)
{
    if (Port == SERIAL_UART0) {
        return (int32_t)fund_circular_queue_out(&SERIAL_UART0_rxq, Buffer, NumberOfBytes);
    } else if (Port == SERIAL_UART1) {
        return (int32_t)fund_circular_queue_out(&SERIAL_UART1_rxq, Buffer, NumberOfBytes);
    }
    return -UDRV_INTERNAL_ERR;
}

int32_t uhal_uart_peek(SERIAL_PORT Port)
{
    uint8_t ch;

    if (Port == SERIAL_UART0) {
        return (int32_t)fund_circular_queue_peek(&SERIAL_UART0_rxq, &ch);
    } else if (Port == SERIAL_UART1) {
        return (int32_t)fund_circular_queue_peek(&SERIAL_UART1_rxq, &ch);
    }
    return -UDRV_INTERNAL_ERR;
}

void uhal_uart_flush(SERIAL_PORT Port, uint32_t Timeout)
{
    if (Port == SERIAL_UART0) {
        //uint16_t size = uxQueueMessagesWaiting(UART0_TxQueue);
        //if(size == 0)
        //    return;
        //am_hal_uart_tx_flush(DRV_UART0);
    } else if (Port == SERIAL_UART1) {
        //uint16_t size = uxQueueMessagesWaiting(UART1_TxQueue);
        //if(size == 0)
        //    return;
        //am_hal_uart_tx_flush(DRV_UART1); // FIXME: BLOCK SYSTEM
    }
}

int32_t uhal_uart_read_available(SERIAL_PORT Port)
{
    if (Port == SERIAL_UART0) {
        return (size_t)fund_circular_queue_utilization_get(&SERIAL_UART0_rxq);
    } else if (Port == SERIAL_UART1) {
        return (size_t)fund_circular_queue_utilization_get(&SERIAL_UART1_rxq);
    }
    return -UDRV_INTERNAL_ERR;
}

void uhal_uart_suspend(void) 
{
    if(uart_status[0].active == true)
    {
      //while(1)
      //{
      //    uint16_t size = uxQueueMessagesWaiting(UART0_TxQueue);
      //    if(size == 0)
      //      break;
      //}
      uhal_uart_flush(0, 0);
      uart_deinit(0);
    }
    if(uart_status[1].active == true)
    {
      //while(1)
      //{
      //    uint16_t size = uxQueueMessagesWaiting(UART1_TxQueue);
      //    if(size == 0)
      //      break;
      //}
      uhal_uart_flush(1, 0);
      uart_deinit(1);
    }
}

void uhal_uart_resume(void) {
    for (int i = SERIAL_UART0 ; i < UHAL_UART_MAX ; i++) {
        if (uart_status[i].active == true) {
            uart_init(i, uart_status[i].baudrate, uart_wire_mode[i]);
	}
    }
}

