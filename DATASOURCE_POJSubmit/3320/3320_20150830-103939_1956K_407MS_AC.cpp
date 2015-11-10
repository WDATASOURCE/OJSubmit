/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-08-30 10:33
# Filename: 		a.cpp
# Description: 
=============================================================================*/
 
#include <set>
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
const int MAXN = 1000100;
int p;
int a[MAXN];

int solve(){
    set <int> all;
    for(int i = 0; i < p; i++)
        all.insert(a[i]);

    int n = all.size();
    int s = 0, t = 0, num = 0;
    map <int, int> count;
    int res = p;
    while(1){
        while(t < p && num < n)
            if(count[a[t++]]++ == 0) num++;

        if(num < n) break;

        res = min(res, t - s);
        if(--count[a[s++]] == 0) num--;
    }

    return res;
}
 
int main(){
    while(scanf("%d", &p) != EOF){
        for(int i = 0; i < p; i++)
            scanf("%d", &a[i]);

        int ans = solve();

        printf("%d\n", ans);
    }
    return 0;
}
