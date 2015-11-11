#include <cstdio>
#include <cmath>
#include <cstring>
const double eps = 1e-6;
const int maxsize = 40010;
double dp[45][maxsize];
int v[50];
double w;
void init()
{
    memset(dp, 0, sizeof(dp));
}
int main()
{
    int t;
    int n;
    scanf ( "%d", &t );
    while(t--)
    {
        scanf ( "%d%lf", &n, &w );
//        w = 1-w;
        for(int i=1; i<=n; i++)
        {
            scanf ( "%d", &v[i] );
        }
        init();
        dp[1][0] = 0.5;
        dp[1][v[1]] = 0.5;
        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<=40000; j++)
            {
                dp[i][j] += dp[i-1][j] * 0.5;
                dp[i][j+v[i]] += dp[i-1][j] * 0.5;
            }
        }
        double s = 0;
        int ans = -1;
        for(int j=0; j<=40000; j++)
        {
            s += dp[n][j];
//            printf ( "dp[n][%d]: %.3f\n", j, dp[n][j] );
            if(s >= w)
            {
                ans = j;
                break;
            }
        }
        printf ( "%d\n", ans );

    }
    return 0;
}