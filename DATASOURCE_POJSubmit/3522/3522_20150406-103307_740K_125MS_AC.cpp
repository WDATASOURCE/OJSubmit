#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 10000
#define M (1 << 29)
using namespace std;

struct Edge{
    int a, b, w;

    friend bool operator < (const Edge &a, const Edge &b){
        return a.w < b.w;
    }
};

int par[110];
Edge edge[N];
int n, m;

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

int kruskal(int x){
    for(int i = 0; i < 110; i++) par[i] = i;
    int ansa = edge[x].w, ansb;
    int ne = 0;
    for(int i = x; i < m; i++){
        if(Union(edge[i].a, edge[i].b)){
            ansb = edge[i].w;
            ne++;
            if(ne == n - 1) return (ansb - ansa);
        }
    }
    return -1;
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF && n + m){
        for(int i = 0; i < m; i++)
            scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].w);
        sort(edge, edge + m);
        int ans = M;
        for(int i = 0; i <= m - n + 1; i++){
            int t = kruskal(i);
            if(t == -1) break;
            ans = ans > t ? t : ans;
        }
        if(ans == M) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}
