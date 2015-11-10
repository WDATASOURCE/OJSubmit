#include <queue>
#include <cstdio>
#include <iostream>
#define M (1 << 29)
#define N 3010
using namespace std;

struct Edge{
    int t, cost, next;
};

int count[N], head[N], dis[N], path[N], n, m, e;
Edge edge[N * N / 2];
bool vis[N];

void init(){
    e = 0;
    fill(vis, vis + N, false);
    fill(dis, dis + N, M);
    fill(count, count + N, 0);
    fill(head, head + N, -1);
}

void addedge(int u, int v, int w){
    edge[e].t = v;
    edge[e].cost = w;
    edge[e].next = head[u];
    head[u] = e++;
}

bool SPFA(int s){
    queue < int > que;
    dis[s] = 0;
    que.push(s);
    vis[s] = true;
    while(!que.empty()){
        int top = que.front();
        que.pop();
        count[top]++;
        vis[top] = false;
        if(count[top] > n) return false;
        for(int i = head[top]; i != -1; i = edge[i].next)
            if(dis[edge[i].t] > dis[top] + edge[i].cost){
                dis[edge[i].t] = dis[top] + edge[i].cost;
                if(!vis[edge[i].t]){
                    vis[edge[i].t] = true;
                    que.push(edge[i].t);
                }
            }
    }
    return true;
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        while(m--){
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            addedge(a, b, w);
            addedge(b, a, w);
        }
        if(SPFA(1)) printf("%d\n", dis[n]);
        else printf("No answer\n");
    }
    return 0;
}
