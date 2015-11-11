/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-01 10:55
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
const int MAX_INT = (1 << 29);
const int MAXN = 10040;

struct Edge{
    int v, w, nxt;
};

int R[MAXN];
int par[MAXN];
int E[2 * MAXN];
bool vis[MAXN];
int head[MAXN];
int depth[2 * MAXN];
Edge edge[2 * MAXN];
long long dis[MAXN];
int dp[2 * MAXN][20];
int n, m, q, E_cnt, cnt;

void init(){
    cnt = 1;
    E_cnt = 0;
    memset(R, 0, sizeof(R));
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(depth, 0, sizeof(depth));
    for(int i = 0; i < MAXN; i++)
        par[i] = i;
}
 
void addEdge(int u, int v, int w){
    edge[E_cnt].v = v;
    edge[E_cnt].w = w;
    edge[E_cnt].nxt = head[u];
    head[u] = E_cnt++;
}

int find(int x){
    if(par[x] != x) par[x] = find(par[x]);
    return par[x];
}

void Union(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy) return;
    par[fx] = fy;
}

void dfs(int u, int dep){
    E[++cnt] = u;
    depth[cnt] = dep;
    R[u] = cnt;
    vis[u] = true;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        if(vis[edge[i].v]) continue;
        dis[edge[i].v] = dis[u] + edge[i].w;
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
    int k = (int)(log((double)(r - l + 1)) / log(2.0));
    int a = dp[l][k], b = dp[r - (1 << k) + 1][k];
    return min(a, b);
}

long long LCA(int u, int v){
    int l = R[u], r = R[v];
    if(l > r) swap(l, r);
    int pos = RMQ(l, r);
    return E[pos];
}

int main(){
    while(scanf("%d%d%d", &n, &m, &q) != EOF){
        init();
        int u, v, w;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
            Union(u, v);
        }
        for(int i = 1; i <= n; i++)
            if(find(i) == i) addEdge(0, i, 0);
        dfs(0, 0);
        ST();
        int a, b;
        //for(int i = 0; i <= n; i++)
            //cerr <<"i = "<< i <<", dis[i] = "<< dis[i] << endl;
        for(int i = 0; i < q; i++){
            scanf("%d%d", &a, &b);
            if(find(a) != find(b)){
                printf("Not connected\n");
                continue;
            }
            int lca = LCA(a, b);
            printf("%I64d\n", dis[a] + dis[b] - 2 * dis[lca]);
        }
    }
    return 0;
}
