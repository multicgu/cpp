#include<iostream>
#include<fstream>
using namespace std;
int main() {
	int a[] = {0,1,2,3,0,4,0};
	ofstream ofile("integers",ios_base::binary);
	ofile.write((char *)a,sizeof(a));
	ofile.close();
	ifstream file("integers",ios_base::binary);
	if(file) {
		while(file) {
			int v;
			streampos here = file.tellg();
			file.read((char *)&v,sizeof(v));
			if(file && v==0)
				cout << "position "<<here<<" is 0"<<endl;
		}
	} else {
		cout<<"Error:cannot open file 'integers'"<<endl;
	}
	file.close();
	return 0;
}
