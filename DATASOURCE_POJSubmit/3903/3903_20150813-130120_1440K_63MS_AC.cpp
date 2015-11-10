/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-13 13:00
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
const int N = 100100;

int a[N], b[N], ans;

int find(int i){
    int l = 0, r = ans, mid;
    while(r - l > 1){
        mid = (r + l) / 2;
        if(b[mid] < a[i]) l = mid;
        else r = mid;
    }
    return r;
}

int main(){
    int i, n;
    while(~scanf("%d", &n)){
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        b[1] = a[1];
        ans = 1;
        for(i = 2; i <= n; i++){
            if(a[i] > b[ans])
                b[++ans] = a[i];
            else{
                int p = find(i);
                b[p] = a[i];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
