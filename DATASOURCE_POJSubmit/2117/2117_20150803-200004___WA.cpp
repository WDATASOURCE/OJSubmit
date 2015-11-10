/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-03 14:29
# Filename: 		a.cpp
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
const int MAXN = 10100;

struct Edge{
    int v, nxt;
};

int root;
int dfn[MAXN];
int low[MAXN];
int cut[MAXN];
int vis[MAXN];
int head[MAXN];
Edge edge[2 * MAXN];
int ecnt, n, m, tdfn;

void init(){
    tdfn = 1;
    ecnt = 0;
    memset(vis, 0, sizeof(vis));
    memset(dfn, 0, sizeof(dfn));
    memset(cut, 0, sizeof(cut));
    memset(low, 0, sizeof(low));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    low[1] = dfn[1] = vis[1] = 1;
}

void addEdge(int u, int v){
    edge[ecnt].v = v;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void Tarjan(int u, int fa){
    int son = 0;
    vis[u] = 1;
    dfn[u] = low[u] = ++tdfn;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        if(vis[v] == 1 && v != fa) low[u] = min(low[u], dfn[v]);
        if(vis[v]) continue;
        Tarjan(v, u);
        son++;
        low[u] = min(low[u], low[v]);
        if((u == root && son > 1) || (u != root && dfn[u] <= low[v])) cut[u]++;
    }
    vis[u] = 2;
}

/*
void dfs(int u){
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        if(vis[v]) low[u] = min(low[u], dfn[v]);
        else{
            vis[v] = 1;
            dfn[v] = low[v] = ++tdfn;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u]){ 
                if(u != 1) res[u]++;
                else son++;
            }
        }
    }
}
*/
 
int main(){
    while(~scanf("%d%d", &n, &m)){
        if(!(n + m)) break;
        if(m == 0){
            printf("%d\n", n - 1);
            continue;
        }
        init();
        int u, v;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        int ans = 0;
        int temp = 0;
        for(int i = 0; i < n; i++){
            if(dfn[i]) continue;
            ans++;
            tdfn = 0;
            root = i;
            Tarjan(i, -1);
            temp = max(temp, cut[i]);
        }
        printf("%d\n", ans + temp);
    }
    return 0;
}
