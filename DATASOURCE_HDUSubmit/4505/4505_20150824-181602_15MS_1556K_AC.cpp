/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-24 18:11
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
const int MAXN = 110;

int a[MAXN];
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, v;
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        for(int i = 0; i < n; i++){
            scanf("%d", &v);
            a[v]++;
        }
        int r = 109;
        while(!a[r]) r--;

        int ans = 0;
        for(int i = 1; i <= r; i++){
            ans += 6;
            if(a[i]) ans += (5 + a[i]);
        }
        ans += 4 * r;
        printf("%d\n", ans);
    }
    return 0;
}
