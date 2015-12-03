#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;
class A
{
	private:
		int _n,*_p;
	public:
		A():_n(0),_p(NULL) {}
		A(int n,int *p):_n(n),_p(p) {}
		A(int n):_n(n),_p(new int[_n]) {}
		A(const A & a);
		A(A && a);
		A & operator=(const A & a);
		A & operator=(A && a);
		const int operator[](int index)const;
		int & operator[](int index);
		virtual ~A() {if(_p) {delete _p; _p = NULL;}}
};
A::A(const A & a) {*this = a;}
A::A(A && a) {*this = static_cast<A &&>a;}
A & A::operator=(const A & a)
{
	_n = a._n; _p = new int[_n];
	for(int i = 0;i<_n;i++) _p[i] = a._p[i];
	return *this;
}
A & A::operator=(A && a)
{
	_n = a._n; _p = a._p;
	a._n = 0; a._p = NULL;
	return *this;
}
const int A::operator[](int index)const
{
	if(index<0 || index>_n) {cout << "out of range!" << endl; exit(1);}
	return _p[index];
}
int & A::operator[](int index)
{
	if(index<0 || index>_n) {cout << "out of range!" << endl; exit(1);}
	return _p[index];
}
int main()
{
	A a(4),b;
	for(int i=0;i<4;i++) a[i]=i+1;
	for(int i=0;i<4;i++) printf("a[%d] = %d; ",i,a[i]); cout << endl;
	b = a;
	for(int i=0;i<4;i++) printf("b[%d] = %d; ",i,b[i]); cout << endl;
	A c(static_cast<A &&>b);
	for(int i=0;i<4;i++) printf("c[%d] = %d; ",i,c[i]); cout << endl;
	return 0;
}
