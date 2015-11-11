/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-24 18:23
# Filename:         a.cpp
# Description: 
=============================================================================*/
 
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
const int MAXN = 10010;
const int MOD = 1000000007;
long long a[MAXN];

/* a * b % mod */
long long multmod(long long a, long long b, long long mod){
    long long res = 0;
    while(b){
        if(b & 1) res += a, res %= mod;
        a += a, a %= mod, b >>= 1;
    }
    return res;
}

/* a ^ b % mod */
long long powmod(long long a, long long b, long long mod){
    long long res = 1;
    while(b){
        if(b & 1) res = multmod(res, a, mod);
        a = multmod(a, a, mod), b >>= 1;
    }
    return res;
}
 
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        long long n, t, k;
        scanf("%lld%lld%lld", &n, &t, &k);
        for(int i = 0; i < n; i++)
            scanf("%lld", &a[i]);

        t %= n;

        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans = a[(i + n - t) % n] * powmod(k, t, MOD) % MOD;
            printf("%lld%c", ans, i == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}
