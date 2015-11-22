#include<iostream>
#include<stdio.h>
#include "point.h"

using namespace std;

int main() 
{
	PPOINT pt = PtCreate(1,2);

	int x,y;
	PtGetValue(pt,x,y);
	cout << x << " " << y << endl;

	PPOINT pt1 = PtCreate(2,3);
	if(PtCompare(pt,pt1)) cout << "true" << endl;
	else cout << "false" << endl;

	PtPrint(pt); PtPrint(pt1);

	char * str = PtTransformIntoString(pt);
	printf("%s\n",str);

	PtDestroy(pt); PtDestroy(pt1);

	return 0;
}
