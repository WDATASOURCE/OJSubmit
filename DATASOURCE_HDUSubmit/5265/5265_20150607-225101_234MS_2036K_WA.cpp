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
    ios_base::sync_with_stdio(false);
    while(cin >> n >> p){
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i] %= p;
        }
        sort(a, a + n);
        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            int A = p - a[i];
            int l = 0, r = n;
            while(r - l > 1){
                int mid = (l + r) >> 1;
                if(a[mid] >= A) r = mid;
                else l = mid;
            }
            int t = (a[i] + a[n - 1]) % p;
            if(t > ans) ans = t;
            if(l == i){
                if(i == 0) continue;
                else l--;
            }
            t = (a[i] + a[l]) % p;
            if(t > ans) ans =t;
        }
        cout << ans << endl;
    }
    return 0;
}
