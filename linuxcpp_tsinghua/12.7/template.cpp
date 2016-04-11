#include<stdio.h>
#include<iostream>
#include<unistd.h>
#include<cstring>
#include<cstdlib>
using namespace std;

int WriteToTemplate(char * buf,size_t length)
{
	char tempfile[] = "/tmp/template.XXXXXX";
	int fd = mkstemp(tempfile);
	//unlink(tempfile);
	//write(fd,&length,sizeof(length));
	printf("write length %d\n",length);
	write(fd,buf,sizeof(length));
	printf("write buf %s\n",buf);
	return fd;
}
char * ReadFromTemplate(int fd,size_t * length)
{
	lseek(fd,0,SEEK_SET);
	//char buf[*length];
	char *buf = new char[*length];
	//read(fd,length,sizeof(*length));
	printf("read length %d\n",*length);
	read(fd,buf,*length);
	close(fd);
	return buf;
}
int main()
{
	//char buf[11]="abcdefghij";
	char * buf = "abcdefghij";
	size_t length;
	int fd = WriteToTemplate(buf,length);
	printf("file fd = %d\n",fd);
	char * get = ReadFromTemplate(fd,&length);
	//printf("%s\n",get);
	cout << get << endl;

	return 0;
}
