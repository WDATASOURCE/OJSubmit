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
int shead[MAXN];
int mp[MAXN][MAXN];
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
        }while(u != top && !sta.empty());
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

        /*
        for(int u = 1; u <= n; u++)
            for(int i = head[u]; i + 1; i = edge[i].nxt){
                int v = edge[i].v;
                if(belong[v] == belong[u]) continue;
                addSedge(belong[u], belong[v], edge[i].w);
            }
            */

        fill(mp[0], mp[MAXN], (1 << 29));
        for(int u = 1; u <= n; u++)
            for(int i = head[u]; i + 1; i = edge[i].nxt){
                int v = edge[i].v;
                if(belong[v] == belong[u]) continue;
                mp[belong[u]][belong[v]] = edge[i].w;
            }

        for(int k = 1; k <= scc_cnt; k++)
            for(int i = 1; i <= scc_cnt; i++)
                for(int j = 1; j <= scc_cnt; j++)
                    if(mp[i][j] > mp[i][k] + mp[k][j])
                        mp[i][j] = mp[i][k] + mp[k][j];

        int q;
        scanf("%d", &q);
        for(int i = 0; i < q; i++){
            scanf("%d%d", &u, &v);
            if(belong[u] == belong[v]) printf("0\n");
            else if(mp[belong[u]][belong[v]] == (1 << 29)) printf("Nao e possivel entregar a carta\n");
            else printf("%d\n", mp[belong[u]][belong[v]]);
        }
        printf("\n");
    }
    return 0;
}
