#include<iostream>
using namespace std;
class base {
	public:
	int val;
	base() {cout<<"bon"<<endl;}
	~base() {cout<<"bend"<<endl;}
};
class base1:virtual public base {};
class base2:virtual public base {};
class derived:public base1,public base2 {};
int main() {derived d;return 0;}
