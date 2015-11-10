#include<iostream>
#include<iomanip>
#include<string.h>
#define N 51
#define M 100
using namespace std;

struct aa
{
	int a;
	char *p;
};
int nus(char *str,int n)
{
	int i,j,sum=0;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(int(str[i])>int(str[j]))
				sum++;
	return sum;
}

void exchange(aa *str,int m,int n)
{
	int i,j;
	aa t;
	for(i=0;i<m;i++)
		str[i].a=nus(str[i].p,n);
	for(i=0;i<m-1;i++)
		for(j=i+1;j<m;j++)
			if(str[i].a>str[j].a)
			{
				t=str[i];
				str[i]=str[j];
				str[j]=t;
			}
	return;

}

int main()
{
	aa str[M];
	int m,n,i;
	cin>>n>>m;
	cin.ignore();
	for(i=0;i<m;i++)
	{
		str[i].p=new char[n+1];
		cin.getline(str[i].p,n+1);
	}
	exchange(str,m,n);
	for(i=0;i<m;i++)
		cout<<str[i].p<<endl;

	return 0;
}
