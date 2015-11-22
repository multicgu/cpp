#include<iostream>
using namespace std;
class A {
	public:
	void display() {
		cout << "A::display" << endl;
	}
};
class B: public A {
	public:
	void display() {
		cout << "B::display" << endl;
	}
};
class driver: public B {
	public:
	void display() {
		cout << "driver::display" << endl;
	}
};
void fun(A * ptr) {
	ptr->display();
}
int main() {
	A a;
	B b;
	driver d;
	fun(&a);
	fun(&b);
	fun(&d);
}
