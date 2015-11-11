/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-08 10:44
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
const int MAXN = 20020;
const int MAXE = 100010;

struct Edge{
    int v, nxt;
};

bool vis[MAXN];
Edge edge[MAXE], redge[MAXE];
int n, m, ecnt, recnt, vs_cnt, scc_cnt;
int head[MAXN], rhead[MAXN], vs[MAXN], belong[MAXN], In[MAXN], Out[MAXN];
 

void init(){
    ecnt = recnt = vs_cnt = scc_cnt = 0;
    memset(In, 0, sizeof(In));
    memset(Out, 0, sizeof(Out));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(redge, 0, sizeof(redge));
    memset(rhead, -1, sizeof(rhead));
}

void addEdge(int *head, Edge *edge, int u, int v, int &cnt){
    edge[cnt].v = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}

void dfs(int u){
    vis[u] = true;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        if(!vis[edge[i].v]) dfs(edge[i].v);
    }
    vs[vs_cnt++] = u;
}

void rdfs(int u, int k){
    vis[u] = true;
    belong[u] = k;
    for(int i = rhead[u]; i + 1; i = redge[i].nxt){
        if(!vis[redge[i].v]) rdfs(redge[i].v, k);
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

void calDegree(){
    for(int u = 1; u <= n; u++){
        for(int i = head[u]; i + 1; i = edge[i].nxt){
            int v = edge[i].v;
            if(belong[u] != belong[v]) In[belong[v]]++, Out[belong[u]]++;
        }
    }
}

int solve(){

    scc();

    calDegree();

    //cerr <<"scc_cnt = "<< scc_cnt << endl;

    int inNum = 0, outNum = 0; 
    for(int i = 0; i < scc_cnt; i++){
        if(!In[i]) inNum++;
        if(!Out[i]) outNum++;
    }

    return max(inNum, outNum);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        init();
        scanf("%d%d", &n, &m);
        int u, v;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            addEdge(head, edge, u, v, ecnt);
            addEdge(rhead, redge, v, u, recnt);
        }

        int ans = solve();
        printf("%d\n", ans);
    }
    return 0;
}
