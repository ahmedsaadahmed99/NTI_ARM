#define SCENARIO_1	  0  // LED TOGGLING USING HEAVY WAIT IN SYSTICK
#define SCENARIO_2	  0  // LED TOGGLING USING SINGLE INTERVAL IN SYSTICK
#define SCENARIO_3	  0  // LED TOGGLING USING PERIOD INTERVAL IN SYSTICK

////////////////////////////////////////////////////////////////////////////////////////////////////
#if SCENARIO_1
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
#if SCENARIO_2
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
#if SCENARIO_3
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