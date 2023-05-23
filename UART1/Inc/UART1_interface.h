/*
 * UART1_interface.h
 *
 *  Created on: May 14, 2023
 *      Author: ahmed saad
 */

#ifndef UART1_INTERFACE_H_
#define UART1_INTERFACE_H_

void UART1_init();
void UART1_enableTX(void);
void UART1_enableRX(void);
void UART1_TXdata(u8 data);
void UART1_RXdata (u8 *data );
void UART1_voidSendString(u8 * str);
void const UART1_StrReceiveString(u8 *  str);
void		  UART1_voidSetCallBack(void (*Fptr)(void));

#endif /* UART1_INTERFACE_H_ */
