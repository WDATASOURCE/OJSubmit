#include<iostream>
#include <cstdio>
#include <algorithm>
#include<cmath>
using namespace std;
int Max=888888;
double tree[505][505];
double array[505];
bool vis[505];
typedef struct fun
{
	double x,y;
}rr;
fun a[505];
void prim(int n)
{
     vis[0]=true;
	 int i,j,k,l=0;
	 double low[505];
	 for(i=1; i<n; i++)
		 low[i]=tree[0][i];
	 for(i=1; i<=n-1; i++)
	 {
		 double min=Max;
		 j=0;
		 for(k=1; k<n; k++)
			 if(low[k]<min && vis[k]==false)//每一次记录的都是最小的啊
			 {
				 min=low[k];
				 j=k;
			 }
			 array[l++]=min;
			 vis[j]=true;
			 for(k=1; k<n; k++)
				 if(tree[j][k]<low[k] && vis[k]==false)
					 low[k]=tree[j][k];
	 }
}
int cmp(const void *a,const void *b)
{
	return *(double *)a>*(double *)b?-1:1;
}
int main()
{
	int T,p,n,i,j;
	cin>>T;
	while(T--)
	{
		cin>>p>>n;
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				tree[i][j]=Max;
		for(i=0; i<n; i++)
		{
			cin>>a[i].x>>a[i].y;
			vis[i]=false;
		}
		//建立树的
		for(i=0; i<n; i++)
		{
			for(j=i+1; j<n; j++)
				tree[i][j]=tree[j][i]=sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
		}
		prim(n);
		qsort(array,n,sizeof(double),cmp);
		printf("%.2lf\n",array[p-1]);
	}
	return 0;
}
