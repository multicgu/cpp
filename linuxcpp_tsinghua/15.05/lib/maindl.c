#include<stdio.h>
#include"head.h"
#include<stdlib.h>
#include<string.h>
#include<dlfcn.h>
void addfun( char * soname, char * sofun );
int main()
{
	char * soname, * sofun;
	printf("Input:XXX.so:function\n");
	char buf[100];
	fgets( buf, sizeof(buf), stdin );
	buf[strlen(buf)-1] = 0;
	soname = strdup( strtok( buf, ":" ) );
	sofun = strdup( strtok( NULL, ":" ) );
	printf("%s\n",soname);
	printf("%s\n",sofun);
	addfun(soname, sofun);

	return 0;
}
void addfun( char * soname, char * sofun )
{
	void * handle = dlopen(soname, RTLD_LAZY);
	if(handle == NULL) {
		printf("dlopen error\n"); 
		printf("%s\n",dlerror());
		exit(1);
	}
	int (*plus)( int x, int y );
	plus = dlsym( handle, sofun );
	if(plus == NULL) {
	   	printf("dlsym error\n"); 
		printf("%s\n",dlerror());
		exit(1); 
	}
	printf("%d\n",(int)(plus)(4,5));
}
