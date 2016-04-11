#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/wait.h>
using namespace std;
int bufsize = 4096;
int main()
{
	int fds[2];
	pipe(fds);
	pid_t pid = fork();
	if(pid == 0) {      //child process, wirte;
		close(fds[0]);
		dup2(fds[1],STDOUT_FILENO);
		char *args[] = {"ls","-l","/",NULL,"echo","In childiiii",NULL};
		execvp("ls",&args[0]);
		execvp("echo",&args[4]);
		close(fds[1]);
	}
	else {                //father process, read;
		printf("In father:\n");
		close(fds[1]);
		FILE * stream = fdopen(fds[0],"r");
		fprintf(stdout,"Data received:\n");
		char buf[bufsize];
		//while(!feof(stream) && !ferror(stream) && fgets(buf,sizeof(buf),stream)!=NULL)
			//fputs(buf,stdout);
		fgets(buf,sizeof(buf),stream);
		while(!feof(stream) && !ferror(stream))
			fputs(buf,stdout);
		close(fds[0]);
		waitpid(pid,NULL,0);
	}
	return 0;
}
