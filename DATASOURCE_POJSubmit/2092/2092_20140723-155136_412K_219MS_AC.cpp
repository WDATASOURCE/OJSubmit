#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
using namespace std;  
struct play  
{  
    int num;  
    int s;  
};  
bool cmp(play a,play b)  
{  
    if(a.s==b.s)  
        return a.num<b.num;  
    else  
        return a.s>b.s;  
}  
int main()  
{  
    int n,m,i,j;  
    while(scanf("%d%d",&n,&m))  
    {  
        play p[10003];  
        memset(p,0,sizeof(p));  
        int temp;  
        if(n==0 && m==0)  
            break;  
        for(i=0;i<n;i++)  
            for(j=0;j<m;j++)  
            {  
                scanf("%d",&temp);  
                p[temp].num=temp;  
                p[temp].s++;  
            }  
        sort(p,p+10000,cmp);  
        i=1;  
        while(p[i].s==p[i+1].s)  
        {  
            printf("%d ",p[i].num);  
            i++;  
        }  
        printf("%d\n",p[i].num);  
    }  
    return 0;  
}  
