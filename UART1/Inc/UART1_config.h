/*
 * UART1_config.h
 *
 *  Created on: May 14, 2023
 *      Author: ahmed saad
 */

#ifndef UART1_CONFIG_H_
#define UART1_CONFIG_H_

//BAUD RATE
#define 	DIV_BAUD_9600_8MHZ      0X0341
#define 	DIV_BAUD_9600_72MHZ     0X1D4C
#define 	DIV_BAUD_115200_8MHZ    0X0045
#define 	DIV_BAUD_115200_72MHZ   0X0271
#define     DIV      				DIV_BAUD_9600_8MHZ
/////////////////////////////////////////////////////////
// WORD LENGTH
/*
 1) DATA_BITS_8
 2) DATA_BITS_9
 */
#define     DATA_BITS     DATA_BITS_8
//////////////////////////////////////////////////////////
// PARITY
/*
 1)PARITY_ENABLED
 2)PARITY_DISABLED
 */
#define     PARITY_ACTIVATION     PARITY_ENABLED
/*
 1) EVEN_PARITY
 2) ODD_PARITY
 */
#define     PARITY_SELECTION     EVEN_PARITY
//////////////////////////////////////////////////////////
// STOP BITS
/*
 1)ONE_STOP_BIT
 2)TWO_STOP_BITS
 */
#define     STOP_BITS     ONE_STOP_BIT
//////////////////////////////////////////////////////////
// TRANSMITTER INTERRUPT
/*
 1)ENABLE
 2)DISABLE
 */
#define     TRANSMITTER_INTERRUPT     ENABLE
//////////////////////////////////////////////////////////
// RECIEVER INTERRUPT
/*
 1)ENABLE
 2)DISABLE
 */
#define     RECIEVER_INTERRUPT     ENABLE

#endif /* UART1_CONFIG_H_ */
