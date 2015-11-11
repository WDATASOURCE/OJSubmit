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
    int a, b, w;
};

Edge edge[N];
int dis[N];
int n, m, e;

void Ford(int s){
    for(int i = 0; i <= n; i++)
        dis[i] = (i == s ? 0 : M);
    bool flag = 1;
    for(int i = 1; i < n && flag; i++){
        flag = 0;
        for(int j = 0; j < e; j++){
            int temp = dis[edge[j].a] + edge[j].w;
            if(dis[edge[j].b] > temp){
                dis[edge[j].b] = temp;
                flag = 1;
            }
        }
    }
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF && n + m){
        e = 0;
        int a, b, w;
        for(int i= 0; i < m; i++){
            scanf("%d%d%d", &a, &b, &w);
            edge[e].a = a, edge[e].b = b, edge[e++].w = w;
            edge[e].b = a, edge[e].a = b, edge[e++].w = w;
        }
        Ford(1);
        printf("%d\n", dis[n]);
    }
    return 0;
}
