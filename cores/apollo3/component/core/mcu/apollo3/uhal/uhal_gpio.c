#include "string.h"
#include "uhal_gpio.h"
#include "uhal_powersave.h"
//#include "pin_define.h"
#include "udrv_system.h"
#include "udrv_errno.h"
#include "board-config.h"
#include "error_check.h"
#include "am_log.h"
#include "rtos.h"

// pin configurations
const am_hal_gpio_pincfg_t AM_HAL_GPIO_NULL =
{
    .uFuncSel = 0,       // [2:0]   Function select (FUNCSEL)
    .ePowerSw = 0,       // [4:3]   Pin is a power switch source (VCC) or sink (VSS)
    .ePullup = 0,        // [7:5]   Pin will enable a pullup resistor
    .eDriveStrength = 0, // [9:8]   Pad strength designator
    .eGPOutcfg = 0,      // [11:10] OUTCFG (GPIO config only)
    .eGPInput = 0,       // [12:12] GPIO Input (GPIO config only)
    .eIntDir = 0,        // [14:13] Interrupt direction
    .eGPRdZero = 0,      // [15:15] GPIO read as zero

    //
    // The following descriptors designate the chip enable features of the
    // pin being configured.  If not a CE, these descriptors are ignored.
    // uIOMnum is 0-5 for the IOMs, or 6 for MSPI, 7 is invalid.
    //
    .uIOMnum = 0, // [18:16] IOM number (0-5), 6 for MSPI
    .uNCE = 0,    // [20:19] NCE number (0-3).
    .eCEpol = 0,  // [21:21] NCE polarity.

    .uRsvd22 = 0, // [31:22]
};

// INPUT
const am_hal_gpio_pincfg_t GPIO_INPUT_NOPULL =
{
    .uFuncSel       = 3,
    .ePullup        = AM_HAL_GPIO_PIN_PULLUP_NONE,
    .eGPOutcfg      = AM_HAL_GPIO_PIN_OUTCFG_DISABLE,
    .eGPInput       = AM_HAL_GPIO_PIN_INPUT_ENABLE,
    .eGPRdZero      = AM_HAL_GPIO_PIN_RDZERO_READPIN
};

// OPEN DRAIN
const am_hal_gpio_pincfg_t GPIO_OPENDRAIN =
{
    .uFuncSel            = 3,
    .ePullup             = AM_HAL_GPIO_PIN_PULLUP_NONE,
    .eDriveStrength      = AM_HAL_GPIO_PIN_DRIVESTRENGTH_2MA,
    .eGPOutcfg           = AM_HAL_GPIO_PIN_OUTCFG_OPENDRAIN,
};

extern bool udrv_powersave_in_sleep;
extern bool udrv_powersave_in_deep_sleep;
extern bool udrv_powersave_early_wakeup;
extern void RadioOnDioIrq( void* context );

static udrv_system_event_t rui_gpio_int_event[M_MAX_GPIO_PIN];

static gpio_isr_func sg_gpio_isr[M_MAX_GPIO_PIN];

static gpio_intc_trigger_mode_t uhal_gpio_wakeup_mode = GPIO_INTC_RISING_FALLING_EDGE;

typedef struct uhal_gpio_status {
    am_hal_gpio_pincfg_t gpio;
    bool wakeup_source;
} uhal_gpio_status_t;

static uhal_gpio_status_t gpio_status[M_MAX_GPIO_PIN];

void uhal_gpio_handler_handler(void *pdata)
{
    if (sg_gpio_isr[(uint32_t)pdata]) {
        sg_gpio_isr[(uint32_t)pdata]((uint32_t)pdata);
    }
}

static void gpio_wakeup_handler(uint32_t irq_num)
{
    udrv_powersave_in_sleep = false;
    udrv_powersave_early_wakeup = true;
    uhal_mcu_wake_up();
}

void uhal_gpio_init(uint32_t pin, gpio_dir_t dir, gpio_pull_t pull, gpio_logic_t logic) {
    if (pin >= M_MAX_GPIO_PIN) {
        return;
    }
    
    //gpio[pin] = AM_HAL_GPIO_NULL; // Edited by Sercan ERAT

    uhal_gpio_set_dir(pin, dir);
    if (dir == GPIO_DIR_OUT) {
        uhal_gpio_set_logic(pin, logic);
    }
    uhal_gpio_set_pull(pin, pull);
}

