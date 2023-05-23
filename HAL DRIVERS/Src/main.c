#define SCENARIO_1	  0  // LED TOGGLING USING DIO
#define SCENARIO_2	  0  // LED TOGGLING USING LED DRIVER
#define SCENARIO_3	  0  // LED ACTIVATION USING SWITCH
#define SCENARIO_4	  0  // BUZZER ACTIVATION
#define SCENARIO_5	  0  // WRITE CHARACTER IN LCD
#define SCENARIO_6    0 // MY ARABIC NAME
#define SCENARIO_7    0 // WRITING ON LCD USING KEYPAD
////////////////////////////////////////////////////////////////////////////////////////////////////
#if SCENARIO_1
#include"RCC_interface.h"
#include"DIO_interface.h"
#include"DELAY.h"

int main(void)
{
    /* Loop forever */
	RCC_PARAMETER_t par;
	par.HSI_Activation=HSI_ON;
	par.Clk_Source=CLK_HSI;
	RCC_voidSysClkInt(par);
	RCC_voidEnablePerClk(RCC_APB2,4);
	DIO_voidSetPinDirection(PORTC,PIN13,GPIO_OUTPUT_2MHZ_PP);
	while(1)
	{
		//	Led On
				DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
				_delay_ms(1000);
				//	Led Off
				DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
				_delay_ms(1000);
	}
	return 0 ;
}
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////
#if SCENARIO_2
#include"RCC_interface.h"
#include"led.h"

int main(void)
{
    /* Loop forever */
	RCC_PARAMETER_t par;
	par.HSI_Activation=HSI_ON;
	par.Clk_Source=CLK_HSI;
	RCC_voidSysClkInt(par);
	RCC_voidEnablePerClk(RCC_APB2,2);
	LED_init(PORTA,PIN0);
	while(1)
	{
		//	Led On
				LED_on(PORTA,PIN0);
				_delay_ms(1000);
				//	Led Off
				LED_off(PORTA,PIN0);
				_delay_ms(1000);
	}
	return 0 ;
}
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////
#if SCENARIO_3
#include"RCC_interface.h"
#include"button.h"
#include "led.h"

int main(void)
{
    /* Loop forever */
	RCC_PARAMETER_t par;
	par.HSI_Activation=HSI_ON;
	par.Clk_Source=CLK_HSI;
	RCC_voidSysClkInt(par);
	RCC_voidEnablePerClk(RCC_APB2,2);
	LED_init(PORTA,PIN0);
	BUTTON_init(PORTA,PIN1);
	DIO_voidSetPinValue(PORTA, PIN1,GPIO_HIGH);
	while(1)
	{
		LED_off(PORTA,PIN0);
		while(!BUTTON_read(PORTA,PIN1));
		LED_on(PORTA,PIN0);
	}
	return 0 ;
}
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////
#if SCENARIO_4
#include"RCC_interface.h"
#include"buzzer.h"

int main(void)
{
    /* Loop forever */
	RCC_PARAMETER_t par;
	par.HSI_Activation=HSI_ON;
	par.Clk_Source=CLK_HSI;
	RCC_voidSysClkInt(par);
	RCC_voidEnablePerClk(RCC_APB2,3);
	BUZZER_Init(PORTB,PIN13);
	while(1)
	{
		//	Led On
				BUZZER_on(PORTB,PIN13);
				_delay_ms(2000);
				//	Led Off
				BUZZER_off(PORTB,PIN13);
				_delay_ms(2000);
	}
	return 0 ;
}
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////
#if SCENARIO_5
#include"RCC_interface.h"
#include"LCD.h"

int main(void)
{
    /* Loop forever */
	RCC_PARAMETER_t par;
	par.HSI_Activation=HSI_ON;
	par.Clk_Source=CLK_HSI;
	RCC_voidSysClkInt(par);
	RCC_voidEnablePerClk(RCC_APB2,2);
	RCC_voidEnablePerClk(RCC_APB2,3);
	LCD_Init();
	while(1)
	{
		LCD_Write_Char('A');
		_delay_ms(100000);
	}
	return 0 ;
}
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////
#if SCENARIO_6
#include"RCC_interface.h"
#include"LCD.h"

u8 alf[8] ={0x06,0x08,0x04,0x0E,0x00,0x04,0x04,0x04};
u8 _7a2[8]={0x00,0x00,0x00,0x00,0x00,0x04,0x02,0x1F};
u8 mem[8]={0x00,0x00,0x00,0x00,0x00,0x07,0x05,0x1F};
u8 dal[8]={0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x0F};
u8 sen[8]={0x00,0x00,0x00,0x00,0x00,0x15,0x15,0x1F};
u8 sharta[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F};
u8 _3en[8]={0x00,0x00,0x00,0x00,0x03,0x04,0x02,0x0F};

int main(void)
{
    /* Loop forever */
	RCC_PARAMETER_t par;
	par.HSI_Activation=HSI_ON;
	par.Clk_Source=CLK_HSI;
	RCC_voidSysClkInt(par);
	RCC_voidEnablePerClk(RCC_APB2,2);
	RCC_voidEnablePerClk(RCC_APB2,3);
	LCD_Init();
	LCD_Create_Custom_Character(alf,0);
		LCD_Create_Custom_Character(_7a2,1);
		LCD_Create_Custom_Character(mem,2);
		LCD_Create_Custom_Character(dal,3);
		LCD_Create_Custom_Character(sen,4);
		LCD_Create_Custom_Character(sharta,5);
		LCD_Create_Custom_Character(_3en,6);
	while(1)
	{
		    LCD_Clear();
			LCD_Write_AtPosition(1,15);
			LCD_Write_Char(0);
			LCD_Write_AtPosition(1,14);
			LCD_Write_Char(1);
			LCD_Write_AtPosition(1,13);
			LCD_Write_Char(2);
			LCD_Write_AtPosition(1,12);
			LCD_Write_Char(3);
			LCD_Write_AtPosition(1,10);
			LCD_Write_Char(4);
			LCD_Write_AtPosition(1,9);
			LCD_Write_Char(5);
			LCD_Write_AtPosition(1,8);
			LCD_Write_Char(6);
			LCD_Write_AtPosition(1,7);
			LCD_Write_Char(3);
	}
	return 0 ;
}
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////
#if SCENARIO_7
#include"RCC_interface.h"
#include"LCD.h"
#include"keypad.h"

int main(void)
{
	u8 Local_u8KeyVal = 0xff;
    /* Loop forever */
	RCC_PARAMETER_t par;
	par.HSI_Activation=HSI_ON;
	par.Clk_Source=CLK_HSI;
	RCC_voidSysClkInt(par);
	RCC_voidEnablePerClk(RCC_APB2,2);
	RCC_voidEnablePerClk(RCC_APB2,3);
	LCD_Init();
	Keypad_Init();
	DIO_voidSetPinValue(PORTA, PIN0,GPIO_HIGH);
	DIO_voidSetPinValue(PORTA, PIN1,GPIO_HIGH);
	DIO_voidSetPinValue(PORTA, PIN2,GPIO_HIGH);
	DIO_voidSetPinValue(PORTA, PIN3,GPIO_HIGH);

	while(1)
	{
		Local_u8KeyVal = Keypad_GetPressedKey();
		if(Local_u8KeyVal != 0xff)
		{
			LCD_Write_Char(Local_u8KeyVal);
		}
		_delay_ms(1000);

	}
	return 0 ;
}
#endif
