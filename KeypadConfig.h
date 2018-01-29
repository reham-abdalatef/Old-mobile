/*
 * KeypadConfig.h
 *
 * Created: 20-Oct-15 12:20:49 AM
 *  Author: Pixels
 */ 


#ifndef KEYPADCONFIG_H_
#define KEYPADCONFIG_H_
#include "StdTypes.h"
#include "DIO.h"


/**specify the number of col and rows*/
#define ROWS_NUM 4
#define COL_NUM 3


typedef struct {
	u8 KeypadPort;		//the port where the keypad will be connected
	u8 RowsMask;		//the rows mask  (where the rows pins are in the port it self ) note that they must be adjacent
	u8 ColsMask;		//the cols mask  (where the col pins are in the port it self ) note that they must be adjacent
	}KeypadConfigType;
extern KeypadConfigType KeypadConfigData ;		//the struct that will contain the data (port , rows maks and col mask) 
extern char keys[ROWS_NUM ][ COL_NUM] ;		//an array to declare what each button represent

#endif /* KEYPADCONFIG_H_ */