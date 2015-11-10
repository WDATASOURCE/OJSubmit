/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-10 15:55
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
const int MAXN = 30030;
const int MAXE = 150500;

struct Edge{
    int v, nxt;
};

struct Sedge{
    int v, w, nxt;
};

Edge edge[MAXE];
stack <int> sta;
bool instack[MAXN];
int n, m, tdfn, scc_cnt, ecnt;
int head[MAXN], dfn[MAXN], low[MAXN], belong[MAXN], val[MAXN], cutval[MAXN], In[MAXN], Out[MAXN];

int scnt, src;
bool vis[MAXN];
Sedge sedge[MAXE];
int shead[MAXN], dis[MAXN]; 

void init(){
    memset(In, 0, sizeof(In));
    memset(Out, 0, sizeof(Out));
    memset(dfn, 0, sizeof(dfn));
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    memset(low, 0, sizeof(low));
    memset(edge, 0, sizeof(edge));
    while(!sta.empty()) sta.pop();
    memset(head, -1, sizeof(head));
    memset(sedge, 0, sizeof(sedge));
    memset(shead, -1, sizeof(shead));
    memset(belong, 0, sizeof(belong));
    memset(cutval, 0, sizeof(cutval));
    tdfn = scc_cnt = ecnt = scnt = 0;
}

void addEdge(int u, int v){
    edge[ecnt].v = v;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void addEdge(int u, int v, int w){
    sedge[scnt].v = v;
    sedge[scnt].w = w;
    sedge[scnt].nxt = shead[u];
    shead[u] = scnt++;
}

void Tarjan(int u){
    sta.push(u);
    instack[u] = true;
    dfn[u] = low[u] = ++tdfn;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        if(!dfn[v]){
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }else if(instack[v]) low[u] = min(low[u], low[v]);
    }
    if(low[u] == dfn[u]){
        scc_cnt++;
        int top;
        do{
            top = sta.top();
            sta.pop();
            instack[top] = false;
            belong[top] = scc_cnt;
            if(val[top] >= 0) cutval[scc_cnt] += val[top];
        }while(u != top && !sta.empty());
    }
}

void SPFA(int src){
    queue <int> que;
    vis[src] = true;
    que.push(src);
    dis[src] = 0;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        vis[u] = false;
        for(int i = shead[u]; i + 1; i = sedge[i].nxt){
            int v = sedge[i].v;
            dis[v] = max(dis[v], dis[u] + sedge[i].w);
            if(vis[v]) continue;
            que.push(v);
            vis[v] = true;
        }
    }
}

int solve(){
    for(int i = 0; i < n; i++)
        if(!dfn[i]) Tarjan(i);

    for(int u = 0; u < n; u++)
        for(int i = head[u]; i + 1; i = edge[i].nxt){
            int v = edge[i].v;
            if(belong[u] != belong[v]) In[belong[v]]++, Out[belong[u]]++;
        }

    for(int u = 0; u < n; u++)
        for(int i = head[u]; i + 1; i = edge[i].nxt)
            if(belong[u] != belong[edge[i].v]) addEdge(belong[u], belong[edge[i].v], cutval[belong[edge[i].v]]);

    src = 0;
    for(int i = 1; i <= scc_cnt; i++)
        if(!In[i]) addEdge(src, i, cutval[i]);

    //for(int i = 0; i <= scc_cnt; i++){
        //cerr << i <<": ";
        //for(int j = shead[i]; j + 1; j = sedge[j].nxt) 
            //cerr << sedge[j].v <<" ";
        //cerr << endl;
    //}

    SPFA(src);

    //for(int i = 0; i <= scc_cnt; i++)
        //cerr <<"i = "<< i <<", dis[i] = "<< dis[i] << endl;

    int ans = 0;
    for(int i = 0; i <= scc_cnt; i++)
        ans = max(ans, dis[i]);
    return ans;
}
 
int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        for(int i = 0; i < n; i++)
            scanf("%d", &val[i]);
        int u, v;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }

        int ans = solve();
        printf("%d\n", ans);
    }
    return 0;
}
