/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-09-04 19:32
# Filename: 		a.cpp
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
const int MAXN = 100010;

int n, q;
int a[MAXN];
int cnt[MAXN];
int dp[MAXN][20];

void ST(){

    for(int i = 1; i <= n; i++)
        dp[i][0] = cnt[i];

    for(int j = 1; j < 20; j++)
        for(int i = 1; i + (1 << j) - 1 <= n; i++)
            dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
}

int RMQ(int l, int r){
    if(l > r) return 0;
    int k = log((double)(r - l + 1)) / log(2.0);
    return max(dp[l][k], dp[r - (1 << k) + 1][k]);
}
 
int main(){
    a[0] = -1000000;
    while(~scanf("%d", &n) && n){
        memset(cnt, 0, sizeof(cnt));
        scanf("%d", &q);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        for(int i = 1; i <= n; i++){
            if(a[i] == a[i - 1]) cnt[i] = cnt[i - 1] + 1;
            else cnt[i]++;
        }

        ST();

        int l, r;
        for(int i = 0; i < q; i++){
            scanf("%d%d", &l, &r);
            //cerr <<"l = "<< l <<", r = "<< r << endl;
            int tmp = l;
            while(tmp <= r && a[tmp] == a[tmp - 1]) tmp++;
            int res = RMQ(tmp, r);
            //cerr <<"tmp = "<< tmp <<", res = "<< res << endl;
            int ans = max(tmp - l, res);
            printf("%d\n", ans);
        }
    }
    return 0;
}
