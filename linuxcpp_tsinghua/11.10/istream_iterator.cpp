#include<stdio.h>
#include<iostream>
#include<iterator>

using namespace std;

int main()
{
	istream_iterator<int> iit(cin),eof;
	ostream_iterator<int> oit(cout,"\n");
	while(iit != eof)
	{
		*oit = *iit;
		iit++;
	}

	return 0;
}
