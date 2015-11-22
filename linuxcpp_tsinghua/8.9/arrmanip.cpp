//arrmanip.cpp
#include<stdio.h>
#include<iostream>
#include "random.h"

using namespace std;

static const int lower = 10;
static const int upper = 99;

void GenerateIntegers(int a[],int n)
{
	for(int i = 0; i < n; i++)
		a[i] = GenerateRandomInteger(lower,upper);
}

void PrintIntegers(int a[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d  ",a[i]);
	cout << endl;
}

int CompareInteger(int x,int y)
{
	if(x > y) return 1;
	else if(x < y) return -1;
	else return 0;
}
