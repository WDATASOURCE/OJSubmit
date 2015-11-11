/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-13 13:18
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
const int MAXN = 2010;
const int MAXE = (MAXN * MAXN / 4 * 3);

struct Edge{
    int v, nxt;
};

stack <int> sta;
bool instack[MAXN];
int n, m, tdfn, scc_cnt, ecnt;
int head[MAXN], low[MAXN], dfn[MAXN], belong[MAXN];
Edge edge[MAXE];
 
void init(){
    tdfn = scc_cnt = ecnt = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
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
    int a, b, c, d;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if(!c && !d){
            addEdge(a, b + n);
            addEdge(a + n, b);
            //addEdge(a + n, b + n);
        }else if(!c && d){
            addEdge(a, b);
            //addEdge(a + n, b);
            addEdge(a + n, b + n);
        }else if(c && !d){
            addEdge(a, b);
            //addEdge(a, b + n);
            addEdge(a + n, b + n);
        }else {
            //addEdge(a, b);
            addEdge(a, b + n);
            addEdge(a + n, b);
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
    for(int i = 0; i < 2 * n; i += 2)
        if(belong[i] == belong[i + n]) flag = false;

    if(flag) printf("YES\n");
    else printf("NO\n");
}

int main(){
    while(~scanf("%d%d", &n, &m)){
        init();
        Input();
        solve();
        //for(int i = 0; i < n; i++)
            //cerr<<"i = "<< i <<", belong[i] = "<< belong[i] <<", belong[i + n] = "<< belong[i + n] << endl;
    }
    return 0;
}
