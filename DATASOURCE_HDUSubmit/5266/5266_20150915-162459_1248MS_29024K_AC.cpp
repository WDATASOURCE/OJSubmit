/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-09-15 16:10
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
const int MAXN = 300300;
const int MAXM = 600600;

struct Edge{
    int v, nxt, id;
};

bool vis[MAXN];
int n, m, q, ecnt, qcnt;
Edge tedge[MAXM], qedge[MAXM];
int thead[MAXN], qhead[MAXN], par[MAXN], res[MAXN];

void init(){
    ecnt = qcnt = 0;
    memset(vis, 0, sizeof(vis));
    memset(tedge, 0, sizeof(tedge));
    memset(qedge, 0, sizeof(qedge));
    memset(thead, -1, sizeof(thead));
    memset(qhead, -1, sizeof(qhead));
    for(int i = 0; i < MAXN; i++) par[i] = i;
}

void addEdge(int *head, Edge *edge, int &cnt, int u, int v, int id){
    edge[cnt].v = v;
    edge[cnt].id = id;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}

int Find(int x){
    if(par[x] != x) par[x] = Find(par[x]);
    return par[x];
}

void Union(int u, int v){
    int fu = Find(u);
    int fv = Find(v);
    if(fu == fv) return;
    par[fv] = fu;
}

void Tarjan(int u, int fa){
    vis[u] = true;
    for(int i = thead[u]; i + 1; i = tedge[i].nxt){
        int v = tedge[i].v;
        if((fa ^ 1) == i) continue;
        Tarjan(v, i);
        Union(u, v);
    }

    for(int i = qhead[u]; i + 1; i = qedge[i].nxt){
        int v = qedge[i].v;
        int id = qedge[i].id;
        if(!vis[v]) continue;
        res[id] = Find(v);
    }
}

int main(){
    while(scanf("%d", &n) != EOF){
        init();
        int u, v;
        for(int i = 1; i < n; i++){
            scanf("%d%d", &u, &v);
            addEdge(thead, tedge, ecnt, u, v, i);
            addEdge(thead, tedge, ecnt, v, u, i);
        }

        scanf("%d", &q);

        for(int i = 0; i < q; i++){
            scanf("%d%d", &u, &v);
            addEdge(qhead, qedge, qcnt, u, v, i);
            addEdge(qhead, qedge, qcnt, v, u, i);
        }

        Tarjan(1, -1);

        for(int i = 0; i < q; i++)
            printf("%d\n", res[i]);
    }

    return 0;
}
