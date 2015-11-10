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
const int MAXN = 1010;

struct Edge{
    int v, nxt;
};

int son;
bool vis[MAXN];
int head[MAXN];
int dfn[MAXN];
int low[MAXN];
int res[MAXN];
int ecnt, n, tdfn;
Edge edge[2 * MAXN];

void init(){
    tdfn = n = ecnt = son = 0;
    memset(vis, 0, sizeof(vis));
    memset(dfn, 0, sizeof(dfn));
    memset(res, 0, sizeof(res));
    memset(low, 0, sizeof(low));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v){
    edge[ecnt].v = v;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void dfs(int u){
    vis[u] = 1;
    dfn[u] = low[u] = ++tdfn;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        if(vis[v]) low[u] = min(low[u], dfn[v]);
        else{
            dfs(v);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u]){ 
                if(u != 1) res[u]++;
                else son++;
            }
        }
    }
}
 
int main(){
    int u, v, T = 0;
    while(scanf("%d", &u) && u){
        init();
        scanf("%d", &v);
        addEdge(u, v);
        addEdge(v, u);
        n = max(n, max(u, v));
        while(scanf("%d", &u) && u){
            scanf("%d", &v);
            addEdge(u, v);
            addEdge(v, u);
            n = max(n, max(u, v));
        }
        if(T) printf("\n");
        printf("Network #%d\n", ++T);
        dfs(1);
        if(son > 1) res[1] = son - 1;
        int flag = 1;
        for(int i = 1; i <= n; i++)
            if(res[i]){
                flag = 0;
                printf("  SPF node %d leaves %d subnets\n",i, res[i] + 1);
            }
        if(flag) printf("  No SPF nodes\n");
    }
    return 0;
}