void uhal_gpio_set_dir(uint32_t pin, gpio_dir_t dir)
{
    if (pin >= M_MAX_GPIO_PIN) {
        return;
    }

    //gpio[pin] = AM_HAL_GPIO_NULL; // Edited by Sercan ERAT

    if (dir == GPIO_DIR_OUT) {
      gpio_status[pin].gpio.uFuncSel       = 3;
      gpio_status[pin].gpio.eDriveStrength = AM_HAL_GPIO_PIN_DRIVESTRENGTH_12MA;
      gpio_status[pin].gpio.eGPOutcfg      = AM_HAL_GPIO_PIN_OUTCFG_PUSHPULL;
      gpio_status[pin].gpio.eGPRdZero      = AM_HAL_GPIO_PIN_RDZERO_READPIN;
    } else if (dir == GPIO_DIR_IN) {
      gpio_status[pin].gpio.uFuncSel       = 3;
      gpio_status[pin].gpio.eGPOutcfg      = AM_HAL_GPIO_PIN_OUTCFG_DISABLE;
      gpio_status[pin].gpio.eGPInput       = AM_HAL_GPIO_PIN_INPUT_ENABLE;
      gpio_status[pin].gpio.eGPRdZero      = AM_HAL_GPIO_PIN_RDZERO_READPIN;
      // gpio[pin].ePullup        = AM_HAL_GPIO_PIN_PULLUP_NONE; // Edited by Sercan ERAT
    }
    
    uint32_t err_code = am_hal_gpio_pinconfig(pin, gpio_status[pin].gpio);
    ERROR_CHECK(err_code);
}

void uhal_gpio_set_pull(uint32_t pin, gpio_pull_t pull)
{
    if (pin >= M_MAX_GPIO_PIN) {
        return;
    }

    if (pull == GPIO_PULL_DOWN) {
        // gpio_status[pin].gpio.ePullup = AM_HAL_GPIO_PIN_PULLDOWN;
    } else if (pull == GPIO_PULL_UP) {
        gpio_status[pin].gpio.ePullup = AM_HAL_GPIO_PIN_PULLUP_WEAK;
    } else if (pull == GPIO_PULL_NONE) {
        gpio_status[pin].gpio.ePullup = AM_HAL_GPIO_PIN_PULLUP_NONE;
    }

    uint32_t err_code = am_hal_gpio_pinconfig(pin, gpio_status[pin].gpio);
    ERROR_CHECK(err_code);
}

void uhal_gpio_set_logic(uint32_t pin, gpio_logic_t logic) {
    if (pin >= M_MAX_GPIO_PIN) {
        return;
    }

    if (logic == GPIO_LOGIC_LOW) {
        uint32_t err_code = am_hal_gpio_state_write(pin, AM_HAL_GPIO_OUTPUT_CLEAR);
        ERROR_CHECK(err_code);
    } else if (logic == GPIO_LOGIC_HIGH) {
        uint32_t err_code = am_hal_gpio_state_write(pin, AM_HAL_GPIO_OUTPUT_SET);
        ERROR_CHECK(err_code);
    }
}

gpio_logic_t uhal_gpio_get_logic(uint32_t pin) {
    if (pin >= M_MAX_GPIO_PIN) {
        return (0xFF);
    }

    // determine if output or input
    uint32_t ui32BaseAddr = pin / 8;
    uint32_t ui32BaseShift = ((pin % 8) * 4) + 1;
    uint8_t output = ((AM_REGVAL(&GPIO->CFGA + ui32BaseAddr) >> ui32BaseShift) & 0x03);

    if (output)
    {
      if (am_hal_gpio_output_read((uint32_t)pin) == 0) {
          return GPIO_LOGIC_LOW;
      } else {
          return GPIO_LOGIC_HIGH;
      }
    }
    else
    {
      if (am_hal_gpio_input_read((uint32_t)pin) == 0) {
          return GPIO_LOGIC_LOW;
      } else {
          return GPIO_LOGIC_HIGH;
      }
    }
}

void uhal_gpio_toggle_logic(uint32_t pin) {
    if (pin >= M_MAX_GPIO_PIN) {
        return;
    }

    uint32_t err_code = am_hal_gpio_state_write(pin, AM_HAL_GPIO_OUTPUT_TOGGLE);
    ERROR_CHECK(err_code);
}

