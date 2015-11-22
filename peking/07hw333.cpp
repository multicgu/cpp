#include<iostream>
#include<string>
using namespace std;
template<class T>
class myclass {
	T * p;
	int nSize;
	public:
	myclass(T * a,int n) {
		p = new T[n];
		for(int i=0;i<n;++i)
			p[i] = a[i];
		nSize = n;
	}
	~myclass() {
		delete [] p;
	}
	void Show() {
		for(int i = 0;i<nSize;++i)
			cout<<p[i];
	}
};
int main()
{
	char * szName = "TomHanks";
	//cout<<strlen(szName)<<endl;
	myclass<char>obj(szName,sizeof(szName));
	obj.Show();
	return 0;
}
