//threadpool_test.cpp
#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
#include<thread>
#include<unistd.h>
#include "threadp.cpp"
//#include "threadpool.h"
//#include "threadpool.cpp"
using namespace std;

class TaskWork : public Task
{
	public:
		TaskWork():Task() {}
		TaskWork(char * TName):Task(TName) {}
		virtual int Run()
		{
			printf("%s\n",(char *)this->TaskData);
			sleep(5);
			return 0;
		}
		/*~Task()
		{
			delete TaskName;
			delete TaskData;
			TaskName = NULL;
			TaskData = NULL;
		}*/
};

int main()
{
	TaskWork task;
	char obj[] = "abc";
	task.SetData( obj );
	task.showdata();
	//ThreadPool thread_pool(10); // For no template version
	ThreadPool<TaskWork> thread_pool(10);   // For template version

	for( int i = 0; i < 20; i++ ) 
		thread_pool.PushTask( &task );

	while( 1 ) {
		if( thread_pool.GetTaskNum() == 0 && thread_pool.StopAll() == -1 ) {
			cout << "exit the main.\n";
			exit(0);
		}
	}
	sleep(2);

	return 0;
}
