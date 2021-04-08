#include"STD_TYPES.h"
#include"bit.h"
#include"I2C_Register.h"
void I2C_VidInitMaster(void)
{
	TWBR=32; //I2C speed=100khz
	clr_bit(TWSR,0);
	clr_bit(TWSR,1);
	set_bit(TWCR,2);//Enable I2C
}

void I2C_VidInitSlave(void)
{
	TWAR=0b00000010;//address slave
	set_bit(TWCR,2);//Enable I2C
}

void I2C_StartCondition(void)
{
	set_bit(TWCR,5);//set start
	set_bit(TWCR,7);//clr flag
	//wait until flag is set
	while((get_bit(TWCR,7))==0);
}

void I2C_StopCondition(void)
{
	set_bit(TWCR,4);//stop bit
	set_bit(TWCR,7);//clr flag
}

void I2C_SendSlaveAddressWith_Write(u8 address)
{
	TWDR=(address<<1);//set slave address
	clr_bit(TWCR,5);//clr start
	set_bit(TWCR,7);//clr flag
	while((get_bit(TWCR,7))==0);
}

void I2C_SendSlaveAddressWith_Read(u8 address)
{
	TWDR=(address<<1);//set slave address
	set_bit(TWDR,0);
	clr_bit(TWCR,5);//clr start
	set_bit(TWCR,7);//clr flag
	while((get_bit(TWCR,7))==0);
}
void I2C_SendSlaveDataWith_Write(u8 data)
{
TWDR=data;
	set_bit(TWCR,7);//clr flag
	while((get_bit(TWCR,7))==0);	
}

void I2C_SendSlaveDataWith_Read(u8 *data)
{
	set_bit(TWCR,7);//clr flag
	while((get_bit(TWCR,7))==0);
	*data=TWDR;
}
