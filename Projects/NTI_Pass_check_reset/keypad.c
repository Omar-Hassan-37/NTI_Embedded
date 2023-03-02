/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  keypad.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"
#include "dio.h"
#include "keypad.h"
#include "keypad_cfg.h"
#include <util/delay.h>
#include "lcd.h"
#include "led.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

#define COLUMNS_NUMBER	4
#define ROWS_NUMBER		4

#define KEYPAD_KEYS_ARR4x4		{ {'0','1','2','A'} , {'4','5','6','B'}, {'7','8','9','C'}, {'F','0','E','D'} }

static u8 keys_value[4][4]=
{
		{'1','2','3','A'},
		{'4','5','6','B'},
		{'7','8','9','C'},
		{'F','0','E','D'}
};

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void keypad_vidInit(void)        
* \Description     : keypad HW initialization                                
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                                                                         
* \Return value:   : None                               
*******************************************************************************/
void keypad_vidInit(void)
{
	/*	ROW channel direction -> output	*/
	dio_vidConfigChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_CHANNEL,INPUT);
	dio_vidConfigChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_CHANNEL,INPUT);
	dio_vidConfigChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_CHANNEL,INPUT);
	dio_vidConfigChannel(KEYPAD_ROW4_PORT,KEYPAD_ROW4_CHANNEL,INPUT);
	
	/*	COLUMN channel direction -> input	*/
	dio_vidConfigChannel(KEYPAD_COL1_PORT,KEYPAD_COL1_CHANNEL,OUTPUT);
	dio_vidConfigChannel(KEYPAD_COL2_PORT,KEYPAD_COL2_CHANNEL,OUTPUT);
	dio_vidConfigChannel(KEYPAD_COL3_PORT,KEYPAD_COL3_CHANNEL,OUTPUT);
	dio_vidConfigChannel(KEYPAD_COL4_PORT,KEYPAD_COL4_CHANNEL,OUTPUT);
	
	dio_vidWriteChannel(KEYPAD_COL1_PORT,KEYPAD_COL1_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_COL2_PORT,KEYPAD_COL2_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_COL3_PORT,KEYPAD_COL3_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_COL4_PORT,KEYPAD_COL4_CHANNEL,STD_HIGH);

	dio_vidWriteChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW4_PORT,KEYPAD_ROW4_CHANNEL,STD_HIGH);
}


static boolean keypad_bolIsPressed(void)
{
	if (
		!dio_dioLevelReadChannel(KEYPAD_COL1_PORT,KEYPAD_COL1_CHANNEL)||
		!dio_dioLevelReadChannel(KEYPAD_COL2_PORT,KEYPAD_COL2_CHANNEL)||
		!dio_dioLevelReadChannel(KEYPAD_COL3_PORT,KEYPAD_COL3_CHANNEL)||
		!dio_dioLevelReadChannel(KEYPAD_COL4_PORT,KEYPAD_COL4_CHANNEL)
		)
		{
		  return TRUE;
		}
		else
		{
		  return FALSE;
		}
}
static u8 keypad_GetCol(void)
{
	u8 loc_col = 0;
	if (STD_LOW == dio_dioLevelReadChannel(KEYPAD_COL1_PORT,KEYPAD_COL1_CHANNEL))
	{
		loc_col = 1;	
	}
	else if (STD_LOW == dio_dioLevelReadChannel(KEYPAD_COL2_PORT,KEYPAD_COL2_CHANNEL))
	{
	 loc_col = 2;	
	}
	else if (STD_LOW == dio_dioLevelReadChannel(KEYPAD_COL3_PORT,KEYPAD_COL3_CHANNEL))
	{
	 loc_col = 3;	
	}
	else if (STD_LOW == dio_dioLevelReadChannel(KEYPAD_COL4_PORT,KEYPAD_COL4_CHANNEL))
	{
	 loc_col = 4;	
	}
	else
	{
		/*	do nothing	*/
	}
	return loc_col;
}

