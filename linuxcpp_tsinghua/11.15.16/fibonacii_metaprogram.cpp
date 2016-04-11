#include<stdio.h>
#include<iostream>
using namespace std;
template<int i = 0> class Fibonacci
{
	public:
		enum { value = Fibonacci<i-1>::value + Fibonacci<i-2>::value };
};
template<> class Fibonacci<1> {public: enum {value = 1};};
template<> class Fibonacci<2> {public: enum {value = 1};};

int main() 
{
	cout << "Fib1= " << Fibonacci<1>::value << endl;
	cout << "Fib2= " << Fibonacci<2>::value << endl;
	cout << "Fib3= " << Fibonacci<3>::value << endl;
	cout << "Fib4= " << Fibonacci<4>::value << endl;
	cout << "Fib10= " << Fibonacci<10>::value << endl;
	cout << "Fib30= " << Fibonacci<30>::value << endl;

	return 0;
}
