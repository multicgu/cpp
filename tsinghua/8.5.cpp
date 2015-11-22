#include<iostream>
using namespace std;
class base {
	public:
		virtual ~base();
};
base::~base() {cout<<"base::disconstructor"<<endl;}
class derived:public base {
	private:
		int * ptr;
	public:
		derived() {ptr=new int(0);}
		virtual ~derived();
};
derived::~derived() {cout<<"derived::disconstructor"<<endl;delete ptr;}
void fun(base * b) {
	delete b;
}
int main() {
	derived * b = new derived();
	fun(b);
	return 0;
}
