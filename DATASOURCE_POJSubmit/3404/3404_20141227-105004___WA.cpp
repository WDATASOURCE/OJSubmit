/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-12-27 10:46
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
#define N 100
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

int a[N];
 
int main(){
    int n;
    while(~scanf("%d", &n)){
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int ans = 0;
        for(int i = 1; i < n; i++)
            ans += a[i];
        ans += a[0] * (n - 2);
        printf("%d\n", ans);
    }
    return 0;
}
