#include<stdio.h>
#include<stdlib.h>
#include"head.h"
#include<string.h>
int main( int argc, char * argv[] )
{
	if(argc != 3) {
		printf("2 int argvs\n");
		exit(1);
	}
	printf("%s + %s = %d\n",argv[1], argv[2],add(atoi(argv[1]),atoi(argv[2])));
	printf("%s - %s = %d\n",argv[1], argv[2],sub(atoi(argv[1]),atoi(argv[2])));
	return 0;
}
