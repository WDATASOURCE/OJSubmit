/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-07-15 09:57
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
#define ABS(a) ((a) < 0 ? (-(a)) : (a))
#define Min(a, b) ((a) > (b) ? (b) : (a))
#define Max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

struct Stu{
    int w, s, cur;
};

Stu a[20];


int main(){
    int n;
    int dx = 1;
    while(~scanf("%d", &n)){
        if(!n) break;
        for(int i = 0; i < n; i++)
            scanf("%d%d%d", &a[i].w, &a[i].s, &a[i].cur);
        int res = -1, ans;
        for(int i = 0; i < 500; i++){
            int aw_cnt = 0, sl_cnt = 0;
            for(int j = 0; j < n; j++){
                int t = a[j].cur + i - 1;
                if(t % (a[j].w + a[j].s) - a[j].w < 0) aw_cnt++;
                else sl_cnt++;
            }
            if(aw_cnt > sl_cnt){
                res = i;
                goto A;
            }
        }

A:
        if(res == -1){
            printf("Case %d: %d\n", dx++, res);
        }else{
            ans = -1;
            for(int j = 0; j < n; j++){
                int t = res + a[j].cur - 1;
                if(t % (a[j].w + a[j].s) >= a[j].w)
                    ans = max(ans, a[j].w + a[j].s - t % (a[j].w + a[j].s));
            }
            printf("Case %d: %d\n", dx++, res + ans + 1);
        }
    }
    return 0;
}
