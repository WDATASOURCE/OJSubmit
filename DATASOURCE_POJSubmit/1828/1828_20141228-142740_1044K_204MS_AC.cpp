/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-12-14 00:07
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
#define N 50010
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

struct point{
    int x, y;
};

point a[N];

bool cmp(point a, point b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main(){
    int n;
    while(~scanf("%d", &n) && n){
        for(int i = 0; i < n; i++)
            scanf("%d%d", &a[i].x, &a[i].y);
        sort(a, a + n, cmp);
        int ans = 1;
        int maxy = a[n - 1].y;
        for(int i = n - 2; i >= 0; i--){
            if(a[i].y > maxy){
                maxy = a[i].y;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
