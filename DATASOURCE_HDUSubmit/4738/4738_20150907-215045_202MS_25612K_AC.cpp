/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-09-07 17:24
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
const int MAXN = 1010;

struct Edge{
    int v, w, nxt;
};

int ans;
//stack <int> sta;
//bool instack[MAXN];
Edge edge[MAXN * MAXN * 2];
int n, m, ecnt, tdfn;
int head[MAXN], low[MAXN], dfn[MAXN];

void init(){
    ans = (1 << 29);
    ecnt = tdfn = 0;
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v, int w){
    edge[ecnt].v = v;
    edge[ecnt].w = w;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void Tarjan(int u, int fa){
    low[u] = dfn[u] = ++tdfn;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        if((fa ^ 1) == i) continue;
        if(!dfn[v]){
            Tarjan(v, i);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]) ans = min(ans, edge[i].w);
        }else low[u] = min(low[u], low[v]);
    }
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        if(!(n + m)) break;
        init();
        int u, v, w;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }

        int num = 0;
        for(int i = 1; i <= n; i++)
            if(!dfn[i]) Tarjan(i, -1), num++;
        if(num > 1) ans = 0;
        else if(ans == (1 << 29)) ans = -1;
        else if(ans == 0) ans = 1;
        printf("%d\n", ans);
    }
    return 0;
}
