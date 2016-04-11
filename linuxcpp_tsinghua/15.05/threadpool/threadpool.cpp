//threadpool.cpp
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<mutex>
#include<thread>
#include<string.h>
#include<condition_variable>
#include "threadpool.h"
using namespace std;

template<class TASK>
int ThreadPool<TASK>::Create()
{
	for( int i = 0; i < thread_num; i++ )
		threads.push_back( thread( &ThreadPool<TASK>::ThreadFun ) );
	return 0;
}

template<class TASK>
ThreadPool<TASK>::ThreadPool( int ThN ):thread_num(ThN)
{
	shutdown = false;
	cout << thread_num  << " numbers threads will be create." << endl;
	Create();
}

template<class TASK>
int ThreadPool<TASK>::GetTaskNum()
{
	return TaskList.size();
}

template<class TASK>
int ThreadPool<TASK>::PushTask( TASK * task )
{
	unique_lock<mutex> locker( _x );
	TaskList.push_back( task );
	_x.unlock();
	_cond.notify_one();
	return 0;
}

template<class TASK>
void * ThreadPool<TASK>::ThreadFun()
{
	thread::id tid = std::this_thread::get_id();
	while(1) {
		unique_lock<mutex> locker( _x );
		while( TaskList.size() == 0 && !shutdown ) {
			_cond.wait( locker );
		}
		if( shutdown ) {
			locker.unlock( );
			printf("Thread %lu will exit.\n",tid);
			return (void *)0;
		}
		typename vector<TASK>::iterator iter = TaskList.begin();
		if( iter != TaskList .end() ) {
			TASK task = *iter;
			TaskList.erase( iter );
			locker.unlock( );
			task.Run();
			printf("%lu idle.\n",tid);
		}
	}
	return (void *)0;
}

template<class TASK>
int ThreadPool<TASK>::StopAll()
{
	if( shutdown ) return -1;
	cout << "All thread will stop." << endl;
	shutdown = true;
	_cond.notify_all();
	for( int i = 0; i < thread_num; i++ ) 
		threads[i].join();

	threads.clear();
	cout << "The Threadpool is stop." << endl;
	return 0;
}

Task::Task() {}

Task::Task( char * TName ) 
{
	TaskName = TName;
	TaskData = NULL;
}

void Task::SetData( void * TData )
{
	TaskData = TData;
}

void Task::showdata()
{
	cout << TaskData << endl;
}
