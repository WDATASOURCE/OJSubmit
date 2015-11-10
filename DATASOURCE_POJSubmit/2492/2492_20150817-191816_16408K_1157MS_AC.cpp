/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-17 17:45
# Filename: 		b.cpp
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
const int MAXN = 2010;
const int MAXE = 2000100;

struct Edge{
    int v, nxt;
};

bool flag;
int n, m, ecnt;
Edge edge[MAXE];
int head[MAXN], vis[MAXN], rela[MAXN];

void init(){
    ecnt = 0;
    flag = true;
    memset(vis, 0, sizeof(vis));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v){
    edge[ecnt].v = v;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void dfs(int u, int dep, int fa){
    vis[u] = 1;
    rela[u] = dep;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        if(vis[v] && rela[u] == rela[v] && v != fa){
            flag = false;
            continue;
        }
        if(vis[v]) continue;
        rela[v] = dep ^ 1;
        dfs(v, dep ^ 1, u);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++){
        init();
        scanf("%d%d", &n, &m);
        int u, v;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        
        for(int i = 1; i <= n; i++)
            if(!vis[i]) dfs(i, 0, -1);

        printf("Scenario #%d:\n", Case);
        if(!flag) printf("Suspicious bugs found!\n");
        else printf("No suspicious bugs found!\n");
        puts("");
    }
    return 0;
}
