/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-11-01 12:23
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

const int MAX=1000005;
const int INF=1000000000;

int aa[MAX];

int main(){
    int n,i;
    int q,a,x;
    while(scanf("%d",&n) != EOF){
        fill(aa, aa + MAX, 0);
        int ans = 0;
        for(i= 0; i < n; i++){
            scanf("%d%d%d", &q, &a, &x);
            if(a == 0) ans += 10;
            else if(a == 1){
                if(x == 1) ans += 40;
                else ans += 20;
                ans += aa[q] * 10;
                aa[q]++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
