#include<stdio.h>
#include<iterator>
#include<iostream>
#include<vector>
#include<algorithm>
#include "/root/cpp/linuxcpp_tsinghua/8.9/random.h"
using namespace std;
const int size = 10;
void display(vector<int> & v,char *);
int main()
{
	int key = 8;
	//iterator
	int a[size];
	for(int i=0;i<size;i++) a[i]=i+3;
	int * p = find(a,a+size,key);
	if(p == a+size) cout << "not found " << key << endl;
	else cout<<"found the "<< key<<" "<<*p<< endl;

	//vector_iterator
	vector<int> v(size);
	for(int i=0;i<size;i++) v[i]=i;
	vector<int>::iterator it,head=v.begin(),tail=v.end();
	it = find(head,tail,key);
	if(it != tail) cout << "found the "<<key<<" "<<*it<<endl;
	else cout << "not found" << key << endl;

	//ostream_iterator
	vector<int> vr(size);
	for(int i=0;i<size;i++) vr[i]=GenerateRandomInteger(10,99);
	display(vr,"origin");
	head=vr.begin(),tail=vr.end();
	sort(head,tail);
	display(vr,"After sort");
	reverse(head,tail);
	display(vr,"After reverse");

	//istream_iterator
	vector<int> vi(size);
	vector<int>::iterator vihead = vi.begin();
	cout<<"Pls enter 10 integers separated with space."<<endl;
	istream_iterator<int> iit(cin),iitend;
	copy(iit,iitend,vihead);
	for(vihead=vi.begin();vihead!=vi.end();vihead++) 
		cout << *vihead << " ";
	cout << endl;

	return 0;
}
void display(vector<int> & v,char * s)
{
	cout << s << endl;
	vector<int>::iterator it,head=v.begin(),tail=v.end();
	ostream_iterator<int> oit(cout,";");
	copy(head,tail,oit);
	cout << endl;
}
