/*
 * buzzer.c
 *
 * Created: 1/13/2023 4:01:26 PM
 *  Author: ahmed saad
 */ 

#include "buzzer.h"
void BUZZER_Init(u8 portName,u8 pinNumber)
{
	DIO_voidSetPinDirection(portName,pinNumber,GPIO_OUTPUT_2MHZ_PP);
}
void BUZZER_on(u8 portName,u8 pinNumber)
{
	DIO_voidSetPinValue(portName,pinNumber,GPIO_HIGH);
}
void BUZZER_off(u8 portName,u8 pinNumber)
{
	DIO_voidSetPinValue(portName,pinNumber,GPIO_LOW);
}
