//random.cpp
#include<stdio.h>
#include<iostream>
#include<ctime>
#include<stdlib.h>

void Randmize()
{
	srand((int)time(0));
}

int GenerateRandomInteger(int lower,int upper)
{
	return rand()%(upper-lower+1)+lower;
}
