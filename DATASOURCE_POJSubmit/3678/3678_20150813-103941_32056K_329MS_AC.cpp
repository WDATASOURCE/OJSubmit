/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-13 10:18
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
const int MAXN = 2020;
const int MAXE = 2000100;

struct Edge{
    int v, nxt;
};

stack <int> sta;
bool instack[MAXN];
Edge edge[MAXE * 2];
int n, m, tdfn, scc_cnt, ecnt;
int head[MAXN], dfn[MAXN], low[MAXN], belong[MAXN];

void init(){
    tdfn = ecnt = scc_cnt = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
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
    int a, b, c;
    char ch[10];
    for(int i = 0; i < m; i++){
        scanf("%d%d%d%s", &a, &b, &c, ch);
        if(strcmp(ch, "AND") == 0){
            if(c == 1){
                addEdge(a + n, a);
                addEdge(b + n, b);
            }else{
                addEdge(a, b + n);
                addEdge(b, a + n);
            }
        }else if(strcmp(ch, "OR") == 0){
            if(c == 1){
                addEdge(a + n, b);
                addEdge(b + n, a);
            }else{
                addEdge(a, a + n);
                addEdge(b, b + n);
            }
        }else{
            if(c == 1){
                addEdge(a, b + n);
                addEdge(b + n, a);
                addEdge(a + n, b);
            }else{
                addEdge(a, b);
                addEdge(b, a);
                addEdge(a + n, b + n);
            }
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
    for(int i = 0; i < n + n; i++)
        if(!dfn[i]) Tarjan(i);

    bool flag = true;
    for(int i = 0; i < n; i++)
        if(belong[i] == belong[i + n]) flag = false;
    if(flag) printf("YES\n");
    else printf("NO\n");
}
 
int main(){
    while(~scanf("%d%d", &n, &m)){
        init();
        Input();
        solve();
    }
    return 0;
}
