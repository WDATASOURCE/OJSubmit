#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

long long dp[1000100];

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        dp[1] = 1, dp[2] = 2;
        for(int i = 3; i <= n; i++){
            if(i & 1) dp[i] = dp[i - 1];
            else dp[i] = dp[i - 1] + dp[i / 2];
            if(dp[i] > 1000000000) dp[i] %= 1000000000;
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}
