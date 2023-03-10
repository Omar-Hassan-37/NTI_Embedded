/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  lcd_types.h
 *       Module:  lcd
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef LCD_TYPES_H
#define LCD_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum{
	_LCD_CLEAR=0x01,
	_LCD_CURSOR_OFF=0x0C,
	_LCD_CURSOR_ON=0x0F,
	_LCD_4BIT_MODE=0x28,
	_LCD_8BIT_MODE=0x38,
	_LCD_ON=0x0F,
	_LCD_CURSOR_UNDERLINE=0x0E,
	_LCD_CURSOR_SHIFT_LEFT=0x10,
	_LCD_CURSOR_SHIFT_RIGHT=0x14,
	_LCD_CURSOR_INCREMENT=0x06,
	_LCD_CGRAM_START_ADDRESS=0x40
}lcd_cmd_t;

typedef enum{
	LCD_u8_FIRST_LINE = 0,
	LCD_u8_SECOND_LINE	= 1
}lcd_row_t;

typedef enum{
	LCD_u8_FIRST_COLUMN	= 0,
	LCD_u8_SECOND_COLUMN = 1,
	LCD_u8_THIRD_COLUMN	= 2,
	LCD_u8_FOURTH_COLUMN = 3,
	LCD_u8_FIFTH_COLUMN	= 4,
	LCD_u8_SIXTH_COLUMN	= 5,
	LCD_u8_SEVENTH_COLUM = 6,
	LCD_u8_EIGHTH_COLUMN = 7,
	LCD_u8_NINTH_COLUMN	= 8,
	LCD_u8_TENTH_COLUMN	= 9,
	LCD_u8_ELEVENTH_COLUMN	= 10,
	LCD_u8_TWELFTH_COLUMN = 11,
	LCD_u8_THIRTEENTH_COLUMN = 12,
	LCD_u8_FOURTEENTH_COLUMN = 13,	
	LCD_u8_FIFTEENTH_COLUMN	 = 14,
	LCD_u8_SIXTEENTH_COLUMN	 = 15
}lcd_column_t;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* LCD_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: lcd_types.h
 *********************************************************************************************************************/
