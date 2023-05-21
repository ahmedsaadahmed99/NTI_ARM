#include "Std_Types.h"
#include "Bit_Math.h"
#include "I2C_private.h"
#include "I2C_interface.h"
#include "I2C_config.h"


void I2C_init(void)
{
	I2C1->CR2 |= 8;
	I2C1->CCR |= 0x28;
	I2C1->TRISE |= 9;
	SET_BIT(I2C1->CR1,0);

}
void I2C_start(void)
{
	SET_BIT(I2C1->CR1,10);
	SET_BIT(I2C1->CR1,8);
	while (!(I2C1->SR1 & (1<<0)));
}

void I2C_add_select(u8 address)
{
	I2C1->DR = address;
	while (!(I2C1->SR1 & (1<<1)));
	u8 temp = I2C1->SR1 | I2C1->SR2;
}

void I2C_Write_Byte(u8 data)
{
	while (!(I2C1->SR1 & (1<<7)));  // wait for TXE bit to set
	I2C1->DR = data;
	while (!(I2C1->SR1 & (1<<2)));  // wait for BTF bit to set

}


void I2C_Read_Byte(u8 *data){

	while (!(I2C1->SR1 & (1<<6)));
	*data = I2C1->DR;
}


void I2C_stop(void)
{
	SET_BIT(I2C1->CR1,9);
}
void I2C_disable_pe(void){
	CLR_BIT(I2C1->CR1,0);
}
void I2C_reset_pe(void){
	SET_BIT(I2C1->CR1,15);
	CLR_BIT(I2C1->CR1,15);
}
void I2C_enable_pe(void){
	SET_BIT(I2C1->CR1,0);
}
