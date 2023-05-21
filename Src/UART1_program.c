/*
 * UART1_program.c
 *
 *  Created on: May 14, 2023
 *      Author: ahmed saad
 */

#include "Std_Types.h"
#include "Bit_Math.h"
#include "UART1_config.h"
#include "UART1_interface.h"
#include "UART1_private.h"
//static	void	(*UART1_CallBack)	   (void)	= NULL;
//u8 TX_Flag=0,RX_Flag=0;
void UART1_init()
{
	// select the DIV
	UART1->BRR=DIV;
	// enable UART
	SET_BIT(UART1->CR1,13);
	// select frame format
#if  DATA_BITS == DATA_BITS_8
	CLR_BIT(UART1->CR1,12); // 8 DATA BITS
#elif  DATA_BITS == DATA_BITS_9
	SET_BIT(UART1->CR1,12); // 9 DATA BITS
#endif
#if PARITY_ACTIVATION == PARITY_ENABLED
	SET_BIT(UART1->CR1,10); // PARITY ENABLED
#elif PARITY_ACTIVATION == PARITY_DISABLED
	CLR_BIT(UART1->CR1,10); // PARITY DISABLED
#endif
#if PARITY_SELECTION  ==   EVEN_PARITY
	CLR_BIT(UART1->CR1,10); // EVEN PARITY
#elif PARITY_SELECTION  ==   ODD_PARITY
	SET_BIT(UART1->CR1,10); // ODD PARITY
#endif
#if	STOP_BITS ==  ONE_STOP_BIT
	CLR_BIT(UART1->CR2,12);
	CLR_BIT(UART1->CR2,13);
#elif	STOP_BITS ==  TWO_STOP_BITS
	CLR_BIT(UART1->CR2,12);
	SET_BIT(UART1->CR2,13);
#endif
	SET_BIT(UART1->CR1,7); // IF TRANSMITTER DATA REGISTER IS EMPTY ENABLE INT
	SET_BIT(UART1->CR1,5); // ENABLE RECIEVER INT
}
void UART1_enableTX(void)
{
	SET_BIT(UART1->CR1,3);
}
void UART1_enableRX(void)
{
	SET_BIT(UART1->CR1,2);
}
void UART1_TXdata(u8 data)
{
	while(!GET_BIT(UART1->SR,7)) ;
	UART1->DR = data ;
}
void UART1_RXdata (u8 *data )
{
	while(!GET_BIT(UART1->SR,5)) ;
	*data = UART1->DR ;
}
void UART1_voidSendString(u8 *  str)
{
	while(*str != NULL_char)
	{
		UART1_TXdata(*str);
		str++;
	}
}
void const UART1_StrReceiveString(u8 *  str)
{

	while(*str != NULL_char)
	{
		UART1_RXdata(str);
		str++;
	}
}
//void		  UART1_voidSetCallBack(void (*Fptr)(void))
//{
//	if(Fptr != NULL)
//	{
//		UART1_CallBack= Fptr  ;
//	}
//}
//void	USART1_IRQHandler(void)
//{
//	if(GET_BIT(UART1->SR,7) == 1)
//	{
//		TX_Flag=1;
//		/*	Clear the Flag			*/
//		CLR_BIT(UART1->SR,7);
//	}
//	if(GET_BIT(UART1->SR,5) == 1)
//	{
//		RX_Flag=1;
//		/*	Clear the Flag			*/
//		CLR_BIT(UART1->SR,5);
//	}
//	if(RX_Flag==1)
//	{
//		UART1_CallBack();
//	}
//}

