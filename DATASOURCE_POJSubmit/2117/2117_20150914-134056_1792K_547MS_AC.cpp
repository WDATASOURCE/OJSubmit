/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-09-12 20:48
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

int root;
Edge edge[MAXN * 3];
int n, m, ecnt, tdfn;
int head[MAXN], low[MAXN], dfn[MAXN], cut[MAXN];

void init(){
    ecnt = tdfn = 0;
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    memset(cut, 0, sizeof(cut));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v){
    edge[ecnt].v = v;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void Tarjan(int u, int fa){
    int son = 0;
    low[u] = dfn[u] = ++tdfn;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        if((fa ^ 1) == i) continue;
        //if(fa == v) continue;
        if(!dfn[v]){
            Tarjan(v, i);
            //Tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(dfn[u] <= low[v]) son++;
        }else low[u] = min(low[u], dfn[v]);
    }

    if(u == root && son > 1) cut[u] = son;
    else if(u != root && son) cut[u] = son + 1;
    else cut[u] = 0;

}
 
int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        if(!(n + m)) break;
        if(m == 0){
            printf("%d\n", n - 1);
            continue;
        }
        init();
        int u, v;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        int ans = 0;
        int res = 0;
        for(int i = 0; i < n; i++){
            if(!dfn[i]){
                ans++;
                root = i;
                Tarjan(i, -1);
            }
            res = max(res, cut[i]);
        }

        if(res) res--;
        ans += res;
        printf("%d\n", ans);
    }
    return 0;
}
