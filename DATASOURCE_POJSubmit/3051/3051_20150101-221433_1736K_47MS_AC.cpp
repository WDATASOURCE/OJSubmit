/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-01-01 21:49
# Filename: 		b.cpp
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
int s, t, tt;
char ch[1100][1100];
int a[4][2] = {0, -1, -1, 0, 0, 1, 1, 0};

void dfs(int x, int y){
    tt++;
    ch[x][y] = '.';
    for(int i = 0; i < 4; i++){
        int dx = x + a[i][0];
        int dy = y + a[i][1];
        if(dx >= 0 && dx < s && dy >= 0 && dy < t && ch[dx][dy] == '*') dfs(dx, dy);
    }
}
 
int main(){
    //clock_t start = clock();
    while(scanf("%d%d", &t, &s) != EOF){
        int ans = 0;
        for(int i = 0; i < s; i++)
            scanf(" %s", ch[i]);
        for(int i = 0; i < s; i++)
            for(int j = 0; j < t; j++)
                if(ch[i][j] == '*'){ 
                    tt = 0;
                    dfs(i, j);
                    ans = ans > tt ? ans : tt;
                }
        printf("%d\n", ans);
    }
    //clock_t stop = clock();
    //cerr <<"time = "<< (double)(stop - start) / CLOCKS_PER_SEC << endl;
    return 0;
}
