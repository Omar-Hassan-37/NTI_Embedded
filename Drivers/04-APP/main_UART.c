/*
 * main_UART.c
 *
 *  Created on: Mar 3, 2023
 *      Author: oh377
 */

#include "std_types.h"

#include <util/delay.h>

#include "dio.h"
#include "led.h"
#include "lcd.h"
#include "EXTI_int.h"
#include "UART_int.h"

//buffer BUFF_arr;
u8 str[] = "Hello";

void transmit_str_ISR(void);
extern void (*UART_TX_CallBack)(void);
void (*ptr)(void);

int main(void)
{

	led_init();
//	led_on(LED_RED);


	u8 data;
	//UART_Init(UART_BAUDRATE_9600);
	ptr = transmit_str_ISR;

	//UART_voidTxCallBack(transmit_str_ISR);
//
	//EXT_voidEnableGlobalInt();
//
//	BUFF_arr.byte_index = 0;
//
//	UART_TransmitStr("omar");
	//UART_TransmitChr('A');
	ptr();
//	transmit_str_ISR();
	while(1)
	{

//		UART_ReceiveChr(&data);
//		if(data == 'A')
//		{
//			led_toggle(LED_RED);
//		}
//		UART_TransmitChr(data);

		_delay_ms(500);
	}
	return 0;
}


void transmit_str_ISR(void)
{
	led_on(LED_RED);
	//UART_TransmitChr('N');
}
