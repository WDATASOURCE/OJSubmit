#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <bitset>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define FI first
#define SE second
using namespace std;
typedef long long LL;
const int N = 2e5 + 5;
int a[N];
LL sum[N], s1[N], s2[N];

int main() {
    int n, W, H;
    while(~scanf("%d%d%d", &n, &W, &H)) {
        int L = W + 1, R = W + n;
        n = R + W;
        for(int i = 1; i < L; ++i) a[i] = 0;
        for(int i = L; i <= R; ++i) scanf("%d", a + i);
        for(int i = R + 1; i <= n; ++i) a[i] = 0;
        for(int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + a[i];
            s1[i] = s1[i - 1];
            s2[i] = s2[i - 1];
            if(a[i] > H) s1[i] += a[i] - H;
            else s2[i] += H - a[i];
        }
        if(sum[n] < 1LL * W * H) {
            puts("-1");
            continue;
        }
        LL ans = 1LL * W * H;
        for(int i = W; i <= n; ++i) {
            int l = i - W + 1, r = i;
            if(sum[r] - sum[l - 1] > 1LL * W * H) {
                ans = min(ans, s1[r] - s1[l - 1]);
            }
            else {
                ans = min(ans, s2[r] - s2[l - 1]);
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}