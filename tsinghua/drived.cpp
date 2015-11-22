#include<iostream>
using namespace std;
class base0 {
	public:
		int var0;
		void fun0() {cout << "Member of Base0" << endl;
			cout << var0 << endl;
		}
};
class base1: public base0 {
	public:
		int var;
		void fun() {cout<< "Member of Base1" << endl;}
};
class base2: public base0 {
	public:
		int var;
		void fun() {cout << "Member of Base2" << endl;}
};
class derived: public base1,public base2 {
	public:
		int var;
		void fun() {cout << "Member of derived"<<endl;}
};
int main() {
	derived d;
	derived * p = &d;
	
	d.var = 4;
	d.fun();
	d.base1::var = 1;
	d.base1::fun();
	d.base2::var = 2;
	d.base2::fun();
	d.base1::var0 = 10;
	d.base1::fun0();
	d.base2::var0 = 20;
	d.base2::fun0();
	return 0;
}
