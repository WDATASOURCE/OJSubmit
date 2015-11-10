/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-01-01 21:49
# Filename: 		b.cpp
# Description: 
=============================================================================*/
 
#include <map>
#include <ctime>
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
#define MAX (1 << 30)
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
#define Min(a, b) (a > b ? b : a)
using namespace std;
int ans, n, m;
int ms[50];
int mv[50];

void dfs(int r, int h, int s, int v, int x){
    if(x == m){
        if(v == n) ans = ans > s ? s : ans;
        return;
    }
    if(s >= ans || v + mv[m - x - 1] >= n || s + ms[m - x - 1] >= ans || 2 * (n - v) / r + s >= ans) return;
    for(int i = r - 1; i >= m - x; i--){
        int mj = Min(h - 1, (n - v - mv[m - x - 1]) / (i * i));
        for(int j = mj; j >= m - x; j--){
            if(!x) s = i * i;
            dfs(i, j, s + 2 * i * j, v + i * i * j, x + 1);
        }
    }
}

int main(){
    for(int i = 1; i < 25; i++)
        ms[i] = ms[i - 1] + 2 * i * i;
    for(int i = 1; i < 25; i++)
        mv[i] = mv[i - 1] + i * i * i;
    while(scanf("%d%d", &n, &m) != EOF){
        //clock_t start = clock();
        ans = MAX;
        int r = sqrt((double)n) + 1;
        int h = n / m + 1;
        dfs(r, h, 0, 0, 0);
        if(ans == MAX) printf("0\n");
        else printf("%d\n", ans);
        //clock_t stop = clock();
        //printf("time = %.2lfMS\n", (double)(stop - start));
    }
    return 0;
}
