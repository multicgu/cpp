#include<iostream>
using namespace std;
int divide(int x,int y) throw(int){
	if(y==0)
		throw x;
	return x/y;
}
int main() {
	try {
		cout << "7/1 =" << divide(7,1)<<endl;;
		cout << "8/0 =" << divide(0,0)<<endl;;
		cout << "5/2 =" << divide(5,2)<<endl;;
	} catch (int e) {
		cout << e << " is divided by zero!" << endl;
	}
	cout << "That is OK!" << endl;

	return 0;
}
