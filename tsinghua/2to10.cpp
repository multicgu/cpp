#include<stdio.h>
#include<iostream>
using namespace std;
int change(long n);
int main()
{
	int i=0;
	long n;//binary;
	cin>>n;
	cout<<change(n)<<endl;

	return 0;
}
int change(long n)
{
	int i,a;
	int m=0,h,temp;
	for(i=0;n>=1;n/=10,i++)
	{
		a=1;
		temp=n%10;
		if(i==0)
			m+=temp;
		else
		{
			for(h=0;h<i;h++)
				a*=2;
			m+=temp*a;
		}
	}
	return m;
}
