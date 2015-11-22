#include<iostream>
#include<string>
using namespace std;
int main() {
	string line;
	cout << "Type a line terminate by 't'" << endl;
	getline(cin,line,'t');
	cout << line << endl;

	return 0;
}
