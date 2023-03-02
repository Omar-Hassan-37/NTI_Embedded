/****************************************************************/
/*   Author             :    Omar Hassan					    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   public Accessing mechanism prototype*/ 
/*							for Stepper [int.h] 			    */
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _STEPPER_INT_H
#define _STEPPER_INT_H


/****************************************************************/	
/** !comment : DC Motor Directions Definition	    			*/
/****************************************************************/

#define STOP	1
#define RIGHT	4
#define LEFT	7


/****************************************************************/
/* Description    :  This function used to initialize Stepper  */
/*					 Inputs : void			 					*/
/*					 return : void		 						*/
/****************************************************************/

void STEPPER_voidInit( void );

/****************************************************************/
/* Description    :  This function used to show the Direction	*/
/*					 of Moving in full step. 					*/
/*					 Inputs : Stepper Number 	 ,  			*/
/*   						  Stepper Direction[left ,right,stop] */
/*					 return : void		 						*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Stepper  */
/*     				 initialized								*/
/****************************************************************/

void STEPPER_voidMoveFullStep( u8 u8StepperNumber , u8 u8Direction  );


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

void STEPPER_voidMoveHalfStep( u8 u8StepperNumber , u8 u8Direction  );



#endif /**!comment : End of the guard 							**/ 
