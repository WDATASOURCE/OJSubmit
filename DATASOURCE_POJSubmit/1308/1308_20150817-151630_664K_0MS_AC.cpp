/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-17 15:04
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
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
const int MAXN = 1010;

bool use[MAXN];
int degree[MAXN];
 
int main(){
    int u, v, t = 0;
    while(~scanf("%d%d", &u, &v)){
        if(u == -1 && v == -1) break;
        if(!(u + v)){
            printf("Case %d is a tree.\n", ++t);
            continue;
        }
        memset(use, 0, sizeof(use));
        memset(degree, 0, sizeof(degree));
        degree[v]++;
        use[u] = use[v] = true;
        while(scanf("%d%d", &u, &v)){
            if(!(u + v)) break;
            degree[v]++;
            use[u] = use[v] = true;
        }

        int num = 0;
        bool flag = true;
        for(int i = 0; i < MAXN; i++){
            if(use[i] && !degree[i]) num++;
            else if(use[i] && degree[i] > 1) flag = false;
        }

        if(num == 1 && flag) printf("Case %d is a tree.\n", ++t);
        else printf("Case %d is not a tree.\n", ++t);
    }
    return 0;
}
