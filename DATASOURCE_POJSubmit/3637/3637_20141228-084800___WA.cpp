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
#define N 20010
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

int a[N];

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int ans = 0;
        for(int i = 0; i < n; i++)
            if(i % 3 == 0) ans += a[i];
        printf("%d\n", ans);
    }
    return 0;
}
