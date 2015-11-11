/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-13 18:52
# Filename:         a.cpp
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
const int MAXE = 100010;
const double eps = 1e-3;

struct Edge{
    int v, nxt;
};

struct Point{
    int x, y;

    double getDis(const Point &a){
        return sqrt((double)((a.x - x) * (a.x - x) + (a.y - y) * (a.y - y)));
    }
};

Edge edge[MAXE];
stack <int> sta;
Point barn[MAXN];
bool instack[MAXN];
int n, m, tdfn, scc_cnt, ecnt, a, b;
int head[MAXN], low[MAXN], dfn[MAXN], belong[MAXN];
double dis11[MAXN][MAXN], dis12[MAXN][MAXN], dis21[MAXN][MAXN], dis22[MAXN][MAXN];

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

void buildGraph(double mid){
    init();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j < i; j++){
            if(dis11[i][j] < mid){
                addEdge(i, j + n);
                addEdge(j, i + n);
            }
            if(dis12[i][j] < mid){
                addEdge(i, j);
                addEdge(j + n, i + n);
            }
            if(dis21[i][j] < mid){
                addEdge(i + n, j + n);
                addEdge(j, i);
            }
            if(dis22[i][j] < mid){
                addEdge(i + n, j);
                addEdge(j + n, i);
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
    for(int i = 1; i <= n + n; i++)
        if(!dfn[i]) Tarjan(i);

    for(int i = 1; i <= n; i++)
        if(belong[i] == belong[i + n]) return false;
    return true;
}

double solve(){
    double l = 0, r = 10001, mid;
    while(r - l > eps){
        mid = (l + r) / 2.0;
        buildGraph(mid * 2);
        if(gao()) l = mid;
        else r = mid;
    }
    return l;
}
 
int main(){
    while(scanf("%d", &n) != EOF){
        for(int i = 1; i <= n; i++){
            scanf("%d%d", &barn[i].x, &barn[i].y);
            scanf("%d%d", &barn[i + n].x, &barn[i + n].y);
        }

        for(int i = 1; i <= n; i++)
            for(int j = 1; j < i; j++){
                dis11[i][j] = barn[i].getDis(barn[j]);
                dis12[i][j] = barn[i].getDis(barn[j + n]);
                dis21[i][j] = barn[i + n].getDis(barn[j]);
                dis22[i][j] = barn[i + n].getDis(barn[j + n]);
            }

        double ans = solve();
        printf("%.2lf\n", ans);
    }
    return 0;
}
