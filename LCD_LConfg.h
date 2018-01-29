/*
 * LCD_LConfg.h
 *
 * Created: 25-Oct-15 1:55:32 AM
 *  Author: Pixels
 */ 


#ifndef LCD_LCONFG_H_
#define LCD_LCONFG_H_
#include "DIO.h"
#include "StdTypes.h"

//where the LCD (command) pins are connected ( in the same port ) 
#define LCD_E 3
#define LCD_RW 2
#define LCD_RS 1


typedef struct{
	u8 CmdPort ;		//the port where the LCD command pins are connected 
	u8 DataPort ;		//the port where the data pins are connected 
	u8 DataMask;		//the data pins mask ( they should be adjacent )
}LCD_ConfgType;

extern LCD_ConfgType LCD_ConfgData ;		//guess why we used extern ? ;)



#endif /* LCD_LCONFG_H_ */