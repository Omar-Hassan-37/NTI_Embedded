/************************************************************/
/* 	Author 	 	 : Ahmed Atia Atia                          */
/* 	Date   		 : 2 May 2019	                            */
/* 	Version 	 : 1V 									    */
/* 	Description	 : prog.c for ADC		                    */
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

#include "ADC_int.h"
#include "ADC_config.h"
#include "ADC_private.h"

#include "led.h"
#include <util/delay.h>

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

static u16 *ADC_u16ConversionResult = NULL;
static void (*ADC_voidConversionFunc)(void) = NULL;

ADC_struct ADC_arr;



/****************************************************************/
/* Description    :  This function used to initialize ADC 	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void ADC_voidInit (void)
{
	
	
	/* End ( if ) condition for Macros */	
	
	/* Voltage reference option = AVCC */
	#if VOLTAGE_REFERENCE == AREF
	CLEAR_BIT(ADMUX, REFS0);
	CLEAR_BIT(ADMUX, REFS1);

	#elif VOLTAGE_REFERENCE == AVCC
	SET_BIT(ADMUX, REFS0);
	CLEAR_BIT(ADMUX, REFS1);

	#elif VOLTAGE_REFERENCE == INTERNAL
	SET_BIT(ADMUX, REFS0);
	SET_BIT(ADMUX, REFS1);

	#endif

	/* Adjustment option = LEFT_ADJUSTMENT */
	#if ADJUSTMENT == RIGHT_ADJUSTMENT
	CLEAR_BIT(ADMUX, ADLAR);

	#elif ADJUSTMENT == LEFT_ADJUSTMENT
	SET_BIT(ADMUX, ADLAR);

	#endif

	/* ADC_AUTO_TRIGGER_ENABLE option = DISABLED */
	#if ADC_AUTO_TRIGGER_ENABLE == ENABLED
	SET_BIT(ADCSRA, ADATE);
	
	#elif ADC_AUTO_TRIGGER_ENABLE == DISABLED
	CLEAR_BIT(ADCSRA, ADATE);

	#endif

	/* ADC_INTERRUPT_ENABLE option = DISABLED */
	#if ADC_INTERRUPT_ENABLE == ENABLED
	SET_BIT(ADCSRA, ADIE);

	#elif ADC_INTERRUPT_ENABLE == DISABLED
	CLEAR_BIT(ADCSRA, ADIE);

	#endif


	/* configure prescaler bits */
	ADCSRA &= PRESCALER_MASK;
	ADCSRA |= DIVID_BY_128;

}


