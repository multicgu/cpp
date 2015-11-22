#include<iostream>
#include<stdio.h>
#include<ctime>
#include<stdlib.h>
#include<stdbool.h>

void Randseed()
{
	srand((int)time(0));
}

int Renum_in_poker()
{
	return rand()%52+1;
}

bool SameCard(int card1,int card2)
{
	return (card1==card2)?true:false;
}

int CalBigPoint(int Card)
{
	int CardPoint = Card%13+2;
	switch(CardPoint)
	{
		case 11: return 1;
		case 12: return 2;
		case 13: return 3;
		case 14: return 4;
		default: return 0;
	}
}

