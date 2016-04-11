#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string.h>

using namespace std;

class diskfree
{
	private:
		char * cmd;
		char * filename;
		char * htmlfile;
	public:
		// init the private;
		diskfree()
		{
			char _cmd[] = "df -h";
			cmd = _cmd;
			printf("%s\n", cmd);
			char _filename[] = "diskfree.txt";
			filename = _filename;
			char _htmlfile[] = "diskfree.html";
			htmlfile = _htmlfile;
		}
		 
		int generate_html( )
		{
			FILE * fstream;
			FILE * wstream = fopen( htmlfile, "w+" );
			char output[1024];
			memset( output, 0, sizeof(char)*1024 );  // clear the output
			fstream = popen( cmd, "r" ); //run cmd in popen & import resault to fstream
			string s = html_format( fstream ); 
			fwrite( s.c_str(), 1, s.size(), wstream );
			return 0;
		}
		 
		string html_format( FILE * fstream )
		{
			char format_head[] = "<html><body><p>";
			char format_end[] = "</p></body></html>";
			string buf;
			buf += format_head;
			cout << buf << endl;
			char ch;
			rewind(fstream);
			while( (ch = fgetc( fstream )) != EOF ) {
				if( ch == ' ' ) buf += "&nbsp;";
				else if( ch == '\n' ) buf += "<br/>";
				else buf += ch;
			}
			buf += format_end;
			cout << buf << endl;
			return buf;
		}
};

typedef diskfree * create_df();
/*
int main()
{
	diskfree text;
	text.generate_html();

	return 0;
}*/
