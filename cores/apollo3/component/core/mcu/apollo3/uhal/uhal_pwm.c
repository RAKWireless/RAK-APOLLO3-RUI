#include "uhal_pwm.h"
#include "uhal_timer.h"
#include "udrv_pwm.h"
#include "udrv_errno.h"

//*****************************************************************************
//
//  Tables copied from am_hal_ctimer.c because they are declared as static within
//  that file, but they would be useful here too.
//
//  Lookup tables used by am_hal_ctimer_output_config().
//
//  CTx_tbl[] relates the padnum and pad funcsel based on a given CTx.
//  Valid pads for CTx are: 4-7, 11-13, 18-19, 22-33, 35, 37, 39, 42-49.
//
//  outcfg_tbl[] contains attributes of the 4 output signal types for each
//  of the 32 CTx signals. Therefore it is indexed by CTnumber 0-31.
//  This table provides only the non-common OUTCFG attributes (2-5, other
//  settings are shown below).
//  OUTCFG 0 = Force output to 0.
//  OUTCFG 1 = Force output to 1.
//  OUTCFG 6 = A6OUT2.
//  OUTCFG 7 = A7OUT2.
//
//*****************************************************************************
#define CTXPADNUM(ctx) ((CTx_tbl[ctx] >> 0) & 0x3f)
#define CTXPADFNC(ctx) ((CTx_tbl[ctx] >> 8) & 0x7)
#define CTX(pad, fn) ((fn << 8) | (pad << 0))
static const uint16_t CTx_tbl[32] =
    {
        CTX(12, 2), CTX(25, 2), CTX(13, 2), CTX(26, 2), CTX(18, 2), // 0 - 4
        CTX(27, 2), CTX(19, 2), CTX(28, 2), CTX(5, 7), CTX(29, 2),  // 5 - 9
        CTX(6, 5), CTX(30, 2), CTX(22, 2), CTX(31, 2), CTX(23, 2),  // 10 - 14
        CTX(32, 2), CTX(42, 2), CTX(4, 6), CTX(43, 2), CTX(7, 7),   // 15 - 19
        CTX(44, 2), CTX(24, 5), CTX(45, 2), CTX(33, 6), CTX(46, 2), // 20 - 24
        CTX(39, 2), CTX(47, 2), CTX(35, 5), CTX(48, 2), CTX(37, 7), // 25 - 29
        CTX(49, 2), CTX(11, 2)                                      // 30 - 31
};

