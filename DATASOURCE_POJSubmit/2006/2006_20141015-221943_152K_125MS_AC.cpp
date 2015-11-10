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
    double ka, ac;
    int m, n;
    while(scanf("%lf%lf%d%d", &ka, &ac, &m, &n) != EOF && m){
        printf("%.3f\n", -log10((-ka + sqrt(ka * ka + (m << 2) * n * ac * ka)) / (n << 1)));
    }
    return 0;
}

