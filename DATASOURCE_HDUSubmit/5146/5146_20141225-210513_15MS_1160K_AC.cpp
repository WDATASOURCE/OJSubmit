/*=============================================================================
# Author:            He Shuwei
# Last modified:     2014-12-20 18:58
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

int a[10000];

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
         long long l = 0;
         long long r = 0;
         int f = 1;
         for(int i = 1; i <= n; i++){
             if(i & 1) l += a[i];
             else r += a[i];
             if(a[i] != a[n - i + 1])
                 f = 0;
         }
         if(f == 1) printf("No\n");
         else{
             if(l == r) printf("Yes\n");
             else printf("No\n");
         }
    }
    return 0;
}