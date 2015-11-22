#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
	char a[101],b[101];
	int A[101],B[101],c[102],fu=0,n,an,bn,i,m,h,temp;
	gets(a);
	char o;
	gets(b);
	for(an=0;a[an]!='\0';an++)
		A[an]=atoi(&a[an]);
	for(bn=0;b[bn]!='\0';bn++)
		B[bn]=atoi(&b[bn]);
	if(an>bn)
	{
ququ:
		m=an-1;
		n=0;
		for(i=bn-1;i<=0;i--,m--)
		{
			c[n]=A[m]+B[i]+fu;
			if(c[n]>=10)
			{
				c[n]=c[n]%10;
				fu=1;
			}
			else
				fu=0;
			n++;
		}
		c[n]=A[m]+fu;
		i=an-m;
		for(h=0;h<i;h++)
		{
			c[n+1]=A[m+1];
		}
	}
	else
	{
		temp=an;
		an=bn;
		bn=temp;
		goto ququ;
	}
	for(h=0;h<i+m;h++)
		cout<<c[h];
	cout<<endl;

	return 0;
}
