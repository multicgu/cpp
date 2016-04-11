#include<stdio.h>
#include<iostream>
#include<sys/socket.h>
#include<cstdlib>
#include<errno.h>
#include<unistd.h>
#include<cstring>
#include<sys/un.h>
using namespace std;
void SendMsg( int socket_fd, char * msg );
int main( int argc, char * argv[] )
{
	int socket_fd = socket( PF_LOCAL, SOCK_STREAM, 0 );
	struct sockaddr_un name;
	strcpy( name.sun_path, argv[1] );
	name.sun_family = AF_LOCAL;
	connect( socket_fd, (struct sockaddr *)&name, sizeof(name) );
	SendMsg( socket_fd, argv[2] );
	close( socket_fd );

	return 0;
}
void SendMsg( int socket_fd, char * msg )
{
	int length = strlen(msg)+1;
	write( socket_fd, &length, sizeof(length) );
	write( socket_fd, msg, length );
}
