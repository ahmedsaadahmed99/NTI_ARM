/*
 * CFile1.c
 *
 * Created: 12/12/2022 10:02:36 PM
 *  Author: ahmed saad
 */ 

#include "button.h"

void BUTTON_init(u8 portName,u8 pinNumber)
{
	DIO_voidSetPinDirection(portName,pinNumber,GPIO_INPUT_PULL_UP_DOWN);
}
u8 BUTTON_read(u8 portName,u8 pinNumber)
{
	u8 value;
	value=DIO_u8GetPinValue(portName,pinNumber);
    return value;
}
