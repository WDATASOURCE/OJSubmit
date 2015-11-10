#include <queue>
#include <cstdio>
#include <iostream>
#define N 100
#define M (1 << 30)
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

int head[N], dis[N], n, m, e;
bool vis[N];
Edge edge[N * N / 2];
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

int prime(){
    int ans = 0;
    Node t;
    t.v = 1;
    t.w = 0;
    que.push(t);
    int nume = 0;
    while(!que.empty() && nume <= m){
        t = que.top();
        que.pop();
        if(vis[t.v]) continue;
        ans += t.w;
        vis[t.v] = true;
        nume++;
        for(int i = head[t.v]; i != -1; i = edge[i].n)
            if(!vis[edge[i].v]){
                Node tt;
                tt.v = edge[i].v;
                tt.w = edge[i].w;
                que.push(tt);
            }
    }
    //cerr <<"nume = "<< nume << endl;
    if(nume == n) return ans;
    return -1;
}

int main(){
    while(scanf("%d", &n) != EOF && n){
        scanf("%d", &m);
        init();
        int a, b, w;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &a, &b, &w);
            addedge(a, b, w);
            addedge(b, a, w);
        }
        printf("%d\n", prime());
    }
    return 0;
}
