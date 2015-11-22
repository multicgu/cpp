#include<iostream>
#include<stdio.h>
using namespace std;
class point {
	public:
		point(float X=0,float Y=0) {
			this->x=X;
			this->y=Y;
		}
		void move(float offx,float offy) {
			x += offx;
			y += offy;
		}
		float getx() {return x;}
		float gety() {return y;}
	private:
		float x,y;
};
//class rectangle:public point {
class rectangle:private point {
	public:
		rectangle(float x,float y,float W,float H):point(x,y) {
			this->w = W;
			this->h = H;
			move(3,2);
			cout<< getx() << "," << gety() << endl;
		}
		float geth() {return h;}
		float getw() {return w;}
	private:
		float w,h;
};
int main() {
	float x,y,w,h;
	cout << "input the x,y,w,h" << endl;
	cin >> x>>y>>w>>h;
	rectangle rect(x,y,w,h);
	//cout << "move 3,2" << endl;
	//rect.move(3,2);
	//cout << rect.getx()<<","<<rect.gety()<<","<<rect.getw()<<","
	//	<<rect.geth()<<endl;
	cout << rect.getw()<<","<<rect.geth()<<endl;

	return 0;
}
