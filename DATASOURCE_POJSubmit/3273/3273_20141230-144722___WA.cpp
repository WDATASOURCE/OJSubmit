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

int a[N], n, m;

bool judge(long long sum){
    long long t = 0;
    int id = m;
    for(int i = 0; i < n; i++){
        if(t + a[i] <= sum) t += a[i];
        else id--, t = a[i];
    }
    if(id >= 0) return true;
    return false;
}

long long find(long long l, long long r){
    while(r - l > 1){
        long long mid = (l + r) >> 1;
        if(!judge(mid)) l = mid;
        else r = mid;
    }
    return r;
} 
 
int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        long long sum = 0;
        long long mi = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            sum += a[i];
            mi = mi > a[i] ? mi : a[i];
        }
        //cerr <<"mi = "<< mi <<" sum = " << sum << endl;
        long long ans = find(mi - 1, sum + 1);
        printf("%I64d\n", ans);
    }
    return 0;
}
