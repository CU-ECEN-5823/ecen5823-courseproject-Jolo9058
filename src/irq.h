/**************************************************************************************************
 * @file      irq.h
 * @version   0.0.1
 * @brief     interrupt handler header file
 *
 * @author    Joe Lopez, jolo9058@colorado.edu
 * @date      Sep 6, 2020
 *
 * @institution University of Colorado Boulder (UCB)
 * @course      ECEN 5823-001: IoT Embedded Firmware (Fall 2020)
 * @instructor  David Sluiter
 *
 * @assignment ecen5823-assignment4-jolo9058
 * @due        Sep 25, 2020
 *
 * @resources  Utilized Silicon Labs' EMLIB peripheral libraries to implement functionality.
 *
 *
 * @copyright  All rights reserved. Distribution allowed only for the use of assignment grading.
 *       Use of code excerpts allowed at the discretion of author. Contact for permission.
 */
#ifndef SRC_IRQ_H_
#define SRC_IRQ_H_

#include "gecko_configuration.h"
#include "gpio.h"
#include "native_gecko.h"
#include "sleep.h"
#include "em_core.h"
#include "i2cspm.h"
#include "native_gecko.h"
#include "bg_types.h"
#include "gatt_db.h"
#include "display.h"


#include "log.h"

void I2C0_IRQHandler(void); //interrupt handler for I2C0

#endif /* SRC_IRQ_H_ */
