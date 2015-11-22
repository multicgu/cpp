#include<stdio.h>
#include<iostream>
#include "point.h"
#include "list.h"

using namespace std;

int main()
{
	PPOINT pt = PtCreate(0,1);
	PPLIST list = LICreate();
	LIAppend(list,CreateObject,pt);
	LIAppend(list,CreateObject,PtCreate(1,2));
	LIAppend(list,CreateObject,PtCreate(2,3));
	LIInsert(list,4,CreateObject,PtCreate(4,5));
	char str[] = "<%d,%d>";
	LITraverse(list,DoPrintObject,str);
	int search = LISearch(list,PtCreate(2,3));
	cout << "search= " << search << endl;
	LIDelete(list,0,DestoryObject);
	LITraverse(list,DoPrintObject,str);
	//LIClear(list,DestoryObject);
	LIDestory(&list,DestoryObject);
	LITraverse(list,DoPrintObject,str);
	cout << GetListCount(list)<< endl;

	return 0;
}
