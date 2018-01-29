/*
 * game.h
 *
 * Created: 8/25/2016 9:02:51 PM
 *  Author: lenovo
 */ 
#include "lcd_4bit.h"

#include <avr/io.h>

#ifndef GAME_H_
#define GAME_H_

typedef struct
{
	int first;
	int second;
}pairof;

#define UP '2'
#define DOWN '8'
#define  EASY  '1'
#define  MEDIUM  '2'
#define  HARD '3'
void make_pair(pairof*a,int first,int second);
int valid(pairof a);
void Game_init();
void start();
void Game_Play();
void dispay_Enemy(pairof p);
void Enemy_Swap();
void Enter_TO_Play(pairof*p);
void Game_score(int*s,pairof p);
void Game_wait(int t);
void Game_score(int*s,pairof p);








#endif /* GAME_H_ */