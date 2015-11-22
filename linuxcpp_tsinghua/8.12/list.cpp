//list.cpp
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include "point.h"
#include "point.cpp" //question?
#include "list.h"

using namespace std;

typedef void * Object;

struct NODE{ PPOINT data; PNODE next; };

PNODE CreateObject(Object o) 
{
	PNODE tn = new NODE;
	tn->data = (PPOINT)o; tn->next = NULL;
	printf("(%d,%d)\n",tn->data->x,tn->data->y);
	return tn;
}

void DestoryObject(Object o) { delete (PPOINT)o; }

void DoPrintObject(Object format,Object o) 
{ 
	PPOINT pt = (PPOINT)o;
	printf(PtTransformIntoString((PPOINT)o,(const char *)format));
	printf(" -> ");
}

bool CompareObject(Object o1,Object o2) 
{
	return PtCompare((PPOINT)o1,(PPOINT)o2);
}

struct LIST{ PNODE head,tail; int count; };

PPLIST LICreate(void)
{
	PPLIST p = new LIST;
	p->head = p->tail = NULL;
	p->count = 0;
	return p;
}

void LIClear(PPLIST list, void (* DestoryObject)(Object o) )
{
	printf("%d\n",GetListCount(list));
	if(list && list->count!=0) {
		PNODE t = list->head;
		while(list->count>0){
			LIDelete(list,0,DestoryObject); 
		}
	}
}

void LIDestory(PPLIST * list, void (* DestoryObject)(void * o) )
{
	if(*list) {
		LIClear(*list,DestoryObject);
		delete *list;   *list = NULL;
	}
}

void LIAppend(PPLIST list,PNODE (* CreateObject)(Object o), Object o)
{
	if(!list) { cout << "List no found!" << endl; exit(1); }
	else {
		if(list->count == 0){
			list->head = list->tail = (* CreateObject)(o);
		}
		else {
			list->tail->next = (* CreateObject)(o);
			list->tail = list->tail->next;
		}
		list->count++;
	}
}

void LIInsert(PPLIST list,int pos,PNODE (* CreateObject)(Object o),Object o)
{
	if(!list) { cout << "List not found!" << endl; exit(1); }
	if(pos >= list->count) { LIAppend(list,CreateObject,o); }
	else if(pos == 0) {
		PNODE tn = list->head;
		list->head = CreateObject(o);
		list->head->next = tn;
		list->count++;
	}
	else {
		PNODE tn = list->head;
		for(int i=0;i<pos-1;i++)
			tn = tn->next;
		PNODE tn1 = CreateObject(o);
		tn1->next = tn->next;
		tn->next = tn1;
		list->count++;
	}
}

void LIDelete(PPLIST list,int pos,void (* DestoryObject)(Object o) )
{
	if(!list) { cout << "List not found!" << endl; exit(1); }
	if(list->count == 0) exit(0);
	PNODE t = list->head;
	if(pos == 0) {
		list->head = t->next;
		(*DestoryObject)(t->data);
		delete t;
		list->count--;
		return;
	}
	for(int i=0;i<pos-1;i++)
		t = t->next;
	PNODE del = t->next;
	t->next = del->next;
	(*DestoryObject)(del->data);
	delete del; 
	list->count--;
	if(list->count == 0) list->head = list->tail = NULL;
}

void LITraverse(PPLIST list,void (* DoPrintObject)(Object tag,Object o),Object tag) 
{
	if(!list) { cout << "List not found!" << endl; exit(1); }
	PNODE t = list->head;
	while(t) {
		(* DoPrintObject)(tag,t->data);
		t = t->next;
	}
	printf("NULL\n");
}

int LISearch(PPLIST list,Object o)
{
	if(!list) { cout << "List not found!" << endl; exit(1); }
	int i=0;
	for(PNODE t=list->head; i < list->count ; i++,t=t->next) 
		if(CompareObject(t->data,o)) return i;
	return -1;
}

int GetListCount(PPLIST list)
{
	return list->count;
}
