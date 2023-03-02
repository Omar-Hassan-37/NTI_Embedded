
#ifndef _TIMR_REG
#define _TIMR_REG

#define TCCR0 *((volatile u8*)0x53)		/*Timer/Counter0 Control Register */
#define TCCR0_WGM00 6					/*Waveform Generation Mode bit 00*/
#define TCCR0_COM01 5					/*Compare Match Output Mode configuration bit 01*/
#define TCCR0_COM00 4					/*Compare Match Output Mode configuration bit 00*/
#define TCCR0_WGM01 3					/*Waveform Generation Mode bit 01*/
#define TCCR0_CS02 	2					/*Timer/Counter0 Clock Select bit 02*/
#define TCCR0_CS01 	1					/*Timer/Counter0 Clock Select bit 01*/
#define TCCR0_CS00 	0					/*Timer/Counter0 Clock Select bit 02*/

#define TCNT0 *((volatile u8*)0x52)		/*Timer/Counter0 Register*/
#define OCR0 	*((volatile u8*)0x5c)	/*Timer/Counter0 Output Compare Register*/

#define TIMSK *((volatile u8*)0x59) 	/*Timer/Counter0 Interrupt Mask Register*/
#define TIMSK_OCIE2		7				/*Timer/Counter2 Output Compare Match Interrupt Enable*/
#define TIMSK_TOIE2		6				/*Timer/Counter2 Overflow Interrupt Enable*/
#define TIMSK_OCIE1A	4				/*Timer/Counter1 Output Compare Channel A Match Interrupt Enable*/
#define TIMSK_OCIE1B	3				/*Timer/Counter1 Output Compare Channel B Match Interrupt Enable*/
#define TIMSK_TOIE1		2				/*Timer/Counter1 Overflow Interrupt Enable*/
#define TIMSK_OCIE0 	1				/*Timer/Counter0 Output Compare Match Interrupt Enable*/
#define TIMSK_TOIE0 	0				/*Timer/Counter0 Overflow Interrupt Enable*/





#define TIFR *((volatile u8*)0x58)		/*Timer/Counter Interrupt Flag Register */
#define TIFR_OCF2	7					/*Timer/Counter2 Output Compare Flag*/
#define TIFR_TOV2	6					/*Timer/Counter2 Overflow Flag*/
#define TIFR_ICF1	5					/*Timer/Counter1 Input Capture Flag*/
#define TIFR_OCF1A	4					/*Timer/Counter1 Output Compare Channel A Match Flag*/
#define TIFR_OCF1B	3					/*Timer/Counter1 Output Compare Channel B Match Flag*/
#define TIFR_TOV1	2					/*Timer/Counter1 Overflow Flag*/
#define TIFR_OCF0	1					/*Timer/Counter0 Output Compare Flag*/
#define TIFR_TOV0	0					/*Timer/Counter0 Overflow Flag*/


#define TCCR1A	*((volatile u8*)0x4f)	/*Timer/Counter1 Control Register A*/
#define TCCR1A_COM1A1	7				/*Timer/Counter1 Compare Output Mode For Channel A bit 1*/
#define TCCR1A_COM1A0	6				/*Timer/Counter1 Compare Output Mode For Channel A bit 0*/
#define TCCR1A_COM1B1	5				/*Timer/Counter1 Compare Output Mode For Channel B bit 1*/
#define TCCR1A_COM1B0	4				/*Timer/Counter1 Compare Output Mode For Channel B bit 0*/
#define TCCR1A_WGM11	1				/*Timer/Counter1 Waveform generation Mode bit1*/
#define TCCR1A_WGM10	0				/*Timer/Counter1 Waveform generation Mode bit0*/


#define TCCR1B	*((volatile u8*)0x4e)	/*Timer/Counter1 Control Register B*/
#define TCCR1B_WGM13	4				/*Timer/Counter1 Waveform generation Mode bit3*/
#define TCCR1B_WGM12	3				/*Timer/Counter1 Waveform generation Mode bit2*/
#define TCCR1B_CS12		2				/*Timer/Counter1 Clock Select bit 2*/
#define TCCR1B_CS11		1				/*Timer/Counter1 Clock Select bit 1*/
#define TCCR1B_CS10		0				/*Timer/Counter1 Clock Select bit 0*/

#define TCNT1 *((volatile u16*)0x4c)	/*Timer/Countrer1 Register*/

#define OCR1A *((volatile u16*)0x4a)	/*Timer/Counter1 Output Compare Register channel A*/

#define OCR1B *((volatile u16*)0x48)	/*Timer/Counter1 Output Compare Register channel B*/


#define TCCR2 *((volatile u8*)0x45)		/*Timer/Counter2 Control Register */
#define TCCR2_WGM20 	6					/*Waveform Generation Mode bit 00*/
#define TCCR2_COM21		5					/*Compare Match Output Mode configuration bit 01*/
#define TCCR2_COM20 	4					/*Compare Match Output Mode configuration bit 00*/
#define TCCR2_WGM21 	3					/*Waveform Generation Mode bit 01*/
#define TCCR2_CS22 		2					/*Timer/Counter2 Clock Select bit 02*/
#define TCCR2_CS21 		1					/*Timer/Counter2 Clock Select bit 01*/
#define TCCR2_CS20 		0					/*Timer/Counter2 Clock Select bit 02*/

#define TCNT2 *((volatile u8*)0x44)		/*Timer/Countrer2 Register*/

#define OCR2 	*((volatile u8*)0x43)	/*Timer/Counter2 Output Compare Register*/

#endif
