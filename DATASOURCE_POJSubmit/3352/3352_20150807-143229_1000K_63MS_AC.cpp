/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-07 09:27
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
const int MAXN = 5050;
const int MAXE = 20020;

struct Edge{
    int v, nxt;
};

bool vis[MAXN];
Edge edge[MAXE];
stack <int> sta;
int ecnt, n, m, scc, tdfn;
int degree[MAXN], belong[MAXN];
int head[MAXN], dfn[MAXN], low[MAXN];

void init(){
    ecnt = scc = tdfn = 0;
    while(!sta.empty()) sta.pop();
    memset(vis, 0, sizeof(vis));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(degree, 0, sizeof(degree));
}

void addEdge(int u, int v){
    edge[ecnt].v = v;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void Tarjan(int u, int fa){
    low[u] = dfn[u] = ++tdfn;
    sta.push(u);
    vis[u] = 1;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        if(i == (fa ^ 1)) continue;
        if(!dfn[v]){
            Tarjan(v, i);
            low[u] = min(low[u], low[v]);
        }else if(vis[v]) low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]){
        scc++;
        while(1){
            int top = sta.top();
            sta.pop();
            vis[top] = 0;
            belong[top] = scc;
            if(u == top) break;
        }
    }
}

int solve(){
    for(int i = 1; i <= n; i ++)
        if(!dfn[i]) Tarjan(1, -1);
    for(int i = 1; i <= n; i++){
        for(int j = head[i]; j + 1; j = edge[j].nxt){
            int v = edge[j].v;
            if(belong[i] != belong[v]) degree[belong[i]]++;
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++)
        if(degree[i] == 1) res++;
    int ans = (res + 1) / 2;
    return ans;
}

int main(){
    //int T = 0;
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        int u, v;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        int ans = solve();
        //printf("Output for Sample Input %d\n", ++T);
        printf("%d\n", ans);
    }
    return 0;
}
