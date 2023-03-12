#ifndef			RCC_INTERFACE_H
#define			RCC_INTERFACE_H

#define			RCC_AHB1		0
#define			RCC_APB2		1
#define			RCC_APB1		2

#define			RCC_GPIOA		0

void	RCC_voidInit(void);

void	RCC_voidEnPerRCC(u8 BusId,u8 PerId);
void	RCC_voidDisPerRCC(u8 BusId,u8 PerId);




#endif