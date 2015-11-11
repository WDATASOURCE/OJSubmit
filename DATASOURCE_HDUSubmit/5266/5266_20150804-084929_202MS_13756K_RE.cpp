/*=============================================================================
# Author:           He Shuwei
# Last modified:    2015-08-01 11:18
# Filename:            HDU_2586_LCA_ST.cpp
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
const int MAXN = 300040;

struct Edge{
    int v, w, nxt;
};

int R[MAXN];
int E[2 * MAXN];
bool vis[MAXN];
int head[MAXN];
int depth[MAXN];
Edge edge[2 * MAXN];
//long long dis[MAXN];
int dp[2 * MAXN][20];
int n, m, E_cnt, cnt;

void init(){
    cnt = E_cnt = 0;
    memset(R, 0, sizeof(R));
    //memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(depth, 0, sizeof(depth));
}
 
void addEdge(int u, int v, int w){
    edge[E_cnt].v = v;
    edge[E_cnt].w = w;
    edge[E_cnt].nxt = head[u];
    head[u] = E_cnt++;
}

void dfs(int u, int dep){
    E[++cnt] = u;
    depth[cnt] = dep;
    R[u] = cnt;
    vis[u] = true;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        if(vis[edge[i].v]) continue;
        //dis[edge[i].v] = dis[u] + edge[i].w;
        dfs(edge[i].v, dep + 1);
        E[++cnt] = u;
        depth[cnt] = dep;
    }
}

void ST(){
    for(int i = 1; i <= cnt; i++)
        dp[i][0] = i;
    for(int j = 1; j < 20; j++)
        for(int i = 1; i <= cnt; i++){
            if(i + (1 << j) - 1 <= cnt){
                int a = dp[i][j - 1], b = dp[i + (1 << (j - 1))][j - 1];
                if(depth[a] < depth[b]) dp[i][j] = a;
                else dp[i][j] = b;
            }
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
        int u, v, q;
        init();
        for(int i = 1; i < n; i++){
            scanf("%d%d", &u, &v);
            addEdge(u, v, 0);
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
