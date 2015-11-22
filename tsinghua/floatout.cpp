#include<iostream>
#include<iomanip>
#include<sstream>
using namespace std;
int main() {
	int a[2],b[2];
	float c[2];
	ostringstream os;
	for(int i=0;i<2;i++) {
		cin >> a[i] >> b[i];
		cin >> c[i];
	}
	for(int i =0;i<2;i++) {
		cout <<"a[i] "<<a[i]<<" b[i] "<<b[i]<<endl;
		//cout<<setprecision(b[i])<<setw(a[i]) << c[i] << endl;
		os << c[i];
		cout<<setfill('0')<<setw(a[i]+b[i])<< os.str() << endl;
	}

	return 0;
}
