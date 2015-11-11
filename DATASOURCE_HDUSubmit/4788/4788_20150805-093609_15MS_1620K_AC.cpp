/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-05 09:15
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

char ch[100];

int func(){
    if(strcmp(ch, "[B]") == 0) return 0;
    else if(strcmp(ch, "[KB]") == 0) return 1;
    else if(strcmp(ch, "[MB]") == 0) return 2;
    else if(strcmp(ch, "[GB]") == 0) return 3;
    else if(strcmp(ch, "[TB]") == 0) return 4;
    else if(strcmp(ch, "[PB]") == 0) return 5;
    else if(strcmp(ch, "[EB]") == 0) return 6;
    else if(strcmp(ch, "[ZB]") == 0) return 7;
    else return 8;
}

int main(){
    int t, n;
    scanf("%d", &t);
    for(int di = 1; di <= t; di++){
        scanf("%d%s", &n, ch);
        double ans = 1.0 - (n * pow(1000.0, func())) / (n * pow(1024.0, func()));
        printf("Case #%d: %.2lf%%\n", di, ans * 100.0);
    }
    return 0;
}
