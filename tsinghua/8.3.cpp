#include<iostream>
using namespace std;
class Complex {
	private:
		double real,imag;
	public:
		Complex(int r=0,int i=0):real(r),imag(i) { } 
		friend Complex operator + (const Complex & t1,const Complex & t2);
		friend Complex operator - (const Complex & t1,const Complex & t2);
		friend ostream & operator << (ostream & o,const Complex t);
};
Complex operator + (const Complex & t1,const Complex & t2) {
	return Complex(t1.real+t2.real,t1.imag+t2.imag);
}
Complex operator - (const Complex & t1,const Complex & t2) {
	return Complex(t1.real-t2.real,t1.imag-t2.imag);
}
ostream & operator << (ostream & o,const Complex t) {
	o << "(" << t.real << "," << t.imag << ")";
	return o;
}
int main() {
	Complex c1(5,4),c2(2,10),c3;
	cout<<"c1=" << c1 <<" c2="<< c2 << endl;
	c3=c1+c2;
	cout<<"c3=c1+c2"<<c3<<endl;
	c3=c1-c2;
	cout<<"c3=c1-c2"<<c3<<endl;

	return 0;
}
