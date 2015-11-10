/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-09-04 15:21
# Filename: 		b.cpp
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
const int MAXN = 50;
const int MAX_INT = (1 << 29);

struct Edge{
    int v, w, nxt;
};

struct Node{
    int u, v, w;

   friend bool operator < (const Node &a, const Node &b){
       return a.w < b.w;
   }
};

int pcnt;
int par[MAXN];
map <string, int> ma;
Node node[MAXN * MAXN], dp[MAXN];

int ecnt, n, m, k;
bool use[MAXN][MAXN];
Edge edge[MAXN * MAXN];
int head[MAXN], vis[MAXN], dis[MAXN];

int Min[MAXN], tmp[MAXN];

void init(){
    ma.clear();
    ecnt = pcnt = 0;
    memset(dp, -1, sizeof(dp));
    memset(use, 0, sizeof(use));
    memset(edge, 0, sizeof(edge));
    memset(node, 0, sizeof(node));
    memset(head, -1, sizeof(head));
    fill(Min, Min + MAXN, MAX_INT);
    for(int i = 0; i < MAXN; i++) par[i] = i;
}

void addEdge(int u, int v, int w){
    edge[ecnt].v = v;
    edge[ecnt].w = w;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

int getId(char s[]){
    if(ma.find(s) == ma.end()) ma[s] = ++pcnt;
    else return ma[s];
    return pcnt;
}

int Find(int x){
    if(par[x] != x) par[x] = Find(par[x]);
    return par[x];
}

bool Union(int x, int y){
    int fx = Find(x);
    int fy = Find(y);
    if(fx == fy) return false;
    par[fy] = fx;
    return true;
}

void dfs(int s, int u, int fa){
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        if(v != s && v != fa && use[u][v]){
            if(dp[v].w == -1){
                if(dp[u].w > edge[i].w) dp[v] = dp[u];
                else{
                    dp[v].w = edge[i].w;
                    dp[v].u = u;
                    dp[v].v = v;
                }
            }
            dfs(s, v, u);
        }
    }
}

int kruskal(int s){
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(node[i].u == s || node[i].v == s) continue;
        if(!Union(node[i].u, node[i].v)) continue;
        use[node[i].u][node[i].v] = use[node[i].v][node[i].u] = true;
        ans += node[i].w;
    }
    return ans;
}

int solve(int s){
    sort(node, node + n);
    int ans = kruskal(s);
    for(int i = head[s]; i + 1; i = edge[i].nxt){
        int v = edge[i].v;
        int belong = Find(v);
        if(Min[belong] > edge[i].w){
            tmp[belong] = edge[i].v;
            Min[belong] = edge[i].w;
        }
    }

    int degree = 0;

    for(int i = 1; i <= pcnt; i++){
        if(Min[i] != MAX_INT){
            degree++;
            use[s][tmp[i]] = use[tmp[i]][s] = true;
            ans += Min[i];
        }
    }

    for(int i = degree + 1; i <= k; i++){
        dp[s].w = -MAX_INT;
        for(int j = 2; j <= pcnt; j++)
            if(use[s][j]) dp[j].w = -MAX_INT;
        dfs(s, 1, -1);
        int temp, mi = MAX_INT;
        for(int j = head[s]; j + 1; j = edge[j].nxt){
            if(mi > edge[j].w - dp[edge[j].v].w){
                mi = edge[j].w - dp[edge[j].v].w;
                temp = edge[j].v;
            }
        }
        if(mi >= 0) break;
        //cerr <<"mi = "<< mi <<", temp = "<< temp << endl;
        use[s][temp] = use[temp][s] = true;
        //cerr <<"111111111"<< endl;
        int u = dp[temp].u;
        int v = dp[temp].v;
        use[u][v] = use[v][u] = false;
        ans += mi;
    }
    return ans;
}
 
int main(){
    while(scanf("%d", &n) != EOF){
        init();
        int u, v, w;
        char s1[50];
        char s2[50];
        ma["Park"] = ++pcnt;
        for(int i = 0; i < n; i++){
            scanf("%s%s%d", s1, s2, &w);
            u = getId(s1), v = getId(s2);
            addEdge(u, v, w);
            addEdge(v, u, w);
            node[i].u = u, node[i].v = v, node[i].w = w;
        }
        scanf("%d", &k);
        int ans = solve(1);
        printf("Total miles driven: %d\n", ans);

    }
    return 0;
}