//*****************************************************************************
//
// GPIO interrupt service routine.
//
//*****************************************************************************
static void rak_hal_gpio_interrupt_service(uint32_t pinNumber)
{
    if (sg_gpio_isr[pinNumber] != NULL)
    {
        if (gpio_status[pinNumber].wakeup_source == true)
        {
            sg_gpio_isr[pinNumber]((uint32_t)pinNumber);
            return;
        }

        if (pinNumber == WB_RXD0 && sg_gpio_isr[pinNumber] != NULL)
        {
            sg_gpio_isr[pinNumber]((uint32_t)pinNumber);
            return;
        }

        if (pinNumber == WB_RXD1 && sg_gpio_isr[pinNumber] != NULL)
        {
            sg_gpio_isr[pinNumber]((uint32_t)pinNumber);
            return;
        }

        if(sg_gpio_isr[pinNumber] == NULL)
        {
            return;
        }

        udrv_powersave_in_sleep = false;
        rui_gpio_int_event[pinNumber].request = UDRV_SYS_EVT_OP_GPIO_INTERRUPT;
        rui_gpio_int_event[pinNumber].p_context = (void *) (long) pinNumber;
        udrv_system_event_produce(&rui_gpio_int_event[pinNumber]);

        if(uhal_mcu_sleep_status() == true)
        {
            // Clear UART Interrupts...
            uhal_gpio_intc_clear(WB_RXD0);
            uhal_gpio_pin_suspend(WB_RXD0);

            uhal_gpio_intc_clear(WB_RXD1);
            uhal_gpio_pin_suspend(WB_RXD1);

            // Resume peripherals...
            uhal_mcu_resume();

            udrv_system_event_consume();

            // Suspend peripherals...
            uhal_mcu_suspend();
        }
    }
} // rak_hal_gpio_interrupt_service()

static TaskHandle_t      gpio_int_task;
static SemaphoreHandle_t gpio_int_task_semaphore;
volatile uint64_t intStatus = 0;
void gpio_int_task_handler(void *pvPaParameters)
{
    while(1)
    {
        xSemaphoreTake(gpio_int_task_semaphore, portMAX_DELAY);

        uint32_t ui32Status1 = (uint32_t)(intStatus >> 0);
        uint32_t ui32Status2 = (uint32_t)(intStatus >> 32);

        for(int pin = 0; pin < 50; pin++)
        {
            uint32_t ui32PinLow = (ui32Status1 & (0x1 << pin));
            uint32_t ui32PinHigh = (ui32Status2 & (0x1 << pin));
            if(ui32PinLow != 0)
            {
                am_log_inf("GP INT PIN: %d", pin);
                rak_hal_gpio_interrupt_service(pin);
            }

            if(ui32PinHigh != 0)
            {
                am_log_inf("GP INT PIN: %d", 32 + pin);
                rak_hal_gpio_interrupt_service(32 + pin);
            }
        }
    }
}

//*****************************************************************************
//
// Interrupt handler for the GPIO pins.
//
//*****************************************************************************
void
am_gpio_isr(void)
{
    #if CFG_SYSVIEW
    SEGGER_SYSVIEW_RecordEnterISR();
    #endif

    //
    // Read and clear the GPIO interrupt status.
    //
    uint64_t ui64Status;
    uint32_t err_code;

    err_code = am_hal_gpio_interrupt_status_get(true, &ui64Status);
    ERROR_CHECK(err_code);
    err_code = am_hal_gpio_interrupt_clear(ui64Status);
    ERROR_CHECK(err_code);
    
    // Interrupt Control
    if(ui64Status != 0)
    {
        am_log_inf("am_gpio_isr");

        intStatus = ui64Status;
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        if(xSemaphoreGiveFromISR(gpio_int_task_semaphore, &xHigherPriorityTaskWoken) != pdFAIL)
        {
            portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }
    }

    #if CFG_SYSVIEW
    SEGGER_SYSVIEW_RecordExitISR();
    #endif
}


