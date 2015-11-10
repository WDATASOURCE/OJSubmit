#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 305
#define M (1 << 30)
using namespace std;

int mp[N][N];
int n, m, t;

void floyd(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                if(mp[i][k] != M && mp[k][j] != M && mp[i][j] > max(mp[i][k], mp[k][j]))
                    mp[i][j] = max(mp[i][k], mp[k][j]);
            }
}


int main(){
    int a, b, v;
    while(scanf("%d%d%d", &n, &m, &t) != EOF){
        fill(mp[0], mp[N], (1 << 30));
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &a, &b, &v);
            mp[a][b] = v;
        }
        floyd();
        while(t--){
            scanf("%d%d", &a, &b);
            if(mp[a][b] != M) printf("%d\n", mp[a][b]);
            else printf("-1\n");
        }
    }
    return 0;
}
