#ifndef GPIO_INT_H_
#define GPIO_INT_H_


#include "std_types.h"

#define GPIO_PORTA                  0
#define GPIO_PORTB                  1
#define GPIO_PORTC                  2
#define GPIO_PORTD                  3
#define GPIO_PORTE                  4
#define GPIO_PORTH                  5


#define PIN0                        0
#define PIN1                        1
#define PIN2                        2
#define PIN3                        3
#define PIN4                        4
#define PIN5                        5
#define PIN6                        6
#define PIN7                        7
#define PIN8                        8
#define PIN9                        9
#define PIN10                       10
#define PIN11                       11
#define PIN12                       12
#define PIN13                       13
#define PIN14                       14
#define PIN15                       15

#define INTPUT                      0
#define OUTPUT                      1
#define ALT_MODE                    2
#define ANALOG_MODE                 3

#define low                         0
#define HIGH                        1


void GPIO_voidInit(u8 Copy_u8Port)
void GPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);
void GPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);


#endif