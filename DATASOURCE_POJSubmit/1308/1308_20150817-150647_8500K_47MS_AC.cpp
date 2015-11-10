/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-17 14:21
# Filename: 		b.cpp
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
const int MAXN = 1010;
const int MAXE = 1000010;

struct Edge{
    int v, nxt;
};
 
int ecnt;
bool flag;
bool vis[MAXN];
bool use[MAXN];
int head[MAXN];
Edge edge[MAXE];
int degree[MAXN];

void init(){
    ecnt = 0;
    flag = true;
    memset(use, 0, sizeof(use));
    memset(vis, 0, sizeof(vis));
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
    if(vis[u]){ 
        flag = false;
        return;
    }
    vis[u] = true;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        dfs(v);
    }
}

int main(){
    int u, v, T = 0;;
    while(~scanf("%d%d", &u, &v)){
        if(u == -1 && v == -1) break;
        if(!(u + v)){ 
            printf("Case %d is a tree.\n", ++T);
            continue;
        }
        init();
        use[u] = use[v] = true;
        degree[v]++;
        addEdge(u, v);
        while(scanf("%d%d", &u, &v)){
            if(!(u + v)) break;
            addEdge(u, v);
            degree[v]++;
            use[u] = use[v] = true;
        }

        for(int i = 0; i < MAXN; i++)
            if(use[i] && !degree[i]){ 
                dfs(i);
                break;
            }

        for(int i = 0; i < MAXN; i++)
            if(use[i] && !vis[i]) flag = false;

        if(flag) printf("Case %d is a tree.\n", ++T);
        else printf("Case %d is not a tree.\n", ++T);
    }
    return 0;
}
