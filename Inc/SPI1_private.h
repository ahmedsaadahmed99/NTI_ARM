/*
 * SPI1_private.h
 *
 *  Created on: May 15, 2023
 *      Author: ahmed saad
 */

#ifndef SPI1_PRIVATE_H_
#define SPI1_PRIVATE_H_

typedef		struct
{
	u32		CR1;
	u32		CR2;
	u32		SR;
	u32		DR;
	u32		CRCPR;
	u32		RXCRCR;
	u32		TXCRCR;
	u32		SPI_I2SCFGR;
	u32		SPI_I2SPR;
}SPI1_Type;

#define		SPI1		((volatile SPI1_Type*)(0x40013000))


#endif /* SPI1_PRIVATE_H_ */
