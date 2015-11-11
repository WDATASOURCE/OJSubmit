/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-05 14:14
# Filename:         a.cpp
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
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
#define ABS(x) ((x) > 0 ? (x) : (-(x)))
using namespace std;

int n, m;
int a[22][550];
int dp[22][550];
 
int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &a[i][j]);
        fill(dp[0], dp[22], (1 << 29));

        for(int j = 1; j <= m; j++)
            dp[1][a[1][j]] = 0;

        for(int i = 2; i <= n; i++)
            for(int j = 1; j <= m; j++){
                int mi = (1 << 29);
                for(int k = 1; k <= m; k++)
                    mi = min(mi, dp[i - 1][a[i - 1][k]] + ABS(a[i - 1][k] - a[i][j]));
                dp[i][a[i][j]] = mi;
            }

        int ans = (1 << 29);
        for(int j = 1; j <= m; j++)
            ans = min(ans, dp[n][a[n][j]]);
        printf("%d\n", ans);
    }
    return 0;
}
