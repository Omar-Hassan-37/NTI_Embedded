/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef SPI_REG_H
#define SPI_REG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SPCR			(*(volatile u8* )0x2D)				/*SPI Control Register*/
#define SPCR_SPIE				7							/*SPI Interrupt Enable*/
#define SPCR_SPE				6							/*SPI Enable*/
#define SPCR_DORD				5							/*Data Order*/
#define SPCR_MSTR				4							/*Master/Slave Select*/
#define SPCR_CPOL				3							/*Clock Polarity*/
#define SPCR_CPHA				2							/*Clock Phase*/
#define SPCR_SPR1				1							/*SPI Clock Rate Select bit 1*/
#define SPCR_SPR0				0							/*SPI Clock Rate Select bit 0*/

#define SPSR			(*(volatile u8* )0x2E)				/*SPI Status Register*/
#define SPSR_SPIF				7							/*SPI Interrupt Flag*/
#define SPSR_SPI2X				0							/*Double SPI Speed Bit*/

#define SPDR			(*(volatile u8* )0x2F)				/*SPI Data Register*/

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


#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: FILE_NAME.h
 *********************************************************************************************************************/
