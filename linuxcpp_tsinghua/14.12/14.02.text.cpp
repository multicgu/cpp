#include <iostream>
#include <vector>
#include <tuple>
#include <thread>
#include <mutex>
std::mutex x;
//  劳工线程类模板，处理T型数据对象
template< typename T >  class Worker
{
	public:
		explicit Worker( int no, T a = 0, T b = 0 ) : _no(no), _a(a), _b(b)  {  }
		void  ThreadFunc( T * r )  {  x.lock();    *r = _a + _b;    x.unlock();  }
	private:
		int  _no;	//  线程编号，非线程ID
		T  _a, _b;	//  保存在线程中的待处理数据
};
int main()
{
//  定义能够存储8个三元组的向量v，元组首元素为指向劳工对象的指针
//  次元素保存该劳工对象计算后的结果数据，尾元素为指向劳工线程对象的指针
//  向量中的每个元素都表示一个描述线程运行的线程对象，
//  该线程对象对应的执行具体任务的劳工对象，及该劳工对象运算后的返回值
	std::vector< std::tuple<Worker<int>*, int, std::thread*> >  v( 8 );
//  构造三元组向量，三元编号顺次为0、1、2
	for( int i = 0; i < 8; i++ )
		v[i] = std::make_tuple( new Worker<int>( i, i+1, i+2 ), 0, nullptr );
//  输出处理前结果；使用std::get<n>(v[i])获取向量的第i个元组的第n个元素
//  三元编号顺次为0、1、2，因而1号元保存的将是劳工对象运算后的结果
	for( int i = 0; i < 8; i++ )
		std::cout << "No. " << i << ": result = " << std::get<1>(v[i]) << std::endl;
//  创建8个线程分别计算
	for( int i = 0; i < 8; i++ )
	{
//  将劳工类成员函数绑定为线程函数，对应劳工对象绑定为执行对象
//  将构造线程对象时传递的附加参数作为被绑定的线程函数的第一个参数
//  auto表示由编译器自动推断f的型式
		auto  f = std::bind( &Worker<int>::ThreadFunc,
		std::get<0>( v[i] ), std::placeholders::_1 );
//  动态构造线程对象，并保存到向量的第i个三元组中
//  传递三元组的1号元地址，即将该地址作为线程函数的参数
//  线程将在执行时将结果写入该地址
//  此性质由绑定函数std::bind()使用占位符std::placeholders::_1指定
//  线程对象为2号元，即三元组的最后一个元素
		std::get<2>( v[i] ) = new std::thread( f, &std::get<1>( v[i] ) );
	}
	for(int i = 0; i < 8; i++ )
	{
//  等待线程结束
		std::get<2>( v[i] )->join(); 
//  销毁劳工对象
		delete std::get<0>( v[i] ),    std::get<0>( v[i] ) = nullptr;
//  销毁线程对象
		delete std::get<2>( v[i] ),    std::get<2>( v[i] ) = nullptr;
	}
//  输出线程计算后的结果
	for( int i = 0; i < 8; i++ )
		std::cout << "No. " << i << ": result = " << std::get<1>(v[i]) << std::endl;
	    return 0;
}