static u8 keypad_GetRow(u8 col)
{
	u8 loc_row =0;
	
	dio_vidWriteChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_CHANNEL,STD_LOW);
	dio_vidWriteChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW4_PORT,KEYPAD_ROW4_CHANNEL,STD_HIGH);
	
	if (keypad_GetCol() == col)
	{
		while(keypad_GetCol() == col)
		{
			keypad_GetCol();
		}
		loc_row = 1;	
	}
	
	dio_vidWriteChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_CHANNEL,STD_LOW);
	dio_vidWriteChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW4_PORT,KEYPAD_ROW4_CHANNEL,STD_HIGH);
	if (keypad_GetCol() == col)
	{
		while(keypad_GetCol() == col)
		{
			keypad_GetCol();
		}
		loc_row = 2;	
	}
	
	dio_vidWriteChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_CHANNEL,STD_LOW);
	dio_vidWriteChannel(KEYPAD_ROW4_PORT,KEYPAD_ROW4_CHANNEL,STD_HIGH);
	if (keypad_GetCol() == col)
	{
		while(keypad_GetCol() == col)
		{
			keypad_GetCol();
		}
		loc_row = 3;	
	}
	
	dio_vidWriteChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW4_PORT,KEYPAD_ROW4_CHANNEL,STD_LOW);
	if (keypad_GetCol() == col)
	{
		while(keypad_GetCol() == col)
		{
			keypad_GetCol();
		}
		loc_row = 4;	
	}
	
	return loc_row;
}

u8 keypad_u8GetKey(void)
{
	u8 loc_row = 0;
	u8 loc_col = 0;
	
	if (TRUE == keypad_bolIsPressed())
	{
		loc_col = keypad_GetCol();
		loc_row = keypad_GetRow(loc_col);
		
//		 lcd_vidGotoRowColumn(0,0);
//		 lcd_vidDisplyChar(loc_row+48);
//		 lcd_vidGotoRowColumn(1,0);
//		 lcd_vidDisplyChar(loc_col+48);
		
		_delay_ms(250);
		keypad_vidInit();	
		return 	keys_value[loc_row-1][loc_col-1];
	}
	else
	{
		return 0xFF;
	}
}

u8 keypad_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey= NO_KEY_PRESSED_VALUE;
	u8 Local_u8ColumnIndex, Local_u8RowIndex, Local_u8PinState;

	u8 Local_u8KepadArr[ROWS_NUMBER][COLUMNS_NUMBER]= KEYPAD_KEYS_ARR4x4;

	u8 Local_u8RowsPinsArr[4]= {KEYPAD_ROW1_CHANNEL, KEYPAD_ROW2_CHANNEL,KEYPAD_ROW3_CHANNEL,KEYPAD_ROW4_CHANNEL};
	u8 Local_u8ColumnsPinsArr[4]= {KEYPAD_COL1_CHANNEL,KEYPAD_COL2_CHANNEL,KEYPAD_COL3_CHANNEL,KEYPAD_COL4_CHANNEL};

	for(Local_u8ColumnIndex=0; Local_u8ColumnIndex<COLUMNS_NUMBER; Local_u8ColumnIndex++)
	{
		/*Activate the current column*/
		dio_vidWriteChannel(KEYPAD_u8_PORT, Local_u8ColumnsPinsArr[Local_u8ColumnIndex], STD_LOW);

		for(Local_u8RowIndex=0; Local_u8RowIndex<ROWS_NUMBER; Local_u8RowIndex++)
		{
			/*Read the current row*/
			Local_u8PinState = dio_dioLevelReadChannel(KEYPAD_u8_PORT,Local_u8RowsPinsArr[Local_u8RowIndex]);

			/*Check if the key is pressed*/
			if(STD_LOW == Local_u8PinState )
			{
				Local_u8PressedKey= Local_u8KepadArr[Local_u8RowIndex][Local_u8ColumnIndex];

				/*Busy waiting (polling) until the key is released*/
				while(STD_LOW == Local_u8PinState)
				{
					Local_u8PinState = dio_dioLevelReadChannel(KEYPAD_u8_PORT,Local_u8RowsPinsArr[Local_u8RowIndex]);

				}
				_delay_ms(100);
				return Local_u8PressedKey;
			}
		}
			/*Deactivate the current row*/
			dio_vidWriteChannel(KEYPAD_u8_PORT, Local_u8ColumnsPinsArr[Local_u8ColumnIndex], STD_HIGH);
	}
	return Local_u8PressedKey;
}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
