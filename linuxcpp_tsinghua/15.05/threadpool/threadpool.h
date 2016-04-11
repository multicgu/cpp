//threadpool.h
#include<stdio.h>
#include<iostream>
#include<vector>
#include<thread>
#include<stdlib.h>
#include<mutex>
#include<string.h>
#include<condition_variable>

using namespace std;

class Task
{
	protected:
		char * TaskName;
		void * TaskData;
	public:
		Task();
		Task( char * TName );
		virtual int Run() = 0;
		void SetData( void * TData );
		void showdata();
		virtual ~Task() {}
};

//template<typename Task>
template<class TASK>
class ThreadPool
{
	private:
		int thread_num;
		vector<TASK> TaskList;
		vector<thread> threads;
		bool shutdown;

		mutex _x;
		condition_variable  _cond;

	public:
		ThreadPool( int ThN = 10 );
		int GetTaskNum();
		int PushTask( TASK * task );
		int StopAll();
		int Create();

		void * ThreadFun();
};
