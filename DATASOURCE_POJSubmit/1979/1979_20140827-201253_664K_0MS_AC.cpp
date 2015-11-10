/*=============================================================================
# Author:			He Shuwei
# Last modified:	2014-08-27 18:43
# Filename:			b.cpp
# Description: 
=============================================================================*/

#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

char ch[25][25];
int aa[25][25];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int w, h, ans;

void find(int x, int y){
    if(ch[x][y] == '#')
        return;
    ans++;
    ch[x][y] = '#';
    for(int k = 0; k < 4; k++){
        int a = x + dir[k][0];
        int b = y + dir[k][1];
        if(a >= 0 && a < h && b >= 0 && b < w)
            find(a, b);
    }
}

int main(){
    int i, j, f;
    while(scanf("%d%d", &w, &h) != EOF){
        if(w == 0 && h == 0)
            break;
        getchar();
        f = 0;
        ans = 0;
        fill(aa[0], aa[25], 0);
        for(i = 0; i < h; i++)
            scanf("%s", ch[i]);
        for(i = 0; i < h; i++){
            for(j = 0; j < w; j++)
                if(ch[i][j] == '@'){
                    f = 1;
                    break;
                }
            if(f)
                break;
        }
        find(i, j);
        printf("%d\n", ans);
    }
    return 0;
}
