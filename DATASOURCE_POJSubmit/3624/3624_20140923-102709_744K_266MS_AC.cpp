#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 3410
#define M 12890
using namespace std;
int v[N], w[N], n, c;
int mp[M];

int main(){
    int i, j, sum;
    while(scanf("%d%d", &n, &c) != EOF){
        fill(mp, mp + M, 0);
        for(i = 1; i <= n; i++)
            scanf("%d%d", &w[i], &v[i]);
        for(i = 1; i <= n; i++)                             // 注意从此处开始, 进行动态规划的操作,  
        for(j = c; j >= w[i]; j--)
            mp[j] = max(mp[j- w[i]] + v[i], mp[j]);
        printf("%d\n", mp[c]);
/* 或者可以用二维数组来实现  int mp[N][M];
        for(i = 1; i <= n; i++)
            for(j = 1; j <= c; j++){
                if(j >= w[i])
                mp[i][j] = max(mp[i - 1][j - w[i]] + v[i], mp[i- 1][j]);
                else
                mp[i][j] = mp[i - 1][j];
            }
        printf("%d\n", mp[n][c]);
*/
    }
    return 0;
}

