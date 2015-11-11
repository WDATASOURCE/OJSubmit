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
bool vis[MAXN];
int degree[MAXN];
vector <int> edge[MAXN];

void init(){
    for(int i = 0; i < MAXN; i++){
        deepth = 0;
        vis[i] = false;
        degree[i] = 0;
        edge[i].clear();
    }
}

void dfs(int u, int dep){
    vis[u] = true;
    deepth = max(deepth, dep);
    int size = edge[u].size();
    for(int i = 0; i < size; i++){
        int v = edge[u][i];
        if(vis[v]) continue;
        dfs(v, dep + 1);
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
        }

        int i;
        for(i = 1; i <= n; i++)
            if(degree[i] == 1 || !degree[i]){
                dfs(i, 1);
                break;
            }

        if(i == n + 1) deepth = n;
        if(deepth == n) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
