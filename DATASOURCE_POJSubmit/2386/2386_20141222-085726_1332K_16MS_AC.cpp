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

char mp[N][N];
bool use[N][N];
int dir[8][2] = {-1, -1, -1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1};
int ans, n, m;

void dfs(int x, int y){
    use[x][y] = true;
    for(int i = 0; i < 8; i++){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(dx >= 0 && dx < n && dy >= 0 && dy < m && !use[dx][dy] && mp[dx][dy] == 'W')
            dfs(dx, dy);
    }
}

int main(){
    while(~scanf("%d%d", &n, &m)){
        for(int i = 0; i < n; i++)
            scanf("%s", mp[i]);
        fill(use[0], use[N], false);
        ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!use[i][j] && mp[i][j] == 'W')
                    dfs(i, j), ans++;
        printf("%d\n", ans);
    }
    return 0;
}
