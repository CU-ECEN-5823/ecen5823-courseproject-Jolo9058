/**************************************************************************************************
 * @file      i2c.c
 * @version   0.0.1
 * @brief     i2c implementation file
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
#include "i2c.h"
void log_i2c_error(I2C_TransferReturn_TypeDef retflag){
	LOG_ERROR("Error encountered during command transfer.");
	switch(retflag){
		case i2cTransferInProgress:
			LOG_ERROR("Returned i2cTransferInProgress");
			break;
		case i2cTransferNack:
			LOG_ERROR("Returned i2cTransferNack");
			break;
		case i2cTransferBusErr:
			LOG_ERROR("Returned i2cTransferBusError");
			break;
		case i2cTransferArbLost:
			LOG_ERROR("Returned i2cTransferArbLost");
			break;
		case i2cTransferUsageFault:
			LOG_ERROR("Returned i2cTransferUsageFault");
			break;
		case i2cTransferSwFault:
			LOG_ERROR("Returned i2cTransferSwFault");
			break;
		default:
			LOG_ERROR("Unknown Error");
			break;
	}
}

void temp_power_on(){  //turn on temperature sensor and wait for it to start up (80 ms).  Parameters: None. Returns: None
	//GPIO_PinOutSet(SENSOR_ON_PORT, SENSOR_ON_PIN);

	timerWaitUs(LPM_RAMP_TIME);
//	LOG_INFO("power up done");
//	GPIO_PinModeSet(SCL_PORT, SCL_PIN, gpioModeWiredAnd, true); //SCL
//	GPIO_PinModeSet(SDA_PORT, SDA_PIN, gpioModeWiredAnd, true); //SDA
} //turn on temperature sensor and wait for it to start up

void temp_power_off(){//turn off temperature sensor.  Parameters: None. Returns: None
	//GPIO_PinOutClear(SENSOR_ON_PORT, SENSOR_ON_PIN);
	GPIO_PinModeSet(SCL_PORT, SCL_PIN, gpioModeDisabled, false); //SCL
	GPIO_PinModeSet(SDA_PORT, SDA_PIN, gpioModeDisabled, false); //SDA
}

void i2c_init(void){ //initializes i2c operation. Parameters: None. Returns: None
	I2CSPM_Init_TypeDef i2c_init_struct = I2CSPM_INIT_DEFAULT;
	i2c_init_struct.sclPort = gpioPortC;
	i2c_init_struct.sclPin = 10;
	i2c_init_struct.sdaPort = gpioPortC;
	i2c_init_struct.sdaPin = 11;
	i2c_init_struct.portLocationScl = 14;
	i2c_init_struct.portLocationSda = 16;

	I2CSPM_Init(&i2c_init_struct);

	  /* Clear and enable interrupt from I2C module */
	  NVIC_ClearPendingIRQ(I2C0_IRQn);
	  //NVIC_EnableIRQ(I2C0_IRQn);

    dat[0] = 0;
    dat[1] = 0;
    i2c_step = no_i2c_step;
}

int temp_read(){ //initiates a temperature read. Returns 0 on success

	i2c_target = temp;

	I2C_TransferReturn_TypeDef retflag;

	/* ****************************************/
	//issue no hold master mode temp read command
	/* ****************************************/
	transfer_seq.addr = TEMP_SLAVE_ADDR;  //transmit to temperature sensor
	transfer_seq.buf[0].len = 1;  // 1 byte of data to transfer
	cmd = TEMP_READ_CMD; //send comand for temperature read
	transfer_seq.buf[0].data = &cmd;
	transfer_seq.flags = I2C_FLAG_WRITE; //performing a write

	i2c_step = write_cmd;

	CORE_CRITICAL_IRQ_DISABLE();
	SLEEP_SleepBlockBegin(sleepEM2);
	retflag = I2C_TransferInit(I2C0, &transfer_seq);
	NVIC_EnableIRQ(I2C0_IRQn);
	CORE_CRITICAL_IRQ_ENABLE();

//	if(retflag==i2cTransferDone){
//
//	  I2C_TransferSeq_TypeDef transfer_seq;
//	  transfer_seq.addr = TEMP_SLAVE_ADDR;  //transmit to temperature sensor
//	  transfer_seq.buf[0].len = 2;  // read msb and lsb
//
//	  transfer_seq.buf[0].data = dat;
//	  transfer_seq.flags = I2C_FLAG_READ; //performing a read
//
//	  I2C_TransferReturn_TypeDef retflag = I2C_TransferInit(I2C0, &transfer_seq);
//
//	  i2c_step = read_temp;
//	}


	return 0;

}

void light_write(uint16_t data, uint8_t command){

	i2c_target = light_write;
	light_write_data = data;

	I2C_TransferReturn_TypeDef retflag;

	transfer_seq.addr = LIGHT_SLAVE_ADDR | 0;  //write to light sensor
	transfer_seq.buf[0].len = 3;  // 3 bytes of data to transfer
	cmd = command; //send comand
	cmd_and_dat[0] = command;
	cmd_and_dat[1] = ((data&0xFF00)>>8);
	cmd_and_dat[2] = data&0x00FF;

	transfer_seq.buf[0].data = &cmd_and_dat;
	transfer_seq.flags = I2C_FLAG_WRITE; //performing a write

	i2c_step = write_cmd;

	CORE_CRITICAL_IRQ_DISABLE();
	SLEEP_SleepBlockBegin(sleepEM2);
	retflag = I2C_TransferInit(I2C0, &transfer_seq);
	NVIC_EnableIRQ(I2C0_IRQn);
	CORE_CRITICAL_IRQ_ENABLE();

}
void light_read(uint8_t command){
	i2c_target = light_read;

	I2C_TransferReturn_TypeDef retflag;

	transfer_seq.addr = LIGHT_SLAVE_ADDR | 1;  //write to light sensor
	transfer_seq.buf[0].len = 1;  // 1 byte of data to transfer
	cmd = command; //send comand
	transfer_seq.buf[0].data = &command;
	transfer_seq.flags = I2C_FLAG_WRITE; //performing a write

	i2c_step = write_cmd;

	CORE_CRITICAL_IRQ_DISABLE();
	SLEEP_SleepBlockBegin(sleepEM2);
	retflag = I2C_TransferInit(I2C0, &transfer_seq);
	NVIC_EnableIRQ(I2C0_IRQn);
	CORE_CRITICAL_IRQ_ENABLE();

}

void light_init(void){

	light_write(0b0000001100000010, CMD_ALS_CONF0); //set up conf0 register
	light_write(HIGH_THRESHOLD, CMD_ALS_WH);
	light_write(LOW_THRESHOLD, CMD_ALS_WL);
}

double tempcode_to_degc(uint16_t tempcode){  //converts tempcode returned by temperature sensor to degrees C. Takes in 16-bit tempcode, returns temp in degrees C as double-precision float

	return 175.72*(double)tempcode/65536 - 46.85;
}
