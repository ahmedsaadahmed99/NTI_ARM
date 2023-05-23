#include"RCC_interface.h"
#include"DIO_interface.h"
#include "led.h"
#include"DELAY.h"
#include"LCD.h"

int main(void)
{
    /* Loop forever */
	RCC_PARAMETER_t par;
	par.HSI_Activation=HSI_ON;
	par.Clk_Source=CLK_HSI;
	RCC_voidSysClkInt(par);
	RCC_voidEnablePerClk(RCC_APB2,2);//port A
	RCC_voidEnablePerClk(RCC_APB2,3);//port B
	LED_init(PORTA,PIN0); //LED0->YELLOW WIRE
	LED_init(PORTA,PIN1); //LED1->BURBBLE WIRE
	LED_init(PORTA,PIN2); //LED2->GRAY WIRE
	DIO_voidSetPinDirection(PORTB,PIN14,GPIO_INPUT_PULL_UP_DOWN); // YELLOW WIRE (B9)
	DIO_voidSetPinDirection(PORTB,PIN13,GPIO_INPUT_PULL_UP_DOWN); //BURBLE WIRE (B8)
	DIO_voidSetPinDirection(PORTB,PIN12,GPIO_INPUT_PULL_UP_DOWN); // GRAY WIRE (B7)
	DIO_voidSetPinValue(PORTB, PIN9, GPIO_LOW);
	DIO_voidSetPinValue(PORTB, PIN8, GPIO_LOW);
	DIO_voidSetPinValue(PORTB, PIN7, GPIO_LOW);
	LED_off(PORTA,PIN0);
	LED_off(PORTA,PIN1);
	LED_off(PORTA,PIN2);
	LCD_Init();
	LCD_Clear();
	while(1)
	{
		if(DIO_u8GetPinValue(PORTB,PIN12) == 1)
		{
			LED_on(PORTA,PIN2);
			LCD_Write_String("Water Level:25%");
		}
		else if(DIO_u8GetPinValue(PORTB,PIN12) == 0)
		{
			LED_off(PORTA,PIN2);
			LCD_Clear();
		}
		if(DIO_u8GetPinValue(PORTB,PIN13) == 1)
		{
			LED_on(PORTA,PIN1);
			LCD_Write_String("Water Level:50%");
		}
		else if(DIO_u8GetPinValue(PORTB,PIN13) == 0)
		{
			LED_off(PORTA,PIN1);
			LCD_Clear();
		}
		if(DIO_u8GetPinValue(PORTB,PIN14) == 1)
		{
			LED_on(PORTA,PIN0);
			LCD_Write_String("Water Level:100%");
		}
		else if(DIO_u8GetPinValue(PORTB,PIN14) == 0)
		{
			LED_off(PORTA,PIN0);
			LCD_Clear();
		}
	}
	return 0 ;
