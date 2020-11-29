/**************************************************************************************************
 * @file      oscillators.c
 * @version   0.4.0
 * @brief     oscillators.c Function Implementations to configure LFXO and ULFRCO oscillators
 *
 * @author    Atharv Desai, atharv.desai@Colorado.edu
 * @date      Sep 06, 2020
 *
 * @institution University of Colorado Boulder (UCB)
 * @course      ECEN 5823-001: IoT Embedded Firmware (Fall 2020)
 * @instructor  David Sluiter
 *
 * @assignment ecen5823-assignment4-atharvdesai1996
 * @due        Sep 25, 2020
 *
 * @resources : David Sluiter IoT Embedded Firmware Course slides
 *
 * @copyright  All rights reserved. Distribution allowed only for the use of assignment grading.
 *       Use of code excerpts allowed at the discretion of author. Contact for permission.
 */
#include "app.h"



/*  Function name: Osc_clock_select()
 *  Description:   Configure the Oscillator LXFO or ULFRCO based on Energy Modes EM0 to EM3
 *  Return type:   void (none)
 *  Arguments : none
 */
void Osc_clock_select()
{
	CMU_OscillatorEnable(my_osc, true, true);
	CMU_ClockSelectSet(cmuClock_LFA, my_clock_select);
	CMU_ClockEnable(cmuClock_LFA, true);
	CMU_ClockDivSet(cmuClock_LETIMER0,my_clock_div);
    frequency = CMU_ClockFreqGet(cmuClock_LETIMER0);
	CMU_ClockEnable(cmuClock_LETIMER0, true);
	led_calc();

}

/*  Function name: led_calc()
 *  Description:   Calculate the LED on and total time period
 *  Return type:   void (none)
 *  Arguments : none
 */
void led_calc()
{
	 led_period = frequency * LETIMER_PERIOD_MS *0.001;    // Computing the value for comp0 block
}






