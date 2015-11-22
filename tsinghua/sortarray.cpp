#include<iostream>
#include<stdio.h>
#include<vector>
//#include<sort>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(&a[0],&a[n]);
	vector<int> arr(a,a+n);
	vector<int>::iterator iter = unique(arr.begin(),arr.end());
	arr.erase(iter,arr.end());
	int N = arr.size();
	for(vector<int>::iterator t = arr.begin();t!=arr.end();t++)
		printf("%d\n",*t);

	return 0;
}
