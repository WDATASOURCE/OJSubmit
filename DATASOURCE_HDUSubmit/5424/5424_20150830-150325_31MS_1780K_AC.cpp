/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-08-30 10:33
# Filename:         a.cpp
# Description: 
=============================================================================*/

#include <set>
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
const int MAXN = 2050;

struct Edge{
    int v, nxt;
};

bool flag;
bool vis[MAXN];
Edge edge[MAXN];
int n, deepth, ecnt;
int head[MAXN], degree[MAXN];

void init(){
    ecnt = 0;
    for(int i = 0; i < MAXN; i++){
        deepth = 0;
        head[i] = -1;
        flag = false;
        degree[i] = 0;
        vis[i] = false;
    }
}

void addEdge(int u, int v){
    edge[ecnt].v = v;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void dfs(int u, int dep){
    vis[u] = true;
    deepth = max(deepth, dep);
    if(deepth == n){
        flag = true;
        return;
    }
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        if(!vis[v] && !flag) dfs(v, dep + 1);
    }
    vis[u] = false;
}

int main(){
    while(scanf("%d", &n) != EOF){
        init();
        int u, v;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &u, &v);
            if(u == v) continue;
            addEdge(u, v);
            addEdge(v, u);
            degree[u]++, degree[v]++;
        }

        int s = 1;
        int num = 0;
        for(int i = 1; i <= n; i++)
            if(degree[i] == 1) num++, s = i;

        if(num > 2){
            puts("NO");
            continue;
        }

        dfs(s, 1);

        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
