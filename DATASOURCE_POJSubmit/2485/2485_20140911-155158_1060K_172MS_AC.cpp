/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-09-10 18:41
# Filename: 		c.cpp
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
#define M (1 << 30)
using namespace std;

int mp[505][505];
int low[505], vis[505], ans, mi, mip, n;

void prime(){
    int i, j;
    ans = 0;
    fill(vis, vis + 505, 0);
    mip = 0;
    vis[mip] = 1;
    for(i = 0; i < n; i++)
        low[i] = mp[mip][i];
    for(i = 1; i < n; i++){
        mi = M;
        for(j = 0; j < n; j++)
            if(!vis[j] && low[j] < mi)
                mi = low[j], mip = j;
    ans = ans > mi ? ans : mi;
    vis[mip] = 1;
    for(j = 0; j < n; j++)
        if(!vis[j] && low[j] > mp[mip][j])
            low[j] = mp[mip][j];
    }
    return;
}


int main(){
    int i, j, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                scanf("%d", &mp[i][j]);
        prime();
        printf("%d\n", ans);
    }
    return 0;
}
