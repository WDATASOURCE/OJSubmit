/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-09-06 08:23
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
const int MAXN = 220;

long long a[MAXN];
long long p[50];

long long solve(long long sum){
    int cnt = 0;
    for(int i = 2; i <= sum; i++)
        while(sum % i == 0) p[cnt++] = i, sum /= i;
    if(sum > 1) p[cnt++] = sum;

    if(cnt < 2) return -1;
    return p[0] * p[1];
}
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        long long sum = 1;
        long long v;
        for(int i = 0; i < n; i++){
            scanf("%lld", &v);
            sum *= v;
        }

        long long ans = solve(sum);
        printf("%lld\n", ans);
    }
    return 0;
}
