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

int a[100010];
int t[100010];

int main(){
    int n, m, l, b, k;
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &l, &b, &k);
            int id = 0;
            for(int i = l; i <= b; i++)
                t[id++] = a[i];
            sort(t, t + id);
            printf("%d\n", t[k - 1]);
        }
    }
    return 0;
}
