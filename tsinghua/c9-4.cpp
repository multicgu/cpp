#include<iostream>
#include<iomanip>
//#include "array.h"
#include "c9-3.h"
using namespace std;
int main() {
	array<int> a(100);
	cout<<"Enter a number n>=2"<<endl;
	int n,count=0;
	cin >> n;
	for(int i = 2;i<n;i++) {
		bool isprime = true;
		for(int j=0;j<count;j++)
			if(i%a[j]==0) {
				isprime = false;
				break;
			}
		if(isprime) {
			if(a.getsize() == count)
				a.resize(2*count);
			a[count++] = i;
		}
	}
	for(int i=0;i<count;i++)
	cout<<setw(8)<<a[i];
	cout<<endl;

	return 0;
}
