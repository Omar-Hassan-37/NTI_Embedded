/*
 * RTOS_LAB1.c
 *
 * Author : Eman Assem
 */ 
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LCD_int.h"
#include "RTOS_interface.h"
#include "util/delay.h"

#define FIRST_DIGIT_LAST_NUM		10
#define SEC_DIGIT_LAST_NUM			7
#define MAX_TASKS_TO_COUNT			2

u8 sevenSeg_firstDigit[10] = {0b01100111, 0b01111111, 0b00000111, 0b01111101, 0b01101101,
							  0b01100110, 0b01001111, 0b01011011, 0b00000110, 0b00111111};
u8 sevenSeg_secDigit[7] = {0b01111101, 0b01101101, 0b01100110, 0b01001111,
						   0b01011011, 0b00000110, 0b00111111};


void ledOn_Red(void);
void traffic_Timer(void);
void ledOn_Yellow(void);
void ledOn_Green(void);

int main(void)
{

	DIO_u8SetPortDirection(DIO_u8PORTA, DIO_u8PIN_OUTPUT);
	DIO_u8SetPortDirection(DIO_u8PORTC, DIO_u8PIN_OUTPUT);
	DIO_u8SetPortDirection(DIO_u8PORTD, DIO_u8PIN_OUTPUT);


//	DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_HIGH);
//	DIO_u8SetPortValue(DIO_u8PORTC, sevenSeg_secDigit[0]);
	RTOS_voidCreateTask(0, 1000, traffic_Timer);

	RTOS_voidCreateTask(1, 60000, ledOn_Red);

	RTOS_voidCreateTask(2, 71000, ledOn_Yellow);

	RTOS_voidCreateTask(3, 82000, ledOn_Green);

	RTOS_voidStart();
    while (1) 
    {
    }
}

void ledOn_Red(void)
{
	DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_HIGH);
//	DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN1, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN2, DIO_u8PIN_LOW);
}

void traffic_Timer(void)
{
	static s8 task_counter = 0;
	static u8 firstDigit_counter = 9;
	static u8 secDigit_counter = 5;

	if(task_counter == MAX_TASKS_TO_COUNT)
	{
		task_counter = -1;
		secDigit_counter = 0;
	}

	DIO_u8SetPortValue(DIO_u8PORTC, sevenSeg_secDigit[secDigit_counter]);
	DIO_u8SetPortValue(DIO_u8PORTD, sevenSeg_firstDigit[firstDigit_counter]);

	if(firstDigit_counter < FIRST_DIGIT_LAST_NUM)
	{
		firstDigit_counter++;
	}
	if(secDigit_counter < SEC_DIGIT_LAST_NUM && firstDigit_counter == FIRST_DIGIT_LAST_NUM)
	{
		secDigit_counter++;
		firstDigit_counter = 0;
	}
	if(task_counter < MAX_TASKS_TO_COUNT && secDigit_counter == SEC_DIGIT_LAST_NUM &&  FIRST_DIGIT_LAST_NUM == FIRST_DIGIT_LAST_NUM)
	{
		task_counter++;
		firstDigit_counter = 9;
		secDigit_counter = 5;
	}
}

void ledOn_Yellow(void)
{
	DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN1, DIO_u8PIN_HIGH);
//	DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN2, DIO_u8PIN_LOW);
}

void ledOn_Green(void)
{
//	DIO_u8TogglePinValue(DIO_u8PORTA, DIO_u8PIN2, 0);
	DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN1, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN2, DIO_u8PIN_HIGH);
}
