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
	
	
	//2-Enable global interrupt
	
	
	//3-Timer Initialize
	
	
	
}

void RTOS_voidCreateTask(u8 priority, u16 periodicity, void (*ptr_TaskFunc)(void))
{

}
static void voidSchedular(void)
{
	
}




