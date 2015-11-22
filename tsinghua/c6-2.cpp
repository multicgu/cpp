#include<iostream>
#include<string>
using namespace std;
void calpalind(string & s);
bool palind(string & temp);
int main() {
	string s;
	getline(cin,s);
	calpalind(s);
	return 0;
}
void calpalind(string & s) {
	int sum = 1,n=1;
	int i,j;
	string temp;
	string * s1 = new string[1];
	*s1 = s[0];
	for(i=1;i<s.length();i++) {
		string * tstr = new string[2*n+1];
		for(int h=0;h<n;h++) tstr[h]=s1[h];
		s1 = tstr;
		for(j=0;j<n;j++) { 
			temp = s1[j]+s[i];
			if(palind(temp)) {sum++;}
			s1[n+j] = temp;
		}
		n=n+j+1;
		s1[n-1] = s[i];
		sum++;
	}
	cout<<sum<<endl;
}
bool palind(string & temp) {
	string comp;
	int n,i;
	for(i=temp.length()-1;i>=0;i--) {
		comp=comp+temp[i];
	}
	if(temp == comp) return true;
	else return false;
}
