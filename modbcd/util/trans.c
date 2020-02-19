/**-----------------------------------------------------------------------------------------------------------------
 * @file	trans.c
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include "trans.h"


/*
--------------------------------------------------------------------------------------------------------------------
*
		                                      FUNCTION PROTOTYPES
*
--------------------------------------------------------------------------------------------------------------------
*/


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

#if  MBCD_CFG_MOD_ASCII_EN > 0 //Ascii mode enabled

/**
 *	@brief	    Trans binary value to ascii (Capital & alphanum)character
 *	@param[in]  binary 
 *	@param[out] None 
 *	@return	    binary	
 **/
SCHAR BinToAsc(UCHAR binary)
{
	return ((binary >= '0') && (binary <= '9'))?(binary+48):(binary+55);
}


/**
 *	@brief	    Trans ascii (Capital & alphanum) character to binary value
 *	@param[in]  ascii
 *	@param[out] None 
 *	@return	    binary	
 **/
UCHAR AscToBin(SCHAR ascii)
{
	return ((ascii >= '0') && (ascii <= '9'))?(ascii-48):(ascii-55);
}

#endif //MBCD_CFG_MOD_ASCII_EN > 0


