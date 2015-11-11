/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-09-05 15:22
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
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int MAXN = 300100;

struct Edge{
    int v, nxt;
};

int head[MAXN];
Edge edge[MAXN * 2];
int n, q, ecnt, pcnt;

int dp[2 * MAXN][20], first[2 * MAXN], dfn[2 * MAXN], deepth[2 * MAXN];

void init(){
    pcnt = ecnt = 0;
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(first, 0, sizeof(first));
}

void addEdge(int u, int v){
    edge[ecnt].v = v;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void dfs(int u, int fa, int dep){
    dfn[++pcnt] = u;
    first[u] = pcnt;
    deepth[pcnt] = dep;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        if(v == fa) continue;
        dfs(v, u, dep + 1);
        dfn[++pcnt] = u;
        deepth[pcnt] = dep;
    }
}

void ST(){
    for(int i = 1; i <= pcnt; i++)
        dp[i][0] = i;

    for(int j = 1; j < 20; j++)
        for(int i = 1; i + (1 << j) - 1 <= pcnt; i++){
            int a = dp[i][j - 1], b = dp[i + (1 << (j - 1))][j - 1];
            if(deepth[a] < deepth[b]) dp[i][j] = a;
            else dp[i][j] = b;
        }
}

int RMQ(int l, int r){
    int k = log((double)(r - l + 1)) / log(2.0);
    int a = dp[l][k], b = dp[r - (1 << k) + 1][k];
    if(deepth[a] < deepth[b]) return a;
    else return b;
}

int LCA(int L, int R){
    int l = first[L];
    int r = first[R];
    if(l > r) swap(l, r);
    int pos = RMQ(l, r);
    return dfn[pos];
}

int main(){
    while(scanf("%d", &n) != EOF){
        init();
        int u, v;
        for(int i = 1; i < n; i++){
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }

        dfs(1, -1, 0);
        ST();
        
        int l, r;
        scanf("%d", &q);
        for(int i = 1; i <= q; i++){
            scanf("%d%d", &l, &r);
            printf("%d\n", LCA(l, r));
        }
    }
    return 0;
}
