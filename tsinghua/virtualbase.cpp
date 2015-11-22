#include<iostream>
using namespace std;
class base0 {
	public:
		base0(int var):var0(var) {}
		int var0;
		void fun0() {cout<<"Member of base0"<<endl;
			cout << var0 << endl;
		}
};
class base1: virtual public base0 {
	public:
		base1(int var):base0(var),var1(var) {}
		int var1;
		void fun1() {cout << "Member of base1" << endl;}
};
class base2: virtual public base0 {
	public:
		base2(int var):base0(var),var2(var) {}
		int var2;
		void fun2() {cout << "Member of base2"<< endl;}
};
class derived: public base1,public base2 {
	public:
		derived(int var):base0(var),base1(var),base2(var) {}
		int var;
		void fun() {cout << "Member of Derived"<<endl;}
};
int main() {
	derived d(1);
	d.fun0();
	d.var0 = 2;
	d.fun0();

	return 0;
}
