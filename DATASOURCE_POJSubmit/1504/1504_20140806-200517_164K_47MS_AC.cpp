#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		char s1[13],s2[13];
		scanf("%d%d",&a,&b);
		sprintf(s1,"%d",a);
		sprintf(s2,"%d",b);
		reverse(s1,s1+strlen(s1));
		reverse(s2,s2+strlen(s2));
		sscanf(s1,"%d",&a);
		sscanf(s2,"%d",&b);
		sprintf(s1,"%d",a+b);
		reverse(s1,s1+strlen(s1));
		sscanf(s1,"%d",&a);
		printf("%d\n",a);
	}
	return 0;
}
