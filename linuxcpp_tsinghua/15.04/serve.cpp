#include<stdio.h>
#include<iostream>
#include<sys/socket.h>
#include<cstring>
#include<cstdlib>
#include<sys/un.h>
#include<unistd.h>
#include<errno.h>
using namespace std;
bool Serve(int client_fd);
int main(int argc, char * const argv[])
{
	char * socket_file = "/tmp/server/socket";
	if(argc != 1)  socket_file = argv[1];
	int socket_fd;
	struct sockaddr_un name;
	strcpy(name.sun_path,socket_file);
	socket_fd = socket(PF_LOCAL, SOCK_STREAM, 0);
	name.sun_family = AF_LOCAL;
	bind(socket_fd, ( struct sockaddr *)&name,(socklen_t)sizeof(name));
	listen(socket_fd,5);
	bool serve = true;
	while(serve) {
		struct sockaddr_un clientname;
		socklen_t clientlen;
		int client_fd = accept(socket_fd,(struct sockaddr *)&clientname,&clientlen);
		serve = Serve(client_fd);
		close(client_fd);
	}
	close(socket_fd);
	int a = unlink( socket_file );
	return 0;
}
bool Serve(int client_fd)
{
	int end = 1;
	while(end) {
		int n;
		end = read( client_fd, &n, sizeof(n) );
		if( end == 0 ) return true;
		char buf[n];
		read( client_fd, buf, n );
		cout << buf << endl;
		if(!strcmp( buf, "quit" )) return false;
	}
}
