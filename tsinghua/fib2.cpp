#include<iostream>
using namespace std;
long fib(int n)
{
	int i=0;
	long sum=0;
	long pre1,pre2;
	pre1=pre2=1;
	if(n<2)
		return 1;
	else
	{
		for(i=2;i<=n;i++)
		{
			sum=pre1+pre2;
			pre1=pre2;
			pre2=sum;
		}
		return sum;
	}
}
int main()
{
	int n;
	cin>>n;
	cout<<fib(n)<<endl;
	return 0;
}
