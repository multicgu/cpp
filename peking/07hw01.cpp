#include<iostream>
using namespace std;
template <class T,int a,int b,int c> class CArrary1D {
	public:
		T ar[a][b][c];
		//int & CArrary1D<int a,int b,int c>::operator[](int i){
		T & operator[](int i){
			return ar[i];
		}
};
template <class T>
class CArrary3D:public Carrary1D <T,a,b,c> {
//class CArrary3D {
	public:
		int i,j,k;
		CArrary3D(int a,int b,int c):i(a),j(b),k(c) {
			Carrary1D<T,i,j,k> a;
		}
};
int main()
{
	CArrary3D<int> a(3,4,5);
	int No = 0;
	for(int i = 0;i<3;++i)
		for(int j=0;j<4;++j)
			for(int k=0;k<5;++k)
				a[i][j][k] = No++;
	for(int i=0;i<3;++i)
		for(int j=0;j<4;++j)
			for(int k=0;k<5;++k)
				cout<<a[i][j][k]<<"k";

	return 0;
}
