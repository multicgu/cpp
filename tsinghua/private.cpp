#include<iostream>
using namespace std;
class A {
	private:
		int x;
	public:
		int y;
};
class B: private A {
	public:
	void fun() {
		y = 5;
	}
	void show() {
	cout << y << endl;
	};
};
int main() {
	B b;
	b.fun();
	b.show();
	return 0;
}
