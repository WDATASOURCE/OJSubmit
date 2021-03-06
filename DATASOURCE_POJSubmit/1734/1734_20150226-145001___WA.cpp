#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 105;
const int INF = 10000000;

int dist[N][N], g[N][N];
int fa[N][N], path[N];

int n, m, num, minc;

void Floyd(){
    int i, j, k, p, tmp;
    minc = INF;
    for(k = 1; k <= n; k++) {
        for(i = 1; i < k; i++)
            for(j = i + 1; j < k; j++) {
                tmp = dist[i][j] + g[i][k] + g[k][j];
                if(tmp < minc){ //找到更优解
                    minc = tmp;
                    num = 0;
                    p = j;
                    while(p != i){ //逆向寻找前驱结点直到找到最前面的i, i->…->j
                        path[num++]=p;
                        p = fa[i][p];//fa[i][j]保存的不是k, 而是fa[k][j].
                    }
                    path[num++] = i;
                    path[num++] = k;
                }
            }
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++) {
                tmp = dist[i][k] + dist[k][j];
                if(dist[i][j] > tmp) {
                    dist[i][j] = tmp;
                    fa[i][j] = fa[k][j];
                }
            }
    }
}

int main() {
    int i, j, u, v, w;
    while(~scanf("%d%d", &n, &m)) {
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++) {
                g[i][j] = INF;
                dist[i][j] = INF;
                fa[i][j] = i;
            }
        for(i = 1; i <= m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            w = min(g[u][v], w);          //处理重边
            g[u][v] = g[v][u] = dist[u][v] = dist[v][u] = w;
        }
        Floyd();
        if(minc == INF) printf("It's impossible.\n");
        else {
            //printf("%d\n", minc);
            printf("%d", path[0]);
            for(i=1;i<num;i++)
                printf(" %d", path[i]);
            printf("\n");
        }
    }
    return 0;
}
