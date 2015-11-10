#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
#include<math.h>
#include<string.h>
#define N 505
#define M 3000
#define W 205
#define INF 1<<29
using namespace std;

struct edge{
    int from, to, cost;
};

edge es[M];
int low[N], n, m, w;

bool ford(){
    int i, j, f = 1, cnt = 1;
    fill(low, low + n + 1, INF);
    while(f){
        f = 0;
        if(cnt++ > n) return true;
        for(i = 0; i < m; i++){
            if(low[es[i].from] + es[i].cost < low[es[i].to]){   
                low[es[i].to] = low[es[i].from] + es[i].cost;
                f = 1;
            }
            if(low[es[i].to] + es[i].cost < low[es[i].from]){
                low[es[i].from] = low[es[i].to] + es[i].cost;
                f = 1;
            }
        }
        for(; i < m + w; i++)
            if(low[es[i].to] + es[i].cost < low[es[i].from]){
                low[es[i].from] = low[es[i].to] + es[i].cost;
                f = 1;
            }

    }
    return false;
}

int main(){
    int i, j, t, v;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &n, &m, &w);
        for(i = 0; i < m; i++)
            scanf("%d%d%d", &es[i].from, &es[i].to, &es[i].cost);
        for(i = m; i < m + w; i++){
            scanf("%d%d", &es[i].from, &es[i].to);
            scanf("%d", &v);
            es[i].cost = -v;
        }
        if(ford())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}