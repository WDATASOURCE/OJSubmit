/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-11-01 12:23
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
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

int a[5001][100010];

int main(){
    int n, m, l, b, k;
    while(scanf("%d%d", &n, &m) != EOF){
        int v;
        for(int i = 1; i <= n; i++){
            scanf("%d", &v);
            for(int j = 0; j < 5000; j++)
                a[j][i] = v;
        }
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &l, &b, &k);
            sort(a[i] + l, a[i] + b + 1);
            printf("%d\n", a[i][l + k - 1]);
        }
    }
    return 0;
}
