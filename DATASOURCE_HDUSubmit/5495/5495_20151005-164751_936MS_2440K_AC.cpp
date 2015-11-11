/*=============================================================================
# Author:            DATASOURCE
# Last modified:     2015-10-05 16:38
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
const int MAXN = 100100;

bool vis[MAXN];
int a[MAXN], b[MAXN];
 
int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(int i = 0; i < n; i++)
            scanf("%d", &b[a[i]]);

        int ans = 0;
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++){
            int id = b[i];
            int num = 0;
            while(!vis[id]){
                vis[id] = true;
                num++;
                id = b[id];
            }
            if(num > 1) ans++;
        }
        printf("%d\n", n - ans);
    }
    return 0;
}

