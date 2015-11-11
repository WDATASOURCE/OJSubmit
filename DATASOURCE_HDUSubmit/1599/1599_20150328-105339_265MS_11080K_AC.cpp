#include <cstdio>
#include <algorithm>
#define N 1100
#define M (1 << 29)
#define Min(a, b) (a > b ? b : a)
using namespace std;
int mp[N][N], dis[N][N];
int n, m;

int Flody(){
    int ans = M;

    for(int k = 1; k <= n; k++){
        for(int i = 1; i < k; i++)
            for(int j = i + 1; j < k; j++)
                ans = Min(ans, dis[i][j] + mp[j][k] + mp[k][i]);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dis[i][j] = Min(dis[i][j], dis[i][k] + dis[k][j]);
    }
    return ans;
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        fill(mp[0], mp[N], M);
        fill(dis[0], dis[N], M);
        int a, b, w;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &a, &b, &w);
            if(w < mp[a][b])
                dis[a][b] = dis[b][a] = mp[a][b] = mp[b][a] = w;
        }

        int ans = Flody();

        if(ans ==  M) printf("It's impossible.\n");
        else printf("%d\n", ans);
    }
    return 0;
}
