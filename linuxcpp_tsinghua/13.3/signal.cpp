#include<stdio.h>
#include<iostream>
#include<signal.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>

using namespace std;

sig_atomic_t sigusr1_count = 0;
extern "C" {
	void OnSigUsr1(int sign_number) { ++sigusr1_count; }
}
int main()
{
	cout << "pid: " << (int)getpid() << endl;
	struct sigaction sa;
	memset(&sa,0,sizeof(sa));
	sa.sa_handler = &OnSigUsr1;
	sigaction(SIGUSR1,&sa,NULL);
	sleep(50);     // kill -s SIGUSR1 pid
	cout << sigusr1_count << endl;

	return 0;
}
