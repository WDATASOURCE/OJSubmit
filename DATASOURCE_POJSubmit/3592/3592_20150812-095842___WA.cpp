/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-12 08:29
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
const int MAXN = 2000;
const int MAXE = 5000;

struct Edge{
    int v, nxt;
};

char mp[MAXN][MAXN];

Edge edge[MAXE];
stack <int> sta;
bool instack[MAXN];
int n, m, scc_cnt, ecnt, tdfn;
int head[MAXN], val[MAXN], dfn[MAXN], low[MAXN], belong[MAXN], In[MAXN], Out[MAXN];

int scnt;
bool vis[MAXN];
Edge sedge[MAXE];
int shead[MAXN], sccval[MAXN], dis[MAXN];

void init(){
    scc_cnt = ecnt = tdfn = scnt = 0;
    memset(In, 0, sizeof(In));
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    memset(Out, 0, sizeof(Out));
    memset(val, 0, sizeof(val));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    while(!sta.empty()) sta.pop();
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(sedge, 0, sizeof(sedge));
    memset(shead, -1, sizeof(shead));
    memset(sccval, 0, sizeof(sccval));
    memset(belong, 0, sizeof(belong));
    memset(instack, 0, sizeof(instack));
}

void addEdge(int *head, Edge *edge, int u, int v, int &cnt){
    edge[cnt].v = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}

void Input(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", mp[i]);
    int a, b;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(mp[i][j] >= '0' && mp[i][j] <= '9') val[m * i + j] = mp[i][j] - '0';
            else if(mp[i][j] == '*'){
                scanf("%d%d", &a, &b);
                addEdge(head, edge, m * i + j, a * m + b, ecnt);
            }

            if(i + 1 < n && mp[i + 1][j] != '#')
                addEdge(head, edge, m * i + j, m * (i + 1) + j, ecnt);
            if(j + 1 < m && mp[i][j + 1] != '#')
                addEdge(head, edge, m * i + j, m * i + j + 1, ecnt);
        }

    //for(int i = 0; i < n * m; i++)
        //cerr <<"i = "<< i <<", val[i] = "<< val[i] << endl;
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
        ++scc_cnt;
        int top;
        do{
            top = sta.top();
            sta.pop();
            instack[top] = false;
            belong[top] = scc_cnt;
            //cerr <<"scc_cnt = "<< scc_cnt <<", sccval[scc_cnt] = "<< sccval[scc_cnt] << endl;
            sccval[scc_cnt] += val[top];
            //cerr <<"scc_cnt = "<< scc_cnt <<", top = "<< top <<", val[top] = "<< val[top] <<", sccval[scc_cnt] = "<< sccval[scc_cnt] << endl;
        }while(top != u && !sta.empty());
    }
}

void SPFA(int src){
    queue <int> que;
    que.push(src);
    vis[src] = true;
    dis[src] = sccval[src];
    while(!que.empty()){
        int u = que.front();
        que.pop();
        vis[u] = false;
        for(int i = shead[u]; i + 1; i = sedge[i].nxt){
            int v = sedge[i].v;
            dis[v] = max(dis[v], dis[u] + sccval[v]);
            if(!vis[v]) que.push(v), vis[v] = true;
        }
    }
}

void solve(){

    Tarjan(0);

    //cerr <<"scc_cnt = "<< scc_cnt << endl;
    //for(int i = 0; i < n * m; i++)
        //cerr <<"i = "<< i <<", belong[i] = "<< belong[i] <<", sccval[belong[i]] = "<< sccval[belong[i]] << endl;

    for(int u = 0; u < n * m; u++)
        for(int i = head[u]; i + 1; i = edge[i].nxt){
            int v = edge[i].v;
            if(belong[u] != belong[v]) addEdge(shead, sedge, belong[u], belong[v], scnt);
        }

    SPFA(belong[0]);

    int ans = 0;
    for(int i = 1; i <= scc_cnt; i++)
        ans = max(ans, dis[i]);

    printf("%d\n", ans);
}
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){

        init();
        Input();
        solve();

    }
    return 0;
}
