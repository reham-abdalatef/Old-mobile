/*
 * game.c
 *
 * Created: 8/25/2016 9:02:33 PM
 *  Author: lenovo
 */ 
#include "game.h"
#include <util/delay.h>
#include "Keypad.h"
int enemies[2][16];
void make_pair(pairof*a,int first,int second)
{
	a->first=first;
	a->second=second;
}

int valid(pairof a)
{
	if(enemies[a.first][a.second] == 1 ||enemies[a.first][a.second+1] == 1 )
	return 0;
	
	return 1;
}
void Game_init()
{
	for(int i=1;i<16;i++)
	{
		if(i%4==0 &&!(i%8==0))
		enemies[0][i]=1;
		else
		enemies[0][i]=0;

		if((i%8==0) )
		enemies[1][i]=1;
		else
		enemies[1][i]=0;
		if(i%7==0)
		enemies[0][i]=2;
		if(i%5==0)
		enemies[1][i]=2;


	}
}
void start()
{
	lcd_init();
   keypad_init();
	lcd_gotoxy(0,0);
	lcd_displayChar('>');
	Game_init();
	
}
void dispay_Enemy(pairof p)
{
	
	for(int i=0;i<16;i++)
	{
		if(enemies[0][i]==1)
		{lcd_gotoxy(i,0);
			lcd_displayChar('|');
		}
		if(enemies[1][i]==1)
		{lcd_gotoxy(i,1);
			lcd_displayChar('|');
		}
		if(enemies[0][i]==2)
			{
				lcd_gotoxy(i,0);
				lcd_displayChar('*');
				
			}
			if(enemies[1][i]==2)
			{
				lcd_gotoxy(i,1);
			lcd_displayChar('*');
				
			}
	}
}

void Enemy_Swap()
{
int x=enemies[0][0];
int y=enemies[1][0];
for(int i=0;i<16;i++)
{
	if(i==15)
	{
		enemies[0][i]=x;
		enemies[1][i]=y;
     continue;
	}
	enemies[0][i]=enemies[0][i+1];
	enemies[1][i]=enemies[1][i+1];
}
	
}

void Enter_TO_Play(pairof*p)
{
	u8 read = kd_read();
	if( read == UP)
	p->first=0;
	else if(read == DOWN)
	p->first=1;
	
}
int Game_Level()
{
	lcd_gotoxy(0,0);
	lcd_dispString("Easy Mid Hard");
	lcd_gotoxy(0,1);
	lcd_dispString("  1   2   3");
int type;
while(1)
{
type=keypad_read();
if(type== HARD|| type==EASY||type==MEDIUM )
return type;
}

}
void Game_wait(int t)
{
	if(t== EASY)
	_delay_ms(500);
	else if(t== MEDIUM)
		_delay_ms(350);
		else 
_delay_ms(200);
}
void Game_score(int*s,pairof p)
{
	if(enemies[p.first][p.second]==2)
	  (*s)++;
	
	
}

void Game_Play()
{ int type,score=0;
	pairof player;
	u8 p='#';
while(p=='#')
{

type=Game_Level();//level
lcd_clrScreen();
 make_pair(&player,1,0);
 Game_init();
	while(valid(player))
	{Enter_TO_Play(&player);
	//Enter_TO_Play(&player);
	Enemy_Swap();
	dispay_Enemy(player);
	lcd_gotoxy(player.second,player.first);
	lcd_displayChar('>');	
	Enter_TO_Play(&player);
	Game_wait(type);
	Enter_TO_Play(&player);
	Game_score(&score,player);
	lcd_clrScreen();
	}
	lcd_clrScreen();
	
	 do {
		 lcd_disp_string_xy("Score:",0,0);
		 lcd_displayInt(score);
		lcd_disp_string_xy("<exit",1,0);
	    lcd_disp_string_xy("try>",1,12);
	    p=keypad_read();
	    lcd_clrScreen();
	if(p =='*' || p=='#'){break;}
}while(1);
score=0;
}

}

