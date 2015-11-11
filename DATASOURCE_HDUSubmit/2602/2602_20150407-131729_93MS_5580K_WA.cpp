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
        fill(dp[0], dp[N], 0);
        for(int i = 1; i <= n; i++)
            for(int j = v[i]; j <= V; j++){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
            }
        printf("%d\n", dp[n][V]);
    }
    return 0;
}
