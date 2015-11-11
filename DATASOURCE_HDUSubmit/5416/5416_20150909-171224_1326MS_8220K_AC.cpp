/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-09-09 13:35
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
const int MAXN = 100100;

struct Edge{
    int v, w, nxt;
};

int ecnt, n, m;
int s[20];
long long res[20];
Edge edge[MAXN * 2];
int head[MAXN], val[MAXN]; 
int cnt[MAXN * 3];

void init(){
    ecnt = 0;
    memset(res, 0, sizeof(res));
    memset(cnt, 0, sizeof(cnt));
    memset(val, 0, sizeof(val));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v, int w){
    edge[ecnt].v = v;
    edge[ecnt].w = w;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void dfs(int u, int fa){
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        if((fa ^ 1) == i) continue;
        int v = edge[i].v;
        val[v] = val[u] ^ edge[i].w;
        dfs(v, i);
    }
}
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        init();
        scanf("%d", &n);
        int u, v, w;
        for(int i = 1; i < n; i++){
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }

        scanf("%d", &m);
        for(int i = 0; i < m; i++)
            scanf("%d", &s[i]);

        dfs(1, -1);

        //for(int i = 1; i <= n; i++)
            //cerr <<"i = "<< i <<", val[i] = "<< val[i] << endl;

        for(int i = 1; i <= n; i++)
            cnt[val[i]]++;

        //for(int i = 0; i < 10; i++)
            //cerr <<"i = "<< i <<", cnt[i] = "<< cnt[i] << endl;

        for(int i = 1; i <= n; i++)
            for(int j = 0; j < m; j++){
                if(s[j] == 0) res[j] += (cnt[val[i]] - 1);
                else res[j] += cnt[val[i] ^ s[j]];
            }
        
        //for(int i = 0; i < 10; i++)
            //cerr <<"i = "<< i <<", res[i] = "<< res[i] << endl;

        for(int i = 0; i < m; i++){
            if(s[i] == 0) printf("%lld\n", res[i] / 2 + n);
            else printf("%lld\n", res[i] / 2);
        }
    }
    return 0;
}