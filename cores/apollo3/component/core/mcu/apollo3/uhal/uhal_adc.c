#include "uhal_adc.h"

static void *(g_ADCHandle);
static am_hal_gpio_pincfg_t g_AM_PIN_ADC;

static am_hal_adc_config_t           ADCConfig;
static am_hal_adc_slot_config_t      ADCSlotConfig;

static UDRV_ADC_RESOLUTION        uhal_adc_resolution = UDRV_ADC_RESOLUTION_10BIT;
static UDRV_ADC_MODE              uhal_adc_mode       = UDRV_ADC_MODE_DEFAULT; // Edited by Sercan ERAT

volatile uint8_t is_adc_pin_active[5] = {0,0,0,0,0};

static uint32_t get_apollo_adc_pin(uint32_t pin) {
    switch (pin) {
        case 31:
            is_adc_pin_active[0] = true; 
            return AM_HAL_PIN_31_ADCSE3; // ADC3
        case 32:
            is_adc_pin_active[1] = true;  
            return AM_HAL_PIN_32_ADCSE4; // ADC4
        case 33:
            is_adc_pin_active[2] = true;  
            return AM_HAL_PIN_33_ADCSE5; // ADC5
        case 13:
            is_adc_pin_active[3] = true;  
            return AM_HAL_PIN_13_ADCD0PSE8; // ADC8
        case 12:
            is_adc_pin_active[4] = true;   
            return AM_HAL_PIN_12_ADCD0NSE9; // ADC9
        default: return 3; // AM_HAL_PIN_XX_GPIO
    }
}

static am_hal_adc_slot_chan_e get_apollo_slot_channel(uint32_t pin) {
    switch (pin) {
        case 31: return AM_HAL_ADC_SLOT_CHSEL_SE3; // ADC3
        case 32: return AM_HAL_ADC_SLOT_CHSEL_SE4; // ADC4
        case 33: return AM_HAL_ADC_SLOT_CHSEL_SE5; // ADC5
        case 13: return AM_HAL_ADC_SLOT_CHSEL_SE8; // ADC8
        case 12: return AM_HAL_ADC_SLOT_CHSEL_SE9; // ADC9
        default: return 0xFF; // AM_HAL_PIN_XX_GPIO
    }
}

void uhal_adc_set_resolution (UDRV_ADC_RESOLUTION resolution) {
    switch (resolution) {
        case UDRV_ADC_RESOLUTION_6BIT:
        case UDRV_ADC_RESOLUTION_8BIT:
        {
            uhal_adc_resolution = UDRV_ADC_RESOLUTION_8BIT;
            ADCSlotConfig.ePrecisionMode = AM_HAL_ADC_SLOT_8BIT;
            break;
        }
        case UDRV_ADC_RESOLUTION_10BIT:
        {
            uhal_adc_resolution = UDRV_ADC_RESOLUTION_10BIT;
            ADCSlotConfig.ePrecisionMode = AM_HAL_ADC_SLOT_10BIT;
            break;
        }
        case UDRV_ADC_RESOLUTION_12BIT:
        {
            uhal_adc_resolution = UDRV_ADC_RESOLUTION_12BIT;
            ADCSlotConfig.ePrecisionMode = AM_HAL_ADC_SLOT_12BIT;
            break;
        }
        case UDRV_ADC_RESOLUTION_14BIT:
        {
            uhal_adc_resolution = UDRV_ADC_RESOLUTION_14BIT;
            ADCSlotConfig.ePrecisionMode = AM_HAL_ADC_SLOT_14BIT;
            break;
        }
        default:
        {
            uhal_adc_resolution = UDRV_ADC_RESOLUTION_10BIT;
            ADCSlotConfig.ePrecisionMode = AM_HAL_ADC_SLOT_10BIT;
            break;
        }
    }
}

UDRV_ADC_RESOLUTION uhal_adc_get_resolution (void) {
    return uhal_adc_resolution;
}

void uhal_adc_set_mode (UDRV_ADC_MODE mode) {
    
    switch (mode) {
        case UDRV_ADC_MODE_1_5:
        {
            uhal_adc_mode = UDRV_ADC_MODE_1_5;
            ADCConfig.eReference = AM_HAL_ADC_REFSEL_INT_1P5;
            break;
        }
        case UDRV_ADC_MODE_DEFAULT:
        default:
        {
            uhal_adc_mode = UDRV_ADC_MODE_DEFAULT;
            ADCConfig.eReference = AM_HAL_ADC_REFSEL_INT_2P0;
            break;
        }
    }
}

