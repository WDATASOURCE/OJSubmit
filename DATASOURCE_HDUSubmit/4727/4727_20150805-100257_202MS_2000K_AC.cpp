/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-05 09:43
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

int a[100010];
 
int main(){
    int t, n;
    scanf("%d", &t);
    for(int dx = 1; dx <= t; dx++){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int i;
        for(i = 1; i < n; i++)
            if(a[i + 1] - a[i] != 1) break;
        if(i == n) printf("Case #%d: 1\n", dx);
        else printf("Case #%d: %d\n", dx, i + 1);
    }
    return 0;
}
