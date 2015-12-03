// show the program crash by shallow copy
#include<stdio.h>
#include<iostream>
using namespace std;
class A
{
	private:
		int _n;
		int * _p;
	public:
		A():_n(0),_p(NULL) {}
		A(int n):_n(n),_p(new int[n]) {}
		A(int n,int * p):_n(n),_p(p) {}
		A(const A & c):_n(c._n),_p(c._p) {}
		A & operator=(const A & a) {_n=a._n;_p=a._p;return *this;}
		~A() {if(_p){delete _p; _p = NULL;}}
		int & operator[](int i);
		const int operator[](int i)const;
};
int & A::operator[](int i) {return _p[i];}
const int A::operator[](int i)const {return _p[i];}
int main()
{
	A a(4),b;
	for(int i=0;i<4;i++)
		a[i] = i+1;
	cout << "Before object assignment:" << endl;
	for(int i=0;i<4;i++)
		cout << a[i] << " ";
	cout << endl;
	b = a;
	cout << "After object assignment:" << endl;
	for(int i=0;i<4;i++)
		cout << b[i] << " ";
	cout << endl;

	return 0;
}
