/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-07-22 19:53
# Filename:         d.cpp
# Description: 
=============================================================================*/
 
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
const int maxn = 100010;
const int maxa = 10010;
const int MOD = 1000000007;
int num[maxn];
int l[maxn], r[maxn];
int pos[maxa]; 
int n;

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; i ++) scanf("%d", &num[i]);
        memset(pos, 0, sizeof(pos));
        for (int i = 1; i <= n; i ++) {
            l[i] = 0;
            for (int j = 1; j * j <= num[i]; j ++) {
                if (num[i] % j == 0) {
                    if (pos[j]) l[i] = max(l[i], pos[j]);
                    if (pos[num[i] / j]) l[i] = max(l[i], pos[num[i] / j]);
                }
                pos[num[i]] = i;
            }
        }
        memset(pos, 0, sizeof(pos));
        for (int i = n; i >= 1; i --) {
            r[i] = n + 1;
            for (int j = 1; j * j <= num[i]; j ++) {
                if (num[i] % j == 0) {
                    if (pos[j]) r[i] = min(r[i], pos[j]);
                    if (pos[num[i] / j]) r[i] = min(r[i], pos[num[i] / j]);
                }
                pos[num[i]] = i;
            }
        }
        long long ans = 0;
        for (int i = 1; i <= n; i ++) {
            ans = (ans + ((long long)(i - l[i]) % MOD) * ((long long)(r[i] - i) % MOD)) % MOD;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
