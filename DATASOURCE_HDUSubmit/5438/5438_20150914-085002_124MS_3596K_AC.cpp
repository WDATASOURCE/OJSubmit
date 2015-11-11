/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-09-13 09:15
# Filename:         1002.cpp
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
const int MAXN = 10010;
const int MAXM = 100010;

struct Edge{
    int v, nxt;
};

int ecnt, n, m;
Edge edge[MAXM * 2];
bool exist[MAXN];
int head[MAXN], deg[MAXN], val[MAXN];

void init(){
    ecnt = 0;
    memset(val, 0, sizeof(val));
    memset(deg, 0, sizeof(deg));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(exist, 1, sizeof(exist));
}

void addEdge(int u, int v){
    edge[ecnt].v = v;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void dfs(int u, int fa, int &num, long long &sum){
    exist[u] = false;
    sum += val[u];
    num++;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        if(exist[v]) dfs(v, u, num, sum);
    }
}

void solve(){
    queue <int> que;
    for(int i = 1; i <= n; i++)
        if(deg[i] <= 1){
            //cerr <<"i = "<< i << endl;
            que.push(i);
            exist[i] = false;
        }

    while(!que.empty()){
        int top = que.front();
        que.pop();
        for(int i = head[top]; i + 1; i = edge[i].nxt){
            int v = edge[i].v;
            if(exist[v]){
                deg[v]--;
                if(deg[v] <= 1) {
                    //cerr <<"v = "<< v << endl;
                    que.push(v);
                    exist[v] = false;
                }
            }
        }
    }

    long long ans = 0;
    for(int i = 0; i < n; i++){
        if(exist[i]){
            int num = 0; 
            long long sum = 0;
            dfs(i, -1, num, sum);
            if(num & 1) ans += sum;
        }
    }
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        init();
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
            scanf("%d", &val[i]);
        int u, v;
        for(int i = 1; i <= m; i++){
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
            deg[u]++, deg[v]++;
        }

        solve();
    }
    return 0;
}