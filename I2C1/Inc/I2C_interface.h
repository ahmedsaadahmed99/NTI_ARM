#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

void 		I2C_init(void);
void 	    I2C_startCond(void);
void 		I2C_SelectAddress(u8 address);
void 		I2C_Write_Byte(u8 data);
void 		I2C_Read_Byte(u8 *data);
void 		I2C_stopCondition(void);



#endif
