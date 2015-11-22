#include<iostream>
using namespace std;
class complex {
	public:
		complex(double r=0.0,double i=0.0):real(r),imag(i) {}
		complex operator + (const complex & c2) {
			return complex(real+c2.real,imag+c2.imag);
		}
		complex operator - (const complex & c2) {
			return complex(real-c2.real,imag-c2.imag);
		}
		void display() {
			cout<<'('<<real<<','<<imag<<')'<<endl;
		}
	private:
		double real;
		double imag;

};
int main() {
	complex c1(5,4),c2(2,10),c;
	c=c1+c2;
	c.display();
	c=c1-c2;
	c.display();

	return 0;
}
