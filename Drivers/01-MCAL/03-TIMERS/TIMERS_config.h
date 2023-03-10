
#ifndef _TIMER_CONFIG_H
#define _TIMER_CONFIG_H

/*Range
#define TIMER0_NORMAL 		
#define TIMER0_CTC 			
#define TIMER0_FAST_PWM 	
#define TIMER0_PHASE_PWM 	
*/

#define TIMER0_MODE 		TIMER0_FAST_PWM
/*Range
//#define		NO_PRESCALLER			0
#define TIMER0_DIV_BY_1			
#define TIMER0_DIV_BY_8			
#define TIMER0_DIV_BY_64		
#define TIMER0_DIV_BY_256		
#define TIMER0_DIV_BY_1024		
*/
#define TIMER0_PRESCALER  	TIMER0_DIV_BY_1024

/*Range
#define TIMER0_NO_ACTION	
#define TIMER0_TOGGLE		
#define TIMER0_SET			
#define TIMER0_CLEAR		
*/

#define TIMER0_COM_EVENT   TIMER0_SET

/*Range
TIMER1_NORMAL
TIMER1_PWM_PHASE_CORRECT_8_BIT
TIMER1_PWM_PHASE_CORRECT_9_BIT
TIMER1_PWM_PHASE_CORRECT_10_BIT
TIMER1_CTC_OCR1A
TIMER1_FAST_PWM_8_BIT
TIMER1_FAST_PWM_9_BIT
TIMER1_FAST_PWM_10_BIT
TIMER1_PHASE_FREQ_ICR1
TIMER1_PHASE_FREQ_OCR1A
TIMER1_PWM_PHASE_CORRECT_ICR1
TIMER1_PWM_PHASE_CORRECT_OCR1A
TIMER1_CTC_ICR1
TIMER1_FAST_PWM_ICR1
TIMER1_FAST_PWM_OCR1A
 */
#define TIMER1_MODE				TIMER1_NORMAL

/*Range
TIMER1_DIV_BY_1
TIMER1_DIV_BY_8
TIMER1_DIV_BY_64
TIMER1_DIV_BY_256
TIMER1_DIV_BY_1024
 */
#define TIMER1_PRESCALER  	TIMER1_DIV_BY_1024

/*Range
TIMER1_NORMAL_PORT_OPER
TIMER1_TOGGLE
TIMER1_CLEAR
TIMER1_SET
 */
#define TIMER1_COM_EVENT   TIMER1_NORMAL_PORT_OPER


/*Range
#define TIMER2_NORMAL
#define TIMER2_CTC
#define TIMER2_FAST_PWM
#define TIMER2_PHASE_PWM
*/

#define TIMER2_MODE 		TIMER2_NORMAL
/*Range
//#define		NO_PRESCALLER			0
#define TIMER2_DIV_BY_1
#define TIMER2_DIV_BY_8
#define TIMER2_DIV_BY_32
#define TIMER2_DIV_BY_64
#define TIMER2_DIV_BY_128
#define TIMER2_DIV_BY_256
#define TIMER2_DIV_BY_1024
*/
#define TIMER2_PRESCALER  	TIMER2_DIV_BY_1024

/*Range
#define TIMER2_NO_ACTION
#define TIMER2_TOGGLE
#define TIMER2_SET
#define TIMER2_CLEAR
*/

#define TIMER2_COM_EVENT   TIMER2_NO_ACTION

#endif
