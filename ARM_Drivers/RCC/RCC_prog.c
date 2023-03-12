#include "Std_Types.h"
#include "Bit_Math.h"

#include "RCC_interface.h"



void	RCC_voidInit(void)
{

	#if CLK_SOURCE==HSI
	// enable HSI
	SET_BIT(RCC_CR, RCC_CR_HSION);
	// choose HSI as default clock
	CLEAR_BIT(RCC_CFGR, RCC_CFGR_SW0);
	CLEAR_BIT(RCC_CFGR, RCC_CFGR_SW1);

#elif	CLK_SOURCE==HSE
	// enable HSE
	SET_BIT(RCC_CR, RCC_CR_HSEON);
	// choose HSE as default clock
	SET_BIT(RCC_CFGR, RCC_CFGR_SW0);
	CLEAR_BIT(RCC_CFGR, RCC_CFGR_SW1);
#endif
}
/*	EN GPIOA RCC*/
//RCC_voidEnPerRCC(RCC_AHB1,0);
void	RCC_voidEnPerRCC(u8 BusId,u8 PerId)
{
	/*	Range Check		*/
	if(BusId <3 && PerId < 32)
	{
		switch(BusId)
		{
			case RCC_AHB1	:	SET_BIT(RCC_AHB1ENR,PerId);	break;
			case RCC_APB2	:	SET_BIT(RCC_APB2ENR,PerId);	break;
	        case RCC_APB1	:	SET_BIT(RCC_APB1ENR,PerId);	break;
		}
	}
}
void	RCC_voidDisPerRCC(u8 BusId,u8 PerId)
{
		/*	Range Check		*/
	if(BusId <3 && PerId < 32)
	{
		switch(BusId)
		{
			case RCC_AHB1	:	CLR_BIT(RCC_AHB1ENR,PerId);	break;
			case RCC_APB2	:	CLR_BIT(RCC_APB2ENR,PerId);	break;
	        case RCC_APB1	:	CLR_BIT(RCC_APB1ENR,PerId);	break;
		}
	}
}





