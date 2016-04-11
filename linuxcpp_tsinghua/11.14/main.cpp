#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include"template_queue.h"
using namespace std;
int main()
{
	Queue<int> queue;
	for(int i = 0; i < 10; i++)
		queue.Enter(i);
	for(int i=0;i<10;i++)
		cout << queue.Leave() << endl;
	
	int * n[2];
	n[0] = new int(10); n[1] = new int(20);
	Queue<int *>q;
	q.Enter(n[0]);
	q.Enter(n[1]);
	cout << *q.Leave() << *q.Leave() << endl;

	return 0;
}
