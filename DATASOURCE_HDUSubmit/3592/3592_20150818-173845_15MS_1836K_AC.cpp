/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-18 14:07
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
const int MAXN = 1010;
const int MAXE = 20100;

struct Edge{
    int v, w, nxt;
};

int ecnt;
bool vis[MAXN];
Edge edge[MAXE];
long long dis[MAXN];
int head[MAXN], cnt[MAXN];

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

long long SPFA(int src, int n){
    queue <int> que;
    que.push(src);
    vis[src] = true;
    dis[src] = 0;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        vis[u] = false;
        cnt[u]++;
        if(cnt[u] > n) return -1;
        for(int i = head[u]; i + 1; i = edge[i].nxt){
            int v = edge[i].v;
            if(dis[v] > dis[u] + edge[i].w){
                dis[v] = dis[u] + edge[i].w;
                if(!vis[v]){
                    que.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    if(dis[n] == (1 << 29)) return -2;
    return dis[n];
}
 
int main(){
    int n, x, y, t;
    scanf("%d", &t);
    while(t--){
        init();
        scanf("%d%d%d", &n, &x, &y);
        int l, r, c;
        for(int i = 0; i < x; i++){
            scanf("%d%d%d", &l, &r, &c);
            addEdge(l, r, c);
        }
        for(int i = 0; i < y; i++){
            scanf("%d%d%d", &l, &r, &c);
            addEdge(r, l, -c);
        }
        for(int i = 1; i <= n; i++)
            addEdge(i, i - 1, 0);

        printf("%lld\n", SPFA(1, n));
    }
    return 0;
}
