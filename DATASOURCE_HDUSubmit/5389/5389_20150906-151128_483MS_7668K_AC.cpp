#include <cstdio>
#include <cstring>
int f(int a, int b)
{
    if((a+b)%9)
        return (a+b) % 9;
    return 9;
}
const int maxsize = 100050;
const int MOD = 258280327;
int x[maxsize];
int dp[maxsize][15];
int main()
{
    int t;
    scanf ( "%d", &t );
    while(t--)
    {
        int n;
        int a, b;
        scanf ( "%d%d%d", &n, &a, &b );
        int s = 0;
        for(int i=1; i<=n; i++)
        {
            scanf ( "%d", &x[i] );
            s = f(s, x[i]);
        }
//        memset(dp, 0, sizeof(dp));
        dp[0][9] = 1;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=9; j++)
                dp[i][j] = 0;
            for(int j=0; j<=9; j++)
            {
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
                dp[i][f(j, x[i])] += dp[i-1][j];
                dp[i][f(j, x[i])] %= MOD;
            }
        }
        if(s == f(a, b))
            printf ( "%d\n", dp[n][a] );
        else
        {
            int ans = 0;
            if(s == a)
                ans++;
            if(s == b)
                ans++;
            printf ( "%d\n", ans );
        }
    }
    return 0;
}