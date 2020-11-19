/**************************************************************************************************
 * @file      i2c.h
 * @version   0.0.1
 * @brief     i2c function header file
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
 *         - I2C Library to initiate transfers and control state machine
 *
 * @copyright  All rights reserved. Distribution allowed only for the use of assignment grading.
 *       Use of code excerpts allowed at the discretion of author. Contact for permission.
 */

#ifndef SRC_I2C_H_
#define SRC_I2C_H_

#include "node.h"
#include "gpio.h"
#include "i2cspm.h"
#include "log.h"
#include "irq.h"

#define LOW_THRESHOLD 0x00
#define HIGH_THRESHOLD 0x80

#define SCL_PORT gpioPortC
#define SCL_PIN 10
#define SDA_PORT gpioPortC
#define SDA_PIN 11

I2C_TransferSeq_TypeDef transfer_seq;
uint8_t cmd;
uint8_t dat[2];
uint8_t cmd_and_dat[3];
uint32_t current_temp;

uint32_t i2c_step;  //variable indicating current i2c state machine state
uint32_t i2c_target;
I2C_TransferReturn_TypeDef i2c_ret_status; //variable to indicate what i2c_transfer returns

#define LIGHT_SLAVE_ADDR (0x48 << 1)
#define TEMP_SLAVE_ADDR (0x80) //7 bit address shifted over 1 bit
#define LPM_RAMP_TIME (80000) //80ms power on ramp time
#define TEMP_READ_CMD (0xF3) //no hold master mode temperature read

void i2c_init(void);  //initializes i2c operation. Parameters: None. Returns: None
void temp_power_on(); //turn on temperature sensor and wait for it to start up (80 ms).  Parameters: None. Returns: None
int temp_read(void); //initiates a temperature read. Returns 0 on success
void temp_power_off(); //turn off temperature sensor.  Parameters: None. Returns: None
double tempcode_to_degc(uint16_t tempcode); //converts tempcode returned by temperature sensor to degrees C. Takes in 16-bit tempcode, returns temp in degrees C as double-precision float

void log_i2c_error(I2C_TransferReturn_TypeDef retflag); //identify and log error

void light_write(uint16_t data, uint8_t command);  //writes data in to light sensor, using command code cmd
void light_read(uint8_t command);   //reads data from register identified by command from light sensor to light_read_data
void light_init(void); //initializes light sensor

uint16_t light_write_data;
uint16_t light_read_data;


#define CMD_ALS_CONF0 0x00
#define CMD_ALS_WH 	  0x01
#define CMD_ALS_WL	  0x2
#define CMD_PWR		  0x03
#define CMD_ALS_RD    0x04
#define CMD_WHITE_RD  0x05
#define CMD_ALS_INT   0x06

typedef enum I2C_Step{write_cmd, read_data, no_i2c_step}I2C_Step;
typedef enum I2C_Target{temp,light_read,light_write}I2C_Target;



#endif /* SRC_I2C_H_ */
