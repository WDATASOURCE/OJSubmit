/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-07-09 20:14
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
#include <algorithm>
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
#define ABS(x) ((x) > 0 ? (x) : -(x))
using namespace std;

struct Point{
    int t;
    int x;

    friend bool operator < (const Point &a, const Point &b){
        return a.t < b.t;
    }
};

Point point[101000];
 
int main(){
    int t;
    scanf("%d", &t);
    for(int d = 1; d <= t; d++){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d%d", &point[i].t, &point[i].x);
        sort(point, point + n);
        double ans = 0.0;
        for(int i = 1; i < n; i++){
            double t = ABS(point[i].x - point[i - 1].x) / (double)(point[i].t - point[i - 1].t);
            if(t > ans) ans = t;
        }

        printf("Case #%d: ", d);
        printf("%.2lf\n", ans);
    }
    return 0;
}
