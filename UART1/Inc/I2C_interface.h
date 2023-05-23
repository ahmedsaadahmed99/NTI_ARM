#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

void 		I2C_init(void);
void 		I2C_start(void);
void 		I2C_add_select(u8 address);
void 		I2C_Write_Byte(u8 data);
void 		I2C_Read_Byte(u8 *data);
void 		I2C_stop(void);
void 		I2C_disable_pe(void);
void 		I2C_reset_pe(void);
void 		I2C_enable_pe(void);




#define		READ							0
#define		WRITE							1

#define		ENABLED							0
#define		DISABLED						1


#endif
