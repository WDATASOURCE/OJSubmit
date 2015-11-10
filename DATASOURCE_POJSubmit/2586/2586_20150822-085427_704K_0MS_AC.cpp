/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-20 08:49
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
    int s, d;
    while(~scanf("%d%d", &s, &d)){
        int a[14];
        fill(a, a + 14, s);
        int sum = s * 5;
        int dx = 5;
        while(dx > 0 && sum > 0){
            a[dx--] = -d;
            sum -= (s + d);
        }

        int l = 1, r = 5;
        while(r < 13){
            if(a[l] > 0) a[++r] = s;
            else a[++r] = -d;
            l++;
        }

        int ans = 0;
        for(int i = 1; i < 13; i++)
            ans += a[i];

        if(ans >= 0) printf("%d\n", ans);
        else printf("Deficit\n");
    }
    return 0;
}
