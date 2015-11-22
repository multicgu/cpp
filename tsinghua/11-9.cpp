#include<iostream>
#include<istream>
#include<string>
using namespace std;
struct salaryinfo {
	unsigned id;
	double salary;
};
int main() {
	salaryinfo emplyee1 = {600001,8000};
	ofstream os("abc",ios_base::binary);
	os.write((char*)&emplyee1,sizeof(emplyee1));
	os.close();
	ifstream is("abc",ios_base::binary);
	if(is) {
		salaryinfo emplyee2;
		is.read((char*)&emplyee2,sizeof(emplyee2));
		cout<<emplyee2.id<<" "<<emplyee2.salary<<endl; 
		is.close();
	}
	else {
		cout << "Error: cannot open file 'abc'"<<endl;
	}
	return 0;
}
