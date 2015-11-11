/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-01 09:16
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
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int MAX_INT = (1 << 29);
const int MAXN = 40040;
const int MAXE = 80080;

struct Edge{
    int v, w, nxt;
};

int E[MAXE];
int R[MAXN];
bool vis[MAXN];
int head[MAXN];
int depth[MAXE];
Edge edge[MAXE];
int dp[MAXE][20];
long long dis[MAXN];
int cnt, E_cnt;
int n, m;

void init(){
    cnt = 1;
    E_cnt = 0;
    memset(R, 0, sizeof(R));
    memset(dis, 0, sizeof(dis));
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

void dfs(int s, int deep){
    E[cnt] = s;
    depth[cnt++] = deep;
    R[s] = cnt - 1;
    for(int i = head[s]; i + 1; i = edge[i].nxt){
        if(vis[edge[i].v]) continue;
        vis[edge[i].v] = true;
        dis[edge[i].v] = dis[s] + edge[i].w;
        dfs(edge[i].v, deep + 1);
        E[cnt] = s;
        depth[cnt++] = deep;
    }
}

void st(){

    for(int i = 1; i < cnt; i++)
        dp[i][0] = i;
    for(int j = 0; j < 20; j++)
        for(int i = 1; i < cnt; i++)
            if(i + (1 << j) - 1 < cnt){
                if(depth[dp[i][j - 1]] < depth[dp[i + (1 << (j - 1))][j - 1]]) dp[i][j] = dp[i][j - 1];
                else dp[i][j] = dp[i + (1 << (j - 1))][j - 1];
            }
}

long long lca(int u, int v){
    int l = R[u], r = R[v];
    if(l > r) swap(l, r);
    int k = (int)(log(r - l + 1) / log(2.0));
    int temp = E[min(dp[l][k], dp[r - (1 << k) + 1][k])];
    long long ans = dis[u] + dis[v] - 2 * dis[temp];
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        init();
        scanf("%d%d", &n, &m);
        int u, v, w;
        for(int i = 1; i < n; i++){
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        vis[1] = true;
        dfs(1, 1);
        st();
        int a, b;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &a, &b);
            printf("%lld\n", lca(a, b));
        }
    }
    return 0;
}
