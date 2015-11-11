/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-09 19:26
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
int a[10100];
 
int main(){
    int n;
    while(scanf("%d", &n)!= EOF){
        memset(a, 0, sizeof(a));
        int v;
        for(int i = 0; i < n; i++){
            scanf("%d", &v);
            a[v]++;
        }
        int ans = -1;
        for(int i = 0; i <= 10100; i++)
            if(a[i] > n - a[i]) ans = i;
        printf("%d\n", ans);
    }
    return 0;
}
