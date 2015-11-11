/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-05-23 00:41
# Filename:         c.cpp
# Description: 
=============================================================================*/
 
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define Min(a, b) ((a) > (b) ? (b) : (a))
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define IsC(a, b, c) ((a) + (b) > c ? (a) : (a) + (b))
using namespace std;

int ma[110][110];
int dp[110][110][110];
 
int main(){
    int n, m, kk;
    while(scanf("%d%d%d", &n, &m, &kk) != EOF){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &ma[i][j]);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                for(int k = kk; k >= 0; k--){
                    if(k < ma[i][j])
                        dp[i][j][k] = Max(dp[i - 1][j][k], dp[i][j - 1][k]);
                    else dp[i][j][k] = Max(Max(dp[i - 1][j][k], dp[i][j - 1][k]), Max(dp[i - 1][j][k - ma[i][j]] + ma[i][j], dp[i][j - 1][k - ma[i][j]] + ma[i][j]));
                }
        int ans = 0;
        for(int i = 0; i < 110; i++)
            ans = Max(ans, dp[n][m][i]);
        printf("%d\n", ans);
    }
    return 0;
}
