#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 1005
#define Max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int v[N], w[N];
int dp[N];

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
        fill(dp, dp + N, 0);
        for(int i = 1; i <= n; i++)
            for(int j = V; j >= 0; j--){
                if(j < v[i]) break;
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        printf("%d\n", dp[V]);
    }
    return 0;
}
