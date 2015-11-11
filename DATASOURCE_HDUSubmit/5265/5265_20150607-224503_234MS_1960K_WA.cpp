/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-05-23 00:41
# Filename:         c.cpp
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
#define Min(a, b) ((a) > (b) ? (b) : (a))
#define Max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

long a[100100];

int main(){
    long n, p;
    while(scanf("%ld%ld", &n, &p) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%ld", &a[i]);
            a[i] %= p;
        }
        sort(a, a + n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            int dx = 1;
            int f = 1;
            while(f){
                int l = 0, r = n;
                while(r - l > 1){
                    int mid = (l + r) >> 1;
                    if(a[mid] >= dx * p) r = mid;
                    else l = mid;
                }
                if(l == i){
                    if(i == 0) continue;
                    else l--;
                }
                long t = (a[i] + a[l]) % p;
                if(t > ans) ans = t;
                if(r == n) break;
                else dx++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
