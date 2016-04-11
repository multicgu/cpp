#include<stdio.h>
#include<iostream>
#include<iomanip>
using namespace std; 
template<int i,int p>struct PrimeCube
{
	enum {answer = (i % p) && PrimeCube<i,p-1>::answer};
	//int answer = (i % p) && PrimeCube<i,p-1>::answer;   can not be compile;
};
template<int i>struct PrimeCube<i,2> { enum {answer = 1}; };
template<int i>struct Number
{
	Number<i-1> n;
	enum{answer = PrimeCube<i,i-1>::answer};
	//int answer = PrimeCube<i,i-1>::answer;   can not be compile;
	void IsPrime()
	{
		if(answer) cout << setw(4) << right << i ;
		n.IsPrime();
		cout << setw(2) << right << answer;
	}
};
template<>struct Number<2>
{
	enum { answer = 1 };
	void IsPrime()
	{
		if(answer) cout << setw(4) << right << 2;
		cout << setw(2) << right << answer;
	}
};

int main()
{
	Number<100> a; a.IsPrime();
	return 0;
}
