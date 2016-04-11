#include<iostream>
#include<thread>
using namespace std;
class WORK
{
	private:
		int _a,_b;
	public:
		WORK(int a,int b):_a(a),_b(b) {}
		void threadID()
		{
			cout << "the thread id is " << this_thread::get_id() << endl;
			cout << _a << "+" << _b << "=" << _a + _b << endl;
		}
};
int main()
{
	WORK work(10,20);
	std::thread t(std::bind(&WORK::threadID,&work));
	t.join();
	return 0;
}
