/*
 * SPI1_config.h
 *
 *  Created on: May 22, 2023
 *      Author: ahmed saad
 */

#ifndef SPI1_CONFIG_H_
#define SPI1_CONFIG_H_

/////////////////////////////////////////////////////////
// DATA MODE
/*
 1) FULL_DUPLEX
 2) HALF_DUPLEX
 */
#define     DATA_MODE     FULL_DUPLEX
/////////////////////////////////////////////////////////
// HALF DUPLEX
/*
 1) RECIEVE_ONLY
 2) TRANSMIT_ONLY
 */
#define     HALF_DUPLEX     TRANSMIT_ONLY
/////////////////////////////////////////////////////////
// DATA FRAME
/*
 1) EIGHT_BIT
 2) SIXTEEN_BIT
 */
#define     DATA_FRAME     EIGHT_BIT
/////////////////////////////////////////////////////////
// SLAVE MANAGMENT
/*
 1) ENABLED
 2) DISABLED
 */
#define     SLAVE_MANAGMENT     ENABLED
/////////////////////////////////////////////////////////
// FRAME FORMAT
/*
 1) MSB --> MOST SIGNIFICANT BIT
 2) LSB --> LEAST SIGNIFICANT BIT
 */
#define     FRAME_FORMAT     MSB
/////////////////////////////////////////////////////////
// BAUD RATE CONTROL
#define  Fpclk_2     0x0000
#define  Fpclk_4     0x0008
#define  Fpclk_8     0x0010
#define  Fpclk_16    0x0018
#define  Fpclk_32    0x0020
#define  Fpclk_64    0x0028
#define  Fpclk_128   0x0030
#define  Fpclk_256   0x0038

#define    BAUD_RATE       Fpclk_8
/////////////////////////////////////////////////////////
// SELECTION MODE
/*
 1) MASTER
 2) SLAVE
 */
#define     SELECTION_MODE     MASTER
/////////////////////////////////////////////////////////
// CLOCK POLARITY
/*
 1) RISING_EDGE
 2) FALLING_EDGE
 */
#define     CLK_POLARITY     RISING_EDGE
/////////////////////////////////////////////////////////
// CLOCK PHASE
/*
 1) SAMPLE_FIRST
 2) SETUP_FIRST
 */
#define     CLK_PHASE     SAMPLE_FIRST
//////////////////////////////////////////////////////////
// TRANSMITTER INTERRUPT
/*
 1)SPI1_TX_INT_ENABLE
 2)SPI1_TX_INT_DISABLE
 */
#define     SPI1_TRANSMITTER_INTERRUPT     SPI1_TX_INT_ENABLE
//////////////////////////////////////////////////////////
// RECIEVER INTERRUPT
/*
 1)SPI1_RX_INT_ENABLE
 2)SPI1_RX_INT_DISABLE
 */
#define     SPI1_RECIEVER_INTERRUPT        SPI1_RX_INT_ENABLE



#endif /* SPI1_CONFIG_H_ */
