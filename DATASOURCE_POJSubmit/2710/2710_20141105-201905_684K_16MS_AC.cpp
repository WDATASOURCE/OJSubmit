/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-11-02 14:26
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
#define E 2.718281828459045 
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

int a[300];

int main(){
    int t, p, q, s, e;
    scanf("%d", &t);
    int id = 1;
    while(t--){
        scanf("%d%d%d%d", &p, &q, &s, &e);
        printf("Problem set %d: %d / %d, base 7 digits %d through %d: ", id++, p, q, s, e);
        p %= q;
        int i;
        for(i = 0; i < 3000; i++){
            p *= 7;
            a[i] = p / q;
            p %= q;
        }
        for(i = s; i <= e; i++)
            printf("%d", a[i]);
        printf("\n");
    }
    return 0;
}
