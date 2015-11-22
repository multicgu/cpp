#include <iostream>
#include<cstdio>
using namespace std;
 
class Shape
{
	protected:
		int w, h;
	public:
		Shape(int w, int h):w(w), h(h){}
		//Shape(int w,int h):(this->w)(w),(this->h)(h) {}
};
class Rectangle:public Shape {
	public:
		Rectangle(int W,int H):Shape(W,H) {}
		double area() {return w*h;}
};
class Triangle:public Shape {
	public:
		Triangle(int W,int H):Shape(W,H) {}
		double area() {return (double)w*h/2;}

};
 
int main()
{
    int w, h;
    cin >> w >> h;
    Rectangle a(w, h);
    cout << a.area() << endl;
    cin >> w >> h;
    Triangle b(w, h);
    //cout << b.area() << endl;
	printf("%.1lf\n",b.area());
    return 0;
}
