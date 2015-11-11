/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-13 18:52
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
const int MAXN = 20010;
const int MAXE = 400020;

struct Edge{
    int v, nxt;
};

stack <int> sta;
Edge edge[MAXE];
bool instack[MAXN];
int alice[MAXN][2];
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
    int val, a, b, c;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &val);
        alice[i][0] = val;
        alice[i][1] = (val % 3) + 1;
        //cerr <<"i = "<< i <<", val = "<< val <<", alice[i][0] = "<< alice[i][0] <<", alice[i][1] = "<< alice[i][1] << endl;
    }
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &c);
        if(c == 0){     // same
            if(alice[a][0] != alice[b][0])
                addEdge(a, b + n), addEdge(b, a + n);
            if(alice[a][0] != alice[b][1])
                addEdge(a, b), addEdge(b + n, a + n);
            if(alice[a][1] != alice[b][0])
                addEdge(a + n, b + n), addEdge(b, a);
            if(alice[a][1] != alice[b][1])
                addEdge(a + n, b), addEdge(b + n, a);
        }else{
            if(alice[a][0] == alice[b][0])
                addEdge(a, b + n), addEdge(b, a + n);
            if(alice[a][0] == alice[b][1])
                addEdge(a, b), addEdge(b + n, a + n);
            if(alice[a][1] == alice[b][0])
                addEdge(a + n, b + n), addEdge(b, a);
            if(alice[a][1] == alice[b][1])
                addEdge(a + n, b), addEdge(b + n, a);
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
        }else if(instack[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]){
        int top ;
        ++scc_cnt;
        do{
            top = sta.top();
            sta.pop();
            instack[top] = true;
            belong[top] = scc_cnt;
        }while(u != top && !sta.empty());
    }
}


bool solve(){
    for(int i = 1; i <= n + n; i++)
        if(!dfn[i]) Tarjan(i);

    for(int i = 1; i <= n; i++)
        if(belong[i] == belong[i + n]) return false;
    return true;
}
 
int main(){
    int t;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++){
        init();
        Input();
        if(solve()) printf("Case #%d: yes\n", Case);
        else printf("Case #%d: no\n", Case);
    }
    return 0;
}
