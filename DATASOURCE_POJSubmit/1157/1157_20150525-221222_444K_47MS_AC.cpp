/*=============================================================================
# Author:			He Shuwei
# Last modified:	2015-05-25 11:32
# Filename:			a.cpp
# Description:      求最长公共子序列，注意记录路径的方法
=============================================================================*/
 
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#define Max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int mp[110][110];
int dp[110][110];

int main(){
    int f, v;
    while(scanf("%d%d", &f, &v) != EOF){
        for(int i = 1; i <= f; i++)
            for(int j = 1; j <= v; j++)
                scanf("%d", &mp[i][j]);
        fill(dp[0], dp[110], 0);
        for(int i = 1; i <= f; i++)
            dp[i][i] = dp[i - 1][i - 1] + mp[i][i];
        for(int i = 2; i <= v; i++)
            dp[1][i] = Max(dp[1][i - 1], mp[1][i]);
        for(int i = 2; i <= f; i++)
            for(int j = i + 1; j <= v; j++)
                dp[i][j] = Max(dp[i - 1][j - 1] + mp[i][j], dp[i][j - 1]);
        printf("%d\n", dp[f][v]);
    }
    return 0;
}
