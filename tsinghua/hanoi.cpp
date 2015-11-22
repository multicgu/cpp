#include<iostream>
using namespace std;
int h=0;
void move(char a,char b)
{
	cout<<"move "<<a<<" to "<<b<<endl;
}
void hanoi(int n,char s,char m,char d)
{
	h++;
	if(n==1)
		move(s,d);
	if(n>1)
	{
		hanoi(n-1,s,d,m);
		move(s,d);
		hanoi(n-1,m,s,d);
	}
}
int main()
{
	hanoi(10,'s','d','m');
	cout<<h<<endl;
	return 0;
}
