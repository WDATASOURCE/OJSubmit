#include<stdio.h>
#include<math.h>
const double PI=acos(-1.0);
int main()
{
    int cas,i,j=0,n;
    double R,r;
    scanf("%d",&cas);
    while(cas--)
    {
        j++;
        scanf("%lf %d",&R,&n);
        printf("Scenario #%d:\n",j);
        r=(R*sin(PI/(n*1.0)))/(1+sin(PI/(n*1.0)));
        printf("%.3f\n\n",r);
    }
    return 0;
}
