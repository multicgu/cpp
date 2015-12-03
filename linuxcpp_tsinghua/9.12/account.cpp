#include<stdio.h>
#include<iostream>
using namespace std;
class Accounts
{
	private:
		double _balance;
	public:
		Accounts(double b):_balance(b) {}
		double GetBalance() const;
		virtual void PrintBalance() const;
};
class CheckingAccounts:public Accounts
{
	public:
		CheckingAccounts(double b):Accounts(b) {}
		void PrintBalance() const;
};
class SavingAccounts:public Accounts
{
	public:
		SavingAccounts(double b):Accounts(b) {}
		void PrintBalance() const;
};
inline double Accounts::GetBalance() const {return _balance;}
inline void Accounts::PrintBalance() const {cout << "error" << endl;}
inline void CheckingAccounts::PrintBalance() const 
{
	cout << "CheckingAccounts balance is " << GetBalance()  << endl;
}
inline void SavingAccounts::PrintBalance() const
{
	cout << "SavingAccounts balance is " << GetBalance()  << endl;
}

int main() 
{
	CheckingAccounts * check = new CheckingAccounts((double)1000);
	SavingAccounts * saving = new SavingAccounts((double)500);
	Accounts * account = check;
	account->PrintBalance();

	account = saving;
	account->PrintBalance();

	delete check;
	delete saving;

	return 0;
}
