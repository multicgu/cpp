#include<iostream>
using namespace std;
class Integer {
	private:
		int _num;
	public:
		Integer(int num) {
			_num = num;
		}
		int gcd(Integer b) {
			int big,small,rem;
			if(_num >= b.retelm())
			{
				big = _num;
				small = b.retelm();
			}
			else
			{
				small = _num;
				big = b.retelm();
			}
			while(1)
			{
				rem=big%small;
				if(rem==0) break;
				big=small;
				small=rem;
			}
			return small;
		}
		Integer(Integer & b) {
			_num = b.retelm();
		}
		int retelm() { return _num; }
		//~Integer() { delete _num; }
};

int main() {
	int a,b;
	cin >> a >> b;
	Integer A(a);
	Integer B(b);
	cout << A.gcd(B) << endl;
	return 0;
}
