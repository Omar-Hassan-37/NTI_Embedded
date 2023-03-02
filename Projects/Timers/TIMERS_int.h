
#ifndef _TIMERS_INT_H
#define _TIMERS_INT_H

#define TIMER0_PWM_PORT		DIO_PORTB
#define TIMER0_PWM_PIN		DIO_PIN3

#define TIMER1_PWM_PORT		DIO_PORTD
#define TIMER1_PWM_OC1A		DIO_PIN5
#define TIMER1_PWM_OC1B		DIO_PIN4

#define TIMER2_PWM_PORT		DIO_PORTD
#define TIMER2_PWM_PIN		DIO_PIN7

/* TIMER0 Functions*/
void TIMER0_void_Init(void);

void TIMER0_void_SetTimerReg(u8 Copy_uint8Val);

void TIMER0_void_SetCompareVal(u8 Copy_uint8Val);

void TIMER0_void_EnableOVInt(void);

void TIMER0_void_DisableOVInt(void);

void TIMER0_void_EnableCTCInt(void);

void TIMER0_void_DisableCTCInt(void);

void TIMER0_void_SetOVCallBack(void (*Copy_ptr) (void) ) ;

void TIMER0_void_SetCTCCallBack(void (*Copy_ptr) (void) ) ;

/*********************************************************************************************************************************************/

/*TIMER1 Functions*/
void TIMER1_void_Init(void);

void TIMER1_void_SetTimerReg(u8 Copy_uint8Val);

void TIMER1_void_SetCompareVal_A(u8 Copy_uint8Val);

void TIMER1_void_SetCompareVal_B(u8 Copy_uint8Val);

void TIMER1_void_EnableOVInt(void);

void TIMER1_void_DisableOVInt(void);

void TIMER1_void_EnableCTCInt_A(void);

void TIMER1_void_DisableCTCInt_A(void);

void TIMER1_void_EnableCTCInt_B(void);

void TIMER1_void_DisableCTCInt_B(void);

void TIMER1_void_SetOVCallBack(void (*Copy_ptr) (void) ) ;

void TIMER1_void_SetCTCCallBack_A(void (*Copy_ptr) (void) ) ;

void TIMER1_void_SetCTCCallBack_B(void (*Copy_ptr) (void) ) ;

/**********************************************************************************************************************************************/

/* TIMER0 Functions*/
void TIMER2_void_Init(void);

void TIMER2_void_SetTimerReg(u8 Copy_uint8Val);

void TIMER2_void_SetCompareVal(u8 Copy_uint8Val);

void TIMER2_void_EnableOVInt(void);

void TIMER2_void_DisableOVInt(void);

void TIMER2_void_EnableCTCInt(void);

void TIMER2_void_DisableCTCInt(void);

void TIMER2_void_SetOVCallBack(void (*Copy_ptr) (void) ) ;

void TIMER2_void_SetCTCCallBack(void (*Copy_ptr) (void) ) ;

#endif
