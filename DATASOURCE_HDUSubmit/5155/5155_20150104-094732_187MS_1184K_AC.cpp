#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define M 55
const int MOD = 1000000007;
using namespace std;
int dp[M][M];
int C[M][M];


int main(){
    int n, m;
    C[0][0] = 1;
    for(int i = 1; i < M; i++){
        C[i][0] = 1;
        for(int j = 1; j <= i; j++){
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
    while(~scanf("%d%d", &n, &m)){
        fill(dp[0], dp[M], 0);
        dp[0][0] = 1;
        for(int i = 0; i < n; i++){   // i ²ã
            for(int j = 0; j <= m; j++){ // ÒÑÍ¿¸öÊý
                for(int k = 1; k <= m; k++){ // i + 1 Í¿µÄ¸öÊý
                    for(int l = min(j, k); l >= 0; l--){ // i + 1 ²ã·ÖÅäµ½ J µÄ¸öÊý
                        if(j + k - l > m) break;
                        dp[i + 1][j + k - l] += 1LL * dp[i][j] * C[j][l] % MOD * C[m - j][k - l] % MOD;
                        dp[i + 1][j + k - l] %= MOD;
                    }

                }
            }

        }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}