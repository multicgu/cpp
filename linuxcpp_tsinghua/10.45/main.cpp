#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;
class Couple
{
	private:
		int _a[2];
	public:
		Couple(int a1,int a2) {_a[0] = a1;_a[1] = a2;}
		int & operator[](int index);
		const int operator[](int index) const;
		Couple & operator=(const Couple & c);
		Couple & operator++();
		Couple operator++(int);
		friend bool operator==(const Couple & a,const Couple &b);
		friend bool operator!=(const Couple & a,const Couple &b);
		friend ostream & operator<<(ostream & os,const Couple & a);
		friend istream & operator>>(istream & is,Couple & a);
};
bool operator==(const Couple &a,const Couple &b)
{
	return (a._a[0] == b._a[0] && a._a[1] == b._a[1]);
}
bool operator!=(const Couple &a,const Couple &b)
{
	return (a._a[0] != b._a[0] || a._a[1] != b._a[1]);
}
int & Couple::operator[](int index)
{
	if(index<0 || index>1)//throw std::out_of_range("Index is out of range.");
		{cout << "Index is out of range." << endl; exit(1);}
	return _a[index];
}
const int Couple::operator[](int index) const
{
	if(index<0 || index>1)//throw std::out_of_range("Index is out of range.");
		{cout << "Index is out of range." << endl; exit(1);}
	return _a[index];
}
Couple & Couple::operator=(const Couple & c)
{
	if(*this == c) return *this;
	this->_a[0] = c._a[0];
	this->_a[1] = c._a[1];
	return *this;
}
Couple & Couple::operator++()
{
	++_a[0];++_a[1];
	return *this;
}
Couple Couple::operator++(int a)
{
	Couple _t = *this;
	++_a[0]; ++_a[1];
	return _t;
}
ostream & operator<<(ostream & os,const Couple & a)
{
	os << "(" << a[0] << "," << a[1] << endl;
	return os;
}
istream & operator>>(istream & is,Couple & a)
{
	is >> a[0] >> a[1];
	return is;
}
int main()
{
	Couple a(1,2),b(1,2),c(2,3);
	if(a == b) cout << "a = b" << endl;
	if(a == c) cout << "a = c" << endl;
	if(a != c) cout << "a!=c" << endl;

	a[0] = 5;
	a[1] = 6;
	//cout << a[0] << "," << a[1] << endl;
	cout << a;
	//cin >> b[0] >> b[1];
	cin >> b;
	//cout << b[0] << "," << b[1] << endl;
	cout << b;

	a = b;
	cout << "After a=b,a= " //<< a[0] << "," << a[1] << endl;
	cout << a;
	++a;
	cout << "After ++a,a= " // << a[0] << "," << a[1] << endl;
	cout << a;
	c = a++;
	cout << "After c=a++,c= "// << c[0] << "," << c[1] << endl;
	cout << c;
	cout << "After c=a++,a= "// << a[0] << "," << a[1] << endl;
	cout << a;

	return 0;
}
