#include<iostream>
using namespace std;
bool juuglynum(long n)
{
	if(n%2==0)
		juuglynum(n/2);
	else if(n%3==0)
		juuglynum(n/3);
	else if(n%5==0)
		juuglynum(n/5);
	else if(n==1)
		return true;
	else
		return false;
}
int main()
{
	long n;
	cin>>n;
	if(n==1)
	{
		cout<<"False"<<endl;
		return 0;
	}
	if(juuglynum(n))
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;

	return 0;
}
