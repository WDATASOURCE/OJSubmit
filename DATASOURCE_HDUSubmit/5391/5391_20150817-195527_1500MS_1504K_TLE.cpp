/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-17 19:53
# Filename:         b.cpp
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
 
int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        long long v = 1;
        for(int i = 1; i < n; i++)
            v = (v * i) % n;
        printf("%lld\n", v);
    }
    return 0;
}
