#include<iostream>
using namespace std;
class base1 {
	public:
	virtual void display()=0; 
};
class base2:public base1 {
	public:
		virtual void display();
};
void base2::display() {
	cout << "base2 display" << endl;
}
class derived:public base2 {
	public:
		virtual void display();
};
void derived::display() {
	cout << "derived:: display" << endl;
}
void fun(base1 * p) {
	p->display();
}
int main() {
	base2 b2;
	derived d;
	fun(&b2);
	fun(&d);

	return 0;
}
