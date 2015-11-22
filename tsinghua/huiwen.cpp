#include<iostream>
#include<stdio.h>
#include<string>
//#include<bool.h>
using namespace std;
class palindrome {
	private:
		char * s;
		int size;
	public:
		palindrome(char * s=NULL,int size=0) {
			this->size=size;
			this->s = new char[size];
			for(int i=0;i<size;i++) {
				this->s[i]=s[i];
				this->s[i]=tolower(this->s[i]);
			}
		}
		~palindrome() {
			delete [] s;	
		}
		bool nullstr() {
			if(s==NULL || s[0]=='\0')
				return true;
			for(int i=0;i<size-1;i++)
				if(!isspace(s[i])) return false;
			return true;
		}
		int judge_palindrome() {
			if(nullstr()) return 1;
			int i,j;
			for(i=0,j=size-2;i<size-1 && j>=0;) {
				if(isspace(s[i]) || ispunct(s[i])) {i++; continue;}
				if(isspace(s[j]) || ispunct(s[j])) {j--; continue;}
				if(s[i]==s[j]) {i++;j--;}
				else return 0;
			}
			return 1;
		}
		void display() {cout << s << endl;}
};
int main() {
	char s[101];
	gets(s);
	int r=0;
	for(r=0;s[r]!='\0';r++);
	//cout << r<< endl;
	palindrome p(s,r+1);
	//p.display();
	cout << p.judge_palindrome() << endl;
	
	return 0;
}
