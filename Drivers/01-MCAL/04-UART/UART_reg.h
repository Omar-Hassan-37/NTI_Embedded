/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  uart.h
 *       Module:  uart
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef UART_REG_H_
#define UART_REG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


#define UDR					(*(volatile u8* )0x2C)			/*USART I/O Data Register*/

#define UCSRA				(*(volatile u8* )0x2B)			/*USART Control and Status Register A*/
#define UCSRA_RXC						7					/*USART Receive Complete*/
#define UCSRA_TXC						6					/*USART Transmit Complete*/
#define UCSRA_UDRE						5					/*USART Data Register Empty*/
#define UCSRA_U2X						1					/*Double the USART Transmission Speed*/

#define UCSRB				(*(volatile u8* )0x2A)			/*USART Control and Status Register B*/
#define UCSRB_RXCIE						7					/*RX Complete Interrupt Enable*/
#define UCSRB_TXCIE						6					/*TX Complete Interrupt Enable*/
#define UCSRB_UDRIE						5					/*USART Data Register Empty Interrupt Enable*/
#define UCSRB_RXEN						4					/*Receiver Enable*/
#define UCSRB_TXEN						3					/*Transmitter Enable*/
#define UCSRB_UCSZ2						2					/*Character Size combined with UCSZ1:0 bit in UCSRC*/
#define UCSRB_RXB8						1					/*Receive Data Bit 8*/
#define UCSRB_TXB8						0					/*Transmit Data Bit 8*/

#define UCSRC				(*(volatile u8* )0x40)			/*USART Control and Status Register C*/
#define UCSRC_URSEL						7					/*Register Select: UCSRC / UBRRH*/
#define UCSRC_UMSEL						6					/*USART Mode Select: Asynchronous / Synchronous*/
#define UCSRC_UPM1						5					/*Parity Mode*/
#define UCSRC_UPM0						4					/*Parity Mode*/
#define UCSRC_USBS						3					/*Stop Bit Select*/
#define UCSRC_UCSZ1						2					/*Character Size*/
#define UCSRC_UCSZ0						1					/*Character Size*/
#define UCSRC_UCPOL						0					/*Clock Polarity for Synchronous mode only*/

#define UBRRH				(*(volatile u8* )0x40)

#define UBRRL				(*(volatile u8* )0x29)


#define RXEN_BIT_NO						(4)
#define TXEN_BIT_NO						(3)
#define URSEL_BIT_NO					(7)
#define USBS_BIT_NO						(3)
#define UCSZ0_BIT_NO					(1)
#define UPM0_BIT_NO						(4)
#define UDRE_BIT_NO						(5)
#define RXC_BIT_NO						(7)
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* UART_H_ */

/**********************************************************************************************************************
 *  END OF FILE: uart.h
 *********************************************************************************************************************/
