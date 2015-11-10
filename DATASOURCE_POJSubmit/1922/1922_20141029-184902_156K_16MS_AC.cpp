/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-10-29 18:36
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
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
 
int main(){
    int n, a, b;
    while(scanf("%d", &n) != EOF && n){
        int ans = (1 << 30);
        for(int i = 0; i < n; i++){
            scanf("%d%d", &a, &b);
            if(b >= 0)
                ans = ans < b + ceil(4.5 / a * 3600) ? ans : b + ceil(4.5 / a * 3600);
        }
        printf("%d\n", ans);
    }
    return 0;
}
