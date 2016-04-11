#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<arpa/inet.h>
//#include<errorn>
using namespace std;
int main( int argc, char * argv[] )
{
	int socket_fd = socket( AF_INET, SOCK_STREAM, 0 );
	struct sockaddr_in name;
	name.sin_family = AF_INET;
	name.sin_port = htons(80);
	if( argc >= 2 ) 
		name.sin_addr.s_addr = inet_addr(argv[1]);
	else
		name.sin_addr.s_addr = inet_addr("192.168.247.139");  // srv ip
	if(connect(socket_fd, (const struct sockaddr *)&name, sizeof(name))== -1) {
		cout << "connect error" << endl;
		exit(1);
	}
	char * msg = "diskfree";
	int length = strlen(msg) + 1;
	cout << length << endl;
	write( socket_fd, &length, sizeof(length) );
	write( socket_fd, msg, length );

	char * rev_htm;
	if( read( socket_fd, &length, sizeof(int) ) == -1 ) {
		cout << "read html error" << endl;
	}
	read( socket_fd, rev_htm, length );
	printf("testtesttest.\n");

	cout << msg << endl;

	return 0;
}
