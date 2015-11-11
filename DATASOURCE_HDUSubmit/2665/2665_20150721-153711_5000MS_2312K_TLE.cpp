/*=============================================================================
# Author:            He Shuwei
# Last modified:     2014-11-01 12:23
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

struct point{
    int i, b;
};

bool cmp(point a, point b){
    return a.b < b.b;
}

point a[100010];

int main(){
    int t;
    scanf("%d", &t);
    int n, m, l, b, k;
    while(t--){
    //while(scanf("%d%d", &n, &m) != EOF){
        scanf("%d%d", &n, &m);
        int v;
        for(int i = 0; i < n; i++){
            scanf("%d", &v);
            a[i].i = i + 1;
            a[i].b = v;
        }
        sort(a, a + n, cmp);
        int j;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &l, &b, &k);
            int ans = 0;
            for(j = 0; j < n; j++){
                if(a[j].i >= l && a[j].i <= b){
                    ans++;
                    if(ans == k)
                        break;
                }
            }
            printf("%d\n", a[j].b);
        }
    }
    return 0;
}
