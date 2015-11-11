/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-07-11 08:05
# Filename:         d.cpp
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

struct Course{
    int r, e, l;

    friend bool operator < (const Course &a, const Course &b){
        return a.e < b.e;
    }
};

Course a[100010];
 
int main(){
    int t;
    scanf("%d", &t);
    for(int dx = 1; dx <= t; dx++){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d%d%d", &a[i].r, &a[i].e, &a[i].l);
        sort(a, a + n);

        int f = 1;
        int cur = 0;
        for(int i = 0; i < n; i++){
            if(cur + a[i].r > a[i].e) f = 0;
            cur = a[i].l + a[i].e;
        }

        if(f) printf("Case #%d: YES\n", dx);
        else printf("Case #%d: NO\n", dx);
    }
 
    return 0;
}
