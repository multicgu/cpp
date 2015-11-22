#include<iostream>
#include<stdio.h>
#include<limits.h>
using namespace std;
int main()
{
	int i,num,max=0,min=INT_MAX,sum=0;
	int n[100];
	//cin>>num;
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d",&n[i]);
		sum+=n[i];
		if(n[i]>max)
			max=n[i];
		if(n[i]<min)
		   	min=n[i];
	}
	cout<<sum<<' '<<min<<' '<<max<<endl;
	return 0;
}
