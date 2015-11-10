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
Edge edge[2 * MAXN];
int a, adep, b, bdep;
long long res;

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

void dfs1(int u, int fa, int dep){
    if(dep >= adep){
        a = u;
        adep = dep;
    }
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        if((fa ^ 1) == i) continue;
        dfs1(edge[i].v, i, dep + 1);
    }
}

void dfs2(int u, int fa, int dep){
    if(dep >= bdep){
        b = u;
        bdep = dep;
    }
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        if((fa ^ 1) == i) continue;
        dfs2(edge[i].v, i, dep + 1);
    }
}

void dfs(int u, int fa, long long sum){
    if(u == b){ 
        res = sum;
        return;
    }
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        if(fa == edge[i].v) continue;
        dfs(edge[i].v, u, sum + edge[i].w);
    }
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

        adep = bdep = 0;
        dfs1(1, -1, 0);
        dfs2(a, -1, 0);

        //cerr <<"a ="<< a <<", b = "<< b 

        res = 0;
        dfs(a, -1, 0);

        //cerr <<"ans = "<< ans <<", res = "<< res << endl;

        printf("%lld\n", ans * 2 - res);
    }
    return 0;
}
