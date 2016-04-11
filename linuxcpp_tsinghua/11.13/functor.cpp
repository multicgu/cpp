#include<stdio.h>
#include<iostream>
#include "/root/cpp/linuxcpp_tsinghua/8.9/random.cpp"
using namespace std;
//functor
template<typename T> class Comparer
{
	public:
		bool operator()(const T & a,const T & b) { return a<b; }
};

template<typename T,typename Comparer> 
const T & Min(const T * a,int n,Comparer<T> compare)
{
	int index = 0;
	for(int i=1;i<n;i++)
		if(compare(a[i],a[index])) index = i;
	return a[index];
}
/*
template<typename T>
const T & Min(const T * a,int n)
{
	int index = 0;
	Comparer<T> c;
	for(int i = 1;i<n;i++)
		if(c(a[i],a[index])) index = i;
	return a[index];
}*/
//function point
template<typename T>
bool compare(const T & a,const T & b)
{
	return a<b;
}
template<typename T>
const T & Minimum(const T * a,int n,bool (*compare)(const T &a,const T & b))
{
	int index = 0;
	for(int i=1;i<n;i++) 
		if(compare(a[i],a[index])) index = i;
	return a[index];
}
int main()
{
	int a[10];
	for(int i=0;i<10;i++) a[i] = GenerateRandomInteger(10,99);
	for(int i=0;i<10;i++) cout << a[i]<< " "; cout << endl;
	int min = Min(a,10,Comparer<int>());
	//int min = Min(a,10);
	cout << min << endl;

	int minimum = Minimum(a,10,compare);
	cout << minimum << endl;

	return 0;
}
