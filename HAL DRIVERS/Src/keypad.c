/*
 * keypad.c
 *
 * Created: 1/12/2023 1:10:50 PM
 *  Author: ahmed saad
 */ 

#include "keypad.h"
#include "Delay.h"
u8 keypad_buttons[4][4]={{'1','2','3','A'},
			{'4','5','6','B'},
			{'7','8','9','C'},
			{'*','0','#','D'}};


void Keypad_Init()
{
		DIO_voidSetPinDirection(COLUMN_PORT,C1_PIN,GPIO_OUTPUT_2MHZ_PP);
		DIO_voidSetPinDirection(COLUMN_PORT,C2_PIN,GPIO_OUTPUT_2MHZ_PP);
		DIO_voidSetPinDirection(COLUMN_PORT,C3_PIN,GPIO_OUTPUT_2MHZ_PP);
		DIO_voidSetPinDirection(COLUMN_PORT,C4_PIN,GPIO_OUTPUT_2MHZ_PP);
		DIO_voidSetPinDirection(ROW_PORT,R1_PIN,GPIO_INPUT_PULL_UP_DOWN);
		DIO_voidSetPinDirection(ROW_PORT,R2_PIN,GPIO_INPUT_PULL_UP_DOWN);
		DIO_voidSetPinDirection(ROW_PORT,R3_PIN,GPIO_INPUT_PULL_UP_DOWN);
		DIO_voidSetPinDirection(ROW_PORT,R4_PIN,GPIO_INPUT_PULL_UP_DOWN);
}
u8 Keypad_GetPressedKey()
{
	u8 column,row;
	u8 volatile Local_preeskey = 0xff;
	while(1)
	{
		for(column=C1_PIN;column<=C4_PIN;column++)
		{
			DIO_voidSetPinValue(COLUMN_PORT,(column-C1_PIN),KEYPAD_LOW);
			for(row=R1_PIN;row<=R4_PIN;row++)
			{
				if(DIO_u8GetPinValue(ROW_PORT,(row-R1_PIN)) == 0)
				{
					Local_preeskey = (keypad_buttons[(row-R1_PIN)][(column-C1_PIN)]);
					_delay_ms(200);
				}
			}
			DIO_voidSetPinValue(COLUMN_PORT,(column-C1_PIN),KEYPAD_HIGH);
		}
	}
	return Local_preeskey  ;
}
