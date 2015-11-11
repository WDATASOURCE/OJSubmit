/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-07-24 14:17
# Filename:         b.cpp
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
    int n, m, x, y;
    while(scanf("%d%d%d%d", &n, &m, &x, &y) != EOF){
        if(n < m){
            swap(n, m);
            swap(x, y);
        }
        if(m == 1){
            printf("1\n");
            continue;
        }

        if((int)ceil(n / 2.0) == x && (int)ceil(m / 2.0) == y && ((n & 1) && (m & 1))){
            printf("%d\n", min(x , y - 1));
            //cout<<"fuck"<<endl;
            continue;
        }

        int mid = ceil(m / 2.0);
        x = min(x, n - x + 1);
        y = min(y, m - y + 1);

        int ans = max(mid, min(x, m - y));

        printf("%d\n", ans);

    }
    return 0;
}