//list.h
//void DestoryObject(void (* PtDestory)(void * o),void * o);
#include "point.h"

struct NODE;

typedef NODE * PNODE;

struct LIST;

typedef LIST * PPLIST;

PNODE CreateObject(void * o);

void DestoryObject(void * o);

void DoPrintObject(void * format,void * o);

bool CompareObject(void * o1,void * o2);

PPLIST LICreate(void);

void LIDestory(PPLIST * list, void (* DestoryObject)(void * o) );

void LIAppend(PPLIST list, PNODE (* CreateNode)(void * o), void * o);

void LIInsert(PPLIST list,int pos,PNODE (* CreateNode)(void * o),void * o);

void LIDelete(PPLIST list,int pos,void (* DestoryObject)(void * o));

void LIClear(PPLIST list, void (* DestoryObject)(void * o) );
    
void LITraverse(PPLIST list,void (* DoPrintObject)(void * tag,void * o),void * tag);

int LISearch(PPLIST list,void * o);

int GetListCount(PPLIST list);

//LIIsEmpty
