/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-17 08:00
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
const int MAXN = 50050;
const int MAXE = 100010;

struct Edge{
    int v, nxt, w;
};

bool vis[MAXN];
Edge edge[MAXN];
int n, l, r, ecnt;
int head[MAXN], dis[MAXN];

void init(){
    l = (1 << 29);
    r = -1;
    ecnt = 0;
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

void SPFA(int src){
    dis[src] = 0;
    queue <int> que;
    que.push(src);
    vis[src] = true;
 
    while(!que.empty()){
        int u = que.front();
        que.pop();
        vis[u] = false;
        //cerr <<"u = "<< u << endl;
        for(int i = head[u]; i + 1; i = edge[i].nxt){
            int v = edge[i].v;
            dis[v] = min(dis[v], dis[u] + edge[i].w);
            if(!vis[v]){
                que.push(v);
                vis[v] = true;
            }
        }
    }
}

int main(){
    while(~scanf("%d", &n)){
        init();
        int a, b, c;
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &a, &b, &c);
            addEdge(a, b + 1, c);
            l = min(l, a);
            r = max(r, b);
        }

        for(int i = 1; i <= r; i++){
            addEdge(i, i + 1, 1);
            //addEdge(i + 1, i, -1);
        }

        SPFA(l);

        printf("%d\n", dis[r + 1]);
    }
 
    return 0;
}
