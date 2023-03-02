/************************************************************/
/* 	Author 	 	 : Ahmed Atia Atia                          */
/* 	Date   		 : 20 April 2019                            */
/* 	Version 	 : 1V 									    */
/* 	Description	 : prog.c for EXT0		                    */
/************************************************************/


/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_types.h"
#include "bit_math.h"
//#include "Lbt_int.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "led.h"
#include <util/delay.h>
#include "EXTI_Config.h"
#include "EXTI_int.h"
#include "EXTI_private.h"


/***********************************************************/
/**!comment   :  pointer to function for callback	       */
/***********************************************************/
void (*pf1) (void);
void (*pf2) (void);
void (*pf3) (void);
//typedef volatile pf x;

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

/****************************************************************/
/* Description    :  This function used to enable global interrupt      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/
void EXT_voidEnableGlobalInt( void )
{
	SET_BIT(SREG, 7);
}

/****************************************************************/
/* Description    :  This function used to disable global interrupt      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/
void EXT_voidDisableGlobalInt( void )
{
	CLEAR_BIT(SREG, 7);
}


/****************************************************************/
/* Description    :  This function used to initialize EXT0      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/



void EXT0_voidInit (void)
{
	
	/*  ( if / else if ) condition for Macros */
	#if EXT0_SENSE_MODE == IOC
	SET_BIT(MCUCR , 0);
	CLEAR_BIT(MCUCR , 1);
	
	#elif EXT0_SENSE_MODE == RISING
	SET_BIT(MCUCR , 0);
	SET_BIT(MCUCR , 1);
	
	#elif EXT0_SENSE_MODE == FALLING
	CLEAR_BIT(MCUCR , 0);
	SET_BIT(MCUCR , 1);
	
	#elif EXT0_SENSE_MODE == LOW_LEVEL
	CLEAR_BIT(MCUCR , 0);
	CLEAR_BIT(MCUCR , 1);
	
	#endif
	/* End ( if ) condition for Macros */

	
/** disable EXT0 in initialization function  **/
/** like : void EXT0_voidDisable(); 		  */
	CLEAR_BIT( GICR , 6 );
	SET_BIT(GIFR , 6 ) ;
	
	
}


/****************************************************************/
/* Description    :  This function used to initialize EXT1      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/
void EXT1_voidInit (void)
{

	/*  ( if / else if ) condition for Macros */
	#if EXT1_SENSE_MODE == IOC
	SET_BIT(MCUCR , 2);
	CLEAR_BIT(MCUCR , 3);

	#elif EXT1_SENSE_MODE == RISING
	SET_BIT(MCUCR , 2);
	SET_BIT(MCUCR , 3);

	#elif EXT1_SENSE_MODE == FALLING
	CLEAR_BIT(MCUCR , 2);
	SET_BIT(MCUCR , 3);

	#elif EXT1_SENSE_MODE == LOW_LEVEL
	CLEAR_BIT(MCUCR , 2);
	CLEAR_BIT(MCUCR , 3);

	#endif
	/* End ( if ) condition for Macros */


	/** disable EXT0 in initialization function  **/
	/** like : void EXT0_voidDisable(); 		  */
	CLEAR_BIT( GICR , 7 );
	SET_BIT(GIFR , 7 ) ;


}



void EXT2_voidInit (void)
{

	/*  ( if / else if ) condition for Macros */

	#if EXT2_SENSE_MODE == FALLING
	CLEAR_BIT(MCUCSR , 6);

	#elif EXT2_SENSE_MODE == RISING
	SET_BIT(MCUCSR , 6);

	#endif
	/* End ( if ) condition for Macros */


	/** disable EXT0 in initialization function  **/
	/** like : void EXT0_voidDisable(); 		  */
	CLEAR_BIT( GICR , 5 );
	SET_BIT(GIFR , 5 ) ;


}

