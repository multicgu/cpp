#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
class a {
	public:
		char ch[10][10];
		/*a(){
			*ch=new char[10];
		}*/
};
int main()
{
	a c;
	strcpy(c.ch[0],"fjksl");
	strcpy(c.ch[1],"rueio");
	printf("%s\n%s\n",c.ch[0],c.ch[1]);
	//cout<<c.ch[0]<<endl;
	//cout<<c.ch[1]<<endl;
	return 0;
}
