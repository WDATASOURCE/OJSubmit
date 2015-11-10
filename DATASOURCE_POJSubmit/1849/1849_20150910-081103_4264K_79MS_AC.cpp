/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-09-09 21:50
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
const int MAXN = 100100;

struct Edge{
    int v, w, nxt;
};

int ecnt, n, m;
int head[MAXN];
long long dis[MAXN];
Edge edge[2 * MAXN];

void init(){
    ecnt = 0;
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v, int w){
    edge[ecnt].v = v;
    edge[ecnt].w = w;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

int bfs(int s){
    dis[s] = 0;
    queue <int> que;
    que.push(s);
    int res = 0, resdep = 0;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(int i = head[u]; i + 1; i = edge[i].nxt){
            int v = edge[i].v;
            if(dis[v] == -1){
                dis[v] = dis[u] + edge[i].w;
                que.push(v);
                if(resdep <= dis[v]){
                    resdep = dis[v];
                    res = v;
                }
            }
        }
    }
    return res;
}

long long solve(){
    memset(dis, -1, sizeof(dis));
    int s = bfs(1);
    memset(dis, -1, sizeof(dis));
    int t = bfs(s);

    return dis[t];
}

int main(){
    while(~scanf("%d%d", &n, &m)){
        init();
        int u, v, w;
        long long ans = 0;
        for(int i = 1; i < n; i++){
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
            ans += w;
        }

        int res = solve();
        printf("%lld\n", ans * 2 - res);
    }
    return 0;
}
