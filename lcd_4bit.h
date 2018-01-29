
#ifndef _LCD_4BIT_H

#define _LCD_4BIT_H


#include "LCD_LConfg.h"
/**initialize the LCD*/
void lcd_init(void);

/**move the cursor to XY coordinates */
void lcd_gotoxy(unsigned char x , unsigned char y );

/**clear the screen*/
void lcd_clrScreen(void);

/**display specific char on the screen*/
void lcd_displayChar(unsigned char data);

/**Display specific string on the screen*/
void lcd_dispString(char * ptr);

/**Display string on a specific location x and y */
void lcd_disp_string_xy(char * ptr , int y , int x);
void lcd_disp_char_xy(char ptr,int y,int x);

/**Display Int on the screen*/
void lcd_displayInt (  int data);


#endif  

