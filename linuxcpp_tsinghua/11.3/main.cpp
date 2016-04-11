#include<stdio.h>
#include<iostream>
#include "stack.h"
#include "stack.cpp"
using namespace std;
int main()
{
	JuStack stack(17);
	try {
		for(int i=0;i<32;i++)
			stack.push(i);
	}
	catch(const StackFull & e) {
		cerr << "Error:Stack Full! value="<< e.getvalue() << endl;
	}
	try {
		for(int i=0;i<18;i++) cout << stack.pop() << " ";
	}
	catch(const StackEmpty & e) {
		cerr << "Error:stack Empty!" << endl;
	}
	return 0;
}
