#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 1005
using namespace std;

int v[N], w[N];
int dp[N][N];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, V;
        scanf("%d%d", &n, &V);
        for(int i = 1; i <= n; i++)
            scanf("%d", &w[i]);
        for(int i = 1; i <= n; i++)
            scanf("%d", &v[i]);
        for(int i = 0; i <= n; i++)
            dp[0][i] = dp[i][0] = 0;

        for(int i = 1; i <= n; i++)
            for(int j = 0; j <= V; j++){
                if(j < v[i]) dp[i][j] = 0;
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
            }
        printf("%d\n", dp[n][V]);
    }
    return 0;
}
