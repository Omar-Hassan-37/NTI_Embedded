/**************************************************/
/**************************************************/
/**************  Author: EmanAssem  **************/
/**************  Layer:  RTOS stack **************/
/**************  SWC:    RTOS       **************/
/**************  Version:1.00       **************/
/**************************************************/
/**************************************************/
#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

typedef struct 
{
	u16 periodicity;
	void (*taskFunc)(void);
}Task_t;

static void voidSchedular(void);

#endif
