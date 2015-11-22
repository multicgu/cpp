#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

class Shape{
public:
    Shape() {}
    virtual ~Shape() {}
};

class Triangle: public Shape{
public:
    Triangle() {}
    ~Triangle() {}
};

class Rectangle: public Shape {
public:
    Rectangle() {}
    ~Rectangle() {}
};

/*用dynamic_cast类型转换操作符完成该函数*/
int getVertexCount(Shape * b){
	Triangle *t = dynamic_cast<Triangle*>(b);
	Rectangle *r = dynamic_cast<Rectangle*>(b);
	if(t != NULL)
   		return 3;
	else if(r != NULL)
		return 4;
	else return 0;
}

int main() {
    Shape s;
    cout << getVertexCount(&s) << endl;
    Triangle t;
    cout << getVertexCount(&t) << endl;
    Rectangle r;
    cout << getVertexCount(&r) << endl;
}
