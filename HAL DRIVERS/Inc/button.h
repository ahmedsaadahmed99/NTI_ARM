/*
 * button.h
 *
 * Created: 12/12/2022 10:02:30 PM
 *  Author: ahmed saad
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "DIO_interface.h"


void BUTTON_init(u8 portName,u8 pinNumber);
u8 BUTTON_read(u8 portName,u8 pinNumber);



#endif /* BUTTON_H_ */
