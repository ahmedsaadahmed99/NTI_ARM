/*
 * UART_private.h
 *
 *  Created on: May 14, 2023
 *      Author: ahmed saad
 */

#ifndef UART1_PRIVATE_H_
#define UART1_PRIVATE_H_

typedef		struct
{
	u32		SR;
	u32		DR;
	u32		BRR;
	u32		CR1;
	u32		CR2;
	u32		CR3;
	u32		CTPR;
}UART1_Type;

#define		UART1		((volatile UART1_Type*)(0x40013800))

#endif /* UART1_PRIVATE_H_ */
