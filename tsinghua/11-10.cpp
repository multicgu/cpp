#include<iostream>
#include<fstream>
using namespace std;
int main() {
	int values[] = {3,7,0,5,4};
	ofstream os("abc",ios_base::binary);
	os.write((char *)values,sizeof(values));
	os.close();

	ifstream is("abc",ios_base::binary);
	int v;
	if(is) {
		is.seekg(3*sizeof(int));
		is.read((char *)&v,sizeof(v));
		cout<< v << endl;
		is.close();
	}
	else cout <<"Error: Cannot open file 'abc'"<<endl;
	return 0;
}
