/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-20 08:16
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
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
const int MAXN = 50;
const int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

int n, m;
char ch[MAXN][MAXN];
bool vis[MAXN][MAXN];

int dfs(int x, int y){
    vis[x][y] = true;
    int cnt = 0;
    for(int i = 0; i < 8; i++){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(dx >= 0 && dx <= n + 1 && dy >= 0 && dy <= m + 1){
            //cerr <<"i = "<< i <<" x = "<< x <<", y = "<< y <<", dx = "<< dx <<", dy = "<< dy << endl;
            if(!vis[dx][dy] && ch[dx][dy] != 'X' && !(i & 1)) cnt++;
            if(!vis[dx][dy] && ch[dx][dy] == 'X') cnt += dfs(dx, dy);
        }
    }
    return cnt;
}
 
int main(){
    int x, y;
    while(scanf("%d%d%d%d", &n, &m, &x, &y) != EOF){
        if(!(n + m + x + y)) break;
        fill(ch[0], ch[MAXN], '.');
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++)
            scanf("%s", ch[i] + 1);
        int ans = dfs(x, y);
        printf("%d\n", ans);
    }
    return 0;
}
