#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <map>

using namespace std;
int dp[109][1009];
int n;
int mi[109];
struct nod{
    int b,p;
} re[109][109];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int cas,maxb;
    scanf("%d",&cas);
    while(cas--)
    {
        int a,b;maxb = 0;
        scanf("%d",&n);
        memset(dp,0x3f,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&mi[i]);
            for(int j=1;j<=mi[i];j++)
            {
                scanf("%d%d",&a,&b);
                if(maxb<a) maxb = a;
                re[i][j].b = a,re[i][j].p= b;
            }
        }
        for(int i=0;i<=maxb;i++) dp[0][i] = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=mi[i];j++)
            {
                for(int k =1;k<= re[i][j].b;k++)
                dp[i][k] = min(dp[i][k],dp[i-1][k]+re[i][j].p);
            }
        }
        double ans = 0;
        for(int i=1;i<=maxb;i++)
        ans = max(ans,i*1.0/dp[n][i]);
        printf("%.3f\n",ans);
    }
    return 0;
}
