#include<stdio.h>
#include<iostream>
#include<sys/types.h>
#include<sys/ipc.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/msg.h>
#include<unistd.h>
using namespace std;
int main()
{
	struct msgbuf buf;
	int msgd = msgget((key_t)1234,IPC_CREAT);
	int running = 1;
	while(running) {
		printf("Enter something: ");
		buf.mtype = 1;
		fgets(buf.mtext,512,stdin);
		//printf("buf.type=%d, buf.mtext=%s\n",buf.mtype,buf.mtext);
		if(msgsnd(msgd,(void *)&buf,512,0) == -1)
		{
			fprintf(stderr,"msgsnd error %d\n",errno);
			exit(EXIT_FAILURE);
		}
		if(strncmp(buf.mtext,"end",3) == 0)
			running = 0;
		//printf("After:buf.type=%d, buf.mtext=%s\n",buf.mtype,buf.mtext);
		sleep(2);
	}

	return 0;
}
