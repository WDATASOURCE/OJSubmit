/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-10-15 18:39
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

int a[1050];

int main(){
    int n, k, i, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        while(k--){
            next_permutation(a, a + n);
        }
        for(i = 0; i < n; i++)
            printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}

