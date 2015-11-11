#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 100010
#define M (-(1 << 29))
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) > (b) ? (b) : (a))
using namespace std;

int w[150], c[150];
int dp[N], n, m;
bool vis[N];

void ZeroOnePack(int v, int w){
    for(int i = m; i >= v; i--)
        dp[i] = Max(dp[i], dp[i - v] + w);
}

void CompletePack(int v, int w){
    for(int i = v; i <= m; i++)
        dp[i] = Max(dp[i], dp[i - v] + w);
}

void MutiplePack(){
    for(int i = 1; i <= n; i++){
        if(c[i] * w[i] > m) CompletePack(w[i], w[i]);
        else{
            int nc = c[i];
            int k = 1;
            while(k <= nc){
                ZeroOnePack(w[i] * k, w[i] * k);
                nc -= k;
                k <<= 1;
            }
            ZeroOnePack(w[i] * nc, w[i] * nc);
        }
    }
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF && n + m){
        for(int i = 1; i <= n; i++)
            scanf("%d", &w[i]);
        for(int i = 1; i <= n; i++)
            scanf("%d", &c[i]);
        fill(dp, dp + N, M);
        fill(vis, vis + N, 0);
        dp[0] = 0;
        MutiplePack();
        int ans = 0;
        for(int i = 1; i <= m; i++)
            if(dp[i] > 0 && !vis[dp[i]])
                ans++, vis[dp[i]] = 1;
        printf("%d\n", ans);
    }
    return 0;
}
