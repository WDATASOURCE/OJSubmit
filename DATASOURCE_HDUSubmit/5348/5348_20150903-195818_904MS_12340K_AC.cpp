/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-09-03 12:34
# Filename:         b.cpp
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
#define ll long long
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
const int MAXN = 100100;

struct Edge{
    int v, nxt, id, state;
};

int ecnt, n, m;
Edge edge[6 * MAXN];
int head[MAXN], degree[MAXN];
bool vis[3 * MAXN], ans[3 * MAXN];

void init(){
    ecnt = 0;
    memset(vis, 0, sizeof(vis));
    memset(ans, 0, sizeof(ans));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(degree, 0, sizeof(degree));
}

void addEdge(int u, int v, int id, int state){
    edge[ecnt].v = v;
    edge[ecnt].id = id;
    edge[ecnt].state = state;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

//Èë +  ³ö -
void dfs(int u, int fx){
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        int id = edge[i].id;
        if(vis[id]){
            head[u] = edge[i].nxt;
            continue;
        }
        vis[id] = true;
        if(degree[u] != -1 && degree[v] != 1 && fx != 2){
            degree[u]--;
            degree[v]++;
            ans[id] = edge[i].state;
            head[u] = edge[i].nxt;
            dfs(v, 1);
        }else if(degree[u] != 1 && degree[v] != -1 && fx != 1){
            degree[u]++;
            degree[v]--;
            ans[id] = !edge[i].state;
            head[u] = edge[i].nxt;
            dfs(v, 2);
        }else continue;
        break;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        init();
        scanf("%d%d", &n, &m);
        int u, v;
        for(int i = 1; i <= m; i++){
            scanf("%d%d", &u, &v);
            if(u == v) continue;
            addEdge(u, v, i, 1);
            addEdge(v, u, i, 0);
        }

        for(int i = 1; i <= n; i++)
            while(head[i] != -1) dfs(i, 0);

        for(int i = 1; i <= m; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}
