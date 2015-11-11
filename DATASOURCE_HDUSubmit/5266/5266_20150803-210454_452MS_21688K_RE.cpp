/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-03 20:45
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
const int MAXN = 300010;
const int MAX_INT = (1 << 29);

struct Edge{
    int v, nxt;
    int index;
};

bool vis[MAXN];
int ecnt, qcnt, n, q;
int thead[MAXN], qhead[MAXN];
Edge tedge[2 * MAXN], qedge[2 * MAXN];
int res[MAXN], par[MAXN], father[MAXN];

void init(){
    ecnt = qcnt = 0;
    memset(vis, 0, sizeof(vis));
    memset(tedge, 0, sizeof(tedge));
    memset(qedge, 0, sizeof(qedge));
    memset(thead, -1, sizeof(thead));
    memset(qhead, -1, sizeof(qhead));
    for(int i = 0; i <= n; i++)
        par[i] = i;
}

void addEdge(int *head, Edge *edge, int u, int v, int index, int &cnt){
    edge[cnt].v = v;
    edge[cnt].index = index;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}

int Find(int x){
    if(par[x] != x) par[x] = Find(par[x]);
    return par[x];
}

void Union(int x, int y){
    int fx = Find(x);
    int fy = Find(y);
    if(fx != fy) par[fx] = fy;
}

void Tarjan(int u){
    father[u] = u;
    vis[u] = true;
    for(int i = thead[u]; i + 1; i = tedge[i].nxt){
        int v = tedge[i].v;
        if(vis[v]) continue;
        Tarjan(v);
        Union(u, v);
        father[Find(u)] = u;
    }

    for(int i = qhead[u]; i + 1; i = qedge[i].nxt){
        int v = qedge[i].v;
        if(!vis[v]) continue;
        res[qedge[i].index] = father[Find(v)];
    }
}
 
int main(){
    while(scanf("%d", &n) != EOF){
        init();
        int u, v;
        for(int i = 1; i < n; i++){
            scanf("%d%d", &u, &v);
            addEdge(thead, tedge, u, v, 0, ecnt);
            addEdge(thead, tedge, v, u, 0, ecnt);
        }
        scanf("%d", &q);
        for(int i = 0; i < q; i++){
            scanf("%d%d", &u, &v);
            addEdge(qhead, qedge, u, v, i, qcnt);
            addEdge(qhead, qedge, v, u, i, qcnt);
        }
        Tarjan(1);
        for(int i = 0; i < q; i++)
            printf("%d\n", res[i]);
    }
    return 0;
}
