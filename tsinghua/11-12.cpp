#include<iostream>
#include<istream>
#include<string>
using namespace std;
template<class T> 
T fromstring(const string & str) {
	istringstream is(str);
	T v;
	is >> v;
	return v;
}
int main() {
	int v1 = fromstring<int>("1");
	cout << v1 << endl;
	double v2 = fromstring<double>("1.2");
	cout << v2 << endl;
	
	return 0;
}
