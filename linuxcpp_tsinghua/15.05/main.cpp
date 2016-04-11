#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include "srv.cpp"

using namespace std;

int main()
{
	char * msg;
	int socket_fd;
	struct socketaddr_in name;
	int setname_bind( &socket_fd, &name ); //return numbers of char;
	cout << "In main " << msg << endl;
	return 0;
}
