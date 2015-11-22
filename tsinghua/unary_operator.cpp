#include<iostream>
using namespace std;
class a {
	private:
		int d;
	public:
		a(int n):d(n) {}
		a & operator ++ ();
		a operator ++ (int);
		a & operator -- ();
		a operator -- (int);
		friend ostream & operator << (ostream & o, a A);
};
a & a::operator ++ () {
	d++;
	return *this;
}
a a::operator ++ (int) {
	a temp = *this;
	++(*this);
	return temp;
}
a & a::operator -- () {
	d--;
	return *this;
}
a a::operator -- (int) {
	a temp = *this;
	--(*this);
	return temp;
}
ostream & operator << (ostream & o, a A) {
	o << A.d;
	return o;
}
int main() {
	a A(5);
	cout << A << endl;
	cout << A++ << endl;
	cout << ++A << endl;
	cout << A-- << endl;
	cout << --A << endl;
	return 0;
}
