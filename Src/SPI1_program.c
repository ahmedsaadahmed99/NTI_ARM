/*
 * SPI1_program.c
 *
 *  Created on: May 15, 2023
 *      Author: ahmed saad
 */

#ifndef SPI1_PROGRAM_C_
#define SPI1_PROGRAM_C_

#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "SPI1_interface.h"
#include "SPI1_private.h"

void SPI1_init()
{
	// FULL DUPLEX
	CLR_BIT(SPI1->CR1,15);
	CLR_BIT(SPI1->CR1,10);
	// SOFTWARE SLAVE MANAGMENT
	SET_BIT(SPI1->CR1,8);
	SET_BIT(SPI1->CR1,9);
	// MSB
	CLR_BIT(SPI1->CR1,7);
	// SPI ENABLE
	SET_BIT(SPI1->CR1,6);
	// FPCLK
	CLR_BIT(SPI1->CR1,3);
	SET_BIT(SPI1->CR1,4);
	CLR_BIT(SPI1->CR1,5);
	// MASTER MODE
	SET_BIT(SPI1->CR1,2);
	// RISING EDGE,SETUP FIRST THEN SAMPLE
	SET_BIT(SPI1->CR1,1);
	SET_BIT(SPI1->CR1,0);
	// 8-BIT DATA FRAME
	CLR_BIT(SPI1->CR1,11);
	//DISABLE ALL INTERRUPT
	SPI1->CR2=0;
}
u8 SPI1_TX_RX_Char(u8 data)
{
	u8 rx_data=0;
	DIO_voidSetPinValue(PORTA, PIN4, GPIO_LOW); //SET SS PIN TO LOW
	SPI1->DR = data ;
    while(GET_BIT(SPI1->SR,7)) ;
		 rx_data = SPI1->DR;
	DIO_voidSetPinValue(PORTA, PIN4, GPIO_HIGH); //SET SS PIN TO HIGH
	return rx_data;

}
#endif /* SPI1_PROGRAM_C_ */
