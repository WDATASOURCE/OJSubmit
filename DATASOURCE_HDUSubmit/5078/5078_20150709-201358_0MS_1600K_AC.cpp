/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-07-09 08:06
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
using namespace std;

struct Point{
    int t, x, y;

    friend bool operator < (const Point &a, const Point &b){
        return a.t < b.t;
    }

    double func(Point a){
        return sqrt((long long)(a.x - x) * (a.x - x) + (long long)(a.y - y) * (a.y - y));
    }
};

Point point[1010];
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i = 0; i< n; i++)
            scanf("%d%d%d", &point[i].t, &point[i].x, &point[i].y);
        sort(point, point + n);
        double ans = 0.0;
        for(int i = 0; i < n - 1; i++){
            double t = (point[i].func(point[i + 1])) / (point[i + 1].t - point[i].t);
            if(t > ans) ans = t;
        }
        printf("%.10lf\n", ans);
    }
    return 0;
}
