/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-07-08 08:54
# Filename:         b.cpp
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
#include <iomanip>
#include <algorithm>
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

int main(){
    int r, y, b;
    while(scanf("%d%d%d", &r, &y, &b) != EOF){
        long long sum = 0;
        if(r >= 2) sum += 2;
        else sum += r;
        if(y >= 2) sum += 2;
        else sum += y;
        if(b >= 2) sum += 2;
        else sum += b;

        //cerr <<"sum = "<< sum << endl;
        long long ans = 0;
        for(int i = 1; i <= sum; i++)
            ans += i;
        ans += (r + y + b - sum - 1) * sum;
        printf("%lld\n", ans);
    }
    return 0;
}