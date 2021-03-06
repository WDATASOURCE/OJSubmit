/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-15 10:14
# Filename:         c.cpp
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
const int MAXN = 200020;

int a[MAXN];
int b[MAXN];
int p[MAXN];
 
int main(){
    int t, n;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++){
        scanf("%d", &n);
        memset(p, 0, sizeof(p));
        int dx = 0, mx, id;
        a[dx++] = -2;
        a[dx++] = -1;
        for(int i = 0; i < n; i++){
            scanf("%d", &a[dx++]);
            a[dx++] = -1;
        }
        mx = 0, id = 0, p[0] = 0;
        for(int i = 1; i < dx; i++){
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while(a[i + p[i]] == a[i - p[i]]) p[i]++;
            if(i + p[i] > mx){
                mx = i + p[i];
                id = i;
            }
        }

        int ans = 0;
        for(int i = 3; i < dx; i += 2){
            int t = i + p[i] - 1;
            if(p[t] < p[i]) continue;
            if((p[i] & 1) && t < dx && p[i] > ans)
                ans = p[i] / 2;
        }
        printf("Case #%d: %d\n", Case, ans * 3);
    }
    return 0;
}
