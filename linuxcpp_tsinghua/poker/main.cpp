#include<iostream>
#include<stdio.h>
#include "poker.h"

enum PokerKinds{clubs,damonds,hearts,spades};
typedef struct 
{
	int Cards[13];
	int BigPoints;
}Players;

using namespace std;
int main() 
{
	Randseed();
	int a;
	int poker[52]={2}; // store a poker without big&small king;
	for(int i=0;i<52;i++){ //generate a 52 cards and get rid of repeat card
		a = Renum_in_poker();
		for(int m=0;m<i;) {
			if(SameCard(a,poker[m])) {/*printf("a=%d & poker[%d]=%d ",a,m,poker[m]);*/a = Renum_in_poker();}
			else m++;
		}
		poker[i] = a; //cout<<i<<"poker="<<poker[i]<< " ";
	}
	//for(int i=0;i<52;i++) {cout<< poker[i] << " ";}
	//cout << endl;
	//printf("%d\n",clubs);
	Players players[4]; 
	for(int i=0;i<52;) { //deal to 4 player and calculate the big point
		for(int m=0;m<13;m++) {
			for(int n=0;n<4;n++) {
				players[n].Cards[m] = poker[i++];
				players[n].BigPoints += CalBigPoint(players[n].Cards[m]);
			}
		}
	}

	return 0;
}
