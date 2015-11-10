/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-18 14:07
# Filename: 		b.cpp
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
const int MAXE = 2010;

struct Edge{
    int v, w, nxt;
};

bool vis[MAXN];
int n, m, ecnt;
Edge edge[MAXE];
int head[MAXN], dis[MAXN], cnt[MAXN];

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
    queue <int> que;
    que.push(src);
    vis[src] = true;
    dis[src] = 0;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        vis[u] = false;
        cnt[u]++;
        if(cnt[u] > n) return false;
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
    return true;
}
 
int main(){
    while(scanf("%d", &n) != EOF){
        init();
        if(!n) break;
        scanf("%d", &m);
        char ch[3];
        int l, r, w;
        for(int i = 0; i < m; i++){
            scanf("%d%d%s%d", &l, &r, ch, &w);
            if(strcmp(ch, "gt") == 0){
                addEdge(l + r, l - 1, -w - 1);
            }else{
                addEdge(l - 1, r + l, w - 1);
            }
        }

        if(SPFA(n)) printf("lamentable kingdom\n");
        else printf("successful conspiracy\n");
    }
    return 0;
}