void uhal_gpio_intc_trigger_mode(uint32_t pin, gpio_intc_trigger_mode_t mode) {

    if (pin >= M_MAX_GPIO_PIN) {
        return;
    }

    uhal_gpio_set_dir((uint32_t)pin, GPIO_DIR_IN);

    switch (mode) {
        case GPIO_INTC_HIGH_LEVEL:
        case GPIO_INTC_RISING_EDGE:
             gpio_status[pin].gpio.eIntDir = AM_HAL_GPIO_PIN_INTDIR_LO2HI;
            break;
        case GPIO_INTC_LOW_LEVEL:
        case GPIO_INTC_FALLING_EDGE:
             gpio_status[pin].gpio.eIntDir = AM_HAL_GPIO_PIN_INTDIR_HI2LO;
            break;
        default:
             gpio_status[pin].gpio.eIntDir = AM_HAL_GPIO_PIN_INTDIR_BOTH;
            break;
    }

    uint32_t err_code = am_hal_gpio_pinconfig(pin, gpio_status[pin].gpio);
    ERROR_CHECK(err_code);
}

static void uhal_gpio_wakeup_trigger_mode(uint32_t pin, gpio_intc_trigger_mode_t mode) {

    if (pin >= M_MAX_GPIO_PIN) {
        return;
    }
    
    uhal_gpio_set_dir((uint32_t)pin, GPIO_DIR_IN);

    switch (mode) {
        case GPIO_INTC_HIGH_LEVEL:
        case GPIO_INTC_RISING_EDGE:
            udrv_gpio_set_pull((uint32_t)pin, GPIO_PULL_DOWN);
             gpio_status[pin].gpio.eIntDir = AM_HAL_GPIO_PIN_INTDIR_LO2HI;
            break;
        case GPIO_INTC_LOW_LEVEL:
        case GPIO_INTC_FALLING_EDGE:
            udrv_gpio_set_pull((uint32_t)pin, GPIO_PULL_UP);
             gpio_status[pin].gpio.eIntDir = AM_HAL_GPIO_PIN_INTDIR_HI2LO;
            break;
        default:
            udrv_gpio_set_pull((uint32_t)pin, GPIO_PULL_NONE);
             gpio_status[pin].gpio.eIntDir = AM_HAL_GPIO_PIN_INTDIR_BOTH;
            break;
    }

    uint32_t err_code = am_hal_gpio_pinconfig(pin, gpio_status[pin].gpio);
    ERROR_CHECK(err_code);

    uhal_gpio_register_isr(pin, gpio_wakeup_handler);
}

int32_t uhal_gpio_register_isr(uint32_t pin, gpio_isr_func handler) {
    if (pin >= M_MAX_GPIO_PIN) {
        return -UDRV_WRONG_ARG;
    }

    sg_gpio_isr[pin] = handler;
    
    if(gpio_int_task_semaphore == NULL)
          gpio_int_task_semaphore = xSemaphoreCreateBinary();

    static bool gpio_int_task_status = false;
    if(gpio_int_task_status == false)
    {
        xTaskCreate(
            (TaskFunction_t) gpio_int_task_handler,
            "GPIO_INT_TASK",
            configMINIMAL_STACK_SIZE*4,
            NULL,
            RAK_TASK_PRIO_NORMAL,
            &gpio_int_task
        );

        gpio_int_task_status = true;
    }

    //
    // Disabled the GPIO/button interrupt.
    //
    volatile uint64_t pGpioIntMask=0;
    am_hal_gpio_interrupt_disable(AM_HAL_GPIO_MASKBIT(pGpioIntMask, pin));

    //
    // Clear the GPIO Interrupt (write to clear).
    //
    am_hal_gpio_interrupt_clear(AM_HAL_GPIO_MASKBIT(pGpioIntMask, pin));

    //
    // Enable the GPIO/button interrupt.
    //
    am_hal_gpio_interrupt_enable(AM_HAL_GPIO_MASKBIT(pGpioIntMask, pin));

    static bool is_gpio_int_enabled = false;

    if(is_gpio_int_enabled == false)
    {
        NVIC_SetPriority(GPIO_IRQn, NVIC_configMAX_SYSCALL_INTERRUPT_PRIORITY);
        NVIC_EnableIRQ(GPIO_IRQn);

        //
        // Enable interrupts to the core.
        //
        am_hal_interrupt_master_enable();

        is_gpio_int_enabled = true;
    }

    return 0;
}

void uhal_gpio_intc_clear(uint32_t pin) {

    if (pin >= M_MAX_GPIO_PIN) {
        return;
    }

    uint32_t err_code = am_hal_gpio_interrupt_disable(AM_HAL_GPIO_BIT(pin));
    ERROR_CHECK(err_code);

    err_code = am_hal_gpio_interrupt_clear(AM_HAL_GPIO_BIT(pin));
    ERROR_CHECK(err_code);

    gpio_status[pin].gpio.eIntDir = AM_HAL_GPIO_PIN_INTDIR_NONE;
    err_code = am_hal_gpio_pinconfig(pin, gpio_status[pin].gpio);
    ERROR_CHECK(err_code);

    // Clear out the last entry
    sg_gpio_isr[pin] = NULL;
}

