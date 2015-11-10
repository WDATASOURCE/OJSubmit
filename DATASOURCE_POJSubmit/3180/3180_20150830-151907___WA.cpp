/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-08-30 15:09
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
 
struct Edge{
    int v, nxt;
};

stack <int> sta;
bool instack[MAXN];
Edge edge[MAXN * 5];
int ans, n, m, ecnt, tdfn;
int head[MAXN], low[MAXN], dfn[MAXN];

void init(){
    tdfn = ecnt = ans = 0;
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    while(!sta.empty()) sta.pop();
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(instack, 0, sizeof(instack));
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
        int num = 0;
        do{
            top = sta.top();
            sta.pop();
            num++;
        }while(u != top && !sta.empty());
        if(num > 2) ans++;
    }
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        int u, v;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }

        for(int i = 1; i <= n; i++)
            if(!dfn[i]) Tarjan(i);

        printf("%d\n", ans);
    }
 
    return 0;
}
