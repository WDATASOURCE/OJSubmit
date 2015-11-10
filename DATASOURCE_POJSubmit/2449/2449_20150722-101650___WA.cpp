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
bool vis[MAXN];
Edge edge[MAXN];
int n, m, s, t, k, E_cnt;

void init(){
    E_cnt = 0;
    memset(head, -1, sizeof(head));
    memset(edge, 0, sizeof(edge));
    memset(vis, 0, sizeof(vis));
    fill(dis, dis + MAXN, MAX_INT);
}

void addEdge(int u, int v, int w){
    edge[E_cnt].v = v;
    edge[E_cnt].w = w;
    edge[E_cnt].nxt = head[u];
    head[u] = E_cnt++;
}

void Dij(int s){
    memset(vis, false, sizeof(vis));
    fill(dis, dis + MAXN, MAX_INT);
    State top, temp;
    temp.v = s, temp.w = 0, temp.dis = 0;
    priority_queue <State> que;
    que.push(temp);
    //vis[s] = true;
    dis[s] = 0;
    while(!que.empty()){
        top = que.top();
        que.pop();
        if(vis[top.v]) continue;
        vis[top.v] = true;
        for(int i = head[top.v]; i + 1; i = edge[i].nxt){
            //cerr <<"edge[i].v = "<< edge[i].v << endl;
            //if(vis[edge[i].v]) continue;
            //vis[edge[i].v] = true;
            if(dis[edge[i].v] > dis[top.v] + edge[i].w){
                dis[edge[i].v] = dis[top.v] + edge[i].w;
                temp.v = edge[i].v, temp.w = dis[edge[i].v], temp.dis = 0;
                que.push(temp);
            }
        }
    }
}

int AStar(int s, int t, int k){
    priority_queue <State> que;
    memset(vis, 0, sizeof(vis));
    State top, temp;
    temp.v = s, temp.w = 0, temp.dis = dis[temp.v];
    que.push(temp);
    while(!que.empty()){
        top = que.top();
        que.pop();
        if(top.v == n){
            k--;
            if(!k) return temp.w;
        }
        for(int i = head[top.v]; i + 1; i = edge[i].nxt){
            temp.v = edge[i].v, temp.w = top.w + edge[i].w, temp.dis = dis[temp.v];
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
        Dij(1);
        //for(int i = 0; i <= n; i++)
            //cerr <<"i = "<< i <<", dis[i] = "<< dis[i] << endl;
        if(dis[n] == MAX_INT){
            printf("%d\n", -1);
            //cerr << 22222 << endl;
            continue;
        }
        int ans = AStar(s, t, k);
        printf("%d\n", ans);
    }
    return 0;
}
