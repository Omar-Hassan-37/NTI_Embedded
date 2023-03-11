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

	SPI_voidSlaveInit();

	led_init();

//	led_on(LED_GREEN);
//	lcd_vidDisplyChar(data);


	SPI_voidSPICallBackFunc(send_rec_ISR, &data);

	SPI_voidEnableInterrupt();

	EXT_voidEnableGlobalInt();

	while(1)
	{
		data = SPI_voidMasterSendByte('A');
		_delay_ms(500);
	}
	return 0;
}

void send_rec_polling(void)
{
	data = SPI_voidSlaveSendByte('M');
	if(data == 'M')
	{
		led_toggle(LED_GREEN);
//			_delay_ms(1000);
		data = 0;
	}
}

void send_rec_ISR(void)
{
	if(data == 'M')
	{
		led_toggle(LED_GREEN);
		_delay_ms(100);
	}
}
