/**************************************************/
/**************************************************/
/**************  Author: EmanAssem  **************/
/**************  Layer:  RTOS stack **************/
/**************  SWC:    RTOS       **************/
/**************  Version:1.00       **************/
/**************************************************/
/**************************************************/
#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_


void RTOS_voidStart(void);

void RTOS_voidCreateTask(u8 priority, u32 periodicity, void (*ptr_TaskFunc)(void));



#endif