UDRV_ADC_MODE uhal_adc_get_mode (void) {
    return uhal_adc_mode;
}

//*****************************************************************************
//
// Interrupt handler for the ADC.
//
//*****************************************************************************
static volatile bool wait_adc_int_flag = false;
am_hal_adc_sample_t Sample;
void am_adc_isr(void)
{
    #if CFG_SYSVIEW
    SEGGER_SYSVIEW_RecordEnterISR();
    #endif

    uint32_t            ui32IntMask;

    //
    // Read the interrupt status.
    //
    if (AM_HAL_STATUS_SUCCESS != am_hal_adc_interrupt_status(g_ADCHandle, &ui32IntMask, false))
    {
        //am_log_inf("Error reading ADC interrupt status\n");
    }

    //
    // Clear the ADC interrupt.
    //
    if (AM_HAL_STATUS_SUCCESS != am_hal_adc_interrupt_clear(g_ADCHandle, ui32IntMask))
    {
        //am_log_inf("Error clearing ADC interrupt status\n");
    }
    //
    // If we got a conversion completion interrupt (which should be our only
    // ADC interrupt), go ahead and read the data.
    //
    if (ui32IntMask & AM_HAL_ADC_INT_CNVCMP)
    {
        uint32_t ui32NumSamples = 1;
        if (AM_HAL_STATUS_SUCCESS != am_hal_adc_samples_read(g_ADCHandle, false,
                                                            NULL,
                                                            &ui32NumSamples,
                                                            &Sample))
        {
            //am_log_inf("Error - ADC sample read from FIFO failed.\n");
        }

        //#if (1 == ADC_EXAMPLE_DEBUG)
        am_log_inf("ADC Slot =  %d\n", Sample.ui32Slot);
        //am_log_inf("ADC Value = %8.8X\n", Sample.ui32Sample);
        am_log_inf("ADC Value = %d\n", Sample.ui32Sample);
        //#endif    
    }

    uhal_adc_suspend();
    wait_adc_int_flag = true; 

    #if CFG_SYSVIEW
    SEGGER_SYSVIEW_RecordExitISR();
    #endif
}

int32_t uhal_adc_read (uint32_t pin, int16_t *value) {

    uint32_t _uFuncSel = get_apollo_adc_pin(pin);

    if(_uFuncSel == 3)
        return UDRV_WRONG_ARG;
    
    //
    // Set a pin to act as our ADC input
    //
    g_AM_PIN_ADC.uFuncSel = _uFuncSel;
    am_hal_gpio_pinconfig(pin, g_AM_PIN_ADC);

    uint32_t slot_number = 0;

    //
    // Initialize the ADC and get the handle.
    //
    if ( AM_HAL_STATUS_SUCCESS != am_hal_adc_initialize(slot_number, &g_ADCHandle) )
    {
        //am_log_inf("Error - reservation of the ADC instance failed.\n");
    }

    //
    // Power on the ADC.
    //
    if (AM_HAL_STATUS_SUCCESS != am_hal_adc_power_control(g_ADCHandle,
                                                        AM_HAL_SYSCTRL_WAKE,
                                                        false) )
    {
        //am_log_inf("Error - ADC power on failed.\n");
    }

    uhal_adc_set_mode(uhal_adc_mode);

    //
    // Set up the ADC configuration parameters. These settings are reasonable
    // for accurate measurements at a low sample rate.
    //
    ADCConfig.eClock             = AM_HAL_ADC_CLKSEL_HFRC;
    ADCConfig.ePolarity          = AM_HAL_ADC_TRIGPOL_RISING;
    ADCConfig.eTrigger           = AM_HAL_ADC_TRIGSEL_SOFTWARE;
    ADCConfig.eClockMode         = AM_HAL_ADC_CLKMODE_LOW_POWER;
    ADCConfig.ePowerMode         = AM_HAL_ADC_LPMODE0;
    ADCConfig.eRepeat            = AM_HAL_ADC_REPEATING_SCAN;
    if (AM_HAL_STATUS_SUCCESS != am_hal_adc_configure(g_ADCHandle, &ADCConfig))
    {
        //am_log_inf("Error - configuring ADC failed.\n");
    }

    uhal_adc_set_resolution(uhal_adc_resolution);

    //
    // Set up an ADC slot
    //
    ADCSlotConfig.eMeasToAvg      = AM_HAL_ADC_SLOT_AVG_1;
    ADCSlotConfig.eChannel        = get_apollo_slot_channel(pin);
    ADCSlotConfig.bWindowCompare  = false;
    ADCSlotConfig.bEnabled        = true;
    if (AM_HAL_STATUS_SUCCESS != am_hal_adc_configure_slot(g_ADCHandle, slot_number, &ADCSlotConfig))
    {
        //am_log_inf("Error - configuring ADC Slot 0 failed.\n");
    }

    //
    // Enable interrupts.
    //
    NVIC_EnableIRQ(ADC_IRQn);
    
    //
    // For this example, the samples will be coming in slowly. This means we
    // can afford to wake up for every conversion.
    //
    am_hal_adc_interrupt_enable(g_ADCHandle, AM_HAL_ADC_INT_CNVCMP );

    //
    // Enable the ADC.
    //
    if (AM_HAL_STATUS_SUCCESS != am_hal_adc_enable(g_ADCHandle))
    {
        //am_log_inf("Error - enabling ADC failed.\n");
    }

    // Trigger the ADC
    //
    wait_adc_int_flag = false;
    am_hal_adc_sw_trigger(g_ADCHandle);
    while(wait_adc_int_flag == false); // Wait to complete ADC measurement!!!!

    //if(slot_number != Sample.ui32Slot)
    //    return UDRV_WRONG_ARG;

    uint32_t result = Sample.ui32Sample;
    *value = (int16_t) result;

    uhal_adc_suspend();

    return UDRV_RETURN_OK;
}

