/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-09-09 17:40
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
using namespace std;

/*
int res[30];
bool vis[30][30];

bool isTrue(int x){
    int sum = 0;
    for(int i = x; i > 0; i--){
        for(int j = 0; j < i; j++)
            sum += vis[i][j];
    }

    if(sum == (x + 1) * x / 2 / 2) return true;
    return false;
}

void gao(int x){
    if(((x + 1) * x / 2) & 1) return;
    int end = (1 << x);
    int ans = 0;
    for(int i = 0; i < end; i++){
        memset(vis, 0, sizeof(vis));
        for(int j = 0; j < x; j++)
            vis[x][j] = (i >> j) & 1;

        for(int j = x - 1; j >= 1; j--){
            for(int k = 0; k < j; k++)
                vis[j][k] = vis[j + 1][k + 1] ^ vis[j + 1][k];
        }

        if(isTrue(x)) ans++;
    }
    res[x] = ans;
    //cerr <<"x = "<< x <<", res[x] = "<< res[x] << endl;
}
*/
 
int main(){
    //memset(res, 0, sizeof(res));
    //for(int i = 3; i < 25; i++) gao(i);

    const int res[] = {0, 0, 0, 4, 6, 0, 0, 12, 40, 0,  0, 171, 410, 0, 0, 1896, 5160, 0, 0, 32757, 59984, 0, 0, 431095, 822229};

    int n;
    while(~scanf("%d", &n) && n){
        printf("%d %d\n", n, res[n]);
    }
    return 0;
}
