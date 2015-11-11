#include <cstdio>
#include <cmath>
const long long MOD = 1000000007;
//a^b%n
long long modexp(long long a,long long b,long long n)
{
    long long ret=1;
    long long tmp=a;
    while(b)
    {
       if(b&0x1) ret=ret*tmp%n;
       tmp=tmp*tmp%n;
       b>>=1;
    }
    return ret;
}

int main()
{
    int t;
    scanf ( "%d", &t );
    while(t--)
    {
        long long n;
        scanf ( "%lld", &n );
        long long ans;
        if(n%2)
        {
            //¼¼Êõ
            int k = n/2;
            ans = modexp(2, 2*k, MOD);
        }
        else
        {
            int k = n/2;
            ans = modexp(2, 2*k-1, MOD);
        }
        printf ( "%lld\n", ans-1 );
    }
    return 0;
}
