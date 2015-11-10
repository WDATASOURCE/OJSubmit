/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-09 21:57
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
const int MAXE = 100010;

struct Edge{
    int v, nxt;
};

Edge edge[MAXE];
stack <int> sta;
bool instack[MAXN];
int n, m, tdfn, ecnt, scc_cnt;
int head[MAXN], dfn[MAXN], low[MAXN], belong[MAXN], Out[MAXN];

void init(){
    tdfn = ecnt = scc_cnt = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(Out, 0, sizeof(Out));
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
    dfn[u] = low[u] = ++tdfn;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        if(dfn[v] == 0){
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }else if(instack[v]) low[u] = min(low[u], low[v]);
    }
    if(low[u] == dfn[u]){
        int top;
        scc_cnt++;
        do{
            top = sta.top();
            sta.pop();
            instack[top] = false;
            belong[top] = scc_cnt;
        }while(u != top && !sta.empty());
    }
}

int solve(){

    for(int i = 1; i <= n; i++)
        if(!dfn[i]) Tarjan(i);

    for(int u = 1; u <= n; u++)
        for(int i = head[u]; i + 1; i = edge[i].nxt)
            if(belong[edge[i].v] != belong[u]) Out[belong[u]]++;

    int num = 0, tmp = 1, ans = 0;

    for(int i = 1; i <= scc_cnt; i++)
        if(!Out[i]) num++, tmp = i;

    if(num == 1){
        for(int i = 1; i <= n; i++)
            if(belong[i] == tmp) ans++;
    }

    return ans;
}


int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        int u, v;
        for(int i = 0; i < m;  i++){
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        int ans = solve();
        printf("%d\n", ans);
    }
    return 0;
}
