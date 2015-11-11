/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-08-30 10:33
# Filename:         a.cpp
# Description: 
=============================================================================*/

#include <set>
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
const int MAXN = 550;

int mp[MAXN][MAXN];

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        int u, v;
        memset(mp, 0, sizeof(mp));
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            mp[u][v] = mp[v][u] = 1;
        }

        int ans = 1;
        int mi = 1;
        if(mp[1][n]) ans = n * (n - 1) / 2;
        printf("%d %d\n", mi, ans);
    }
    return 0;
}