/****************************************************************/
/* Description    : This function used to Enable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidEnable()
{
	
	SET_BIT( ADCSRA , ADEN );
	
}

/****************************************************************/
/* Description    : This function used to Enable ADC Interrput	*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidInterrputEnable()
{

	
	SET_BIT( ADCSRA , ADIE );
	
}


/****************************************************************/
/* Description    : This function used to Disable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidDisable()
{
	
	CLEAR_BIT( ADCSRA , ADEN );
	
}


/****************************************************************/
/* Description    : This function used to Start converting		*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidStartConversion()
{
	
	SET_BIT( ADCSRA , ADSC );
	
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

void ADC_voidAutoTrigger()
{
	

	
/****************************************************************/	
/** !comment : From Data Sheet : Starting conversion on positive*/
/*			   edge when ADATE = 1						    	*/
/****************************************************************/

	
	/** Enable ADC Auto Trigger	 							   **/
	/** ADATE = 1 =====> 	SET_BIT( ADATE , 5 ); 			   **/

    SET_BIT( ADCSRA , 5 );
	

		/*  ( if / else if ) condition for Macros */
	#if ADC_AUTO_TRIGGER_SOURCE == FREE_RUNNING_MODE 
	CLEAR_BIT( SFIOR , 0 );
	CLEAR_BIT( SFIOR , 1 );
	CLEAR_BIT( SFIOR , 2 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == ANALOG_COMPARATOR
	SET_BIT( SFIOR , 0 );
	CLEAR_BIT( SFIOR , 1 );
	CLEAR_BIT( SFIOR , 2 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == EXTERNAL_INTERRPUT_REQUEST_0
	CLEAR_BIT( SFIOR , 5 );
	SET_BIT( SFIOR , 6 );
	CLEAR_BIT( SFIOR , 7 );
	
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_COMPARE_MATCH
	SET_BIT( SFIOR , 0 );
	SET_BIT( SFIOR , 1 );
	CLEAR_BIT( SFIOR , 2 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_OVERFLOW
	CLEAR_BIT( SFIOR , 0 );
	CLEAR_BIT( SFIOR , 1 );
	SET_BIT( SFIOR , 2 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_COMPARE_MATCH_B
	SET_BIT( SFIOR , 0 );
	CLEAR_BIT( SFIOR , 1 );
	SET_BIT( SFIOR , 2 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_OVERFLOW
	CLEAR_BIT( SFIOR , 0 );
	SET_BIT( SFIOR , 1 );
	SET_BIT( SFIOR , 2 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_CAPTURE_EVENT
	SET_BIT( SFIOR , 0 );
	SET_BIT( SFIOR , 1 );
	SET_BIT( SFIOR , 2 );	
	
	#endif
	/* End ( if ) condition for Macros */
	
}


/****************************************************************/
/* Description    : This function used to Read ADC and 			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : u16 Digital Converting melli Volt	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

u16 ADC_u16ReadADCInMV(u8 channel)
{
	ADMUX &= CHANNEL_MASK;
	ADMUX |= channel;
	
	/* start conversion */
	ADC_voidStartConversion();

	/* wait until the conversion is clear */
	while(CHECK_BIT(ADCSRA, ADIF) == 0);

	/* clear the conversion flag */
	SET_BIT(ADCSRA, ADIF);

	/* check if left Adjustment or right (8 bit or 10 bit) */
	#if ADJUSTMENT == LEFT_ADJUSTMENT
	return ADCH;
	
	#elif ADJUSTMENT == RIGHT_ADJUSTMENT
	return ADC;

	#endif
	
}

u16 ADC_u16ReadADC(u8 channel)
{
	ADMUX &= CHANNEL_MASK;
	ADMUX |= channel;

	/* check if left Adjustment or right (8 bit or 10 bit) */
	#if ADJUSTMENT == LEFT_ADJUSTMENT
	return ADCH;

	#elif ADJUSTMENT == RIGHT_ADJUSTMENT
	return ADC;

	#endif
}

/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/
/*																*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)
 * 							 channel
 * 							 result (pointer to pass the value in
 * 							 it to the app layer)*/
/*					Return : void								*/
/****************************************************************/

void ADC_voidCallBack(void (*addresscpy)(void), u8 channel, u16 *result)
{
	ADMUX &= CHANNEL_MASK;
	ADMUX |= channel;
	if(addresscpy != NULL)
	{
		ADC_voidConversionFunc = addresscpy;
		ADC_u16ConversionResult = result;
	}
}

/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/
/*																*/
/*					Inputs : struct contains(size of the array
 * 							 the channel array,
 * 							 the result array to pass the values
 * 							 in it,
 * 							 the call back function from the
 * 							 app layer)
 */
/*					Return : void								*/
/****************************************************************/
void ADC_voidCallArrayBack (ADC_struct adc)
{
	if(adc.callBackFunc != NULL)
	{
		ADC_arr.size = adc.size;
		ADC_arr.channelArr = adc.channelArr;
		ADC_arr.resultArr = adc.resultArr;
		ADC_arr.callBackFunc = adc.callBackFunc;
	}
	ADMUX &= CHANNEL_MASK;
	ADMUX |= ADC_arr.channelArr[0];

	ADC_voidStartConversion();
}

//void __vector_16(void)
//{
//	if(ADC_u16ConversionResult != NULL)
//	{
//#if ADJUSTMENT == LEFT_ADJUSTMENT
//	*ADC_u16ConversionResult = ADCH;
//
//#elif ADJUSTMENT == RIGHT_ADJUSTMENT
//	*ADC_u16ConversionResult =  ADC;
//
//	#endif
//	}
//
//	/* disable the ADC conversion interrupt */
//	CLEAR_BIT(ADCSRA, ADIE);
//
//	ADC_voidConversionFunc();
//}

void __vector_16(void)
{
	static u8 counter = 0;

#if ADJUSTMENT == LEFT_ADJUSTMENT
	ADC_arr.resultArr[counter] = ADCH;

#elif ADJUSTMENT == RIGHT_ADJUSTMENT
	ADC_arr.resultArr[counter] =  ADC;

	#endif

	counter++;
	if(counter < ADC_arr.size)
	{
		ADMUX &= CHANNEL_MASK;
		ADMUX |= ADC_arr.channelArr[counter];
		ADC_voidStartConversion();
	}
	else
	{
		ADC_arr.callBackFunc();
	}
}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/
