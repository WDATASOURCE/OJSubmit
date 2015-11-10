#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 1100
#define E 15100
#define M (1 << 29)
using namespace std;

struct Edge{
    int a, b, w;

    friend bool operator < (const Edge &a, const Edge &b){
        return a.w < b.w;
    }
};

int par[N], n, m;
Edge edge[E];

void init(){
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
    par[fx] = fy;
    return true;
}

void kruskal(){
    int ans = 0;
    queue<Edge> que;
    sort(edge, edge + m);
    for(int i = 0; i < m; i++){
        if(Union(edge[i].a, edge[i].b)){
            //cerr <<"i = "<< i <<", a = "<< edge[i].a <<", b = "<< edge[i].b << endl;
            ans = ans > edge[i].w ? ans : edge[i].w;
            que.push(edge[i]);
        }
    }
    printf("%d\n", ans);
    printf("%d\n", n - 1);
    while(!que.empty()){
        printf("%d %d\n", que.front().a, que.front().b);
        que.pop();
    }
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        for(int i = 0; i < m; i++)
            scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].w);
        kruskal();
    }
    return 0;
}
