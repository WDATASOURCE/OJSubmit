/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-12-28 18:56
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
    int N;
    while(scanf("%d", &N) && N){
        int a, b;
        int m = 0, n = 0;
        int cr = 0, cm = 0;
        while(scanf("%d%d", &a, &b), !(a == -1 && b == -1)){
            if(cr + a > N){
                m = max(m, cr);
                n += cm;
                cr = a, cm = b;
            }else{
                cr += a;
                cm = max(cm, b);
            }
        }
        m = max(m, cr);
        n += cm;
        printf("%d x %d\n", m, n);
    }
    return 0;
}


