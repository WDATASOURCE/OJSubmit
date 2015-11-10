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
#define ABS(x) ((x) >= 0 ? (x) : (-(x)))
using namespace std;
const int MAXN = 502;
const int MAXE = 80200;

struct Edge{
    int v, nxt;
};

struct Point{
    int x, y;
};

Edge edge[MAXE];
stack <int> sta;
Point point[MAXN];
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

void buildGraph(int mid){
    init();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++){
            if(ABS(point[i].y - point[j].y) >= 2 * mid || ABS(point[i].x - point[j].x) >= mid) continue;
            if(ABS(point[i].y - point[j].y) < mid){
                if(point[i].y > point[j].y){
                    addEdge(i, j + n);
                    addEdge(i + n, i);
                    addEdge(j + n, i);
                    addEdge(j, j + n);
                }else if(point[i].y < point[j].y){
                    addEdge(j, i + n);
                    addEdge(j + n, j);
                    addEdge(i + n, j);
                    addEdge(i, i + n);
                }else{
                    addEdge(i, j + n);
                    addEdge(i + n, j);
                    addEdge(j, i + n);
                    addEdge(j + n, i);
                }
            }else{
                if(point[i].y > point[j].y){
                    addEdge(i + n, j + n);
                    addEdge(j, i);
                }else{
                    addEdge(j + n, i + n);
                    addEdge(i, j);
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

bool gao(){
    for(int i = 0; i < n + n; i++)
        if(!dfn[i]) Tarjan(i);

    for(int i = 0; i < n; i++)
        if(belong[i] == belong[i + n]) return false;
    return true;
}

int solve(){
    int l = 1, r = 20001, mid;
    while(r - l > 1){
        mid = (l + r) >> 1;
        buildGraph(mid);
        if(gao()) l = mid;
        else r = mid;
    }
    return l;
}
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d%d", &point[i].x, &point[i].y);
       int ans = solve();
       printf("%d\n", ans);
    }
    return 0;
}
