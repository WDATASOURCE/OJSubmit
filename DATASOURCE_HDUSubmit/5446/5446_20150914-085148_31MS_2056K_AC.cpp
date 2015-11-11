#include <cstdio>
#include <cstring>
#include <cmath>
const int maxsize = 100050;
long long fat[maxsize];
long long n, m, p;
typedef long  long LL;
LL mult_mod(LL a, LL b, LL m)
{
    a %= m;
    b %= m;
    LL res = 0;
    while(b){
        if(b&1){
            res += a;
            if(res >= m)
                res -= m;
        }
        a<<=1;
        if(a>=m)
            a -= m;
        b>>=1;
    }
    return res;
}
long long exp_mod(long long a, long long b, long long m)
{
    long long res = 1;
    long long tmp = a;
    while(b)
    {
        if(b&1)
//            res = (res * tmp) % m;
            res = mult_mod(res, tmp, m);
//        tmp = tmp * tmp % m;
        tmp = mult_mod(tmp, tmp, m);
        b>>=1;
    }
    return res;
}
void get_fat()
{
    int i;
    fat[0] = 1;
    for(i=1; i<=p; i++)
    {
        fat[i] = (fat[i-1] * i) % p;
    }
    return;
}
long long comb(long long n, long long m, long long p)
{
    if(n<m)
        return 0;
    long long res = fat[n];
    res = res * (exp_mod(fat[n-m]*fat[m] % p, p-2, p)) % p;
    return res;
}
long long lucas(long long n, long long m, long long p)
{
    long long res = 1;
    while(res && n && m)
    {
        res = res * comb(n%p, m%p, p) % p;
        n/=p;
        m/=p;
    }
    return res;
}
long long pi[50];
long long mi[50];
long long M;
int k;
long long chinese_fuck()
{
    long long res = 0;
//    printf ( "M: %lld\n", M );
    for(int i=0; i<k; i++)
    {
        long long Mi = M/pi[i];
//        printf ( "Mi: %lld\n", Mi );
//        printf ( "pi: %lld, mi: %lld\n", pi[i], mi[i] );
        long long t = exp_mod(Mi, pi[i]-2, pi[i]);
//        printf ( "t: %lld\n", t );
        res += mult_mod(mi[i],mult_mod(t,Mi,M), M);
//        printf ( "res: %lld\n", res );
        if(res>=M)
            res -= M;
    }
    if(res < 0)
        res+=M;
    if(res >= M)
        res-=M;
    return res;
}
int main()
{
    int t;
    scanf ( "%d", &t );
    while(t--)
    {
        M =  1;
        scanf ( "%lld%lld%d", &n, &m, &k );
        for(int i=0; i<k; i++)
        {
            scanf ( "%lld", &p );
            M*=p;
            get_fat();
            pi[i] = p;
            mi[i] = lucas(n, m, p);
        }
        long long ans = chinese_fuck();
        printf ( "%lld\n", ans );
    }
    return 0;
}