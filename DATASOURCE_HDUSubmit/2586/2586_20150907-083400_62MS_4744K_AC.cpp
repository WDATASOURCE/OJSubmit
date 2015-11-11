/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-09-06 21:56
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
const int MAXN = 40040;

struct Edge{
    int v, w, nxt;
};

bool vis[MAXN];
int n, q, ecnt, qcnt;
int uu[MAXN], vv[MAXN];
Edge tedge[MAXN * 2], qedge[MAXN];
int thead[MAXN], qhead[MAXN], res[MAXN], dis[MAXN], par[MAXN];

void init(){
    qcnt = ecnt = 0;
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    memset(tedge, 0, sizeof(tedge));
    memset(qedge, 0, sizeof(qedge));
    memset(thead, -1, sizeof(thead));
    memset(qhead, -1, sizeof(qhead));
}

void addEdge(int *head, Edge *edge, int &cnt, int u, int v, int w){
    edge[cnt].v = v;
    edge[cnt].w = w;
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
    par[fv] = fu;
}

void Tarjan(int u, int w){
    dis[u] = w;
    par[u] = u;
    vis[u] = true;
    for(int i = thead[u]; i + 1; i = tedge[i].nxt){
        int v = tedge[i].v;
        if(vis[v]) continue;
        Tarjan(v, dis[u] + tedge[i].w);
        Union(u, v);
    }

    for(int i = qhead[u]; i + 1; i = qedge[i].nxt){
        int v = qedge[i].v;
        int id = qedge[i].w;
        if(!vis[v]) continue;
        res[id] = Find(v);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        init();
        scanf("%d%d", &n, &q);
        int u, v, w;
        for(int i = 1; i < n; i++){
            scanf("%d%d%d", &u, &v, &w);
            addEdge(thead, tedge, ecnt, u, v, w);
            addEdge(thead, tedge, ecnt, v, u, w);
        }

        for(int i = 0; i < q; i++){
            scanf("%d%d", &u, &v);
            uu[i] = u, vv[i] = v;
            addEdge(qhead, qedge, qcnt, u, v, i);
            addEdge(qhead, qedge, qcnt, v, u, i);
        }

        Tarjan(1, 0);

        for(int i = 0; i < q; i++){
            int ans = dis[uu[i]] + dis[vv[i]] - 2 * dis[res[i]];
            printf("%d\n", ans);
        }
    }
    return 0;
}
