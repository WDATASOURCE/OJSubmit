/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-12-20 20:32
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
#define N 150
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

int mp[N][N];
int len[N][N];
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int ans, n, m;

int dfs(int x, int y){
    if(len[x][y]) return len[x][y];
    int ma = 0;
    for(int i = 0; i < 4; i++){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(dx >= 0 && dx < n && dy >= 0 && dy < m && mp[dx][dy] < mp[x][y])
            ma = max(dfs(dx, dy), ma);
    }
    len[x][y] = ++ma;
    return ma;
}

int main(){
    while(~scanf("%d%d", &n, &m)){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &mp[i][j]);
        fill(len[0], len[N], 0);
        ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                ans = max(dfs(i, j), ans);
        printf("%d\n", ans);
    }
    return 0;
}
