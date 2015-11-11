/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-07-08 10:56
# Filename:         b.cpp
# Description: 
=============================================================================*/
 
#include <map>
#include <ctime>
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
#define ABS(a) (((a) > 0) ? (a) : ((-a)))
#define Min(a, b) ((a) > (b) ? (b) : (a))
using namespace std;

int main(){
    int x, y;
    while(scanf("%d%d", &x, &y) != EOF){
        if(x > y){
            printf("-1\n");
            continue;
        }
        double uc = (y + 1 - 1e-9) / x;
        double temp = 1.0;
        int ans = x - 1;
        for(int i = 1; i <= x; i++){
            int cha = (int)(uc * i - temp);
            temp += cha;
            temp = temp / i * (i + 1);
            ans += cha;
        }
        printf("%d\n", ans);
    }
    return 0;
}
