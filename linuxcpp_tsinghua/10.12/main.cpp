#include<stdio.h>
#include<iostream>
#include<fstream>
//#include "/cpp/linuxcpp_tsinghua/8.12/point.h"
using namespace std;
class Point
{
	protected:
		int _x;
	public:
		Point(int x):_x(x) {}

};	
class Point2D:public Point
{
	protected:
		int _y;
	public:
		Point2D(int x,int y):Point(x),_y(y) {}
		Point2D():Point(0),_y(0) {}
		friend ostream & operator<<(ostream & os,Point2D & p2d);
		friend istream & operator>>(istream & is,Point2D & p2d);
};
class Point3D:public Point2D
{
	private:
		int _z;
	public:
		Point3D(int x,int y,int z):Point2D(x,y),_z(z) {}
		Point3D():Point2D(0,0),_z(0) {}
		friend ostream & operator<<(ostream & os,Point3D & p3d);
		friend istream & operator>>(istream & is,Point3D & p3d);
};
ostream & operator<<(ostream & os,Point2D & p2d)
{
	os << "(" << p2d._x << "," << p2d._y << ") " ;
	return os;
}
ostream & operator<<(ostream & os,Point3D & p3d)
{
	os << "(" << p3d._x <<","<<p3d._y <<"," << p3d._z << ") " ;
	return os;
}
istream & operator>>(istream & is,Point2D & p2d)
{
	char c; int a[2]={0,0}; int i=0;
	c = is.get();
	while( c != ')' )
	{
		if(isdigit(c)) { a[i] = a[i]*10+c-48; }
		if(c == ',') {i++;}
		if(c == ')') break;
		c = is.get();
	}
	p2d._x = a[0];
	p2d._y = a[1];
	return is;
}
istream & operator>>(istream & is,Point3D & p3d)
{
	char c; int a[3]={0,0,0}; int i=0;
	c = is.get();
	while( c != ')' )
	{
		if(isdigit(c)) { a[i] = a[i]*10+c-48; }
		if(c == ',') {i++;}
		if(c == ')') break;
		c = is.get();
	}
	p3d._x = a[0];
	p3d._y = a[1];
	p3d._z = a[2];
	return is;
}
int main() 
{
	ofstream ofs("/root/cpp/linuxcpp_tsinghua/10.12/test");
	//ofs.open("/cpp/linuxcpp_tsinghua/10.12/test");
	Point2D p2d(1,2);
	Point3D p3d(3,4,5);
	ofs << p2d;
	ofs << p3d;
	ofs.close();

	ifstream ifs("/root/cpp/linuxcpp_tsinghua/10.12/test");
	Point2D po2d;
	Point3D po3d;
	ifs >> po2d;
	ifs >> po3d;
	cout << po2d << po3d << endl;
	ifs.close();
	return 0;
}
