/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-10 09:25
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
const int MAXN = 1010;
const int MAXE = 6666;

struct Edge{
    int v, nxt;
};

Edge edge[MAXE];
stack <int> sta;
bool instack[MAXN], vis[MAXN];
int n, m, tdfn, ecnt, scc_cnt, depth;
int head[MAXN], dfn[MAXN], low[MAXN], In[MAXN], belong[MAXN];

void init(){
    ecnt = tdfn = scc_cnt = 0;
    memset(In, 0, sizeof(In));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    while(!sta.empty()) sta.pop();
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v){
    edge[ecnt].v = v;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void Tarjan(int u){
    sta.push(u);
    instack[u] = true;
    low[u] = dfn[u] = ++tdfn;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        if(!dfn[v]){
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }else if(instack[v]) low[u] = min(low[u], low[v]);
    }
    if(low[u] == dfn[u]){
        int top;
        ++scc_cnt;
        do{
            top = sta.top();
            sta.pop();
            belong[top] = scc_cnt;
            instack[top] = false;
        }while(!sta.empty() && top != u);
    }
}

void dfs(int u, int dep){
    vis[u] = 1;
    depth = max(depth, dep);
    for(int i = head[u]; i + 1; i = edge[i].nxt)
        if(!vis[edge[i].v]) dfs(edge[i].v, dep + 1);
}

void solve(){
    for(int i = 1; i <= n; i++)
        if(!dfn[i]) Tarjan(i);

    for(int u = 1; u <= n; u++)
        for(int i = head[u]; i + 1; i = edge[i].nxt)
            if(belong[u] != belong[edge[i].v]) In[belong[edge[i].v]]++;

    int num = 0, tmp = 1;
    for(int i = 1; i <= scc_cnt; i++)
        if(!In[i]) num++;

    if(num > 1){
        printf("No\n");
        return;
    }

    for(int i = 1; i <= n; i++)
        if(!In[belong[i]]){
            tmp = i;
            break;
        }

    memset(vis, 0, sizeof(vis));
    depth = 1;
    dfs(tmp, 1);

    for(int i = 1; i <= n; i++)
        if(!vis[i]){
            printf("No\n");
            return;
        }
    if(depth < scc_cnt) printf("No\n");
    else printf("Yes\n");
}
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        init();
        scanf("%d%d", &n, &m);
        int u, v;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }

        solve();
    }
    return 0;
}
