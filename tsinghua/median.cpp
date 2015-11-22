#include<iostream>
#include<cstdio>
using namespace std;
template<class T>
void merge(T * arr,long head,long tail) {
	long mid=(head+tail)>>1;
	long la=mid-head;
	long lb=tail-mid;
	long lc=tail-head;
	T * A=new T[la];
	for(int i=0;i<la;i++)
		A[i]=arr[head+i];
	T * B=arr+mid;
	T * C=arr+head;
	long a=0,b=0,i=0;
	while(a<la) {
		if(A[a]<B[b] || b>=lb) {C[i++]=A[a++];}
		if(B[b]<=A[a] && b<lb) {C[i++]=B[b++];}
	}
}
template<class T> 
void mergesort(T * arr,long head,long tail) {
	//printf("%d %d\n",head,tail);
	if(tail-head<2) return;
	long mid=(head+tail)>>1;
	mergesort(arr,head,mid);
	mergesort(arr,mid,tail);
	merge(arr,head,tail);
}
template<class T>
void cal_median(T * arr,long size) {
	mergesort(arr,0,size);
	//for(int i=0;i<size;i++) cout << i<< "="<< arr[i] << " ";
	//cout << endl;
	cout << arr[size/2] << endl;
}
int main() {
	unsigned int m;
	unsigned long n;
	cin >> m;
	cin >> n;
	int M[m];
	double N[n];
	for(int i=0;i<m;i++)
		cin >> M[i];
	for(int i=0;i<n;i++)
		cin >> N[i];
	cal_median(M,m);
	cal_median(N,n);

	return 0;
}
