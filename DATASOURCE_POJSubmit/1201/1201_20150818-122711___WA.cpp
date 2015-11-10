/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-18 09:28
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
const int MAXN = 50010;
const int MAXE = 60010;

struct Edge{
    int v, w, nxt;
};

int n, m, ecnt;
bool vis[MAXN];
Edge edge[MAXE];
long long sum[MAXN], dis[MAXN];
int head[MAXN], val[MAXN], cnt[MAXN];

void init(){
    ecnt = 0;
    memset(cnt, 0, sizeof(cnt));
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
    queue <int> que;
    que.push(src);
    vis[src] = true;
    dis[src] = 0;
    int u, v;
    while(!que.empty()){
        u = que.front();
        que.pop();
        vis[u] = false;
        cnt[u]++;
        if(cnt[u] > n) return false;
        for(int i = head[u]; i + 1; i = edge[i].nxt){
            v = edge[i].v;
            if(dis[v] > dis[u] + edge[i].w){
                dis[v] = dis[u] + edge[i].w;
                if(!vis[v]){
                    que.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return true;
}
 
int main(){
    while(scanf("%d", &n) != EOF){
        init();
        int l, r, w, s = 50050, t = 0;
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &l, &r, &w);
            l++, r++;
            addEdge(r, l - 1, -w);
            s = min(s, l);
            t = max(t, r);
        }

        for(int i = s; i <= t; i++){
            addEdge(i - 1, i, 1);
            addEdge(i, i - 1, 0);
        }

        if(SPFA(t)) printf("%lld\n", -dis[s]);
        else printf("0\n");

    }
    return 0;
}
