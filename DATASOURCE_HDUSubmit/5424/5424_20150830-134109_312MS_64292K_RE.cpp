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
const int MAXN = 1050;

int deepth;
vector <int> edge[MAXN];
int degree[MAXN], par[MAXN];

void init(){
    for(int i = 0; i < MAXN; i++){
        degree[i] = 0;
        par[i] = i;
        edge[i].clear();
    }
}

int Find(int x){
    if(par[x] != x) par[x] = Find(par[x]);
    return par[x];
}

void Union(int x, int y){
    int fx = Find(x);
    int fy = Find(y);
    if(fx == fy) return;
    par[fx] = fy;
}

void dfs(int u, int fa, int dep){
    deepth = max(deepth, dep);
    int size = edge[u].size();
    for(int i = 0; i < size; i++){
        int v = edge[u][i];
        if(v == u || v == fa) continue;
        dfs(v, u, dep + 1);
    }
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        init();
        int u, v;
        if(n == 1){
            printf("YES\n");
            continue;
        }
        for(int i = 0; i < n; i++){
            scanf("%d%d", &u, &v);
            edge[u].push_back(v);
            edge[v].push_back(u);
            degree[u]++, degree[v]++;
            Union(u, v);
        }

        bool flag = true;
        for(int i = 1; i <= n; i++)
            if(degree[i] == 1){
                deepth = 0;
                dfs(i, -1, 1);
                break;
            }

        int fa = Find(1);
        for(int i = 2; i <= n; i++)
            if(fa != Find(i)) flag = false;

        if(deepth != n) flag = false;

        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