#define OUTC(timB, timN, N2) ((N2 << 4) | (timB << 3) | (timN << 0))
#define OUTCTIMN(ctx, n) (outcfg_tbl[ctx][n] & (0x7 << 0))
#define OUTCTIMB(ctx, n) (outcfg_tbl[ctx][n] & (0x1 << 3))
#define OUTCO2(ctx, n) (outcfg_tbl[ctx][n] & (0x1 << 4))
static const uint8_t outcfg_tbl[32][4] =
    {
        {OUTC(0, 0, 0), OUTC(1, 2, 1), OUTC(0, 5, 1), OUTC(0, 6, 0)}, // CTX0:  A0OUT,  B2OUT2, A5OUT2, A6OUT
        {OUTC(0, 0, 1), OUTC(0, 0, 0), OUTC(0, 5, 0), OUTC(1, 7, 1)}, // CTX1:  A0OUT2, A0OUT,  A5OUT,  B7OUT2
        {OUTC(1, 0, 0), OUTC(1, 1, 1), OUTC(1, 6, 1), OUTC(0, 7, 0)}, // CTX2:  B0OUT,  B1OUT2, B6OUT2, A7OUT
        {OUTC(1, 0, 1), OUTC(1, 0, 0), OUTC(0, 1, 0), OUTC(0, 6, 0)}, // CTX3:  B0OUT2, B0OUT,  A1OUT,  A6OUT
        {OUTC(0, 1, 0), OUTC(0, 2, 1), OUTC(0, 5, 1), OUTC(1, 5, 0)}, // CTX4:  A1OUT,  A2OUT2, A5OUT2, B5OUT
        {OUTC(0, 1, 1), OUTC(0, 1, 0), OUTC(1, 6, 0), OUTC(0, 7, 0)}, // CTX5:  A1OUT2, A1OUT,  B6OUT,  A7OUT
        {OUTC(1, 1, 0), OUTC(0, 1, 0), OUTC(1, 5, 1), OUTC(1, 7, 0)}, // CTX6:  B1OUT,  A1OUT,  B5OUT2, B7OUT
        {OUTC(1, 1, 1), OUTC(1, 1, 0), OUTC(1, 5, 0), OUTC(0, 7, 0)}, // CTX7:  B1OUT2, B1OUT,  B5OUT,  A7OUT
        {OUTC(0, 2, 0), OUTC(0, 3, 1), OUTC(0, 4, 1), OUTC(1, 6, 0)}, // CTX8:  A2OUT,  A3OUT2, A4OUT2, B6OUT
        {OUTC(0, 2, 1), OUTC(0, 2, 0), OUTC(0, 4, 0), OUTC(1, 0, 0)}, // CTX9:  A2OUT2, A2OUT,  A4OUT,  B0OUT
        {OUTC(1, 2, 0), OUTC(1, 3, 1), OUTC(1, 4, 1), OUTC(0, 6, 0)}, // CTX10: B2OUT,  B3OUT2, B4OUT2, A6OUT
        {OUTC(1, 2, 1), OUTC(1, 2, 0), OUTC(1, 4, 0), OUTC(1, 5, 1)}, // CTX11: B2OUT2, B2OUT,  B4OUT,  B5OUT2
        {OUTC(0, 3, 0), OUTC(1, 1, 0), OUTC(1, 0, 1), OUTC(1, 6, 1)}, // CTX12: A3OUT,  B1OUT,  B0OUT2, B6OUT2
        {OUTC(0, 3, 1), OUTC(0, 3, 0), OUTC(0, 6, 0), OUTC(1, 4, 1)}, // CTX13: A3OUT2, A3OUT,  A6OUT,  B4OUT2
        {OUTC(1, 3, 0), OUTC(1, 1, 0), OUTC(1, 7, 1), OUTC(0, 7, 0)}, // CTX14: B3OUT,  B1OUT,  B7OUT2, A7OUT
        {OUTC(1, 3, 1), OUTC(1, 3, 0), OUTC(0, 7, 0), OUTC(0, 4, 1)}, // CTX15: B3OUT2, B3OUT,  A7OUT,  A4OUT2
        {OUTC(0, 4, 0), OUTC(0, 0, 0), OUTC(0, 0, 1), OUTC(1, 3, 1)}, // CTX16: A4OUT,  A0OUT,  A0OUT2, B3OUT2
        {OUTC(0, 4, 1), OUTC(1, 7, 0), OUTC(0, 4, 0), OUTC(0, 1, 1)}, // CTX17: A4OUT2, B7OUT,  A4OUT,  A1OUT2
        {OUTC(1, 4, 0), OUTC(1, 0, 0), OUTC(0, 0, 0), OUTC(0, 3, 1)}, // CTX18: B4OUT,  B0OUT,  A0OUT,  A3OUT2
        {OUTC(1, 4, 1), OUTC(0, 2, 0), OUTC(1, 4, 0), OUTC(1, 1, 1)}, // CTX19: B4OUT2, A2OUT,  B4OUT,  B1OUT2
        {OUTC(0, 5, 0), OUTC(0, 1, 0), OUTC(0, 1, 1), OUTC(1, 2, 1)}, // CTX20: A5OUT,  A1OUT,  A1OUT2, B2OUT2
        {OUTC(0, 5, 1), OUTC(0, 1, 0), OUTC(1, 5, 0), OUTC(0, 0, 1)}, // CTX21: A5OUT2, A1OUT,  B5OUT,  A0OUT2
        {OUTC(1, 5, 0), OUTC(0, 6, 0), OUTC(0, 1, 0), OUTC(0, 2, 1)}, // CTX22: B5OUT,  A6OUT,  A1OUT,  A2OUT2
        {OUTC(1, 5, 1), OUTC(0, 7, 0), OUTC(0, 5, 0), OUTC(1, 0, 1)}, // CTX23: B5OUT2, A7OUT,  A5OUT,  B0OUT2
        {OUTC(0, 6, 0), OUTC(0, 2, 0), OUTC(0, 1, 0), OUTC(1, 1, 1)}, // CTX24: A6OUT,  A2OUT,  A1OUT,  B1OUT2
        {OUTC(1, 4, 1), OUTC(1, 2, 0), OUTC(0, 6, 0), OUTC(0, 2, 1)}, // CTX25: B4OUT2, B2OUT,  A6OUT,  A2OUT2
        {OUTC(1, 6, 0), OUTC(1, 2, 0), OUTC(0, 5, 0), OUTC(0, 1, 1)}, // CTX26: B6OUT,  B2OUT,  A5OUT,  A1OUT2
        {OUTC(1, 6, 1), OUTC(0, 1, 0), OUTC(1, 6, 0), OUTC(1, 2, 1)}, // CTX27: B6OUT2, A1OUT,  B6OUT,  B2OUT2
        {OUTC(0, 7, 0), OUTC(0, 3, 0), OUTC(0, 5, 1), OUTC(1, 0, 1)}, // CTX28: A7OUT,  A3OUT,  A5OUT2, B0OUT2
        {OUTC(1, 5, 1), OUTC(0, 1, 0), OUTC(0, 7, 0), OUTC(0, 3, 1)}, // CTX29: B5OUT2, A1OUT,  A7OUT,  A3OUT2
        {OUTC(1, 7, 0), OUTC(1, 3, 0), OUTC(0, 4, 1), OUTC(0, 0, 1)}, // CTX30: B7OUT,  B3OUT,  A4OUT2, A0OUT2
        {OUTC(1, 7, 1), OUTC(0, 6, 0), OUTC(1, 7, 0), OUTC(1, 3, 1)}, // CTX31: B7OUT2, A6OUT,  B7OUT,  B3OUT2
};


