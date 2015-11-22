#include<iostream>
#include<cstring>
using namespace std;
class Array2 {
	int sizea,sizeb;
	//int * ptra,*ptrb;
	int ** ptr;
	public:
		Array2(int sa=-1,int sb=-1):sizea(sa),sizeb(sb) {
			if(sa==-1 && sb==-1)
				ptr == NULL;
			else
			{
				if(ptr[sa][sb])
					cout<<ptr[sa][sb];
				else
					ptr = new int[sa][sb];
			}
		}
		Array2(Array2 & arr2) {
			if(!arr2.ptr)
			{
				ptr = NULL;
				sizea=sizeb=0;
				return;
			}
			ptr.sizea=arr2.sizea;
			ptr.sizeb=arr2.sizeb;
			ptr = new int[arr2.sizea][arr2.sizeb];	
			memcpy(ptr,arr2.pty,sizeof(int)*arr2.sizea*arr2.sizeb);
		}
		int & operator[][](int n,int m)
		{
			return ptr[n][m];
		}
		Array2 & operator=(Array2 & ar)
		{
			if(ptr==ar.ptr)
				return *this;
			if(ar.prt==NULL)
			{
				if(ptr)
					delete []ptr;
				ptr=NULL;
				sizea=sizeb=0;
				return *this;
			}
			delete []ptr;
			ptr=new int[ar.sizea][ar.sizeb];
			memcpy(ptr,ar.ptr,sizeof(int)*sizea*sizeb);
			return *this;
		}
};

int main()
{
	Array2 a(3,4);
	int i,j;
	for(i=0;i<3;++i)
		for(j=0;j<4;j++)
			a[i][j]=i*4+j;
	for(i=0;i<3;++i)
	{
		for(j=0;j<4;j++)
			cout<<a(i,j)<<",";
		cout<< endl;
	}
	cout<<"next"<<endl;
	Array b; b = a;
	for(i=0;i<3;++i)
	{
		for(j=0;j<4;j++)
			cout<<b[i][j]<<",";
		cout<<endl;
	}
	return 0;
}
