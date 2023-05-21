/*
 * I2C_interface.h
 *
 *  Created on: May 18, 2023
 *      Author: ahmed saad
 */

#ifndef I2C1_INTERFACE_H_
#define I2C1_INTERFACE_H_

/**** STEPS FOLLOWED  ************
1. Enable the I2C CLOCK and GPIO CLOCK
2. Configure the I2C PINs for ALternate Functions
	a) Select Alternate Function in MODER Register
	b) Select Open Drain Output
	c) Select High SPEED for the PINs
	d) Select Pull-up for both the Pins
	e) Configure the Alternate Function in AFR Register
3. Reset the I2C
4. Program the peripheral input clock in I2C_CR2 Register in order to generate correct timings
5. Configure the clock control registers
6. Configure the rise time register
7. Program the I2C_CR1 register to enable the peripheral
*/
//void I2C_voidMasterInit(u8 Copy_u8SlaveAddress);
//void I2C_voidSlaveInit(u8 Copy_u8SlaveAddress);
//void I2C_SendStartCondition(void);
//void I2C_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);
//void I2C_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);
//void I2C_MasterWriteDataByte(u8 Copy_u8DataByte);
//void I2C_MasterReadDataByte(u8 *Copy_pu8DataByte);
//void I2C_SendStopCondition(void);


#endif /* I2C1_INTERFACE_H_ */
