/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    2 May 2019  						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   public Accessing mechanism prototype*/ 
/*							and Sense Mode Definition [int.h] 	*/
/****************************************************************/



/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _ADC_INT_H
#define _ADC_INT_H


/****************************************************************/	
/** !comment : Sense Mode Definition					   		*/
/****************************************************************/

#define AVCC 					5
#define AREF 					4
#define INTERNAL				2.56

#define REFS1					7
#define REFS0					6
#define ADLAR					5
#define CHANNEL_MASK		0b11100000

#define ADEN					7
#define ADSC					6
#define ADATE					5
#define ADIF					4
#define ADIE					3

#define RIGHT_ADJUSTMENT 		0
#define LEFT_ADJUSTMENT 		1

#define DISABLED				0
#define ENABLED					1

#define PRESCALER_MASK		0b11111000
#define DIVID_BY_2				1
#define DIVID_BY_4				2
#define DIVID_BY_8				3
#define DIVID_BY_16				4
#define DIVID_BY_32				5
#define DIVID_BY_64				6
#define DIVID_BY_128			7


#define FREE_RUNNING_MODE 				0
#define ANALOG_COMPARATOR				1
#define EXTERNAL_INTERRPUT_REQUEST_0 	2
#define TIMER_COUNTER_0_COMPARE_MATCH	3
#define TIMER_COUNTER_0_OVERFLOW		4
#define TIMER_COUNTER_COMPARE_MATCH_B	5
#define TIMER_COUNTER_1_OVERFLOW		6
#define TIMER_COUNTER_1_CAPTURE_EVENT	7

#define ADC0		0u
#define ADC1        1u
#define ADC2        2u
#define ADC3        3u
#define ADC4        4u
#define ADC5        5u
#define ADC6        6u
#define ADC7        7u

typedef struct
{
	u8 size;
	u8 *channelArr;
	u16 *resultArr;
	void (*callBackFunc)(void);
}ADC_struct;

#define ADC_CHANNELS_SIZE			8u
#define ADC_CHANNELS_ARRAY		{ADC0, ADC1, ADC2, ADC3, ADC4, ADC5, ADC6, ADC7}
/****************************************************************/
/* Description    :  This function used to initialize ADC 	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void ADC_voidInit (void);


//****************************************************************/
/* Description    : This function used to Enable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidEnable();


/****************************************************************/
/* Description    : This function used to Enable ADC Interrput	*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidInterrputEnable();


/****************************************************************/
/* Description    : This function used to Disable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidDisable();


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
u8 ADC_u8ReadADC(u8 addresscpy);



/****************************************************************/
/* Description    : This function used to Start converting		*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidStartConversion();


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

void ADC_voidAutoTrigger();



/****************************************************************/
/* Description    : This function used to Read ADC and 			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : u16 Digital Converting melli Volt	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

u16 ADC_u16ReadADCInMV(u8 Copy_u8Channel);


/****************************************************************/
/* Description    : This function used to call back the			*/
/*					function from App to the interrupt			*/
/*					Inputs : addresscpy (pointer to function)
 * 							channel (PA0,PA1,PA2,PA3,PA4,PA5,
 * 										PA6,PA7)
 * 							result (pointer to save the result
 * 									and display it on lcd from
 * 									app layer					*/
/*					Return : u16 Digital Converting melli Volt	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/
void ADC_voidCallBack(void (*addresscpy)(void), u8 channel, u16 *result);

/****************************************************************/
/* Description    : This function used to read the value of 	*/
/*					an array of ADC channels 					*/
/*																*/
/*					Inputs : adc (struct)			  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidCallArrayBack (ADC_struct adc);

#endif	/** !comment  :  End of guard                          **/
