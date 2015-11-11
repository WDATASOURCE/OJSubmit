/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-24 16:43
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
#define ABS(x) ((x) > 0 ? (x) : (-(x)))
using namespace std;
int mp[50][50];
int a[50][50];
const int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
 
int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        if(!(n + m)) break;
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &mp[i][j]);

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                for(int k = 0; k < 4; k++){
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if(x > 0 && x <= n && y > 0 && y <= m){
                        if(mp[i][j] * mp[x][y] < 0) a[i][j] += ABS(mp[x][y]);
                        else a[i][j] -= ABS(mp[x][y]);
                    }
                }
            }
        int x = 0, y = 0, ans = -(1 << 29);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(ans < a[i][j]) x = i, y = j, ans = a[i][j];

        printf("%d %d %d\n", x, y, ans);
    }
    return 0;
}
