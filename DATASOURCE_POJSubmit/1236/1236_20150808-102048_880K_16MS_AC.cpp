/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-08 08:39
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
const int MAXN = 110;
const int MAXE = (MAXN * MAXN);

struct Edge{
    int v, nxt;
};

bool vis[MAXN];
Edge edge[MAXE], redge[MAXE];
int ecnt, recnt, scc_cnt, vs_cnt, n;
int head[MAXN], rhead[MAXN], belong[MAXN], vs[MAXN], indegree[MAXN], outdegree[MAXN];

void init(){
    memset(vis, 0, sizeof(vis));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(redge, 0, sizeof(redge));
    memset(rhead, -1, sizeof(rhead));
    memset(indegree, 0, sizeof(indegree));
    memset(outdegree, 0, sizeof(outdegree));
    ecnt = recnt = scc_cnt = vs_cnt = 0;
}

void addEdge(int *head, Edge *edge, int u, int v, int &cnt){
    edge[cnt].v = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}

void dfs(int u){
    vis[u] = true;
    for(int i = head[u]; i + 1; i = edge[i].nxt)
        if(!vis[edge[i].v]) dfs(edge[i].v);
    vs[vs_cnt++] = u;
}

void rdfs(int u, int k){
    vis[u] = true;
    belong[u] = k;
    for(int i = rhead[u]; i + 1; i = redge[i].nxt)
        if(!vis[redge[i].v]) rdfs(redge[i].v, k);
}

void calDegree(){
    for(int u = 1; u <= n; u++){
        for(int i = head[u]; i + 1; i = edge[i].nxt){
            int v = edge[i].v;
            if(belong[u] != belong[v]) indegree[belong[v]]++, outdegree[belong[u]]++;
        }
    }
}

void scc(){
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++)
        if(!vis[i]) dfs(i);

    memset(vis, 0, sizeof(vis));
    for(int i = vs_cnt - 1; i >= 0; i--)
        if(!vis[vs[i]]) rdfs(vs[i], scc_cnt++);
}

void solve(){

    scc();

    calDegree();

    int inNum = 0, outNum = 0;
    for(int i = 0; i < scc_cnt; i++){
        if(!indegree[i]) inNum++;
        if(!outdegree[i]) outNum++;
    }

    if(scc_cnt == 1){
        printf("1\n0\n");
        return;
    }
    printf("%d\n%d\n", inNum, max(inNum, outNum));
}
 
int main(){
    while(scanf("%d", &n) != EOF){
        init();
        int v;
        for(int i = 1; i <= n; i++){
            while(scanf("%d", &v) && v){
                addEdge(head, edge, i, v, ecnt);
                addEdge(rhead, redge, v, i, recnt);
            }
        }

        solve();
    }
    return 0;
}
