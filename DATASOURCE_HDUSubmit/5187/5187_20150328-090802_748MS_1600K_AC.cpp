#include <cstdio>
typedef long long LL;
LL n, p;

LL multmod(LL a, LL b, LL p){
    LL res = 0;
    while(b){
        if(b & 1) res += a, res %= p;
        a += a, a %= p, b >>= 1;
    }
    return res;
}

/*
LL powmod(LL a, LL b, LL p){
    if(b == 0) return 1;
    LL x = powmod(a, b / 2, p);
    LL ans = multmod(x, x, p);
    if(n & 1) ans = multmod(ans, a, p);
    return ans;
}
*/

LL powmod(LL a, LL b, LL p){
    LL res = 1;
    while(b){
        if(b & 1) res = multmod(res, a, p);
        a = multmod(a, a, p), b >>= 1;
    }
    return res;
}

int main(){
    while(scanf("%I64d%I64d", &n, &p) != EOF){
        if(n == 1){
            printf("%I64d\n", n % p);
            continue;
        }else{
            LL ans = powmod(2, n, p) - 2;
            while(ans < 0) ans += p;
            printf("%I64d\n", ans);
        }
    }
    return 0;
}
