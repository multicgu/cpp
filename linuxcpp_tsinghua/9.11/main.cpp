#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

class Base 
{
	public:
		Base(string s):str_a(s) {}
		Base(const Base & that):str_a(that.str_a){}
		void print() { cout << "In Base " << str_a << endl; }
	protected:
		string str_a;
};
class Derived:public Base
{
	public:
		Derived(string s1,string s2):Base(s1),str_b(s2) {}
		void print() {cout <<"In Derive "+str_a+" "+str_b << endl; }
	protected:
		string str_b;
};

int main() 
{
	Derived d1("Hello","world");
	Base b1 = d1;
	d1.print(); b1.print();
	Base & b2 = d1;
	d1.print(); b1.print();
	Base * b3 = &d1;
	d1.print(); b1.print();

	return 0;
}
