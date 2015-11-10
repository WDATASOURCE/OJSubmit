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
const int MAXE = 1000010;

struct Edge{
    int v, nxt;
};

struct Point{
    int x, y;

    int getDis(const Point &a){
        return ABS(x - a.x) + ABS(y - a.y);
    }
};

Edge edge[MAXE];
stack <int> sta;
bool instack[MAXN];
int diss12[MAXN][2];
Point barn[MAXN], s1, s2;
Point hate[MAXN], like[MAXN];
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

void buildGraph(int mid){
    init();
    int dis = s1.getDis(s2);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j < i; j++){
            int disIs1 = diss12[i][0];
            int disIs2 = diss12[i][1];
            int disJs1 = diss12[j][0];
            int disJs2 = diss12[j][1];
            if(disIs1 + disJs1 > mid) addEdge(i, j + n), addEdge(j, i + n);
            if(disIs2 + disJs2 > mid) addEdge(i + n, j), addEdge(j + n, i);
            if(disIs1 + dis + disJs2 > mid) addEdge(i, j), addEdge(j + n, i + n);
            if(disIs2 + dis + disJs1 > mid) addEdge(i + n, j + n), addEdge(j, i);
        }
    for(int i = 0; i < a; i++){
        addEdge(hate[i].x, hate[i].y + n);
        addEdge(hate[i].y, hate[i].x + n);
        addEdge(hate[i].x + n, hate[i].y);
        addEdge(hate[i].y + n, hate[i].x);
    }

    for(int i = 0; i < b; i++){
        addEdge(like[i].x, like[i].y);
        addEdge(like[i].y, like[i].x);
        addEdge(like[i].x + n, like[i].y + n);
        addEdge(like[i].y + n, like[i].x + n);
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
    for(int i = 1; i <= n + n; i++)
        if(!dfn[i]) Tarjan(i);

    for(int i = 1; i <= n; i++)
        if(belong[i] == belong[i + n]) return false;
    return true;
}

int solve(){
    int l = -1, r = 4000001, mid;
    while(r - l > 1){
        mid = (l + r) >> 1;
        buildGraph(mid);
        if(gao()) r = mid;
        else l = mid;
    }
    if(l == 4000000) return -1;
    return r;
}
 
int main(){
    while(scanf("%d%d%d", &n, &a, &b) != EOF){
        scanf("%d%d%d%d", &s1.x, &s1.y, &s2.x, &s2.y);
        for(int i = 1; i <= n; i++){
            scanf("%d%d", &barn[i].x, &barn[i].y);
            diss12[i][0] = barn[i].getDis(s1), diss12[i][1] = barn[i].getDis(s2);
        }

        for(int i = 0; i < a; i++)
            scanf("%d%d", &hate[i].x, &hate[i].y);

        for(int i = 0; i < b; i++)
            scanf("%d%d", &like[i].x, &like[i].y);

        int ans = solve();
        printf("%d\n", ans);
    }
    return 0;
}
