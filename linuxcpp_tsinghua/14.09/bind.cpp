#include <iostream>
#include <thread>
class Worker  {
	public:
		Worker( int a = 0, int b = 0 ) : _a(a), _b(b)  {  }
	void  ThreadFunc()  { 
		std::cout << "The thread id is " << std::this_thread::get_id() << std::endl;
		std::cout << _a << "+" << _b << "=" << _a + _b << std::endl;	
	}
	private:  int  _a, _b;
};

int  main()
{
	Worker  worker( 10, 20 );
	std::thread  t( std::bind( &Worker::ThreadFunc, &worker ) );
	t.join();
	return 0;
}

