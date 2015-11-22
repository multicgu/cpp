#include<iostream>
using namespace std;
int & Inc(int & x,int & y);
int main() 
{
	int a = 10,b = 20,c;
	Inc(a,b);
	c = Inc(a,b)++;
	cout << c << endl;
	cout << a << endl;
	return 0;
}
int & Inc(int & x,int & y)
{
	x += y; return x;
}
