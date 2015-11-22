#include<iostream>
using namespace std;
class student
{
	private:
		char name[20];
		int age;
		int number;
		float avg_fir,avg_sec,avg_thd,avg_for;
	public:
		student(char * Name,int Age,int Num);
		void getname(void);
		void getage(void);
		void getnum(void);
		void getavgfir(void);
		void getavgsec(void);
		void getavgthd(void);
		void getavgfor(void);
		void printall(void);
};
student::student(int Age,int Num)
{
	age=Age;
	number=Num;
	avg_fir=avg_sec=avg_thd=avg_for=0;
}
void student:: printall(void)
{
	cout>>name>>','>>age>>','>>number>>','>>avg_fir>>','>>avg_sec>>','>>avg_thd>>','>>avg_for;
}
void student:: getname(void)
{
	char Name[20];
	cin>>Name;
	*name=*Name;
}
void student:: getage(void)
{
	int Age;
	cin>>Age;
	age=Age;
}
void student:: getnum(void)
{
	int Num;
	cin>>Num;
	number=Num;
}
void student:: getavgfir(void)
{
	double fir;
	cin>>fir;
	avg_fir=fir;
}
void student:: getavgsec(void)
{
	double sec;
	cin>>sec;
	avg_sec=sec;
}
void student:: getavgthd(void)
{
	double thd;
	cin>>thd;
	avg_thd=thd;
}
void student:: getavgfor(void)
{
	double fort;
	cin>>fort;
	avg_for=fort;
}
int main()
{
	char ch;
	student stu(0,0);
	stu.getname();
	cin>>',';stu.getage();cin>>',';stu.getnum();cin>>',';stu.getavgfir();cin>>',';
	stu.getavgsec();cin>>',';stu.getavgthd();cin>>',';stu.getavgfor();
	stu.printall();
	//cin>>stu.getname()>>ch>>stu.getage>>ch>>stu.getnum>>ch>>stu.getavgfir>>ch>>stu.getavgsec>>ch>>stu.getavgthd>>ch>>stu.getavgfor;
	//cout<<stu.name<<ch<<stu.age<<ch<<stu.number<<ch<<avg_fir<<ch<<avg_sec<<ch<<avg_thd<<ch<<avg_for;
	return 0;
}
