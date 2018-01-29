/*
 * KeypadConfig.c
 *
 * Created: 20-Oct-15 12:21:20 AM
 *  Author: Pixels
 */ 
#include "KeypadConfig.h"
KeypadConfigType KeypadConfigData = 
{	PC,		//the keypad port
	0x78 ,	//the rows mask
	0x07		//the col mask
	  } ;
	  
	  /**the buttons representation*/
char keys[ROWS_NUM ][ COL_NUM] = {
{
	'1' , '2' , '3'
},
{
	'4' , '5' , '6'
},
{
	'7' ,'8','9'
},
{
	'*','0','#'
}
	} ;