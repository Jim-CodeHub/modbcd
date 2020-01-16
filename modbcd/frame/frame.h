/**-----------------------------------------------------------------------------------------------------------------
 * @file	frame.h
 * @brief	Official macro and datablock declare	
 *
 * Copyright (c) 2019-2020 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __MODBCD_MBFRAME_H__
#define __MODBCD_MBFRAME_H__


#if defined(__cplusplus)
extern "C" {
#endif


/*------------------------------------------------------------------------------------------------------------------
 * 
 *										MBFRAME SHORT ALIAS FOR GENERAL MACRO 
 *
 *------------------------------------------------------------------------------------------------------------------
*/
#define  MBCD_FRAME_CR								0X0D
#define  MBCD_FRAME_LF								0X0A


/*------------------------------------------------------------------------------------------------------------------
 * 
 *										MBFRAME SHORT ALIAS FOR LIMIT MACRO 
 *
 *------------------------------------------------------------------------------------------------------------------
*/
#define  MBCD_MAX_ASCII_FRAME_SIZE					2*255	/**< Regardless start and end character				  */


/*------------------------------------------------------------------------------------------------------------------
 * 
 *										MBFRAME SHORT ALIAS FOR FUNCTION CODE 
 *
 *------------------------------------------------------------------------------------------------------------------
*/
															/*------------------- Bit data access ----------------*/
#define  MBCD_FCODE_RD_DISCRETE_INPUT				0X02	/*													  */
#define  MBCD_FCODE_RD_COILS						0X01	/* 										  			  */
#define  MBCD_FCODE_WR_SINGLE_COIL					0X05	/* 										  			  */
#define  MBCD_FCODE_WR_MULTIPLE_COILS				0x0F	/* 										  			  */

															/*------------------- Word data access ---------------*/
#define  MBCD_FCODE_RD_INPUT_REGISTER				0X04	/*              									  */
#define  MBCD_FCODE_RD_HOLDING_REGISTERS			0X03	/*              									  */
#define  MBCD_FCODE_WR_SINGLE_REGISTER				0X06	/*              									  */
#define  MBCD_FCODE_WR_MULTIPLE_REGISTERS			0x10	/*              									  */
#define  MBCD_FCODE_RW_MULTIPLE_REGISTERS			0x17	/*              									  */
#define  MBCD_FCODE_MASK_WRITE_REGISTER				0x16	/*              									  */
#define  MBCD_FCODE_RD_FIFO_QUEUE					0x18	/*              									  */

															/*------------------- File record access -------------*/
#define  MBCD_FCODE_RD_FILE_RECORD					0X14	/*													  */
#define  MBCD_FCODE_WR_FILE_RECORD					0X15	/* 													  */

															/*------------------- Diagnostics --------------------*/
#define  MBCD_FCODE_RD_EXCEPTION_STATUS				0X07	/*													  */
#define  MBCD_FCODE_DIAGNOSTIC						0X08	/* 											 		  */
#define  MBCD_FCODE_GET_COM_EVENT_COUNTER			0X0B	/* 											 		  */
#define  MBCD_FCODE_GET_COM_EVENT_LOG				0X0C	/* 											 		  */
#define  MBCD_FCODE_REPORT_SERVER_ID				0X11	/* 											 		  */
#define  MBCD_FCODE_RD_DEVICE_IDENTIFICATION		0x2B	/* SUB - 0X0E								 		  */

															/*------------------- Diagnostics(0X08) Sub code -----*/
#define  MBCD_FCODE_RET_QUERY_DATA					0x00	/*													  */
#define  MBCD_FCODE_RET_RST_COMM_OPT				0X01	/* 													  */
#define  MBCD_FCODE_RET_DIAGNOSTIC_REG				0X02	/* 													  */
#define  MBCD_FCODE_CH_ASCII_INPUT_DELIMITER		0X03	/* 													  */
#define  MBCD_FCODE_FORCE_LISTERN_ONLY_MODE			0X04	/* 													  */
#define  MBCD_FCODE_CLR_CNT_DIG_REG					0X0A	/* 													  */
#define  MBCD_FCODE_RET_BUS_MSG_CNT					0X0B	/* 													  */
#define  MBCD_FCODE_RET_BUS_COMM_ERR_CNT			0X0C	/* 													  */
#define  MBCD_FCODE_RET_BUS_EXCEP_ERR_CNT			0x0D	/* 													  */
#define  MBCD_FCODE_RET_SERVER_MSG_CNT				0x0E	/* 													  */
#define  MBCD_FCODE_RET_SERVER_NO_RSP_CNT			0x0F	/* 													  */
#define  MBCD_FCODE_RET_SERVER_NAK_CNT				0x10	/* 													  */
#define  MBCD_FCODE_RET_SERVER_BUSY_CNT				0x11	/* 													  */
#define  MBCD_FCODE_RET_BUS_CHAR_OVERRUN_CNT		0x12	/* 													  */
#define  MBCD_FCODE_CLR_OVERRUN_CNT_FLG				0x14	/* 													  */

															/*------------------- Others -------------------------*/
#define  MBCD_FCODE_ENCAP_INTERFACE_TRANSPORT		0X2B	/* SUB - 0X0D and 0X0E		   						  */

															/*------------------- CANOPEN ------------------------*/
#define  MBCD_FCODE_CANOPEN_REFERENCE				0X2B	/* SUB - 0XD										  */

															/*------------------- Others And CANOPEN Sub code ----*/
#define  MBCD_FCODE_CANOPEN_REFER_PDU				0X0D    /*													  */	
#define  MBCD_FCODE_RD_DEVICE_ID					0X0E	/*													  */


#if defined(__cplusplus)
}
#endif


#endif /*__MODBCD_MBFRAME_H__*/


