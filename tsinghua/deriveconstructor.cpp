#include<iostream>
using namespace std;
class B {
	private:
		int b;
	public:
		B() {cout<<"B's default constructor called"<<endl;}
		B(int i) {
			b = i;
			cout<<"B's constructor called"<<endl;
		}
		void print() {
			cout << "b = " << b << endl;
		}
};
class C: public B {
	private:
		int c;
	public:
		C(int i,int j):B(i),c(j) {
			cout<<"C's constructor called"<<endl;
		}
		void print() {
			B::print();
			cout<<"c=="<<c<<endl;
		}
};
int main() {
	C obj(1,2);
	obj.print();
	return 0;
}
