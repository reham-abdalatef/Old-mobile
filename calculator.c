#include"calculator.h"
#include "math.h"
char opera[4]={'+','-','*','/'};
void calculator_init(void)
{
	lcd_init();
	keypad_init();
}
int calculator_readNum(void)
{
	u8 charNum[16] ; int IntNum=0; u8 loopIndex=0,arraySize;
	lcd_disp_string_xy("Enter a Num:",0,0);
	//_delay_ms(2000);
	//	lcd_clrScreen();
	lcd_disp_string_xy("then *",1,0);
	_delay_ms(1000);
	lcd_clrScreen();
	charNum[0]='0';  //the entered num will start by index 1 .
	loopIndex=1;
	while (charNum[loopIndex-1]!='*')
	{
		charNum[loopIndex]=keypad_read();
		lcd_displayChar(charNum[loopIndex]);
		_delay_ms(300);
		loopIndex++;
	}
	arraySize=loopIndex;//firstNum[arraySize]='*',firstNum[0]=0,and the user should enter number smaller than 9999,if we need a bigger num we should increase cases of the next condition
	//which at the next loop.
	for (loopIndex=1;loopIndex<arraySize-1 ;loopIndex++)
	{
		IntNum+=((int)(charNum[loopIndex]-'0'))*pow(10,loopIndex-1);
	}
	return IntNum;
}
int calculator_readOperation(void)
{
 int loopIndex=0; int op_code, key='1';
	lcd_clrScreen();
	lcd_dispString("Enter operation,then#:");
	
	loopIndex=0;
	while (1)
	{
		key=keypad_read();
		if(key=='#'){break;}
		lcd_disp_char_xy(' ',1,0);
		lcd_disp_char_xy(opera[loopIndex%5],1,0);   //
		loopIndex++;
		_delay_ms(300);
	}
	return ((loopIndex)%5);
}
void calculator_run()
{int error=0;
	int firstNum=0,secondNum,result=0,oper,flag=1;
	while (1)
	{
		if (flag==0)
		{
			firstNum=result;
		}
		else if (flag==1)
		{
			firstNum=calculator_readNum();
		//	lcd_displayInt(firstNum);
			_delay_ms(300);
			lcd_clrScreen();
		}
		if (flag==2)
		{
			break;
		}
		oper=calculator_readOperation();
		_delay_ms(300);
		lcd_clrScreen();
		secondNum=calculator_readNum();
		switch (oper)
		{
			case 1 :
			result=firstNum+secondNum;break;
			case 2 :
			result=firstNum-secondNum;break;
			case 3 :
			result=firstNum*secondNum;break;
			case 4 :
			{
				if(secondNum == 0)
				{lcd_clrScreen();
				        	lcd_dispString("Error");
						lcd_disp_string_xy("exit>2",1,8);
						_delay_ms(400);
						flag=(keypad_read()-'0');
						_delay_ms(300);
						lcd_clrScreen();
						error=1;
						break;
				}
				result=firstNum/secondNum;
				
				break;
				
			}
		}
		if(error)
		{
			break;
		}
				lcd_clrScreen();
		lcd_dispString("result=");
		lcd_displayInt(result);
		_delay_ms(1000);
		lcd_clrScreen();
		lcd_disp_string_xy("continue>0",0,0);
		lcd_disp_string_xy("clr>1",1,0);
		lcd_disp_string_xy("exit>2",1,8);
		flag=(keypad_read()-'0');
		_delay_ms(300);
		lcd_clrScreen();
	}
}
