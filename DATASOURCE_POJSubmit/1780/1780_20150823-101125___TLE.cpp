/*=============================================================================
# Author:			He Shuwei
# Last modified:	2015-08-23 09:36
# Filename:			a.cpp
# Description: 
=============================================================================*/
 
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1000100;

struct Edge{
    int v, id, nxt;
};

struct Data{
    int v, e;
};

bool vis[MAXN];
Data sta[MAXN];
Edge edge[MAXN];
int top, st, ecnt, n;
int head[MAXN], path[MAXN]; 

void init(){
    ecnt = 0;
    memset(vis, 0, sizeof(vis));
    memset(path, 0, sizeof(path));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v, int id){
    edge[ecnt].v = v;
    edge[ecnt].id = id;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void dfs(int u){
    Data p;
    st = 0;
    int t = head[u];
    p.v = u, p.e = t;
    sta[st++] = p;
    vis[edge[t].id] = 1;
    while(1){
        if(t == -1){
            Data y = sta[st - 1];
            path[top++] = edge[y.e].id;
            st--;
            if(!st) break;
        }
        Data x = sta[st - 1];
        t = head[x.v];
        while(t != -1){
            if(!vis[edge[t].id]){
                vis[edge[t].id] = 1;
                p.v = edge[t].v, p.e = t;
                sta[st++] = p;
                break;
            }
            t = edge[t].nxt;
        }
    }
}

int main(){
    while(~scanf("%d", &n) && n){
        if(n == 1){
            printf("0123456789\n");
            continue;
        }
        init();
        int cnt = 1;            // 边数
        for(int i = 1; i <= n; i++)
            cnt *= 10;
        int len = cnt / 10;     // 节点数
        for(int i = 0; i < len; i++){
            int tmp = i % (len / 10);
            tmp *= 10;
            for(int j = 9; j >= 0; j--)
                addEdge(i, tmp + j, i * 10 + j);
        }
        top = 0;
        dfs(0);
        for(int i = top - 1; i > 0; i--)
            printf("%d", path[i] / len);
        printf("%d\n", path[0]);
    }
    return 0;
}
