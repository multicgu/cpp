#include<iostream>
#include<vector>
using namespace std;
void mergesort(int * arr,int lo,int hi);
//void mergesort(vector<int> & arr,int lo,int hi);
void merge(int * arr,int lo,int hi);
//void merge(vector<int> & arr,int lo,int hi);
void penult(int * arr,int n,int k);
//void penult(vector<int> & arr,int n,int k);
int main() {
	int n,k;
	cin >> n >> k;
	int * arr = new int[n];
	//vector<int> arr;
	for(int i = 0;i<n;i++) 
		cin >> arr[i]; 
	penult(arr,n,k);
	delete [] arr;
	return 0;
}

void penult(int * arr,int n,int k) { //倒数K的函数；
//void penult(vector<int> & arr,int n,int k) {
	merge(arr,0,n);   //先排序;
	cout<<arr[k-1]<<endl;  //输出迪K小的数；
}
void mergesort(int * arr,int lo,int hi) { //归并排序；
//void mergesort(vector<int> & arr,int lo,int hi) {
	/*if((hi-lo)<2) {cout<<"error!!!"<<endl; return;}
	int mi = (lo+hi)>>1;
	int la=mi-lo;
	int lc=hi-mi;
	vector<int> A;
	for(int i=0;i<la;i++) A.push_back(arr[i]);
	vector<int> & B = arr;
	int a,c;
	for(int i=0,a=0,c=0;a<la;) {
		if(c>=lc || A[a]<=arr[lo+c]) B[i++]=A[a++];
		if(c>=lc || A[a]<=arr[lo+c]) B[i++]=A[a++];
	}*/
	//int A[mi-lo];
	int mi = (lo+hi)>>1;
	int la=mi-lo;
	int lc=hi-mi;
	int * A = new int(mi-lo);
	int * B = &arr[lo];
	int * C = &arr[mi];
	for(int i=0;i<la;i++) A[i]=arr[lo+i];
	int a,c;
	for(int i=0,a=0,c=0;a<la;) {
		if(c>=lc || A[a]<=C[c]) B[i++]=A[a++];
		if(c<lc && arr[mi+c]<A[a]) B[i++]=arr[mi+c++];
	} 
	delete [] A;  //为什么使用delete配合new编译会报内存的错？
}
void merge(int * arr,int lo,int hi) {  //归并；
//void merge(vector<int> & arr,int lo,int hi) {
	if((hi-lo)<=1) return;
	int mi = (lo+hi)>>1;
	merge(arr,lo,mi);
	merge(arr,mi,hi);
	mergesort(arr,lo,hi);
}
