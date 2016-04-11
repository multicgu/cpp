#include <iostream>
#include<stdio.h>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

int  WriteToTempFile( char * buffer, size_t length )
{
	char  temp_filename[] = "/tmp/temp_file.XXXXXX";
	int  fd = mkstemp( temp_filename );
	//unlink( temp_filename );
	write( fd, &length, sizeof(length) );
	printf("write length %d, sizeof length %d\n",length,sizeof(length));
	write( fd, buffer, length );
	return fd;
}

char *  ReadFromTempFile( int fd, size_t * length )
{
	lseek( fd, 0, SEEK_SET ); //文件定位，SEEK_SET文件开始，偏移量0;
    read( fd, length, sizeof(*length) );
	printf("read length %d, sizeof length %d\n",*length,sizeof(*length));
	char *  buffer = new char[*length];
    read( fd, buffer, *length );
	close( fd );
    return buffer;
}
int main()
{
	char *  s = "This a test text.";
    int  fd = WriteToTempFile( s, strlen(s) );
	size_t   length;
    char *  t = ReadFromTempFile( fd, &length );
	std::cout << t << std::endl;
    return 0;
}
