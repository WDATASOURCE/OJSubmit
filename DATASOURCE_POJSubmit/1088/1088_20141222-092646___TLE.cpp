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
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int ans, n, m;

void dfs(int x, int y, int t){
    ans = ans > t ? ans : t;
    for(int i = 0; i < 4; i++){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(dx >= 0 && dx < n && dy >= 0 && dy < m && mp[dx][dy] < mp[x][y])
            dfs(dx, dy, t + 1);
    }
}

int main(){
    while(~scanf("%d%d", &n, &m)){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &mp[i][j]);
        ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                dfs(i, j, 1);
        printf("%d\n", ans);
    }
    return 0;
}
