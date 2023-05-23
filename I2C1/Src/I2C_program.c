#include "Std_Types.h"
#include "Bit_Math.h"
#include "I2C_private.h"
#include "I2C_interface.h"
#include "I2C_config.h"
#include "DELAY.h"

void I2C_enable_pe(void);
void I2C_reset_pe(void);
void I2C_disable_pe(void);
void I2C_init(void)
{
	I2C_disable_pe(); //I2C DISABLE
	//I2C RESET
	I2C_reset_pe();
	I2C1->CR2 |= 8;
	I2C1->CCR |= 0x28;
	I2C1->TRISE |= 9;
	I2C_enable_pe(); //I2C ENABLE
}
void I2C_startCond(void)
{
	SET_BIT(I2C1->CR1,10); //ENABLE ACK
	SET_BIT(I2C1->CR1,8);  // GENERATE START CONDITION
	while (!(GET_BIT(I2C1->SR1,0))); // WAIT UNTIL GENERATING START CONDITION
}

void I2C_SelectAddress(u8 address)
{
	 u8 temp=0;
	I2C1->DR = address;  // sending address
	while (!(GET_BIT(I2C1->SR1,1))); // WAIT UNTIL ADDRESS SENT
	temp = I2C1->SR1 | I2C1->SR2;
}

void I2C_Write_Byte(u8 data)
{
	while (!(GET_BIT(I2C1->SR1,7)));  // WAIT FOR DATA REGISTER BE EMPTY TX
	I2C1->DR = data; //SEND DATA
	while (!(GET_BIT(I2C1->SR1,2)));  // WAIT UNTIL DATA TRANSFER IS FINISHED
}


void I2C_Read_Byte(u8 *data){

	while (!(GET_BIT(I2C1->SR1,6))); // WAIT FOR DATA REGISTER BE EMPTY RX
	*data = I2C1->DR; //RECIEVE DATA
}


void I2C_stopCondition(void)
{
	SET_BIT(I2C1->CR1,9);
	while (!(GET_BIT(I2C1->SR1,4))); //WAIT UNTIL GENERATING STOP CONDITION
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
