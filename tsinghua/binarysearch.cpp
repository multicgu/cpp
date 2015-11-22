#include<iostream>
using namespace std;
template <class T>
int binSearch(T arr[],int n,T key) {
	int lo=0,hi=n-1;
	if(hi<0) hi=0;
	int mid = (lo+hi)>>1;
	//cout<<mid<<endl;
	while(hi-lo >= 0) {
		cout<<mid<<endl;
		if(key-arr[mid]<=0.01 && key-arr[mid]>=-0.01) {return mid;}
		if(key < arr[mid]) { hi=mid-1; mid=(lo+hi)>>1;}
		if(key>arr[mid]) {lo=mid+1;mid=(lo+hi)>>1;}
	}
	return hi;
}
int main() {
	int n,m;
	int key1;
	double key2;
	cin >> n >> m >>key1 >> key2;
	int * arr_int = new int[n];
	double * arr_double = new double[m];
	for(int i=0;i<n;i++)
		cin >> arr_int[i];
	for(int i=0;i<m;i++)
		cin >> arr_double[i];
	binSearch(arr_int,n,key1);
	binSearch(arr_double,m,key2);

	return 0;
}
