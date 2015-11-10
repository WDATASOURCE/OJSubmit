#include<stdio.h>
#include<math.h>
int main()
{
    int x,y,k;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        if(x > y)
        {
            k = x;
            x = y;
            y = k;
        }
        k = y - x;
        if(x == (int)((y - x)*(1 + sqrt(5.0))/2))
        {
            printf("0\n");
        }
        else
            printf("1\n");
    }
    return 0;
}