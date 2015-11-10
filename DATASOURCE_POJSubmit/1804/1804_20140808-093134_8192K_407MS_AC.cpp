#include<stdio.h>
#include<string.h>
int N=2000001;
int C[2000005];
int a[1005];
int Lowbit(int x)
{
    return x&(-x);
}
void Modify(int i,int x)
{
    while(i<=N)
    {
        C[i]+=x;
        i+=Lowbit(i);
    }
}
int Sum(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=C[i];
        i-=Lowbit(i);
    }
    return sum;
}
int main()
{
    int c,t,n;
    int i,j;   
    int sum=0;    
    scanf("%d",&c);
    for(i=1;i<=c;++i)
    {
        sum=0;
        memset(C,0,sizeof(C));
        scanf("%d",&n);
        for(j=1;j<=n;++j)
        {
            scanf("%d",&a[j]);
        }
        for(j=n;j>=1;--j)
        {
            t=a[j]+1000001;
            sum+=Sum(t-1);
            Modify(t,1);
        }
        printf("Scenario #%d:\n%d\n\n",i,sum);
    }
    return 0 ;
}
