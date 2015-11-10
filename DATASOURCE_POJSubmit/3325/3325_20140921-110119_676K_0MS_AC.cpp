/*=============================================================================
# Author:			He Shuwei
# Last modified:	2014-09-17 16:56
# Filename:			b.cpp
# Description: 
=============================================================================*/

#include <map>
#include <ctime>
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
    int sum, n, v, mi, ma;
    while(scanf("%d", &n) != EOF && n){
        mi = (1 << 30);
        ma = -1;
        sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &v);
            mi = mi > v ? v : mi;
            ma = ma > v ? ma : v;
            sum += v;
        }
        printf("%d\n", (sum - mi - ma) / (n - 2));
    }
    return 0;
}
