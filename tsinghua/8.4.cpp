#include<iostream>
using namespace std;
class base1 {
	public:
		virtual void display();
};
void base1::display() {cout<<"base1::display()"<<endl;}
class base2:public base1 {
	public:
		virtual void display();
};
void base2::display() {cout<<"base2::display()"<<endl;}
class derived:public base2 {
	public:
		virtual void display();
};
void derived::display() {cout<<"derived::display()"<<endl;}
void display(base1 * ptr) {
	ptr->display();
}
int main() {
	base1 b1;
	base2 b2;
	derived d;
	display(&b1);
	display(&b2);
	display(&d);

	return 0;
}
