//fd and newfd point to same file
#include<stdio.h>
#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
using namespace std;
int main()
{
	int fd = open("testdup",O_RDWR|O_CREAT);
	int newfd = dup2(fd,1);
	printf("newfd = %d, fd = %d",newfd,fd);
	close(fd);
	return 0;
}
