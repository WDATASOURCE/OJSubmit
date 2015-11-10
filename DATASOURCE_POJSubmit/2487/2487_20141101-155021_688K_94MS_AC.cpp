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

int a[1100];

int main(){
    int t, id = 0;
    scanf("%d", &t);
    while(t--){
        int s, n;
        scanf("%d%d", &s, &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int sum = 0;
        int ans = 0;
        for(int i = n - 1; i >= 0; i--){
            sum += a[i];
            ans++;
            if(sum >= s)
                break;
        }
        printf("Scenario #%d:\n", ++id);
        if(sum >= s)
            printf("%d\n\n", ans);
        else printf("impossible\n\n");
    }
    return 0;
}
