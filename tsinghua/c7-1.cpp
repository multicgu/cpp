#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
class Account {
	private:
		string userName;
	public:
		Account() {}
		Account(string name);
		void PrintName();
};
class CreditAccount:public Account {
	public:
		CreditAccount(string name,int credit);
		void PrintInfo();
	private:
		int credit;
};
Account::Account(string name) {
	userName = name;
}
void Account::PrintName() {
	cout << userName << endl;
}
CreditAccount::CreditAccount(string name,int credit):Account(name) {
	this->credit = credit;
}
void CreditAccount::PrintInfo() {
	PrintName();
	cout << credit << endl;
}
int main() {
	CreditAccount a("I Love CPP",10000);
	a.PrintInfo();
	return 0;
}
