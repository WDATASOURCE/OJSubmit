/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-10-07 11:11
# Filename: 		b.cpp
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
#define lson l, mid, lp
#define rson mid, r, rp
#define lp (node << 1) + 1
#define rp (node << 1) + 2
using namespace std;

int a[100010], b[100010];

int main(){
    int i, n;
    while(scanf("%d", &n) != EOF && n){
        int f = 0;
        for(i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            b[a[i]] = i;
        }
        for(i = 1; i <= n; i++)
            if(a[i] != b[i])
                f = 1;
        if(f)
            printf("not ambiguous\n");
        else
            printf("ambiguous\n");
    }
    return 0;
}