/****************************************************************/
/* Description    : This function used to Enable EXT0			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT0_voidEnable()
{
	
	SET_BIT( GICR , 6 );
	
}


/****************************************************************/
/* Description    : This function used to Disable EXT0			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT0_voidDisable()
{
	
	CLEAR_BIT( GICR , 6 );
	
}


/****************************************************************/
/* Description    : This function used to Enable EXT1			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT1_voidEnable()
{

	SET_BIT( GICR , 7 );

}


/****************************************************************/
/* Description    : This function used to Disable EXT1			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT1_voidDisable()
{

	CLEAR_BIT( GICR , 7 );

}


/****************************************************************/
/* Description    : This function used to Enable EXT2			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT2_voidEnable()
{

	SET_BIT( GICR , 5 );

}


/****************************************************************/
/* Description    : This function used to Disable EXT1			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT2_voidDisable()
{

	CLEAR_BIT( GICR , 5 );

}


/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/ 
/*						[ Layer Architecture Problem Solved ]	*/
/*																*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT0_voidCallBack(void (*addresscpy)(void))
{
	if(addresscpy != NULL)
	{
		pf1 = addresscpy;
	}
}


/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/
/*						[ Layer Architecture Problem Solved ]	*/
/*																*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT1_voidCallBack(void (*addresscpy)(void))
{
	if(addresscpy != NULL)
	{
		pf2 = addresscpy;
	}
}


/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/
/*						[ Layer Architecture Problem Solved ]	*/
/*																*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT2_voidCallBack(void (*addresscpy)(void))
{
	if(addresscpy != NULL)
	{
		pf3 = addresscpy;
	}
}


/****************************************************************/
/* Description    : This function used to Set lach Interrupt	*/
/*									 happens.					*/ 
/*																*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
void EXT0_voidSetSignalch(u8 SenseCpy)
{
	
	switch(SenseCpy)
	{
		case IOC:
			SET_BIT(MCUCR , 0);
			CLEAR_BIT(MCUCR , 1);
			break;

		case RISING:
			SET_BIT(MCUCR , 0);
			SET_BIT(MCUCR , 1);
			break;

		case FALLING:
			CLEAR_BIT(MCUCR , 0);
			SET_BIT(MCUCR , 1);
			break;

		case LOW_LEVEL:
			CLEAR_BIT(MCUCR , 0);
			CLEAR_BIT(MCUCR , 1);
			break;

		default: break;
	}

	/* End ( if ) condition for Macros */


}



/****************************************************************/
/* Description    : This function used to Set lach Interrupt	*/
/*									 happens.					*/
/*																*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
void EXT1_voidSetSignalch(u8 SenseCpy)
{

	switch(SenseCpy)
	{
		case IOC:
		SET_BIT(MCUCR , 2);
		CLEAR_BIT(MCUCR , 3);
		break;

		case RISING:
		SET_BIT(MCUCR , 2);
		SET_BIT(MCUCR , 3);
		break;

		case FALLING:
		CLEAR_BIT(MCUCR , 2);
		SET_BIT(MCUCR , 3);
		break;

		case LOW_LEVEL:
		CLEAR_BIT(MCUCR , 2);
		CLEAR_BIT(MCUCR , 3);
		break;

		default: break;
	}

	/* End ( if ) condition for Macros */


}




/****************************************************************/
/* Description    : This function used to Set lach Interrupt	*/
/*									 happens.					*/
/*																*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
void EXT2_voidSetSignalch(u8 SenseCpy)
{

	switch(SenseCpy)
	{
		case RISING:
		SET_BIT(MCUCSR , 6);
		break;

		case FALLING:
		CLEAR_BIT(MCUCSR , 6);
		break;

		default: break;
	}
	
	/* End ( if ) condition for Macros */
	

}


/****************************************************************/
/* Description    : This function used to Check if interrupt is */
/*					Executed or Not.							*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : flag Status [ LBTY_OK , LBTY_NOK ]	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
/*
flagStatus EXT0_enuIsExecuted( void )
{
	flagStatus ErrorStatus ;
	
	if( (GET_BIT(GIFR, 6)) == 1 )
	{
		
		ErrorStatus = LBTY_NOK ;
	}
	else if ( (GET_BIT(GIFR, 6)) == 0 )
	{
		
		ErrorStatus = LBTY_OK ;
	}
	
	return ErrorStatus ;
}
*/
/** Linker Problem solved */


void __vector_1(void)
{
	pf1();
}



void __vector_2(void)
{
	pf2();
}


void __vector_3(void)
{
	pf3();
}
/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/
