#include<stdio.h>
#include<math.h>
int a[40];
int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        int k=0;
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        while(n!=0)
        {
            if(abs(n)%2!=0)
            {
                a[k++]=1;
                n=(n-1)/(-2);
            }
            else
            {
                a[k++]=0;
                n=n/(-2);
            }
        }
        for(i=k-1;i>=0;i--)
          printf("%d",a[i]);
          printf("\n");
    }
}