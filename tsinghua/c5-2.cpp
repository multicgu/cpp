#include <iostream>
#include<stdio.h>
using namespace std;
  
class Mouse{
	public:
		static int num;
		Mouse() { 
				++num;
		}
		Mouse(Mouse & m) { ++num; }
		~Mouse() { --num; };
};
int Mouse::num = 0;  
void fn(Mouse m);
  
int main()
{
    Mouse::num = 0;
    Mouse a;
	printf("%p\n",&a);
    cout << Mouse::num << endl;
    Mouse b(a);
	printf("%p\n",&b);
    cout << Mouse::num << endl;
    for (int i = 0; i < 10; ++i)
    {
        Mouse x;
        cout << Mouse::num << endl;
		printf("%p\n",&x);
    }
    fn(a);
    cout << Mouse::num << endl;
    return 0;
}
  
void fn(Mouse m)
{
    cout << Mouse::num << endl;
	printf("%p\n",&m);
    Mouse n(m);
	printf("%p\n",&n);
    cout << Mouse::num << endl;
} 

