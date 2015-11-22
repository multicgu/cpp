#include<iostream>
#include<stdexcept>
#include<iomanip>
#include<cmath>
using namespace std;
double calArea(double a,double b,double c) throw(invalid_argument){
	if(a==b || b==c || a==c) {
		double s = (a+b+c)/2;
		return sqrt(s*(s-a)*(s-b)*(s-c));
	}
	else 
		throw invalid_argument("The input is illegal");
}
int main() {
	double a,b,c;
	cin >> a >> b >> c;
	try {
		double area = calArea(a,b,c);
		cout << setiosflags(ios_base::fixed);
		cout<< setprecision(2) << area << endl;
	} catch(exception & e) {
		cout <<e.what() << endl;
		
	}
	return 0; 
}
