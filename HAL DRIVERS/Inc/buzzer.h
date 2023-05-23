/*
 * buzzer.h
 *
 * Created: 1/13/2023 4:01:41 PM
 *  Author: ahmed saad
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

#include "DIO_interface.h"

void BUZZER_Init(u8 portName,u8 pinNumber);
void BUZZER_on(u8 portName,u8 pinNumber);
void BUZZER_off(u8 portName,u8 pinNumber);

#endif /* BUZZER_H_ */
