
/**
* macros.h
* 
* Author Pixels
*/

#ifndef _MACROS_H
#define _MACROS_H

#define HIGH_NIBBLE(hVar,var) hVar= (var & 0xf0)  // hVar will hold value of high nibble of var 

#define LOW_NIBBLE(lVar,var) lVar= (var<<4) // lVar will hold the value of low nibble of var 
 

#define CLR_BIT(var, bit)	DIO_WritePort(var , 0x00 , 1<<bit)   //clear specified pin

#define SET_BIT(var, bit)   DIO_WritePort(var , 0xFF , 1<<bit)  //set specified pin

#define TOG_BIT(var, bit) (var) ^= (1<<bit) //toggle specified pin

#endif 

