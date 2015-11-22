#include<iostream>
#include<vector>
using namespace std;
int maxsubseq(vector<int> & arr);
int main(void) {
	int n,i;
	cin >> n;
	vector<int> arr(n);
	for(i=0;i<n;i++) 
		cin >> arr[i];
	cout << maxsubseq(arr) << endl;
	return 0;
}
int maxsubseq(vector<int> & arr) {
	int i, max = 0, sum = 0;
	for(i=0;i<arr.size();i++) {
		sum += arr[i];
		if(sum < 0) sum = 0;
		if(sum > max)
			max = sum;
		//cout << "sum" << sum << " max" << max << endl;
	}
	return max;
}
