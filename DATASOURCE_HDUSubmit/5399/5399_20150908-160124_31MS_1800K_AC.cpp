#include <cstdio>
#include <cstring>
const long long p = 1000000007;
const int maxsize = 110;
long long fac[maxsize];
void init()
{
    int i;
    fac[0] = 1;
    for(i=1; i<=100; i++)
    {
        fac[i] = fac[i-1]*i % p;
    }
    return;
}
long long exp(long long a, long long b)
{
    long long res = 1;
    long long tmp = a;
    while(b)
    {
        if(b&1)
            res = (res * tmp) % p;
        tmp = tmp * tmp % p;
        b>>=1;
    }
    return res;
}
int ipt[110][1000];
int f[110];
int _f[110];
int vis[110];
int main()
{
    int n, m;
    init();
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i=1; i<=n; i++)
        {
            f[i] = i;
        }
        int pre = 0;
        long long ans = 1;
        int flag = 1;
        int ff = 0;
        for(int i=0; i<m; i++)
        {
            int x;
            scanf ( "%d", &x );
            if(x != -1)
            {
                memset(vis, 0, sizeof(vis));
                ipt[i][0] = 1;
                ipt[i][1] = x;
                for(int j=2; j<=n; j++)
                {
                    scanf ( "%d", &ipt[i][j] );
                }
                for(int j=1; j<=n; j++)
                {
                    vis[ipt[i][j]]++;
                }
                for(int j=1; j<=n; j++)
                {
                    if(vis[ipt[i][j]] > 1)
                        ff = 1;
                }
            }
            else
            {
                ipt[i][0] = 0;
                flag = 0;
                pre++;
            }
        }
        if(pre > 1)
            ans = (ans * exp(fac[n], pre-1)) % p;
        if(flag)
        {
            ans = 1;
            for(int i=m-1; i>=0; i--)
            {
                for(int j=1; j<=n; j++)
                {
                    _f[j] = ipt[i][f[j]];
                }
                for(int j=1; j<=n; j++)
                {
                    f[j] = _f[j];
                }
            }
            for(int i=1; i<=n; i++)
            {
                if(f[i] != i)
                    ans = 0;
            }
        }
        if(!ff)
            printf ( "%lld\n", ans );
        else
            printf ( "0\n" );
    }
    return 0;
}