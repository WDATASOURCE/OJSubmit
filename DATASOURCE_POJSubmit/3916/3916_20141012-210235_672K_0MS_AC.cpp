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

int main(){
    int n;
    while(scanf("%d", &n) != EOF && n){
        int b = 0, v;
        for(int i = 0; i < n; i++){
            scanf("%d", &v);
            if(b != v)
                printf("%d ", v);
            b = v;
        }
        printf("$\n");
    }
    return 0;
}
