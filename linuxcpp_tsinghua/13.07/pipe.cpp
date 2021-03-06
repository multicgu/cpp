#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

using namespace std;

const int bufsize = 4096;

void Write( FILE * STREAM, int count,const char * buf)
{
	for( ; count>0 ; --count ) {
		fprintf(STREAM,"%s\n",buf);
		fflush(STREAM);
		sleep(1);
	}
}
void Read( FILE * STREAM)
{
	char buf[bufsize];
	int n = 0;
	while(!feof(STREAM) && !ferror(STREAM) && fgets(buf,sizeof(buf),STREAM) != NULL) {
		fprintf(stdout,"Data received(%d): \n",++n);
		fputs(buf , stdout);
	}
}
int main()
{
	int bufsize = 4096;
	int fds[2];
	pipe(fds);
	printf("fds[0] = %d, fds[1] = %d\n",fds[0],fds[1]);
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
		//buf[bufsize-1] = 'z';
		//buf[bufsize-2] = '\0';
		Write( STREAM, 3, buf );
		close(fds[1]);
	}
	return 0;
}
