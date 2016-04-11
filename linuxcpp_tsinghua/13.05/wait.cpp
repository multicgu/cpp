#include<iostream>
#include<sys/types.h>
#include<cstdlib>
#include<sys/wait.h>
#include<unistd.h>

using namespace std;
void spawn(char * program,char ** args);
/*int main()
{
	char * args[] = {"ls","-l","/",NULL};
	int child_status;
	//wait(&child_status);
	spawn("ls",args);
	if(WIFEXITED(child_status)) {
		cout << "exit scuessful:" << WEXITSTATUS(child_status)  << endl;
	}
	else 
		cout << "exit error" << endl;
	return 0;
}*/
int main()
{
	char * arg_list[] = { "ls", "-l", "/", NULL };
	spawn( "ls", arg_list );
	int child_status;
	//wait( &child_status );    //  等待子进程结束
	if( WIFEXITED( child_status ) )    //  判断子进程是否正常退出
		cout << "Exited normally with " << WEXITSTATUS(child_status) <<endl;
    else
		cout << "Exited abnormally." << endl;
	cout << "Done!\n";
	return 0;
}

void spawn(char * program,char ** args)
{
	pid_t pid = fork();
	if(pid > 0) {
		cout << "In farther process " << (int)getpid() << endl;
		return;
	}
	else {
		cout << "In child process " << (int)getpid() << endl;
		execvp(program,args);
		cerr << "Errors occured when executing execvp.\n";
		abort();
	}
}
