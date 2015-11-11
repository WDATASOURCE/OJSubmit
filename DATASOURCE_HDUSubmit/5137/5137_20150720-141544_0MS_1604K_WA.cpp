/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-07-20 13:19
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

struct Node{
    int v, w, nxt;
};

int dis[50];
bool vis[50];
Node node[2010];
int head[50], E_cnt;
int n, m;

void init(){
    E_cnt = 0;
    memset(head, -1, sizeof(head));
    memset(node, 0, sizeof(node));
}

void addEdge(int u, int v, int w){
    node[E_cnt].v = v;
    node[E_cnt].w = w;
    node[E_cnt].nxt = head[u];
    head[u] = E_cnt++;
}

int spfa(int s, int d){
    fill(dis, dis + 50, (1 << 29));
    fill(vis, vis + 50, false);
    queue <int> que;
    vis[1] = true;
    vis[d] = true;
    que.push(s);
    dis[s] = 0;
    while(!que.empty()){
        int top = que.front();
        que.pop();
        vis[top] = false;
        if(top == d) continue;
        for(int i = head[top]; i + 1; i = node[i].nxt){
            if(node[i].v == d) continue;
            if(dis[node[i].v] > dis[top] + node[i].w){
                dis[node[i].v] = dis[top] + node[i].w;
                if(!vis[node[i].v]){
                    que.push(node[i].v);
                    vis[node[i].v] = true;
                }
            }
        }
    }
    return dis[n];
}
 
int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        if(!(n + m)) break;
        init();
        int u, v, w;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        int ans = -1;
        for(int i = 2; i < n; i++){
            int temp = spfa(1, i);
            if(temp >= (1 << 29)) continue;
            ans = max(ans, temp);
        }

        if(ans == -1) printf("Inf\n");
        else printf("%d\n", ans);
    }
    return 0;
}
