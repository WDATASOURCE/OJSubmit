#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 1100
#define M (1 << 29)
#define Min(a, b) (a > b ? b : a)
#define Max(a, b) (a > b ? a : b)
using namespace std;

int mp[N][N], dis[N][N];
int path[N], pre[N][N];
int n, m, minc, num;

void init(){
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++){
            mp[i][j] = M;
            dis[i][j] = M;
            pre[i][j] = i;
        }
    int a, b, w;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &w);
        if(w < mp[a][b])
            dis[a][b] = dis[b][a] = mp[a][b] = mp[b][a] = w;
    }
}

void Floyd(){
    minc = M;
    for(int k = 1; k <= n; k++){
        for(int i = 1; i < k; i++)
            for(int j = i + 1; j < k; j++)
                if(minc > dis[i][j] + mp[j][k] + mp[k][i]){
                    minc = dis[i][j] + mp[j][k] + mp[k][i];
                    num = 0;
                    int t = j;
                    while(t != i){
                        path[num++] = t;
                        t = pre[i][t];
                    }
                    path[num++] = i;
                    path[num++] = k;
                }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(dis[i][j] > dis[i][k] + dis[k][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                    pre[i][j] = pre[k][j];
                }
    }
}

int main(){
    while(scanf("%d%d", &n, &m) !=EOF){
        init();
        Floyd();
        if(minc == M) printf("No solution.\n");
        else{
            printf("%d", path[0]);
            for(int i = 1; i < num; i++)
                printf(" %d", path[i]);
            printf("\n");
        }
    }
    return 0;
}
