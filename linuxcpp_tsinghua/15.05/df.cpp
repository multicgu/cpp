#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<string.h>

using namespace std;

extern "C" string html_format( FILE * fstream )
{
	char format_head[] = "<html><body><p>";
	char format_end[] = "</p></body></html>";
	string buf;
	buf += format_head;
	char ch;
	rewind( fstream ); // seek stream head;
	while( (ch = fgetc( fstream )) != EOF ) {
		if( ch == ' ' ) buf += "&nbsp;";
		else if( ch == '\n' ) buf += "</br>";
		else buf += ch;
	}
	buf += format_end;
	cout << buf << endl;
	return buf;
}
extern "C" string generate_html( )
{
	char * cmd = "df -h";
	char * htmlfile = "diskfree.html";
	FILE * fstream;
	FILE * wstream = fopen( htmlfile, "w+" );
	char output[1024];
	memset( output, 0, sizeof(char)*1024 );
	fstream = popen( cmd, "r" );
	string s = html_format( fstream );
	cout << "In string generate_html" << endl;
	cout << s << endl;
	fwrite( s.c_str(), 1, s.size(), wstream );
	return s;
}

