/*=============================================================================
# Author: He Shuwei
# Last modified:	2014-08-10 20:49
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
    int n, i, t, v, sum;
    scanf("%d", &t);
    while(t--){
        sum = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++){
            scanf("%d", &v);
            sum += v;
        }
        sum -= (n - 1);
        printf("%d\n", sum);
    }
    return 0;
}
