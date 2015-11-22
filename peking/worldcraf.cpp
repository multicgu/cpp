#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class sm {
	public:
		int iceman,lion,wolf,ninja,dragon;
		void getval(){
			cin>>dragon>>ninja>>iceman>>lion>>wolf;
		}
		int putval(char *name)
		{
			switch (name[0])
			{
				case 'i': return iceman;break;
				case 'l': return lion; break;
				case 'w': return wolf; break;
				case 'n': return ninja; break;
				case 'd': return dragon; break;
				default: cout<<"wrong input"<<endl;
			}
		}
};
class red {
	public:
		char soldiers[5][10];
		int media;
		int a,b,c,d,e;
		sm r;
		red(int m) {
			a=b=c=d=e=0;
			strcpy(soldiers[0],"iceman");
			strcpy(soldiers[1],"lion");
			strcpy(soldiers[2],"wolf");
			strcpy(soldiers[3],"ninja");
			strcpy(soldiers[4],"dragon");
			media=m;
		}
		int calsonu(int n)
		{
			n=n%5;
			switch (n)
			{
				case 0:a++; return a;break;
				case 1:b++; return b;break;
				case 2:c++; return c;break;
				case 3:d++; return d;break;
				case 4:e++; return e;break;
			}
		}
		void mediasub(int n) {media-=n;}
		void useit(int time,int n,sm s)
		{
			int i=n%5;
				if(media<0)
					printf("%03d red headquarter stops making warriors\n",time);
				else
				printf("%03d red %s %d born with strength %d,%d %s in red headquarter\n",time,soldiers[i],i+1,s.putval(soldiers[i]),calsonu(i),soldiers[i]);
		}
};
class blue {
	public:
		char soldiers[5][10];
		int media;
		int a,b,c,d,e;
		blue(int m){
			a=b=c=d=e=0;
			strcpy(soldiers[0],"lion");
			strcpy(soldiers[1],"dragon");
			strcpy(soldiers[2],"ninja");
			strcpy(soldiers[3],"iceman");
			strcpy(soldiers[4],"wolf");
			media=m;
		}
		int calsonu(int n)
		{
			n=n%5;
			switch (n)
			{
				case 0:a++; return a;break;
				case 1:b++; return b;break;
				case 2:c++; return c;break;
				case 3:d++; return d;break;
				case 4:e++; return e;break;
			}
		}
		void mediasub(int n) {media-=n;}
		void useit(int time,int n,sm s)
		{
			int i=n%5;
				if(media<0)
					printf("%03d blue headquarter stops making warriors\n",time);
				else
				printf("%03d blue %s %d born with strength %d,%d %s in blue headquarter\n",time,soldiers[i],i+1,s.putval(soldiers[i]),calsonu(i),soldiers[i]);
		}
};
int main()
{
	int time=0,casenum,medtot;
	cin>>casenum>>medtot;
	sm solrm;
	solrm.getval();
	red redteam(medtot);
	blue blueteam(medtot);
	cout<<"Case:"<<casenum<<endl;
	int n=0,i=0,r=0,b=0;
	while(redteam.media>=0 || blueteam.media>=0)
	{
		if(redteam.media>=0)
		{
			redteam.media-=solrm.putval(redteam.soldiers[r%5]);
			if(redteam.media<0)
			{
				int a=0;
				for(a=0;a<5 && redteam.media<0;a++)
				{
					redteam.media+=solrm.putval(redteam.soldiers[r%5]);
					redteam.media-=solrm.putval(redteam.soldiers[(++r)%5]);
				}
					redteam.useit(time,r,solrm);
			}
			else
				redteam.useit(time,r,solrm);
		}
		if(blueteam.media>=0)
		{
			blueteam.media-=solrm.putval(blueteam.soldiers[b%5]);
			if(blueteam.media<0)
			{
				int a=0;
				for(a=0;a<5 && blueteam.media<0;a++)
				{
					blueteam.media+=solrm.putval(blueteam.soldiers[b%5]);
					blueteam.media-=solrm.putval(blueteam.soldiers[(++b)%5]);
				}
					blueteam.useit(time,b,solrm);
			}
			else
				blueteam.useit(time,b,solrm);
		}
		n++;time++;b++;r++;
	}
	return 0;
}
