#include<vector>
using namespace std;

class employee
{
	public:
		virtual void PaySalary()=0;
		virtual void PayBonus()=0;
};
class programmer:public employee
{
	public:
		virtual void PaySalary(){cout<<"programmer paysalary"<<endl;}
		virtual void PayBonus(){cout<<"Programmer Paybonus"<<endl;}
};
class manager:public employee
{
	public:
		virtual void PaySalary(){cout<<"Manager paysalary"<<endl;}
		virtual void PayBonus(){cout<<"Manager paybonus"<<endl;}
};
class company
{
	private:
		vector<employee *> _employee;
	public:
		virtual void PayRoll(employee * e);
		virtual void PayRoll(employee & e);
};
void company::PayRoll(employee * e)
{
	programmer * p = dynamic_cast<programmer *>(e);
	if(p) {
		p->PaySalary();
		p->PayBonus();
	}
	else e->PaySalary();
}
void company::PayRoll(employee & e)
{
	try {
		programmer & p = dynamic_cast<programmer &>(e);
		p.PaySalary();
		p.PayBonus();
	}
	catch(bad_cast) { e.PaySalary(); }
}
