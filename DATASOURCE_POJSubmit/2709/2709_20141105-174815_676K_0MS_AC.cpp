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

int a[20];

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n, i, ans;
    int m;
    while(scanf("%d", &n) != EOF && n){
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        scanf("%d", &m);
        sort(a, a + n, cmp);
        ans = a[0] % 50 == 0 ? a[0] / 50 : a[0] / 50 + 1;
        a[0] = ans * 50 - a[0];
        for(i = 1; i < n; i++)
            a[i] = ans * 50 - a[i];
        sort(a, a + n, cmp);
        while(1){
            if(a[2] == 0 && m > 0){
                ans++;
                for(i = 0; i < n; i++)
                    a[i] += 50;
            }
            m--;
            if(m <= 0)
                break;
            else{
                a[0]--;
                a[1]--;
                a[2]--;
                sort(a, a + n, cmp);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
