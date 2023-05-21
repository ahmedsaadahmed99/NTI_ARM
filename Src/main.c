#define SCENARIO_1	  0  // LED TOGGLING USING DIO
#define SCENARIO_2	  0  // LED TOGGLING USING LED DRIVER
#define SCENARIO_3	  0  // LED ACTIVATION USING SWITCH
#define SCENARIO_4	  0  // BUZZER ACTIVATION
#define SCENARIO_5	  0  // WRITE CHARACTER IN LCD
#define SCENARIO_6    0 // MY ARABIC NAME
#define SCENARIO_7    0 // WRITING ON LCD USING KEYPAD
#define SCENARIO_8    0 // LED TOGGLING USING EXT_INT
#define SCENARIO_9    0 // LED TOGGLING USING HEAVY WAIT IN SYSTICK
#define SCENARIO_10   0 // LED TOGGLING USING SINGLE INTERVAL IN SYSTICK
#define SCENARIO_11   0 // LED TOGGLING USING PERIOD INTERVAL IN SYSTICK
#define SCENARIO_12   0 // water level project
#define SCENARIO_13   1 // UART
#define SCENARIO_14   0 // SPI
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
////////////////////////////////////////////////////////////////////////////////////////////////////
#if SCENARIO_8
#include"RCC_interface.h"
#include"DIO_interface.h"
#include"led.h"
#include"NVIC_interface.h"
#include"EXTI_interface.h"
#include"Delay.h"

void	fun(void);
int main(void)
{
    /* Loop forever */
	RCC_PARAMETER_t par;
	par.HSI_Activation=HSI_ON;
	par.Clk_Source=CLK_HSI;
	RCC_voidSysClkInt(par);
	RCC_voidEnablePerClk(RCC_APB2,0);
	RCC_voidEnablePerClk(RCC_APB2,2);
	LED_init(PORTA, PIN0);
	DIO_voidSetPinValue(PORTA, PIN15,GPIO_LOW);
	NVIC_voidInit();
	EXTI_voidInit(EXTI15,EXTI_PORTA);
	EXTI_voidChangeSenseMode(EXTI15,RISING_EDGE);
	NVIC_voidEnablePerInt(40);
	EXTI15_voidSetCallBack(fun);
	while(1)
	{


	}
	return 0 ;
}

void	fun(void)
{
		/*		Led On		*/
		LED_on(PORTA, PIN0);
		_delay_ms(1000);
		/*		Led Off		*/
		LED_off(PORTA, PIN0);

	/*	Clear EXTI0 Flag	*/
}

#endif
////////////////////////////////////////////////////////////////////////////////////////////////////
#if SCENARIO_9
#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include	"STK_interface.h"


/*	C13 ==> Built in led (Toggle Led)		*/
int main()
{
	/*	System Clock Init			*/
	RCC_PARAMETER_t par;
		par.HSI_Activation=HSI_ON;
		par.Clk_Source=CLK_HSI;
		RCC_voidSysClkInt(par);
	/*	Enable RCC for GPIOC 		*/
		RCC_voidEnablePerClk(RCC_APB2,4);
	/*	C13 Direction 	"Output @ 2MHz Push Pull"	*/
	DIO_voidSetPinDirection(PORTC,PIN13,GPIO_OUTPUT_2MHZ_PP);
	/*	SysTick	Init				*/
	STK_voidInit();
	while(1)
	{
		/*		Led On		*/
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
		STK_voidSetBusyWait(1000000);
		/*		Led Off		*/
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
		STK_voidSetBusyWait(1000000);
	}
	return 0;
}
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////
#if SCENARIO_10
#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include	"STK_interface.h"


void	ToggleLed(void)
{
	static	u8 flag	=	0;
	if(flag	==	0)
	{
		/*		Led On		*/
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
		flag	=	1;
	}
	else
	{
		/*		Led Off		*/
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
		flag	=	0;
	}
}

/*	C13 ==> Built in led (Toggle Led)		*/
int main()
{
	RCC_PARAMETER_t par;
			par.HSI_Activation=HSI_ON;
			par.Clk_Source=CLK_HSI;
			RCC_voidSysClkInt(par);
		/*	Enable RCC for GPIOC 		*/
			RCC_voidEnablePerClk(RCC_APB2,4);
	/*	C13 Direction 	"Output @ 2MHz Push Pull"	*/
	DIO_voidSetPinDirection(PORTC,PIN13,GPIO_OUTPUT_2MHZ_PP);
	/*	SysTick	Init				*/
	STK_voidInit();
	/*	Call Single Interval 		*/
	/*	LED ON in the CallBack		*/
	STK_voidSetIntervalSingle(1000000, ToggleLed);
	/*	LED OFF in the CallBack		*/
	STK_voidSetBusyWait(2000000);
	STK_voidSetIntervalSingle(1000000, ToggleLed);

	while(1)
	{

	}
	return 0;
}
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////
#if SCENARIO_11
#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include	"STK_interface.h"

