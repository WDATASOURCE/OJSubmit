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
const int MAXM = 100010;
const int MAX_INT = ((1 << 29) - 1);

struct Edge{
    int u, v, w, nxt, nxt1;
};

int dis[MAXN];
int head[MAXN];
int rhead[MAXN];
bool vis[MAXN];

struct State{
    int v, w;
    friend bool operator < (const State &a, const State &b){
        return a.w + dis[a.v] > b.w + dis[b.v];
    }
};

Edge edge[MAXM];
int n, m, s, t, k, E_cnt;

void init(){
    E_cnt = 0;
    memset(head, -1, sizeof(head));
    memset(rhead, -1, sizeof(rhead));
    memset(edge, 0, sizeof(edge));
    memset(vis, 0, sizeof(vis));
    fill(dis, dis + MAXN, MAX_INT);
}

void addEdge(int u, int v, int w){
    edge[E_cnt].u = u;
    edge[E_cnt].v = v;
    edge[E_cnt].w = w;
    edge[E_cnt].nxt = head[u];
    head[u] = E_cnt;
    edge[E_cnt].nxt1 = rhead[v];
    rhead[v] = E_cnt++;
}

void Dij(int s){
    memset(vis, false, sizeof(vis));
    fill(dis, dis + MAXN, MAX_INT);
    State top, temp;
    temp.v = s, temp.w = 0;
    priority_queue <State> que;
    que.push(temp);
    dis[s] = 0;
    while(!que.empty()){
        top = que.top();
        que.pop();
        if(vis[top.v]) continue;
        vis[top.v] = true;
        for(int i = rhead[top.v]; i + 1; i = edge[i].nxt1){
            if(dis[edge[i].u] > dis[top.v] + edge[i].w){
                dis[edge[i].u] = dis[top.v] + edge[i].w;
                temp.v = edge[i].u, temp.w = dis[edge[i].v];
                que.push(temp);
            }
        }
    }
}

int AStar(int s, int t, int k){
    priority_queue <State> que;
    memset(vis, 0, sizeof(vis));
    State top, temp;
    temp.v = s, temp.w = 0;
    que.push(temp);
    while(!que.empty()){
        top = que.top();
        que.pop();
        if(top.v == n){
            k--;
            if(!k) return top.w;
        }
        for(int i = head[top.v]; i + 1; i = edge[i].nxt){
            temp.v = edge[i].v, temp.w = top.w + edge[i].w;
            que.push(temp);
        }
    }
    //cerr <<1111 << endl;
    return -1;
}
 
int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        int u, v, w;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
        }
        scanf("%d%d%d", &s, &t, &k);
        Dij(t);
        //for(int i = 0; i <= n; i++)
            //cerr <<"i = "<< i <<", dis[i] = "<< dis[i] << endl;
        if(dis[t] == MAX_INT){
            printf("%d\n", -1);
            continue;
        }
        if(s == t) k++;
        int ans = AStar(s, t, k);
        printf("%d\n", ans);
    }
    return 0;
}
