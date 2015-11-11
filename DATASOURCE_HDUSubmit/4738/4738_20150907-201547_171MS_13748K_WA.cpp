/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-09-07 17:24
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
const int MAXN = 1010;

struct Edge{
    int v, w, nxt;
};
 
stack <int> sta;
bool instack[MAXN];
Edge edge[MAXN * MAXN];
int n, m, ecnt, tdfn, bcc_cnt;
int head[MAXN], low[MAXN], dfn[MAXN], belong[MAXN];

void init(){
    bcc_cnt = ecnt = tdfn = 0;
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    while(!sta.empty()) sta.pop();
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(instack, 0, sizeof(instack));
}

void addEdge(int u, int v, int w){
    edge[ecnt].v = v;
    edge[ecnt].w = w;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void Tarjan(int u, int fa){
    sta.push(u);
    instack[u] = true;
    low[u] = dfn[u] = ++tdfn;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        if(fa == v) continue;
        if(!dfn[v]){
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }else if(instack[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]){
        bcc_cnt++;
        int top;
        do{
            top = sta.top();
            belong[top] = bcc_cnt;
            instack[top] = false;
            sta.pop();
        }while(u != top);
    }
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        if(!(n + m)) break;
        init();
        int u, v, w;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }

        int num = 0;
        int ans = (1 << 29);
        for(int i = 1; i <= n; i++)
            if(!dfn[i]) Tarjan(i, -1), num++;
        if(num > 1) ans = 0;
        else{
            for(int u = 1; u <= n; u++)
                for(int i = head[u]; i + 1; i = edge[i].nxt)
                    if(belong[u] != belong[edge[i].v]) ans = min(ans, edge[i].w);
            if(ans == (1 << 29)) ans = -1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
