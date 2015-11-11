/*=============================================================================
# Author:            DATASOURCE
# Last modified:     2015-10-07 19:05
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
const int MAXN = 300010;
const int DEG = 20;

struct Edge{
    int v, nxt;
};

int ecnt, n, m;
Edge edge[MAXN * 2];
int fa[MAXN][20];
int head[MAXN], depth[MAXN];

void init(){
    ecnt = 0;
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(depth, 0, sizeof(depth));
}

void addEdge(int u, int v){
    edge[ecnt].v = v;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void initfa(int root){
    queue <int> que;
    que.push(root);
    depth[root] = 0;
    fa[root][0] = root;
    while(!que.empty()){
        int u = que.front();
        que.pop();

        for(int i = 1; i < DEG; i++)
            fa[u][i] = fa[fa[u][i - 1]][i - 1];

        for(int i = head[u]; i + 1; i = edge[i].nxt){
            int v = edge[i].v;
            if(v == fa[u][0]) continue;
            depth[v] = depth[u] + 1;
            fa[v][0] = u;
            que.push(v);
        }
    }
}

int LCA(int u, int v){
    if(depth[u] > depth[v]) swap(u, v);
    int du = depth[u], dv = depth[v];
    int tu = u, tv = v;
    for(int det = dv - du, i = 0; det; det >>= 1, i++)
        if(det & 1) tv = fa[tv][i];
    if(tu == tv) return tu;
    for(int i = DEG - 1; i >= 0; i--){
        if(fa[tu][i] == fa[tv][i]) continue;
        tu = fa[tu][i];
        tv = fa[tv][i];
    }
    return fa[tu][0];
}
 
int main(){
    while(scanf("%d", &n) != EOF){
        init();
        int u, v;
        for(int i = 1; i < n; i++){
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        initfa(1);
        int q;
        scanf("%d", &q);
        while(q--){
            scanf("%d%d", &u, &v);
            int ans = LCA(u, v);
            printf("%d\n", ans);
        }
    }
    return 0;
}
