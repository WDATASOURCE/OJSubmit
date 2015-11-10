/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-07-21 20:22
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
const int MAXN = 30030;
const int MAXM = 150010;
const int INF = ((1 << 31) - 1);

struct Edge{
    int v, w, nxt;
};

int n, m, E_cnt;
//int cnt[MAXN];
int vis[MAXN];
int dis[MAXN];
int head[MAXN];
Edge edge[MAXM];

void init(){
    E_cnt = 0;
    //memset(cnt, 0, sizeof(cnt));
    memset(head, -1, sizeof(head));
    memset(edge, 0, sizeof(edge));
    fill(dis, dis + MAXN, INF);
}

void addEdge(int u, int v, int w){
    edge[E_cnt].v = v;
    edge[E_cnt].w = w;
    edge[E_cnt].nxt = head[u];
    head[u] = E_cnt++;
}

void spfa(int s){
    stack <int> sta;
    sta.push(s);
    vis[s] = true;
    dis[s] = 0;
    while(!sta.empty()){
        int top = sta.top();
        sta.pop();
        vis[top] = false;
        for(int i = head[top]; i + 1; i = edge[i].nxt){
            if(dis[edge[i].v] > dis[top] + edge[i].w){
                dis[edge[i].v] = dis[top] + edge[i].w;
                if(!vis[edge[i].v]){
                    sta.push(edge[i].v);
                    vis[edge[i].v] = true;
                }
            }
        }
    }
}
 
int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        int u, v, w;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
        }
        spfa(1);
        printf("%d\n", dis[n]);
    }
    return 0;
}
