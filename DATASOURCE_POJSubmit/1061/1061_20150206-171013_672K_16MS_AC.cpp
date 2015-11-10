#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 105
using namespace std;

long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

void exgcd(long long a, long long b, long long &x, long long &y){
    if(b == 0) {
        x = 1, y = 0;
        return ;
    }
    exgcd(b, a % b, x, y);
    long long t = x;
    x = y;
    y = t - a / b * y;
    return;
}

int main(){
    long long x, y, m, n, l;
    while(scanf("%I64d%I64d%I64d%I64d%I64d", &x, &y, &m, &n, &l) != EOF){
        long long a = m - n;
        long long b = y - x;
        long long p, q;
        if(a < 0) a = -a, b = -b;
        long long d = gcd(a, l);
        if(b % d){
            printf("Impossible\n");
            continue;
        }
        a /= d, l /= d, b /= d;
        exgcd(a, l, p, q);
        p *= b;
        long long t = p % l;
        while(t < 0) t += l;
        printf("%I64d\n", t);
    }
    return 0;
}
