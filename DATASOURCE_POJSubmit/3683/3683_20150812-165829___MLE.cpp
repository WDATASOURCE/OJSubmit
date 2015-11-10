/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-12 14:33
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
const int MAXN = 2010;

struct Edge{
    int v, nxt;
};

stack <int> sta;
bool instack[MAXN];
int t[MAXN], s[MAXN], d[MAXN];
Edge edge[4 * MAXN * MAXN];
int n, m, tdfn, scc_cnt, ecnt;
int head[MAXN], dfn[MAXN], low[MAXN], belong[MAXN];

void init(){
    tdfn = scc_cnt = ecnt = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    while(!sta.empty()) sta.pop();
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(instack, 0, sizeof(instack));
}

void addEdge(int u, int v){
    edge[ecnt].v = v;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
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
        int top;
        ++scc_cnt;
        do{
            top = sta.top();
            sta.pop();
            belong[top] = scc_cnt;
            instack[top] = false;
        }while(u != top && !sta.empty());
    }
}

int main(){
    while(scanf("%d", &n) != EOF){
        init();
        int sh, sm, th, tm;
        for(int i = 1; i <= n; i++){
            scanf("%d:%d %d:%d %d", &sh, &sm, &th, &tm, &d[i]);
            //cerr <<"sh = "<< sh <<", sm = "<< sm <<", th = "<< th <<", tm = "<< tm <<", d[i] = "<< d[i] << endl;
            s[i] = sh * 60 + sm;
            t[i] = th * 60 + tm;
        }

        for(int i = 1; i<= n; i++){
            for(int j = 1; j < i; j++){
                if(min(s[i] + d[i], s[j] + d[j]) > max(s[i], s[j])){
                    addEdge(i, j + n);
                    addEdge(j, i + n);
                }
                if(min(s[i] + d[i], t[j]) > max(s[i], t[j] - d[j])){
                    addEdge(i, j);
                    addEdge(n + j, n + i);
                }
                if(min(t[i], s[j] + d[j]) > max(t[i] - d[i], s[j])){
                    addEdge(n + i, n + j);
                    addEdge(j, i);
                }
                if(min(t[i], t[j]) > max(t[i] - d[i], t[j] - d[j])){
                    addEdge(n + i, j);
                    addEdge(n + j, i);
                }
            }
        }

        //for(int i = 1; i <= 2 * n; i ++){
            //cerr <<"i = "<< i <<": ";
            //for(int j = head[i]; j + 1; j = edge[j].nxt)
                //cerr << edge[j].v <<" ";
            //cerr << endl;
        //}

        for(int i = 1; i <= 2 * n; i++)
            if(!dfn[i]) Tarjan(i);

        //for(int i = 1; i <= n; i++)
            //cerr <<"i = "<< i <<", belong[i] = "<< belong[i] <<", belong[i + n] = "<< belong[i + n] << endl;

        //for(int i = 1; i <= 2 * n; i++)
            //cerr <<"i = "<< i <<", belong[i] = "<< belong[i] << endl;

        bool flag = 1;
        for(int i = 1; i <= n; i++)
            if(belong[i] == belong[i + n]) flag = 0;

        if(flag){
            printf("YES\n");

            for(int i = 1; i <= n; i++){
                if(belong[i] > belong[i + n])
                    printf("%02d:%02d %02d:%02d\n", s[i] / 60, s[i] % 60, (s[i] + d[i]) / 60, (s[i] + d[i]) % 60);
                else
                    printf("%02d:%02d %02d:%02d\n", (t[i] - d[i]) / 60, (t[i] - d[i]) % 60, t[i] / 60, t[i] % 60);
            }
        }else printf("NO\n");
    }
    return 0;
}
