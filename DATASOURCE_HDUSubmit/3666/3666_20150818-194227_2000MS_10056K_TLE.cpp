/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-18 19:05
# Filename:         b.cpp
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
const int MAXN = 840;
const int MAXE = 161000;

struct Edge{
    int v, nxt;
    double w;
};

int n, m, ecnt;
int cnt[MAXN];
bool vis[MAXN];
int head[MAXN];
Edge edge[MAXE];
double dis[MAXN];

void init(){
    ecnt = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    fill(dis, dis + MAXN, (1 << 29));
}

void addEdge(int u, int v, int w){
    edge[ecnt].v = v;
    edge[ecnt].w = w;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

bool SPFA(int src){
    stack <int> sta;
    vis[src] = true;
    sta.push(src);
    dis[src] = 0;
    while(!sta.empty()){
        int u = sta.top();
        sta.pop();
        vis[u] = false;
        cnt[u]++;
        if(cnt[u] > n + m) return false;
        for(int i = head[u]; i + 1; i = edge[i].nxt){
            int v = edge[i].v;
            if(dis[v] > dis[u] + edge[i].w){
                dis[v] = dis[u] + edge[i].w;
                if(!vis[v]){
                    sta.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return true;
}

int main(){
    double l, r;
    while(scanf("%d%d%lf%lf", &n, &m, &l, &r) != EOF){
        init();
        int v;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                scanf("%d", &v);
                addEdge(j + n, i, log(r / v));
                addEdge(i, j + n, log(v / l));
            }
        if(SPFA(n + m)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
