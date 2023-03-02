/*
 * main_stepper.c
 *
 *  Created on: Feb 25, 2023
 *      Author: oh377
 */

#include "std_types.h"
#include "dio.h"
#include "STEPPER_int.h"

void main (void)
{
	STEPPER_voidInit();

	while(1)
	{
		STEPPER_voidMoveFullStep(0, RIGHT);
	}
}

