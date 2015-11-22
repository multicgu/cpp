#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main() {
	string a,b;
	cin >> a;
	cin >> b;
	int as = a.size();
	int bs = b.size();

	int i,br,n,sum=0;
	for(i=0;i<as;i++) {
		br=0;
		if(a[i] == b[0]) {
			for(br=0;br<bs && i+br<as;br++) {
				if(a[i+br]!=b[br])
					break;
				if(br==bs-1) sum++;
			}
		}
	}
	printf("%d\n",sum);

	return 0;
}
