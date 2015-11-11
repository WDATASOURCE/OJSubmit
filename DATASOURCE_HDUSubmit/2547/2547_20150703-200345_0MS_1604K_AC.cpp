/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-06-26 22:57
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
using namespace std;

double func(int a, int b, int c, int d){
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        double a, b, c, d;
        scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
        double ans = func(a, b, c, d);
        printf("%.1lf\n", ans);
    }
    return 0;
}
