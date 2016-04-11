#include<stdio.h>
#include<iostream>
using namespace std;
class constcasttest
{
	private:
		int _num;
	public:
		constcasttest(int num):_num(num) {}
		void print() const;
};
void constcasttest::print() const
{
	const_cast<constcasttest*>(this)->_num--;
	cout << _num << endl;
}
int main()
{
	constcasttest c(4);
	c.print();
	return 0;
}
