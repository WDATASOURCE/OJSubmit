/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-12-14 00:07
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
#define N 20010
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

int n, b, a[N];

int main(){
    while(scanf("%d%d", &n, &b) != EOF){
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        int sum = 0;
        sort(a, a + n);
        for(int i = n - 1; i >= 0; i--){
            sum += a[i];
            if(sum >= b){
                printf("%d\n", n - i);
                break;
            }
        }
    }
    return 0;
}
