/*=============================================================================
# Author:           He Shuwei
# Last modified:    2015-07-21 14:56
# Filename:            b.cpp
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
const int MAX_N = 100100;
const int MAX_E = 200200;
const int MAX_INT = (1 << 31) - 1;

struct Edge{
    int v, w, nxt;
};

struct State{
    int v, w;
};

int E_cnt, n, m;
int dis[MAX_N];
bool vis[MAX_N];
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

int bfs1(int s){
    queue < int > que;
    memset(vis, false, sizeof(vis));
    fill(dis, dis + MAX_N, MAX_INT);
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

void bfs2(int s, int ans){
    State top, temp;
    temp.v = s, temp.w = MAX_INT;
    memset(vis, false, sizeof(vis));
    vis[s] = true;
    queue <State> que;
    que.push(temp);
    int beMin = MAX_INT, mi = MAX_INT; 
    int beDep = ans, dx = 0;
    while(!que.empty()){
        top = que.front();
        que.pop();
        vis[top.v] = false;
        if(dis[top.v] != beDep){
            //if(dis[top.v] != beDep - 1) continue;
            beDep = dis[top.v];
            beMin = mi;
            mi = MAX_INT;
            path[dx++] = beMin;
        }
        if(top.w != beMin) continue;
        for(int i = head[top.v]; i + 1; i = edge[i].nxt){
            if(dis[edge[i].v] == dis[top.v] - 1 && mi >= edge[i].w){
                mi = edge[i].w;
                if(!vis[edge[i].v]){
                    temp.v = edge[i].v, temp.w = edge[i].w;
                    que.push(temp);
                    vis[edge[i].v] = true;
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
    //while(scanf("%d%d", &n, &m) != EOF){
        init();
        int u, v, w;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        int ans = bfs1(n);
        bfs2(1, ans);
        printf("%d\n", ans);
        for(int i = 0; i < ans; i++)
            printf("%d%c", path[i], i == ans - 1 ? '\n' : ' ');
    }
    return 0;
}
