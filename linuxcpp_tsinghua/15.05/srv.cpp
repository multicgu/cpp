#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include "run_module.cpp"

using namespace std;

int setname_bind( int * socket_fd, struct sockaddr_in * name );
int return_html( int socket_fd, string msg );
int getmsg( int * socket_fd, string & msg );

int main()
{
	int socket_fd;
	struct sockaddr_in name;

	setname_bind( &socket_fd, &name );
	listen( socket_fd, 10 );
	string msg;
	cout << getmsg( &socket_fd, msg ) << endl;
	cout << msg[0] << endl;
	// check the client's cmd, add the so file, generate the html file
	switch (msg[0])
	{
		case 'd':
			//if( s = run_mod( "libdf.so" ) == NULL ) cout << "Run_mod failed\n";
			s = run_mod( "libdf.so" );
			break;
		case 'r':
			break;
		case 't':
			break;
		case 'm':
			break;
		case 'v':
			break;
	}
	printf("string s\n");
	cout << s << endl;
	return_html( socket_fd, s );

	return 0;
}

int setname_bind( int * socket_fd, struct sockaddr_in * name )
{
	*socket_fd = socket( AF_INET, SOCK_STREAM, 0 );
	name->sin_family = AF_INET;
	name->sin_port = htons( 80 );
	name->sin_addr.s_addr = htonl(INADDR_ANY);
	bind( *socket_fd, (struct sockaddr *)name, sizeof(*name) );
	return 0;
}

int getmsg( int * socket_fd, string & msg )
{
	struct sockaddr_in cli_name;
	socklen_t cli_nalen;
	int cli_sock_fd = accept( *socket_fd, (struct sockaddr *)&cli_name, &cli_nalen );
	if( cli_sock_fd == -1 ) {
		cout << "accept error" << endl;
		exit( 1 );
	}
	int end;
	if( read( cli_sock_fd, &end, sizeof(end) ) == 0 ) return 0;
	char * tmp = new char[end];
	read( cli_sock_fd, tmp, end );
	msg += tmp;
	return end;
}

int return_html( int socket_fd, string msg )
{
	int length = msg.size()+1;
	printf("testtesttestbefore\n");
	if( write( socket_fd, &length, sizeof(length) ) == -1 ){
	   	cout << "return htm error" << endl; 
		exit( 1 ); 
	}
	write( socket_fd, msg.c_str(), length );
	printf("testtesttestend\n");
	return 0;
}
