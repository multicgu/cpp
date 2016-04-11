#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<getopt.h>
using namespace std;
const char * program_name;
void OutPutInfo(ostream & os,int exit_code)
{
	os << "Usage: " << program_name << "options[filename]" << endl;
	os << "-h --help: " << "Show the use manual." << endl;
	os << "-o --output" << "Filename:write output to file." << endl;
	os << "-v --vebose" << "Show the detail imformation." << endl;
	exit(exit_code);
}

int main(int argc,char * argv[])
{
	const char * short_opt = "ho:v";
	const struct option long_opt[] = 
	{
		{"help",0,NULL,'h'},
		{"output",1,NULL,'o'},
		{"vebose",0,NULL,'v'},
		{NULL,0,NULL,0}
	};
	int vebose = 0;
	char * filename = NULL;
	program_name = argv[0];
	int opt = getopt_long(argc,argv,short_opt,long_opt,NULL);
	while(opt != -1) {
		switch(opt) {
			case 'h': OutPutInfo(cout,0); break;
			case 'o': filename = optarg; break;
			case 'v': vebose = 1; break;
			case '?': OutPutInfo(cerr,0); break;
			case -1: break;
			default: abort();
		}
		opt = getopt_long(argc,argv,short_opt,long_opt,NULL);
	}

	return 0;
}
