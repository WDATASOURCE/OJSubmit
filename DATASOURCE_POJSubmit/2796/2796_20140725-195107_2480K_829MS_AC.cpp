#include <stdio.h>  
  
#define N 100001  
int lef[N],rig[N];  
__int64 sum[N],a[N];
int main()  
{  
    int i,j,n;  
    scanf("%d",&n);  
    for(i = 1; i <= n; ++i)  
    {  
        scanf("%I64d",a + i);  
        sum[i] = sum[i-1] + a[i];  
        lef[i] = rig[i] = i;  
    }  
    for(i = 2; i <= n; ++i)  
        while(lef[i] > 1 && a[lef[i]-1] >= a[i])  
            lef[i] = lef[lef[i] - 1];  
    for(i = n-1; i; --i)  
        while(rig[i] < n && a[rig[i]+1] >= a[i])  
            rig[i] = rig[rig[i] + 1];  
     int ll ,rr ;  ///答案可以为0，res初始为-1  
    __int64 res = -1,tmp;  
    for(i = 1; i <= n; ++i)  
    {  
        tmp = a[i] * (sum[rig[i]] - sum[lef[i]-1]);  
        if(tmp > res)  
        {  
            res = tmp;  
            ll = lef[i];  
            rr = rig[i];  
        }  
    }  
    printf("%I64d\n%d %d\n",res,ll,rr);  
 //   while(1);  
    return 0;  
}  
