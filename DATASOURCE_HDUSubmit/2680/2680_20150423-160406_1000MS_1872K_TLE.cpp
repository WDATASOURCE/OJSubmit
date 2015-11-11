#include <stack>
#include <queue>
#include <cstdio>
#include <iostream>
#define N 1010
#define M (1 << 29)
using namespace std;

int n, m, t, s, e;
int aa[N];

struct Edge{
    int v, w, n;
};

int head[N], dis[N], cnt[N];
bool vis[N];
Edge edge[20010];

void init(){
    e = 0;
    for(int i = 0; i < n; i++){
        head[i] = -1;
        cnt[i] = 0;
    }
}

void addEdge(int u, int v, int w){
    edge[e].v = v;
    edge[e].w = w;
    edge[e].n = head[u];
    head[u] = e++;
}

int solve(int s){
    queue <int> que;
    for(int i = 0; i <= n; i++){
        dis[i] = M, vis[i] = false;
    }
    vis[s] = true;
    dis[s] = 0;
    que.push(s);
    while(!que.empty()){
        int u = que.front();
        que.pop();
        vis[u] = false;
        if(++cnt[u] > n) return M;
        for(int i = head[u]; i != -1; i = edge[i].n)
            if(dis[edge[i].v] > dis[u] + edge[i].w){
                dis[edge[i].v] = dis[u] + edge[i].w;
                if(!vis[edge[i].v]){
                    que.push(edge[i].v);
                    vis[edge[i].v] = true;
                }
            }
    }
    return dis[t];
}
int main(){
    while(scanf("%d%d%d", &n, &m, &t) != EOF){
        init();
        int a, b, c;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &a, &b, &c);
            addEdge(a, b, c);
        }
        scanf("%d", &s);
        for(int i = 0; i < s; i++)
            scanf("%d", &aa[i]);
        int ans = M;
        for(int i = 0; i < s; i++){
            int res = solve(aa[i]);
            if(res < ans) ans = res;
        }
        printf("%d\n", ans == M ? -1 : ans);
    }
    return 0;
}
