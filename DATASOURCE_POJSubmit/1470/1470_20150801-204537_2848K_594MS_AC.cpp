/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-01 18:01
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
const int MAXN = 50050;
const int MAX_INT = (1 << 29);

struct Edge{
    int v, nxt;
};

int R[MAXN];
int res[MAXN];
bool vis[MAXN];
int head[MAXN];
int E[2 * MAXN];
int degree[MAXN];
Edge edge[2 * MAXN];
int depth[2 * MAXN];
int dp[2 * MAXN][20];
int cnt, E_cnt, n, q;

void init(){
    cnt = E_cnt = 0;
    memset(R, 0, sizeof(R));
    memset(vis, 0, sizeof(vis));
    memset(res, 0, sizeof(res));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(depth, 0, sizeof(depth));
    memset(degree, 0, sizeof(degree));
}

void addEdge(int u, int v){
    edge[E_cnt].v = v;
    edge[E_cnt].nxt = head[u];
    head[u] = E_cnt++;
}

void ST(){
    for(int i = 0; i <= cnt; i++)
        dp[i][0] = i;
    for(int j = 1; j < 20; j++)
        for(int i = 0; i <= cnt; i++)
            if(i + (1 << j) - 1 <= cnt){
                int a = dp[i][j - 1], b = dp[i + (1 << (j - 1))][j - 1];
                if(depth[a] < depth[b]) dp[i][j] = a;
                else dp[i][j] = b;
            }
}

int RMQ(int l, int r){
    int k = (int)(log((double)(r - l + 1)) / log(2.0));
    int a = dp[l][k], b = dp[r - (1 << k) + 1][k];
    if(depth[a] < depth[b]) return a;
    else return b;
}

int LCA(int u, int v){
    int l = R[u], r = R[v];
    if(l > r) swap(l, r);
    int pos = RMQ(l, r);
    return E[pos];
}

void dfs(int u, int dep){
    E[++cnt] = u;
    R[u] = cnt;
    depth[cnt] = dep;
    vis[u] = true;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        if(vis[edge[i].v]) continue;
        dfs(edge[i].v, dep + 1);
        E[++cnt] = u;
        depth[cnt] = dep;
    }
}

int main(){
    while(scanf("%d", &n) != EOF){
        init();
        int u, v, num;
        for(int j = 0; j < n; j++){
            scanf("%d:(%d)", &u, &num);
            for(int i = 0; i < num; i++){
                scanf("%d", &v);
                //cerr <<"u = "<< u <<", v = "<< v << endl;
                addEdge(u, v);
                degree[v]++;
            }
        }

        int s = 0;
        for(int i = 1; i <= n; i++)
            if(!degree[i]) s = i;

        dfs(s, 1);
        ST();
        scanf("%d", &q);
        int a, b;
        for(int i = 0; i < q; i++){
            scanf(" (%d %d)", &a, &b);
            res[LCA(a, b)]++;
        }
        for(int i = 1; i <= n; i++)
            if(res[i]) printf("%d:%d\n", i, res[i]);
    }
    return 0;
}
