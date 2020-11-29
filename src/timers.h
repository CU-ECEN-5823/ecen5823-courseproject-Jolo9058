/**************************************************************************************************
 * @file      timers.h
 * @version   0.4.0
 * @brief     timers.h Function Declarations
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

#ifndef SRC_TIMERS_H_
#define SRC_TIMERS_H_

//Function Declarations
void letimer_config();
void mysleep();
void timerWaitUs(uint32_t us_wait);
uint32_t led_period;     // Count variables declaration

#endif /* SRC_TIMERS_H_ */
