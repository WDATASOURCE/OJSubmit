#include<iostream>
#include <algorithm>
using namespace std;


bool iscan(int *p,int n,int a,int c)
{
	int i,j,be,ba;			//a 为可能的答案
	be=p[0];
	ba=be+a;
	c--;
	for(i=1;i<n;i++){
		if(p[i]>=ba)
		{
			be=p[i];
			ba=be+a;
			c--;
		}
	
	}
	if(c<=0)
		return true;
	return false;
}

int  find(int n,int c,int *p)
{
	int l=0,h=p[n-1]+1;
	int min;
	while(h-l!=1)
	{
		min=(l+h)/2;

		if(iscan(p,n,min,c))
			l=min;
		else
			h=min;

	}
	return l;
}
	
int main()
{
	ios_base::sync_with_stdio(false);
	int i,n,c,key;
	cin>>n>>c;
	int *p=new int[n];
	for(i=0;i<n;i++)
	cin>>p[i];
	sort(p,p+n);
	key=find(n,c,p);
	cout<<key<<endl;
	return 0;
}
