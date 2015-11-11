#include <cstdio>
const int maxsize = 100050;
int isNotPrime[maxsize];
int prime[maxsize];
int pcnt;
void getPrime()
{
    pcnt = 0;
    int i, j;
    isNotPrime[0] = isNotPrime[1] = 1;
    for(i=2; i<maxsize; i++)
    {
        if(!isNotPrime[i])
            prime[pcnt++] = i;
        for(j=0; j<pcnt && prime[j]*i<maxsize; j++)
        {
            isNotPrime[prime[j] * i] = 1;
            if(i % prime[j] == 0)
                break;
        }
    }
    return;
}
int p, k1, b1, k2;
int ap[maxsize];
int bp[maxsize];
long long gcd(long long a, long long b)
{
    return b==0?a:gcd(b, a%b);
}
long long lcm(long long a, long long b)
{
    return a/gcd(a, b) * b;
}
long long pow_mod(long long a, long long b, long long m)
{
    long long res = 1;
    long long tmp = a;
    while(b)
    {
        if(b&1)
            res = res * tmp %m;
        tmp = tmp*tmp%m;
        b>>=1;
    }
    return res;
}
long long cyc;
int main()
{
//    getPrime();
//    printf ( "%d %d %d\n", prime[1000], prime[12000], prime[5000] );
    int _case = 0;
    while(scanf("%d%d%d%d", &p, &k1, &b1, &k2) != EOF)
    {
        _case++;
        int cnt = 0;
        printf ( "Case #%d:\n", _case );
        cyc = lcm((p-1)/gcd(k1, p-1), (p-1)/gcd(k2, p-1) );
//        printf ( "cyc: %lld\n", cyc );
        long long a, b;

        k1 %= (p-1);
        k2 %= (p-1);
        b1 %= (p-1);

        for(a=1; a<p; a++)
        {
            long long t = pow_mod(a, (k1+b1)%(p-1), p);
            b = (p-t+p)%p;
            if(b == 0)
                continue;
            long long ta, tb;
            ta = t; tb = b;
            int flag = 1;
            for(int i=1; i<=cyc; i++)
            {
                ta = ta * (pow_mod(a, k1, p));
                tb = tb * (pow_mod(b, k2, p));
                ta %= p; tb %=p;
                if((ta + tb) % p  != 0)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
            {
                printf ( "%lld %lld\n", a, b );
                cnt++;
            }
        }
        if(!cnt)
            printf ( "-1\n" );
//        else
//            printf ( "±¬ÍêÁË\n" );
    }
    return 0;
}