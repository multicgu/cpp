#include<stdio.h>
int main()
{
	int *a;
	printf("%d\n",sizeof(*a));
	*a = 4197488;
	printf("%d\n",sizeof(*a));
	return 0;
}
