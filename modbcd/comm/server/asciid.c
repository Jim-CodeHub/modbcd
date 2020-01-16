/**-----------------------------------------------------------------------------------------------------------------
 * @file	asciid.c
 * @brief	Modbus ASCII mode server/slave handler 
 * @note	Bit per Byte : 
 *					1     start  bit
 *					7	  data   bit, least significant bit (LSB) sent first
 *					1 / 0 parity bit
 *					1 / 2 stop   bit
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <modbcd/comm/server/asciid.h>


#if  ((MBCD_CFG_MS_SEL == 0) && (MBCD_CFG_MODE_ASCII_EN > 0)) //Slave and ascii mode enabled

/*
--------------------------------------------------------------------------------------------------------------------
*
*											  VARIABLES DECLARATION 
*
--------------------------------------------------------------------------------------------------------------------
*/
static struct asciid_state stat_s = {.state = ASCIID_STATE_IDLE};


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief		Init Modbus Ascii server
 *	@param[in]	buff		-   Recive buffer 
 *	@param[in]	size		-   Size of recive buffer 
 *	@param[in]  recv		-	Method to recive character from RS232/RS485/USART ...
 *	@param[in]  send		-	Method to send character to RS232/RS485/USART ...
 *	@param[in]  exec		-	Method to execute action 
 *	@param[out] None	
 *	@return		None
 *	@note		1. The param 'size' SHOULD BE larger enough
 *				2. The param 'exec' SHOULD BE :
 *					a). Check whether function code and data field is valid or not
 *					b). Execute action
 *					c). Do normal/exception response (asciid_emit() can be called)
 **/
void asciid_init(unsigned char *buff, unsigned short size, pFun_recv recv, pFun_exec exec)
{
	stat_s.pInit = buff;
	stat_s.pInxt = buff;

	stat_s._size = size;

	stat_s.serial_recv = recv;
	stat_s.serial_exec = exec;

	return;
}

/**
 *	@brief	    Recive Modbus client data
 *	@param[in]  None 
 *	@param[out] None
 *	@return		None	
 *	@note		Put the function into the loop or interrupt depends on the implementation of 'serial_recv()'	
 **/
void asciid_recv(void)
{
	char ch = stat_s.serial_recv();

	if (':' == ch) {memset(stat_s.pInit, 0, stat_s._size); stat_s.pInxt= stat_s.pInit; stat_s.state = ASCIID_STATE_0;}

	switch (stat_s.state)
	{
		case ASCIID_STATE_0: /**< Check address field */
			{
				/**< Quick address field (the first byte) handler */
				stat_s.state = ((0 != ch) && (MBCD_CFG_ADDRESS != ch))?ASCIID_STATE_IDLE:ASCIID_STATE_1;
			}
			break;
		case ASCIID_STATE_1: /**< Recive data into buff */
			{
				switch (ch)
				{
					case 0X0D: /**< CR */ 
						stat_s.state = ASCIID_STATE_2;
						break;
					default:
						{
							*(stat_s.pInxt) = ch; (stat_s.pInxt)++; 
						}
				}
			}
			break;
		case ASCIID_STATE_2: /**< End recive and execute action */
			{
				switch (ch)
				{
					case 0X0A: /**< LF */ 
						{
							stat_s.serial_exec(&stat_s);
							stat_s.state = ASCIID_STATE_IDLE;
						}
						break;
					default:
						;
				}
			}
			break;
		default: /**< ASCII_STATE_IDLE */
			;
	}

	return;
}

#endif //((MBCD_CFG_MS_SEL == 0) && (MBCD_CFG_MODE_ASCII_EN > 0))

