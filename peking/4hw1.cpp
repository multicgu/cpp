#include<iostream>
using namespace std;
class b {
	public:
	b() {cout<<"bin"<<endl;}
	~b() {cout<<"bend"<<endl;}
};
class c:public b {
	public:
		c() {cout<<"cin"<<endl;}
		~c() {cout<<"cend"<<endl;}
};
int main()
{
	c *pc = new c;
	delete pc;
	return 0;
}
