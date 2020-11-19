/**************************************************************************************************
 * @file      schedule.h
 * @version   0.0.1
 * @brief     scheduler header file
 *
 * @author    Joe Lopez, jolo9058@colorado.edu
 * @date      Sep 28, 2020
 *
 * @institution University of Colorado Boulder (UCB)
 * @course      ECEN 5823-001: IoT Embedded Firmware (Fall 2020)
 * @instructor  David Sluiter
 *
 * @assignment ecen5823-assignment5-jolo9058
 * @due        Oct 2, 2020
 *
 * @resources  Utilized Silicon Labs' EMLIB peripheral libraries to implement functionality.
 *         -
 *
 * @copyright  All rights reserved. Distribution allowed only for the use of assignment grading.
 *       Use of code excerpts allowed at the discretion of author. Contact for permission.
 */


#ifndef SRC_SCHEDULE_H_
#define SRC_SCHEDULE_H_

#include "node.h"
#include "display.h"
#include "i2c.h"

void state_machine(struct gecko_cmd_packet* evt); //takes a bluetooth low energy external event and handles it appropriately

void event_letimer_comp0(void); //handle letimer comp0 firing by beginning lpm sequence
void event_letimer_comp1(void); //handle letimer comp0
void event_i2c(void); //handle i2c interrupt by advancing i2c state machine
void event_gpio_pb0(void); //handle GPIO interrupt (pushbutton 0 pressed/released)
void event_gpio_pb1(void); //handle GPIO interrupt (pushbutton1  pressed)

typedef enum event{LETIMER_COMP0 = 0b1, LETIMER_COMP1 = 0b10, I2C_SCHEDULE = 0b100, PB0_SCHEDULE = 0b1000, PB1_SCHEDULE = 0b10000}event;  //used in schedule variable to indicate that event occured

#endif /* SRC_SCHEDULE_H_ */
