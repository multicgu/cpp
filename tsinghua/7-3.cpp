#include<iostream>
#include<stdio.h>
using namespace std;
class A {
	private:
		int a;
	public:
		A() {a=8;cout<<"A default constructor called"<<endl;}
		A(int a){this->a=a;cout<<"A constructor called"<<endl;}
		void print() {cout<<a<<endl;}
};
class B:public A {
	private:
		int b;
	public:
		B() {b=0;cout<<"B default constructor called"<<endl;}
		//B(int b,int a):A(a) {this->b=b;cout<<"B constructor called"<<endl;}
		B(int b,int a){this->b=b;cout<<"B constructor called"<<endl;}
		void printb() {cout <<b<<endl; }
};
int main() {
	B bb(5,6);
	//B bb;
	bb.print();
	bb.printb();
	return 0;
}
