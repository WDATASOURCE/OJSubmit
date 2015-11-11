/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-07-09 08:06
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
#define Max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int a[110][110];
int b[110];
int dp[110][110];
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &a[i][j]);
        for(int i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        fill(dp[0], dp[110], 0);

        for(int i = 2; i <= n; i++){
            if(b[i] != -1){
                if(b[i - 1] != -1){
                    dp[i][b[i]] = dp[i - 1][b[i - 1]] + a[b[i - 1]][b[i]];
                }else{
                    for(int k = 1; k <= m; k++)
                        dp[i][b[i]] = Max(dp[i - 1][k] + a[k][b[i]], dp[i][b[i]]);
                }
            }else{
                for(int j = 1; j <= m; j++){
                    if(b[i - 1] != -1){
                        dp[i][j] = dp[i - 1][b[i - 1]] + a[b[i - 1]][j];
                    }else{
                        for(int k = 1; k <= m; k++)
                            dp[i][j] = Max(dp[i][j], dp[i - 1][k] + a[k][j]);
                    }
                }
            }
        }

        /*
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= m; j++)
                printf("%d ", dp[i][j]);
            printf("\n");
        }
        cerr << endl << endl;
        */


        int ans = 0;
        for(int i = 1; i <= m; i++)
            ans = Max(ans, dp[n][i]);
        printf("%d\n", ans);
    }
    return 0;
}