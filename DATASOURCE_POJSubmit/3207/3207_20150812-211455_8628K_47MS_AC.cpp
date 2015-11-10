/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-12 20:34
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
const int MAXN = 2010;
const int MAXE = 1000010;

struct Edge{
    int v, nxt;
};

stack <int> sta;
Edge edge[MAXE];
int mp[MAXN][2];
bool instack[MAXN];
int n, m, tdfn, scc_cnt, ecnt;
int head[MAXN], low[MAXN], dfn[MAXN], belong[MAXN];

void init(){
    tdfn = scc_cnt = ecnt = 0;
    memset(mp, 0, sizeof(mp));
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
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

void Input(){
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &mp[i][0], &mp[i][1]);
        if(mp[i][0] > mp[i][1]) swap(mp[i][0], mp[i][1]);
    }
}

void buildGraph(){
    for(int i = 1; i <= m; i++)
        for(int j = 1; j < i; j++){
            if((mp[i][0] > mp[j][0] && mp[i][0] < mp[j][1] && mp[i][1] > mp[j][1]) || (mp[j][0] > mp[i][0] && mp[j][0] < mp[i][1] && mp[j][1] > mp[i][1])){
                addEdge(i, j + n);
                addEdge(j, i + n);
                addEdge(i + n, j);
                addEdge(j + n, i);
            }
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
        int top;
        ++scc_cnt;
        do{
            top = sta.top();
            sta.pop();
            instack[top] = false;
            belong[top] = scc_cnt;
        }while(u != top && !sta.empty());
    }
}

void solve(){
    for(int i = 1; i < n + n; i++)
        if(!dfn[i]) Tarjan(i);

    bool flag = true;
    for(int i = 1; i <= n; i++)
        if(belong[i] == belong[i + n]) flag = false;

    if(flag) printf("panda is telling the truth...\n");
    else printf("the evil panda is lying again\n");
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        Input();
        buildGraph();
        solve();
    }
    return 0;
}
