
#include "bit_math.h"

#include "GPIO_int.h"
#include "GPIO_private.h"
#include "GPIO_cfg.h"


void GPIO_voidInit(u8 Copy_u8Port)
{
	RCC_voidEnPerRCC(RCC_AHB1, Copy_u8Port);
}

void GPIO_voidDisable(u8 Copy_u8Port)
{
	RCC_voidDisPerRCC(RCC_AHB1, Copy_u8Port);
}

void	GPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
	if(Copy_u8Port < 6 && Copy_u8Pin < 16)
	{
		if(Copy_u8Direction == INPUT)
		{
			switch(Copy_u8Port)
			{
				case GPIO_PORTA:	
					CLEAR_BIT(GPIOA_MODER, (Copy_u8Pin*2));
					CLEAR_BIT(GPIOA_MODER, ((Copy_u8Pin*2)+1));
					break;

				case GPIO_PORTB:	
					CLEAR_BIT(GPIOB_MODER, (Copy_u8Pin*2));
					CLEAR_BIT(GPIOB_MODER, ((Copy_u8Pin*2)+1));
					break;

				case GPIO_PORTC:	
					CLEAR_BIT(GPIOC_MODER, (Copy_u8Pin*2));
					CLEAR_BIT(GPIOC_MODER, ((Copy_u8Pin*2)+1));
					break;

				case GPIO_PORTD:	
					CLEAR_BIT(GPIOD_MODER, (Copy_u8Pin*2));
					CLEAR_BIT(GPIOD_MODER, ((Copy_u8Pin*2)+1));
					break;

				case GPIO_PORTE:	
					CLEAR_BIT(GPIOE_MODER, (Copy_u8Pin*2));
					CLEAR_BIT(GPIOE_MODER, ((Copy_u8Pin*2)+1));
					break;

				case GPIO_PORTH:	
					CLEAR_BIT(GPIOH_MODER, (Copy_u8Pin*2));
					CLEAR_BIT(GPIOH_MODER, ((Copy_u8Pin*2)+1));
					break;
			}
		}
		else if(Copy_u8Direction == OUTPUT)
		{
			switch(Copy_u8Port)
			{
				case GPIO_PORTA:	
					SET_BIT(GPIOA_MODER, (Copy_u8Pin*2));
					CLEAR_BIT(GPIOA_MODER, ((Copy_u8Pin*2)+1));
					break;
				case GPIO_PORTB:	
					SET_BIT(GPIOB_MODER, (Copy_u8Pin*2));
					CLEAR_BIT(GPIOB_MODER, ((Copy_u8Pin*2)+1));
					break;
				case GPIO_PORTC:	
					SET_BIT(GPIOC_MODER, (Copy_u8Pin*2));
					CLEAR_BIT(GPIOC_MODER, ((Copy_u8Pin*2)+1));
					break;
				case GPIO_PORTD:	
					SET_BIT(GPIOD_MODER, (Copy_u8Pin*2));
					CLEAR_BIT(GPIOD_MODER, ((Copy_u8Pin*2)+1));
					break;
				case GPIO_PORTE:	
					SET_BIT(GPIOE_MODER, (Copy_u8Pin*2));
					CLEAR_BIT(GPIOE_MODER, ((Copy_u8Pin*2)+1));
					break;
				case GPIO_PORTH:	
					SET_BIT(GPIOH_MODER, (Copy_u8Pin*2));
					CLEAR_BIT(GPIOH_MODER, ((Copy_u8Pin*2)+1));
					break;
			}
		}
		else if(Copy_u8Direction == ALT_MODE)
		{
			switch(Copy_u8Port)
			{
				case GPIO_PORTA:	
					CLEAR_BIT(GPIOA_MODER, (Copy_u8Pin*2));
					SET_BIT(GPIOA_MODER, ((Copy_u8Pin*2)+1));
					break;

				case GPIO_PORTB:	
					CLEAR_BIT(GPIOB_MODER, (Copy_u8Pin*2));
					SET_BIT(GPIOB_MODER, ((Copy_u8Pin*2)+1));
					break;

				case GPIO_PORTC:	
					CLEAR_BIT(GPIOC_MODER, (Copy_u8Pin*2));
					SET_BIT(GPIOC_MODER, ((Copy_u8Pin*2)+1));
					break;

				case GPIO_PORTD:	
					CLEAR_BIT(GPIOD_MODER, (Copy_u8Pin*2));
					SET_BIT(GPIOD_MODER, ((Copy_u8Pin*2)+1));
					break;

				case GPIO_PORTE:	
					CLEAR_BIT(GPIOE_MODER, (Copy_u8Pin*2));
					SET_BIT(GPIOE_MODER, ((Copy_u8Pin*2)+1));
					break;

				case GPIO_PORTH:	
					CLEAR_BIT(GPIOH_MODER, (Copy_u8Pin*2));
					SET_BIT(GPIOH_MODER, ((Copy_u8Pin*2)+1));
					break;
			}
		}
		else if(Copy_u8Direction == ANALOG_MODE)
		{
			switch(Copy_u8Port)
			{
				case GPIO_PORTA:	
					SET_BIT(GPIOA_MODER, (Copy_u8Pin*2));
					SET_BIT(GPIOA_MODER, ((Copy_u8Pin*2)+1));
					break;

				case GPIO_PORTB:	
					SET_BIT(GPIOB_MODER, (Copy_u8Pin*2));
					SET_BIT(GPIOB_MODER, ((Copy_u8Pin*2)+1));
					break;

				case GPIO_PORTC:	
					SET_BIT(GPIOC_MODER, (Copy_u8Pin*2));
					SET_BIT(GPIOC_MODER, ((Copy_u8Pin*2)+1));
					break;

				case GPIO_PORTD:	
					SET_BIT(GPIOD_MODER, (Copy_u8Pin*2));
					SET_BIT(GPIOD_MODER, ((Copy_u8Pin*2)+1));
					break;

				case GPIO_PORTE:	
					SET_BIT(GPIOE_MODER, (Copy_u8Pin*2));
					SET_BIT(GPIOE_MODER, ((Copy_u8Pin*2)+1));
					break;

				case GPIO_PORTH:	
					SET_BIT(GPIOH_MODER, (Copy_u8Pin*2));
					SET_BIT(GPIOH_MODER, ((Copy_u8Pin*2)+1));
					break;
			}
		}
	}
}

