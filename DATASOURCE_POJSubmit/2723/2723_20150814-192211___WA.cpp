/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-13 18:52
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
const int MAXN = 4020;
const int MAXE = 8020;

struct Edge{
    int v, nxt;
};

stack <int> sta;
Edge edge[MAXE];
int lock[MAXN][2];
int door[MAXN][2];
bool instack[MAXN];
int n, m, tdfn, scc_cnt, ecnt;
int head[MAXN], low[MAXN], dfn[MAXN], belong[MAXN];

void init(){
    tdfn = scc_cnt = ecnt = 0;
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    while(!sta.empty()) sta.pop();
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(belong, 0, sizeof(belong));
    memset(instack, 0, sizeof(instack));
}

void addEdge(int u, int v){
    edge[ecnt].v = v;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void buildGraph(int mid){
    init();
    int t = n * 2;
    for(int i = 0; i < n; i++){
        addEdge(lock[i][0], lock[i][1] + t);
        addEdge(lock[i][1], lock[i][0] + t);
    }
    for(int i = 0; i < mid; i++){
        addEdge(door[i][0] + t, door[i][1]);
        addEdge(door[i][1] + t, door[i][0]);
    }
}

void Tarjan(int u){
    sta.push(u);
    instack[u] = true;
    dfn[u] = low[u] = ++tdfn;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        if(!dfn[v]){
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }else if(instack[v]) low[u] = min(low[u], low[v]);
    }
    if(low[u] == dfn[u]){
        int top ;
        ++scc_cnt;
        do{
            top = sta.top();
            sta.pop();
            instack[top] = false;
            belong[top] = scc_cnt;
        }while(u != top && !sta.empty());
    }
}

bool gao(){
    int t = n * 2;
    for(int i = 0; i < t + t; i++)
        if(!dfn[i]) Tarjan(i);
    
    for(int i = 0; i < t; i++)
        if(belong[i] == belong[i + t]) return false;
    return true;
}

int solve(){
    int l = 0, r = m + 1, mid;
    while(r - l > 1){
        mid = (l + r) >> 1;
        buildGraph(mid);
        if(gao()) l = mid;
        else r = mid;
    }
    return l;
}
 
int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        if(!(n + m)) break;

        for(int i = 0; i < n; i++)
            scanf("%d%d", &lock[i][0], &lock[i][1]);
        for(int i = 0; i < m; i++)
            scanf("%d%d", &door[i][0], &door[i][1]);

       int ans = solve();
       printf("%d\n", ans);
    }
    return 0;
}
