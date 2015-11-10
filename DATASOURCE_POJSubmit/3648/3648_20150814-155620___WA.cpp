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
const int MAXN = 410;
const int MAXE = 8020;

struct Edge{
    int v, nxt;
};

stack <int> sta;
Edge edge[MAXE];
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

void Input(){
    int a, b;
    char c, d;
    for(int i = 0; i < m; i++){
        scanf("%d%c %d%c", &a, &c, &b, &d);
        if(c == 'h' && d == 'h'){
            addEdge(a + n, b);
            addEdge(b + n, a);
        }else if(c == 'w' && d == 'h'){
            addEdge(a, b);
            addEdge(b + n, a + n);
        }else if(c == 'h' && d == 'w'){
            addEdge(a + n, b + b);
            addEdge(b, a);
        }else{
            addEdge(a, b + n);
            addEdge(b, a + n);
        }
    }
    addEdge(0, n);
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


void solve(){
    for(int i = 1; i <= n + n; i++)
        if(!dfn[i]) Tarjan(i);

    bool flag = true;
    for(int i = 1; i <= n; i++)
        if(belong[i] == belong[i + n]) flag = false;

    if(flag){
        for(int i = 1; i < n; i++){
            if(belong[i] < belong[i + n])
                printf("%d%c%c", i, 'h', i == n - 1 ? '\n' : ' ');
            else printf("%d%c%c", i, 'w', i == n - 1 ? '\n' : ' ');
        }
    }else printf("bad luck\n");

}
 
int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        if(!(n + m)) break;
        init();
        Input();
        solve();
    }
    return 0;
}
