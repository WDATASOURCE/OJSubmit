#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1010
#define T 2010
#define MAX 0x3f3f3f3f
using namespace std;

int map[N][N], n, t;
int vis[N], low[N];


void Dijkstra(){
    int i, j, min, minp; 
    for(i = 1; i <= n; i++)
        vis[i] = 0;
    vis[1] = 1;
    minp = 1;
    for(i = 1; i <= n; i++)
        if(i != 1)
            low[i]= map[minp][i];
    //for(i = 1; i < n; i++){
    while(1){
        min = MAX;
        minp = -1;
        for(j = 1; j <= n; j++)
            if(vis[j] == 0 && min > low[j]){
                min = low[j];
                minp = j;
            }
        if(minp == -1) break;
        vis[minp] = 1;
        for(j = 1; j <= n; j++)
            if(vis[j] == 0 && low[j] > low[minp] + map[minp][j])
                low[j] = low[minp] + map[minp][j];
        if(n == minp) break;
    }
    printf("%d\n", low[n]);
}



int main(){
    int i, j;
    while(scanf("%d%d", &t, &n) == 2){
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                map[i][j] = MAX;
        while(t--){
            int v;
            scanf("%d%d%d", &i, &j, &v);
            map[j][i] = min(map[j][i], v);
            map[i][j] = min(map[i][j], v);
        }

        Dijkstra();
    }
    return 0;

}


/* 学长指导版
 *
#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1010
#define T 2010
#define MAX 0x3f3f3f3f
using namespace std;

int map[N][N], n, t;
int vis[N], low[N];


int Dijkstra(int s){
    int j, mi, mip; 
    fill(vis, vis + n + 1, 0);

    vis[s] = 1;
    for(j = 1; j <= n; j++) low[j] = map[s][j];

    while(1){
        mi = MAX, mip = -1;
        for(j = 1; j <= n; j++)
            if(!vis[j] && mi > low[j]){
                mi = low[j], mip = j;
            }
        if(mip == -1) break;

        vis[mip] = 1;
        for(j = 1; j <= n; j++)
            if(!vis[j] && low[j] > low[mip] + map[mip][j])
                low[j] = low[mip] + map[mip][j];
    }
    return low[n];
}


int main(){
    int i, j, v;
    while(scanf("%d%d", &t, &n) == 2){
        fill(map[1], map[n + 1], MAX);

        while(t--){
            scanf("%d%d%d", &i, &j, &v);
            map[j][i] = min(map[j][i], v);
            map[i][j] = min(map[i][j], v);
        }
        printf("%d\n", Dijkstra(1));
    }
    return 0;

}
 */
