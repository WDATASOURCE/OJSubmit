/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-07-23 10:10
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
const double eps = 1e-3;
const int MAXN = 1010;
const int MAXM = 5050;
const int MAX_INT = (1 << 29);

struct Edge{
    int v, w, nxt;
};
 
int cnt[MAXN];
int val[MAXN];
int head[MAXN];
bool vis[MAXN];
double dis[MAXN];
Edge edge[2 * MAXM];
int n, m, E_cnt;

void init(){
    E_cnt = 0;
    memset(head, -1, sizeof(head));
    memset(vis, false, sizeof(vis));
    memset(edge, 0, sizeof(edge));
}

void addEdge(int u, int v, int w){
    edge[E_cnt].v = v;
    edge[E_cnt].w = w;
    edge[E_cnt].nxt = head[u];
    head[u] = E_cnt++;
}

bool check(double mid){
    fill(dis, dis + MAXN, MAX_INT);
    memset(vis, false, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    queue <int> que;
    dis[1] = 0.0;
    vis[1] = true;
    que.push(1);
    while(!que.empty()){
        int top = que.front();
        que.pop();
        vis[top] = false;
        cnt[top]++;
        if(cnt[top] > n) return true;
        for(int i = head[top]; i + 1; i = edge[i].nxt){
            double temp = mid * (double)edge[i].w - val[edge[i].v];
            //cerr <<"temp = "<< temp << endl;
            if(dis[top] + temp < dis[edge[i].v]){
                dis[edge[i].v] = dis[top] + temp;
                if(!vis[edge[i].v]){
                    que.push(edge[i].v);
                    vis[edge[i].v] = true;
                }
            }
        }
    }
    return false;
}

double solve(){
    double l = 0.0, r = 10000.0, mid;
    while(r - l > eps){
        mid = (l + r) / 2.0;
        if(check(mid)) l = mid;
        else r = mid;
    }
    return l;
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        for(int i = 1; i <= n; i++)                 //结点编号从 1 开始， 之前没注意，一直从 0 开始， 调了好久
            scanf("%d", &val[i]);
        int u, v, w;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
        }
 
        //for(int i = 0; i <= n; i++){
            //cerr <<"i = "<< i << ": ";
            //for(int j = head[i]; j + 1; j = edge[j].nxt)
                //cerr << edge[j].v <<" ";
            //cerr << endl;
        //}
        
        double ans = solve();
        printf("%.2f\n", ans);
    }
    return 0;
}
