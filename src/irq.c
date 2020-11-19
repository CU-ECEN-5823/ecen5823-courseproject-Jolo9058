/*
 * irq.c
 *
 *  Created on: Sep 8, 2020
 *      Author: Joe Lopez
 */

#include "irq.h"

void I2C0_IRQHandler(void){ //interrupt handler for I2C0

	i2c_ret_status = I2C_Transfer(I2C0); //this handles interupt flags

	//if(i2c_ret_status != i2cTransferInProgress){
	//LOG_INFO("I2C IRQ");
	CORE_CRITICAL_IRQ_DISABLE();

	gecko_external_signal(I2C_SCHEDULE);
	//irqs++;

	CORE_CRITICAL_IRQ_ENABLE();
	//}



}
