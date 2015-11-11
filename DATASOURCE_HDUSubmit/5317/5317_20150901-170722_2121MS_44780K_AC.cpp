/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-09-01 16:18
# Filename:         a.cpp
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
const int MAXN =1000010;

int F[MAXN];
int dp[MAXN][10];

int GCD(int l, int r){
    if(l > r) return GCD(r, l);
    if(l == 0) return r;
    return GCD(r % l, l);
}

void init(){
    memset(F, 0, sizeof(F));
    memset(dp, 0, sizeof(dp));
    for(int i = 2; i < MAXN; i++){
        if(F[i]) continue;
        for(int j = 1; i * j < MAXN; j++)
            F[i * j]++;
    }

    dp[2][1] = 1;
    for(int i = 3; i < MAXN; i++){
        for(int j = 0; j < 10; j++){
            if(j == F[i]) dp[i][j] = dp[i - 1][j] + 1;
            else dp[i][j] = dp[i - 1][j];
        }
    }
}
 
int main(){
    init();
    //int tt = 0;
    //for(int i = 0; i < MAXN; i++)
        //tt = max(tt, F[i]);
    //cerr <<"tt = "<< tt << endl;
    int T;
    scanf("%d", &T);
    while(T--){
        int l, r;
        scanf("%d%d", &l, &r);
        int ans = 1;

        for(int i = 1; i < 10; i++)
            for(int j = 1; j < 10; j++)
                if((dp[r][i] - dp[l - 1][i]) && (dp[r][j] - dp[l - 1][j])){
                    if(i == j && dp[r][i] - dp[l - 1][i] <= 1) continue;
                    ans = max(ans, GCD(i, j));
                }

        printf("%d\n", ans);
    }
    return 0;
}
