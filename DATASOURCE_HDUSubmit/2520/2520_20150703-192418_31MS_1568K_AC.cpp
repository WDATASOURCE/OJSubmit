/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-06-26 22:57
# Filename:         a.cpp
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
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        long long n;
        long long ans = 0;
        long long v = 1;
        scanf("%I64d", &n);
        for(int i = 1; i <= n; i++)
            ans += v, v += 2;
        ans %= 10000;
        printf("%I64d\n", ans);
    }
    return 0;
}
