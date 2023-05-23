#include"RCC_interface.h"
#include"DIO_interface.h"
#include"NVIC_interface.h"
#include "led.h"
#include "SPI1_interface.h"
#include"DELAY.h"

u8 Rx =0;
extern u8 SPI1_TX_Flag,SPI1_RX_Flag;
void SPI_fun(void);

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
	NVIC_voidInit();
	NVIC_voidEnablePerInt(35);
	SPI1_voidSetCallBack(SPI_fun);
	SPI1_init();
	while(1)
	{

	}
	return 0 ;
}
void SPI_fun(void)
{
	if(SPI1_TX_Flag == 1)
	{
		Rx=SPI1_TX_RX_Char('A');
		SPI1_TX_Flag=0;
	}
	if(SPI1_RX_Flag == 1)
	{
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
		SPI1_RX_Flag=0;
	}
}

