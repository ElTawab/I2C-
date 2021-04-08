#ifndef I2C_Interface_H_
#define I2C_Interface_H_
void I2C_VidInitMaster(void);
void I2C_VidInitSlave(void);
void I2C_StartCondition(void);
void I2C_SendSlaveAddressWith_Write(u8 address);
void I2C_SendSlaveAddressWith_Read(u8 address);
void I2C_SendSlaveDataWith_Write(u8 data);
void I2C_SendSlaveDataWith_Read(u8 *data);
#endif