/*
 * I2C_program.c
 *
 *  Created on: May 18, 2023
 *      Author: ahmed saad
 */
//#include "Std_Types.h"
//#include "Bit_Math.h"
//#include "I2C1_interface.h"
//#include "I2C1_private.h"
//
//void I2C_voidMasterInit(u8 Copy_u8SlaveAddress)
//{
//	// Reset I2C
//	SET_BIT(I2C1->CR1,15);
//	CLR_BIT(I2C1->CR1,15);
//	// Select I2C Clock Frequency
//	SET_BIT(I2C1->CR2,3);  // 8MHZ
//	/* Configure the clock control registers */
//	I2C1->CCR = 40<<0;
//	/* Configure the rise time register */
//	I2C1->TRISE = 9;
//	// Enable I2C
//	SET_BIT(I2C1->CR1,0);
//}
