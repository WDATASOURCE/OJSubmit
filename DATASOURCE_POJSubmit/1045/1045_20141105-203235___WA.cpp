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

int main(){  
    int n, i;  
    double vs, r, c, w, vr;  
    while(scanf("%lf%lf%lf%d", &vs, &r, &c, &n) != EOF){
        for (i = 0; i < n; i++){
            scanf("%lf", &w);
            vr = c * r * w * vs / sqrt(1 + pow(c * r * w, 2.0));  
            printf("%.3lf\n", vr);  
        }  
    }
    return 0;
}   
