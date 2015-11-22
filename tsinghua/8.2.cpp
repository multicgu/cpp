#include<iostream>
using namespace std;
class cl {
	private:
		int hours,minutes,seconds;
	public:
		cl(int hours=23,int minutes=59,int seconds=59) {
			if(0<=hours && hours<24 && 0<=minutes && minutes<60 && 0<=seconds && seconds<60)  {
				this->hours = hours;
				this->minutes = minutes;
				this->seconds = seconds;
			} 
			else cout<< "error time" << endl;
		}
		cl operator ++ () {
			seconds++;
			if(seconds>=60) {
				minutes++;
				seconds-=60;
				if(minutes>=60) {
					hours=(++hours)%24;
					minutes-=60;
				}
			}
			return *this;
		}
		cl operator ++ (int) {
			cl temp = *this;
			++(*this);
			return temp;
		}
		void showtime() {
			cout<<hours<<":"<<minutes<<":"<<seconds<<endl;
		}
};
int main() {
	cl my;
	cout << "First time output:";
	my.showtime();
	(++my).showtime();
	(my++).showtime();
	my.showtime();

	return 0;
}
