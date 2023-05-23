#include "Std_Types.h"
#include "Bit_Math.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "LEDMRX_interface.h"

volatile u8  u8StartFlag      =0;
volatile u32 u32FrameData[50] ={0};
volatile u8  u32EdgeCounter    =0;
volatile u8  u8Data      	   =0;

void voidPlay(void)
{
	switch(u8Data)
	{
	case 70:DIO_voidSetPinValue(PORTA, PIN1,GPIO_HIGH); break;
	case 69:DIO_voidSetPinValue(PORTA, PIN1,GPIO_LOW);  break;
	default:break;
	}
}
void voidTakeAction(void)
{
	u8 i ;
	u8Data=0;
	if( (u32FrameData[0] >= 10000) && (u32FrameData[0] <= 14000) )
	{
		for(i=0;i<8;i++)
		{
			if( (u32FrameData[17+i] >= 2000) && (u32FrameData[17+i] <= 2300) )
			{
				SET_BIT(u8Data,i);
			}
			else
			{
				CLR_BIT(u8Data,i);
			}
		}
		voidPlay();
	}
	else
	{
		/*Invalid Frame*/
	}
	u8StartFlag		=0;
	u32EdgeCounter	=0;
	u32FrameData[0] =0;
}

void voidGetFrame(void)
{
	if(u8StartFlag==0)
	{
		/*Start Timer*/
		STK_voidSetIntervalSingle( 1000000,voidTakeAction);
		u8StartFlag =1;
	}
	else
	{
		u32FrameData[u32EdgeCounter]= STK_u32GetElapsedTime();
		STK_voidSetIntervalSingle(1000000,voidTakeAction);
		u32EdgeCounter++;
	}
}

void main(void)
{
	/*RCC Initialization*/
	RCC_PARAMETER_t par;
	par.HSI_Activation=HSI_ON;
	par.Clk_Source=CLK_HSI;
	RCC_voidSysClkInt(par);
	RCC_voidEnablePerClk(RCC_APB2,2);	/*GPIOA Enable Clock*/

	/*IO Pin Initialization*/
	DIO_voidSetPinDirection(PORTA,PIN0,GPIO_INPUT_FLOAT);		/*INPUT FLOATING*/
	DIO_voidSetPinDirection(PORTA,PIN1,GPIO_OUTPUT_2MHZ_PP); 	/*OUTPUT 2 MHZ PUSH PULL*/
	DIO_voidSetPinDirection(PORTA,PIN2,GPIO_OUTPUT_2MHZ_PP);	/*OUTPUT 2 MHZ PUSH PULL*/
	DIO_voidSetPinDirection(PORTA,PIN3,GPIO_OUTPUT_2MHZ_PP);	/*OUTPUT 2 MHZ PUSH PULL*/

	/*EXTI Initialization*/
	EXTI0_voidSetCallBack(voidGetFrame);
	EXTI_voidInit(EXTI0,EXTI_PORTA);
	EXTI_voidChangeSenseMode(EXTI0,FALLING_EDGE);	/*A0 EXTI0 Enable / FALLING_EDGE*/

	/*Enable EXTI0 from NVIC*/
	NVIC_voidInit();
	NVIC_voidEnablePerInt(6);

	/*SysTick Initialization */
	STK_voidInit();												/*Enable SysTicK AHB/8=1MHZ*/


	while(1)
	{
	}




}