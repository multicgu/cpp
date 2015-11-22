#include<iostream>
#include<stdio.h>
using namespace std;
void recursion(int n,int i);
int main()
{
	int n,i=1;
	cin>>n;
	recursion(n,i);
	return 0;
}
void recursion(int n,int i)
{
	int m=0;
	for(m=0;m<(2*n-1)/2;m++)
		printf(" ");
	for(m=0;m<2*i-1;m++)
		printf("*");
	puts("");
	if(n==1)
		return;
	recursion(n-1,i+1);
	for(m=0;m<(2*n-1)/2;m++)
		printf(" ");
	for(m=0;m<2*i-1;m++)
		printf("*");
	puts("");
}
