#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 2000
#define Max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int a[N];
int n, V;
int dp[N];

int main(){
    while(scanf("%d", &n) != EOF && n){
        fill(dp, dp + N, 0);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        int ma = a[n];
        scanf("%d", &V);
        if(V < 5){
            printf("%d\n", V);
            continue;
        }
        for(int i = 1; i < n; i++)
            for(int j = V - 5; j >= a[i]; j--)
                dp[j] = Max(dp[j], dp[j - a[i]] + a[i]);
        printf("%d\n", V - dp[V - 5] - ma);
    }
    return 0;
}
