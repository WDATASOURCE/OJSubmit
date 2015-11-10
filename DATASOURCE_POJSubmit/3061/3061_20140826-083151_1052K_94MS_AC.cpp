/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-08-26 08:06
# Filename: 		b.cpp
# Description: 
=============================================================================*/
 
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M (1 << 30)
using namespace std;
int sum[100005];

int find(int l, int r, int x, int ll){
    while(r - l > 1){
        int mid = (r + l) / 2;
        if(sum[mid] - sum[ll] < x)
            l = mid;
        else
            r = mid;
    }
    return r - ll;
}
 
int main(){
    int i, v, n, t, s;
    scanf("%d", &t);
    while(t--){
        int ans = M;
        scanf("%d%d", &n, &s);
        for(i = 1; i <= n; i++){
            scanf("%d", &v);
            sum[i] = sum[i - 1] + v;
        }
        if(sum[n] < s){
            printf("%d\n", 0);
            continue;
        }
        for(i = 1; i <= n && sum[n] - sum[i - 1] >= s; i++){
            v = find(i - 1, n, s, i - 1);
            ans = ans > v ? v : ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
