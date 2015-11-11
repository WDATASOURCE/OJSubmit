/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-07-10 20:56
# Filename:         b.cpp
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
#define Min(a, b) ((a) > (b) ? (b) : (a))
using namespace std;

int a[220];
int b[220];
int dp[220][220];
 
int main(){
    int t;
    scanf("%d", &t);
    for(int dx = 1; dx <= t; dx++){
        int n;
        scanf("%d", &n);
        a[0] = b[0] = 0;
        a[n + 1] = b[n + 1] = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        fill(dp[0], dp[220], (1 << 29));
        for(int l = 1; l <= n; l++){
            for(int i = 1; i <= n; i++){
                int j = i + l - 1;
                if(j > n) break;
                if(i == j) dp[i][i] = a[i] + b[i - 1] + b[i + 1];
                for(int k = i; k < j; k++){
                    dp[i][j] = Min(dp[i][k] + dp[k + 1][j] - b[k + 1] + b[j + 1], dp[i][j]);
                    dp[i][j] = Min(dp[i][k] + dp[k + 1][j] - b[k] + b[i - 1], dp[i][j]);
                }
            }
        }
        printf("Case #%d: %d\n", dx, dp[1][n]);
        /*
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++)
                printf("%d ", dp[i][j]);
            printf("\n");
        }
        &*/
    }
    return 0;
}

