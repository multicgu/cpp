#include<stdio.h>
#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<cstdlib>
using namespace std;

int spawn(char * program,char ** args);

int main()
{
	char * args[] = {"ls","-l","/",NULL};
	spawn("ls",args);
	cout << "Done!"<< (int)getpid() << endl;
	return 0;
}

int spawn(char * program,char ** args)
{
	pid_t pid = fork();
	if(pid != 0) {
		cout << "In farther process " << (int)getpid()  << endl;
		return pid;
	}
	else {
		cout << "In child process " << (int)getpid() << endl;
		execvp(program,args);
		cerr << "Errors occured when executing execvp.\n";
		abort();
	}

}
