/*
 * SPI_TRANS.c
 *
 * Created: 1/21/2022 9:33:16 PM
 * Author : Doha
 */ 

#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "I2C_interface.h"

int main(void)
{
	u8 I2C_Data;

	DIO_voidSetPinDirection(PORTA,PIN0,OUTPUT);
//	DIO_voidSetPinValue(PORTA,PIN0,HIGH);
	DIO_voidSetPinDirection(PORTA,PIN1,INPUT);
	DIO_voidSetPinValue(PORTA,PIN1,HIGH);
	
	I2C_Slave_voidInit(0x10);
	I2C_Error_State Error=I2C_OK;
	while (1)
	{
//		Error =I2C_Master_enuSendStartCond();
		I2C_Slave_voidListen();
		Error=I2C_Slave_enuReadu8Data(&I2C_Data);
//		if(Error==I2C_OK && DIO_u8GetPinValue(PORTA,PIN0)==1)
//		{
//			Error=I2C_Master_enuSendu8Data('H');
			DIO_voidSetPinValue(PORTA,PIN0,HIGH);
//		}
//		else if(Error==I2C_OK && DIO_u8GetPinValue(PORTA,PIN1)==0)
//		{
//			Error=I2C_Master_enuSendu8Data('L');
//		}
	}
}


