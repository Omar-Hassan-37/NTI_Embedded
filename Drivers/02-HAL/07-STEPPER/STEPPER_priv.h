/****************************************************************/
/*   Author             :    Omar Hassan	 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Stepper priv [priv.h] contain		*/
/*                           Stepper Definition and Directions */
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _STEPPER_PRIV_H
#define _STEPPER_PRIV_H





/*****************************************************************/
/*!comment :Define Encabsulated Data type [ Stepper ] it is a	**/
/*		    Struct contain u8 for North wire and another u8 East **/
/*          wire another for u8 South wire another for u8 West wire **/
/*****************************************************************/

typedef struct stepper
{
	
	u8 NorthPin;
	u8 EastPin;
	u8 SouthPin;
	u8 WestPin;

}Stepper;

/*****************************************************************/
/* !comment : Array of struct ( DC Motors ) from config.c	 	 */
/*****************************************************************/

extern Stepper ArrayOfStepper [ NUMBER_OF_STEPPERS ] ;
  
  
#endif /** !comment  :  End of guard                            **/ 
