#include<stdio.h>
#include<iostream>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/stat.h>
using namespace std;
int main()
{
	const int share_size = 4096;
	int shmd = shmget(IPC_PRIVATE,share_size,IPC_CREAT|IPC_EXCL|S_IRUSR|S_IWUSR);
	char * buf = (char *)shmat(shmd,NULL,0);
	printf("Share memory attach at %p\n",buf);
	struct shmid_ds shmbuf;
	shmctl(shmd,IPC_STAT,&shmbuf);
	printf("Segment size:%d\n",shmbuf.shm_segsz);
	sprintf(buf,"Hello world.");
	shmdt(buf);

	buf = (char *)shmat(shmd,(void *)102400000,0);
	printf("Share memory reattach at %p\n",buf);
	printf("%s\n",buf);
	shmdt(buf);
	shmctl(shmd,IPC_RMID,0);

	return 0;
}
