#include<iostream>
#include<stdio.h>
using namespace std;
template <class T,int MAX = 1000>
class Stack {
	private:
		T list[MAX+1];
		int top;
	public:
		Stack() {
			top = 0;
		}
		void push(const T & item) {
			list[top] = item;
			top++;
		}
		T pop() {
			if(top>0) top--;
			else cout<< "no element" <<endl;
		}
		const T & peek() const {
			return list[top];
		}
		bool isEmpty() const {
			return top==0;
		}
};

/*template <class T,int MAX=1000>
Stack<T>::Stack() {
	top = 0;
	MAX = 1000;
	list = new T[MAX+1];
}
template <class T,int MAX=1000>
void Stack<T>::push(const T & item) {
	list[top] = item;
	top++;
}
template <class T,int MAX=1000>
T Stack<T,MAX=1000>::pop() {
	if(top>0) top--;
	else cont<< "no element" <<endl;
}
template <class T,int MAX=1000>
const T Stack<T,MAX=1000>::peek() const {
	return list[top];
}
template <class T,int MAX=1000>
bool Stack<T,MAX=1000>::isEmpty() const {
	return top==0;
}*/
void check(char * t,Stack<char> & store) {
	for(int i=0;t[i]!='\0';i++) {
		if(t[i] == '(') store.push(t[i]);
		else if((t[i] == ')') && (store.isEmpty()==false)) 
			store.pop();
		else if((t[i] == ')') && (store.isEmpty()==true)) {
			cout << "No" << endl;
			return;
		}
	}
	if(store.isEmpty() == false) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}
int main() {
	char a[1000],b[1000];
	gets(a);
	gets(b);
	Stack<char> storeA;
	Stack<char> storeB;
	check(a,storeA);
	check(b,storeB);
	return 0;
}
