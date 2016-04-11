#include<iostream>
#include<stdio.h>
#include<dlfcn.h>
#include<string.h>
#include<stdlib.h>
//#include "diskfree.cpp"
#include "df.h"

using namespace std;

typedef string (* fun)();

string run_mod( char * soname )
{
	char * fun_name = "generate_html";
	printf("%s\n", soname);
	void * handle = dlopen( soname, RTLD_LAZY );
	if( handle == NULL ) {
		printf( "dlopen failed. %s\n", dlerror() );
		exit( 1 );
	}
	fun f = (fun)dlsym( handle, fun_name );
	if( f == NULL ) {
		printf( "dlsym error.  %s\n", dlerror() );
		exit( 1 );
	}
	string s = f();
	dlclose( handle );
	return s;
}
