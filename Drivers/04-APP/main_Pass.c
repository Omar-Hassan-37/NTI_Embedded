/*
 * main.c
 *
 *  Created on: Feb 19, 2023
 *      Author: oh377
 */

#include "std_types.h"
#include "bit_math.h"

#include "dio.h"
#include "led.h"
#include "button.h"
#include "lcd.h"
#include "keypad.h"
#include "ADC_int.h"
#include "ADC_private.h"
#include "EXTI0_int.h"

#include <util/delay.h>

static u8 password[] = {'0','0','1','2','2','2'};
static u8 index_counter = 0;

void local_vidtogglePin_1(led_id_t led);
void local_vidToggleThreeLed_2();
void local_vidControlLed_4();
void local_checkPass_1_1();
boolean local_checkPass_input(u8 letter);
void local_vidResetPass();

void display_ISR();

void display_AutoTrigger();

u16 dispaly_num;

void main(void)
{
	led_init();
	button_vidInit();
	lcd_vidInit();
	keypad_vidInit();
//	lcd_vidDisplyChar('m');
//	lcd_vidDisplyStr("omar");
	u16 local_u8DigitalReading;

	dio_vidConfigChannel(DIO_PORTA, DIO_PIN0, INPUT);

//	dio_vidConfigChannel(DIO_PORTB, DIO_PIN0, OUTPUT);
//	dio_vidConfigChannel(DIO_PORTB, DIO_PIN1, OUTPUT);
//	dio_vidConfigChannel(DIO_PORTB, DIO_PIN2, OUTPUT);
//	dio_vidConfigChannel(DIO_PORTB, DIO_PIN3, OUTPUT);
//	dio_vidConfigChannel(DIO_PORTB, DIO_PIN4, OUTPUT);
//	dio_vidConfigChannel(DIO_PORTB, DIO_PIN5, OUTPUT);
//	dio_vidConfigChannel(DIO_PORTB, DIO_PIN6, OUTPUT);
//	dio_vidConfigChannel(DIO_PORTB, DIO_PIN7, OUTPUT);
//
//	dio_vidWriteChannel(DIO_PORTA, DIO_PIN0, STD_LOW);
//	dio_vidWriteChannel(DIO_PORTA, DIO_PIN1, STD_LOW);
//	dio_vidWriteChannel(DIO_PORTA, DIO_PIN2, STD_LOW);
//	dio_vidWriteChannel(DIO_PORTA, DIO_PIN3, STD_LOW);
//	dio_vidWriteChannel(DIO_PORTA, DIO_PIN4, STD_LOW);
//	dio_vidWriteChannel(DIO_PORTA, DIO_PIN5, STD_LOW);
//	dio_vidWriteChannel(DIO_PORTA, DIO_PIN6, STD_LOW);
//	dio_vidWriteChannel(DIO_PORTA, DIO_PIN7, STD_LOW);


//	dio_vidConfigChannel(DIO_PORTD, DIO_PIN2, INPUT);
//	dio_vidConfigChannel(DIO_PORTD, DIO_PIN3, INPUT);

	ADC_voidCallBack(display_ISR, 0u);
	ADC_voidInit();
	ADC_voidAutoTrigger();

	EXT0_voidInit();
	EXT0_voidEnable();

//	EXT1_voidCallBack(display_AutoTrigger);
//	EXT0_voidCallBack(display_AutoTrigger);
	EXT_voidEnableGlobalInt();


//	EXT1_voidInit();
//	EXT1_voidEnable();
//	lcd_vidDisplyNum(500);

//	ADC_voidStartConversion();
	while(1)
	{
//		local_vidtogglePin_1(LED_RED);
//		local_vidToggleThreeLed_2();
//		local_vidControlLed_4();

//		local_checkPass_1_1();


	}
}

void display_ISR(void)
{
	lcd_vidSendCmd(_LCD_CLEAR);
	dispaly_num = ADCH;
	lcd_vidDisplyNum(dispaly_num);
	_delay_ms(500);
//	ADC_voidStartConversion();
}

void display_AutoTrigger()
{
//	dispaly_num = ADC_u16ReadADC(0u);
//	lcd_vidDisplyNum(dispaly_num);
//	_delay_ms(500);
//	lcd_vidSendCmd(_LCD_CLEAR);
}

void local_vidtogglePin_1(led_id_t led)
{
	led_toggle(led);
	_delay_ms(500);
//	led_off(led);
//	_delay_ms(500);
}

void local_vidToggleThreeLed_2()
{
	led_toggle(LED_RED);
	_delay_ms(500);
	led_toggle(LED_GREEN);
	_delay_ms(500);
	led_toggle(LED_BLUE);
	_delay_ms(500);
}

void local_vidControlLed_4()
{
	dio_vidWriteChannel(BUTTON0_PORT, BUTTON0_PIN, STD_HIGH);
	while(1)
	{
		if(Button_GetStatus(BUTTON0))
		{
			led_on(LED_RED);
		}
		else
		{
			led_off(LED_RED);
		}
	}
}

void local_checkPass_1_1()
{
//	u8 entered_pass[7] = {0};
	boolean local_error_state = FALSE;

	lcd_vidDisplyStr("Enter Password:");
	LCD_voidGotoXY(LCD_u8_SECOND_LINE, LCD_u8_FIRST_COLUMN);

	u8 local_pressed_key;

	for(u8 iterator = 0; iterator < 6; iterator++)
	{
		do
		{
			local_pressed_key = keypad_u8GetPressedKey();
		}while(local_pressed_key == NO_KEY_PRESSED_VALUE);

		if(NO_KEY_PRESSED_VALUE != local_pressed_key)
		{
			local_error_state = local_checkPass_input(local_pressed_key);
			lcd_vidDisplyChar(local_pressed_key);
		}

	}

	if(local_error_state)
	{
		lcd_vidSendCmd(_LCD_CLEAR);
		lcd_vidDisplyStr("Correct Pass");

		_delay_ms(2500);

		lcd_vidSendCmd(_LCD_CLEAR);
		local_vidResetPass();
	}
	else
	{
		lcd_vidSendCmd(_LCD_CLEAR);
		lcd_vidDisplyStr("Incorrect Pass");
	}
	_delay_ms(5000);
	lcd_vidSendCmd(_LCD_CLEAR);
	index_counter = 0;
}

boolean local_checkPass_input(u8 letter)
{

	if(password[index_counter] == letter)
	{
		index_counter++;
		return TRUE;
	}
	else
	{
		index_counter++;
		return FALSE;
	}
}

void local_vidResetPass()
{
	lcd_vidDisplyStr("Enter New Pass:");
	LCD_voidGotoXY(LCD_u8_SECOND_LINE, LCD_u8_FIRST_COLUMN);

	index_counter = 0;
	u8 local_pressed_key;

	for(u8 iterator = 0; iterator < 6; iterator++)
	{
		do
		{
			local_pressed_key = keypad_u8GetPressedKey();
		}while(local_pressed_key == NO_KEY_PRESSED_VALUE);

		if(NO_KEY_PRESSED_VALUE != local_pressed_key)
		{
			lcd_vidDisplyChar(local_pressed_key);
			password[index_counter] = local_pressed_key;
			index_counter++;
		}

	}

	lcd_vidSendCmd(_LCD_CLEAR);
	lcd_vidDisplyStr("Pass Changed");
}








