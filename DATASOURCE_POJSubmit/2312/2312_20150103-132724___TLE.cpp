/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-01-03 13:01
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
#define N 310
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
#define Min(a, b) (a > b ? b : a)
using namespace std;

char ch[N][N];
bool is[N][N];
int dir[4][2] = {0, -1, -1, 0, 0, 1, 1, 0};
int ans, n, m;

void dfs(int x, int y, int di){
    if(ch[x][y] == 'T'){
        ans = Min(ans, di);
        return;
    }
    if(di > ans) return;
    is[x][y] = true;
    for(int i = 0; i < 4; i++){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(dx >= 0 && dx < n && dy >= 0 && dy < m && !is[dx][dy] && ch[dx][dy] != 'S' && ch[dx][dy] != 'R'){
            if(ch[dx][dy] == 'B') dfs(dx, dy, di + 2);
            else dfs(dx, dy, di + 1);
        }
    }
    is[x][y] = false;
}
 
int main(){
    //clock_t start = clock();
    while(scanf("%d%d", &n, &m) != EOF && n && m){
        for(int i = 0; i < n; i++)
            scanf(" %s", ch[i]);
        int sx, sy;
        ans = (1 << 30);
        fill(is[0], is[N], false);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(ch[i][j] == 'Y'){ 
                    sx = i, sy = j;
                    break;
                }
        dfs(sx, sy, 0);
        if(ans != (1 << 30)) printf("%d\n", ans);
        else printf("-1\n");
    }
    //clock_t stop = clock();
    //cerr <<"time = "<< (double)(stop - start) <<"MS"<< endl;
    return 0;
}
