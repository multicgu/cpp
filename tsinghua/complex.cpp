#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class complex {
	private:
		double r,i;
	public:
		void print(){
			cout << r << "+" << i << "i" << endl;
		}
		complex():r(0),i(0){}
		complex & operator=(const string & s)
		{
			int pos = s.find("+",0);
			string stmp = s.substr(0,pos);
			r = atof(stmp.c_str());
			stmp = s.substr(pos+1,s.length()-pos-2);
			i = atof(stmp.c_str());
			return * this;
		}
};
int main()
{
	complex a;
	a = "3 + 4i";a.print();
	a = "5 + 6i";a.print();
	return 0;
}
