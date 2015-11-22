#include<iostream>
#include<string.h>
using namespace std;
class student {
	private:
		char name[20];
		int age;
		int num;
		float fir,sec,thd,fort;
	public:
		student(void);
		void getall(void);
		void printall(void);
};
student::student(void)
{
	strcpy(name,"\0");
	age=0;
	num=0;
	fir=sec=thd=fort=0;
}
void student::getall(void)
{
	char ch=',';
	cin.get(name,20,',');
	cin.get(ch);
	cin>>age;
	cin.get(ch);
	cin>>num;
	cin.get(ch);
	cin>>fir;
	cin.get(ch);
	cin>>sec;
	cin.get(ch);
	cin>>thd;
	cin.get(ch);
	cin>>fort;
}
void student::printall(void)
{
	char ch=',';
	cout<<name<<ch<<age<<ch<<num<<ch<<fir<<ch<<sec<<ch<<thd<<ch<<fort;
}
int main()
{
	student stu();
	stu.getall();
	stu.printall();
	
	return 0;
}
