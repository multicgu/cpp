#include<iostream>
struct X {
	void x() {std::cout<<"X";}
};
int main() {
	X x1();
	X x2();
	return 0;
}
