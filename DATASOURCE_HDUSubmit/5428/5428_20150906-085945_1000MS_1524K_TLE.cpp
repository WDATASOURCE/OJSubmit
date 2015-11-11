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

int cnt = 0;
long long a[MAXN];
long long p[50];

long long solve(long long sum){
    for(int i = 2; i <= sum; i++)
        while(sum % i == 0) p[cnt++] = i, sum /= i;
    if(sum > 1) p[cnt++] = sum;

}
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        cnt = 0;
        int n;
        long long ans;
        scanf("%d", &n);
        long long sum = 1;
        long long v;
        for(int i = 0; i < n; i++){
            scanf("%lld", &v);
            solve(v);
        }

        sort(p, p + cnt);
        if(cnt < 2) ans = -1;
        else ans = p[0] * p[1];

        printf("%lld\n", ans);
    }
    return 0;
}
