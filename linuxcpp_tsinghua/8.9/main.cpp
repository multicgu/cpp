#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include "random.h"
#include "arrmanip.h"

using namespace std;
int DoCompareObject(const void * e1,const void * e2);

int main() 
{
	int counts;
	cout << "How many numbers you want to generate?" << endl;
	cin >> counts;
	int num[counts];
	Randmize();
	GenerateIntegers(num,counts);
	PrintIntegers(num,counts);
	cout << "Sort with quicksort algrathm." << endl;
	qsort(num,counts,sizeof(int),DoCompareObject);
	PrintIntegers(num,counts);

	return 0;
}

int DoCompareObject(const void * e1,const void * e2)
{
	return CompareInteger(*(const int *)e1,*(const int *)e2);
}
