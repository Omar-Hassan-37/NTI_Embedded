/*
 * main_SPI.c
 *
 *  Created on: Mar 4, 2023
 *      Author: oh377
 */

#include "std_types.h"

#include "dio.h"
#include "led.h"
#include "EXTI_int.h"
#include "SPI_int.h"
#include <util/delay.h>


u8 data;

void send_rec_polling(void);
void send_rec_ISR(void);

int main(void)
{

	led_init();
	SPI_voidMasterInit();

//	_delay_ms(1000);


	SPI_voidSPICallBackFunc(send_rec_ISR, &data);

	SPI_voidEnableInterrupt();

	EXT_voidEnableGlobalInt();

	while(1)
	{
		data = SPI_voidMasterSendByte('M');
		_delay_ms(500);
	}
	return 0;
}

void send_rec_polling(void)
{
	led_toggle(LED_GREEN);
	data = SPI_u8MasterRecieveByte();
	if(data == 'O')
	{
		led_toggle(LED_GREEN);
		_delay_ms(100);
	}
	_delay_ms(100);
}

void send_rec_ISR(void)
{
	if(data == 'A')
	{
		led_toggle(LED_GREEN);
		_delay_ms(100);
	}
}
