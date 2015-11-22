#include<iostream>
using namespace std;
class Integer{
	private:
		int _num;
		int getLength() {}
	public:
		Integer(int num):_num(num) {}
		int retnum() { return _num; }
		int inversed() {
			int a = _num;
			int tmp,inv=0;
			while(a>0)
			{
				tmp = a%10;
				inv = inv*10 + tmp;
				a = a/10;
			}
			return inv;
		}
};
int main()
{
	int n;
	cin >> n;
	Integer integer(n);
	cout << integer.inversed() << endl;

}
