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

bool is[3000];

int main(){
    int n, i;
    while(scanf("%d", &n) != EOF){
        fill(is, is + 3000, false);
        int a, b, c;
        scanf("%d", &a);
        for(i = 1; i < n; i++){
            scanf("%d", &b);
            c = b - a;
            if(c < 0)
                c = -c;
            is[c] = true;
            a = b;
        }
        int f = 1;
        for(i = 1; i < n; i++)
            if(!is[i]){
                f = 0;
                break;
            }
        if(f)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}

