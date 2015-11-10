#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 10010
#define M ((1 << 29))
#define Min(a, b) ((a) > (b) ? (b) : (a))
using namespace std;

int w[550], v[550];
int dp[N], V, n;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int a, b;
        scanf("%d%d", &a, &b);
        V  = b - a;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d%d", &w[i], &v[i]);
        fill(dp, dp + N, M);
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
            for(int j = v[i]; j <= V; j++)
                dp[j] = Min(dp[j], dp[j - v[i]] + w[i]);
        if(dp[V] == M) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n", dp[V]);
    }
    return 0;
}
