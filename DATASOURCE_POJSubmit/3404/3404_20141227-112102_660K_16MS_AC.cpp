/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-12-27 10:46
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
#define N 100
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

int a[N], n;

int solve(){
    if(n == 1) return a[0];
    if(n == 2) return a[1];
    if(n == 3) return a[0] + a[1] + a[2];
    int ans = 0, j;
    int t = 2 * a[1] + a[0];
    for(j = n - 1; j > 2; j -= 2){
        int cmp1 = t + a[j];
        int cmp2 = 2 * a[0] + a[j] + a[j - 1];
        ans += min(cmp1, cmp2);
    }
    if(j == 1) ans += a[1];
    if(j == 2) ans += a[0] + a[1] + a[2];
    return ans;
}
 
int main(){
    while(~scanf("%d", &n)){
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        printf("%d\n", solve());
    }
    return 0;
}
