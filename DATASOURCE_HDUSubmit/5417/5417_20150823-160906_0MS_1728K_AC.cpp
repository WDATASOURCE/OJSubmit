#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    int x,y,w,n;
    while(scanf("%d%d%d%d",&x,&y,&w,&n)!=EOF)
    {
        n--;
        int t = x/w+1;
        int s = n/t*(x+y)+(n%t)*w;
        printf("%d\n",s);
    }
    return 0;
}