#include<stdio.h>
#include<iostream>
#include<typeinfo>
//#include "employee.h"
#include "employee.cpp"
using namespace std;
int main() 
{
	programmer p;
	employee & e = p;
	manager * m = new manager;
	employee * pm = m;
	cout << typeid(e).name() << endl;

	company c;
	cout << "after c" << endl;
	c.PayRoll(pm);
	cout << "after c.payroll(m)" << endl;
	c.PayRoll(e);
	cout << "after c.payroll(e)" << endl;

	return 0;
}
