#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define N 25
using namespace std;

int a[N];
int dp[N][N];

int main(){
    int i, j, n, b, ans, sum;
    while(scanf("%d%d", &n, &b) != EOF){
        for(i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            sum += a[i];
        }
        int c = sum - b;
        fill(dp[0], dp[N], 0);
        for(i = 1; i <= n; i++)
        for(j = 1; j <= c; j++){
            if(j >= a[i])
            dp[i][j] = max(dp[i - 1][j - a[i]] + a[i], dp[i - 1][j]);
            else
            dp[i][j] = dp[i - 1][j];
        } 
        printf("%d\n", dp[n][c]);
    }
    return 0;
}
