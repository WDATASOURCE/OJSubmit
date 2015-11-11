#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define eps 1e-8
#define randin srand((unsigned int)time(NULL))
#define input freopen("input.txt","r",stdin)
#define debug(s) cout << "s = " << s << endl;
#define outstars cout << "*************" << endl;
const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const int INF = 0x7fffffff;
typedef long long ll;

const int maxn = 40;
const int maxm = 1800;

int num[maxn][maxn];
int vis[maxn][maxn][maxm];
int dp[maxn][maxn][maxm];
int n, m;

int main() {

    //input;
    int T, _t = 1;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m);
        int len = n + m - 1;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                scanf("%d", &num[i][j]);
            }
        }
        memset(dp, 0x3f, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        int tmp = 0;
        for (int j = 0; j <= m; j ++) {
            for (int sum = 0; sum <= maxm; sum ++) {
                dp[0][j][sum] = 0;
            }
        }
        for (int i = 0; i <= n; i ++) {
            for (int sum = 0; sum <= maxm; sum ++) {
                dp[i][0][sum] = 0;
            }
        }
        for (int j = 1; j <= m; j ++) {
            tmp += num[1][j];
            vis[1][j][tmp] = true;
            dp[1][j][tmp] = dp[1][j-1][tmp-num[1][j]] + len * num[1][j] * num[1][j];
        }
        tmp = 0;
        for (int i = 1; i <= n; i ++) {
            tmp += num[i][1];
            vis[i][1][tmp] = true;
            dp[i][1][tmp] = dp[i-1][1][tmp-num[i][1]] + len * num[i][1] * num[i][1];
        }
        for (int i = 2; i <= n; i ++) {
            for (int j = 2; j <= m; j ++) {
                for (int sum = 0; sum <= maxm; sum ++) {
                    if (sum - num[i][j] >= 0) {
                        if (vis[i-1][j][sum-num[i][j]]) {
                            dp[i][j][sum] = min(dp[i][j][sum], dp[i-1][j][sum-num[i][j]] + len * num[i][j] * num[i][j]);
                            vis[i][j][sum] = true;
                        }
                        if (vis[i][j-1][sum-num[i][j]]) {
                            dp[i][j][sum] = min(dp[i][j][sum], dp[i][j-1][sum-num[i][j]] + len * num[i][j] * num[i][j]);
                            vis[i][j][sum] = true;
                        }
                    }
                }
            }
        }
        int ans = inf;
        for (int sum = 0; sum <= maxm; sum ++) {
            if (vis[n][m][sum]) {
                ans = min(ans, dp[n][m][sum] - sum * sum);
            }
        }
        printf("Case #%d: %d\n", _t ++, ans);
    }

    return 0;
}