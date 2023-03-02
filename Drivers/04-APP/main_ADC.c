/*
 * main_ADC.c
 *
 *  Created on: Mar 1, 2023
 *      Author: oh377
 */


#include "std_types.h"
#include "bit_math.h"

#include "dio.h"
#include "led.h"
#include "lcd.h"
#include "ADC_int.h"
#include "ADC_private.h"
#include "EXTI0_int.h"

#include <util/delay.h>

ADC_struct adc;

u8 size = ADC_CHANNELS_SIZE;
u8 arr[ADC_CHANNELS_SIZE] = ADC_CHANNELS_ARRAY;
u16 resultsArr[ADC_CHANNELS_SIZE];
u16 result;

void readADC_polling(u8 channel);

void readADC_Interrupt(u8 channel);

void readADC_Array(void);

void display_ISR(void);

void display_AutoTrigger(void);

void display_ADC_Arr_values(void);

extern u16 ADC_u16ReadADC(u8 channel);


int main(void)
{

	led_init();
	lcd_vidInit();

	dio_vidSetPortDir(DIO_PORTA, INPUT);

	ADC_voidInit();
	ADC_voidEnable();
	EXT0_voidInit();
	EXT_voidEnableGlobalInt();

//	readADC_polling(0u);

//	readADC_Interrupt(1u);

//	display_AutoTrigger();

	readADC_Array();

	while(1)
	{
//		led_toggle(LED_RED);
//		_delay_ms(500);
	}

	return 0;
}


/****************************************************************/
/* Description    : This function used to Read ADC and 			*/
/*					Inputs : channel(PA0/PA1/PA2/PA3/PA4/PA5
 * 										/PA6/PA7)				*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/
void readADC_polling(u8 channel)
{
	u16 reading = ADC_u16ReadADCInMV(0u);
	lcd_vidDisplyNum(reading);
}

/****************************************************************/
/* Description    : This function used to Read ADC by 			 */
/*					ADC_INTERRUPT								*/
/*					Inputs : channel(PA0/PA1/PA2/PA3/PA4/PA5
 * 										/PA6/PA7)				*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/
void readADC_Interrupt(u8 channel)
{
	ADC_voidCallBack(display_ISR, 0u, &result);

	/* start conversion */
	ADC_voidStartConversion();
}

/****************************************************************/
/* Description    : This function used to Read ADC Array by		 */
/*					ADC_INTERRUPT								*/
/*					Inputs : adc (struct)						*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/
void readADC_Array(void)
{
	adc.size = ADC_CHANNELS_SIZE;
	adc.channelArr = arr;
	adc.resultArr = resultsArr;
	adc.callBackFunc = display_ADC_Arr_values;

	ADC_voidCallArrayBack(adc);
}

/****************************************************************/
/* Description    : This function used to display the reading   */
/*					on LCD screen								*/
/*					Inputs : void								*/
/*					Return : void								*/
/****************************************************************/
void display_ISR(void)
{
	lcd_vidSendCmd(_LCD_CLEAR);
	lcd_vidDisplyNum(result);
	_delay_ms(500);
}

/****************************************************************/
/* Description    : This function used to display the reading   */
/*					on LCD screen of Auto trigger ADC			*/
/*					Inputs : void								*/
/*					Return : void								*/
/****************************************************************/
void display_AutoTrigger(void)
{
	result = ADC_u16ReadADC(0u);
	lcd_vidDisplyNum(result);
	_delay_ms(500);
	lcd_vidSendCmd(_LCD_CLEAR);
}

/****************************************************************/
/* Description    : This function used to display the reading   */
/*					of ADC array (ADC0,ADC1,ADC2,ADC3,ADC4,
 * 					ADC5,ADC6,ADC7 on LCD screen				*/
/*					Inputs : void								*/
/*					Return : void								*/
/****************************************************************/
void display_ADC_Arr_values(void)
{
	for(u8 i = 0; i < size; i++)
	{
		if(i == 4)
		{
			LCD_voidGotoXY(1, 0);
		}
		lcd_vidDisplyNum(resultsArr[i]);
		lcd_vidDisplyChar(' ');
	}
}

