/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-25 19:10
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
#define ABS(x) ((x) > 0 ? (x) : (-(x)))
using namespace std;
const double eps = 1e-9;

struct Point{
    double v;
    int id;

    friend bool operator < (const Point &a, const Point &b){
        if(ABS(a.v - b.v) < eps) return a.id < b.id;
        return a.v < b.v;
    }
}a[110];
 
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        if(!n) break;
        for(int i = 1; i <= n; i++){
            scanf("%lf", &a[i].v);
            a[i].id = i;
        }

        sort(a + 1, a + n + 1);

        double sum = 0.0;
        for(int i = 2; i < n; i++)
            sum += a[i].v;

        double ave = sum / (n - 2);

        int p = 0;
        double cha = 100000.0;
        for(int i = 1; i <= n; i++){
            if(ABS(a[i].v - ave) < cha){
                cha = ABS(a[i].v - ave);
                p = a[i].id;
            }
        }
        printf("%d\n", p);
    }
    return 0;
}
