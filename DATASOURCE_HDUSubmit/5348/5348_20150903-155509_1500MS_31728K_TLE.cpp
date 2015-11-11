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
    int v, nxt, id, state;
};

int ecnt, n, m;
Edge edge[6 * MAXN];
bool vis[3 * MAXN], ans[3 * MAXN];
int head[MAXN], In[MAXN], Out[MAXN], degree[MAXN];

void init(){
    ecnt = 0;
    memset(In, 0, sizeof(In));
    memset(Out, 0, sizeof(Out));
    memset(vis, 0, sizeof(vis));
    memset(ans, 0, sizeof(ans));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(degree, 0, sizeof(degree));
}

void addEdge(int u, int v, int id, int state){
    edge[ecnt].v = v;
    edge[ecnt].id = id;
    edge[ecnt].state = state;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void dfs(int u){
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        int id = edge[i].id;
        if(vis[edge[i].id]) continue;
        vis[id] = true;
        if(In[u] >= Out[u]){
            Out[u]++;
            In[v]++;
            //if(edge[i].state) edge1[id].state = 1;
            //else edge1[id].state = 0;
            ans[id] = edge[i].state;
        }else{
            In[u]++;
            Out[v]++;
            ans[id] = !edge[i].state;
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
            if(u == v) continue;
            degree[u]++, degree[v]++;
            addEdge(u, v, i, 1);
            addEdge(v, u, i, 0);
        }
        int s = 1;
        for(int i = 1; i <= n; i++)
            if(degree[i] & 1) s = i;
        dfs(s);

        for(int i = 1; i <= m; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}
