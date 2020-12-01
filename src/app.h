/***************************************************************************//**
 * @file  app.h from Silabs soc-btmest-switch example code
 * @brief app header file
 *
 * @editor    Awesome Student, Awesome.Student@Colorado.edu
 * @date      Sep 15, 2020
 *
 * @institution University of Colorado Boulder (UCB)
 * @course      ECEN 5823-001: IoT Embedded Firmware (Fall 2020)
 * @instructor  David Sluiter
 *
 * @assignment ecen5823-assignment10-AwesomeStudent
 * @due        Sep 18, 2020
 *
 * @resources  Utilized Silicon Labs' BT mesh v1.7 library
 *
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#ifndef APP_H
#define APP_H

#include <gecko_configuration.h>

// DOS, added to enable #define to control whether a publisher or a subscriber
// is implemented.
#include <src/ble_mesh_device_type.h>

/* Bluetooth stack headers */
#include <src/gpio.h>
#include <src/node.h>
#include "native_gecko.h"
#include "gatt_db.h"
#include "mesh_proxy.h"
#include "lpn.h"

/* Timer definitions */
#include "app_timer.h"

#include "app.h"

//////////////////////////////////////////////////
#include "sleep.h"
#include "oscillators.h"
#include "timers.h"
#include "em_letimer.h"
//////////////////////////////////////////////////////


/* Coex header */
#include "coexistence-ble.h"

/* Display Interface header */
#include "display_interface.h"

/* Retarget serial headers */
#include "retargetserial.h"
#include <stdio.h>

///////////////////////////////////////////////////
/*#define LETIMER_PERIOD_MS 3000
#define LOWEST_ENERGY_MODE  3   // Options are 0 1 2 3


#if LOWEST_ENERGY_MODE == 0 || LOWEST_ENERGY_MODE == 1 || LOWEST_ENERGY_MODE == 2
	#define my_osc cmuOsc_LFXO              // Enabling LFXO for EM0, EM1, EM2 modes
	#define my_clock_select cmuSelect_LFXO
    #define my_clock_div    cmuClkDiv_4     // Clock divide by 4 for getting min time period ~7Sec
#elif LOWEST_ENERGY_MODE == 3
	#define my_osc cmuOsc_ULFRCO            // Enabling ULFRCO for EM3 mode
	#define my_clock_select cmuSelect_ULFRCO
    #define my_clock_div    cmuClkDiv_1     // For ULFRCO, no need of div
#endif
*/

////////////////////////////////////////////////////

/***************************************************************************//**
 * Main application code.
 * @param[in] pConfig  Pointer to stack configuration.
 ******************************************************************************/
void appMain(const gecko_configuration_t *pConfig);

int get_alarm_deactivate();



//uint32_t frequency;



#endif /* APP_H */
