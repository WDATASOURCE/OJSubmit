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

int a[10];
 
int main(){
    int i, t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(i = 0; i < 10; i++)
            scanf("%d", &a[i]);
        sort(a, a + 10);
        printf("%d %d\n", n, a[7]);
    }
    return 0;
}
