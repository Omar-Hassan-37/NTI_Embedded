
/**************************************************/
/**************************************************/
/**************  Author: Eman Assem  **************/
/**************  Layer:  MCAL        **************/
/**************  SWC:    DIO         **************/
/**************  Version:1.00        **************/
/**************************************************/
/**************************************************/

#define F_CPU 16000000UL
#include <util/delay.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ERR_TYPE.h"

#include "DIO_reg.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"




u8 DIO_u8SetPinDirection(u8 copy_u8Port,u8 Copy_u8PinNumber,u8 Copy_u8PinDirection)
{
	u8 Local_u8ErrorState = OK; 

	if(Copy_u8PinNumber <= DIO_u8PIN7 )  
	{
		if(Copy_u8PinDirection == DIO_u8PIN_INPUT) 
		{
			switch(copy_u8Port)
			{
				case DIO_u8PORTA : CLR_BIT(DDRA,Copy_u8PinNumber); break;
				case DIO_u8PORTB : CLR_BIT(DDRB,Copy_u8PinNumber); break;
				case DIO_u8PORTC : CLR_BIT(DDRC,Copy_u8PinNumber); break;
				case DIO_u8PORTD : CLR_BIT(DDRD,Copy_u8PinNumber); break;
				default : Local_u8ErrorState = NOK ; break;
			}
		}

		else if(Copy_u8PinDirection == DIO_u8PIN_OUTPUT) 
		{
			switch(copy_u8Port)
			{
				case DIO_u8PORTA : SET_BIT(DDRA,Copy_u8PinNumber); break;  
				case DIO_u8PORTB : SET_BIT(DDRB,Copy_u8PinNumber); break;
				case DIO_u8PORTC : SET_BIT(DDRC,Copy_u8PinNumber); break;
				case DIO_u8PORTD : SET_BIT(DDRD,Copy_u8PinNumber); break;
				default : Local_u8ErrorState = NOK; break;
			}
		}

		else //IF NOT INPUT OR OUTPUT
		{
			Local_u8ErrorState = NOK;
		}

	}

	else//PIN  NUMBER
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
		
}
u8 DIO_u8SetPortDirection(u8 copy_u8Port,u8 Copy_u8PortDirection)
{
		u8 Local_u8ErrorState = OK; 
		
		if(copy_u8Port<=DIO_u8PORTD)
		{
if(Copy_u8PortDirection == DIO_u8PORT_INPUT || Copy_u8PortDirection == DIO_u8PORT_OUTPUT)
{
    switch (copy_u8Port)
{
	case DIO_u8PORTA: DDRA=Copy_u8PortDirection; break;
	case DIO_u8PORTB: DDRB=Copy_u8PortDirection; break;
	case DIO_u8PORTC: DDRC=Copy_u8PortDirection; break;
	case DIO_u8PORTD: DDRD=Copy_u8PortDirection; break;
	default: Local_u8ErrorState =NOK;  break;
	
}

}
else
{
	Local_u8ErrorState=NOK;
}

		}
		else
		{
		Local_u8ErrorState=NOK;
		}
	return Local_u8ErrorState ;
	
}


u8 DIO_u8SetPinValue(u8 copy_u8Port,u8 Copy_u8PinNumber,u8 Copy_u8PinValue)
{
	u8 Local_u8ErrorState = OK; 
	
	
	if(Copy_u8PinNumber <= DIO_u8PIN7 )
	{
		if(Copy_u8PinValue == DIO_u8PIN_INPUT)
		{
			switch(copy_u8Port)
			{
				case DIO_u8PORTA : CLR_BIT(PORTA,Copy_u8PinNumber); break;
				case DIO_u8PORTB : CLR_BIT(PORTB,Copy_u8PinNumber); break;
				case DIO_u8PORTC : CLR_BIT(PORTC,Copy_u8PinNumber); break;
				case DIO_u8PORTD : CLR_BIT(PORTD,Copy_u8PinNumber); break;
				default : Local_u8ErrorState = NOK ; break;
			}
		}

		else if(Copy_u8PinValue == DIO_u8PIN_HIGH)
		{
			switch(copy_u8Port)
			{
				case DIO_u8PORTA : SET_BIT(PORTA,Copy_u8PinNumber); break;
				case DIO_u8PORTB : SET_BIT(PORTB,Copy_u8PinNumber); break;
				case DIO_u8PORTC : SET_BIT(PORTC,Copy_u8PinNumber); break;
				case DIO_u8PORTD : SET_BIT(PORTD,Copy_u8PinNumber); break;
				default : Local_u8ErrorState = NOK; break;
			}
		}

		else 
		{
			Local_u8ErrorState = NOK;
		}

	}

	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
	
	
}
u8 DIO_u8SetPortValue(u8 copy_u8Port, u8 Copy_u8Value)
{
			u8 Local_u8ErrorState = OK;
			
			if(copy_u8Port<=DIO_u8PORTD)
			{
				if(Copy_u8Value == DIO_u8PORT_LOW || Copy_u8Value == DIO_u8PORT_HIGH)
				{
					switch (copy_u8Port)
					{
						case DIO_u8PORTA: PORTA=Copy_u8Value; break;
						case DIO_u8PORTB: PORTB=Copy_u8Value; break;
						case DIO_u8PORTC: PORTC=Copy_u8Value; break;
						case DIO_u8PORTD: PORTD=Copy_u8Value; break;
						default :Local_u8ErrorState =NOK;  break;
						
					}

				}
				else
				{
					Local_u8ErrorState=NOK;
				}

			}
			else
			{
				Local_u8ErrorState=NOK;
			}
			return Local_u8ErrorState ;
	
	
}


u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_pu8Value)
{
	u8 Local_u8ErrorState = OK;
	if(Copy_u8Pin <= DIO_u8PIN7)
	{
		switch(Copy_u8Port)
		{
			case DIO_u8PORTA :*Copy_pu8Value=GET_BIT(PINA,Copy_u8Pin); break;
			case DIO_u8PORTB :*Copy_pu8Value=GET_BIT(PINB,Copy_u8Pin); break;
			case DIO_u8PORTC :*Copy_pu8Value=GET_BIT(PINC,Copy_u8Pin); break;
			case DIO_u8PORTD :*Copy_pu8Value=GET_BIT(PIND,Copy_u8Pin); break;
			default : Local_u8ErrorState = NOK ; break;
		}
		
	}else 
	{
		Local_u8ErrorState=NOK;
		
	}
	
	return Local_u8ErrorState ;
}

u8 DIO_u8TogglePinValue(u8 copy_u8Port,u8 Copy_u8PinNumber,u8 Copy_u8counter)
{u8 Local_u8ErrorState = OK;
	if(Copy_u8PinNumber <= DIO_u8PIN7)
	{
		switch(copy_u8Port)
		{
			case DIO_u8PORTA :TOG_BIT(PORTA,Copy_u8PinNumber); break;
			case DIO_u8PORTB :while(Copy_u8counter != 0){TOG_BIT(PORTB,Copy_u8PinNumber); _delay_ms(500);Copy_u8counter--;} break;
			case DIO_u8PORTC :while(Copy_u8counter != 0){TOG_BIT(PORTC,Copy_u8PinNumber); _delay_ms(500);Copy_u8counter--;} break;
			case DIO_u8PORTD :while(Copy_u8counter != 0){TOG_BIT(PORTD,Copy_u8PinNumber); _delay_ms(500);Copy_u8counter--;} break;
			default : Local_u8ErrorState = NOK ; break;
		}
		
	}else 
	{
		Local_u8ErrorState=NOK;
		
	}
	
	return Local_u8ErrorState ;
}