void uhal_gpio_set_wakeup_enable(uint32_t pin) {
    if (pin >= M_MAX_GPIO_PIN) {
        return;
    }

    gpio_status[pin].wakeup_source = true;
}

void uhal_gpio_set_wakeup_disable(uint32_t pin) {
    if (pin >= M_MAX_GPIO_PIN) {
        return;
    }

    if(gpio_status[pin].wakeup_source == true)
    {
      uhal_gpio_intc_clear(pin);
      uint32_t err_code = am_hal_gpio_pinconfig(pin, g_AM_HAL_GPIO_DISABLE);
      ERROR_CHECK(err_code);
      gpio_status[pin].wakeup_source = false;
    }
    
}

void uhal_gpio_set_wakeup_mode(gpio_intc_trigger_mode_t mode) {
    uhal_gpio_wakeup_mode = mode;
}

void uhal_gpio_pin_suspend(uint32_t pin)
{
    am_hal_gpio_pinconfig(pin, g_AM_HAL_GPIO_DISABLE);
}

void uhal_gpio_suspend(void) {
     for (int i = 0 ; i < M_MAX_GPIO_PIN ; i++) 
     {
        if (i == 20 || i == 21 
            ) {
            continue;
        }
        
        if (i == WB_A0 || i == WB_A1)
        {

            // GPIO INPUT
            uint32_t err_code = am_hal_gpio_pinconfig(i, GPIO_OPENDRAIN);
            ERROR_CHECK(err_code);

            // GPIO OPENDRAIN
            // uint32_t err_code = am_hal_gpio_pinconfig(i, GPIO_OPENDRAIN);
            // ERROR_CHECK(err_code);

        }

        if (gpio_status[i].wakeup_source == true)
        {
            uhal_gpio_wakeup_trigger_mode(i, uhal_gpio_wakeup_mode);
            continue;
        }

#ifdef SUPPORT_LORA
        //if (i == RADIO_RESET)
        //{
        //    am_hal_gpio_pinconfig(i, g_AM_HAL_GPIO_DISABLE);
        //    continue;
        //}
        if (i == RADIO_ANT_SW)
        {
            am_hal_gpio_pinconfig(i, g_AM_HAL_GPIO_DISABLE);
            continue;
        }
        //if (i == RADIO_NSS)
        //{
        //    am_hal_gpio_pinconfig(i, g_AM_HAL_GPIO_DISABLE);
        //    continue;
        //}
        //if (i == RADIO_BUSY)
        //{
        //    am_hal_gpio_pinconfig(i, g_AM_HAL_GPIO_DISABLE);
        //    continue;
        //}
#endif

        if (sg_gpio_isr[i] != NULL)
        {
            continue;
        }

        //am_hal_gpio_pinconfig(i, g_AM_HAL_GPIO_DISABLE); // (Why are we disabling all pin???)
    }

    return;
}

void uhal_gpio_resume(void) {
    for (int i = 0 ; i < M_MAX_GPIO_PIN ; i++) 
    {
        if (i == 20 || i == 21 
            ) {
            continue;
	    }
  
#ifdef SUPPORT_LORA
        //if (i == RADIO_RESET)
        //{
        //    am_hal_gpio_pinconfig(i, g_AM_HAL_GPIO_DISABLE);
        //    continue;
        //}
        if (i == RADIO_ANT_SW)
        {
            am_hal_gpio_pinconfig(i, gpio_status[i].gpio);
            continue;
        }
        //if (i == RADIO_NSS)
        //{
        //    am_hal_gpio_pinconfig(i, g_AM_HAL_GPIO_DISABLE);
        //    continue;
        //}
        //if (i == RADIO_BUSY)
        //{
        //    am_hal_gpio_pinconfig(i, g_AM_HAL_GPIO_DISABLE);
        //    continue;
        //}
#endif

        //if(memcmp(&gpio[i], &AM_HAL_GPIO_NULL, sizeof(am_hal_gpio_pincfg_t)) != 0 ) // (Why are we disabling all pin???)
        //  am_hal_gpio_pinconfig(i, gpio[i]); 
    }

    return;
}