void uhal_adc_suspend (void) {
    //
    // Disable the ADC.
    //
    if (AM_HAL_STATUS_SUCCESS != am_hal_adc_disable(g_ADCHandle))
    {
        //am_log_inf("Error - disable ADC failed.\n");
    }

    //
    // Enable the ADC power domain.
    //
    if (AM_HAL_STATUS_SUCCESS != am_hal_pwrctrl_periph_disable(AM_HAL_PWRCTRL_PERIPH_ADC))
    {
        //am_log_inf("Error - disabling the ADC power domain failed.\n");
    }

    if(is_adc_pin_active[0] == true)
    {
        is_adc_pin_active[0] = false;
        am_hal_gpio_pinconfig(31, g_AM_HAL_GPIO_DISABLE);
    }
    if(is_adc_pin_active[1] == true)
    {
        is_adc_pin_active[1] = false;
        am_hal_gpio_pinconfig(32, g_AM_HAL_GPIO_DISABLE);
    }
    if(is_adc_pin_active[2] == true)
    {
        is_adc_pin_active[2] = false;
        am_hal_gpio_pinconfig(33, g_AM_HAL_GPIO_DISABLE);
    }
    if(is_adc_pin_active[3] == true)
    {
        is_adc_pin_active[3] = false;
        am_hal_gpio_pinconfig(13, g_AM_HAL_GPIO_DISABLE);
    }
    if(is_adc_pin_active[4] == true)
    {
        is_adc_pin_active[4] = false;
        am_hal_gpio_pinconfig(12, g_AM_HAL_GPIO_DISABLE);
    }

    //
    // Initialize the ADC and get the handle.
    //
    if (AM_HAL_STATUS_SUCCESS != am_hal_adc_deinitialize(g_ADCHandle))
    {
        //am_log_inf("Error - return of the ADC instance failed.\n");
    }

    // Disable interrupts.
    NVIC_DisableIRQ(ADC_IRQn);
}

void uhal_adc_resume (void) {
}

void uhal_adc_oversampling(uint32_t oversampling)
{
	switch (oversampling) {
		case 0:
		case 1:
			ADCSlotConfig.eMeasToAvg = AM_HAL_ADC_SLOT_AVG_1;
			return;
			break;
		case 2:
			ADCSlotConfig.eMeasToAvg = AM_HAL_ADC_SLOT_AVG_2;
			break;
		case 4:
			ADCSlotConfig.eMeasToAvg = AM_HAL_ADC_SLOT_AVG_4;
			break;
		case 8:
			ADCSlotConfig.eMeasToAvg = AM_HAL_ADC_SLOT_AVG_8;
			break;
		case 16:
			ADCSlotConfig.eMeasToAvg = AM_HAL_ADC_SLOT_AVG_16;
			break;
		case 32:
			ADCSlotConfig.eMeasToAvg = AM_HAL_ADC_SLOT_AVG_32;
			break;
		case 64:
			ADCSlotConfig.eMeasToAvg = AM_HAL_ADC_SLOT_AVG_64;
			break;
		case 128:
			ADCSlotConfig.eMeasToAvg = AM_HAL_ADC_SLOT_AVG_128;
			break;
		case 256:
			ADCSlotConfig.eMeasToAvg = AM_HAL_ADC_SLOT_AVG_128;
			break;
	}
}
