//point.h
struct POINT;

typedef struct POINT * PPOINT;

PPOINT PtCreate(int x,int y);

void PtDestroy(PPOINT pt);

void PtGetValue(PPOINT pt,int & x,int & y);

void PtSetValue(PPOINT pt,int x,int y);

bool PtCompare(PPOINT pt1,PPOINT pt2);

void PtPrint(PPOINT pt);

char * DuplicateString(const char * str);

char * PtTransformIntoString(PPOINT pt,const char * format);
