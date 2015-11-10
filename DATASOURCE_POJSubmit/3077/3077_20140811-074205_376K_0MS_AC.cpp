#include <cstdio>


int main()
{
    int n,con,i;
    __int64 x;

    scanf("%d",&n);

    while(n--)
    {
        scanf("%I64d",&x);
        con = 0;
        while(x > 10)
        {
            if(x % 10 > 4)
                x += 10;
            x /= 10;
            con++;
        }
        for(i = 0 ;i < con; i++)
            x *= 10;
         printf("%I64d\n",x);



    }

    return 0;
}