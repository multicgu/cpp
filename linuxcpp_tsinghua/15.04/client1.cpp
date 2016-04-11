#include<stdio.h>
#include<cstdio>
#include<iostream>
#include<sys/socket.h>
#include<cstring>
#include<cstdlib>
#include<unistd.h>
#include<sys/un.h>
using namespace std;
void SendMsg(int socket_fd,char * msg)
{
	int lenght = strlen(msg)+1;
	write(socket_fd, &lenght, sizeof(lenght));
	write(socket_fd, msg, lenght);
}
int main(int argc, char * argv[])
{
	int socket_fd = socket(PF_LOCAL,SOCK_STREAM,0);
	struct sockaddr_un name;
	strcpy(name.sun_path, argv[1]);
	char * msg = argv[2];
	name.sin_family = AF_LOCAL;
	connect(socket_fd, (const struct sockaddr *)&name, (socklen_t)sizeof(name));
	SendMsg(socket_fd, msg);
	close(socket_fd);
	
	return 0;
}
