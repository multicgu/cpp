#include<stdio.h>

int main()
{
	//char a[][3] = {"哥","哥","我","岸","上","走"};
	//char a[][3] = {"哥哥","我岸","上走"};
	char a[][3] = {"fj","rw","dg","io","jk","ew"};
	char (*p)[3];
	p = a;
	for(int i=0;i<6;i++) 
		printf("%s ",*(p+i));
	printf("\n");

	return 0;
}
