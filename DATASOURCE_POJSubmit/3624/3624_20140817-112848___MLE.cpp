#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 3410
#define M 12890
using namespace std;
int v[N], w[N], n, c;
int mp[N][M];

int main(){
    int i, j, sum;
    while(scanf("%d%d", &n, &c) != EOF){
        fill(mp[0], mp[N], 0);
        for(i = 1; i <= n; i++)
            scanf("%d%d", &w[i], &v[i]);
        for(i = 1; i <= n; i++)
            for(j = 1; j <= c; j++){
                if(j >= w[i])
                mp[i][j] = mp[i - 1][j - w[i]] + v[i] > mp[i- 1][j] ? mp[i - 1][j - w[i]] + v[i] : mp[i - 1][j];
                else
                mp[i][j] = mp[i - 1][j];
            }
        printf("%d\n", mp[n][c]);
    }
    return 0;
}
