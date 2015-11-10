#include <map>
//#include <ctime>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 200100
#define M (1 << 30)
#define Max(a, b) (a > b ? a : b)
using namespace std;

struct Edge{
    int a, b, w;

    friend bool operator < (const Edge &a, const Edge &b){
        return a.w < b.w;
    }
};

class LCA{

public:

    struct Edge1{
        int v, n, w;
    };

    Edge1 edge1[2 * N];
    int thead[N], qhead[N], ahead[N];
    int vis[N], p[N], val[N], ans[N], e;

    void init(){
        e = 0;
        fill(thead, thead + N, -1);
        fill(qhead, qhead + N, -1);
        fill(ahead, ahead + N, -1);
        fill(val, val + N, -M);
        fill(vis, vis + N, 0);
    }

    int find(int x){
        static int path[2 * N];
        int len = 0, px;
        for(px = x; ~p[px]; px = p[px]) path[len++] = px;
        for(int i = len - 1; i >= 0; i--){
            int u = path[i];
            val[u] = Max(val[u], val[p[u]]);
            p[u] = px;
        }
        return px;
    }

    void Union(int x, int y, int w){
        p[find(y)] = find(x);
        val[y] = w;
    }

    void add(int *head, int u, int v, int w = 0){
        edge1[e].v = v, edge1[e].w = w, edge1[e].n = head[u], head[u] = e++;
        if(head == ahead) return;
        edge1[e].v = u, edge1[e].w = w, edge1[e].n = head[v], head[v] = e++;

    }

    void dfs(int u){
        vis[u] = 1, p[u] = -1;
        for(int i = thead[u]; ~i; i = edge1[i].n)
            if(!vis[edge1[i].v]) dfs(edge1[i].v), Union(u, edge1[i].v, edge1[i].w);
        vis[u] = 2;
        for(int i = qhead[u]; ~i; i = edge1[i].n)
            if(vis[edge1[i].v] == 2) add(ahead, find(edge1[i].v), i, edge1[i].w);
        for(int i = ahead[u]; ~i; i = edge1[i].n){
            int x = edge1[edge1[i].v].v, y = edge1[edge1[i].v ^ 1].v;
            find(x), find(y);
            ans[edge1[i].w] = Max(val[x], val[y]);
        }
    }
}lca;

int par[N], n, m;
Edge edge[N];
bool vis[N];

void init(){
    for(int i = 0; i < N; i++)
        par[i] = i, vis[i] = false;
}

int find(int x){
    if(par[x] != x) par[x] = find(par[x]);
    return par[x];
}

bool Union(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy) return false;
    par[fx] = fy;
    return true;
}

int Kruscal(){
    int ne = 0, ans = 0;
    sort(edge, edge + m);
    for(int i = 0; i < m; i++)
        if(Union(edge[i].a, edge[i].b)){
            ans += edge[i].w;
            ne++;
            vis[i] = true;
            lca.add(lca.thead, edge[i].a, edge[i].b, edge[i].w);
            //lca.add(lca.thead, edge[i].b, edge[i].b, edge[i].w);
            if(ne == n - 1) break;
        }
    if(ne == n - 1) return ans;
    return -1;
}

int Ckruscal(){
    int res = M, me = 0, ne = 0;
    map <pair<int, int>, int> ma;
    for(int i = 0; i < m; i++){
        if(!vis[i]){
            pair<int, int> pir(edge[i].a, edge[i].b);
            if(ma.count(pir)) continue;
            lca.add(lca.qhead, edge[i].a, edge[i].b, me++);
            //lca.add(lca.qhead, edge[i].b, edge[i].a, me++);
            ma[pir] = 1;
            pir = make_pair(edge[i].b, edge[i].a);
            ma[pir] = 1;
        }
    }
    lca.dfs(1);
    for(int i = 0; i < m; i++)
        if(!vis[i]){
            if(edge[i].w - lca.ans[ne] < res) res = edge[i].w - lca.ans[ne];
            ne++;
        }
    if(res < M) return res;
    return -1;
}

int main(){
    //clock_t start = clock();
    int t;
    scanf("%d", &t);
    for(int j = 1; j <= t; j++){
        //printf("Case %d: ", j);
        scanf("%d%d", &n, &m);
        int a, b, w;
        init();
        lca.init();
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &a, &b, &w);
            edge[i].a = a, edge[i].b = b, edge[i].w = w;
        }
        int ans = Kruscal();
        int res = Ckruscal();
        if(!res) printf("Not Unique!\n");
        else printf("%d\n", ans);
    }
    //clock_t stop = clock();
    //printf("Time = %.2lfMS\n", (double)(stop - start) / CLOCKS_PER_SEC * 1000);
    return 0;
}
