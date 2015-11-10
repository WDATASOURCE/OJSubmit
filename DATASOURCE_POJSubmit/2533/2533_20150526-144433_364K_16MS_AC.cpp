/*=============================================================================
# Author:			He Shuwei
# Last modified:	2015-05-25 11:32
# Filename:			a.cpp
# Description:      
=============================================================================*/
 
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#define Max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int a[1100];
int dp[1100];

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++){
            dp[i] = 1;
            for(int j = i - 1; j > 0; j--)
                if(dp[i] <= dp[j] && a[i] > a[j]) dp[i] = dp[j] + 1;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans = Max(ans, dp[i]);
        printf("%d\n", ans);
    }
    return 0;
}
