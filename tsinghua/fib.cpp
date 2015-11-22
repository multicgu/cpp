#include<iostream>
#include<stdio.h>
using namespace std;
long long fib(int n) {
	if(n==0)
		return 1;
	if(n==1)
		return 1;
	if(n>=2)
		return fib(n-1)+fib(n-2);
}
int main()
{
	int n;
	cin>>n;
	printf("%lld\n",fib(n));
	//cout<<fib(n)<<endl;

	return 0;
}
