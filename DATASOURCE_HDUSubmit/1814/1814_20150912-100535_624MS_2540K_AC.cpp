/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-09-11 17:38
# Filename:         b.cpp
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
using namespace std;
const int MAXN = 16005;

struct Edge{
    int v, nxt;
};

int cnt, ecnt, n, m;
Edge edge[4 * MAXN];
int head[MAXN], col[MAXN], res[MAXN];

void init(){
    cnt = ecnt = 0;
    memset(res, 0, sizeof(res));
    memset(col, 0, sizeof(col));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v){
    edge[ecnt].v = v;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

bool dfs(int u){
    if(col[u] == 2) return false;
    if(col[u] == 1) return true;
    col[u] = 1;
    col[u ^ 1] = 2;
    res[cnt++] = u;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        if(!dfs(v)) return false;
    }
    return true;
}

bool solve(){
    memset(col, 0, sizeof(col));
    for(int i = 0; i < n; i++){
        if(col[i]) continue;
        cnt = 0;
        if(!dfs(i)){
            for(int j = 0; j < cnt; j++){
                col[res[j]] = 0;
                col[res[j] ^ 1] = 0;
            }
            if(!dfs(i ^ 1)) return false;
        }
    }
    return true;
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        n <<= 1;
        int u, v;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            u--, v--;
            addEdge(u, v ^ 1);
            addEdge(v, u ^ 1);
        }
        if(solve()){
            for(int i = 0; i < n; i++)
                if(col[i] == 1) printf("%d\n", i + 1);
        } else printf("NIE\n");
    }
    return 0;
}
