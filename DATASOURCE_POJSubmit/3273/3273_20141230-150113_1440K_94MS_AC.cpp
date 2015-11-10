/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-12-30 14:29
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
#define N 100010
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

int a[N], sum[N], n, m;

bool judge(int s){
    int b = 0, di = m;
    for(int i = 0; i < n; i++){
        if(sum[i] - b > s){
            b = sum[i - 1];
            di--;
        }
    }
    if(di <= 0) return false;
    return true;
}

int find(int l, int r){
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if(!judge(mid)) l = mid;
        else r = mid;
    }
    return r;
} 
 
int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        fill(sum, sum + n, 0);
        int mi = 0, s = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            s += a[i];
            sum[i] = s;
            mi = mi > a[i] ? mi : a[i];
        }
        int ans = find(mi - 1, s);
        printf("%d\n", ans);
    }
    return 0;
}
