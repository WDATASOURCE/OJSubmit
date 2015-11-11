#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 1000
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

int head[N], dis[N];
bool vis[N];
Edge edge[N * N];
int n, m, k, e;
priority_queue <Node> que;

void addEdge(int u, int v, int w){
    edge[e].v = v;
    edge[e].w = w;
    edge[e].n = head[u];
    head[u] = e++;
}

void init(){
    e = 0;
    fill(head, head + N, -1);
    fill(vis, vis + N, false);
    while(!que.empty()) que.pop();

    scanf("%d%d%d", &n, &m, &k);

    int a, b, w, v, vc[N];
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &w);
        addEdge(a, b, w);
        addEdge(b, a, w);
    }
    while(k--){
        scanf("%d", &v);
        for(int i = 0; i < v; i++)
            scanf("%d", &vc[i]);
        for(int i = 0; i < v; i++)
            for(int j = 0; j < v; j++){
                addEdge(vc[i], vc[j], 0);
                addEdge(vc[j], vc[i], 0);
            }
    }
}

int prime(){
    int ans = 0;
    int me = 0;
    Node t1, t2;
    t1.v = 1;
    t1.w = 0;
    que.push(t1);
    while(!que.empty() && me <= e){
        t1 = que.top();
        que.pop();
        if(vis[t1.v]) continue;
        vis[t1.v] = 1;
        ans += t1.w;
        me++;
        if(me == n) break;
        for(int i = head[t1.v]; i != -1; i = edge[i].n){
            if(!vis[edge[i].v]){
                t2.v = edge[i].v;
                t2.w = edge[i].w;
                que.push(t2);
            }
        }
    }
    if(me == n) return ans;
    return -1;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        init();
        int ans = prime();
        printf("%d\n", ans);
    }
    return 0;
}
