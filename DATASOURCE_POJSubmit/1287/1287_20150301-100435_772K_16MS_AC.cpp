#include <cstdio>
#include <iostream>
#include <algorithm>
#define M (1 << 30)
#define N 10000
using namespace std;

struct Edge{
    int a, b, w;

    friend bool operator < (const Edge &a, const Edge &b){
        return a.w < b.w;
    }
};

int par[N], n, m, e;
Edge edge[N];

void init(){
    e = 0;
    for(int i = 0; i < N; i++)
        par[i] = i;
}

int find(int x){
    if(par[x] != x) par[x] = find(par[x]);
    return par[x];
}

bool Union(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy) return false;
    else{
        par[fx] = fy;
        return true;
    }
}

int Kruscal(){
    int ne = 0, ans = 0;
    sort(edge, edge + e);
    for(int i = 0; i < e; i++)
        if(Union(edge[i].a, edge[i].b)){ 
            ans += edge[i].w;
            ne++;
            if(ne == n - 1) break;
        }
    if(ne == n - 1) return ans;
    return -1;
}


int main(){
    while(scanf("%d", &n) != EOF && n){
        scanf("%d", &m);
        int a, b, w;
        init();
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &a, &b, &w);
            edge[e].a = a, edge[e].b = b, edge[e++].w = w;
            edge[e].b = a, edge[e].a = b, edge[e++].w = w;
        }
        int ans = Kruscal();
        printf("%d\n", ans);
    }
    return 0;
}
