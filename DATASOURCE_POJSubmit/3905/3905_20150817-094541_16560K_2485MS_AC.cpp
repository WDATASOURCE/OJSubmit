/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-13 18:52
# Filename: 		a.cpp
# Description: 
=============================================================================*/
 
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
#define ABS(x) ((x) >= 0 ? (x) : (-(x)))
using namespace std;
const int MAXN = 2010;
const int MAXE = 2000010;

struct Edge{
    int v, nxt;
};

Edge edge[MAXE];
stack <int> sta;
bool instack[MAXN];
int n, m, tdfn, scc_cnt, ecnt, a, b;
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
    char a1, b1;
    for(int i = 0; i < m; i++){
        scanf(" %c%d %c%d", &a1, &a, &b1, &b);
        //cerr << a1 << a <<" "<< b1 << b << endl;
        if(a1 == '+' && b1 == '+'){
            addEdge(a + n, b);
            addEdge(b + n, a);

        }else if(a1 == '-' && b1 == '-'){
            addEdge(a, b + n);
            addEdge(b, a + n);
        
        }else if(a1 == '+' && b1 == '-'){
            addEdge(a + n, b + n);
            addEdge(b, a);

        }else{
            addEdge(a, b);
            addEdge(b + n, a + n);

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

bool solve(){
    for(int i = 1; i <= n + n; i++)
        if(!dfn[i]) Tarjan(i);

    for(int i = 1; i <= n; i++)
        if(belong[i] == belong[i + n]) return false;
    return true;
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        Input();
        int ans = solve();
        printf("%d\n", ans);
    }
    return 0;
}
