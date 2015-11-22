#include<iostream>
#include<stdio.h>
#include<cstring>
#include "point.h"

using namespace std;

struct POINT{int x,y; };

PPOINT PtCreate(int x,int y)
{
	PPOINT pt = new POINT;
	pt->x = x; pt->y = y;
	return pt;
}

void PtDestroy(PPOINT pt) { delete pt; }

void PtGetValue(PPOINT pt, int & x, int & y)
{ if(pt) {x = pt->x; y = pt->y;} }

void PtSetValue(PPOINT pt, int x, int y)
{ if(pt) {pt->x = x; pt->y = y;} }

bool PtCompare(PPOINT pt1,PPOINT pt2)
{ 
	if(!pt1 || !pt2) {cout << "PtCompare:Parameter(s) illegal." << endl; }
	else return (pt1->x == pt2->x) && (pt1->y == pt2->y);
}

void PtPrint(PPOINT pt)
{
	if(pt) {printf("(%d,%d)\n",pt->x,pt->y);}
	else printf("NULL\n");
}

char * PtTransformIntoString(PPOINT pt)
{
	if(pt) {
		char * buf;
		sprintf(buf,"(%d,%d)",pt->x,pt->y);
		return DuplicateString(buf);
	}
	return NULL;
}

char * DuplicateString(const char * str)
{
	int n  = strlen(str);
	char * T = new char[n+1];
	for(int i=0;i<n;i++)
		T[i] = str[i];
	T[n] = '\n';
	return T;
}
