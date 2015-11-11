/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-04 08:06
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
const int MAXN = 300030;
const int MAX_INT = (1 << 29);

struct Edge{
    int v, nxt;
};

bool vis[MAXN];
int dp[MAXN][20];
Edge edge[2 * MAXN];
int cnt, ecnt, n, q;
int head[MAXN], depth[MAXN], E[MAXN], R[MAXN];

void init(){
    cnt = ecnt = 0;
    memset(R, 0, sizeof(R));
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(depth, 0, sizeof(depth));
}

void addEdge(int u, int v){
    edge[ecnt].v = v;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void dfs(int u, int dep){
    E[++cnt] = u;
    R[u] = cnt;
    vis[u] = true;
    depth[cnt] = dep;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        if(vis[v]) continue;
        dfs(v, dep + 1);
        E[++cnt] = u;
        depth[cnt] = dep;
    }
}

void ST(){
    int a, b;
    for(int i = 1; i <= cnt; i++)
        dp[i][0] = i;
    for(int j = 1; j <= 20; j++)
        for(int i = 1; i <= cnt; i++)
            if(i + (1 << j) - 1 <= cnt){
                a = dp[i][j - 1], b = dp[i + (1 << (j - 1))][j - 1];
                if(depth[a] < depth[b]) dp[i][j] = a;
                else dp[i][j] = b;
            }
}

int RMQ(int l, int r){
    int k = (int)(log(r - l + 1) / log(2.0));
    int a = dp[l][k], b = dp[r - (1 << k) + 1][k];
    if(depth[a] < depth[b]) return a;
    else return b;
}

int LCA(int u, int v){
    int l = R[u], r = R[v];
    if(l > r) swap(l, r);
    int pos = RMQ(l, r);
    return E[pos];
}

int main(){
    while(scanf("%d", &n) != EOF){
        int u, v;
        init();
        for(int i = 1; i < n; i++){
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }

        dfs(1, 1);
        ST();

        scanf("%d", &q);
        for(int i = 0; i < q; i++){
            scanf("%d%d", &u, &v);
            printf("%d\n", LCA(u, v));
        }
    }
    return 0;
}
