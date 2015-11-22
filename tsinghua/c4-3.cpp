#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
class Equation{
	private:
		int _a, _b, _c;
	public:
		Equation(int a,int b,int c):_a(a),_b(b),_c(c) {}
		void solve() {
			float a,b,c;
			a=_a; b=_b; c=_c;  //change int to float;
			int result; // store the different situation;
			float m,n; // store answer;
			float delta=(b*b-4*a*c); 
			if(_a==0){ // a == 0;
				if(_b==0 && _c==0) result=5;
				if(_b==0 && _c!=0) result=4;
				if(_b!=0) result=6;
			}
			else {  // a != 0;
				if(int(delta)==0) result=2;
				if((delta)>0) result=1;
				if((delta)<0) result=3;
			}
			m=(float(-b+sqrt(delta))/(2*a)); // answer 1;
			n=(float(-b-sqrt(delta))/(2*a)); // answer 2;
			switch (result)
			{
				case 1: cout<<1<<endl;
						printf("%.2f %.2f\n",n,m);
						/*if(m>n) printf("%.2f %.2f\n",n,m);
						else printf("%.2f %.2f\n",m,n); */
						break;
				case 2: cout<<2<<endl;
						printf("%.2f\n",m); break;
				case 3: cout<<3<<endl; break;
				case 4: cout<<4<<endl; break;
				case 5: cout<<5<<endl; break;
				case 6: cout<<6<<endl;
						if(c==0) printf("%.2f\n",0);
						else printf("%.2f\n",(-c)/b);
						break;
			}
		}
};
int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	Equation tmp(a,b,c);
	tmp.solve();
	return 0;
}
