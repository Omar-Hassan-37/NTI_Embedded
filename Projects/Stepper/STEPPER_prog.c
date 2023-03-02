/****************************************************************/
/*   Author             :    Omar Hassan					    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   Progam algorithm for Stepper		*/
/*									 [prog.c]				    */
/****************************************************************/


/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include <util/delay.h>
#include "std_types.h"
#include "bit_math.h"

/****************************************************************/
/********************* DIO Component DIRECTIVES *****************/
/****************************************************************/

#include "dio.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "STEPPER_int.h"
#include "STEPPER_config.h"
#include "STEPPER_priv.h"


/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/



static u8 fullStepClockWiseArr[4] = {
		0b00000001, 0b00000010,
		0b00000100, 0b00001000
};

static u8 halfStepClockWiseArr[8] = {
		0b00001001, 0b00000001,
		0b00000011, 0b00000010,
		0b00000110, 0b00000100,
		0b00001100, 0b00001000
};

/****************************************************************/
/* Description    :  This function used to initialize DC Motor  */
/*					 Inputs : void			 					*/
/*					 return : void		 						*/
/****************************************************************/

void STEPPER_voidInit( void )
{
/*****************************************************************/
/* !comment : Loop to initialize all DC Motors				 	 */
/*****************************************************************/
	
	for( u8 i = 0 ; i < NUMBER_OF_STEPPERS ; i++ )
	{
		
		/** !comment : Turn off north wire for current stepper		 */
		dio_vidConfigChannel(STEPPER_PORT, ArrayOfStepper[i].NorthPin, OUTPUT);
		dio_vidWriteChannel(STEPPER_PORT, ArrayOfStepper[i].NorthPin ,STD_LOW );
		/** !comment : Turn off east wire for current stepper		 */
		dio_vidConfigChannel(STEPPER_PORT, ArrayOfStepper[i].EastPin, OUTPUT);
		dio_vidWriteChannel(STEPPER_PORT, ArrayOfStepper[i].EastPin ,STD_LOW );
		/** !comment : Turn off south wire for current stepper		 */
		dio_vidConfigChannel(STEPPER_PORT, ArrayOfStepper[i].SouthPin, OUTPUT);
		dio_vidWriteChannel(STEPPER_PORT, ArrayOfStepper[i].SouthPin ,STD_LOW );
		/** !comment : Turn off west wire for current stepper		 */
		dio_vidConfigChannel(STEPPER_PORT, ArrayOfStepper[i].WestPin, OUTPUT);
		dio_vidWriteChannel(STEPPER_PORT, ArrayOfStepper[i].WestPin ,STD_LOW );
	}

}


/****************************************************************/
/* Description    :  This function used to show the Direction	*/
/*					 of Moving. 								*/
/*					 Inputs : Stepper Number 	 ,  				*/
/*   						  Stepper Direction[left ,right,stop] */
/*					 return : void		 						*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Stepper  */
/*     				 initialized								*/
/****************************************************************/

void STEPPER_voidMoveFullStep( u8 u8StepperNumber , u8 u8Direction  )
{
	
	switch( u8Direction )
	{
		
		case STOP:			
							/** !comment : Turn off all wires			*/
							dio_vidWriteChannel(STEPPER_PORT, ArrayOfStepper[u8StepperNumber].NorthPin ,STD_LOW );
							dio_vidWriteChannel(STEPPER_PORT, ArrayOfStepper[u8StepperNumber].EastPin ,STD_LOW );
							dio_vidWriteChannel(STEPPER_PORT, ArrayOfStepper[u8StepperNumber].SouthPin ,STD_LOW );
							dio_vidWriteChannel(STEPPER_PORT, ArrayOfStepper[u8StepperNumber].WestPin ,STD_LOW );

		break;
		
		
		case RIGHT:			
							/** !comment : Turn on right Turn off left	*/
							for(u8 i = 0; i < 4; i++)
							{
								dio_vidSetPortValue(STEPPER_PORT, fullStepClockWiseArr[i]);
								_delay_ms(100);
							}
							
		break;
		
		
		case LEFT:			
							/** !comment : Turn on left Turn off right	*/
							for(u8 i = 3; i >= 0; i--)
							{
								dio_vidSetPortValue(STEPPER_PORT, fullStepClockWiseArr[i]);
								_delay_ms(100);
							}
							
		break;
		
		
		default:			
							/** !comment : Turn off all wires ( STOP )	*/
							dio_vidWriteChannel(STEPPER_PORT, ArrayOfStepper[u8StepperNumber].NorthPin ,STD_LOW );
							dio_vidWriteChannel(STEPPER_PORT, ArrayOfStepper[u8StepperNumber].EastPin ,STD_LOW );
							dio_vidWriteChannel(STEPPER_PORT, ArrayOfStepper[u8StepperNumber].SouthPin ,STD_LOW );
							dio_vidWriteChannel(STEPPER_PORT, ArrayOfStepper[u8StepperNumber].WestPin ,STD_LOW );
		break;
							
	}
	
}


/****************************************************************/
/* Description    :  This function used to show the Direction	*/
/*					 of Moving in half step. 					*/
/*					 Inputs : Stepper Number 	 ,  			*/
/*   						  Stepper Direction[left ,right,stop] */
/*					 return : void		 						*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Stepper  */
/*     				 initialized								*/
/****************************************************************/

void STEPPER_voidMoveHalfStep( u8 u8StepperNumber , u8 u8Direction  )
{
	switch( u8Direction )
	{

		case STOP:
							/** !comment : Turn off all wires			*/
							dio_vidWriteChannel(STEPPER_PORT, ArrayOfStepper[u8StepperNumber].NorthPin ,STD_LOW );
							dio_vidWriteChannel(STEPPER_PORT, ArrayOfStepper[u8StepperNumber].EastPin ,STD_LOW );
							dio_vidWriteChannel(STEPPER_PORT, ArrayOfStepper[u8StepperNumber].SouthPin ,STD_LOW );
							dio_vidWriteChannel(STEPPER_PORT, ArrayOfStepper[u8StepperNumber].WestPin ,STD_LOW );

		break;


		case RIGHT:
							/** !comment : Turn on right Turn off left	*/
							for(u8 i = 0; i < 8; i++)
							{
								dio_vidSetPortValue(STEPPER_PORT, halfStepClockWiseArr[i]);
								_delay_ms(100);
							}

		break;


		case LEFT:
							/** !comment : Turn on left Turn off right	*/
							for(u8 i = 7; i >= 0; i--)
							{
								dio_vidSetPortValue(STEPPER_PORT, halfStepClockWiseArr[i]);
								_delay_ms(100);
							}

		break;


		default:
							/** !comment : Turn off all wires ( STOP )	*/
							dio_vidWriteChannel(STEPPER_PORT, ArrayOfStepper[u8StepperNumber].NorthPin ,STD_LOW );
							dio_vidWriteChannel(STEPPER_PORT, ArrayOfStepper[u8StepperNumber].EastPin ,STD_LOW );
							dio_vidWriteChannel(STEPPER_PORT, ArrayOfStepper[u8StepperNumber].SouthPin ,STD_LOW );
							dio_vidWriteChannel(STEPPER_PORT, ArrayOfStepper[u8StepperNumber].WestPin ,STD_LOW );
		break;

	}
}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/
