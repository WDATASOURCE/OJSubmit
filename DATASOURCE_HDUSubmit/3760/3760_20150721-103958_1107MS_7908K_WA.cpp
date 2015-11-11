/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-07-20 14:32
# Filename:         a.cpp
# Description: 
=============================================================================*/
 
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
const int MAX_N = 100100;
const int MAX_E = 200200;
const int MAX_INT = (1 << 31) - 1;

struct Edge{
    int v, w, nxt;
};

struct Node{
    int v, w, deepth;
};

int E_cnt, n, m;
int dis[MAX_N];
bool vis[MAX_N];
Node sta[MAX_N];
int path[MAX_N];
int head[MAX_N];
Edge edge[2 * MAX_E];

void init(){
    E_cnt = 0;
    memset(head, -1, sizeof(head));
    memset(edge, 0, sizeof(edge));
    memset(vis, false, sizeof(vis));
}

void addEdge(int u, int v, int w){
    edge[E_cnt].v = v;
    edge[E_cnt].w = w;
    edge[E_cnt].nxt = head[u];
    head[u] = E_cnt++;
}

int spfa(int s){
    queue < int > que;
    memset(vis, false, sizeof(vis));
    fill(dis, dis + MAX_N, (1 << 29));
    vis[s] = true;
    dis[s] = 0;
    que.push(s);
    while(!que.empty()){
        int top = que.front();
        que.pop();
        vis[top] = false;
        for(int i = head[top]; i + 1; i = edge[i].nxt){
            if(dis[edge[i].v] > dis[top] + 1){
                dis[edge[i].v] = dis[top] + 1;
                if(!vis[edge[i].v]){
                    que.push(edge[i].v);
                    vis[edge[i].v] = true;
                }
            }
        }
    }
    return dis[1];
}

void spfa2(int s, int ans){
    queue < pair <int, int > > que;
    memset(vis, false, sizeof(vis));
    pair <int, int> pir, temp, top;
    pir = make_pair(s, MAX_INT);
    que.push(pir);
    int dx = 0;
    vis[s] = true;
    int beDep = ans;
    int beMin = MAX_INT;
    int mi = MAX_INT;
    while(!que.empty()){
        top = que.front();
        que.pop();
        vis[top.first] = false;
        if(dis[top.first] != beDep){
            if(dis[top.first] != beDep - 1) continue;
            beMin = mi;
            mi = MAX_INT;
            beDep = dis[top.first];
            path[dx++] = beMin;
        }
        if(beMin != top.second) continue;
        for(int i = head[top.first]; i + 1; i = edge[i].nxt){
            if(dis[edge[i].v] == dis[top.first] - 1 && mi >= edge[i].w){
                mi = edge[i].w;
                if(!vis[edge[i].v]){
                    vis[edge[i].v] = true;
                    temp = make_pair(edge[i].v, edge[i].w);
                    que.push(temp);
                }
            }
        }
    }
}
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        init();
        int u, v, w;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        int ans = spfa(n);
        spfa2(1, ans);
        printf("%d\n", ans);
        //path[1] = MAX_INT;
        for(int i = 0; i < ans; i++)
            printf("%d%c", path[i], i == ans - 1 ? '\n' : ' ');
    }
    return 0;
}
