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