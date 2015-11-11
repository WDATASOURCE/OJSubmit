/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-06-26 22:57
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
using namespace std;

int a[1010];
int ans[1010][1010];

int main(){
    int n, q;
    while(scanf("%d%d", &n, &q) != EOF){
        fill(ans[0], ans[1010], 0);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        for(int i = 1; i <= n; i++){
            int t = 0;
            for(int j = i + 1; j <= n; j++){
                if(a[i] > a[j]) t++;
                ans[i][j] = t;
            }
        }
        while(q--){
            int l, r;
            scanf("%d%d", &l, &r);
            long long res = 0;
            for(int i = l; i <= r; i++)
                res += ans[i][r];
            printf("%I64d\n", res);
        }
    }

    return 0;
}
