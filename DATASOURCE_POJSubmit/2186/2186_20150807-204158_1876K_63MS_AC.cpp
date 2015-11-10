/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-07 20:17
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
const int MAXN = 10010;
const int MAXE = 50050;

struct Edge{
    int v, nxt;
};

bool vis[MAXN];
int cmp[MAXN], vs[MAXN];
int head[MAXN], rhead[MAXN];
Edge edge[MAXE], redge[MAXE];
int n, m, ecnt, recnt, vscnt;

void init(){
    recnt = ecnt = 0;
    memset(vis, 0, sizeof(vis));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(redge, 0, sizeof(redge));
    memset(rhead, -1, sizeof(rhead));
}

void addEdge(int *head, Edge *edge, int u, int v, int &cnt){
    edge[cnt].v = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}

void dfs(int u){
    vis[u] = true;
    for(int i = head[u]; i + 1; i = edge[i].nxt)
        if(!vis[edge[i].v]) dfs(edge[i].v);
    vs[vscnt++] = u;
}

void rdfs(int u, int k){
    vis[u] = true;
    cmp[u] = k;
    for(int i = rhead[u]; i + 1; i = redge[i].nxt)
        if(!vis[redge[i].v]) rdfs(redge[i].v, k);
}

int scc(){
    memset(vis, 0, sizeof(vis));
    vscnt = 0;
    for(int i = 1; i <= n; i++)
        if(!vis[i]) dfs(i);

    int scc_cnt = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = vscnt - 1; i >= 0; i--)
        if(!vis[vs[i]]) rdfs(vs[i], scc_cnt++);
    
    return scc_cnt;
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        int u, v;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            addEdge(head, edge, u, v, ecnt);
            addEdge(rhead, redge, v, u, recnt);
        }

        int scc_cnt = scc();
        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(cmp[i] == scc_cnt - 1) u = i, ans++;

        memset(vis, 0, sizeof(vis));
        rdfs(u, 0);

        for(int i = 1; i <= n; i++)
            if(!vis[i]){
                ans = 0;
                break;
            }
        printf("%d\n", ans);
    }
    return 0;
}
