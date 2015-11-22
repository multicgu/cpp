#include<iostream>
#include<stdio.h>
using namespace std;
class triangle {
	private:
		int a,b,c;
	public:
		triangle():a(0),b(0),c(0) {}
		void change(int a1,int b1,int c1){
			a=a1;b=b1;c=c1;
		}
		bool righttriangle() {
			if(a==0 || b==0 || c==0) return false;
			if(a*a==b*b+c*c || b*b==a*a+c*c || c*c==a*a+b*b)
				return true;
			else
				return false;
		}
};
void judge(triangle t) {
	if(t.righttriangle()==true)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;
}
int main() {
	int a,b,c,i;
	triangle d;
	cin>>a>>b>>c;
	d.change(a,b,c);
	judge(d);
	//triangle d[3];
	/*for(i=0;i<3;i++)
	{
		cin>>a>>b>>c;
		d[i].change(a,b,c);
	}*/
	/*for(i=0;i<3;i++)
	{
		judge(d[i]);
	}*/
	return 0;
}