#define CLK AM_HAL_CTIMER_HFRC_12MHZ // Use an Ambiq HAL provided value to select which clock

static TimerHandle_t uhal_pwm_timer_id;  /**< Definition of timer. */

typedef struct uhal_pwm_status {
    bool initialized;
    bool enabled;
    uint32_t freq_hz;
    uint8_t is_invert;
    uint32_t pin;
    uint32_t duty;
} uhal_pwm_status_t;


static uhal_pwm_status_t pwm_status[UDRV_PWM_MAX];

static UDRV_PWM_RESOLUTION pwm_resolution = UDRV_PWM_RESOLUTION_8BIT;

static volatile bool ready_flag[UDRV_PWM_MAX];            // A flag indicating PWM status.

static inline bool isInISR(void)
{
  return (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0 ;
}

UDRV_PWM_RESOLUTION uhal_pwm_get_resolution (void) {
    return pwm_resolution;
}

void uhal_pwm_set_resolution (UDRV_PWM_RESOLUTION resolution) {
    if (resolution > UDRV_PWM_RESOLUTION_14BIT) {
        return;
    }
    pwm_resolution = resolution;
}

static void pwm_init(udrv_pwm_port port, uint32_t freq_hz, uint8_t is_invert, uint32_t pin) {    
    uint8_t ctx = 0;
    for (ctx = 0; ctx < 32; ctx++)
    {
        if (CTXPADNUM(ctx) == pin)
        {
            break;
        }
    }
    if (ctx >= 32)
    {
        return; // could not find pad in CTx table
    }
   
    // Use the 0th index of the outcfg_tbl to select the functions
    uint32_t timer = OUTCTIMN(ctx, 0);
    uint32_t segment = AM_HAL_CTIMER_TIMERA;
    if (OUTCTIMB(ctx, 0))
    {
        segment = AM_HAL_CTIMER_TIMERB;
    }

    //
    // Among other things, am_bsp_low_power_init() stops the XT oscillator,
    // which is needed for this example.
    //
    am_hal_clkgen_control(AM_HAL_CLKGEN_CONTROL_XTAL_START, 0);

    // clear timer (also stops the timer)
    am_hal_ctimer_clear(timer, segment);
}

void uhal_pwm_init(udrv_pwm_port port, uint32_t freq_hz, uint8_t is_invert, uint32_t pin) {
    if (port >= UDRV_PWM_MAX) {
        return;
    }

    pwm_init(port, freq_hz, is_invert, pin);

    pwm_status[port].initialized = true;
    pwm_status[port].freq_hz = freq_hz;
    pwm_status[port].is_invert = is_invert;
    pwm_status[port].pin = pin;
}

int32_t uhal_pwm_set_duty(udrv_pwm_port port, uint32_t duty) {

    uint32_t period_in_us = (uint32_t) (12000000/pwm_status[port].freq_hz);

    if (period_in_us > 0x0000FFFF)
    {
        return -UDRV_WRONG_ARG;
    }
    if (period_in_us < 3)
    {
        return -UDRV_WRONG_ARG;
    }

    uint32_t ontime = 0;

    switch (pwm_resolution) {
        case UDRV_PWM_RESOLUTION_8BIT:
            if (duty > 255) {
                return -UDRV_WRONG_ARG;
	    } else {
                duty = duty*100/255;
                ontime = (uint32_t)((duty * period_in_us) / ((0x01 << 8) - 1));
	    }
            break;
        case UDRV_PWM_RESOLUTION_10BIT:
            if (duty > 1023) {
                return -UDRV_WRONG_ARG;
	    } else {
                duty = duty*100/1023;
                ontime = (uint32_t)((duty * period_in_us) / ((0x01 << 10) - 1));
	    }
            break;
        case UDRV_PWM_RESOLUTION_12BIT:
            if (duty > 4095) {
                return -UDRV_WRONG_ARG;
	    } else {
                duty = duty*100/4095;
                ontime = (uint32_t)((duty * period_in_us) / ((0x01 << 12) - 1));
	    }
            break;
        case UDRV_PWM_RESOLUTION_14BIT:
            if (duty > 16383) {
                return -UDRV_WRONG_ARG;
	    } else {
                duty = duty*100/16383;
                ontime = (uint32_t)((duty * period_in_us) / ((0x01 << 14) - 1));
	    }
            break;
        default:
	    return -UDRV_INTERNAL_ERR;
    }

    uint8_t ctx = 0;
    for (ctx = 0; ctx < 32; ctx++)
    {
        if (CTXPADNUM(ctx) == pwm_status[port].pin)
        {
            break;
        }
    }
    if (ctx >= 32)
    {
        return -UDRV_INTERNAL_ERR; // could not find pad in CTx table
    }
   
    // Use the 0th index of the outcfg_tbl to select the functions
    uint32_t timer = OUTCTIMN(ctx, 0);
    uint32_t segment = AM_HAL_CTIMER_TIMERA;
    if (OUTCTIMB(ctx, 0))
    {
        segment = AM_HAL_CTIMER_TIMERB;
    }

    bool set_periods = true;
    uint32_t output = AM_HAL_CTIMER_OUTPUT_NORMAL;

    if ((ontime == 0) || (period_in_us == 0))
    {
        //if(pwm_status[port].is_invert == 0)
          output = AM_HAL_CTIMER_OUTPUT_FORCE0;
        //else
        //  output = AM_HAL_CTIMER_OUTPUT_FORCE1;

        set_periods = false; // disable setting periods when going into a forced mode
    }
    else if (ontime == period_in_us)
    {
        //if(pwm_status[port].is_invert == 0)
          output = AM_HAL_CTIMER_OUTPUT_FORCE1;
        //else
        //  output = AM_HAL_CTIMER_OUTPUT_FORCE0;

        set_periods = false; // disable setting periods when going into a forced mode
    }

    // Configure the pin
    am_hal_ctimer_output_config(timer,
                                segment,
                                pwm_status[port].pin,
                                output,
                                AM_HAL_GPIO_PIN_DRIVESTRENGTH_12MA); //

    //
    // Configure a timer to drive the LED.
    //
    am_hal_ctimer_config_single(timer,
                                segment,
                                (AM_HAL_CTIMER_FN_PWM_REPEAT | CLK) );

    if (set_periods)
    {   
        am_hal_ctimer_period_set(timer, segment, period_in_us, ontime);
        am_hal_ctimer_aux_period_set(timer, segment, period_in_us, ontime);
    
        am_hal_ctimer_start(timer, segment);
    }

    // I found this function at Sparkfun's Apollo3 Core
    // if timer is running and wait for timer value to roll over 
    //(will indicate that at least one pulse has been emitted)
    AM_CRITICAL_BEGIN // critical section when reading / writing config registers
    if ((segment == AM_HAL_CTIMER_TIMERA && *((uint32_t *)CTIMERADDRn(CTIMER, timer, CTRL0)) & (CTIMER_CTRL0_TMRA0EN_Msk)) ||
        (segment == AM_HAL_CTIMER_TIMERB && *((uint32_t *)CTIMERADDRn(CTIMER, timer, CTRL0)) & (CTIMER_CTRL0_TMRB0EN_Msk)))
    {
        uint32_t current = 0;
        uint32_t last = 0;
        do
        {
            last = current;
            current = am_hal_ctimer_read(timer, segment);
        } while (current >= last);
    }
    AM_CRITICAL_END // end critical section
    //--------------------------------------------------
    
    return UDRV_RETURN_OK;
}

static void pwm_deinit(udrv_pwm_port port) {

    uint8_t ctx = 0;
    for (ctx = 0; ctx < 32; ctx++)
    {
        if (CTXPADNUM(ctx) == pwm_status[port].pin)
        {
            break;
        }
    }
    if (ctx >= 32)
    {
        return; // could not find pad in CTx table
    }
   
    // Use the 0th index of the outcfg_tbl to select the functions
    uint32_t timer = OUTCTIMN(ctx, 0);
    uint32_t segment = AM_HAL_CTIMER_TIMERA;
    if (OUTCTIMB(ctx, 0))
    {
        segment = AM_HAL_CTIMER_TIMERB;
    }

    // clear timer (also stops the timer)
    am_hal_ctimer_clear(timer, segment);

    // Disable the PWM pins.
    am_hal_gpio_pinconfig(pwm_status[port].pin, g_AM_HAL_GPIO_DISABLE);
}

void uhal_pwm_deinit(udrv_pwm_port port) {
    if (port >= UDRV_PWM_MAX) {
        return;
    }

    pwm_deinit(port);

    pwm_status[port].initialized = false;
}

static void pwm_enable(udrv_pwm_port port) {

}

void uhal_pwm_enable(udrv_pwm_port port) {
    if (port >= UDRV_PWM_MAX) {
        return;
    }

    pwm_enable(port);
    pwm_status[port].enabled = true;
}

static void pwm_disable(udrv_pwm_port port) {
    uint8_t ctx = 0;
    for (ctx = 0; ctx < 32; ctx++)
    {
        if (CTXPADNUM(ctx) == pwm_status[port].pin)
        {
            break;
        }
    }
    if (ctx >= 32)
    {
        return; // could not find pad in CTx table
    }
   
    // Use the 0th index of the outcfg_tbl to select the functions
    uint32_t timer = OUTCTIMN(ctx, 0);
    uint32_t segment = AM_HAL_CTIMER_TIMERA;
    if (OUTCTIMB(ctx, 0))
    {
        segment = AM_HAL_CTIMER_TIMERB;
    }

    // Configure the pin
    am_hal_ctimer_output_config(timer,
                                segment,
                                pwm_status[port].pin,
                                AM_HAL_CTIMER_OUTPUT_FORCE0,
                                AM_HAL_GPIO_PIN_DRIVESTRENGTH_12MA); //

    // clear timer (also stops the timer)
    am_hal_ctimer_clear(timer, segment);
}

void uhal_pwm_disable(udrv_pwm_port port) {
    if (port >= UDRV_PWM_MAX) {
        return;
    }

    pwm_disable(port);
    pwm_status[port].enabled = false;
}

void uhal_pwm_suspend(void) {
    for (int i = UDRV_PWM_0 ; i < UDRV_PWM_MAX ; i++) {
        
        if (pwm_status[i].enabled == true) {
            pwm_disable(i);
	    }

        if (pwm_status[i].initialized == true) {
            pwm_deinit(i);
	    }
    }
}

void uhal_pwm_resume(void) {
    for (int i = UDRV_PWM_0 ; i < UDRV_PWM_MAX ; i++) {
        if (pwm_status[i].initialized == true) {
            pwm_init(i, pwm_status[i].freq_hz, pwm_status[i].is_invert, pwm_status[i].pin);
	    }
        if (pwm_status[i].enabled == true) {
	        pwm_enable(i);
	        uhal_pwm_set_duty(i, pwm_status[i].duty);
	    }
    }
}

static timer_handler pwm_tmr_handler = NULL;
static void *p_context = NULL;
static void pwm_timer_timeout_handler(TimerHandle_t xTimer)
{
  pwm_tmr_handler(p_context);
}

int32_t uhal_pwm_timer_create (timer_handler tmr_handler, TimerMode_E mode) {

    if(uhal_pwm_timer_id == NULL)
    {
        uhal_pwm_timer_id = xTimerCreate("PWM_TMR",
                                1,
                                get_apollo_timer_mode(mode),
                                NULL,
                                pwm_timer_timeout_handler);
    }

    pwm_tmr_handler = tmr_handler;

    if (uhal_pwm_timer_id != NULL) {
        return UDRV_RETURN_OK;
    } else {
        return -UDRV_INTERNAL_ERR;
    }
}

int32_t uhal_pwm_timer_start (uint32_t count, void *m_data) {

    if(uhal_pwm_timer_id == NULL)
    {
        return -UDRV_INTERNAL_ERR;
    }

    if(count == 0)
        return -UDRV_INTERNAL_ERR;
        
    p_context = m_data;

    if( isInISR() ) 
    {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        if(pdPASS != xTimerStopFromISR(uhal_pwm_timer_id, xHigherPriorityTaskWoken))
        {
            return -UDRV_INTERNAL_ERR;
        }

        if(xHigherPriorityTaskWoken != pdFALSE)
        {
            portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }

        if(pdPASS != xTimerChangePeriodFromISR(uhal_pwm_timer_id,
                        (uint32_t) (count*1.024f), // This is not correct solution! FIX ME!
                        &xHigherPriorityTaskWoken ))
        {
            return -UDRV_INTERNAL_ERR;
        }

        if(xHigherPriorityTaskWoken != pdFALSE)
        {
            portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }

        if(pdPASS != xTimerStartFromISR(uhal_pwm_timer_id, &xHigherPriorityTaskWoken))
        {
            return -UDRV_INTERNAL_ERR;
        }

        if(xHigherPriorityTaskWoken != pdFALSE)
        {
            portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }
    } 
    else
    {
        if(pdPASS != xTimerStop(uhal_pwm_timer_id, OSTIMER_WAIT_FOR_QUEUE))
        {
            return -UDRV_INTERNAL_ERR;
        }

        if(pdPASS != xTimerChangePeriod( uhal_pwm_timer_id,
                        (uint32_t) (count*1.024f), // This is not correct solution! FIX ME!
                        OSTIMER_WAIT_FOR_QUEUE ))
        {
            return -UDRV_INTERNAL_ERR;
        }

        // Start application timers.
        if (pdPASS != xTimerStart(uhal_pwm_timer_id, OSTIMER_WAIT_FOR_QUEUE))
        {
            return -UDRV_INTERNAL_ERR;
        }
    }

    return UDRV_RETURN_OK;
}

int32_t uhal_pwm_timer_stop (void) {
    
    if(uhal_pwm_timer_id == NULL)
    {
        return -UDRV_INTERNAL_ERR;
    }

    if( isInISR() ) 
    {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        if(pdPASS != xTimerStopFromISR(uhal_pwm_timer_id, xHigherPriorityTaskWoken))
        {
            return -UDRV_INTERNAL_ERR;
        }

        if(xHigherPriorityTaskWoken != pdFALSE)
        {
            portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }

    } 
    else
    {
        if(pdPASS != xTimerStop(uhal_pwm_timer_id, OSTIMER_WAIT_FOR_QUEUE))
        {
            return -UDRV_INTERNAL_ERR;
        }
    }

    return UDRV_RETURN_OK;
}
