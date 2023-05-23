#include "Std_Types.h"
#include "Bit_Math.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "I2C_interface.h"
#include "DELAY.h"

int main()
{
	u8 flag=0;
	u8 Tx_Data[6] = "AHMED";
	u8 Rx_Data[6]  = {0};
	u8 EEPROM_Address = 0b10100000;
	RCC_PARAMETER_t par;
	par.HSI_Activation=HSI_ON;
	par.Clk_Source=CLK_HSI;
	RCC_voidSysClkInt(par);
	RCC_voidEnablePerClk(RCC_APB2,2);//port A
	RCC_voidEnablePerClk(RCC_APB2,3);//port B
	RCC_voidEnablePerClk(RCC_APB2,4);//port C
	RCC_voidEnablePerClk(RCC_APB2,21);//I2C
	RCC_voidEnablePerClk(RCC_APB2,0);// AF
	DIO_voidSetPinDirection(PORTB,PIN6,GPIO_OUTPUT_2MHZ_AFOD); //CLK OUTPUT "Alternate Function Open Drain"
	DIO_voidSetPinDirection(PORTB,PIN7,GPIO_OUTPUT_2MHZ_AFOD); //SDA OUTPUT "Alternate Function Open Drain"
	DIO_voidSetPinDirection(PORTA, PIN0,GPIO_OUTPUT_2MHZ_PP); //LED0
	/* Make Pull Up in Hardware Connections for both SCL and SDA */
	I2C_init();
	//Sending the Data to EEPROM
	I2C_startCond();
	I2C_SelectAddress(EEPROM_Address);
	I2C_Write_Byte(0x000);
	/* Send Data */
	for(int i = 0;i < 6; i++)
	{
		I2C_Write_Byte(Tx_Data[i]);
	}
	I2C_stopCondition();
	//Receiving the Data from EEPROM
	I2C_startCond();
	I2C_SelectAddress(EEPROM_Address);
	I2C_Write_Byte(0x000);
	I2C_startCond();
	I2C_SelectAddress(EEPROM_Address+1);
	for(int i = 1;i < 6; i++)
	{
		I2C_Read_Byte(&Rx_Data[i]);
	}
	I2C_Read_Byte(&Rx_Data[0]);
	I2C_stopCondition();
	/* A0 Direction "Push Pull Output" for Led */
	while (1)
	{
		/* Comparing between Transmitted Data and Received Data */
		for(int i = 0;i < 6; i++)
		{
			if(Rx_Data[i] == Tx_Data[i])
			{
				flag=1;
			}
			else
			{
				flag=0;
			}
		}

		if(flag ==1)
		{
			DIO_voidSetPinValue(PORTA, PIN0,GPIO_HIGH);
			_delay_ms(1000);
		}
		else if(flag == 0)
		{
			DIO_voidSetPinValue(PORTA, PIN0,GPIO_LOW);
			_delay_ms(1000);
		}
	}
	return 0;
}