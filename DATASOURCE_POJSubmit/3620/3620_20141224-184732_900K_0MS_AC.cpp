/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-12-23 22:59
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
#define N 200
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

int as, n, m;
char ch[N][N];
int dir[4][2] = {0, -1, 0, 1, -1, 0, 1, 0};

void dfs(int x, int y){
    ch[x][y] = '*';
    as++;
    for(int i = 0; i < 4; i++){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(ch[dx][dy] == '#' && dx >= 1 && dx <= n && dy >= 1 && dy <= m)
            dfs(dx, dy);
    }
}

int main(){
    int k;
    while(scanf("%d%d%d", &n, &m, &k) != EOF){
        fill(ch[0], ch[N], '*');
        int a, b;
        for(int i = 0; i < k; i++){
            scanf("%d%d", &a, &b);
            ch[a][b] = '#';
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(ch[i][j] == '#'){
                    as = 0;
                    dfs(i, j);
                    ans = ans > as ? ans : as;
                }
        printf("%d\n", ans);
    }
	return 0;
}
