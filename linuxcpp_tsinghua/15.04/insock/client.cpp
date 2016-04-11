#include<iostream>
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<netdb.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
using namespace std;
int GetHomePage( int socket_fd );
int main( int argc, char * argv[] )
{
	int socket_fd = socket( PF_INET, SOCK_STREAM, 0 );
	cout << "socket_fd = " << socket_fd << endl;
	struct sockaddr_in name;
	cout << argv[1] << endl;
	struct hostent * host = gethostbyname( argv[1] );
	if( host == NULL ) {
		cerr << "host error" << endl;
		return 1;
	}
	name.sin_family = AF_INET;
	name.sin_port = htons( 80 );
	name.sin_addr = *((struct in_addr *)host->h_addr);
	if(connect( socket_fd, (struct sockaddr *)&name, sizeof(struct sockaddr_in))==-1 ) {
		cerr << "connect error" << endl;
		printf("%d\n",errno);
		return 1;
	}
	GetHomePage( socket_fd );
	
	return 0;
}
int GetHomePage( int socket_fd )
{
	char buf[1024];
	int count;
	sprintf( buf, "GET /\n" );
	write( socket_fd, buf, strlen(buf) );
	while(true) {
		int count = read( socket_fd, buf, 1024 );
		if( count == 0 ) return 0;
		fwrite( buf, sizeof(char), count, stdout );
	}
}
