/****************************************************************/
/*   Author             :    Omar Hassan	 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   contain Stepper Pins configuration	*/
/*             							[config.c] 				*/
/****************************************************************/

#include "Std_types.h"
#include "dio.h"
#include "STEPPER_config.h"
#include "STEPPER_priv.h"



/*****************************************************************/
/* !comment : Array of struct ( Steppers )					 	 */
/*****************************************************************/

Stepper ArrayOfStepper [ NUMBER_OF_STEPPERS ] =
{
	{DIO_PIN0 , DIO_PIN1, DIO_PIN2, DIO_PIN3}  ,
	
};

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/
