/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-22 18:59
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
const int MAXN = 1500;

struct Time{
    int h, m, s;

    Time(){};
    Time(int _h, int _m, int _s){
        h = _h, m = _m, s = _s;
    }
};

Time subTime(Time l, Time r){
    if(l.s > r.s) r.s += 60, r.m--;
    r.s -= l.s;

    if(l.m > r.m) r.m += 60, r.h--;
    r.m -= l.m;

    r.h -= (l.h % 24);
    if(r.h < 0) r.h += 24;

    return r;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        Time l, r;
        scanf("%d:%d:%d %d:%d:%d", &r.h, &r.m, &r.s, &l.h, &l.m, &l.s);
        Time ans = subTime(l, r);
        printf("%02d:%02d:%02d\n", ans.h, ans.m, ans.s);
    }
    return 0;
}
