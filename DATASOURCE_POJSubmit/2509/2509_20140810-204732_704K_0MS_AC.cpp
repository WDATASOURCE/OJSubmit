/*=============================================================================
# Author: He Shuwei
# Last modified:	2014-08-10 20:47
# Filename:			b.cpp
# Description: 
=============================================================================*/
 
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){
    int ans, n, k, v;
    while(scanf("%d%d", &n, &k) != EOF){
        int l = n; 
        ans = n;
        while(l >= k){
            v = l / k;
            ans += v;
            l = v + l - k * v;
        }
        printf("%d\n", ans);
    }
    return 0;
}