void	ToggleLed(void)
{
	static	u8 flag	=	0;
	if(flag	==	0)
	{
		/*		Led On		*/
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
		flag	=	1;
	}
	else
	{
		/*		Led Off		*/
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
		flag	=	0;
	}
}

/*	C13 ==> Built in led (Toggle Led)		*/
int main()
{
	RCC_PARAMETER_t par;
	par.HSI_Activation=HSI_ON;
	par.Clk_Source=CLK_HSI;
	RCC_voidSysClkInt(par);
	/* Enable RCC for GPIOC 		*/
	RCC_voidEnablePerClk(RCC_APB2,4);
	/* C13 Direction 	"Output @ 2MHz Push Pull"	*/
	DIO_voidSetPinDirection(PORTC,PIN13,GPIO_OUTPUT_2MHZ_PP);
	/*	SysTick	Init				*/
	STK_voidInit();
	/*	Call Single Periodic 		*/
	STK_voidSetIntervalPeriodic(1000000, ToggleLed);
	while(1)
	{

	}
	return 0;
}
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////
#if SCENARIO_12
#include"RCC_interface.h"
#include"DIO_interface.h"
#include "led.h"
#include "buzzer.h"
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
	//BUZZER_Init(PORTA, PIN2);
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

}
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////
#if SCENARIO_13
#include"RCC_interface.h"
#include"DIO_interface.h"
#include "led.h"
#include "UART1_interface.h"
#include"DELAY.h"

int main(void)
{
    /* Loop forever */
	RCC_PARAMETER_t par;
	par.HSI_Activation=HSI_ON;
	par.Clk_Source=CLK_HSI;
	RCC_voidSysClkInt(par);
	RCC_voidEnablePerClk(RCC_APB2,2);//port A
	RCC_voidEnablePerClk(RCC_APB2,14);//UART
	RCC_voidEnablePerClk(RCC_APB2,0);//AF
	LED_init(PORTA,PIN0); //LED0
	DIO_voidSetPinDirection(PORTA,PIN9,GPIO_OUTPUT_2MHZ_AFPP); // TX
	DIO_voidSetPinDirection(PORTA,PIN10,GPIO_INPUT_FLOAT); //RX
	LED_off(PORTA,PIN0);
	UART1_init();
	UART1_enableTX();
	UART1_enableRX();
	while(1)
	{
		UART1_TXdata('A');
		u8 Rx =0;
		UART1_RXdata(&Rx);
		if(Rx == 'A')
		{
			LED_on(PORTA, PIN0);
			_delay_ms(1000000);
		}
		else
		{
			LED_off(PORTA, PIN0);
			_delay_ms(1000000);
		}
	}
	return 0 ;

}
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////
#if SCENARIO_14
#include"RCC_interface.h"
#include"DIO_interface.h"
#include "led.h"
#include "SPI1_interface.h"
#include"DELAY.h"

int main(void)
{
    /* Loop forever */
	RCC_PARAMETER_t par;
	par.HSI_Activation=HSI_ON;
	par.Clk_Source=CLK_HSI;
	RCC_voidSysClkInt(par);
	RCC_voidEnablePerClk(RCC_APB2,2);//port A
	RCC_voidEnablePerClk(RCC_APB2,12);//SPI1
	RCC_voidEnablePerClk(RCC_APB2,0);//AF
	LED_init(PORTA,PIN0); //LED0
	DIO_voidSetPinDirection(PORTA,PIN7,GPIO_OUTPUT_2MHZ_AFPP); // MOSI OUTPUT
	DIO_voidSetPinDirection(PORTA,PIN6,GPIO_INPUT_FLOAT); // MISO INPUT
	DIO_voidSetPinDirection(PORTA,PIN5,GPIO_OUTPUT_2MHZ_AFPP); //CLK OUTPUT
	DIO_voidSetPinDirection(PORTA,PIN4,GPIO_OUTPUT_2MHZ_AFPP); //SS OUTPUT
	LED_off(PORTA,PIN0);
	SPI1_init();
	while(1)
	{
		u8 Rx =0;
		Rx=SPI1_TX_RX_Char('A');
		if(Rx != 'A')
		{
			LED_on(PORTA, PIN0);
			_delay_ms(1000000);
		}
		else
		{
			LED_off(PORTA, PIN0);
			_delay_ms(1000000);
		}
	}
	return 0 ;

}
#endif
