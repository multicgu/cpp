#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<stdio.h>
using namespace std;
int main() {
	map<string,int> words;
	string s;
	cin >> s;
	vector<int> n;
	while(s != "QUIT") {
		map<string,int>::iterator iter=words.find(s);
		if((iter == words.begin() && iter == words.end()) || (iter == words.end())){
			words.insert(make_pair(s,0));
			n.push_back(words[s]);
		}
		else{
			words[s]++;
			n.push_back(words[s]);
		}
		cin >> s;
	}
	int N = n.size();
	for(int i=0;i<N;i++)
		cout<<n[i]<<endl;

	return 0;
}
