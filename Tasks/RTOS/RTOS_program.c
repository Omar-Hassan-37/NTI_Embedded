/**************************************************/
/**************************************************/
/**************  Author: EmanAssem  **************/
/**************  Layer:  RTOS stack **************/
/**************  SWC:    RTOS       **************/
/**************  Version:1.00       **************/
/**************************************************/
/**************************************************/

//LIB LAYER
#include "STD_TYPES.h"

//MCAL LAYER
#include "TMR_interface.h"
#include "GIE_interface.h"

//RTOS LAYER
#include "RTOS_private.h"
#include "RTOS_interface.h"
#include "RTOS_config.h"


Task_t SystemTasks[TASKS_NUMBER]={{NULL}};

void RTOS_voidStart(void)
{
	//1-Pass to timer ISR scheduler function to call task every specific time
	TMR_timer0_CTC_SetCallBack(voidSchedular);
	
	//2-Enable global interrupt
	GIE_voidEnable();
	
	//3-Timer Initialize
	TMR_timer0Init();
	
	
}

void RTOS_voidCreateTask(u8 priority, u32 periodicity, void (*ptr_TaskFunc)(void))
{
	SystemTasks[priority].periodicity = periodicity;
	SystemTasks[priority].taskFunc = ptr_TaskFunc;
}

static void voidSchedular(void)
{
	static u32 counter = 59999;
	counter++;
	if(counter > 82000){counter = 0;}
	for(u8 priority = 0; priority < TASKS_NUMBER; priority++)
	{
		if(counter % SystemTasks[priority].periodicity == 0)
		{
			if(SystemTasks[priority].taskFunc != NULL){
				SystemTasks[priority].taskFunc();
			}
		}
	}
}




