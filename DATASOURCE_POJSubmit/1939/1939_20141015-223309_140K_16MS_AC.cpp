/*=============================================================================
# Author:			He Shuwei
# Last modified:	2014-10-15 21:37
# Filename:			a.cpp
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

int main(){
    long long a, b, c, d, e, f;
    int n;
    while(scanf("%d", &n) != EOF){
        double x, y;
        scanf("%lld%lld", &a, &b);
        scanf("%lld%lld", &c, &d);
        x = (double)(a + c) / 2.0;
        y = (double)(b + d) / 2.0;
        printf("%d %.6f %.6f", n, x, y);
        for(int i = 0; i < n - 2; i++){
            scanf("%lld%lld", &e, &f);
            x = (double)(c + e) / 2.0;
            y = (double)(d + f) / 2.0;
            printf(" %.6f %.6f", x, y);
            c = e;
            d = f;
        }
        x = (double)(a + c) / 2.0;
        y = (double)(b + d) / 2.0;
        printf(" %.6f %.6f\n", x, y);
    }
    return 0;
}

