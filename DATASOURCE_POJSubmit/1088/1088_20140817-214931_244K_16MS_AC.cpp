#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 105
using namespace std;
int mp[N][N], dp[N][N];
int dima[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int r, c;

int Dp(int i, int j){
    if(dp[i][j] != 0)
        return dp[i][j];
    int s, ma = 0; 
    for(int t = 0; t < 4; t++){
        int temx = i + dima[t][0], temy = j + dima[t][1];
        if(temx >= 0 && temx < r && temy >= 0 && temy < c && mp[temx][temy] < mp[i][j])
            ma = max(Dp(temx, temy), ma);
    }
    dp[i][j] = ++ma;
    return ma;
}

int main(){
    int i, j;
    while(scanf("%d%d", &r, &c) != EOF){
        fill(dp[0], dp[N], 0);
        int ans = 0;
        for(i = 0; i < r; i++)
            for(j = 0; j < c; j++)
                scanf("%d", &mp[i][j]);
        for(i = 0; i < r; i++)
            for(j = 0; j < c; j++)
                ans = max(Dp(i, j), ans);
        printf("%d\n", ans);
    }
    return 0;
}
