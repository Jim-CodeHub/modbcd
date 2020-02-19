/**-----------------------------------------------------------------------------------------------------------------
 * @file	mbcrc.h
 * @brief	Modbus CRC algorithm	
 *
 * Copyright (c) 2019-2020 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __MODBCD_MBCRC_H__
#define __MODBCD_MBCRC_H__


#if defined(__cplusplus)
extern "C" {
#endif


/*------------------------------------------------------------------------------------------------------------------
 * 
 *												MBCRC INCLUDES 
 *
 *------------------------------------------------------------------------------------------------------------------
*/
#include "../config.h"


#if MBCD_CFG_MOD_RTU_EN > 0

/*------------------------------------------------------------------------------------------------------------------
 * 
 *											 FUNCTIONS DECLARATION
 *
 *------------------------------------------------------------------------------------------------------------------
*/
USHRT mbcrc(const UCHAR *puchMsg, USHRT usDataLen);


#endif //MBCD_CFG_MOD_RTU_EN


#if defined(__cplusplus)
}
#endif


#endif /*__MODBCD_MBCRC_H__*/


