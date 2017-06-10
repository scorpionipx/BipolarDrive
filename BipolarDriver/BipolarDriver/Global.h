#ifndef GLOBAL_H_
#define GLOBAL_H_

/* Includes */
/*============================================================================*/

/* Constants and types */
/*============================================================================*/
#define F_CPU		16000000L //clock freq-must be define before including util/delay.h

#define FALSE 0
#define TRUE 1

struct boolean_struct
{
	unsigned int BOOL_0 : 1;
	unsigned int BOOL_1 : 1;
	unsigned int BOOL_2 : 1;
	unsigned int BOOL_3 : 1;
	unsigned int BOOL_4 : 1;
	unsigned int BOOL_5 : 1;
	unsigned int BOOL_6 : 1;
	unsigned int BOOL_7 : 1;
}GLOBAL_BOOL;

#define BUTTON_1_PRESSED GLOBAL_BOOL.BOOL_0   // BUTTON ONE PRESSED
#define BUTTON_2_PRESSED GLOBAL_BOOL.BOOL_1   // BUTTON TWO PRESSED

typedef signed char sint8;
typedef unsigned char uint8;
typedef signed int sint16;
typedef unsigned int uint16;
typedef signed long sint32;
typedef unsigned long uint32;

/* Exported Variables */
/*============================================================================*/

#endif /* GLOBAL_H_ */ 

/* Notice: the file ends with a blank new line to avoid compiler warnings */
