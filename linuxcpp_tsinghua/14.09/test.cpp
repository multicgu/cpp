#include<stdio.h>
int main()
{
	const int x=5,y=6;
	//const int * p = &x;
	int * const p;
	*p = 5;
	printf("%d\n",*p);
	p = &y;
	printf("%d\n",*p);
	*p = 7;
	printf("%d\n",*p);
	
	return 0;
}
