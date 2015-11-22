#include<iostream>
#include<stdio.h>
using namespace std;
class point {
	protected:
		int p;
	private:
		int x,y;
	public:
		point(int x,int y) {
			this->x = x;
			this->y = y;
		}
		int getx() {return x;}
		int gety() {return y;}
};
//class B:protected point {
class B:public point {
	public:
		B(int P,int x,int y):point(x,y) {
			p = P;
		}
		int getp() {return p;}
};
int main() {
	B b(1,2,3);
	cout << b.getp() <<","<<b.getx()<<","<<b.gety()  <<endl;

	return 0;
}
