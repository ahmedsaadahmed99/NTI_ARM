/*****************************************/
/* Author  :  Ahmed Assaf                */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/
#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_interface.h"
#include "STK_interface.h"


#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

void HLEDMRX_voidInit(void)
{
	 DIO_voidSetPinDirection(PORTA,LEDMRX_ROW0_PIN ,GPIO_OUTPUT_2MHZ_PP);
 	 DIO_voidSetPinDirection(PORTA,LEDMRX_ROW1_PIN ,GPIO_OUTPUT_2MHZ_PP);
	 DIO_voidSetPinDirection(PORTA,LEDMRX_ROW2_PIN ,GPIO_OUTPUT_2MHZ_PP);
	 DIO_voidSetPinDirection(PORTA,LEDMRX_ROW3_PIN ,GPIO_OUTPUT_2MHZ_PP);
	 DIO_voidSetPinDirection(PORTA,LEDMRX_ROW4_PIN ,GPIO_OUTPUT_2MHZ_PP);
	 DIO_voidSetPinDirection(PORTA,LEDMRX_ROW5_PIN ,GPIO_OUTPUT_2MHZ_PP);
	 DIO_voidSetPinDirection(PORTA,LEDMRX_ROW6_PIN ,GPIO_OUTPUT_2MHZ_PP);
	 DIO_voidSetPinDirection(PORTA,LEDMRX_ROW7_PIN ,GPIO_OUTPUT_2MHZ_PP);
	 DIO_voidSetPinDirection(LEDMRX_COL0_PIN ,GPIO_OUTPUT_2MHZ_PP);
 	 DIO_voidSetPinDirection(LEDMRX_COL1_PIN ,GPIO_OUTPUT_2MHZ_PP);
	 DIO_voidSetPinDirection(LEDMRX_COL2_PIN ,GPIO_OUTPUT_2MHZ_PP);
	 DIO_voidSetPinDirection(LEDMRX_COL3_PIN ,GPIO_OUTPUT_2MHZ_PP);
	 DIO_voidSetPinDirection(LEDMRX_COL4_PIN ,GPIO_OUTPUT_2MHZ_PP);
	 DIO_voidSetPinDirection(LEDMRX_COL5_PIN ,GPIO_OUTPUT_2MHZ_PP);
	 DIO_voidSetPinDirection(LEDMRX_COL6_PIN ,GPIO_OUTPUT_2MHZ_PP);
	 DIO_voidSetPinDirection(LEDMRX_COL7_PIN ,GPIO_OUTPUT_2MHZ_PP);
}
void HLEDMRX_voidDisplay(u8 *Copy_u8Data)
{	while(1)
	{
		/*Column 0*/
		/*Disable all column*/
	DisableAllColomns();
	SetRowValues(Copy_u8Data[0]);
		/*Enable  column 0*/
	DIO_voidSetPinValue(LEDMRX_COL0_PIN,GPIO_LOW);
	STK_voidSetBusyWait( 2500 ); /*2.5 ms*/
	
			/*Column 1*/
		/*Disable all column*/
	DisableAllColomns();
	SetRowValues(Copy_u8Data[1]);
		/*Enable  column 0*/
	DIO_voidSetPinValue(LEDMRX_COL1_PIN,GPIO_LOW);
	STK_voidSetBusyWait( 2500 ); /*2.5 ms*/
	
	/*Column 2*/
		/*Disable all column*/
	DisableAllColomns();
	SetRowValues(Copy_u8Data[2]);
		/*Enable  column 0*/
	DIO_voidSetPinValue(LEDMRX_COL2_PIN,GPIO_LOW);
	STK_voidSetBusyWait( 2500 ); /*2.5 ms*/
	
			/*Column 3*/
		/*Disable all column*/
	DisableAllColomns();
	SetRowValues(Copy_u8Data[3]);
		/*Enable  column 0*/
	DIO_voidSetPinValue(LEDMRX_COL3_PIN ,GPIO_LOW);
	STK_voidSetBusyWait( 2500 ); /*2.5 ms*/
	
	/*Column 4*/
		/*Disable all column*/
	DisableAllColomns();
	SetRowValues(Copy_u8Data[4]);
		/*Enable  column 4*/
	DIO_voidSetPinValue(LEDMRX_COL4_PIN ,GPIO_LOW);
	STK_voidSetBusyWait( 2500 ); /*2.5 ms*/
	
			/*Column 5*/
		/*Disable all column*/
	DisableAllColomns();
	SetRowValues(Copy_u8Data[5]);
		/*Enable  column 0*/
	DIO_voidSetPinValue(LEDMRX_COL5_PIN ,GPIO_LOW);
	STK_voidSetBusyWait( 2500 ); /*2.5 ms*/
	
	/*Column 6*/
		/*Disable all column*/
	DisableAllColomns();
	SetRowValues(Copy_u8Data[6]);
		/*Enable  column 0*/
	DIO_voidSetPinValue(LEDMRX_COL6_PIN ,GPIO_LOW);
	STK_voidSetBusyWait( 2500 ); /*2.5 ms*/
	
			/*Column 7*/
		/*Disable all column*/
	DisableAllColomns();
	SetRowValues(Copy_u8Data[7]);
		/*Enable  column 0*/
	DIO_voidSetPinValue(LEDMRX_COL7_PIN ,GPIO_LOW);
	STK_voidSetBusyWait( 2500 ); /*2.5 ms*/
	}
	
	
	

	
}
static void DisableAllColomns(void)
{
	/*Disable all column*/
	DIO_voidSetPinValue(LEDMRX_COL0_PIN ,GPIO_HIGH);
	DIO_voidSetPinValue(LEDMRX_COL1_PIN ,GPIO_HIGH);
	DIO_voidSetPinValue(LEDMRX_COL2_PIN ,GPIO_HIGH);
	DIO_voidSetPinValue(LEDMRX_COL3_PIN ,GPIO_HIGH);
	DIO_voidSetPinValue(LEDMRX_COL4_PIN ,GPIO_HIGH);
	DIO_voidSetPinValue(LEDMRX_COL5_PIN ,GPIO_HIGH);
	DIO_voidSetPinValue(LEDMRX_COL6_PIN ,GPIO_HIGH);
	DIO_voidSetPinValue(LEDMRX_COL7_PIN ,GPIO_HIGH);
	
}

