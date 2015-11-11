/*=============================================================================
# Author:           He Shuwei
# Last modified:    2015-08-12 11:46
# Filename:            a.cpp
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
const int MAXN = 200020;

int dp[MAXN][2];
char ch[MAXN];
int val[MAXN];
 
int main(){
    int t;
    scanf("%d", &t);
    for(int dx = 1; dx <= t; dx++){
        scanf("%s", ch + 1);
        ch[0] = '0';
        int len = strlen(ch);
        for(int i = 1; i < len; i++)
            scanf("%d", &val[i]);

        for(int i = 1; i < len; i++){
            if(ch[i] != '?'){
                if(ch[i - 1] == '?')
                    dp[i][0] = dp[i][1] = (max(dp[i - 1][0] + (0 ^ (ch[i] - '0')) * val[i], dp[i - 1][1] + (1 ^ (ch[i] - '0')) * val[i]));
                else 
                    dp[i][0] = dp[i][1] = (max(dp[i - 1][0] + ((ch[i - 1] - '0') ^ (ch[i] - '0')) * val[i], dp[i - 1][1] + ((ch[i - 1] - '0')  ^ (ch[i] - '0')) * val[i]));
            }else{ 
                if(ch[i - 1] == '?'){
                    for(int j = 0; j < 2; j++)
                        dp[i][j] = max(dp[i - 1][0] + (0 ^ j) * val[i], dp[i - 1][1] + (1 ^ j) * val[i]);
                }else{
                    for(int j = 0; j < 2; j++)
                        dp[i][j] = max(dp[i - 1][0] + ((ch[i - 1] - '0') ^ j) * val[i], dp[i - 1][1] + ((ch[i - 1] - '0') ^ j) * val[i]);
                }
            }
        }

        //for(int i = 0; i < len; i++)
            //for(int j = 0; j < 2; j++)
                //printf("%d%c", dp[i][j], j == 1 ? '\n' : ' ');

        int ans = max(dp[len - 1][0], dp[len - 1][1]);
        printf("Case #%d: %d\n", dx, ans);
    }
    return 0;
}
