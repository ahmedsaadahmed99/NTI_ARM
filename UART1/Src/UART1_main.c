#include"RCC_interface.h"
#include"DIO_interface.h"
#include"NVIC_interface.h"
#include "led.h"
#include "UART1_interface.h"
#include"DELAY.h"

u8 Rx =0;
extern u8 TX_Flag,RX_Flag;
void fun(void);

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
	NVIC_voidInit();
	NVIC_voidEnablePerInt(37);
	UART1_enableTX();
	UART1_enableRX();
	UART1_voidSetCallBack(fun);
	UART1_init();
	while(1)
	{

	}
	return 0 ;
}
void fun(void)
{
	if(TX_Flag == 1)
	{
		UART1_TXdata('A');
		TX_Flag=0;
	}
	if(RX_Flag == 1)
	{
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
		RX_Flag=0;
	}
}
