/*=============================================================================
# Author:           He Shuwei
# Last modified:    2015-08-03 10:37
# Filename:            a.cpp
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
const int MAX_INT = (1 << 29);

struct Edge{
    int v, nxt;
    int index;
};

map <string, int> ma;
bool vis[MAXN];
int father[MAXN];
pair<int, int> pai[MAXN];
int res[MAXN], par[MAXN];
int dis[MAXN], degree[MAXN];
int thead[MAXN], qhead[MAXN];
Edge tedge[2 * MAXN], qedge[2 * MAXN];
int n, q, ecnt, qcnt, cnt;

void init(){
    ma.clear();
    ecnt = qcnt = cnt = 0;
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(tedge, 0, sizeof(tedge));
    memset(qedge, 0, sizeof(qedge));
    memset(thead, -1, sizeof(thead));
    memset(qhead, -1, sizeof(qhead));
    memset(degree, 0, sizeof(degree));
    for(int i = 0; i < MAXN; i++) par[i] = i;
}

void addEdge(int * head, Edge* edge, int u, int v, int index, int &cnt){
    edge[cnt].v = v;
    edge[cnt].index = index;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}

int Find(int x){
    if(par[x] != x) par[x] = Find(par[x]);
    return par[x];
}

void Union(int x, int y){
    int fx = Find(x);
    int fy = Find(y);
    if(fx != fy) par[fx] = fy;
}

void dfs(int u){
    father[u] = u;
    vis[u] = true;
    for(int i = thead[u]; i + 1; i = tedge[i].nxt){
        if(vis[tedge[i].v]) continue;
        dis[tedge[i].v] = dis[u] + 1;
        dfs(tedge[i].v);
        Union(u, tedge[i].v);
        father[Find(u)] = u;
    }

    for(int i = qhead[u]; i + 1; i = qedge[i].nxt)
        if(vis[qedge[i].v]) res[qedge[i].index] = father[Find(qedge[i].v)];
}

int main(){
    int t;
    string A, B;
    ios_base::sync_with_stdio(false);
    cin >> t;
    while(t--){
        init();
        cin >> n >> q;
        if(n == 1){
            for(int i = 0; i < q; i++){
                cin >> A >> B;
                cout << 0 << endl;
            }
            continue;
        }
        int u, v;
        for(int i = 1; i < n; i++){
            cin >> A >> B;
            if(ma.count(A)) v = ma[A];
            else v = ma[A] = ++cnt;
            if(ma.count(B)) u = ma[B];
            else u = ma[B] = ++cnt;
            degree[v]++;
            addEdge(thead, tedge, u, v, 0, ecnt);
        }

        for(int i = 0; i < q; i++){
            cin >> A >> B;
            u = ma[A], v = ma[B];
            pai[i] = make_pair(u, v);
            addEdge(qhead, qedge, u, v, i, qcnt);
            addEdge(qhead, qedge, v, u, i, qcnt);
        }

        int s = 0;
        for(int i = 1; i <= cnt; i++)
            if(!degree[i]){ s = i; break;}

        //cerr <<"s = "<< s << endl;
        //for(int i = 0; i <= cnt; i++)
            //cerr<<"i = "<< i <<", degree[i] = "<< degree[i] << endl;

        dfs(s);

        //for(int i = 0; i <= cnt; i++)
            //cerr<<"i = "<< i <<", dis[i] = "<< dis[i] << endl;

        int ans = 0;
        for(int i = 0; i < q; i++){
            u = pai[i].first, v = pai[i].second;
            if(u == v) ans = 0;
            else if(res[i] == u) ans = 1;
            else if(res[i] == v) ans = dis[u] - dis[v];
            else ans = dis[u] + dis[v] - 2 * dis[res[i]];
            cout << ans << endl;
        }
    }
    return 0;
}
