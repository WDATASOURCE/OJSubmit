/*=============================================================================
# Author:           He Shuwei
# Last modified:	2015-07-21 14:56
# Filename:			b.cpp
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
int mmin[MAX_N];
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

void bfs2(int s){
    State temp, top;
    queue <State> que;
    fill(path, path + MAX_N, MAX_INT);
    fill(mmin, mmin + MAX_N, MAX_INT);
    temp.v = s;
    temp.w = 0;
    que.push(temp);
    while(!que.empty()){
        top = que.front();
        que.pop();
        int deepth = dis[top.v];
        if(top.w > path[deepth]) continue;
        for(int i = head[top.v]; i + 1; i = edge[i].nxt){
            temp.v = edge[i].v;
            temp.w = edge[i].w;
            if(dis[temp.v] == deepth - 1 && temp.w <= path[deepth - 1]){
                path[deepth - 1] = temp.w;
                if(temp.w < mmin[temp.v]){
                    mmin[temp.v] = temp.w;
                    que.push(temp);
                }
            }
        }
    }
}
 
int main(){
    int t;
    //scanf("%d", &t);
    //while(t--){
        //scanf("%d%d", &n, &m);
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        int u, v, w;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        int ans = bfs1(n);
        bfs2(1);
        printf("%d\n", ans);
        for(int i = ans - 1; i >= 0; i--)
            printf("%d%c", path[i], i == 0 ? '\n' : ' ');
    }
    return 0;
}
