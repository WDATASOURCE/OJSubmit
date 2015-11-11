/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-09-01 11:57
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
const int MAXN = 110;

struct Edge{
    int v, nxt;
};

int ecnt;
Edge edge[MAXN];
int head[MAXN], dp[MAXN], degree[MAXN];

void init(){
    ecnt = 0;
    memset(dp, 0, sizeof(dp));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(degree, 0, sizeof(degree));
}

void addEdge(int u, int v){
    edge[ecnt].v = v;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void dfs(int u){
    dp[u] = 0;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        dfs(v);
        dp[u] += (dp[v] + 1);
    }
}
 
int main(){
    int n, k;
    while(scanf("%d%d", &n, &k) != EOF){
        init();
        int u, v;
        for(int i = 1; i < n; i++){
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            degree[v]++;
        }

        u = 1;
        for(int i = 1; i <= n; i++)
            if(degree[u] == 0){ u = i; break;}

        dfs(u);

        int ans = 0;
        for(int i = 1; i <= n; i ++)
            if(dp[i] == k) ans++;

        printf("%d\n", ans);
    }
 
    return 0;
}