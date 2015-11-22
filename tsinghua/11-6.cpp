#include<iostream>
#include<sstream>
#include<string>
using namespace std;
template<class T>
string tostring(const T & v) {
	ostringstream os;
	os << v;
	return os.str();
}
int main() {
	cout << tostring(2) <<endl;
	cout << tostring(3.4) << endl;
	return 0;
}
