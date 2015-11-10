#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 1100
#define MAX (1 << 29)
#define MIN 0
using namespace std;

struct Edge{
    int v, w, n;
};

struct Node{
    int v, w;
    
    friend bool operator < (const Node &a, const Node &b){
        return a.w > b.w;
    }
};

Edge edge[N * 20];
int vis[N], dis[N], head[N];
int n, m, k, e;

void addEdge(int u, int v, int w){
    edge[e].v = v;
    edge[e].w = w;
    edge[e].n = head[u];
    head[u] = e++;
}

void init(){
    fill(head, head + N, -1);
    int a, b, w;
    e = 0;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &w);
        addEdge(a, b, w);
        addEdge(b, a, w);
    }
}

bool dijstral(int mid){
    priority_queue<Node> que;
    fill(vis, vis + N, 0);
    fill(dis, dis + N, MAX);
    Node t;
    t.v = 1;
    t.w = 0;
    dis[t.v] = t.w;
    que.push(t);
    while(!que.empty()){
        t = que.top();
        que.pop();
        if(vis[t.v]) continue;
        vis[t.v] = 1;
        for(int i = head[t.v]; i != -1; i = edge[i].n)
            if(!vis[edge[i].v] && dis[edge[i].v] > (dis[t.v] + (edge[i].w >= mid ? 1 : 0))){
                Node tt;
                tt.v = edge[i].v;
                dis[edge[i].v] = tt.w = dis[t.v] + (edge[i].w >= mid ? 1 : 0);
                que.push(tt);
            }
    }
    //for(int i = 1; i <= n; i++)
        //printf("%d ", dis[i]);
    //printf("\n");
    if(dis[n] <= k) return true;
    else return false;
}

void solve(){
    int l = 0, r = 1000002;
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if(dijstral(mid)) r = mid;
        else l = mid;
    }
    if(l > 1000000) printf("-1\n");
    else printf("%d\n", l);
}

int main(){
    while(scanf("%d%d%d", &n, &m, &k) != EOF){
        init();
        solve();
    }
    return 0;
}
