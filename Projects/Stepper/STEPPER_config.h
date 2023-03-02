/****************************************************************/
/*   Author             :    Omar Hassan 				        */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   contain Stepper Numbers config	    */
/*             							[config.h] 		        */
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _STEPPER_CONFIG_H
#define _STEPPER_CONFIG_H

/****************************************************************/	
/** !comment : DC Motor Numbers Configuration [ 0 : ( n - 1 ) ]	*/
/**			   starts from 0 ends with ( n - 1 )				*/ 
/****************************************************************/
#define STEPPER_PORT			DIO_PORTB

#define NUMBER_OF_STEPPERS  	1


#endif /** !comment  :  End of guard                            **/ 
