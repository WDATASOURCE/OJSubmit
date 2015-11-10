/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-10-11 23:45
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
#define lson l, mid, lp
#define rson mid, r, rp
#define lp (rt << 1) + 1
#define rp (rt << 1) + 2
#define e 2.718281828459045 
using namespace std;

int main() {
    int n, i = 0;
    while(scanf("%d", &n) && n){
        if(n % 2)
            printf("%d. odd %d\n", ++i, n / 2);
        else 
            printf("%d. even %d\n", ++i, n / 2);
    }
    return 0;
}
