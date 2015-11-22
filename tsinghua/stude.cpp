#include<iostream>
#include<stdio.h>
using namespace std;
class student
{
	private:
		char name[20];
		int age,num;
		float fir,sec,thd,fot;
	public:
		void getall(void);
		void printall(void);
};
void student::getall(void)
{
	int a=0;
	char ch;
	while((name[a]=getchar())!=',')
		a++;
	name[a]='\0';
	cin>>age>>ch>>num>>ch>>fir>>ch>>sec>>ch>>thd>>ch>>fot;
}
void student::printall(void)
{
	int avg=(fir+sec+thd+fot)/4;
	char ch=',';
	printf("%s",name);
	cout<<ch<<age<<ch<<num<<ch<<avg<<endl;
}
int main()
{
	student stu;
	stu.getall();
	stu.printall();
	return 0;
}
