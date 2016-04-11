#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

using namespace std;

const int bufsize = 4096;

void Write(const FILE * STREAM, int count,const char * buf)
{
	fprintf(STREAM,"Write words:\n");
	for( ; count>0 ; --count ) {
		fprintf(STREAM,"%s\n",buf);
		fflush(STREAM);
		sleep(1);
	}
}
void Read(const FILE * STREAM)
{
	char buf[bufsize];
	int n = 0;
	while(!feof(STREAM) && !ferror(STREAM) && fgets(buf,STREAM) != NULL) {
		fprintf(stdout,"Data received(%d): \n",++n);
		fputs(buf , stdout);
	}
}
int main()
{
	int fds[2];
	pipe(fds);
	pid_t pid = fork();
	if(pid == 0) {
		close(fds[1]);
		FILE * STREAM = fdopen(fds[0],"r");
		Read(STREAM);
		close(fds[0]);
	}
	else {
		close(fds[0]);
		FILE * STREAM = fdopen(fds[1],"w");
		char buf[bufsize];
		for(int i = 0; i < bufsize-2; i++)  buf[i] = 'a' + i%26;
		buf[bufsize-1] = buf[bufsize-2] = '\0';
		Write( STREAM, 3, buf );
		close(fds[1]);
	}
	rerturn 0;
}
