/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-05-31 15:10
# Filename:         a.cpp
# Description: 
=============================================================================*/
 
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
using namespace std;

int mp[550][550];
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

int func(int x, int y){
    if(mp[x - 1][y] && mp[x][y - 1]) return 1;
    else if(mp[x][y - 1] && mp[x + 1][y]) return 1;
    else if(mp[x - 1][y] && mp[x][y + 1]) return 1;
    else if(mp[x + 1][y] && mp[x][y + 1]) return 1;
    else return 0;
}
 
int main(){
    int t;
    scanf("%d", &t);
    for(int di = 1; di <= t; di++){
        int n, m;
        scanf("%d%d", &n, &m);
        int q;
        scanf("%d", &q);
        int x, y;
        fill(mp[0], mp[550], 0);
        for(int i = 0; i < q; i++){
            scanf("%d%d", &x, &y);
            mp[x][y] = 1;
        }

        int f = 1;
        while(f){
            f = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                if(mp[i][j]) continue;
                if(func(i, j)) mp[i][j] = 1, f = 1;
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(mp[i][j]) ans++;
        printf("Case #%d:\n%d\n", di, ans);
    }
    return 0;
}