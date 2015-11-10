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
    int i, a, b, c, v;
    while(scanf("%d", &v) != EOF){
        a = 1, b = 1, c = v;
        int area = (1 << 30);
        int t = sqrt((double)v);
        for(i = 1; i <= t; i++){
            if(v % i == 0){
                int tt = (v / i);
                for(int j = 1; j <= tt; j++){
                    if(tt % j == 0){
                        int ttt = tt / j;
                        if((i * j + i * ttt + j * ttt) * 2 < area){
                            a = i;
                            b = j;
                            c = ttt;
                            area = (i * j + i * ttt + j * ttt) * 2;
                        }
                    }
                }
            }
        }
        printf("%d %d %d\n", a, b, c);
    }
    return 0;
}

