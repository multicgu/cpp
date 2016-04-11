#include<stdio.h>
#include<iostream>
#include<unistd.h>
using namespace std;

void showid(void);
int main()
{
	showid();

	printf("After set uid...\n");
	if(setuid(1000)<0) cout << "Seterr" << endl;
	//if(seteuid(1000)<0) cout << "Seterr" << endl;
	showid();
	if(setuid(0)<0){ cout << "Set uid to 0 error" << endl; return 0;}

	if(seteuid(0)<0){ cout << "Set euid to 0 error" << endl; return 0;}
	showid();

	return 0;
}
void showid()
{
	printf("uid: %d, euid: %d\n",getuid(),geteuid());
	printf("gid: %d, egid: %d\n",getgid(),getegid());
}
