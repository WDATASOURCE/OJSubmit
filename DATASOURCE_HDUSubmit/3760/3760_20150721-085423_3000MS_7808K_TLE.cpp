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

struct Edge{
    int v, w, nxt;
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
    queue < pair<int, int> > que;
    memset(vis, false, sizeof(vis));
    fill(dis, dis + MAX_N, (1 << 29));
    vis[s] = true;
    dis[s] = 0;
    pair<int, int> pir, temp;
    pir = make_pair(s, 0);
    que.push(pir);
    while(!que.empty()){
        pir = que.front();
        que.pop();
        int top = pir.first;
        int num = pir.second;
        for(int i = head[top]; i + 1; i = edge[i].nxt){
            if(vis[edge[i].v]) continue;
            vis[edge[i].v] = true;
            dis[edge[i].v] = num + 1;
            temp = make_pair(edge[i].v, num + 1);
            que.push(temp);
        }
    }
    return dis[1];
}

void bfs2(int s, int ans){
    int dx = 0;
    queue < int > que;
    queue < pair<int, int> > sta;
    que.push(s);
    while(dx < ans){
        int mi = (1 << 29);
        while(!que.empty()){
            int top = que.front();
            que.pop();
            for(int i = head[top]; i + 1; i = edge[i].nxt)
                if(dis[edge[i].v] == ans - dx - 1 && mi >= edge[i].w){
                    mi = edge[i].w;
                    sta.push(pair<int, int>(edge[i].v, mi));
                }
        }
        path[dx++] = mi;
        while(!sta.empty()){ 
            if(sta.front().second == mi) que.push(sta.front().first);
            sta.pop();
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
        int ans = bfs1(n);
        bfs2(1, ans);
        printf("%d\n", ans);
        for(int i = 0; i < ans; i++)
            printf("%d%c", path[i], i == ans - 1 ? '\n' : ' ');
    }
    return 0;
}
