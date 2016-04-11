#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
//  请求Web服务器的主页
void GetHomepage( int socket_fd )
{
	char  buffer[8192];
	sprintf( buffer, "GET /\n" );
	write( socket_fd, buffer, strlen( buffer ) );
	while( true )  {
		ssize_t  count = read( socket_fd, buffer, 8192 );
		if( count == 0 )    return;
		fwrite( buffer, sizeof( char ), count, stdout );
	}
}
int main( int argc, char * const argv[] )
{
	int  socket_fd;
	struct sockaddr_in  name;
	struct hostent *  hostinfo;
	socket_fd = socket( PF_INET, SOCK_STREAM, 0 );
	name.sin_family = AF_INET;
	hostinfo = gethostbyname( argv[1] );
	if( hostinfo == NULL )    return 1;
    else    name.sin_addr = *( (struct in_addr *)hostinfo->h_addr );
	name.sin_port = htons( 80 );
	printf("%d\n",socket_fd);
	printf("%d\n",hostinfo->h_addr);
	printf("%d\n",name.sin_addr.s_addr);
	if( connect( socket_fd, (struct sockaddr *)&name,
	sizeof(struct sockaddr_in) ) == -1 )  {
	perror( "Failure to connect the server." );
	return 2;
	}
	GetHomepage( socket_fd );
	return 0;
}

