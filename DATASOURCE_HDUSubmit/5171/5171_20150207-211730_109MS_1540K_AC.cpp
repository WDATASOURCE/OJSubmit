#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define mo 10000007
struct mat{
    int a[2][2];
}t;

mat operator * (const mat &a, const mat&b){
    mat c;
    memset(c.a, 0, sizeof(c.a));
    for(int i = 0;i < 2;i ++)
        for(int j = 0;j < 2;j ++)
            for(int k = 0;k < 2;k ++)
                c.a[i][j] = (c.a[i][j] + 1LL * a.a[i][k] * b.a[k][j]) % mo;
    return c;
}

mat pow(mat a, int k){
    mat c;
    memset(c.a, 0, sizeof(c.a));
    for(int i = 0;i < 2;i ++) c.a[i][i] = 1;
    while(k){
        if(k & 1) c = c * a;
        a = a * a;
        k >>= 1;
    }
    return c;
}

int fib(int m){
    memset(t.a, 0, sizeof(t.a));
    t.a[0][1] = t.a[1][0] = t.a[1][1] = 1;
    t = pow(t, m);
    return t.a[1][0];
}

int n, k, a[100010];
    
int main(){
    while(scanf("%d%d", &n, &k) != EOF){
        for(int i = 1;i <= n;i ++) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        int sum = 0;
        for(int i = 1;i <= n - 2;i ++) sum = (sum + a[i]) % mo;
        sum = (1LL * fib(2 + k) * a[n - 1] + sum) % mo;
        sum = (1LL * (fib(2 + k + 1) - 1) * a[n] + sum) % mo;
        printf("%d\n", (sum + mo) % mo);
    }
    return 0;
}