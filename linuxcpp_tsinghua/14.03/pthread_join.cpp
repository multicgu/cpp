#include<pthread.h>
#include<iostream>
#include<stdio.h>
using namespace std;
class printinfo
{
	public:
		printinfo(int c,int n):_c(c),_n(n) {};
		void show()
		{
			for(int i=0;i<_n;i++) cerr << _c;
		}
	private:
		char _c;
		int _n;
};
void * print(void * pf)
{
	printinfo * p = reinterpret_cast<printinfo *>(pf);
	if(p) p->show();
	return NULL;
}
int main()
{
	pthread_t tie1,tie2;
	printinfo *a=new printinfo('a',100);
	printinfo *z=new printinfo('z',100);
	pthread_create(&tie1,NULL,&print,reinterpret_cast<void *>(a));
	pthread_create(&tie1,NULL,&print,reinterpret_cast<void *>(z));

	pthread_join(tie1,NULL);
	pthread_join(tie1,NULL);
	return 0;
}
