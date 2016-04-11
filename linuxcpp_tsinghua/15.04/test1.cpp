#include<stdio.h>
#include<iostream>
#include<netdb.h>
using namespace std;
int main()
{
	char * a = "www.163.com";
	if(a == NULL) cout << "error" << endl;
	struct hostent * host = gethostbyname(a);
	cout << (host->h_name) << endl;
	cout << host->h_length << endl;
	cout << host->h_addr << endl;
	spawn(hostname);
	
	return 0;
}
