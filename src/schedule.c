/**************************************************************************************************
 * @file      schedule.c
 * @version   0.0.1
 * @brief     scheduler implementation file
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
#include "schedule.h"

void state_machine(struct gecko_cmd_packet* evt){ //takes a bluetooth low energy external event and handles it appropriately

	if((BGLIB_MSG_ID(evt->header)) == gecko_evt_system_external_signal_id){

	uint32_t schedule = evt->data.evt_system_external_signal.extsignals;  //variable to indicate events scheduled
	LOG_INFO("Handling external event: schedule = %x", schedule);
	//while(schedule){
	  /* Scheduler */
	/* Note: this scheduler is implemented as a stack of if-else clauses instead of a
	 * switch case statement in order to facilitate the possibility that multiple event flags are
	 * set simultaneously, in which case the schedule variable will not be equal to any one case*/
	  /* ********* */
	  if (schedule & LETIMER_COMP0){
		  CORE_CRITICAL_IRQ_DISABLE();
		  schedule &= ~LETIMER_COMP0;
		  //gpioLed0SetOn();
		  CORE_CRITICAL_IRQ_ENABLE();

		  event_letimer_comp0();

	  }
	  else if (schedule & LETIMER_COMP1){
		  CORE_CRITICAL_IRQ_DISABLE();
		  schedule &= ~LETIMER_COMP1;
		  event_letimer_comp1();
		  //gpioLed0SetOff();
		  CORE_CRITICAL_IRQ_ENABLE();
	  }
	  else if(schedule & I2C_SCHEDULE){
		  CORE_CRITICAL_IRQ_DISABLE();
		  schedule &= ~I2C_SCHEDULE;

		  CORE_CRITICAL_IRQ_ENABLE();
		  event_i2c();


	  }
	  else if(schedule & PB0_SCHEDULE){
		  LOG_INFO("PB0");
		  CORE_CRITICAL_IRQ_DISABLE();
		  schedule &= ~PB0_SCHEDULE;
		  CORE_CRITICAL_IRQ_ENABLE();

		  event_gpio_pb0();
	  }

	  else if(schedule & PB1_SCHEDULE){

		  CORE_CRITICAL_IRQ_DISABLE();
		  schedule &= ~PB1_SCHEDULE;
		  CORE_CRITICAL_IRQ_ENABLE();

		  event_gpio_pb1();
	  }

	//}
	}
}


void event_letimer_comp0(void){ //handle letimer comp0 firing by beginning lpm sequence


	  /* Perform temperature measurement */
	  LOG_INFO("Sensor Power ON");
	  temp_power_on();
//	  LOG_INFO("Reading temp");
//	  temp_read();
}

void event_letimer_comp1(void){
	LOG_INFO("power up done");
	GPIO_PinModeSet(SCL_PORT, SCL_PIN, gpioModeWiredAnd, true); //SCL
	GPIO_PinModeSet(SDA_PORT, SDA_PIN, gpioModeWiredAnd, true); //SDA
	LOG_INFO("Reading temp");
	temp_read();
}


void event_i2c(void){ //handle i2c interrupt by advancing i2c state machine

	int tempcode;


	switch(i2c_ret_status){
	case(i2cTransferInProgress):
		  //LOG_INFO("A transfer is in progress");
		  break;

	case(i2cTransferDone):  //transaction complete
		  LOG_INFO("A transfer Completed");
		  switch(i2c_step){
		  case(write_cmd): //finished first step
			  if(i2c_target == temp){

				  transfer_seq.addr = TEMP_SLAVE_ADDR;  //transmit to temperature sensor
				  transfer_seq.buf[0].len = 2;  // read msb and lsb

				  transfer_seq.buf[0].data = dat;
				  transfer_seq.flags = I2C_FLAG_READ; //performing a read
				  I2C_TransferReturn_TypeDef retflag = I2C_TransferInit(I2C0, &transfer_seq);

				  i2c_step = read_data;
			  }
			  else if (i2c_target == light_read){

				  transfer_seq.addr = LIGHT_SLAVE_ADDR | 1;  //transmit to temperature sensor
				  transfer_seq.buf[0].len = 2;  // read msb and lsb

				  transfer_seq.buf[0].data = dat;
				  transfer_seq.flags = I2C_FLAG_READ; //performing a read
				  I2C_TransferReturn_TypeDef retflag = I2C_TransferInit(I2C0, &transfer_seq);

				  i2c_step = read_data;

			  }
			  else if (i2c_target == light_write){
					SLEEP_SleepBlockEnd(sleepEM2);
					i2c_step = no_i2c_step;
			  }
			  break;

		  case(read_data):
				if(i2c_target == temp){
					tempcode = dat[0] << 8 | dat[1];
					float temp_c = tempcode_to_degc(tempcode);
					LOG_INFO("Current Temperature: %f degrees C", temp_c);
					current_temp = (int)temp_c;

					LOG_INFO("Sensor Power OFF");
					temp_power_off();

					uint8_t temp_buff[5]; //buffer to hold bitstream
					uint8_t * buff_ptr = temp_buff; //pointer to buffer
					uint32_t t = (int)temp_c << 8;


					//uint32_t temp_int = FLT_TO_UINT32(temp_c, -3);
					UINT32_TO_BITSTREAM(buff_ptr, t);

	//				struct gecko_msg_gatt_server_send_characteristic_notification_rsp_t* temp_resp = gecko_cmd_gatt_server_send_characteristic_notification(
	//						0xFF, //connection; 0xFF=send to all
	//						gattdb_temperature_measurement,//characteristic handle
	//						5, //length (bytes)
	//						temp_buff); //data buffer pointer
	//				if(temp_resp->result!=0){
	//					LOG_WARN("Characteristic notification non-0 response: %x", temp_resp->result);
	//				}
	//				LOG_INFO("Sent Length: %d", temp_resp->sent_len);

					NVIC_DisableIRQ(I2C0_IRQn);
					SLEEP_SleepBlockEnd(sleepEM2);
					i2c_step = no_i2c_step;
				}
				else if (i2c_target == light_read){
					light_read_data = dat[1] << 8 | dat[0];

					SLEEP_SleepBlockEnd(sleepEM2);
					i2c_step = no_i2c_step;
				}
				break;

		  case(no_i2c_step):
		  default:
			  break;
		  }
		  break;

	  case(i2cTransferNack):
		if(i2c_step == read_data){
			  transfer_seq.addr = TEMP_SLAVE_ADDR;  //transmit to temperature sensor
			  transfer_seq.buf[0].len = 2;  // read msb and lsb

			  transfer_seq.buf[0].data = dat;
			  transfer_seq.flags = I2C_FLAG_READ; //performing a read
			  I2C_TransferReturn_TypeDef retflag = I2C_TransferInit(I2C0, &transfer_seq);
		}
		else{
			LOG_WARN("Unexpected NACK");
		}
		break;
	  default: //error occurred
		  	  LOG_ERROR("Encountered i2c transfer error. Error code: %d", i2c_ret_status);
		  	  break;
	}
}


void event_gpio_pb0(void){


}

void event_gpio_pb1(void){
	LOG_INFO("PB1 pressed");

}
