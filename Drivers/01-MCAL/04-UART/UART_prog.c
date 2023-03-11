/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  uart.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "UART_int.h"

#include "led.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
buffer buff;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void (*UART_TX_CallBack)(void);

/******************************************************************************
* \Syntax          : void UART_Init(u16 baudRate)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : baudRate   UART baudrate
* \Return value:   : None
*******************************************************************************/
void UART_Init(u16 baudRate)
{
	/* Set baud rate */
	UBRRL = (u8)baudRate;
	UBRRH = (u8)(baudRate>>8);

	 /* Enable receiver and transmitter */
	SET_BIT(UCSRB,UCSRB_RXEN);  /* Enable Receiver*/
	SET_BIT(UCSRB,UCSRB_TXEN);  /* Enable Transmitter */

	/* Set frame format: 8data, 1stop bit, Even Parity */

	/*Set URSEL bit to 1 to select register UCSRC*/
	SET_BIT(UCSRC, UCSRC_URSEL);


	/*select the data size*/
#if UART_CHAR_SIZE == UART_CHAR_SIZE_5_BIT
	CLEAR_BIT(UCSRC, UCSRC_UCSZ0);
	CLEAR_BIT(UCSRC, UCSRC_UCSZ1);
	CLEAR_BIT(UCSRB, UCSRB_UCSZ2);

#elif UART_CHAR_SIZE == UART_CHAR_SIZE_6_BIT
	SET_BIT(UCSRC, UCSRC_UCSZ0);
	CLEAR_BIT(UCSRC, UCSRC_UCSZ1);
	CLEAR_BIT(UCSRB, UCSRB_UCSZ2);

#elif UART_CHAR_SIZE == UART_CHAR_SIZE_7_BIT
	CLEAR_BIT(UCSRC, UCSRC_UCSZ0);
	SET_BIT(UCSRC, UCSRC_UCSZ1);
	CLEAR_BIT(UCSRB, UCSRB_UCSZ2);

#elif UART_CHAR_SIZE == UART_CHAR_SIZE_8_BIT
	SET_BIT(UCSRC, UCSRC_UCSZ0);
	SET_BIT(UCSRC, UCSRC_UCSZ1);
	CLEAR_BIT(UCSRB, UCSRB_UCSZ2);

#elif UART_CHAR_SIZE == UART_CHAR_SIZE_9_BIT
	SET_BIT(UCSRC, UCSRC_UCSZ0);
	SET_BIT(UCSRC, UCSRC_UCSZ1);
	SET_BIT(UCSRB, UCSRB_UCSZ2);

#endif

	/*set the frame parity mode*/
#if UART_PARITY_MODE == DISABLED
	 CLEAR_BIT(UCSRC, UCSRC_UPM0);
	 CLEAR_BIT(UCSRC, UCSRC_UPM1);

#elif UART_PARITY_MODE == UART_PARITY_EVEN
	 CLEAR_BIT(UCSRC, UCSRC_UPM0);
	 SET_BIT(UCSRC, UCSRC_UPM1);

#elif UART_PARITY_MODE == UART_PARITY_ODD
	 SET_BIT(UCSRC, UCSRC_UPM0);
	 SET_BIT(UCSRC, UCSRC_UPM1);

#endif

	 /*set stop bit 1 or 2*/
#if UART_STOP_BIT_SELECT == UART_STOP_BIT_1
	 CLEAR_BIT(UCSRC, UCSRC_USBS);

#elif UART_STOP_BIT_SELECT == UART_STOP_BIT_2
	 SET_BIT(UCSRC, UCSRC_USBS);

#endif

	 /*set RX interrupt*/
#if UART_RX_INT == DISABLED
	 CLEAR_BIT(UCSRB, UCSRB_RXCIE);

#elif UART_RX_INT == ENABLED
	 SET_BIT(UCSRB, UCSRB_RXCIE);

#endif

	 /*set TX interrupt*/
#if UART_TX_INT == DISABLED
	 CLEAR_BIT(UCSRB, UCSRB_TXCIE);

#elif UART_TX_INT == ENABLED
	 SET_BIT(UCSRB, UCSRB_TXCIE);

#endif

	 /*set Data register interrupt*/
#if UART_DATA_REG_INT == DISABLED
	 CLEAR_BIT(UCSRB, UCSRB_UDRIE);

#elif UART_DATA_REG_INT == ENABLED
	 SET_BIT(UCSRB, UCSRB_UDRIE);

#endif
	//UCSRC |= (1 << URSEL_BIT_NO) | UART_8_BIT_DATA | UART_EVEN_PARITY;

//	SET_BIT(UART_UCSRB_REG,7); /*	Enable Rx Complete Interrupt	*/
//	SET_BIT(UART_UCSRB_REG,6); /*	Enable Tx Complete Interrupt	*/

}

/******************************************************************************
* \Syntax          : void UART_TransmitChr(u8 data)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : data   data byte
* \Return value:   : None
*******************************************************************************/
void UART_TransmitChr(u8 data)
{

	while(0 == CHECK_BIT(UCSRA, UCSRA_UDRE));
	/* Put data into buffer*/
	UDR = data;
}

/******************************************************************************
* \Syntax          : u8 UART_ReceiveChr(void)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : u8     received data byte
*******************************************************************************/
u8 UART_ReceiveChr(u8 *data)
{
	while(0 == CHECK_BIT(UCSRA, UCSRA_UDRE));
	/* read data from buffer*/
	*data = UDR;
	return 0;
}

void UART_TransmitStr(u8 *str)
{
	while (*str != '\0')
	{
//	buff.byte_index = 0;
//	strcpy(buff.UART_tr_buff, str);
		UART_TransmitChr(*str);
		str++;
	}
}

void UART_voidTxCallBack(void (*Copy_ptrFunc)(void))
{
	if(Copy_ptrFunc != NULL)
	{
		UART_TX_CallBack = Copy_ptrFunc;
		//Copy_ptrFunc();
		UART_TX_CallBack();
	}
}

void __vector_15(void)
{
//	UART_TransmitChr('2');
	UART_TX_CallBack();

}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
