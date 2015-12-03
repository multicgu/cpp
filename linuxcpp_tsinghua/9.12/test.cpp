#include<stdio.h>
#include<iostream>
using namespace std;
class Base
{
	public:
		Base(int a):data(a) {}
		virtual void printdata() { cout << "in base " << data << endl; }
		int getdata() {return data;}
	private:
		int data;
};
class Derive:public Base
{
	public:
		Derive(int d):Base(d) { }
		virtual void printdata() {cout << "in derive " << getdata() << endl;}
};

int main()
{
	//Base * base = new Derive(5);
	Derive d(5);
	d.printdata();
	//Derive derive = d;
	Base *base = &d;
	//derive.printdata();
	base->printdata();
	
	return 0;
}	
