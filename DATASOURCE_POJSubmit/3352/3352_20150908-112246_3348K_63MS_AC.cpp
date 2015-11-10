/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-09-07 17:24
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
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
const int MAXN = 10100;
const int MAXM = 200100;

struct Edge{
    int v, w, nxt;
};

stack <int> sta;
Edge edge[MAXM];
bool instack[MAXN];
int n, m, ecnt, tdfn, bcc_cnt;
int head[MAXN], low[MAXN], dfn[MAXN], belong[MAXN], deg[MAXN];

void init(){
    bcc_cnt = ecnt = tdfn = 0;
    memset(deg, 0, sizeof(deg));
    memset(low, 0, sizeof(low));
    //memset(res, 0, sizeof(res));
    memset(dfn, 0, sizeof(dfn));
    while(!sta.empty()) sta.pop();
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(belong, 0, sizeof(belong));
    memset(instack, 0, sizeof(instack));
}

void addEdge(int u, int v, int w){
    edge[ecnt].v = v;
    edge[ecnt].w = w;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void Tarjan(int u, int fa){
    sta.push(u);
    instack[u] = true;
    low[u] = dfn[u] = ++tdfn;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        if((fa ^ 1) == i) continue;
        if(!dfn[v]){
            Tarjan(v, i);
            low[u] = min(low[u], low[v]);
        }else low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]){
        bcc_cnt++;
        int top;
        do{
            top = sta.top();
            sta.pop();
            instack[top] = false;
            belong[top] = bcc_cnt;
        }while(u != top);
    }
}

int main(){
    //int t;
    //scanf("%d", &t);
    //while(t--){
    while(~scanf("%d%d", &n, &m)){
        init();
        int u, v;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            addEdge(u, v, i + 1);
            addEdge(v, u, i + 1);
        }

        for(int i = 1; i <= n; i++)
            if(!dfn[i]) Tarjan(i, -1);

        //for(int i = 1; i <= n; i++)
            //cerr <<"i = "<< i <<", belong[i] = "<< belong[i] << endl;

        for(int u = 1; u <= n; u++)
            for(int i = head[u]; i + 1; i = edge[i].nxt)
                if(belong[u] != belong[edge[i].v]) deg[belong[u]]++;

        //for(int i = 1; i <= bcc_cnt; i++)
            //cerr <<"i = "<< i <<", deg[i] = "<< deg[i] << endl;
        //cerr <<"bcc_cnt = "<< bcc_cnt << endl;
        
        int cnt = 0;
        for(int i = 1; i <= bcc_cnt; i++)
            if(deg[i] == 1) cnt++;

        printf("%d\n", (cnt + 1) / 2);


    }
    return 0;
}