static void SetRowValues(u8 Copy_u8Value)
{	u8 Local_u8BIT;
	Local_u8BIT=GET_BIT(Copy_u8Value,0);
	DIO_voidSetPinValue(PORTA,LEDMRX_ROW0_PIN,Local_u8BIT);

	Local_u8BIT=GET_BIT(Copy_u8Value,1);
	DIO_voidSetPinValue(PORTA,LEDMRX_ROW1_PIN,Local_u8BIT);
	Local_u8BIT=GET_BIT(Copy_u8Value,2);
	DIO_voidSetPinValue(PORTA,LEDMRX_ROW2_PIN,Local_u8BIT);
	Local_u8BIT=GET_BIT(Copy_u8Value,3);
	DIO_voidSetPinValue(PORTA,LEDMRX_ROW3_PIN,Local_u8BIT);
	Local_u8BIT=GET_BIT(Copy_u8Value,4);
	DIO_voidSetPinValue(PORTA,LEDMRX_ROW4_PIN,Local_u8BIT);
	Local_u8BIT=GET_BIT(Copy_u8Value,5);
	DIO_voidSetPinValue(PORTA,LEDMRX_ROW5_PIN,Local_u8BIT);
	Local_u8BIT=GET_BIT(Copy_u8Value,6);
	DIO_voidSetPinValue(PORTA,LEDMRX_ROW6_PIN,Local_u8BIT);
	Local_u8BIT=GET_BIT(Copy_u8Value,7);
	DIO_voidSetPinValue(PORTA,LEDMRX_ROW7_PIN,Local_u8BIT);

}
