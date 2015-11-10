#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 110
using namespace std;
struct line{
    int b, p;
};
int n, m;
int dp[N][N], mi[N];
line mp[N][N];

int main(){
    int i, j, t;
    scanf("%d", &t);
    while(t--){
        int ma = 0;
        fill(dp[0], dp[N], (1 << 30));
        scanf("%d", &n);
        for(i = 1; i <= n; i++){
            scanf("%d", &m);
            mi[i] = m;
            for(j = 1; j <= m; j++){
                scanf("%d%d", &mp[i][j].b, &mp[i][j].p);
                ma = max(ma, mp[i][j].b);
            }
        }
        for(i = 0; i <= ma; i++) dp[0][i] = 0;
        for(i = 1; i <= n; i++)
        for(j = 1; j <= mi[i]; j++)
        for(int k = 1; k <= mp[i][j].b; k++)
        dp[i][k] = min(dp[i][k], dp[i - 1][k] + mp[i][j].p);
        double ans = 0;  
        for(int i = 1;i <= ma; i++)  
        ans = max(ans, i * 1.0 / dp[n][i]);  
        printf("%.3f\n",ans);  
        }
    return 0;
    }
