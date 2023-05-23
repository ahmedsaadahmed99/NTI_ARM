/*
 * SPI_interface.h
 *
 *  Created on: May 15, 2023
 *      Author: ahmed saad
 */

#ifndef SPI1_INTERFACE_H_
#define SPI1_INTERFACE_H_

void SPI1_init();
u8 SPI1_TX_RX_Char(u8 data);
void		 SPI1_voidSetCallBack(void (*Fptr)(void));

#endif /* SPI1_INTERFACE_H_ */
