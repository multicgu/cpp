#include<iostream>
using namespace std;
class point {
	public:
		void initpoint(float x, float y) {
			this->x = x;
			this->y = y;
		}
		void move(float offx,float offy) {
			x += offx;
			y += offy;
		}
		float getX() const  {return x;}
		float getY() const  {return y;}
	private:
		float x,y;
};
//class rectangle: public point {
class rectangle: private point {
	public:
		void initrectangle(float x,float y,float w,float h) {
			initpoint(x,y);
			this->w = w;
			this->h = h;
		}
		void move(float offx,float offy) {
			point::move(offx,offy);
		};
		float getX() const {return point::getX();}
		float getY() const {return point::getY();}
		float getW() const {return w;}
		float getH() const {return h;}
	private:
		float w,h;
};
int main() {
	rectangle rect;
	rect.initrectangle(2,3,20,10);
	rect.move(3,2);
	cout << "The data of rect(x,y,w,h)" << endl;
	cout << rect.getX() << endl;
	cout << rect.getY() << endl;
	cout << rect.getW() << endl;
	cout << rect.getH() << endl;
	return 0;
}
