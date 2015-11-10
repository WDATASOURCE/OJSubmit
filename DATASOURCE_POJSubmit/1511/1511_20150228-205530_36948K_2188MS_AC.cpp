#include <queue>
#include <cstdio>
#include <iostream>
#define N 1000100
#define M (100000000000LL)
using namespace std;

struct Edge{
    int v, w, n;
};

struct Node{
    long long v, w;

    friend bool operator < (const Node &a, const Node &b){
        return a.w > b.w;
    }
};

int vv[N], uu[N], ww[N];
int head[N], n, m, e;
long long dis[N];
bool vis[N];
Edge edge[N];
priority_queue < Node > que;

void init(){
    e = 0;
    while(!que.empty()) que.pop();
    fill(head, head + N, -1);
    fill(dis, dis + N, M);
    fill(vis, vis + N, false);
}

void addedge(int u, int v, int w){
    edge[e].v = v;
    edge[e].w = w;
    edge[e].n = head[u];
    head[u] = e++;
}

void Dijkstra(int s){
    Node t;
    t.v = s;
    t.w = 0;
    dis[t.v] = t.w;
    que.push(t);
    while(!que.empty()){
        t = que.top();
        que.pop();
        if(vis[t.v]) continue;
        vis[t.v] = true;
        for(int i = head[t.v]; i != -1; i = edge[i].n)
            if(!vis[edge[i].v] && dis[edge[i].v] > dis[t.v] + edge[i].w){
                Node tt;
                tt.v = edge[i].v;
                dis[edge[i].v] = tt.w = dis[t.v] + edge[i].w;
                que.push(tt);
            }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        init();
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &vv[i], &uu[i], &ww[i]);
            addedge(uu[i], vv[i], ww[i]);
        }
        Dijkstra(1);
        long long ans = 0;
        for(int i = 1; i <= n; i++) ans += dis[i];
        init();
        for(int i = 0; i < m; i++){
            addedge(vv[i], uu[i], ww[i]);
        }
        Dijkstra(1);
        for(int i = 1; i <= n; i++) ans += dis[i];
        printf("%lld\n", ans);
    }
    return 0;
}
