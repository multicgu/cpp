#include<stdio.h>
#include<iostream>
using namespace std;
class Couple
{
	private:
		int _a,_b;
	public:
		Couple(int a,int b):_a(a),_b(b) {}
		Couple operator+(const Couple & c);
		Couple operator*(const Couple & c);
		void print() {printf("(%d,%d)\n",_a,_b);}
};
Couple Couple::operator+(const Couple & c)
{
	Couple _t(this->_a + c._a, this->_b + c._b);
	return _t;
}
Couple Couple::operator*(const Couple & c)
{
	Couple _t(this->_a * c._a, this->_b * c._b);
	return _t;
}
int main()
{
	Couple a(3,4);
	Couple b(1,2);
	Couple c = a + b;
	c.print();
	return 0;
}
