/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-04 12:00
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
const int MAXN = 50050;

struct Edge{
    int v, nxt;
    int index;
};

bool vis[MAXN];
int ecnt, qcnt, acnt, n, q;
int uu[MAXN], vv[MAXN], val[MAXN];
int Min[MAXN], Max[MAXN], Up[MAXN], Down[MAXN];
Edge tedge[2 * MAXN], qedge[2 * MAXN], aedge[2 * MAXN];
int thead[MAXN], qhead[MAXN], ahead[MAXN], par[MAXN], res[MAXN];

void init(){
    ecnt = qcnt = acnt = 0;
    memset(res, 0, sizeof(res));
    memset(val, 0, sizeof(val));
    memset(vis, 0, sizeof(vis));
    memset(tedge, 0, sizeof(tedge));
    memset(qedge, 0, sizeof(qedge));
    memset(aedge, 0, sizeof(aedge));
    memset(thead, -1, sizeof(thead));
    memset(qhead, -1, sizeof(qhead));
    memset(ahead, -1, sizeof(ahead));
}

void addEdge(int *head, Edge *edge, int u, int v, int index, int &cnt){
    edge[cnt].v = v;
    edge[cnt].index = index;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}

int Find(int x){
    if(x == par[x]) return par[x];
    int temp = par[x];
    par[x] = Find(par[x]);
    Up[x] = max(max(Up[x], Up[temp]), Max[temp] - Min[x]);
    Down[x] = max(max(Down[x], Down[temp]), Max[x] - Min[temp]);
    Max[x] = max(Max[x], Max[temp]);
    Min[x] = min(Min[x], Min[temp]);
    return par[x];
}

void Tarjan(int u){
    vis[u] = true;
    par[u] = u;
    for(int i = qhead[u]; i + 1; i = qedge[i].nxt){
        int v = qedge[i].v, index = qedge[i].index;
        if(!vis[v]) continue;
        int lca = Find(v);
        addEdge(ahead, aedge, lca, i, index, acnt);
    }

    for(int i = thead[u]; i + 1; i = tedge[i].nxt){
        int v = tedge[i].v;
        if(vis[v]) continue;
        Tarjan(v);
        par[v] = u;
    }

    for(int i = ahead[u]; i + 1; i = aedge[i].nxt){
        int index = aedge[i].index;
        Find(uu[index]);
        Find(vv[index]);
        res[index] = max(max(Up[uu[index]], Down[vv[index]]), Max[vv[index]] - Min[uu[index]]); 
    }
}
 
int main(){
    while(scanf("%d", &n) != EOF){
        init();
        for(int i = 1; i <= n; i++){
            scanf("%d", &val[i]);
            Up[i] = Down[i] = 0;
            Max[i] = Min[i] = val[i];
        }
        int u, v;
        for(int i = 1; i < n; i++){
            scanf("%d%d", &u, &v);
            addEdge(thead, tedge, u, v, i, ecnt);
            addEdge(thead, tedge, v, u, i, ecnt);
        }

        scanf("%d", &q);
        for(int i = 0; i < q; i++){
            scanf("%d%d", &uu[i], &vv[i]);
            addEdge(qhead, qedge, u, v, i, qcnt);
            addEdge(qhead, qedge, v, u, i, qcnt);
        }

        Tarjan(1);

        for(int i = 0; i < q; i++)
            printf("%d\n", res[i]);
    }
    return 0;
}
