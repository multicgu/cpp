//template_queue.cpp
#include<stdio.h>
#include<iostream>
using namespace std;
class QueueEmpty {};
template<typename T> class QueueItem;
template<typename T> class Queue
{
	private:
		QueueItem<T> * head,* tail;
		int count;
	public:
		Queue():head(NULL),tail(NULL),count(0) {};
		virtual ~Queue();
		virtual void Enter(const T & item);
		virtual T Leave();
		bool IsEmpty() const {return head == NULL;}
};
template<typename T> class QueueItem
{
	friend class Queue<T>;
	private:
		T _item;
		QueueItem<T> * next;
	public:
		QueueItem(const T & item):_item(item),next(NULL) {} 
};
template<typename T> Queue<T>::~Queue()
{
	while(!IsEmpty()) Leave();
}
template<typename T> void Queue<T>::Enter(const T & item)
{
	QueueItem<T> * p = new QueueItem<T>(item);
	if(IsEmpty()) {head = tail = p; count++;}
	else {
	tail->next = p;
	tail = p;
	count++;
	}
}
template<typename T> T Queue<T>::Leave()
{
	if(IsEmpty()) throw QueueEmpty();
	QueueItem<T> * p = head;
	T t = p->_item;
	head = head->next;
	delete p;
	count--;
	return t;	
}
