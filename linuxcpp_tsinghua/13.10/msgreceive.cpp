#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<sys/types.h>
#include<errno.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
using namespace std;
struct msgdata
{
	long int msgtype;
	char mtext[512];
};
int main()
{
	int running = 1;
	struct msgdata bufr;
	//struct msgbuf bufr;
	long int msgtype = 1;
	int msgd = msgget((key_t)1234,0666 | IPC_CREAT);
	if(msgd == -1) {fprintf(stderr,"msgget failed %d\n",errno);exit(EXIT_FAILURE);}
	while(running) {
		if(msgrcv(msgd,(void*)&bufr,(size_t)512,msgtype,0) == -1) {
			fprintf(stderr,"msgrcv err %d\n",errno);
			exit(EXIT_FAILURE);
		}
		printf("you wrote: %s\n",bufr.mtext);
		if(strncmp(bufr.mtext,"end",3) == 0)
			running = 0;
	}
	if(msgctl(msgd,IPC_RMID,0) == -1) fprintf(stderr,"msgctlrmerr %d\n",errno);
	exit(EXIT_SUCCESS);
}
