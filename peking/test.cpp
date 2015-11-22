#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
	char a[4];
	fstream iofile("student.dat",ios::in|ios::out|ios::binary);
	if(!iofile){
		cout<<"error"<<endl;return 0;}
	
	iofile.write("abc",strlen("abc")+1);
	iofile.seekg(0,ios::beg);
	cout<<iofile.read((char*)&a,sizeof(a))<<endl;
	return 0;
}
