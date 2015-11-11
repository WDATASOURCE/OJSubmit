/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-09-01 15:01
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
long long n;

void dfs(long long l, long long r){
    //cerr <<"l = "<< l <<", r = "<< r << endl;
    if(l == 0){
        if(n == -1) n = r;
        else n = min(n, r);
    }
    if(l > r) return;
    if(n != -1 && r >= n) return;
    if(l < 0) return;
    if(r - l + 1 > (l - 1) * 2) return;
    dfs((l - 1) * 2 - r, r);
    dfs((l - 1) * 2 - r + 1, r);
    dfs(l, 2 * r - l);
    dfs(l, 2 * r - l + 1);
}

int main(){
    long long l, r;
    while(scanf("%lld%lld", &l, &r) != EOF){
        n = -1;
        dfs(l, r);
        printf("%lld\n", n);
    }
    return 0;
}