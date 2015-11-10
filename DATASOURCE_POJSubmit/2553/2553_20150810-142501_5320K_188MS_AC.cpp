/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-10 13:59
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
const int MAXN = 5050;
const int MAXE = 500050;

struct Edge{
    int v, nxt;
};

Edge edge[MAXE];
stack <int> sta;
bool instack[MAXN];
vector <int> vec[MAXN];
int n, m, tdfn, ecnt, scc_cnt;
int head[MAXN], dfn[MAXN], low[MAXN], Out[MAXN], belong[MAXN], res[MAXN];

void init(){
    tdfn = ecnt = scc_cnt = 0;
    memset(Out, 0, sizeof(Out));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    while(!sta.empty()) sta.pop();
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(instack, 0, sizeof(instack));
    for(int i = 0; i < MAXN; i++)
        vec[i].clear();
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
        if(!dfn[v]){
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }else if(instack[v]) low[u] = min(low[u], low[v]);
    }
    if(low[u] == dfn[u]){
        ++scc_cnt;
        int top;
        do{
            top = sta.top();
            sta.pop();
            instack[top] = false;
            belong[top] = scc_cnt;
            vec[scc_cnt].push_back(top);
        }while(!sta.empty() && u != top);
    }
}

int solve(){
    for(int i = 1; i <= n; i++)
        if(!dfn[i]) Tarjan(i);

    for(int u = 1; u <= n; u++)
        for(int i = head[u]; i + 1; i = edge[i].nxt)
            if(belong[edge[i].v] != belong[u]) Out[belong[u]]++;

    int num = 0;
    for(int i = 1; i <= scc_cnt; i++)
        if(!Out[i]){
            int size = vec[i].size();
            for(int j = 0; j < size; j++)
                res[num++] = vec[i][j];
        }
    return num;
}

int main(){
    while(scanf("%d", &n) != EOF && n){
        init();
        scanf("%d", &m);
        int u, v;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        int ans = solve();
        sort(res, res + ans);
        for(int i = 0; i < ans; i++)
            printf("%d%c", res[i], i == ans - 1 ? '\n' : ' ');
    }
 
    return 0;
}
