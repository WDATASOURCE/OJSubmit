/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-09-03 12:34
# Filename:         b.cpp
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
const int MAXN = 100100;

struct Edge{
    int v, nxt, id, flag, state;
};

struct Edge1{
    int u, v, state;
};

Edge1 edge1[3 * MAXN];

int ecnt, n, m;
bool vis[6 * MAXN];
Edge edge[6 * MAXN];
int head[MAXN], In[MAXN], Out[MAXN], degree[MAXN];

void init(){
    ecnt = 0;
    memset(In, 0, sizeof(In));
    memset(Out, 0, sizeof(Out));
    memset(vis, 0, sizeof(vis));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(edge1, 0, sizeof(edge1));
    memset(degree, 0, sizeof(degree));
}

void addEdge(int u, int v, int id){
    edge[ecnt].v = v;
    edge[ecnt].id = id;
    edge[ecnt].state = 1;
    edge[ecnt].nxt = head[u];
    edge[ecnt].flag = ecnt + 1;
    head[u] = ecnt++;

    edge[ecnt].v = u;
    edge[ecnt].id = id;
    edge[ecnt].state = 0;
    edge[ecnt].nxt = head[v];
    edge[ecnt].flag = ecnt - 1;
    head[v] = ecnt++;
}

void dfs(int u){
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        if(vis[i]) continue;
        int v = edge[i].v;
        int id = edge[i].id;
        if(In[u] >= Out[u]){
            Out[u]++;
            In[v]++;
            vis[edge[i].flag] = true;
            vis[i] = true;
            //if(edge[i].state) edge1[id].state = 1;
            //else edge1[id].state = 0;
            edge1[id].state = edge[i].state;
        }else{
            In[u]++;
            Out[v]++;
            vis[edge[i].flag] = true;
            vis[i] = true;
            edge1[id].state = !edge[i].state;
        }
        dfs(v);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        init();
        scanf("%d%d", &n, &m);
        int u, v;
        for(int i = 1; i <= m; i++){
            scanf("%d%d", &u, &v);
            edge1[i].u = u, edge1[i].v = v;
            if(u == v) continue;
            degree[u]++, degree[v]++;
            addEdge(u, v, i);
        }
        int s = 1;
        for(int i = 1; i <= n; i++)
            if(degree[i] & 1) s = i;
        dfs(s);

        for(int i = 1; i <= m; i++)
            printf("%d\n", edge1[i].state);
    }
    return 0;
}
