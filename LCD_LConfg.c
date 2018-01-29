/*
 * LCD_LConfg.c
 *
 * Created: 25-Oct-15 1:55:46 AM
 *  Author: Pixels
 */ 

#include "LCD_LConfg.h"

LCD_ConfgType LCD_ConfgData = {
	PB ,		//command pins port
	PB,		//data pins port
	0xF0		//data pins Mask
	};