/*=============================================================================
# Author:			He Shuwei
# Last modified:	2015-08-31 11:22
# Filename:			a.cpp
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
const int MAXN = 550;

struct Edge{
    int v, w, nxt;
}edge[MAXN * MAXN];

stack <int> sta;
bool instack[MAXN];
int n, m, ecnt, tdfn, scc_cnt;
int head[MAXN], low[MAXN], dfn[MAXN], belong[MAXN];

int scnt;
int dis[MAXN];
bool vis[MAXN];
int shead[MAXN];
Edge sedge[MAXN * MAXN];

void init(){
    scc_cnt = ecnt = tdfn = 0;
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    while(!sta.empty()) sta.pop();
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(belong, 0, sizeof(belong));
    memset(instack, 0, sizeof(instack));

    scnt = 0;
    memset(sedge, 0, sizeof(sedge));
    memset(shead, -1, sizeof(shead));
}

void addEdge(int u, int v, int w){
    edge[ecnt].v = v;
    edge[ecnt].w = w;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void addSedge(int u, int v, int w){
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
        }else if(instack[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]){
        int top;
        ++scc_cnt;
        do{
            top = sta.top();
            sta.pop();
            instack[top] = false;
            belong[top] = scc_cnt;
        }while(u != top);
    }
}

void SPFA(int s){
    dis[s] = 0;
    queue <int> que;
    que.push(s);
    vis[s] = true;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        vis[u] = false;
        for(int i = shead[u]; i + 1; i = sedge[i].nxt){
            int v = sedge[i].v;
            //cerr <<"u = "<< u <<", v = "<< v <<", dis[v] = "<< dis[v] << endl;
            if(dis[v] > dis[u] + sedge[i].w){
                //cerr <<"sedge[i].w = "<< sedge[i].w << endl;
                dis[v] = dis[u] + sedge[i].w;
                if(!vis[v]){
                    que.push(v);
                    vis[v] = true;
                }
            }
        }
    }
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        if(!(n + m)) break;
        init();
        int u, v, w;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
        }

        for(int i = 1; i <= n; i++)
            if(!dfn[i]) Tarjan(i);
        for(int u = 1; u <= n; u++)
            for(int i = head[u]; i + 1; i = edge[i].nxt){
                int v = edge[i].v;
                if(belong[v] == belong[u]) continue;
                addSedge(belong[u], belong[v], edge[i].w);
            }

        int q;
        scanf("%d", &q);
        for(int i = 0; i < q; i++){
            scanf("%d%d", &u, &v);
            memset(vis, 0, sizeof(vis));
            fill(dis, dis + MAXN, (1 << 29));
            SPFA(belong[u]);
            if(belong[u] == belong[v]) printf("0\n");
            else if(dis[belong[v]] == (1 << 29)) printf("Nao e possivel entregar a carta\n");
            else printf("%d\n", dis[belong[v]]);
        }
        printf("\n");
    }
    return 0;
}
