#include<iostream>
#include<fstream>
using namespace std;
struct date {
	int mon,day,year;
};
int main() {
	date dt = {6,10,92};
	ofstream file("date",ios_base::binary);
	file.write((char *) &dt,sizeof(dt));
	file.close();

	return 0;
}
