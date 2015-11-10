/*=============================================================================
# Author:			He Shuwei
# Last modified:	2014-10-15 21:37
# Filename:			a.cpp
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
    int A, a, B, b, P;
    while(scanf("%d%d%d%d%d", &A, &a, &B, &b, &P) != EOF){
        if((b >= A && B <= P) || (a >= B && A <= P) || (A + B <= P))
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

