/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-11-09 13:29
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

int main(){
    int k;
    while(scanf("%d", &k) != EOF && k){
        int ans = 1;
        double sum = log(2.0) * pow(2.0, (k - 1960) / 10 + 2.0);
        for(;; ans++){
            sum -= log(ans * 1.0);
            if(sum < 0)
                break;
        }
        printf("%d\n", --ans);
    }
    return 0;
}
