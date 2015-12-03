#include<stdio.h>
#include<iostream>
using namespace std;
class Couple
{
	private:
		int _a,_b;
	public:
		Couple(int a,int b):_a(a),_b(b) {}
		void print() {printf("(%d,%d)\n",_a,_b);}
		friend Couple operator+(const Couple & a,const Couple & b);
		friend Couple operator*(const Couple & a, const Couple & b);
		friend Couple operator*(const int & a, const Couple & b);
		friend Couple operator*(const Couple & a, const int & b);
};
Couple operator+(const Couple & a, const Couple & b)
{
	Couple c(a._a + b._a, a._b + b._b);
	return c;
}
Couple operator*(const Couple & a, const Couple & b)
{
	Couple c(a._a * b._a, a._b * b._b);
	return c;
}
Couple operator*(const int & a, const Couple & b)
{
	Couple c(a*b._a, a*b._b);
	return c;
}
Couple operator*(const Couple & a, const int & b)
{
	Couple c(b*a._a, b*a._b);
	return c;
}

int main()
{
	Couple a(1,2);
	Couple b(3,4);
	int k = 3;
	Couple c = a + b;
	c.print();
	c = a * b;
	c.print();
	c = k*c;
	c.print();
	c = c*k;
	c.print();

	return 0;
}
