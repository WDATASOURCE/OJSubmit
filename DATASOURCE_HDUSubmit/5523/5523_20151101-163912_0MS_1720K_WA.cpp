/*=============================================================================
# Author:            DATASOURCE
# Last modified:     2015-11-01 12:36
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
#define ABS(x) ((x) < 0 ? (-(x)) : (x))
using namespace std;

int main(){
    int n, s, t;
    while(scanf("%d%d%d", &n, &s, &t) != EOF){
        if(ABS(t - s) + 1 == n) printf("0\n");
        else if(s == t) printf("-1\n");
        else if(s == 1 || s == n) printf("1\n");
        else printf("2\n");
    }
    return 0;
}

