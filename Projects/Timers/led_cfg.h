/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  led_cfg.h
 *       Module:  led
 *
 *  Description:  write the configurations of the led module    
 *  
 *********************************************************************************************************************/
#ifndef LED_CFG_H
#define LED_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define LED_RED_PORT        DIO_PORTB
#define LED_RED_CHANNEL     DIO_PIN7

#define LED_GREEN_PORT      DIO_PORTA
#define LED_GREEN_CHANNEL   DIO_PIN4

#define LED_BLUE_PORT       DIO_PORTA
#define LED_BLUE_CHANNEL    DIO_PIN5

#define LED_YELLOW_PORT     DIO_PORTA
#define LED_YELLOW_CHANNEL  DIO_PIN6

#define SOURCE              1
#define SINK                0

/*	LEDs HW Connection	*/
/*	SOURCE				*/
/*	SINK				*/

#define LED_RED_CONNECTION		SOURCE
#define LED_GREEN_CONNECTION	SOURCE	/**/
#define LED_BLUE_CONNECTION		SOURCE
#define LED_YELLOW_CONNECTION	SOURCE

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
