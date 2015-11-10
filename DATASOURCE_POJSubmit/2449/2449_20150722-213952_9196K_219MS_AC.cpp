/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-07-21 21:11
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
const int MAXN = 1010;
const int MAXM = 100100;
const int MAX_INT = ((1 << 29) - 1);

struct Edge{
    int v, w, nxt;
    
    //Edge(int v, int w, int nxt): v(v), w(w), nxt(nxt) {}
};

struct State{
    int v, w, dis;

    //State(int v, int w, int dis): v(v), w(w), dis(dis) {}

    friend bool operator < (const State &a, const State &b){
        return a.w + a.dis > b.w + b.dis;
    }
};

int dis[MAXN];
int head[MAXN];
int rhead[MAXN];
bool vis[MAXN];
Edge edge[MAXM];
Edge redge[MAXM];
int n, m, s, t, k, E_cnt;
int rE_cnt;

void init(){
    rE_cnt = E_cnt = 0;
    memset(head, -1, sizeof(head));
    memset(rhead, -1, sizeof(rhead));
    memset(edge, 0, sizeof(edge));
    memset(redge, 0, sizeof(redge));
    memset(vis, 0, sizeof(vis));
    fill(dis, dis + MAXN, MAX_INT);
}

void addEdge(int u, int v, int w){
    edge[E_cnt].v = v;
    edge[E_cnt].w = w;
    edge[E_cnt].nxt = head[u];
    head[u] = E_cnt++;
}

void raddEdge(int u, int v, int w){
    redge[rE_cnt].v = v;
    redge[rE_cnt].w = w;
    redge[rE_cnt].nxt = rhead[u];
    rhead[u] = rE_cnt++;
}

void Dij(int s){
    memset(vis, false, sizeof(vis));
    fill(dis, dis + MAXN, MAX_INT);
    State top, temp;
    temp.v = s, temp.w = 0, temp.dis = 0;
    priority_queue <State> que;
    que.push(temp);
    dis[s] = 0;
    while(!que.empty()){
        top = que.top();
        que.pop();
        if(vis[top.v]) continue;
        vis[top.v] = true;
        for(int i = rhead[top.v]; i + 1; i = redge[i].nxt){
            if(dis[redge[i].v] > dis[top.v] + redge[i].w){
                dis[redge[i].v] = dis[top.v] + redge[i].w;
                temp.v = redge[i].v, temp.w = dis[redge[i].v], temp.dis = 0;
                que.push(temp);
            }
        }
    }
}

int AStar(int s, int t, int k){
    if(s == t) k++;
    if(dis[s] == MAX_INT) return -1;
    priority_queue <State> que;
    memset(vis, 0, sizeof(vis));
    State top, temp;
    temp.v = s, temp.w = 0, temp.dis = dis[temp.v];
    que.push(temp);
    while(!que.empty()){
        top = que.top();
        que.pop();
        if(top.v == t){
            k--;
            if(!k) return top.w;
        }
        for(int i = head[top.v]; i + 1; i = edge[i].nxt){
            temp.v = edge[i].v, temp.w = top.w + edge[i].w, temp.dis = dis[temp.v];
            que.push(temp);
        }
    }
    return -1;
}
 
int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        int u, v, w;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            raddEdge(v, u, w);
        }
        scanf("%d%d%d", &s, &t, &k);
        Dij(t);
        int ans = AStar(s, t, k);
        printf("%d\n", ans);
    }
    return 0;
}
