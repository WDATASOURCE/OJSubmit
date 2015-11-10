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

double func(int n){
    double ans = 0.0;
    for(int i = 1; i <= n; i++)
        ans += log((double)i);
    return ans;
}
 
int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        if(n == 0 && m == 0)
            break;
        double t = func(n) - func(m) - func(n - m);
        int ans = pow(E, t);
        printf("%d\n", ans);
    }
    return 0;
}
