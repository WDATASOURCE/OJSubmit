#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define INF 10000000
#define Max(a,b)	(a>b?a:b)
#define Min(a,b)	(a>b?b:a)	
int ps[101];
int low[101];			// i ??????;
int high[101];  		// i ??????;
int main ()
{
	int n,p,i,j,css;
	int max,min,mid;
	while(cin>>n>>p)
	{
		css=1;
		for(i=0;i<101;i++)
		{
			high[i]=0;
			low[i]=0;
		}
		int nn = n;
		while(nn--)
		{
			max=-1;
			min=INF;
			for(i=1;i<=p;i++)
			{
				scanf("%d",&ps[i]);
				max=Max(max,ps[i]);
				min=Min(min,ps[i]);
			}
			for(i=1;i<=p;i++)
			{
				if(ps[i]==max)
					high[i]++;
				if(ps[i]==min)
					low[i]++;
			}
		}
		for(i=1;i<=p;i++)
		{
			mid=(n/2)+(n%2);
			if(low[i]>=mid&&high[i]==0)
			{
				printf("%d ",i);
				css=0;
			}
		}
		if(css==1)
			printf("0");
		printf("\n");
	}
return 0;
}