/*=============================================================================
# Author:           He Shuwei
# Last modified:	2015-08-05 08:17
# Filename:			POJ_1144_割点.cpp
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
}edge[MAXN * MAXN];

int ecnt, tdfn, n, root;
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
    dfn[u] = low[u] = ++tdfn;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        if((fa ^ 1) == i) continue;
        if(!dfn[v]){
            Tarjan(v, i);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u]) son++;
        }else low[u] = min(low[u], dfn[v]);
    }
    if(u == root && son > 2) cut[u] = 1;
    else if(u != root && son) cut[u] = 1;
}
 
int main(){
    int u, v;
    while(~scanf("%d", &n) && n){
        init();
        while(scanf("%d", &u) && u){
            while(getchar() != '\n'){
                scanf("%d", &v);
                addEdge(u, v);
                addEdge(v, u);
            }
        }
        root = 1;
        Tarjan(root, -1);
        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(cut[i]) ans++;
        printf("%d\n", ans);
    }
    return 0;
}

