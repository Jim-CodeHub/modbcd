/**-----------------------------------------------------------------------------------------------------------------
 *
 * @file	port.h
 * @brief   FreeModbus portable header	
 *
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef _PORT_H__
#define _PORT_H__


/*------------------------------------------------------------------------------------------------------------------
 * 
 *												PORT INCLUDES 
 *
 *------------------------------------------------------------------------------------------------------------------
*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>


/*------------------------------------------------------------------------------------------------------------------
 * 
 *											   PORT SHORT ALIAS	
 *
 *------------------------------------------------------------------------------------------------------------------
*/
#define	INLINE									inline					/**< For 'inline' functions				  */

#define assert( x )														/**< For code check (empty now)			  */

typedef char									BOOL;										
typedef unsigned char							UCHAR;
typedef char									CHAR;
typedef unsigned short							USHORT;
typedef short									SHORT;
typedef unsigned long							ULONG;
typedef long									LONG;

#ifndef TRUE
#define TRUE									1
#endif

#ifndef FALSE
#define FALSE									0
#endif


/*------------------------------------------------------------------------------------------------------------------
 * 
 *											   PORT CONFIG 
 *
 *------------------------------------------------------------------------------------------------------------------
*/


/*------------------------------------------------------------------------------------------------------------------
 * 
 *											   USER'S CONFIG 
 *
 *------------------------------------------------------------------------------------------------------------------
*/


/*------------------------------------------------------------------------------------------------------------------
 * 
 *											PORT FUN DECLARATION
 *
 *------------------------------------------------------------------------------------------------------------------
*/
//void vMBCD_PortTimersVectors( void );


#endif //_PORT_H__

