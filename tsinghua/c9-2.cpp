#include<iostream>
#include<cstdlib>
using namespace std;
struct student {
	int id;
	float gpa;
};
template <class T>
class store {
	private:
		T item;
		bool havevalue;
	public:
		store();
		T getelement();
		void putelement(T elem);
};
template <class T>
store<T>::store():havevalue(false) {}
template <class T>
T store<T>::getelement() {
	if(!havevalue) {
		cout<<"No item present!" << endl;
		exit(1);
	}
	return item;
}
template <class T>
void store<T>::putelement(T elem) {
	item = elem;
	havevalue = true;
}
int main() {
	store<int> s1,s2;
	s1.putelement(3);
	s2.putelement(-7);
	cout << s1.getelement() << ' ' << s2.getelement() << endl;
	student g= {1000,3};
	store<student> s3;
	s3.putelement(g);
	cout << "id is"<<s3.getelement().id<<" gpa = " << s3.getelement().gpa<< endl;

	store<double> d;
	cout << d.getelement() << endl;

	return 0;
}