void	GPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
		/*	Range Check		*/
	if(Copy_u8Port < 6 && Copy_u8Pin < 16)
	{
		if(Copy_u8Value == HIGH)
		{
			switch(Copy_u8Port)
			{
				case GPIO_PORTA	:	SET_BIT(GPIOA_ODR,PIN);	break;
				case GPIO_PORTB	:	SET_BIT(GPIOB_ODR,PIN);	break;
	       		case GPIO_PORTC	:	SET_BIT(GPIOC_ODR,PIN);	break;
				case GPIO_PORTD	:	SET_BIT(GPIOD_ODR,PIN);	break;
				case GPIO_PORTE	:	SET_BIT(GPIOE_ODR,PIN);	break;
	       		case GPIO_PORTH	:	SET_BIT(GPIOH_ODR,PIN);	break;
			}
		}
		else if(Copy_u8Value == LOW)
		{
			switch(Copy_u8Port)
			{
				case GPIO_PORTA	:	CLEAR_BIT(GPIOA_ODR,PIN);	break;
				case GPIO_PORTB	:	CLEAR_BIT(GPIOB_ODR,PIN);	break;
	       		case GPIO_PORTC	:	CLEAR_BIT(GPIOC_ODR,PIN);	break;
				case GPIO_PORTD	:	CLEAR_BIT(GPIOD_ODR,PIN);	break;
				case GPIO_PORTE	:	CLEAR_BIT(GPIOE_ODR,PIN);	break;
	       		case GPIO_PORTH	:	CLEAR_BIT(GPIOH_ODR,PIN);	break;
			}
		}
		
	}
}

u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 result = 0;
	switch(Copy_u8Port)
	{
		case GPIO_PORTA:	result = CHECK_BIT(GPIOA_IDR, Copy_u8Pin); break;
		case GPIO_PORTB:	result = CHECK_BIT(GPIOB_IDR, Copy_u8Pin); break;
		case GPIO_PORTC:	result = CHECK_BIT(GPIOC_IDR, Copy_u8Pin); break;
		case GPIO_PORTD:	result = CHECK_BIT(GPIOD_IDR, Copy_u8Pin); break;
		case GPIO_PORTE:	result = CHECK_BIT(GPIOE_IDR, Copy_u8Pin); break;
		case GPIO_PORTH:	result = CHECK_BIT(GPIOH_IDR, Copy_u8Pin); break;
	}
	return result;
}