#include<iostream>
#include<stdio.h>
#include<dlfcn.h>

using namespace std;

int run_mod( char * soname )
{
	void * handle = dlopen( soname, RTLD_LAZY );
	char * fun_name = "generate_html";
	if( handle == NULL ) {
		printf( "dlopen failed. %s\n", dlerror() );
		return 1;
	}
	int (* fun)();
	fun = dlsym( handle, fun_name );
	if( fun == NULL ) {
		printf( "dlsym error.  %s\n", dlerror() );
		return 1;
	}
	fun();
	return 0;
}
