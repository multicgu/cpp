#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
class CStudent {
	public:
		char szName[20];
		int nScore;
};
int main()
{
	fstream iofile("student.dat",ios::out|ios::in|ios::binary);
	if(!iofile) {cout<<"error"<<endl;return 0;}
	CStudent s;
	while(cin>>s.szName>>s.nScore)
	{
		if(strcmp(s.szName,"exit")==0)
			break;
		iofile.write((char *)&s,sizeof(s));
	}
	cout<<"~~~~~~~~~~~~~~"<<endl;
	iofile.seekg(0,ios::beg);
	while(iofile.read((char *)&s,sizeof(s)))
		cout<<s.szName<<" "<<s.nScore<<endl;
	cout<<"~~~~~~~~~~~~~~"<<endl;
	iofile.seekp(2*sizeof(s),ios::beg);
	iofile.write("eric",strlen("eric")+1);
	iofile.seekg(0,ios::beg);
	cout<<"~~~~~~~"<<endl;
	while(iofile.read((char *)&s,sizeof(s)))
		cout<<s.szName<<" "<<s.nScore<<endl;

	iofile.close();
	return 0;
}
