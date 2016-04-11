#include<stdio.h>
#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
#include<tuple>
using namespace std;
std::mutex x;
template<typename T>
class Worker
{
	public:
		explicit Worker(int no, T a=0, T b=0):_no(no),_a(a),_b(b) {}
		void threadfun(T * r)
		{
			x.lock();
			*r = _a + _b;
			x.unlock();
		}
	private:
		int _no; //thread number;
		T _a, _b;
};
int main()
{
	std::vector< std::tuple<Worker<int>*, int, std::thread *> > v(8);
	for(int i = 0; i < 8; i++)
		v[i] = std::make_tuple(new Worker<int>(i, i+1, i+2), 0, nullptr);
	for(int i = 0; i<8; i++)
		cout << std::get<1>(v[i]) << endl;
	for(int i = 0; i < 8; i++) {
		cout << "In bind loop\n";
		//auto f = std::bind(&Worker<int>::threadfun, std::get<0>(v[i]), std::placeholders::_1);
        auto f = std::bind( &Worker<int>::threadfun,std::get<0>( v[i] ), std::placeholders::_1 );

		get<2>(v[i]) = new thread(f, &get<1>(v[i]));
	}
	printf("before delete\n");
	for(int i = 0; i < 8; i++) {
		get<2>(v[i])->join();
		delete get<0>(v[i]), get<0>(v[i]) = nullptr;
		delete get<2>(v[i]), get<2>(v[i]) = nullptr;
	}
	cout << "before show" << endl;
	for(int i = 0; i<8; i++)
		cout << get<1>(v[i]) << endl;
	return 0;
}
