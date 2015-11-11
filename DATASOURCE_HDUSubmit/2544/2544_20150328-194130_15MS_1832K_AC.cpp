#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 1100
#define E 21000
#define M (1 << 29)
#define Min(a, b) (a > b ? b : a)
#define Max(a, b) (a > b ? a : b)
using namespace std;

struct Edge{
    int v, w, p, n;
};

struct Node{
    int v, w, p;

    friend bool operator < (const Node &a, const Node &b){
        return a.w > b.w;
    }
};

int head[N], vis[N], e, ans, res;
Edge edge[E];
int n, m, s, t;

void addEdge(int u, int v, int w, int p){
    edge[e].v = v;
    edge[e].w = w;
    edge[e].p = p;
    edge[e].n = head[u];
    head[u] = e++;
}

void init(){
    fill(head, head + N, -1);
    fill(vis, vis + N, 0);
    e = 0, s = 1, t = n;
    int a, b, w, p;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &w);
        addEdge(a, b, w, 0);
        addEdge(b, a, w, 0);
    }
}

Node dijstral(int s){
    Node node, t1, t2;
    node.v = s, node.w = 0, node.p = 0;
    priority_queue<Node> que;
    que.push(node);
    while(!que.empty()){
        t1 = que.top();
        que.pop();
        if(vis[t1.v]) continue;
        vis[t1.v] = 1;
        if(t1.v == t) return t1;
        for(int i = head[t1.v]; i != -1; i = edge[i].n){
            t2.v = edge[i].v;
            t2.w = t1.w + edge[i].w;
            t2.p = t1.p + edge[i].p;
            que.push(t2);
        }
    }
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF && n + m){
        init();
        Node ans = dijstral(s);
        printf("%d\n", ans.w);
    }
    return 0;
}
