#include<iostream>
using namespace std;
int main()
{
	int n,sum=1;
	int a=1;
	for(n=1;n<=10;n++)
	{
		a*=2;
		sum+=a;
	}
	cout<<sum<<endl;
	return 0;
}
