/**-----------------------------------------------------------------------------------------------------------------
 * @file	config.h
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __MODBCD_CONFIG_H__
#define __MODBCD_CONFIG_H__


#if defined(__cplusplus)
extern "C" {
#endif


/*------------------------------------------------------------------------------------------------------------------
 * 
 *											 CONFIG INCLUDES 
 *
 *------------------------------------------------------------------------------------------------------------------
*/
#include <stddef.h>


/*------------------------------------------------------------------------------------------------------------------
 * 
 *											 CONFIG DATA TYPE 
 *
 *------------------------------------------------------------------------------------------------------------------
*/
#define  UINT16			unsigned short	


/*------------------------------------------------------------------------------------------------------------------
 * 
 *										   FLASH/ROM SPACE CONFIG
 *
 *				Example : '#define MBCD_CFG_CRC_P3 PROGMEM' (For avr-gcc)
 *
 *				MBCD_CFG_CRC_P1 static unsigned char MBCD_CFG_CRC_P2 auchCRCHi MBCD_CFG_CRC_P3[] = {...}
 *
 *								static unsigned char				 auchCRCHi PROGMEM		  [] = {...}
 *
 *				Note : Set ALL macro empty if data in RAM
 *
 *------------------------------------------------------------------------------------------------------------------
*/
#define  MBCD_CFG_CRC_P1
#define  MBCD_CFG_CRC_P2
#define  MBCD_CFG_CRC_P3


/*------------------------------------------------------------------------------------------------------------------
 * 
 *											CONFIG CODE SWITCH 
 *
 *------------------------------------------------------------------------------------------------------------------
*/
#define  MBCD_CFG_MS_SEL								1	/**< 0 for Slave and 1 for Master */

#define  MBCD_CFG_MOD_ASCII_EN							1
#define  MBCD_CFG_MOD_RTU_EN                          	1 
#define  MBCD_CFG_MOD_TCP_EN                          	0 


#if defined(__cplusplus)
}
#endif


#endif /*__MODBCD_CONFIG_H__*/

