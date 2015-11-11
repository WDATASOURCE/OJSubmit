#include <queue>
#include <cstdio>
#include <iostream>
#define N 1010
#define M (1 << 30)
using namespace std;
int n, m, t, s;
int a[N];

class Dijkstra{
private:
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
    int n, m, e, tt;
    bool vis[N];
    Edge edge[20010];

public:

    Dijkstra(int nn, int mm, int t){
        e = 0;
        n = nn, m = mm, tt = t;
        for(int i = 0; i < n + 1; i++)
            head[i] = -1;
    }

    void addedge(int u, int v, int w){
        edge[e].v = v;
        edge[e].w = w;
        edge[e].n = head[u];
        head[u] = e++;
    }

    int solve(int s){
        Node t;
        t.v = s;
        t.w = 0;
        priority_queue < Node > que;
        for(int i = 0; i < n + 1; i++){
            dis[i] = M;
            vis[i] = false;
        }
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
        return dis[tt];
    }
};

int main(){
    while(scanf("%d%d%d", &n, &m, &t) != EOF){
        int aa, b, c;
        Dijkstra dij(n, m, t);
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &aa, &b, &c);
            dij.addedge(aa, b, c);
        }
        scanf("%d", &s);
        for(int i = 0; i < s; i++)
            scanf("%d", &a[i]);
        int ans = M;
        for(int i = 0; i < s; i++){
            int res = dij.solve(a[i]);
            if(res < ans) ans = res;
        }
        printf("%d\n", ans == M ? -1:ans);
    }
    return 0;
}
