/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-06-26 22:57
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
using namespace std;

int n, m, res;
int p[30];
int mp[30][30];
int t[30];
int ans[30];

int prim(){
    int s = t[0];
    int dis[30];
    bool vis[30];
    fill(vis, vis + 30, true);
    int aaa = 0;
    for(int i = 0; i < m; i++){
        vis[t[i]] = false;
        dis[t[i]] = mp[s][t[i]];
    }
    vis[s] = true;
    int mi = (1 << 29);
    int mip = 0;

    for(int i = 0; i < m - 1; i++){
        mi = (1 << 29);
        for(int j = 0; j < m; j++)
            if(!vis[t[j]] && mi > dis[t[j]]){ 
                mi = dis[t[j]];
                mip = t[j];
            }

        if(mi == (1 << 29)) return -1;
        aaa += mi;
        vis[mip] = true;

        for(int j = 0; j < m; j++)
            if(!vis[t[j]] && dis[t[j]] > mp[mip][t[j]])
                dis[t[j]] = mp[mip][t[j]];
    }
    return aaa;
}

void func(int num, int dx){
    t[dx] = num;
    if(dx == m - 1){
        int tt = prim();
        //for(int i = 0; i < m; i++)
            //printf("%d ", t[i]);
        //printf("\n tt = %d\n", tt);
        if(tt == -1) return;
        else if(res > tt){
            res = tt;
            for(int i = 0; i < m; i++)
                ans[i] = t[i];
        }else return;
    }
    for(int i = num + 1; i < n; i++)
        func(i, dx + 1);
}

int main(){
    while(1){
        scanf("%d%d", &n, &m);
        if(!n && !m) break;
        for(int i = 0; i < n; i++)
            scanf("%d", &p[i]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &mp[i][j]);
        res = (1 << 29);
        for(int i = 0; i < n; i++)
            func(i, 0);
        for(int i = 0; i < m; i++)
            printf("%d%c", ans[i] + 1, i == m - 1 ? '\n' : ' ');
    }
    return 0;
}
