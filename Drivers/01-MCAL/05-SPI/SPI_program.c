/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SPI_program.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"
#include "bit_math.h"

#include "led.h"
#include "dio.h"
#include "SPI_reg.h"
#include "SPI_int.h"
#include "SPI_config.h"
#include "SPI_priv.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
u8 *buffer = NULL;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void (*SPI_CallBackFunc)(void);

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void SPI_voidMasterInit(void)
{
	/*Make MOSI, SCK, and SS pins directions as output.*/
	dio_vidConfigChannel(SPI_PORT, SPI_SCK_PIN, OUTPUT);
	dio_vidConfigChannel(SPI_PORT, SPI_MOSI_PIN, OUTPUT);
	dio_vidConfigChannel(SPI_PORT, SPI_SS_PIN, OUTPUT);

	/*Make MISO pin direction as input*/
	dio_vidConfigChannel(SPI_PORT, SPI_MISO_PIN, INPUT);

	/*Make SS pin High*/
	dio_vidWriteChannel(SPI_PORT, SPI_SS_PIN, STD_HIGH);

	/*Enable SPI*/
	SET_BIT(SPCR, SPCR_SPE);

	/*Master mode*/
	SET_BIT(SPCR, SPCR_MSTR);

#if SPI_SCK_FREQ == SPI_CLK_DIVIDE_BY_4
	CLEAR_BIT(SPCR, SPCR_SPR0);
	CLEAR_BIT(SPCR, SPCR_SPR1);
	CLEAR_BIT(SPSR, SPSR_SPI2X);

#elif SPI_SCK_FREQ == SPI_CLK_DIVIDE_BY_16
	SET_BIT(SPCR, SPCR_SPR0);
	CLEAR_BIT(SPCR, SPCR_SPR1);
	CLEAR_BIT(SPSR, SPSR_SPI2X);

#elif SPI_SCK_FREQ == SPI_CLK_DIVIDE_BY_64
	CLEAR_BIT(SPCR, SPCR_SPR0);
	SET_BIT(SPCR, SPCR_SPR1);
	CLEAR_BIT(SPSR, SPSR_SPI2X);

#elif SPI_SCK_FREQ == SPI_CLK_DIVIDE_BY_128
	SET_BIT(SPCR, SPCR_SPR0);
	SET_BIT(SPCR, SPCR_SPR1);
	CLEAR_BIT(SPSR, SPSR_SPI2X);

#elif SPI_SCK_FREQ == SPI_CLK_DIVIDE_BY_2_2x
	CLEAR_BIT(SPCR, SPCR_SPR0);
	CLEAR_BIT(SPCR, SPCR_SPR1);
	SET_BIT(SPSR, SPSR_SPI2X);

#elif SPI_SCK_FREQ == SPI_CLK_DIVIDE_BY_8_2x
	SET_BIT(SPCR, SPCR_SPR0);
	CLEAR_BIT(SPCR, SPCR_SPR1);
	SET_BIT(SPSR, SPSR_SPI2X);

#elif SPI_SCK_FREQ == SPI_CLK_DIVIDE_BY_32_2x
	CLEAR_BIT(SPCR, SPCR_SPR0);
	SET_BIT(SPCR, SPCR_SPR1);
	SET_BIT(SPSR, SPSR_SPI2X);

#elif SPI_SCK_FREQ == SPI_CLK_DIVIDE_BY_64_2x
	SET_BIT(SPCR, SPCR_SPR0);
	SET_BIT(SPCR, SPCR_SPR1);
	SET_BIT(SPSR, SPSR_SPI2X);

#endif



}

u8 SPI_voidMasterSendByte(u8 data)
{
	dio_vidWriteChannel(SPI_PORT, SPI_SS_PIN, STD_LOW);			/*Enable slave select*/
	u8 buffer;
	SPDR = data;							/* Write data to SPI data register */
//	while(0 == CHECK_BIT(SPSR, SPSR_SPIF));		/* Wait till transmission complete */
//	buffer = SPDR;							/* Recieve data from slave */
//	dio_vidWriteChannel(SPI_PORT, SPI_SS_PIN, STD_HIGH);		/*Disable slave select*/
	return buffer;
}

u8 SPI_u8MasterRecieveByte(void)
{
	u8 buffer;
	dio_vidWriteChannel(SPI_PORT, SPI_SS_PIN, STD_LOW);			/*Enable slave select*/
	SPDR = DUMMY_DATA;						/* Write dummy data to SPI data register */
	while(0 == CHECK_BIT(SPSR, SPSR_SPIF));		/* Wait till transmission complete */
	buffer = SPDR;
//	dio_vidWriteChannel(SPI_PORT, SPI_SS_PIN, STD_HIGH);		/*Disable slave select*/
	return buffer;
}


void SPI_voidSlaveInit(void)
{
	/*Make MOSI, SCK, and SS pins directions as input.*/
	dio_vidConfigChannel(SPI_PORT, SPI_SCK_PIN, INPUT);
	dio_vidConfigChannel(SPI_PORT, SPI_MOSI_PIN, INPUT);
	dio_vidConfigChannel(SPI_PORT, SPI_SS_PIN, INPUT);

	dio_vidWriteChannel(SPI_PORT, SPI_SS_PIN, STD_HIGH);

	/*Make MISO pin direction as output*/
	dio_vidConfigChannel(SPI_PORT, SPI_MISO_PIN, OUTPUT);

	/*Enable SPI*/
	SET_BIT(SPCR, SPCR_SPE);

	/*Slave mode*/
	CLEAR_BIT(SPCR, SPCR_MSTR);
}

u8 SPI_voidSlaveSendByte(u8 data)
{
	u8 buffer;
	SPDR = data;							/* Write data to SPI data register */
//	while(0 == CHECK_BIT(SPSR, SPSR_SPIF));		/* Wait till transmission complete */
//	buffer = SPDR;							/* Recieve data from slave */
	return buffer;
}

u8 SPI_u8SlaveRecieveByte(void)
{
	while(0 == CHECK_BIT(SPSR, SPSR_SPIF));		/* Wait till transmission complete */
	return SPDR;
}

void SPI_voidEnableInterrupt(void)
{
	SET_BIT(SPCR, SPCR_SPIE);
}

void SPI_voidSPICallBackFunc(void (*Copy_ptrFunc)(void), u8 *buff)
{
	if(Copy_ptrFunc != NULL)
	{
		SPI_CallBackFunc = Copy_ptrFunc;
		buffer = buff;
	}
}

void __vector_12(void)
{
	*buffer = SPDR;
	SPI_CallBackFunc();
//	dio_vidWriteChannel(SPI_PORT, SPI_SS_PIN, STD_HIGH);		/*Disable slave select*/
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
