/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-07-26 11:12
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
const int MAXN = 10010;
const int MAXE = 20020;

struct Edge{
    int v, nxt;
};

int E_cnt, cnt, n;
int E[MAXE];
int R[MAXN];
int head[MAXN];
Edge edge[MAXE];
int deepth[MAXE];
int dp[2 * MAXN][20];
int degree[MAXN];

void init(){
    cnt = 1;
    E_cnt = 0;
    memset(R, 0, sizeof(R));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(degree, 0, sizeof(degree));
    memset(deepth, 0, sizeof(deepth));
}

void addEdge(int u, int v){
    edge[E_cnt].v = v;
    edge[E_cnt].nxt = head[u];
    head[u] = E_cnt++;
}

void dfs(int s, int deep){
    E[cnt] = s;
    deepth[cnt++] = deep;
    for(int i = head[s]; i + 1; i = edge[i].nxt){
        dfs(edge[i].v, deep + 1);
        E[cnt] = s;
        deepth[cnt++] = deep;

    }
}

int LCA(int l, int r){
    for(int i = 1; i <= 2 * n - 1; i++)
        dp[i][0] = i;

    for(int j = 1; j < 20; j++)
        for(int i = 1; i <= 2 * n - 1; i++)
           if(i + (1 << j) - 1 <= 2 * n - 1){
               if(deepth[dp[i][j - 1]] < deepth[dp[i + (1 << (j - 1))][j - 1]]) dp[i][j] = dp[i][j - 1];
               else dp[i][j] = dp[i + (1 << (j - 1))][j - 1]; 
           }

    //for(int i = 1; i <= 2 * n - 1; i++){
        //for(int j = 0; j < 4; j++)
            //cerr << dp[i][j] <<" ";
        //cerr << endl;
    //}

    int k = (int)(log(r - l + 1) / log(2.0));
    //cerr<<"1 = "<< dp[l][k] <<", 2 = "<< dp[r - (1 << k) + 1][k] << endl;
    return E[min(dp[l][k], dp[r - (1 << k) + 1][k])];
}
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        init();
        scanf("%d", &n);
        int u, v;
        for(int i = 1; i < n; i++){
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            degree[v]++;

        }
        scanf("%d%d", &u, &v);
        int s = 0;
        for(int i = 1; i <= n; i++)
            if(!degree[i]) s = i;

        //cerr <<"s = "<< s << endl;

        dfs(s, 1);

        //for(int i = 1; i <= 2 * n - 1; i++)
            //cerr <<"i = "<< i <<", E[i] = "<< E[i] << endl;
        //cerr << endl;

        //for(int i = 1; i <= 2 * n - 1; i++)
            //cerr <<"i = "<< i <<", E[i] = "<< E[i] <<", deepth[i] = "<< deepth[i] << endl;

        for(int i = 1; i <= 2 * n - 1; i++)
            if(!R[E[i]]) R[E[i]] = i;

        //for(int i = 1; i <= n; i++)
            //cerr <<"i = "<< i <<", R[i] = "<< R[i] << endl;

        int l = R[u], r = R[v];
        if(l > r) swap(l, r);
        //cerr <<"l = "<< l <<", r = "<< r << endl;
        int ans = LCA(l, r);
        printf("%d\n", ans);
    }
    return 0;
}
