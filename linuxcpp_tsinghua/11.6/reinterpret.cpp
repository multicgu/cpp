#include<stdio.h>
#include<iostream>
using namespace std;
int f(void *p)
{
	int n = reinterpret_cast<int>(p);
	return n;
}
int main() 
{
	printf("int=%d, int *=%d\n",sizeof(int),sizeof(int*));
	int n[8]={1,2,3,4,5,6,7,8};
	cout << f(n) << endl;
	return 0;
}
