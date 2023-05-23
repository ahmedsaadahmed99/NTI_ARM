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
#include "SPI1_config.h"

static	void	(*SPI1_CallBack)	   (void)	= NULL;
u8 SPI1_TX_Flag=0,SPI1_RX_Flag=0;

void SPI1_init()
{
	SET_BIT(SPI1->CR1,6); // SPI ENABLE
	SPI1->CR1|=BAUD_RATE; // BAUD RATE
#if (DATA_MODE == FULL_DUPLEX)
	CLR_BIT(SPI1->CR1,15);
	CLR_BIT(SPI1->CR1,10);
#elif (DATA_MODE == HALF_DUPLEX)
	SET_BIT(SPI1->CR1,15);
    #if (HALF_DUPLEX == TRANSMIT_ONLY)
	SET_BIT(SPI1->CR1,14);
	#elif (HALF_DUPLEX == RECIEVE_ONLY)
	CLR_BIT(SPI1->CR1,14);
	#endif
#endif
#if (DATA_FRAME == EIGHT_BIT)
	CLR_BIT(SPI1->CR1,11);
#elif (DATA_FRAME == SIXTEEN_BIT)
	SET_BIT(SPI1->CR1,11);
#endif
#if (SLAVE_MANAGMENT == ENABLED)
	SET_BIT(SPI1->CR1,8);
	SET_BIT(SPI1->CR1,9);
#elif (SLAVE_MANAGMENT == DISABLED)
	CLR_BIT(SPI1->CR1,8);
	CLR_BIT(SPI1->CR1,9);
#endif
#if (FRAME_FORMAT == MSB)
	CLR_BIT(SPI1->CR1,7);
#elif (FRAME_FORMAT == LSB)
	SET_BIT(SPI1->CR1,7);
#endif
#if (SELECTION_MODE == MASTER)
	SET_BIT(SPI1->CR1,2);
#elif (SELECTION_MODE == SLAVE)
	CLR_BIT(SPI1->CR1,2);
#endif
#if (CLK_POLARITY == RISING_EDGE)
	SET_BIT(SPI1->CR1,1);
#elif (CLK_POLARITY == FALLING_EDGE)
	CLR_BIT(SPI1->CR1,1);
#endif
#if (CLK_PHASE == SAMPLE_FIRST)
	SET_BIT(SPI1->CR1,0);
#elif (CLK_PHASE == SETUP_FIRST)
	CLR_BIT(SPI1->CR1,0);
#endif
#if (SPI1_TRANSMITTER_INTERRUPT == SPI1_TX_INT_ENABLE)
	SET_BIT(SPI1->CR2,7);
#elif (SPI1_TRANSMITTER_INTERRUPT == SPI1_TX_INT_DISABLE)
	CLR_BIT(SPI1->CR2,7);
#endif
#if (SPI1_RECIEVER_INTERRUPT == SPI1_RX_INT_ENABLE)
	SET_BIT(SPI1->CR2,6);
#elif (SPI1_RECIEVER_INTERRUPT == SPI1_RX_INT_DISABLE)
	CLR_BIT(SPI1->CR2,6);
#endif
}
u8 SPI1_TX_RX_Char(u8 data)
{
	u8 rx_data=0;
	DIO_voidSetPinValue(PORTA, PIN4, GPIO_LOW); //SET SS PIN TO LOW
	SPI1->DR = data ;
	rx_data = SPI1->DR;
	DIO_voidSetPinValue(PORTA, PIN4, GPIO_HIGH); //SET SS PIN TO HIGH
	return rx_data;

}
void		  SPI1_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		SPI1_CallBack= Fptr  ;
	}
}
void	SPI1_IRQHandler(void)
{
	if(GET_BIT(SPI1->SR,1) == 1)
	{
		SPI1_TX_Flag=1;
		/*	Clear the Flag			*/
		CLR_BIT(SPI1->SR,1);
	}
	if(GET_BIT(SPI1->SR,0) == 1)
	{
		SPI1_RX_Flag=1;
		/*	Clear the Flag			*/
		CLR_BIT(SPI1->SR,0);
	}
	if(SPI1_CallBack != NULL)
		SPI1_CallBack();
}
#endif /* SPI1_PROGRAM_C_ */
