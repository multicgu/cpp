#include<iostream>
using namespace std;
class IntNum {
	public:
		IntNum(int x=0):xptr(new int(x)) {
			cout<< "calling constructor.." << endl;
		}
		IntNum(const IntNum & n):xptr(new int(*n.xptr)) {
			cout << "calling copy constructor.." << endl;
		}
		~IntNum() {delete xptr; cout<<"calling destructing.."<<endl;}
		IntNum(IntNum && n):xptr(n.xptr) {
			n.xptr = NULL;
			cout<< "calling move constructor.." << endl;
		}
		int getInt() {return *xptr;}
	private:
		int * xptr;
};
IntNum getNum() {
	IntNum a;
	return a;
}
int main(void) {
	cout<< getNum().getInt()<<endl;
}
