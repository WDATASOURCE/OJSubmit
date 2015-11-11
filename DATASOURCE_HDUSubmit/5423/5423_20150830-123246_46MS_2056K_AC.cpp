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
const int MAXN = 1050;

int dp[MAXN], num[MAXN];
vector <int> vec[MAXN];

void dfs(int u, int fa, int dep){
    dp[u] = dep;
    int size = vec[u].size();
    for(int i = 0; i < size; i++){
        int v = vec[u][i];
        if(v == fa) continue;
        dfs(v, u, dep + 1);
    }
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < MAXN; i++)
            vec[i].clear();
        memset(dp, 0, sizeof(dp));
        memset(num, 0, sizeof(num));
        int u, v;
        for(int i = 1; i < n; i++){
            scanf("%d%d", &u, &v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        dfs(1, -1, 1);

        for(int i = 1; i <= n; i++)
            num[dp[i]]++;

        bool flag = true;

        for(int i = 2; i <= n; i++)
            if(num[i - 1] > 1 && num[i]) flag = false;

        if(flag) printf("YES\n");
        else printf("NO\n");

    }
    return 0;
}
