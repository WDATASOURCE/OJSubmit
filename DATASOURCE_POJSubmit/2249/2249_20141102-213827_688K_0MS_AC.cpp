/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-11-02 14:26
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
#define E 2.718281828459045 
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

int func(int n, int m){
    if(n - m < m)
        m = n - m;
    int i, j;
    long long ans = 1;
    for(i = 0, j = 1; i < m; i++){
        ans *= (n - i);
        for(; j <= m && ans % j == 0; j++)
            ans /= j;
    }
    return (int)ans;
}

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        if(n == 0 && m == 0)
            break;
        int ans = func(n, m);
        printf("%d\n", ans);
    }
    return 0;
}
