#include<iostream>
#include<vector>
using namespace std;
double average(vector<double> &arr) {
	double sum=0;
	//for(auto e:arr) 
	for(int i=0;i<arr.size();i++)
		sum += arr[i];
	return sum/arr.size();
}
int main() {
	int n,i;
	cout<<"n = ";
	cin>>n;
	vector<double> arr(n);
	for(i=0;i<n;i++)
		cin >> arr[i];
	cout<< average(arr) << endl;
	return 0;
}
