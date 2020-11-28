/**************************************************************************************************
 * @file      timers.c
 * @version   0.4.0
 * @brief     timers.c Function Implementations to initialize timer, comp1 based timer
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
 * @resources :  David Sluiter IoT Embedded Firmware Course slides
 *               https://siliconlabs.github.io/Gecko_SDK_Doc/efr32bg1/html/group__CMU
 *               https://siliconlabs.github.io/Gecko_SDK_Doc/efr32bg1/html/structLETIMER__Init__TypeDef
 *               https://docs.silabs.com/mcu/latest/efr32mg13/group-SLEEP
 *               https://silabs-prod.adobecqms.net/community/mcu/32-bit/forum.topic.html/letimer_example_onefr32bg22-L0B1
 *               https://www.silabs.com/community/mcu/32-bit/forum.topic.html/em2_wakeup_from_gpio-kvEV
 *
 * @copyright  All rights reserved. Distribution allowed only for the use of assignment grading.
 *       Use of code excerpts allowed at the discretion of author. Contact for permission.
 */



#include "app.h"


/*  Function name: letimer_config()
 *  Description:   Configure the LETIMER0 structure and COMP! and COMP0 blocks
 *  Return type:   void (none)
 *  Arguments: none
 */
void letimer_config()
{
	// LETIMER Structure population
	const LETIMER_Init_TypeDef mytimer ={
	.enable = false,
	.debugRun =false,
	.bufTop = false,
	.comp0Top = true,
	.repMode = letimerRepeatFree,
	.ufoa0 = letimerUFOANone,
	.ufoa1 = letimerUFOANone,
	.topValue = 18432,
	.out0Pol = 0,
	.out1Pol = 0,
	};
	LETIMER_Init(LETIMER0, &mytimer);
	LETIMER_CompareSet(LETIMER0, 0,led_period);  // Comp0  register initialization
	LETIMER_IntEnable(LETIMER0,LETIMER_IEN_UF);  // Enable the LETIMER0 Interrupts Underflow
	NVIC_EnableIRQ(LETIMER0_IRQn);    			 // Enable LETIMER0 interrupt vector in NVIC
	LETIMER_Enable(LETIMER0, true);              // Enable LETIMER0
}

/*  Function name: mysleep()
 *  Description:   Configure the sleep block and initialize it
 *  Return type:   void (none)
 *  Arguments: none
 */

void mysleep()
{
	SLEEP_Init_t sleepConfigure = {0};              // Initialize the sleep data structure
	SLEEP_InitEx(&sleepConfigure);
	SLEEP_SleepBlockBegin(LOWEST_ENERGY_MODE + 1);  // To block all Energy modes lower than the LOWEST_ENERGY_MODE

}

/*  Function name: timerWaitUs()
 *  Description:   To implement Comp1 interrupt based timer in uS
 *  Return type:   void (none)
 *  Arguments: number to uS to be wait
 */

void timerWaitUs(uint32_t us_wait)
{
	float my_req_count = frequency * us_wait *0.000001;   // Required ticks for the time passed in argument
	uint16_t my_curr_count = (uint16_t)LETIMER_CounterGet(LETIMER0); // Getting current counter value in block
	uint16_t my_break_count;
	uint16_t rollover;
	uint16_t comp1_val = (uint16_t)LETIMER_CompareGet(LETIMER0, 0);  // Setting comp1 value

	if (my_req_count >= my_curr_count)                  // Rollover condition
	{
		rollover = my_req_count - my_curr_count;
		my_break_count = comp1_val - rollover;
	}
	else
	{
		my_break_count = my_curr_count - my_req_count;   // Normal condition
	}

	LETIMER_CompareSet(LETIMER0, 1, my_break_count);    // Comp1  register initialization
	LETIMER_IntEnable(LETIMER0,LETIMER_IEN_COMP1);      // Enable the LETIMER0 Interrupt COMP1

}


