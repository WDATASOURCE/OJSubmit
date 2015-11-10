/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-04 16:23
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
const int MAXN = 110;

struct Edge{
    int v, nxt;
};

Edge edge[2 * MAXN];
int ecnt, tdfn, n, rt;
int cut[MAXN], dfn[MAXN];
int head[MAXN], low[MAXN], vis[MAXN];

void init(){
    ecnt = tdfn = 0;
    memset(cut, 0, sizeof(cut));
    memset(vis, 0, sizeof(vis));
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
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
        if((u == 1 && son > 1) || (u != 1 && dfn[u] <= low[v])) cut[u]++;
    }
    vis[u] = 2;
}
 
int main(){
    int u, v;
    while(scanf("%d", &n) != EOF && n){
        init();
        while(scanf("%d", &u) && u){
            while(getchar() != '\n'){
                scanf("%d", &v);
                addEdge(u, v);
                addEdge(v, u);
            }
        }
        Tarjan(1, -1);
        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(cut[i]) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
