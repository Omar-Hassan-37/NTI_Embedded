/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  dio.h
 *       Module:  dio
 *
 *  Description:  dio APIs  
 *  
 *********************************************************************************************************************/
#ifndef DIO_H_H
#define DIO_H_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"
#include "bit_math.h"
#include "dio_reg.h"
#include "dio_types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void dio_vidConfigChannel(dio_portId_t port, dio_channelId_t channel, dio_direction_t direction);
void dio_vidWriteChannel(dio_portId_t port, dio_channelId_t channel, dio_level_t level);
void dio_vidSetPortDir(dio_portId_t port, u8 direction);
void dio_vidSetPortValue(dio_portId_t port, u8 value);
void dio_vidWriteChannelGroup(dio_portId_t port,u8 value,u8 mask,u8 position);
void dio_vidFlipChannel(dio_portId_t port, dio_channelId_t channel);
dio_level_t dio_dioLevelReadChannel(dio_portId_t port, dio_channelId_t channel);
void dio_vidEnablePullUp(dio_portId_t port, dio_channelId_t channel);
//
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: FILE_NAME.h
 *********************************************************************************************************************/
