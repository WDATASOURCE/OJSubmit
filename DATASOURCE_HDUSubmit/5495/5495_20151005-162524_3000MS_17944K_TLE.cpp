/*=============================================================================
# Author:            DATASOURCE
# Last modified:     2015-10-05 14:35
# Filename:         323C.cpp
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
const int MAXN = 100010;

struct Edge{
    int v, nxt;
};

Edge edge[MAXN];
bool instack[MAXN];
int a[MAXN], b[MAXN];
int n, m, ecnt, tdfn, scc_cnt, statop;
int sta[MAXN], head[MAXN], belong[MAXN], low[MAXN], dfn[MAXN], num[MAXN];

void init(){
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    memset(num, 0, sizeof(num));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(belong, 0, sizeof(belong));
    ecnt = tdfn = scc_cnt = statop = 0;
}

void addEdge(int u, int v){
    edge[ecnt].v = v;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

inline long long read() {
    long long x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

void Tarjan(int u){
    sta[++statop] = u;
    instack[u] = true;
    low[u] = dfn[u] = ++tdfn;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        if(!dfn[v]){
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }else if(instack[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]){
        int top;
        scc_cnt++;
        do{
            top = sta[statop];
            statop--;
            num[scc_cnt]++;
            belong[top] = scc_cnt;
            instack[top] = false;
        }while(top != u && statop > 0);
    }
}

int main(){
    int t;
    //scanf("%d", &t);
    t = read();
    while(t--){
        init();
        int n;
        n = read();
        //scanf("%d", &n);
        for(int i = 0; i < n; i++)
            a[i] = read();
            //scanf("%d", &a[i]);
        for(int i = 0; i < n; i++)
            b[i] = read();
            //scanf("%d", &b[i]);
        for(int i = 0; i < n; i++)
            addEdge(a[i], b[i]);

        for(int i = 1; i <= n; i++)
            if(!dfn[i]) Tarjan(i);

        int ans = 0;
        for(int i = 1; i <= scc_cnt; i++)
            if(num[i] > 1) ans++;

        printf("%d\n", n - ans);
    }
    return 0;
}
